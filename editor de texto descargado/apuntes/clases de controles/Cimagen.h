// -----------------------------------------------------------------
// Cimagen.h --> Clase para crear imagenes (17/07/2003)
// -----------------------------------------------------------------

class Cimagen{
public:
	    // --> Propiedades
		HWND         hWnd;           // --> Handle de la imagen
		HWND         hWndPadre;      // --> Handle de la ventana padre
		HINSTANCE    hInstancia;     // --> Instancia de la aplicación
		LPSTR        lpszImagen;     // --> Nombre de la imagen en el archivo de recursos
		DWORD        dwEstilo;       // --> Estilo de la imagen
		RECT         Posicion;       // --> Coordenadas del rectangulo que contendra la imagen
	    // --> Métodos
		void Cimagen::Crear(void);                                	         // --> Crea la imagen    
		void Cimagen::Destruir(void);                                        // --> Destruye la imagen
		void Cimagen::Visible(BOOL Valor);                                   // --> Muestra o no la imagen
		void Cimagen::Actualizar(void);                                      // --> Actualiza el contenido de la imagen
		void Cimagen::Mensaje(UINT uMensaje, WPARAM wParam, LPARAM lParam);  // --> Envia un mensaje a la imagen
};

void Cimagen::Actualizar(void){
	UpdateWindow(hWnd);
}

void Cimagen::Crear(void){
	hWnd = CreateWindowEx(0,"static", lpszImagen, dwEstilo, Posicion.left, Posicion.top, Posicion.right, Posicion.bottom, hWndPadre, 0, hInstancia, NULL);
}

void Cimagen::Destruir(void){
	DestroyWindow(hWnd);
}

void Cimagen::Visible(BOOL Valor){
	if(Valor){
		ShowWindow(hWnd, SW_SHOW);
		UpdateWindow(hWnd);
	}else{
		ShowWindow(hWnd, SW_HIDE);
		UpdateWindow(hWnd);
	}
}

