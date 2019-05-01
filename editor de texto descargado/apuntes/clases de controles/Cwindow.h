// -----------------------------------------------------------------
// Cwindow.h --> Clase para crear ventanas (16/07/2003)
// -----------------------------------------------------------------

class Cwindow{
protected:
	char szBuffer[260];
public:
	// --> Propiedades
	HWND       hWnd;        // --> Handle de la ventana
	HWND       hWndPadre;   // --> Handle de la ventana padre
	HINSTANCE  hInstancia;  // --> Instancia de la aplicación
	DWORD      dwEstilo;    // --> Estilo(s) de la ventana
	RECT       Posicion;    // --> Posición de la ventana
	HICON      hIcono;      // --> Handle del icono
	HCURSOR    hCursor;     // --> Handle del cursor
	LPSTR      lpszMenu;    // --> Menu de la ventana
	LPSTR      lpszTitulo;  // --> Titulo de la ventana
	WNDPROC    WndProc;     // --> Función de la ventana
	HACCEL     hAccel;      // --> Acelerador de la ventana
	MSG        msg;         // --> Mensajes que recibe la ventana 
	int        nModoWin;    // --> Indica el modo inicial de la ventana (pasado desde el WinMain)
	// --> Métodos
	void Cwindow::Crear(void);                                            // --> Crea la ventana
	void Cwindow::Destruir(void);                                         // --> Destruye la ventana
	void Cwindow::Disponible(BOOL Valor);                                 // --> Habilita o no la ventana
	void Cwindow::Visible(BOOL Valor);                                    // --> Muestra o no la ventana
	void Cwindow::Foco(void);                                             // --> Da el foco a la ventana
	void Cwindow::Minimizar(void);                                        // --> Minimiza la ventana
	void Cwindow::Maximizar(void);                                        // --> Maximiza la ventana
	void Cwindow::Restaurar(void);                                        // --> Restaura la ventana
	void Cwindow::Texto(LPSTR lpszTexto);                                 // --> Establece el texto de la ventana
	LPSTR Cwindow::Texto(void);                                           // --> Devuelve el texto de la ventana
	void Cwindow::Mover(int nPosX, int nPosY);                            // --> Mueve la ventana
	void Cwindow::Dimensionar(int nAncho, int nLargo);                    // --> Dimensiona la ventana
	int Cwindow::Mensaje(UINT uMensaje, WPARAM wParam, LPARAM lParam);   // --> Envia un mensaje a la ventana
	void Cwindow::Actualizar(void);                                       // --> Actualiza el contenido de la ventana        
};

void Cwindow::Crear(void){
   WNDCLASSEX Clase;
   ZeroMemory (&Clase, sizeof(WNDCLASSEX));
   ZeroMemory (&msg, sizeof(MSG));
   Clase.hInstance = hInstancia;
   Clase.lpszClassName = lpszTitulo;
   Clase.lpfnWndProc = WndProc;
   Clase.style = CS_HREDRAW | CS_VREDRAW | CS_BYTEALIGNCLIENT | CS_BYTEALIGNWINDOW | CS_OWNDC;
   Clase.cbSize = sizeof (WNDCLASSEX);
   Clase.hIcon = hIcono;
   Clase.hIconSm = hIcono;  
   Clase.hCursor = hCursor; 
   Clase.lpszMenuName = lpszMenu; 
   Clase.cbClsExtra = 0;
   Clase.cbWndExtra = 0;
   Clase.hbrBackground = (HBRUSH) (COLOR_BTNFACE+1);
   RegisterClassEx (&Clase);
   if (hWndPadre == NULL){
		hWnd = CreateWindowEx(WS_EX_CONTROLPARENT, lpszTitulo, lpszTitulo, dwEstilo, Posicion.left, Posicion.top, Posicion.right, Posicion.bottom, HWND_DESKTOP, NULL, hInstancia, NULL);
   }else{
		hWnd = CreateWindowEx(WS_EX_CONTROLPARENT, lpszTitulo, lpszTitulo, dwEstilo, Posicion.left, Posicion.top, Posicion.right, Posicion.bottom, hWndPadre, NULL, hInstancia, NULL);
   }
   ShowWindow(hWnd, nModoWin);
   UpdateWindow(hWnd);
   while(GetMessage(&msg, NULL, 0, 0)){
      if (!TranslateAccelerator(hWnd, hAccel, &msg)){
	   	  TranslateMessage (&msg);
	      DispatchMessage  (&msg);
	  }
   }
	
}

void Cwindow::Destruir(void){
	DestroyWindow(hWnd);
	hWnd=NULL;
}

void Cwindow::Disponible(BOOL Valor){
	EnableWindow(hWnd, Valor);
}

void Cwindow::Visible(BOOL Valor){
	if(Valor) ShowWindow(hWnd, SW_SHOW);
	if(!Valor) ShowWindow(hWnd, SW_HIDE);
}

void Cwindow::Foco(void){
	SetFocus(hWnd);
}

void Cwindow::Minimizar(void){
	ShowWindow(hWnd, SW_MINIMIZE);
}

void Cwindow::Maximizar(void){
	ShowWindow(hWnd, SW_MAXIMIZE);
}

void Cwindow::Restaurar(void){
	ShowWindow(hWnd, SW_RESTORE);
}

void Cwindow::Texto(LPSTR lpszTexto){
	SendMessage(hWnd, WM_SETTEXT, (WPARAM) 260, (LPARAM) lpszTexto);
}

LPSTR Cwindow::Texto(void){
	SendMessage(hWnd, WM_GETTEXT, (WPARAM) 260, (LPARAM) szBuffer);
	return szBuffer;
}

void Cwindow::Mover(int nPosX, int nPosY){
	Posicion.left = nPosX;
	Posicion.top = nPosY;
	MoveWindow(hWnd, nPosX, nPosY, Posicion.right, Posicion.bottom, true);  
}

void Cwindow::Dimensionar(int nAncho, int nLargo){
	Posicion.right = nAncho;
	Posicion.bottom = nLargo;
	MoveWindow(hWnd, Posicion.left, Posicion.top, Posicion.right, Posicion.bottom, true);    
}

int Cwindow::Mensaje(UINT uMensaje, WPARAM wParam, LPARAM lParam){
    return (int) SendMessage(hWnd, uMensaje, wParam, lParam);
}

void Cwindow::Actualizar(void){
	UpdateWindow(hWnd);
}

