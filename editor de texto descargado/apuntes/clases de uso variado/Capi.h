// -----------------------------------------------------------------
// Capi.h --> Clase con diversas funciones API (17/07/2003)
// -----------------------------------------------------------------

class Capi{
public:
	// --> Propiedades
	char        szbuffer[260];    // --> szbuffer con el resultado de la llamada a las funciones
	HWND        hWndPadre;        // --> Handle de la ventana padre
	char        szfecha[20];      // --> Fecha a devolver por la funcion fecha
	char        horacomp[10];     // --> Hora a devolver
	char        fecha[20];        // --> Para el año
	char        hora   [10];      // --> Para la hora
	char        minuto [10];      // --> Para el minuto
	char        segundo[10];      // --> Para el segundo
	// --> Métodos
	void Capi::CambiarResolucion(int nAncho, int nLargo, int nBits);                                                    // --> Cambia la resolución de video 
	void Capi::ObtenerTipoUnidad(LPSTR Unidad);                                                                         // --> Obtiene el tipo de unidad usada
	void Capi::CerrarSesionWindows(void);                                                                               // --> Cierra la sesion activa de windows
	void Capi::EstablecerWallpaper(LPSTR lpszArchivo);                                                                  // --> Establece un bmp como wallpaper 
	void Capi::EjecutarArchivo(LPSTR lpszArchivo, LPSTR lpszArgumentos, int nModo);                                     // --> Ejecuta un archivo
	void Capi::EjecutarArchivoWin(LPSTR lpszArchivo, int nModo);                                                        // --> Ejecuta un archivo en el directorio de windows
	void Capi::Screensaver(void);                                                                                       // --> Ejecuta el screensaver predeterminado
	void Capi::MenuInicio(void);                                                                                        // --> Lanza el menu inicio de windows
	void Capi::Bloquear(void);                                                                                          // --> Bloquea todos los procesos de la pc  
	void Capi::Desbloquear(void);                                                                                       // --> Desbloquea los procesos de la pc
	void Capi::Dormir(int nMilisegundos);                                                                               // --> Duerme los procesos activos de la pc 
	BOOL Capi::OperacionesArchivo(LPSTR lpszFuente, LPSTR lpszDestino, int nFlag);                                      // --> Permite realizar operaciones con archivos
	void Capi::SiempreVisible(HWND hWnd, BOOL Valor);                                                                   // --> Permite colocar o no una ventana siempre visible
	void Capi::MenuBitmap(HWND hWnd, HINSTANCE hInstancia, int nIndiceSubMenu, int nIDBitmap, int nIndiceItem);         // --> Permite colocar un bitmap de 16x16 en un item de un menu    
	LPSTR Capi::Fecha(void);                                                                                            // --> Devuelve la fecha actual
	LPSTR Capi::Hora(void);                                                                                             // --> Devuelve la hora actual
};

void Capi::EjecutarArchivoWin(LPSTR lpszArchivo , int nModo){
	WinExec(lpszArchivo, nModo);
}

void Capi::EjecutarArchivo(LPSTR lpszArchivo, LPSTR lpszArgumentos, int nModo){
	ShellExecute(hWndPadre, "open", lpszArchivo, lpszArgumentos, "", nModo);
}

void Capi::EstablecerWallpaper(LPSTR lpszArchivo){
	SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, lpszArchivo, SPIF_UPDATEINIFILE);
}

void Capi::CerrarSesionWindows(void){
	ExitWindowsEx(EWX_FORCE, 0);
}

void Capi::ObtenerTipoUnidad(LPSTR Unidad){
	switch (GetDriveType(Unidad)){
		case DRIVE_REMOVABLE :
			lstrcpy(szbuffer, "Unidad Removible");
			break;
		case DRIVE_FIXED :
			lstrcpy(szbuffer, "Unidad no Removible");
			break;
		case DRIVE_REMOTE :
			lstrcpy(szbuffer, "Unidad Remota");
			break;
		case DRIVE_CDROM :
			lstrcpy(szbuffer, "Unidad de CD");
			break;
		case DRIVE_RAMDISK :
			lstrcpy(szbuffer, "Unidad de CD");
			break;
		default :
			lstrcpy(szbuffer, "Unidad no valida!");
			break;
	}	
}

void Capi::CambiarResolucion (int nAncho, int nLargo, int nBits){
	DEVMODE dev;
	ZeroMemory(&dev,sizeof(DEVMODE));
	EnumDisplaySettings(NULL, NULL, &dev);
	dev.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT | DM_BITSPERPEL;
	dev.dmPelsHeight = nLargo;
	dev.dmPelsWidth = nAncho;
	dev.dmBitsPerPel = nBits;
	ChangeDisplaySettings(&dev, NULL);
}

void Capi::Screensaver(void){
	SendMessage(hWndPadre, WM_SYSCOMMAND, (WPARAM) SC_SCREENSAVE, 0);
}

void Capi::MenuInicio(void){
	SendMessage(hWndPadre, WM_SYSCOMMAND, (WPARAM) SC_TASKLIST, 0);
}

void Capi::Bloquear(void){
	BlockInput(true);
}

void Capi::Desbloquear(void){
	BlockInput(false);
}

void Capi::Dormir(int nMilisegundos){
	Sleep(nMilisegundos);
}

BOOL Capi::OperacionesArchivo(LPSTR lpszFuente, LPSTR lpszDestino, int nFlag){
	SHFILEOPSTRUCT shops;	
	ZeroMemory(&shops, sizeof(SHFILEOPSTRUCT));
	if(nFlag==OP_COPIAR){
		shops.hwnd = hWndPadre;
		shops.wFunc = FO_COPY;
		shops.pFrom = lpszFuente;
		shops.pTo = lpszDestino;
		shops.fFlags = FOF_ALLOWUNDO;
		SHFileOperation(&shops);
	}else if(nFlag==OP_BORRAR){
		shops.hwnd = hWndPadre;
		shops.wFunc = FO_DELETE;
		shops.pFrom = lpszFuente;
		shops.pTo = lpszDestino;
		shops.fFlags = FOF_ALLOWUNDO;
		SHFileOperation(&shops);
	}else if(nFlag==OP_MOVER){
		shops.hwnd = hWndPadre;
		shops.wFunc = FO_MOVE;
		shops.pFrom = lpszFuente;
		shops.pTo = lpszDestino;
		shops.fFlags = FOF_ALLOWUNDO;
		SHFileOperation(&shops);
	}else if(nFlag==OP_RENOMBRAR){
		shops.hwnd = hWndPadre;
		shops.wFunc = FO_RENAME;
		shops.pFrom = lpszFuente;
		shops.pTo = lpszDestino;
		shops.fFlags = FOF_ALLOWUNDO;
		SHFileOperation(&shops);
	}
	return !shops.fAnyOperationsAborted;
}

void Capi::SiempreVisible(HWND hWnd, BOOL Valor){
	if(Valor){
		SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOSIZE|SWP_NOMOVE|SWP_SHOWWINDOW);
	}else{
		SetWindowPos(hWnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOSIZE|SWP_NOMOVE|SWP_SHOWWINDOW);
	}
}

void Capi::MenuBitmap(HWND hWnd, HINSTANCE hInstancia,int nIndiceSubMenu, int nIDBitmap, int nIndiceItem){
	HMENU hMenu;
	HMENU hSubMenu;
	HBITMAP hBitmap;
	hMenu = GetMenu(hWnd);
	hSubMenu = GetSubMenu(hMenu, nIndiceSubMenu);
	hBitmap = LoadBitmap(hInstancia, MAKEINTRESOURCE(nIDBitmap));			
	SetMenuItemBitmaps(hSubMenu, nIndiceItem , MF_BYPOSITION, hBitmap, hBitmap);
}

LPSTR Capi::Hora(void){
	SYSTEMTIME st;
	ZeroMemory(&st, sizeof(SYSTEMTIME));
	GetLocalTime(&st);
	switch(st.wHour){
		case 1:
			lstrcpy(horacomp, "01");
			break;
		case 2:
			lstrcpy(horacomp, "02");
			break;
		case 3:
			lstrcpy(horacomp, "03");
			break;
		case 4:
			lstrcpy(horacomp, "04");
			break;
		case 5:
			lstrcpy(horacomp, "05");
			break;
		case 6:
			lstrcpy(horacomp, "06");
			break;
		case 7:
			lstrcpy(horacomp, "07");
			break;
		case 8:
			lstrcpy(horacomp, "08");
			break;
		case 9:
			lstrcpy(horacomp, "09");
			break;
		default:
			lstrcpy(horacomp, gcvt(st.wHour, 2, hora));
			break;
	}
	lstrcat(horacomp, ":");
	switch(st.wMinute){
		case 0:
			lstrcat(horacomp, "00");
			break;
		case 1:
			lstrcat(horacomp, "01");
			break;
		case 2:
			lstrcat(horacomp, "02");
			break;
		case 3:
			lstrcat(horacomp, "03");
			break;
		case 4:
			lstrcat(horacomp, "04");
			break;
		case 5:
			lstrcat(horacomp, "05");
			break;
		case 6:
			lstrcat(horacomp, "06");
			break;
		case 7:
			lstrcat(horacomp, "07");
			break;
		case 8:
			lstrcat(horacomp, "08");
			break;
		case 9:
			lstrcat(horacomp, "09");
			break;
		default:
			lstrcat(horacomp, gcvt(st.wMinute, 2, minuto));
			break;
	}
	lstrcat(horacomp, ":");
	switch(st.wSecond){
		case 0:
			lstrcat(horacomp, "00");
			break;
		case 1:
			lstrcat(horacomp, "01");
			break;
		case 2:
			lstrcat(horacomp, "02");
			break;
		case 3:
			lstrcat(horacomp, "03");
			break;
		case 4:
			lstrcat(horacomp, "04");
			break;
		case 5:
			lstrcat(horacomp, "05");
			break;
		case 6:
			lstrcat(horacomp, "06");
			break;
		case 7:
			lstrcat(horacomp, "07");
			break;
		case 8:
			lstrcat(horacomp, "08");
			break;
		case 9:
			lstrcat(horacomp, "09");
			break;
		default:
			lstrcat(horacomp, gcvt(st.wSecond, 2, segundo));
			break;
	}
	return horacomp;
}

LPSTR Capi::Fecha(void){
	SYSTEMTIME st;
	ZeroMemory(&st, sizeof(SYSTEMTIME));
	GetLocalTime(&st);
	switch(st.wDay){
		case 1:
			lstrcpy(szfecha, "01");
			break;
		case 2:
			lstrcpy(szfecha, "02");
			break;
		case 3:
			lstrcpy(szfecha, "03");
			break;
		case 4:
			lstrcpy(szfecha, "04");
			break;
		case 5:
			lstrcpy(szfecha, "05");
			break;
		case 6:
			lstrcpy(szfecha, "06");
			break;
		case 7:
			lstrcpy(szfecha, "07");
			break;
		case 8:
			lstrcpy(szfecha, "08");
			break;
		case 9:
			lstrcpy(szfecha, "09");
			break;
		case 10:
			lstrcpy(szfecha, "10");
			break;
		case 11:
			lstrcpy(szfecha, "11");
			break;
		case 12:
			lstrcpy(szfecha, "12");
			break;
		case 13:
			lstrcpy(szfecha, "13");
			break;
		case 14:
			lstrcpy(szfecha, "14");
			break;
		case 15:
			lstrcpy(szfecha, "15");
			break;
		case 16:
			lstrcpy(szfecha, "16");
			break;
		case 17:
			lstrcpy(szfecha, "17");
			break;
		case 18:
			lstrcpy(szfecha, "18");
			break;
		case 19:
			lstrcpy(szfecha, "19");
			break;
		case 20:
			lstrcpy(szfecha, "20");
			break;
		case 21:
			lstrcpy(szfecha, "21");
			break;
		case 22:
			lstrcpy(szfecha, "22");
			break;
		case 23:
			lstrcpy(szfecha, "23");
			break;
		case 24:
			lstrcpy(szfecha, "24");
			break;
		case 25:
			lstrcpy(szfecha, "25");
			break;
		case 26:
			lstrcpy(szfecha, "26");
			break;
		case 27:
			lstrcpy(szfecha, "27");
			break;
		case 28:
			lstrcpy(szfecha, "28");
			break;
		case 29:
			lstrcpy(szfecha, "29");
			break;
		case 30:
			lstrcpy(szfecha, "30");
			break;
		case 31:
			lstrcpy(szfecha, "31");
			break;
	}
	lstrcat(szfecha, "/");
	switch(st.wMonth){
		case 1:
			lstrcat(szfecha, "01");
			break;
		case 2:
			lstrcat(szfecha, "02");
			break;
		case 3:
			lstrcat(szfecha, "03");
			break;
		case 4:
			lstrcat(szfecha, "04");
			break;
		case 5:
			lstrcat(szfecha, "05");
			break;
		case 6:
			lstrcat(szfecha, "06");
			break;
		case 7:
			lstrcat(szfecha, "07");
			break;
		case 8:
			lstrcat(szfecha, "08");
			break;
		case 9:
			lstrcat(szfecha, "09");
			break;
		case 10:
			lstrcat(szfecha, "10");
			break;
		case 11:
			lstrcat(szfecha, "11");
			break;
		case 12:
			lstrcat(szfecha, "12");
			break;
	}
	lstrcat(szfecha, "/");
	gcvt(st.wYear, 4, fecha);
	lstrcat(szfecha, fecha);
	return szfecha;
}
