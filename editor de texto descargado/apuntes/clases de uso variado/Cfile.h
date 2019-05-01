// ------------------------------------------------------------------
// Cfile.h --> Clase para trabajar con archivos de texto (12/10/2003)
// ------------------------------------------------------------------

class Cfile{
private:
	// --> Propiedades
	HFILE hFile;
	DWORD dwSize;
	long pos;
public:
	// --> Métodos
	LPSTR Cfile::AbrirArchivo(LPSTR lpszArchivo);
	void Cfile::GuardarArchivo(LPSTR lpszArchivo, LPSTR lpszBuffer);
};

void Cfile::GuardarArchivo(LPSTR lpszArchivo, LPSTR lpszBuffer){
	if(lstrlen(lpszArchivo)>1){ 
		hFile = _lcreat(lpszArchivo, 0);
		if(hFile == HFILE_ERROR){
			MessageBox(NULL, "Se ha presentado un error creando el archivo seleccionado", "Atención", MB_OK|MB_ICONERROR);
		}
		_hwrite(hFile, lpszBuffer, (long) lstrlen(lpszBuffer));  
		_lclose(hFile);
	}
}

LPSTR Cfile::AbrirArchivo(LPSTR lpszArchivo){
	if(lstrlen(lpszArchivo)>1){ 		 
		hFile =	_lopen(lpszArchivo, OF_READ); 
		if(hFile == HFILE_ERROR){
			MessageBox(NULL, "Se ha presentado un error abriendo el archivo seleccionado", "Atención", MB_OK|MB_ICONERROR);
		}		
		dwSize = GetFileSize((HANDLE) hFile, NULL);
		if(dwSize==0){
			return "";		
		}else{
			char *buffer = new char [dwSize];
			_lread(hFile, buffer, dwSize);		
			pos = StrCSpn(buffer, "ý")+1;
			lstrcpyn(buffer, buffer, pos);
			_lclose(hFile);
			return buffer;
			delete [] buffer;
		}				
	}else{
		return "";
	}

}

