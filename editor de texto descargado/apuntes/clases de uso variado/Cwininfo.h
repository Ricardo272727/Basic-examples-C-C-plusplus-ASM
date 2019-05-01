// -----------------------------------------------------------------
// Cwininfo.h --> Clase para obtener informacion de Windows (20/07/2003)
// -----------------------------------------------------------------

class Cwininfo{
protected:
	LPITEMIDLIST lp;
public:
	// --> Propiedades
	char szbuffer[260];    // --> szbuffer con la cadena resultante de la llamada a las funciones
	HWND hWndPadre;        // --> Handle de la ventana padre
	// --> Métodos
	void Cwininfo::WinDir(void);                         // --> Obtiene el directorio de Windows y lo guarda en la variable szbuffer
	void Cwininfo::SysDir(void);                         // --> Obtiene el directorio del system32 y lo guarda en la variable szbuffer 
	void Cwininfo::EscritorioDir(void);                  // --> Obtiene el directorio del Escritorio y lo guarda en la variable szbuffer
	void Cwininfo::FuentesDir(void);                     // --> Obtiene el directorio de las fuentes y lo guarda en la variable szbuffer 
	void Cwininfo::EntornoRedDir(void);                  // --> Obtiene el directorio del entorno de red y lo guarda en la variable szbuffer  
	void Cwininfo::MisDocumentosDir(void);               // --> Obtiene el directorio de mis documentos y lo guarda en la variable szbuffer  
	void Cwininfo::MenuInicioDir(void);                  // --> Obtiene el directorio del menu inicio y lo guarda en la variable szbuffer 
	void Cwininfo::DocRecientesDir(void);                // --> Obtiene el directorio de los documentos recientes y lo guarda en la variable szbuffer 
	void Cwininfo::EnviarADir(void);                     // --> Obtiene el directorio de enviar a y lo guarda en la variable szbuffer  
	void Cwininfo::ArchMenuInicioDir(void);              // --> Obtiene el directorio de los archivos del menu inicio y lo guarda en la variable szbuffer
	void Cwininfo::MenuIniciarDir(void);                 // --> Obtiene el directorio de la carpeta inicio del menu inicio y lo guarda en la variable szbuffer
	void Cwininfo::PlantillasDir(void);                  // --> Obtiene el directorio de las plantillas de documentos y lo guarda en la variable szbuffer
	void Cwininfo::NombreUsuarioWin(void);               // --> Obtiene el nombre del usuario de la sesión actual y lo guarda en la variable szbuffer 
	void Cwininfo::NombreComputadora(void);              // --> Obtiene el nombre de la pc y lo guarda en la variable szbuffer 
	void Cwininfo::VersionWindows(void);                 // --> Obtiene la versión de windows y lo guarda en la variable szbuffer
};

void Cwininfo::VersionWindows(void){
	OSVERSIONINFO lpv;
	ZeroMemory(&lpv, sizeof (OSVERSIONINFO));
	lpv.dwOSVersionInfoSize = sizeof (OSVERSIONINFO);
	GetVersionEx(&lpv);
	if (lpv.dwPlatformId == VER_PLATFORM_WIN32s){
		lstrcpy(szbuffer, "Windows 3.1 ");
	}
	if (lpv.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS){
		lstrcpy(szbuffer, "Windows 9x ");
	}
	if (lpv.dwPlatformId == VER_PLATFORM_WIN32_NT){
		lstrcpy(szbuffer, "Windows NT o Similar");
	}
}

void Cwininfo::NombreComputadora(void){
	DWORD Size;
	Size = 255;
	GetComputerName(szbuffer, &Size);
}

void Cwininfo::NombreUsuarioWin(void){
	DWORD Size;
	Size = 255;
	GetUserName(szbuffer, &Size);
}

void Cwininfo::PlantillasDir(void){
	ZeroMemory(&lp, sizeof (LPITEMIDLIST));
	SHGetSpecialFolderLocation(hWndPadre, CSIDL_TEMPLATES, &lp);
	SHGetPathFromIDList(lp, szbuffer);
	if (lstrlen(szbuffer) > 3) lstrcat(szbuffer, "\\");
}

void Cwininfo::MenuIniciarDir(void){
	ZeroMemory(&lp , sizeof(LPITEMIDLIST));
	SHGetSpecialFolderLocation(hWndPadre, CSIDL_STARTUP, &lp);
	SHGetPathFromIDList(lp, szbuffer);
	if (lstrlen(szbuffer) > 3) lstrcat (szbuffer, "\\");
}

void Cwininfo::ArchMenuInicioDir(void){
	ZeroMemory(&lp, sizeof(LPITEMIDLIST));
	SHGetSpecialFolderLocation(hWndPadre, CSIDL_STARTMENU, &lp);
	SHGetPathFromIDList(lp, szbuffer);
	if (lstrlen(szbuffer) > 3) lstrcat(szbuffer, "\\");
}

void Cwininfo::EnviarADir(void){
	ZeroMemory(&lp, sizeof(LPITEMIDLIST));
	SHGetSpecialFolderLocation(hWndPadre, CSIDL_SENDTO, &lp);
	SHGetPathFromIDList(lp, szbuffer);
	if (lstrlen(szbuffer) > 3) lstrcat(szbuffer, "\\");
}

void Cwininfo::DocRecientesDir(void){
	ZeroMemory(&lp, sizeof(LPITEMIDLIST));
	SHGetSpecialFolderLocation(hWndPadre, CSIDL_RECENT, &lp);
	SHGetPathFromIDList(lp, szbuffer);
	if (lstrlen(szbuffer) > 3) lstrcat(szbuffer, "\\");
}

void Cwininfo::MenuInicioDir(void){
	ZeroMemory(&lp , sizeof(LPITEMIDLIST));
	SHGetSpecialFolderLocation(hWndPadre, CSIDL_PROGRAMS, &lp);
	SHGetPathFromIDList(lp, szbuffer);
	if (lstrlen(szbuffer) > 3) lstrcat (szbuffer, "\\");
}

void Cwininfo::MisDocumentosDir(void){
	ZeroMemory(&lp, sizeof(LPITEMIDLIST));
	SHGetSpecialFolderLocation(hWndPadre, CSIDL_PERSONAL, &lp);
	SHGetPathFromIDList(lp, szbuffer);
	if (lstrlen(szbuffer) > 3) lstrcat(szbuffer, "\\");
}

void Cwininfo::EntornoRedDir(void){
	ZeroMemory(&lp, sizeof(LPITEMIDLIST));
	SHGetSpecialFolderLocation(hWndPadre, CSIDL_NETHOOD, &lp);
	SHGetPathFromIDList(lp, szbuffer);
	if (lstrlen(szbuffer) > 3) lstrcat(szbuffer, "\\");
}

void Cwininfo::FuentesDir(void){
	ZeroMemory(&lp, sizeof(LPITEMIDLIST));
	SHGetSpecialFolderLocation(hWndPadre, CSIDL_FONTS, &lp);
	SHGetPathFromIDList(lp, szbuffer);
	if (lstrlen(szbuffer) > 3) lstrcat (szbuffer, "\\");
}

void Cwininfo::EscritorioDir(void){
	ZeroMemory(&lp, sizeof(LPITEMIDLIST));
	SHGetSpecialFolderLocation(hWndPadre, CSIDL_DESKTOP, &lp);
	SHGetPathFromIDList(lp, szbuffer);
	if (lstrlen(szbuffer) > 3) lstrcat(szbuffer, "\\");
}

void Cwininfo::SysDir(void){
	GetSystemDirectory(szbuffer, MAX_PATH);
	if (lstrlen(szbuffer) > 3) lstrcat(szbuffer, "\\");
}


void Cwininfo::WinDir(void){
	GetWindowsDirectory(szbuffer, MAX_PATH);
	if (lstrlen(szbuffer) > 3) lstrcat(szbuffer, "\\");
}