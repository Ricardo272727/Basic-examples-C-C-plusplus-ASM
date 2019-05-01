// -----------------------------------------------------------------
// Clistbox.h --> Clase para crear listbox (18/07/2003)
// -----------------------------------------------------------------

class Clistbox{
protected:
	char szbuffer[260];
public:
	// --> Propiedades
	HWND        hWnd;                  // --> Handle del listbox
	HWND        hWndPadre;             // --> Handle de la ventana pariente
	HINSTANCE   hInstancia;            // --> Instancia de la aplicación
	RECT        Posicion;              // --> Posición del listbox
	WNDPROC     WndProcAddress;        // --> puntero a el WndProc del sistema
	WNDPROC     WndProcAddressListbox; // --> puntero a el WndProc (subclassing)
	// --> Métodos
	void Clistbox::Crear(void);                                                                                 // --> Crea el listbox
	void Clistbox::Destruir(void);                                                                              // --> Destruye el listbox 
	void Clistbox::Disponible(BOOL Valor);                                                                      // --> Habilita o no el listbox
	void Clistbox::Visible(BOOL Valor);                                                                         // --> Muestra o no el listbox
	void Clistbox::AgregarItem(LPSTR lpszItem);                                                                 // --> Agrega un item al listbox    
	void Clistbox::EliminarItem(int nIndice);                                                                   // --> Elimina un item al listbox    
	int Clistbox::NumeroItems(void);                                                                            // --> Devuelve el número de items en el listbox  
	void Clistbox::Limpiar(void);                                                                               // --> Limpia el listbox 
	void Clistbox::SeleccionarItem(int nIndice);                                                                // --> Selecciona un item en el listbox
	int Clistbox::BuscarItem(LPSTR lpszItem);                                                                   // --> Busca un item en el listbox
	LPSTR Clistbox::TextoItem(int nIndice);                                                                     // --> Devuelve el texto de un item en el listbox
	int Clistbox::Seleccionado(void);                                                                           // --> Devuelve el indice del item seleccionado
	void Clistbox::Fuente(LONG lTamano, BOOL Negrita, BOOL Cursiva, BOOL Subrayado, LPSTR lpszNombreFuente);    // --> Establece la fuente del listbox
	void Clistbox::Foco(void);                                                                                  // --> Da el foco al listbox
	void Clistbox::Actualizar(void);                                                                            // --> Actualiza el contenido del listbox
	void Clistbox::Mover(int nPosX, int nPosY);                                                                 // --> Mueve el listbox
	void Clistbox::Dimensionar(int nAncho, int nLargo);                                                         // --> Dimensiona el tamaño del listbox   
	void Clistbox::Mensaje(UINT uMensaje, WPARAM wParam, LPARAM lParam);                                        // --> Envia un mensaje al listbox
};	

void Clistbox::Crear(void){
	hWnd = CreateWindowEx(WS_EX_CLIENTEDGE, "listbox", "", WS_VISIBLE|WS_CHILD|LBS_HASSTRINGS|LBS_DISABLENOSCROLL, Posicion.left, Posicion.top, Posicion.right, Posicion.bottom, hWndPadre, 0, hInstancia, NULL);
	WndProcAddress = (WNDPROC) GetWindowLong(hWnd, GWL_WNDPROC);
	SetWindowLong(hWnd, GWL_WNDPROC, (LONG) WndProcAddressListbox);	
}

void Clistbox::Destruir(void){
	DestroyWindow(hWnd);
}

void Clistbox::Disponible(BOOL Valor){
	EnableWindow(hWnd, Valor);
}

void Clistbox::Visible(BOOL Valor){
	if(Valor){
		ShowWindow(hWnd, SW_SHOW);
		UpdateWindow(hWnd);
	}else{
		ShowWindow(hWnd, SW_HIDE);
		UpdateWindow(hWnd);
	}
}

void Clistbox::AgregarItem(LPSTR lpszItem){
	SendMessage(hWnd, LB_ADDSTRING, 0, (LPARAM) (LPCTSTR) lpszItem);
}

void Clistbox::EliminarItem(int nIndice){
	SendMessage(hWnd, LB_DELETESTRING, (WPARAM) nIndice, 0);
}

int Clistbox::NumeroItems(void){
	return (int) SendMessage(hWnd, LB_GETCOUNT, 0, 0);
}

void Clistbox::Limpiar(void){
	SendMessage(hWnd, LB_RESETCONTENT, 0, 0); 
}

void Clistbox::SeleccionarItem(int nIndice){
	SendMessage(hWnd, LB_SETCURSEL, (WPARAM) nIndice, 0);
}

int Clistbox::BuscarItem(LPSTR lpszItem){
	return (int) SendMessage(hWnd,  LB_FINDSTRING, 0, (LPARAM) (LPCTSTR) lpszItem);
}

LPSTR Clistbox::TextoItem(int nIndice){
	SendMessage(hWnd, LB_GETTEXT, (WPARAM) nIndice, (LPARAM) (LPCTSTR) szbuffer);
	return szbuffer;
}

int Clistbox::Seleccionado(void){
	return (int) SendMessage(hWnd, LB_GETCARETINDEX, 0, 0);
}

void Clistbox::Fuente(LONG lTamano, BOOL Negrita, BOOL Cursiva, BOOL Subrayado, LPSTR lpszNombreFuente){
	LOGFONT fuente;
	HFONT hFuente;
	HDC hdc;
	ZeroMemory(&fuente, sizeof(LOGFONT));
	ZeroMemory(&hFuente, sizeof(HFONT));
	fuente.lfHeight = lTamano;
	fuente.lfWidth = 0;
	fuente.lfEscapement = 1;
	fuente.lfOrientation = 1;
	if (Negrita){
		fuente.lfWeight = FW_BOLD;
	}else{
		fuente.lfWeight = FW_NORMAL;
	}
	fuente.lfItalic = Cursiva;
	fuente.lfUnderline = Subrayado;
	fuente.lfStrikeOut = false;
	fuente.lfCharSet = DEFAULT_CHARSET;
	fuente.lfOutPrecision = OUT_DEFAULT_PRECIS;
	fuente.lfClipPrecision = CLIP_DEFAULT_PRECIS;
	fuente.lfQuality = DEFAULT_QUALITY;
	fuente.lfPitchAndFamily = DEFAULT_PITCH|FF_ROMAN;
	lstrcpy(fuente.lfFaceName, lpszNombreFuente);
	hdc = GetDC(hWnd); 
	hFuente = CreateFontIndirect(&fuente);
    SendMessage(hWnd, WM_SETFONT, (WPARAM) hFuente, MAKELPARAM(true, 0));
}

void Clistbox::Foco(void){
	SetFocus(hWnd);
}

void Clistbox::Actualizar(void){
	UpdateWindow(hWnd);
}

void Clistbox::Mover(int nPosX, int nPosY){
	Posicion.left = nPosX;
	Posicion.top = nPosY;
	MoveWindow(hWnd, nPosX, nPosY, Posicion.right, Posicion.top, true);  
}

void Clistbox::Dimensionar(int nAncho, int nLargo){
	Posicion.right = nAncho;
	Posicion.bottom = nLargo;
	MoveWindow(hWnd, Posicion.left, Posicion.top, nAncho, nLargo, true);  
}

void Clistbox::Mensaje(UINT uMensaje, WPARAM wParam, LPARAM lParam){
	SendMessage(hWnd, uMensaje, wParam, lParam);
}
