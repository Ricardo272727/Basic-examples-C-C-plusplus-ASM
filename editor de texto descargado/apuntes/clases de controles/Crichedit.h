// -----------------------------------------------------------------
// Crichedit.h --> Clase para crear richedits (02/08/2003)
// -----------------------------------------------------------------


class Crichedit{
protected:
	char szbuffer[65000];
	HMODULE hMod1;
	HMODULE hMod2;
public:
	// --> Propiedades
	HWND               hWnd;               // --> Handle del richedit
	HWND               hWndPadre;          // --> Handle de la ventana padre
	HINSTANCE          hInstancia;         // --> Instancia de la aplicacion
	RECT               Posicion;           // --> Posición del richedit
	WNDPROC            WndProcAddress;     // --> puntero a el WndProc del edit (por el sistema) 
	WNDPROC            WndProcAddressRich; // --> puntero a el WndProc (subclassing)
	// --> METODOS	
	void Crichedit::Crear(void);                                                                                 // --> Crea el richedit	
	void Crichedit::Destruir(void);                                                                              // --> Destruye el richedit	
	void Crichedit::Visible(BOOL Valor);                                                                         // --> Muestra / Oculta el richedit 	
	void Crichedit::Disponible(BOOL Valor);                                                                      // --> Habilita / Deshabilita el richedit    	
	void Crichedit::Texto(LPSTR lpszTexto);                                                                      // --> Establece el texto del richedit   	
	LPSTR Crichedit::Texto(void);                                                                                // --> Devuelve el texto del richedit	
	void Crichedit::Fuente(LONG lTamano, BOOL Negrita, BOOL Cursiva, BOOL Subrayado, LPSTR lpszNombreFuente);    // --> Establece la fuente del richedit 
	void Crichedit::Foco(void);                                                                                  // --> Da el foco al richedit
	void Crichedit::Actualizar(void);                                                                            // --> Actualiza el contenido del richedit
	void Crichedit::Mover(int nPosX, int nPosY);                                                                 // --> Mueve el richedit
	void Crichedit::Dimensionar(int nAncho, int nLargo);                                                         // --> Dimensiona el richedit
	int Crichedit::Mensaje(UINT uMensaje, WPARAM wParam, LPARAM lParam);                                         // --> Envia un mensaje al richedit
};

void Crichedit::Crear(void){
	if(LoadLibrary("librerias//riched20.dll")==NULL){
		MessageBox(NULL, "Error cargando riched20.dll", "", MB_OK);
	}else{
		hMod1 = GetModuleHandle("librerias//riched20.dll");
	}
	if(LoadLibrary("librerias//riched32.dll")==NULL){
		MessageBox(NULL, "Error cargando riched32.dll", "", MB_OK);
	}else{
		hMod2 = GetModuleHandle("librerias//riched32.dll");
	}	
	hWnd = CreateWindowEx(WS_EX_CLIENTEDGE, "RichEdit", (LPSTR) NULL, WS_CHILD|WS_VISIBLE|ES_MULTILINE|WS_VSCROLL|WS_HSCROLL, Posicion.left, Posicion.top, Posicion.right, Posicion.bottom, hWndPadre, 0, hInstancia, NULL);
	WndProcAddress = (WNDPROC) GetWindowLong(hWnd, GWL_WNDPROC);
	SetWindowLong(hWnd, GWL_WNDPROC, (LONG) WndProcAddressRich);
}

void Crichedit::Destruir(void){
	DestroyWindow(hWnd);
	hWnd=NULL;
	FreeLibrary(hMod1); 
	FreeLibrary(hMod2); 
}

void Crichedit::Visible(BOOL Valor){
	if(Valor){
		ShowWindow(hWnd, SW_SHOW);
		UpdateWindow(hWnd);
	}else{
		ShowWindow(hWnd, SW_HIDE);
		UpdateWindow(hWnd);
	}
}

void Crichedit::Disponible(BOOL Valor){
	EnableWindow(hWnd, Valor);
}

void Crichedit::Texto(LPSTR lpszTexto){
	SendMessage(hWnd, WM_SETTEXT, (WPARAM) -1, (LPARAM) lpszTexto);
}

LPSTR Crichedit::Texto(void){
	SendMessage(hWnd, WM_GETTEXT, (WPARAM) -1, (LPARAM) szbuffer);
	return szbuffer;
}

void Crichedit::Fuente(LONG lTamano, BOOL Negrita, BOOL Cursiva, BOOL Subrayado, LPSTR lpszNombreFuente){
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

void Crichedit::Foco(void){
	SetFocus(hWnd);
}

void Crichedit::Actualizar(void){
	UpdateWindow(hWnd);
}

void Crichedit::Mover(int nPosX, int nPosY){
	Posicion.left = nPosX;
	Posicion.top = nPosY;
	MoveWindow(hWnd, nPosX, nPosY, Posicion.right, Posicion.bottom, true);  
}

void Crichedit::Dimensionar(int nAncho, int nLargo){
	Posicion.right = nAncho;
	Posicion.bottom = nLargo;
	MoveWindow(hWnd, Posicion.left, Posicion.top, Posicion.right, Posicion.bottom, true);    
}

int Crichedit::Mensaje(UINT uMensaje, WPARAM wParam, LPARAM lParam){
	return (int) SendMessage(hWnd, uMensaje, wParam, lParam);
}

