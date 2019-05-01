// -----------------------------------------------------------------
// Cframe.h --> Clase para crear frames (17/07/2003)
// -----------------------------------------------------------------

class Cframe{
protected:
	char szBuffer[260];
public:
	// --> Propiedades
	HWND               hWnd;             // --> Handle del Frame
	HWND               hWndPadre;        // --> Handle de la ventana padre
	HINSTANCE          hInstancia;       // --> Instancia de la aplicación
	LPSTR              lpszTitulo;       // --> Titulo del Frame
	RECT               Posicion;         // --> Posición del Frame
	// --> Métodos
	void Cframe::Crear(void);                                                                                	// --> Crea el frame
	void Cframe::Destruir(void);                                                                                // --> Destruye el frame	
	void Cframe::Disponible(BOOL Valor);                                                                        // --> Habilita o no el frame	
	void Cframe::Visible(BOOL Valor);                                                                           // --> Muestra o no el frame	
	void Cframe::Fuente(LONG lTamano, BOOL Negrita, BOOL Cursiva, BOOL Subrayado, LPSTR lpszNombreFuente);      // --> Establece la fuente del frame
	void Cframe::Texto(LPSTR lpszTexto);                                                                        // --> Establece el texto del frame
	LPSTR Cframe::Texto(void);                                                                                  // --> Devuelve el texto del frame
	int Cframe::Mensaje(UINT uMensaje, WPARAM wParam, LPARAM lParam);                                           // --> Envia un mensaje al frame 
};

void Cframe::Crear(void){
	hWnd = CreateWindow("button", lpszTitulo, WS_CHILD|WS_VISIBLE|BS_GROUPBOX, Posicion.left, Posicion.top, Posicion.right, Posicion.bottom, hWndPadre, 0, hInstancia, NULL);
}

void Cframe::Destruir(void){
	DestroyWindow(hWnd);
	hWnd=NULL;
}

void Cframe::Disponible(BOOL Valor){
	EnableWindow(hWnd, Valor);
}

void Cframe::Visible(BOOL Valor){
	if(Valor){
		ShowWindow(hWnd, SW_SHOW);
		UpdateWindow(hWnd);
	}else{
		ShowWindow(hWnd, SW_HIDE);
		UpdateWindow(hWnd);
	}
}

void Cframe::Fuente(LONG lTamano, BOOL Negrita, BOOL Cursiva, BOOL Subrayado, LPSTR lpszNombreFuente){
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

void Cframe::Texto(LPSTR lpszTexto){
	SendMessage(hWnd, WM_SETTEXT, (WPARAM) 260, (LPARAM) lpszTexto);	
}

LPSTR Cframe::Texto(void){
	SendMessage(hWnd, WM_GETTEXT, (WPARAM) 260, (LPARAM) szBuffer);
	return szBuffer;
}

int Cframe::Mensaje(UINT uMensaje, WPARAM wParam, LPARAM lParam){
	return (int) SendMessage(hWnd, uMensaje, wParam, lParam);
}