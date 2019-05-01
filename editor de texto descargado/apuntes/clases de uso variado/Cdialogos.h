// -----------------------------------------------------------------
// Cdialogos.h --> Clase de dialogos comunes (17/07/2003)
// -----------------------------------------------------------------

class Cdialogos{
protected:
	OPENFILENAME ofn;
public:
	// --> Propiedades
	HWND              hWndPadre;       // --> Handle de la ventana padre
	char              szbuffer[260];   // --> Buffer con la seleccion del usuario
	HINSTANCE         hInstancia;      // --> Instancia de la aplicacion
	RECT              Margenes;        // --> Margenes de la pagina
	// --> Métodos
	void Cdialogos::Abrir(LPSTR lpszFiltro, LPSTR lpszTitulo);         // --> Muestra el cuadro de dialogo abrir  	
	void Cdialogos::Guardar(LPSTR lpszFiltro, LPSTR lpszTitulo);       // --> Muestra el cuadro de dialogo guardar 	
	void Cdialogos::Pagina(void);                                      // --> Muestra el cuadro de dialogo configurar pagina	
	void Cdialogos::Explorar(LPSTR lpszTitulo);                        // --> Muestra el cuadro de dialogo explorar por directorio 	
	COLORREF Cdialogos::Color(void);                                   // --> Muestra el cuadro de dialogo seleccionar color	
	void Cdialogos::Fuente(void);                                      // --> Muestra el cuadro de dialogo seleccionar fuente
};

struct data_fuente{
	char szfuente[255];
	long tamano;
	bool negrita;
	bool cursiva;
	bool subrayado;
}fuentes;

void Cdialogos::Abrir(LPSTR lpszFiltro, LPSTR lpszTitulo){
	ZeroMemory(&ofn, sizeof(OPENFILENAME));
	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = hWndPadre;
	ofn.lpstrFilter = (lpszFiltro);
	ofn.lpstrFile = szbuffer;
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrFileTitle = (lpszTitulo);
	ofn.Flags = OFN_FILEMUSTEXIST|OFN_PATHMUSTEXIST|OFN_HIDEREADONLY;
	GetOpenFileName (&ofn);
}

void Cdialogos::Guardar(LPSTR lpszFiltro, LPSTR lpszTitulo){
	ZeroMemory(&ofn, sizeof(OPENFILENAME));
	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = hWndPadre;
	ofn.lpstrFilter = (lpszFiltro);
	ofn.lpstrFile = szbuffer;
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrFileTitle = (lpszTitulo);
	ofn.Flags = OFN_FILEMUSTEXIST|OFN_PATHMUSTEXIST|OFN_HIDEREADONLY;
	GetSaveFileName (&ofn);
}

void Cdialogos::Pagina(void){
	PAGESETUPDLG page;
	ZeroMemory(&page, sizeof(PAGESETUPDLG));
	page.hwndOwner = hWndPadre;
	page.lStructSize = sizeof(PAGESETUPDLG);
	PageSetupDlg(&page);
	Margenes.left = page.rtMargin.left;
	Margenes.top = page.rtMargin.top;
	Margenes.right = page.rtMargin.right;
	Margenes.bottom = page.rtMargin.bottom;
}

void Cdialogos::Explorar(LPSTR lpszTitulo){
	BROWSEINFO br;
	LPCITEMIDLIST lp;
	ZeroMemory(&br , sizeof (BROWSEINFO));
	ZeroMemory(&lp , sizeof (LPCITEMIDLIST));
	br.hwndOwner = hWndPadre;
	br.lpszTitle = lpszTitulo;
	br.pszDisplayName = szbuffer;
	br.ulFlags = BIF_RETURNONLYFSDIRS;
	lp = SHBrowseForFolder(&br);
	if (SHGetPathFromIDList(lp, szbuffer)){
		if (lstrlen(szbuffer) > 3) lstrcat (szbuffer , "\\");	
	}
}

COLORREF Cdialogos::Color(void){
	CHOOSECOLOR cc;                 
	static COLORREF acrCustClr[16]; 
	HBRUSH hbrush;                  
	static DWORD rgbCurrent;        
	ZeroMemory(&cc, sizeof(CHOOSECOLOR));
	cc.lStructSize = sizeof(CHOOSECOLOR);
	cc.hwndOwner = hWndPadre;
	cc.lpCustColors = (LPDWORD) acrCustClr;
	cc.rgbResult = rgbCurrent;
	cc.Flags = CC_FULLOPEN | CC_RGBINIT;
	if (ChooseColor(&cc)==TRUE) 
	{
		hbrush = CreateSolidBrush(cc.rgbResult);
		rgbCurrent = cc.rgbResult; 
	}
	return rgbCurrent;
}

void Cdialogos::Fuente(void){
	CHOOSEFONT cf;
	LOGFONT lf;
	ZeroMemory(&cf, sizeof(CHOOSEFONT));
	ZeroMemory(&lf, sizeof(LOGFONT));
	lstrcpy(lf.lfFaceName, fuentes.szfuente);
	lf.lfHeight = fuentes.tamano; 
	lf.lfItalic = fuentes.cursiva;
	lf.lfUnderline = fuentes.subrayado;
	if(fuentes.negrita){
		lf.lfWeight = FW_BOLD;
	}else{
		lf.lfWeight = FW_NORMAL; 
	}
	cf.lStructSize = sizeof (CHOOSEFONT);
	cf.hwndOwner = hWndPadre;
	cf.lpLogFont = &lf;
	cf.Flags = CF_SCREENFONTS | CF_EFFECTS | CF_INITTOLOGFONTSTRUCT;
	ChooseFont(&cf);
	lstrcpy(fuentes.szfuente, lf.lfFaceName);
	fuentes.tamano = lf.lfHeight; 
	fuentes.cursiva = lf.lfItalic;
	fuentes.subrayado = lf.lfUnderline; 
	if (lf.lfWeight == FW_BOLD){
		fuentes.negrita = true;	
	}else{
		fuentes.negrita = !true;	
	}
}
