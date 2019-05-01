// -----------------------------------------------------------------
// Ccheckbox.h --> Clase para crear checkbox (17/07/2003)
// -----------------------------------------------------------------

class Ccheckbox{
protected:
	char szBuffer[260];
public:
	// --> Propiedades
	HWND              hWnd;                // --> Handle del checkbox
	HWND              hWndPadre;           // --> Handle de la ventana padre
	HINSTANCE         hInstancia;          // --> Instancia de la aplicación
	LPSTR             lpszTexto;           // --> Texto del checkbox
	RECT              Posicion;            // --> Posición del checkbox
	WNDPROC           WndProcAddress;      // --> puntero a el WndProc del sistema
	WNDPROC           WndProcAddressCheck; // --> puntero a el WndProc (subclassing)
	// --> Métodos
	void Ccheckbox::Crear(void);                                                                                	// --> Crea el checkbox
	void Ccheckbox::Destruir(void);                                                                                 // --> Destruye el checkbox
	void Ccheckbox::Visible(BOOL Valor);                                                                            // --> Muestra o no el checkbox
	void Ccheckbox::Disponible(BOOL Valor);                                                                         // --> Habilita o no el checkbox
	void Ccheckbox::Estado(BOOL Valor);                                                                             // --> Establece el estado del checkbox
	BOOL Ccheckbox::Estado(void);                                                                                   // --> Devuelve el estado del checkbox
	void Ccheckbox::Fuente(LONG lTamano, BOOL Negrita, BOOL Cursiva, BOOL Subrayado, LPSTR lpszNombreFuente);       // --> Establece la fuente del checkbox
	void Ccheckbox::Mover(int nPosX, int nPosY);                                                                    // --> Mueve el checkbox  
	void Ccheckbox::Dimensionar(int nAncho, int nLargo);                                                            // --> Dimensiona el tamaño del checkbox
	void Ccheckbox::Actualizar(void);                                                                               // --> Actualiza el contenido del checkbox
	void Ccheckbox::Foco(void);                                                                                     // --> Da el foco al checkbox
	int Ccheckbox::Mensaje(UINT uMensaje, WPARAM wParam, LPARAM lParam);                                           // --> Envia un mensaje al checkbox
	void Ccheckbox::Texto(LPSTR lpszTexto);                                                                         // --> Establece el texto del checkbox
	LPSTR Ccheckbox::Texto(void);                                                                                   // --> Devuelve el texto del checkbox
};

void Ccheckbox::Crear(void){
	hWnd = CreateWindow("button", lpszTexto, WS_VISIBLE|WS_CHILD|BS_AUTOCHECKBOX, Posicion.left, Posicion.top, Posicion.right, Posicion.bottom, hWndPadre, 0, hInstancia, NULL);
	WndProcAddress = (WNDPROC) GetWindowLong(hWnd, GWL_WNDPROC);
	SetWindowLong(hWnd, GWL_WNDPROC, (LONG) WndProcAddressCheck);	
}

void Ccheckbox::Destruir(void){
	DestroyWindow(hWnd);
	hWnd = NULL;
}

void Ccheckbox::Visible(BOOL Valor){
	if(Valor){
		ShowWindow(hWnd, SW_SHOW);
		UpdateWindow(hWnd);
	}else{
		ShowWindow(hWnd, SW_HIDE);
		UpdateWindow(hWnd);
	}
}

void Ccheckbox::Disponible(BOOL Valor){
	EnableWindow(hWnd, Valor);
}

void Ccheckbox::Estado(BOOL Valor){
	if (Valor){
		SendMessage(hWnd, BM_SETCHECK, (WPARAM) 1, 0);
	}else{
		SendMessage(hWnd, BM_SETCHECK, (WPARAM) 0, 0);
	}
}

BOOL Ccheckbox::Estado(void){
	if(SendMessage(hWnd, BM_GETCHECK, 0, 0) == 1){
		return true;
	}else if(SendMessage(hWnd, BM_GETCHECK, 0, 0) == 0){
		return false;
	}else{
		return false;
	}
}

void Ccheckbox::Fuente(LONG lTamano, BOOL Negrita, BOOL Cursiva, BOOL Subrayado, LPSTR lpszNombreFuente){
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

void Ccheckbox::Mover(int nPosX, int nPosY){
	Posicion.left = nPosX;
	Posicion.top = nPosY;
	MoveWindow(hWnd, nPosX, nPosY, Posicion.right, Posicion.bottom, true);  
}

void Ccheckbox::Dimensionar(int nAncho, int nLargo){
	Posicion.right = nAncho;
	Posicion.bottom = nLargo;
	MoveWindow(hWnd, Posicion.left, Posicion.top, nAncho, nLargo, true);  
}

void Ccheckbox::Actualizar(void){
	UpdateWindow(hWnd);
}

void Ccheckbox::Foco(void){
	SetFocus(hWnd);
}

int Ccheckbox::Mensaje(UINT uMensaje, WPARAM wParam, LPARAM lParam){
	return (int) SendMessage(hWnd, uMensaje, wParam, lParam);
}

LPSTR Ccheckbox::Texto(void){
	SendMessage(hWnd, WM_GETTEXT, (WPARAM) 260, (LPARAM) szBuffer);
	return szBuffer;
}

void Ccheckbox::Texto(LPSTR lpszTexto){
	SendMessage(hWnd, WM_SETTEXT, (WPARAM) 260, (LPARAM) lpszTexto);
}