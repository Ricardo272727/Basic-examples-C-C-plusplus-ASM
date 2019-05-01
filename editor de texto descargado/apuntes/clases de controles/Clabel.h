// -----------------------------------------------------------------
// Clabel.h --> Clase para crear labels (18/07/2003)
// -----------------------------------------------------------------

class Clabel{
protected:
	char szbuffer[260];
public:
	// --> Propiedades
	HWND          hWnd;           // --> Handle del label
	HWND          hWndPadre;      // --> Handle de la ventana padre
	HINSTANCE	  hInstancia;     // --> Instancia de la aplicación
	LPSTR         lpszTexto;      // --> Texto del label
	DWORD         dwEstilo;       // --> Estilo del label
	RECT          Posicion;       // --> Posición del label
	// --> Métodos
	void Clabel::Crear(void);                                                                               // --> Crea el label
	void Clabel::Destruir(void);                                                                            // --> Destruye el label
	void Clabel::Visible(BOOL Valor);                                                                       // --> Muestra o no el label
	void Clabel::Texto(LPSTR lpszTexto);                                                                    // --> Establece el texto del label   
	LPSTR Clabel::Texto(void);                                                                              // --> Devuelve el texto del label  
	void Clabel::Fuente(LONG lTamano, BOOL Negrita, BOOL Cursiva, BOOL Subrayado, LPSTR lpszNombreFuente);  // --> Establece la fuente del label
	void Clabel::Mover(int nPosX, int nPosY);                                                               // --> Mueve el label    
	void Clabel::Dimensionar(int nAncho, int nLargo);                                                       // --> Dimensiona el tamaño del label     
	void Clabel::Actualizar(void);                                                                          // --> Actualiza el contenido del label   
	void Clabel::Mensaje(UINT uMensaje, WPARAM wParam, LPARAM lParam);                                      // --> Envia un mensaje al label       
};	

void Clabel::Crear(void){
	hWnd = CreateWindow("static", lpszTexto, dwEstilo, Posicion.left, Posicion.top, Posicion.right, Posicion.bottom, hWndPadre, 0, hInstancia,NULL);
}

void Clabel::Destruir(void){
	DestroyWindow(hWnd);
}

void Clabel::Visible(BOOL Valor){
	if(Valor){
		ShowWindow(hWnd, SW_SHOW);
		UpdateWindow(hWnd);
	}else{
		ShowWindow(hWnd, SW_HIDE);
		UpdateWindow(hWnd);
	}
}

void Clabel::Texto(LPSTR lpszTexto){
	SendMessage(hWnd, WM_SETTEXT, (WPARAM) 260, (LPARAM) lpszTexto);
}

LPSTR Clabel::Texto(void){
	SendMessage(hWnd, WM_GETTEXT, (WPARAM) 260, (LPARAM) szbuffer);	
	return szbuffer;
}

void Clabel::Fuente(LONG lTamano, BOOL Negrita, BOOL Cursiva, BOOL Subrayado, LPSTR lpszNombreFuente){
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

void Clabel::Actualizar(void){
	UpdateWindow(hWnd);
}

void Clabel::Mover(int nPosX, int nPosY){
	Posicion.left = nPosX;
	Posicion.top = nPosY;
	MoveWindow(hWnd, nPosX, nPosY, Posicion.right, Posicion.bottom, true);  
}

void Clabel::Dimensionar(int nAncho, int nLargo){
	Posicion.right = nAncho;
	Posicion.bottom = nLargo;
	MoveWindow(hWnd, Posicion.left, Posicion.top, Posicion.right, Posicion.bottom, true);    
}

void Clabel::Mensaje(UINT uMensaje, WPARAM wParam, LPARAM lParam){
	SendMessage(hWnd, uMensaje, wParam, lParam);
}
