// -----------------------------------------------------------------
// Cbutton.h --> Clase para crear botones (16/07/2003)
// -----------------------------------------------------------------

class Cbutton{
protected:
	char szbuffer[260];
	Cimagen img;
public:
	// --> Propiedades
	HWND             hWnd;                  // --> Handle del botón
	HWND             hWndPadre;             // --> Handle de la ventana padre
	HINSTANCE        hInstancia;            // --> Instancia de la aplicacion
	DWORD            dwEstilo;              // --> Estilo(s) del botón
	RECT             Posicion;              // --> Posición del botón
	LPSTR            lpszTexto;             // --> Texto del botón
	WNDPROC          WndProcAddress;        // --> puntero a el WndProc del botón (por el sistema) 
	WNDPROC          WndProcAddressButton;  // --> puntero a el WndProc (subclassing)
	// --> Métodos
	void Cbutton::Crear(void);                                                                                   // --> Crea el botón    
	void Cbutton::Destruir(void);                                                                                // --> Destruye el botón    
	void Cbutton::Visible(BOOL Valor);                                                                           // --> Muestra o no el botón
	void Cbutton::Disponible(BOOL Valor);                                                                        // --> Habilita o no el botón
	void Cbutton::Texto(LPSTR lpszTexto);                                                                        // --> Establece el texto del botón    
	LPSTR Cbutton::Texto(void);                                                                                  // --> Devuelve el texto del botón    
	void Cbutton::Fuente(LONG lTamano, BOOL Negrita, BOOL Cursiva, BOOL Subrayado, LPSTR lpszNombreFuente);      // --> Establece la fuente del botón 
	void Cbutton::Foco(void);                                                                                    // --> Da el foco al botón      
	void Cbutton::Mover(int nPosX, int nPosY);                                                                   // --> Mueve el botón
	void Cbutton::Dimensionar(int nAncho, int nLargo);                                                           // --> Dimensiona el botón
	int Cbutton::Mensaje(UINT uMensaje, WPARAM wParam, LPARAM lParam);                                           // --> Envia un mensaje al botón
	void Cbutton::Actualizar(void);                                                                              // --> Actualiza el contenido del botón 
	void Cbutton::BotonIcono(LPSTR lpszIcono);                                                                   // --> Establece el icono del botón 
	void Cbutton::RestaurarIcono(void);                                                                          // --> Restaura el icono del botón
	void Cbutton::BotonImagen(LPSTR lpszImagen);                                                                 // --> Establece una imagen en el botón      
};

void Cbutton::Crear(void){
	hWnd = CreateWindow("BUTTON", lpszTexto, dwEstilo, Posicion.left, Posicion.top, Posicion.right, Posicion.bottom, hWndPadre, 0, hInstancia, NULL);
	WndProcAddress = (WNDPROC) GetWindowLong(hWnd, GWL_WNDPROC);
	SetWindowLong(hWnd, GWL_WNDPROC, (LONG) WndProcAddressButton);	
}

void Cbutton::Destruir(void){
	DestroyWindow(hWnd);
	hWnd=NULL;
}

void Cbutton::Visible(BOOL Valor){
	if(Valor){
		ShowWindow(hWnd, SW_SHOW);
		UpdateWindow(hWnd);
	}else{
		ShowWindow(hWnd, SW_HIDE);
		UpdateWindow(hWnd);
	}
}

void Cbutton::Disponible(BOOL Valor){
	EnableWindow(hWnd,Valor);
}

void Cbutton::Texto(LPSTR lpszTexto){
	SendMessage(hWnd, WM_SETTEXT, (WPARAM) 260, (LPARAM) lpszTexto);
}

LPSTR Cbutton::Texto(void){
	SendMessage(hWnd, WM_GETTEXT, (WPARAM) 260, (LPARAM) szbuffer);
	return szbuffer;
}

void Cbutton::Fuente(LONG lTamano, BOOL Negrita, BOOL Cursiva, BOOL Subrayado, LPSTR lpszNombreFuente){
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

void Cbutton::Foco(void){
	SetFocus(hWnd);
}

void Cbutton::Mover(int nPosX, int nPosY){
	Posicion.left = nPosX;
	Posicion.top = nPosY;
	MoveWindow(hWnd, nPosX, nPosY, Posicion.right, Posicion.bottom, true);  
}

void Cbutton::Dimensionar(int nAncho, int nLargo){
	Posicion.right = nAncho;
	Posicion.bottom = nLargo;
	MoveWindow(hWnd, Posicion.left, Posicion.top, Posicion.right, Posicion.bottom, true);    
}

int Cbutton::Mensaje(UINT uMensaje, WPARAM wParam, LPARAM lParam){
	return (int) SendMessage(hWnd, uMensaje, wParam, lParam);
}

void Cbutton::Actualizar(void){
	UpdateWindow(hWnd);
}

void Cbutton::BotonIcono(LPSTR lpszIcono){
	img.hWndPadre = hWnd;
	img.dwEstilo = CI_ICONO;
	img.hInstancia = hInstancia;
	img.lpszImagen = lpszIcono;
	img.Posicion.left = 5;
	img.Posicion.top = 4;
	img.Posicion.right = 32;
	img.Posicion.bottom = 32; 
	Dimensionar(Posicion.right, 40);
	img.Crear(); 
}

void Cbutton::BotonImagen(LPSTR lpszImagen){
	img.hWndPadre = hWnd;
	img.dwEstilo = CI_BITMAP;
	img.hInstancia = hInstancia;
	img.lpszImagen = lpszImagen;
	img.Posicion.left = 5;
	img.Posicion.top = 4;
	img.Posicion.right = 14;
	img.Posicion.bottom = 14; 
	img.Crear(); 
}

void Cbutton::RestaurarIcono(void){
	img.Crear(); 
}

