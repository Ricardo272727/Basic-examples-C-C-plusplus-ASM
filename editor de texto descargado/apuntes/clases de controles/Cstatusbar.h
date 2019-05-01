// -----------------------------------------------------------------
// Cstatusbar.h --> Clase para crear statusbar (19/07/2003)
// -----------------------------------------------------------------

class Cstatusbar{
protected:
	char szbuffer[260];
public:
	// --> Propiedades
	HWND         hWnd;            // --> Handle del statusbar
	HWND         hWndPadre;       // --> Handle de la ventana padre
	HINSTANCE    hInstancia;      // --> Instancia de la aplicación 
	DWORD        dwEstilo;        // --> Estilo(s) del statusbar
	// --> Métodos
	void Cstatusbar::Crear(void);                                                                        // --> Crea el statusbar
	void Cstatusbar::Destruir(void);                                                                     // --> Destruye el statusbar 
	void Cstatusbar::Visible(BOOL Valor);                                                                // --> Muestra o no el statusbar
	void Cstatusbar::Texto(LPSTR lpszTexto);                                                             // --> Establece el texto de un panel
	LPSTR Cstatusbar::Texto(void);                                                                       // --> Devuelve el texto de un panel 
	void Cstatusbar::Actualizar(void);                                                                   // --> Actualiza el contenido del statusbar 
	void Cstatusbar::Dimensionar(int nAncho, int nLargo);                                                // --> Dimensiona el statusbar   
};

void Cstatusbar::Crear(void){
	hWnd = CreateWindowEx(0, STATUSCLASSNAME, (LPCTSTR) NULL, dwEstilo, 0, 0, 0, 0, hWndPadre, (HMENU) NULL, hInstancia, NULL);  
}

void Cstatusbar::Destruir(void){
	DestroyWindow(hWnd);
	hWnd=NULL;
}

void Cstatusbar::Visible(BOOL Valor){
	if(Valor){
		ShowWindow(hWnd, SW_SHOW);
		UpdateWindow(hWnd);
	}else{
		ShowWindow(hWnd, SW_HIDE);
		UpdateWindow(hWnd);
	}
}

void Cstatusbar::Texto(LPSTR lpszTexto){
	SendMessage(hWnd, SB_SETTEXT, (WPARAM) 0 | 0, (LPARAM) lpszTexto);
}

LPSTR Cstatusbar::Texto(void){
	SendMessage(hWnd, SB_GETTEXT, (WPARAM) 0 | 0, (LPARAM) szbuffer);	
	return szbuffer;
}

void Cstatusbar::Actualizar(void){
	UpdateWindow(hWnd);
}

void Cstatusbar::Dimensionar(int nAncho, int nLargo){
	MoveWindow(hWnd, 0, 0, nAncho, nLargo, true);    
}