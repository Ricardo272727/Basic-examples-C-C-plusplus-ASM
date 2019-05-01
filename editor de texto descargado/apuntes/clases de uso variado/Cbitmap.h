// -----------------------------------------------------------------
// Cbitmap.h --> Clase para mostrar bitmaps (17/07/2003)
// -----------------------------------------------------------------

class Cbitmap{
public:
	// --> Propiedades
	HWND         hWnd;           // --> Handle de la ventana que contiene el bitmap 
	HWND         hWndPadre;      // --> Handle de la ventana padre
	HINSTANCE    hInstancia;     // --> Instancia de la aplicación
	RECT         Posicion;       // --> Coordenadas del rectangulo que contendra la imagen
	HDC          hdc;            // --> HDC de la imagen
	int          hdcaux;         // --> HDC auxiliar
	HDC          hdcComp;        // --> HDC compatible
	PAINTSTRUCT  ps;             // --> Paintstruct
	HBITMAP      bmp;            // --> Handle del bitmap
	BITMAP       MapaBmp;        // --> Mapeado del bitmap
	RECT         rx;             // --> Area cliente de la imagen 	
	// --> Métodos
	void Cbitmap::CargarBMP(LPSTR lpszBMP);                                             // --> Carga un bitmap desde un archivo
	void Cbitmap::RestaurarBMP(void);                                                   // --> Restaura el bitmap  
	void Cbitmap::Crear(void);                                                          // --> Crea el bitmap
	void Cbitmap::Destruir(void);                                                       // --> Destrye el bitmap
	void Cbitmap::Actualizar(void);                                                     // --> Actualiza el contenido del bitmap  
	void Cbitmap::Mensaje(UINT uMensaje, WPARAM wParam, LPARAM lParam);                 // --> Envia un mensaje al bitmap      
};

void Cbitmap::Crear(void){
	hWnd = CreateWindowEx(0,"static", "", WS_CHILD|WS_VISIBLE|SS_BITMAP|SS_CENTERIMAGE|SS_NOTIFY, Posicion.left, Posicion.top, Posicion.right, Posicion.bottom, hWndPadre, 0, hInstancia, NULL); 
}

void Cbitmap::CargarBMP(LPSTR lpszBMP){
	hdc = GetDC(hWnd);
	hdcComp = CreateCompatibleDC(hdc);
	hdcaux = SaveDC(hdc);
	bmp = (HBITMAP) LoadImage(NULL, lpszBMP, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	SelectObject(hdcComp, bmp);
	GetObject(bmp, sizeof(MapaBmp), &MapaBmp);
	GetClientRect (hWnd, &rx);
	StretchBlt(hdc, 0, 0, (rx.right - rx.left), (rx.bottom - rx.top), hdcComp, 0, 0, MapaBmp.bmWidth, MapaBmp.bmHeight, SRCCOPY);
	ReleaseDC(hWnd, hdc);
}

void Cbitmap::RestaurarBMP(void){
	hdc = BeginPaint(hWnd, &ps);
	GetClientRect (hWnd, &rx);
	StretchBlt(hdc, rx.left, rx.top, (rx.right - rx.left), (rx.bottom - rx.top), hdcComp, 0, 0, MapaBmp.bmWidth, MapaBmp.bmHeight, SRCCOPY);
	EndPaint(hWnd, &ps);
}

void Cbitmap::Actualizar(void){
	UpdateWindow(hWnd);
}

void Cbitmap::Destruir(void){
	DestroyWindow(hWnd);
	hWnd=NULL;
}

void Cbitmap::Mensaje(UINT uMensaje, WPARAM wParam, LPARAM lParam){
	SendMessage(hWnd, uMensaje, wParam, lParam);
}