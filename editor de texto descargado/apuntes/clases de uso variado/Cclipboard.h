// ------------------------------------------------------------------
// Cclipboard.h --> Clase para trabajar el clipboard (13/10/2003)
// ------------------------------------------------------------------

class Cclipboard{
protected:
	HGLOBAL clipbuffer;
	char * buffer;
public:
	// --> Propiedades
	HWND hWndPadre;
	// --> Métodos
	void Cclipboard::CopiarTexto(LPSTR lpszTexto);
};

void Cclipboard::CopiarTexto(LPSTR lpszTexto){
	if(OpenClipboard(hWndPadre)){
		EmptyClipboard(); 
		clipbuffer = GlobalAlloc(GMEM_DDESHARE, lstrlen(lpszTexto) + 1);
		buffer = (char *) GlobalLock(clipbuffer);
		strcpy(buffer, LPCSTR(lpszTexto));
		GlobalUnlock(clipbuffer);
		SetClipboardData(CF_TEXT, clipbuffer);
		CloseClipboard();
	}
}
