// -----------------------------------------------------------------
// Cimagelist.h --> Clase para crear ImageList (17/07/2003)
// -----------------------------------------------------------------

class Cimagelist{ 
public:
	// --> Propiedades
	HIMAGELIST       hWnd;                 // --> Handle del imagelist
	HWND             hWndPadre;            // --> Handle de la ventana padre
	int              nAnchoImg;            // --> Ancho de las imagenes
	int              nLargoImg;            // --> Largo de las imagenes
	int              nNumeroImagen;        // --> Número de las imagenes
	int              nNumeroMaximoImagen;  // --> Número maximo de imagenes
	// --> Métodos
	void Cimagelist::Crear(void);                     	// --> Crea el imagelist
	void Cimagelist::AgregarIcono(HICON hIcono);        // --> Agrega un icono
	void Cimagelist::AgregarBitmap(HBITMAP hBMP);       // --> Agrega un bitmap  
	void Cimagelist::EliminarImagenes(void);            // --> Elimina todas las imagenes del imagelist     
	void Cimagelist::Destruir(void);                    // --> Destruye el imagelist     
};

void Cimagelist::Destruir(void){
	 ImageList_Destroy(hWnd);
}

void Cimagelist::EliminarImagenes(void){
	ImageList_RemoveAll(hWnd);
}

void Cimagelist::AgregarBitmap(HBITMAP hBMP){
	ImageList_Add(hWnd, hBMP, NULL);
}

void Cimagelist::AgregarIcono(HICON hIcono){
	ImageList_AddIcon(hWnd, hIcono);
}

void Cimagelist::Crear(void){
  	hWnd = ImageList_Create(nAnchoImg, nLargoImg, ILC_COLOR|ILC_MASK, nNumeroImagen, nNumeroMaximoImagen);	 
}


