// -----------------------------------------------------------------
// Cimpresora.h --> Clase para usar la impresora (18/07/2003)
// -----------------------------------------------------------------

class Cimpresora{
protected:
	HANDLE        hImpresora;                   // --> Handle de la impresora
	HDC           ImpresoraDC;                  // --> HDC de la impresora
	DOCINFO       DocInfo;                      // --> DocInfo
	RECT          rx;                           // --> Posicion de la impresión   
	LOGFONT       fuente;                       // --> Datos de la fuente a usar
	HFONT         hFuente;                      // --> Handle de la fuente a usar
	HPEN          hPen;                         // --> Handle de la pluma a usar en las lineas
	LOGBRUSH      logbrush;                     // --> Data de la brocha a usar
	HBRUSH        hBrush;                       // --> Handle de la brocha a usar
	PAINTSTRUCT   ps;                           // --> Paintstruct
	HBITMAP       bmp;                          // --> Handle del bitmap
	BITMAP        MapaBmp;                      // --> Mapeado del bitmap
	char          szbuf[255];                   // --> Buffer usado en la impresión por lineas
	Cstring       str;                          // --> Para funciones de cadenas
public:
	// --> Propiedades
    char          szImpresora [260];            // --> Nombre de la impresora
	char          szBufferImpresion [65000];    // --> Buffer que contiene el texto a imprimir
	char          szNombreDocumento [260];      // --> Nombre del documento a imprimir
	LONG          lTamano;                      // --> Tamaño de la fuente
	LPSTR         lpszNombreFuente;             // --> Nombre de la fuente
	BOOL          Negrita;                      // --> Indica si se debe usar negrita
	BOOL          Cursiva;                      // --> Indica si se debe usar cursiva
	BOOL          Subrayado;                    // --> Indica si se debe usar subrayado
	int           nMargenIzquierdo;             // --> Indica el margen izquierdo
	int           nMargenSuperior;              // --> Indica el margen superior
	int           nMenosMargenDerecho;          // --> Indica el margen derecho
	int           nMenosMargenInferior;         // --> Indica el margen inferior
	COLORREF      CColor;                       // --> indica el color de la impresión
	bool          bHojaCarta;                   // --> Indica si se usa hoja carta
	// --> Métodos
	void  Cimpresora::Imprimir(void);                                                                                                                                            // --> Imprime el buffer de impresión en la impresora indicada
	LPSTR Cimpresora::ObtenerImpresoraLocal(int nIndice);                                                                                                                        // --> Obtiene una Impresora local
	LPSTR Cimpresora::ObtenerImpresoraRemota(int nIndice);                                                                                                                       // --> Obtiene una Impresora remota
	LPSTR Cimpresora::ObtenerImpresoraRed(int nIndice);                                                                                                                          // --> Obtiene una Impresora de red
	void  Cimpresora::EmpezarImpresionDocumento(void);                                                                                                                           // --> Inicia la impresión (para impresión controlada por lineas)	
	void  Cimpresora::TerminarImpresionDocumento(void);                                                                                                                          // --> Termina la impresión (para impresión controlada por lineas)
	void  Cimpresora::ImprimirTexto(int nPosX, int nPosY, LPSTR lpszTexto);                                                                                                      // --> Imprime una linea de texto (para impresión controlada por lineas)
	void  Cimpresora::Linea(int nPosX, int nPosY, int nLargo, int nTamanoPluma);                                                                                                 // --> Imprime una linea (para impresión controlada por lineas)
	void  Cimpresora::Elipse(int nPosX, int nPosY, int nAncho, int nLargo, int nTamanoPluma, COLORREF ColorFondo);                                                               // --> Imprime una elipse (para impresión controlada por lineas)        
	void  Cimpresora::Torta(int nPosX, int nPosY, int nAncho, int nLargo, int nTamanoPluma, int  nXRadial1, int nYRadial1, int nXRadial2, int nYRadial2, COLORREF ColorFondo);   // --> Imprime una torta (para impresión controlada por lineas)        
	void  Cimpresora::Cuerda(int nPosX, int nPosY, int nAncho, int nLargo, int nTamanoPluma, int  nXRadial1, int nYRadial1, int nXRadial2, int nYRadial2, COLORREF ColorFondo);  // --> Imprime una cuerda (para impresión controlada por lineas)         
	void  Cimpresora::Rectangulo(int nPosX, int nPosY, int nAncho, int nLargo, int nTamanoPluma, COLORREF ColorFondo);                                                           // --> Imprime un rectangulo (para impresión controlada por lineas)          
	void  Cimpresora::ImprimirBitmapDesdeArchivo(int nPosX, int nPosY, int nAncho, int nLargo, LPSTR lpszArchivo);                                                               // --> Imprime un bitmap desde un archivo (para impresión controlada por lineas)          
	void  Cimpresora::ImpresionPorLineas(int nLineas, Crichedit redit, BOOL bHojaCarta, data_fuente fuentes, LPSTR lpszNombreDoc, int nMargen);                                                                                         // --> Permite realizar la impresión por lineas    
};

LPSTR Cimpresora::ObtenerImpresoraRed(int nIndice){
	DWORD dwNeeded = 0;
	DWORD dwReturned = 0;
	DWORD dwBytes = 0;
	unsigned char *pPrInfo4=NULL;
	LPCSTR strStr;
	EnumPrinters(PRINTER_ENUM_LOCAL | PRINTER_ENUM_NETWORK,	
                 NULL,
                 1,	
                 NULL, 
				 dwBytes,
                 &dwNeeded,	
                 &dwReturned);
	if(dwNeeded != 0){			
		pPrInfo4 = new unsigned char [dwNeeded+128];				
		dwBytes  = dwNeeded+128;
		EnumPrinters(PRINTER_ENUM_LOCAL | PRINTER_ENUM_NETWORK,	
             NULL,	
             1,		
             pPrInfo4,	
			 dwBytes,	
             &dwNeeded,	
             &dwReturned);
			 strStr =(LPCSTR)((PRINTER_INFO_1*)pPrInfo4)[nIndice].pName;				
		  	 return (LPSTR) strStr;
	}else{
		return "";
	}
	delete [] pPrInfo4;
}


LPSTR Cimpresora::ObtenerImpresoraRemota(int nIndice){
	DWORD dwNeeded = 0;
	DWORD dwReturned = 0;
	DWORD dwBytes = 0;
	unsigned char *pPrInfo4=NULL;
	LPCSTR strStr;
	EnumPrinters(PRINTER_ENUM_REMOTE,	
                 NULL,
                 1,	
                 NULL, 
				 dwBytes,
                 &dwNeeded,	
                 &dwReturned);
	if(dwNeeded != 0){			
		pPrInfo4 = new unsigned char [dwNeeded+128];				
		dwBytes  = dwNeeded+128;
		EnumPrinters(PRINTER_ENUM_REMOTE,	
             NULL,	
             1,		
             pPrInfo4,	
			 dwBytes,	
             &dwNeeded,	
             &dwReturned);
			 strStr =(LPCSTR)((PRINTER_INFO_1*)pPrInfo4)[nIndice].pName;				
		  	 return (LPSTR) strStr;
	}else{
		return "";
	}
	delete [] pPrInfo4;
}

LPSTR Cimpresora::ObtenerImpresoraLocal(int nIndice){
	DWORD dwNeeded = 0;
	DWORD dwReturned = 0;
	DWORD dwBytes = 0;
	unsigned char *pPrInfo4=NULL;
	LPCSTR strStr;
	EnumPrinters(PRINTER_ENUM_LOCAL,	
                 NULL,
                 1,	
                 NULL, 
				 dwBytes,
                 &dwNeeded,	
                 &dwReturned);
	if(dwNeeded != 0){			
		pPrInfo4 = new unsigned char [dwNeeded+128];				
		dwBytes  = dwNeeded+128;
		EnumPrinters(PRINTER_ENUM_LOCAL,	
             NULL,	
             1,		
             pPrInfo4,	
			 dwBytes,	
             &dwNeeded,	
             &dwReturned);
			 strStr =(LPCSTR)((PRINTER_INFO_1*)pPrInfo4)[nIndice].pName;				
		  	 return (LPSTR) strStr;
	}else{
		return "";
	}
	delete [] pPrInfo4;
}


void Cimpresora::Imprimir(void){
	ZeroMemory(&fuente, sizeof(LOGFONT));
	ZeroMemory(&hFuente, sizeof(HFONT));
	ZeroMemory(&DocInfo, sizeof(DOCINFO));
	if (lstrlen(szImpresora)>1){
		OpenPrinter(szImpresora, &hImpresora, NULL);
		ImpresoraDC = CreateDC("WINSPOOL", szImpresora, NULL, NULL);
		if (ImpresoraDC != NULL){ 
			fuente.lfHeight = lTamano+50;
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
			hFuente = CreateFontIndirect(&fuente);
			SelectObject(ImpresoraDC, (HGDIOBJ) hFuente);
			rx.left = nMargenIzquierdo;
			rx.top = nMargenSuperior;
			rx.right = GetDeviceCaps(ImpresoraDC, PHYSICALWIDTH) - nMenosMargenDerecho;
			rx.bottom = GetDeviceCaps(ImpresoraDC, PHYSICALHEIGHT) - nMenosMargenInferior;
			DocInfo.lpszDocName = szNombreDocumento;
			DocInfo.cbSize = sizeof(DOCINFO);
			StartDoc(ImpresoraDC, &DocInfo);
				StartPage(ImpresoraDC);
					SetTextColor(ImpresoraDC, CColor);
					DrawText(ImpresoraDC, szBufferImpresion, lstrlen(szBufferImpresion), &rx, DT_WORDBREAK|DT_NOCLIP|DT_NOPREFIX);
				EndPage(ImpresoraDC);
			EndDoc(ImpresoraDC);
			DeleteDC(ImpresoraDC);
		}	
	}
}

void  Cimpresora::EmpezarImpresionDocumento(void){
	ZeroMemory(&fuente, sizeof(LOGFONT));
	ZeroMemory(&hFuente, sizeof(HFONT));
	ZeroMemory(&DocInfo, sizeof(DOCINFO));
	if (lstrlen(szImpresora)>1){
		OpenPrinter(szImpresora, &hImpresora, NULL);
		ImpresoraDC = CreateDC("WINSPOOL", szImpresora, NULL, NULL);
		if (ImpresoraDC != NULL){ 
			fuente.lfHeight = lTamano+50;
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
			hFuente = CreateFontIndirect(&fuente);
			SelectObject(ImpresoraDC, (HGDIOBJ) hFuente);
			rx.left = nMargenIzquierdo;
			rx.top = nMargenSuperior;
			rx.right = GetDeviceCaps(ImpresoraDC, PHYSICALWIDTH) - nMenosMargenDerecho;
			rx.bottom = GetDeviceCaps(ImpresoraDC, PHYSICALHEIGHT) - nMenosMargenInferior;
			DocInfo.lpszDocName = szNombreDocumento;
			DocInfo.cbSize = sizeof(DOCINFO);
			StartDoc(ImpresoraDC, &DocInfo);
			StartPage(ImpresoraDC);
		}
	}
}

void  Cimpresora::TerminarImpresionDocumento(void){
	EndPage(ImpresoraDC);
	EndDoc(ImpresoraDC);
	DeleteDC(ImpresoraDC);
}

void  Cimpresora::ImprimirTexto(int nPosX, int nPosY, LPSTR lpszTexto){
	SetTextColor(ImpresoraDC, CColor);
	StrTrim(lpszTexto, "\n");
	TextOut(ImpresoraDC, nPosX, nPosY, lpszTexto, lstrlen(lpszTexto)-1);
}

void  Cimpresora::Linea(int nPosX, int nPosY, int nLargo, int nTamanoPluma){
	ZeroMemory(&hPen, sizeof(HPEN));
	hPen = CreatePen(PS_SOLID, nTamanoPluma, CColor);	
	SelectObject(ImpresoraDC, hPen);
	MoveToEx(ImpresoraDC, nPosX, nPosY, (LPPOINT) NULL);
	LineTo(ImpresoraDC, nLargo, nPosY);
	DeleteObject(hPen);
}

void  Cimpresora::Elipse(int nPosX, int nPosY, int nAncho, int nLargo, int nTamanoPluma, COLORREF ColorFondo){
	ZeroMemory(&hPen, sizeof(HPEN));
	ZeroMemory(&hBrush, sizeof(HBRUSH));
	ZeroMemory(&logbrush, sizeof(LOGBRUSH));
	hPen = CreatePen(PS_SOLID, nTamanoPluma, CColor);	
	logbrush.lbStyle = BS_SOLID;
	logbrush.lbColor = ColorFondo;
	logbrush.lbHatch = HS_VERTICAL|HS_HORIZONTAL;	
	hBrush = CreateBrushIndirect(&logbrush);
	SelectObject(ImpresoraDC, hPen);
	SelectObject(ImpresoraDC, hBrush);
	Ellipse(ImpresoraDC, nPosX, nPosY, nAncho, nLargo);
	DeleteObject(hBrush);
	DeleteObject(hPen);	
}

void  Cimpresora::Torta(int nPosX, int nPosY, int nAncho, int nLargo, int nTamanoPluma, int  nXRadial1, int nYRadial1, int nXRadial2, int nYRadial2, COLORREF ColorFondo){
	ZeroMemory(&hPen, sizeof(HPEN));
	ZeroMemory(&hBrush, sizeof(HBRUSH));
	ZeroMemory(&logbrush, sizeof(LOGBRUSH));
	hPen = CreatePen(PS_SOLID, nTamanoPluma, CColor);	
	logbrush.lbStyle = BS_SOLID;
	logbrush.lbColor = ColorFondo;
	logbrush.lbHatch = HS_VERTICAL|HS_HORIZONTAL;	
	hBrush = CreateBrushIndirect(&logbrush);
	SelectObject(ImpresoraDC, hPen);
	SelectObject(ImpresoraDC, hBrush);
	Pie(ImpresoraDC, nPosX, nPosY, nAncho, nLargo, nXRadial1, nYRadial1, nXRadial2, nYRadial2);
	DeleteObject(hPen);	
	DeleteObject(hBrush);
}

void  Cimpresora::Cuerda(int nPosX, int nPosY, int nAncho, int nLargo, int nTamanoPluma, int  nXRadial1, int nYRadial1, int nXRadial2, int nYRadial2, COLORREF ColorFondo){
	ZeroMemory(&hPen, sizeof(HPEN));
	ZeroMemory(&hBrush, sizeof(HBRUSH));
	ZeroMemory(&logbrush, sizeof(LOGBRUSH));
	hPen = CreatePen(PS_SOLID, nTamanoPluma, CColor);	
	logbrush.lbStyle = BS_SOLID;
	logbrush.lbColor = ColorFondo;
	logbrush.lbHatch = HS_VERTICAL|HS_HORIZONTAL;	
	hBrush = CreateBrushIndirect(&logbrush);
	SelectObject(ImpresoraDC, hPen);
	SelectObject(ImpresoraDC, hBrush);
	Chord(ImpresoraDC, nPosX, nPosY, nAncho, nLargo, nXRadial1, nYRadial1, nXRadial2, nYRadial2);
	DeleteObject(hPen);	
	DeleteObject(hBrush);
}

void  Cimpresora::Rectangulo(int nPosX, int nPosY, int nAncho, int nLargo, int nTamanoPluma, COLORREF ColorFondo){
	ZeroMemory(&hPen, sizeof(HPEN));
	ZeroMemory(&hBrush, sizeof(HBRUSH));
	ZeroMemory(&logbrush, sizeof(LOGBRUSH));
	hPen = CreatePen(PS_SOLID, nTamanoPluma, CColor);	
	logbrush.lbStyle = BS_SOLID;
	logbrush.lbColor = ColorFondo;
	logbrush.lbHatch = HS_VERTICAL|HS_HORIZONTAL;	
	hBrush = CreateBrushIndirect(&logbrush);
	SelectObject(ImpresoraDC, hPen);
	SelectObject(ImpresoraDC, hBrush);
	Rectangle(ImpresoraDC, nPosX, nPosY, nAncho, nLargo);
	DeleteObject(hPen);	
	DeleteObject(hBrush);
}

void  Cimpresora::ImprimirBitmapDesdeArchivo(int nPosX, int nPosY, int nAncho, int nLargo, LPSTR lpszArchivo){
	HDC hdccomp;
	bmp = (HBITMAP) LoadImage(NULL, lpszArchivo, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	hdccomp = CreateCompatibleDC(ImpresoraDC);
	SelectObject(hdccomp, bmp);
	GetObject(bmp, sizeof(MapaBmp), &MapaBmp);
//	StretchBlt(ImpresoraDC, nPosX, nPosY, nAncho, nLargo, hdccomp, 0, 0, MapaBmp.bmWidth, MapaBmp.bmHeight, SRCCOPY);
	BitBlt(ImpresoraDC, nPosX, nPosY, nAncho, nLargo, hdccomp, 0, 0, SRCCOPY);	  
	DeleteDC(hdccomp);
}

void  Cimpresora::ImpresionPorLineas(int nLineas, Crichedit redit, BOOL bHojaCarta, data_fuente fuentes, LPSTR lpszNombreDoc, int nMargen){
	int lineas=0;
	int paginas=0;
	int limite=0;
	int iteraciones=0;
	int verticalidad=nMargenSuperior;
	if(bHojaCarta){
		limite = 50;
	}else{
		limite = 70;
	}
	lstrcpy(szNombreDocumento, lpszNombreDoc);
	lstrcpy(szbuf, "255");
	lstrcpy(lpszNombreFuente, fuentes.szfuente);
	EmpezarImpresionDocumento(); 
	for(lineas=0;lineas<nLineas;lineas++){
		iteraciones++;
		if(iteraciones<=limite){
			redit.Mensaje(EM_GETLINE, lineas, (WPARAM) szbuf); 					
			ImprimirTexto(nMargen, verticalidad, szbuf);  
			verticalidad = verticalidad + fuentes.tamano + 60;			
		}
		if(iteraciones==limite){						
			paginas++;
			iteraciones=0;
			verticalidad=nMargenSuperior;
			ImprimirTexto(nMargen, 500, str.AcomodarCifra(paginas, 10));
			TerminarImpresionDocumento(); 
			EmpezarImpresionDocumento(); 			
		}		
	}
	TerminarImpresionDocumento(); 
}