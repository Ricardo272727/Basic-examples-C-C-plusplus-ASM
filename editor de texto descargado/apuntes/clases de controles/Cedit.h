// -----------------------------------------------------------------
// Cedit.h --> Clase para crear edits (19/07/2003)
// -----------------------------------------------------------------

class Cedit{
protected:
	char szbuffer[260];
	LONG WndProc;
public:
	// --> Propiedades
	HWND             hWnd;               // --> Handle del edit
	HWND             hWndPadre;          // --> Handle de la ventana padre
	HINSTANCE        hInstancia;         // --> Instancia de la aplicación
	DWORD            dwEstilo;           // --> Estilo del edit
	LPSTR            lpszTexto;          // --> Texto del edit
	RECT             Posicion;           // --> Posición del edit
	WNDPROC          WndProcAddress;     // --> puntero a el WndProc del edit (por el sistema) 
	WNDPROC          WndProcAddressEdit; // --> puntero a el WndProc (subclassing)
	// --> Métodos
	void Cedit::Crear(void);                                                                     	         // --> Crea el edit	
	void Cedit::Destruir(void);                                                                              // --> Destruye el edit	
	void Cedit::Disponible(BOOL Valor);                                                                      // --> Habilita o no el edit
	void Cedit::Visible(BOOL Valor);                                                                         // --> Muestra o no el edit 
	void Cedit::Texto(LPSTR lpszTexto);                                                                      // --> Establece el texto del edit
	LPSTR Cedit::Texto(void);                                                                                // --> Devuelve el texto del edit	
	void Cedit::Fuente(LONG lTamano, BOOL Negrita, BOOL Cursiva, BOOL Subrayado, LPSTR lpszNombreFuente);    // --> Establece la fuente del edit 
	void Cedit::Foco(void);                                                                                  // --> Da el foco al edit
	void Cedit::Actualizar(void);                                                                            // --> Actualiza el contenido del edit
	int Cedit::Mensaje(UINT uMensaje, WPARAM wParam, LPARAM lParam);                                         // --> Envia un mensaje al edit 
	void Cedit::Mover(int nPosX, int nPosY);                                                                 // --> Mueve el edit
	void Cedit::Dimensionar(int nAncho, int nLargo);                                                         // --> Dimensiona el tamaño del edit
	int Cedit::NumeroCaracteres(void);                                                                       // --> Devuelve el numero de caracteres en el edit 
	void Cedit::NumeroCaracteres(int nNumero);                                                               // --> Establece el numero de caracteres limite del edit   
};

void Cedit::Crear(void){
	hWnd = CreateWindowEx(WS_EX_CLIENTEDGE|WS_EX_CONTROLPARENT, "edit", lpszTexto, dwEstilo, Posicion.left, Posicion.top, Posicion.right, Posicion.bottom, hWndPadre, 0, hInstancia, NULL);
	WndProcAddress = (WNDPROC) GetWindowLong(hWnd, GWL_WNDPROC);
	SetWindowLong(hWnd, GWL_WNDPROC, (LONG) WndProcAddressEdit);
}

void Cedit::Destruir(void){
	DestroyWindow(hWnd);
	hWnd=NULL;
}	

void Cedit::Disponible(BOOL Valor){
	EnableWindow(hWnd, Valor);
}

void Cedit::Visible(BOOL Valor){
	if(Valor){
		ShowWindow(hWnd, SW_SHOW);
		UpdateWindow(hWnd);
	}else{
		ShowWindow(hWnd, SW_HIDE);
		UpdateWindow(hWnd);
	}
}

void Cedit::Texto(LPSTR lpszTexto){
	SendMessage(hWnd, WM_SETTEXT, (WPARAM) -1, (LPARAM) lpszTexto);
}

LPSTR Cedit::Texto(void){
	SendMessage(hWnd, WM_GETTEXT, (WPARAM) -1, (LPARAM) szbuffer);
	return szbuffer;
}

void Cedit::Fuente(LONG lTamano, BOOL Negrita, BOOL Cursiva, BOOL Subrayado, LPSTR lpszNombreFuente){
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

void Cedit::Foco(void){
	SetFocus(hWnd);
}

void Cedit::Actualizar(void){
	UpdateWindow(hWnd);
}

int Cedit::Mensaje(UINT uMensaje, WPARAM wParam, LPARAM lParam){
	return (int) SendMessage(hWnd, uMensaje, wParam, lParam);
}

void Cedit::Mover(int nPosX, int nPosY){
	Posicion.left = nPosX;
	Posicion.top = nPosY;
	MoveWindow(hWnd, nPosX, nPosY, Posicion.right, Posicion.bottom, true);  
}

void Cedit::Dimensionar(int nAncho, int nLargo){
	Posicion.right = nAncho;
	Posicion.bottom = nLargo;
	MoveWindow(hWnd, Posicion.left, Posicion.top, Posicion.right, Posicion.bottom, true);    
}

int Cedit::NumeroCaracteres(void){
	return (int) SendMessage(hWnd, WM_GETTEXTLENGTH, 0, 0);
}

void Cedit::NumeroCaracteres(int nNumero){
	SendMessage(hWnd, EM_SETLIMITTEXT, (WPARAM) nNumero, 0);
}