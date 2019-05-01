// -----------------------------------------------------------------
// Ccombobox.h --> Clase para crear combobox (17/07/2003)
// -----------------------------------------------------------------

class Ccombobox{
protected:
	char szbuffer[260];
public:
	// --> Propiedades
	HWND                 hWnd;                // --> Handle del combobox
	HWND                 hWndPadre;           // --> Handle de la ventana padre
	HINSTANCE            hInstancia;          // --> Instancia de la aplicación
	int                  X;                   // --> Posición X del combobox
	int                  Y;                   // --> Posición Y del combobox
	int                  nAncho;              // --> Ancho del combobox
	WNDPROC              WndProcAddress;      // --> puntero a el WndProc del sistema
	WNDPROC              WndProcAddressCombo; // --> puntero a el WndProc (subclassing)
	// --> Métodos
	void Ccombobox::Crear(void);                                                   	                            // --> Crea el combobox
	void Ccombobox::Destruir(void);                                                                             // --> Destruye el combobox  
	void Ccombobox::Visible(BOOL Valor);                                                                        // --> Muestra o no el combobox
	void Ccombobox::Disponible(BOOL Valor);                                                                     // --> Habilita o no el combobox
	void Ccombobox::AgregarItem(LPSTR lpszItem);                                                                // --> Agrega un item al combobox  
	void Ccombobox::EliminarItem(int nIndice);                                                                  // --> Eliminar un item del combobox 
	int Ccombobox::NumeroItems(void);                                                                           // --> Devuelve el número de items del combobox   
	void Ccombobox::Limpiar(void);                                                                              // --> Limpia el combobox  
	void Ccombobox::SeleccionarItem(int nIndice);                                                               // --> Selecciona un item del combobox
	int Ccombobox::ItemSeleccionado(void);                                                                      // --> Devuelve el indice del item seleccionado 
	int Ccombobox::BuscarItem(LPSTR lpszItem);                                                                  // --> Busca un item en el combobox   
	LPSTR Ccombobox::TextoItem(int nIndice);                                                                    // --> Devuelve el texto de un item en el combobox
	void Ccombobox::Fuente(LONG lTamano, BOOL Negrita, BOOL Cursiva, BOOL Subrayado, LPSTR lpszNombreFuente);   // --> Establece la fuente del checkbox
	void Ccombobox::Actualizar(void);                                                                           // --> Actualiza el contenido del checkbox
	void Ccombobox::Foco(void);                                                                                 // --> Pone el foco en el combobox 
	void Ccombobox::Mover(int nPosX, int nPosY);                                                                // --> Mueve el combobox 
	int Ccombobox::Mensaje(UINT uMensaje, WPARAM wParam, LPARAM lParam);                                        // --> Envia un mensaje al combobox  
};

void Ccombobox::Crear(void){
	 hWnd = CreateWindow("combobox", "", WS_CHILD|WS_VISIBLE|CBS_DROPDOWNLIST|CBS_HASSTRINGS|CBS_DISABLENOSCROLL, X, Y, nAncho, 140, hWndPadre, 0, hInstancia, NULL);
	 WndProcAddress = (WNDPROC) GetWindowLong(hWnd, GWL_WNDPROC);
	 SetWindowLong(hWnd, GWL_WNDPROC, (LONG) WndProcAddressCombo);	
}

void Ccombobox::Destruir(void){
	DestroyWindow(hWnd);
	hWnd=NULL;
}

void Ccombobox::Visible(BOOL Valor){
	if(Valor){
		ShowWindow(hWnd, SW_SHOW);
		UpdateWindow(hWnd);
	}else{
		ShowWindow(hWnd, SW_HIDE);
		UpdateWindow(hWnd);
	}
}

void Ccombobox::Disponible(BOOL Valor){
	EnableWindow(hWnd, Valor);
}

void Ccombobox::AgregarItem(LPSTR lpszItem){
	SendMessage(hWnd, CB_ADDSTRING, 0, (LPARAM) (LPCTSTR) lpszItem);	
}

void Ccombobox::EliminarItem(int nIndice){
	SendMessage(hWnd, CB_DELETESTRING, (WPARAM) nIndice, 0);
}

int Ccombobox::NumeroItems(void){
	return (int) SendMessage(hWnd, CB_GETCOUNT, 0, 0);
}

void Ccombobox::Limpiar(void){
	SendMessage(hWnd, CB_RESETCONTENT, 0, 0);
}

void Ccombobox::SeleccionarItem(int nIndice){
	SendMessage(hWnd, CB_SETCURSEL, (WPARAM) nIndice, 0);
}

int Ccombobox::ItemSeleccionado(void){
	return (int) SendMessage(hWnd, CB_GETCURSEL, 0, 0 );
}

int Ccombobox::BuscarItem(LPSTR lpszItem){
    return (int) SendMessage(hWnd, CB_FINDSTRING, 0, (LPARAM) (LPCSTR) lpszItem);
}

LPSTR Ccombobox::TextoItem(int nIndice){
	SendMessage(hWnd, CB_GETLBTEXT, nIndice, (LPARAM) (LPCSTR) szbuffer);
	return szbuffer;
}

void Ccombobox::Fuente(LONG lTamano, BOOL Negrita, BOOL Cursiva, BOOL Subrayado, LPSTR lpszNombreFuente){
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

void Ccombobox::Actualizar(void){
	UpdateWindow(hWnd);
}

void Ccombobox::Foco(void){
	SetFocus(hWnd);
}

void Ccombobox::Mover(int nPosX, int nPosY){
	X = nPosX;
	Y = nPosY;
	MoveWindow(hWnd, nPosX, nPosY, nAncho, 140, true);
}

int Ccombobox::Mensaje(UINT uMensaje, WPARAM wParam, LPARAM lParam){
	return (int) SendMessage(hWnd, uMensaje, wParam, lParam);
}