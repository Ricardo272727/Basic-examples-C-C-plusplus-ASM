// -----------------------------------------------------------------
// CWndAcerca.h --> Clase para crear ventanas de acerca de (20/07/2003)
// -----------------------------------------------------------------

LRESULT CALLBACK WndProcEditAcerca(HWND hWnd, UINT uMensaje, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProcAcerca(HWND hWnd, UINT uMensaje, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProcBoton1Acerca(HWND hWnd, UINT uMensaje, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProcBoton2Acerca(HWND hWnd, UINT uMensaje, WPARAM wParam, LPARAM lParam);

class CWndAcerca{
public:
	// --> Propiedades
	HWND         hWndPadre;            // --> Handle de la ventana padre
	HINSTANCE    hInstancia;           // --> Instancia de la aplicación
	HICON        hIcono;               // --> Handle del icono de la ventana
	HCURSOR      hCursor;              // --> Handle del cursor de la ventana
	Cwindow      win;        
	Cframe       frame1;     
	Cframe       frame2;
	Cframe       frame3;
	Clabel       label1;
	Clabel       label2;
	Clabel       label3;
	Clabel       label4;
	Clabel       label5;
	Clabel       label6;
	Clabel       label7;
	Clabel       label8;
	Clabel       label9;
	Clabel       label10;
	Clabel       label11;
	Cbutton      boton1;
	Cbutton      boton2;
	Cimagen      imagen;
	Capi         api;
	Cwininfo     wininfo;
	LPSTR        lpszTitulo;           // --> Titulo de la ventana 
	LPSTR        lpszIconoApp;         // --> Icono de la aplicación
	LPSTR        lpszNombreApp;        // --> Nombre de la aplicación 
	LPSTR        lpszVersionApp;       // --> Versión de la aplicación
	LPSTR        lpszProgramadorInfo;  // --> Info del programador
	int          nPosX;                // --> Posición X
	int          nPosY;                // --> Posición Y
	// --> Métodos
	void CWndAcerca::Crear(void);          // --> Crea la ventana acerca de
	void CWndAcerca::Destruir(void);       // --> Destruye la ventana acerca de
};

CWndAcerca acerca;

void CWndAcerca::Crear(void){
	win.hWndPadre = hWndPadre;
	win.hInstancia = hInstancia;
	win.dwEstilo = CW_DIALOGO;
	win.lpszTitulo = lpszTitulo;
	win.hCursor = hCursor;
	win.hIcono = hIcono;
	win.Posicion.left = nPosX;
	win.Posicion.top = nPosY;
	win.Posicion.right = 400;
	win.Posicion.bottom = 360;
	win.WndProc = WndProcAcerca;
	win.nModoWin = SW_SHOW;
	win.Crear(); 
}

void CWndAcerca::Destruir(void){
	win.Destruir();
	win.hWnd = NULL;
}

LRESULT CALLBACK WndProcAcerca(HWND hWnd, UINT uMensaje, WPARAM wParam, LPARAM lParam){
	switch(uMensaje){
		case WM_CREATE:{
			// --> Frame 1
			acerca.frame1.hWndPadre = hWnd;
			acerca.frame1.hInstancia = acerca.hInstancia;
			acerca.frame1.Posicion.left = 5;
			acerca.frame1.Posicion.top = 5;
			acerca.frame1.Posicion.right = 385;
			acerca.frame1.Posicion.bottom = 60;
			acerca.frame1.Crear(); 
			// --> Imagen de la aplicación
			acerca.imagen.hWndPadre = hWnd;
			acerca.imagen.hInstancia = acerca.hInstancia;
			acerca.imagen.dwEstilo = CI_ICONO;
			acerca.imagen.lpszImagen = acerca.lpszIconoApp;
			acerca.imagen.Posicion.left = 10;
			acerca.imagen.Posicion.top = 20;
			acerca.imagen.Posicion.right = 32;
			acerca.imagen.Posicion.bottom = 32;
			acerca.imagen.Crear(); 
			// --> Label 1
			acerca.label1.hWndPadre = hWnd;
			acerca.label1.hInstancia = acerca.hInstancia;
			acerca.label1.dwEstilo = CL_NORMAL;
			acerca.label1.Posicion.left = 50;
			acerca.label1.Posicion.top = 20;
			acerca.label1.Posicion.right = 300;
			acerca.label1.Posicion.bottom = 20;
			acerca.label1.lpszTexto = acerca.lpszNombreApp;
			acerca.label1.Crear();
			acerca.label1.Fuente(14, !false, false, false, "ARIAL"); 
			// --> Label 2
			acerca.label2.hWndPadre = hWnd;
			acerca.label2.hInstancia = acerca.hInstancia;
			acerca.label2.dwEstilo = CL_NORMAL;
			acerca.label2.Posicion.left = 50;
			acerca.label2.Posicion.top = 40;
			acerca.label2.Posicion.right = 300;
			acerca.label2.Posicion.bottom = 20;
			acerca.label2.lpszTexto = acerca.lpszVersionApp;
			acerca.label2.Crear();
			acerca.label2.Fuente(14, false, false, false, "ARIAL"); 
			// --> Frame 2
			acerca.frame2.hWndPadre = hWnd;
			acerca.frame2.hInstancia = acerca.hInstancia;
			acerca.frame2.Posicion.left = 5;
			acerca.frame2.Posicion.top = 65;
			acerca.frame2.Posicion.right = 385;
			acerca.frame2.Posicion.bottom = 50;
			acerca.frame2.Crear(); 
			// --> label 3
			acerca.label3.hWndPadre = hWnd;
			acerca.label3.hInstancia = acerca.hInstancia;
			acerca.label3.dwEstilo = CL_NORMAL;
			acerca.label3.Posicion.left = 10;
			acerca.label3.Posicion.top = 80;
			acerca.label3.Posicion.right = 300;
			acerca.label3.Posicion.bottom = 30;
			acerca.label3.lpszTexto = acerca.lpszProgramadorInfo;
			acerca.label3.Crear();
			acerca.label3.Fuente(14, false, false, false, "ARIAL"); 
			// --> Frame 3
			acerca.frame3.hWndPadre = hWnd;
			acerca.frame3.hInstancia = acerca.hInstancia;
			acerca.frame3.Posicion.left = 5;
			acerca.frame3.Posicion.top = 115;
			acerca.frame3.Posicion.right = 385;
			acerca.frame3.Posicion.bottom = 170;
			acerca.frame3.Crear(); 
			// --> label 4
			acerca.label4.hWndPadre = acerca.frame3.hWnd;
			acerca.label4.hInstancia = acerca.hInstancia;
			acerca.label4.dwEstilo = CL_NORMAL;
			acerca.label4.Posicion.left = 10;
			acerca.label4.Posicion.top = 20;
			acerca.label4.Posicion.right = 300;
			acerca.label4.Posicion.bottom = 18;
			acerca.label4.lpszTexto = "Ejecutandose en el sistema operativo";
			acerca.label4.Crear();
			acerca.label4.Fuente(14, false, false, false, "ARIAL"); 
			// --> label 5
			acerca.label5.hWndPadre = acerca.frame3.hWnd;
			acerca.label5.hInstancia = acerca.hInstancia;
			acerca.label5.dwEstilo = CL_NORMAL;
			acerca.label5.Posicion.left = 10;
			acerca.label5.Posicion.top = 35;
			acerca.label5.Posicion.right = 300;
			acerca.label5.Posicion.bottom = 18;
			acerca.wininfo.VersionWindows(); 
			acerca.label5.lpszTexto = acerca.wininfo.szbuffer;
			acerca.label5.Crear();
			acerca.label5.Fuente(14, !false, false, false, "ARIAL"); 
			// --> label 6
			acerca.label6.hWndPadre = acerca.frame3.hWnd;
			acerca.label6.hInstancia = acerca.hInstancia;
			acerca.label6.dwEstilo = CL_NORMAL;
			acerca.label6.Posicion.left = 10;
			acerca.label6.Posicion.top = 50;
			acerca.label6.Posicion.right = 300;
			acerca.label6.Posicion.bottom = 18;
			acerca.label6.lpszTexto = "ID de la estación de trabajo";
			acerca.label6.Crear();
			acerca.label6.Fuente(14, false, false, false, "ARIAL"); 
			// --> label 7
			acerca.label7.hWndPadre = acerca.frame3.hWnd;
			acerca.label7.hInstancia = acerca.hInstancia;
			acerca.label7.dwEstilo = CL_NORMAL;
			acerca.label7.Posicion.left = 10;
			acerca.label7.Posicion.top = 65;
			acerca.label7.Posicion.right = 300;
			acerca.label7.Posicion.bottom = 18;
			acerca.wininfo.NombreComputadora(); 
			acerca.label7.lpszTexto = acerca.wininfo.szbuffer;
			acerca.label7.Crear();
			acerca.label7.Fuente(14, !false, false, false, "ARIAL"); 
			// --> label 8
			acerca.label8.hWndPadre = acerca.frame3.hWnd;
			acerca.label8.hInstancia = acerca.hInstancia;
			acerca.label8.dwEstilo = CL_NORMAL;
			acerca.label8.Posicion.left = 10;
			acerca.label8.Posicion.top = 80;
			acerca.label8.Posicion.right = 300;
			acerca.label8.Posicion.bottom = 18;
			acerca.label8.lpszTexto = "Nombre usuario Windows";
			acerca.label8.Crear();
			acerca.label8.Fuente(14, false, false, false, "ARIAL"); 
			// --> label 9
			acerca.label9.hWndPadre = acerca.frame3.hWnd;
			acerca.label9.hInstancia = acerca.hInstancia;
			acerca.label9.dwEstilo = CL_NORMAL;
			acerca.label9.Posicion.left = 10;
			acerca.label9.Posicion.top = 95;
			acerca.label9.Posicion.right = 300;
			acerca.label9.Posicion.bottom = 18;
			acerca.wininfo.NombreUsuarioWin(); 
			acerca.label9.lpszTexto = acerca.wininfo.szbuffer;
			acerca.label9.Crear();
			acerca.label9.Fuente(14, !false, false, false, "ARIAL"); 
			// --> label 10
			acerca.label10.hWndPadre = acerca.frame3.hWnd;
			acerca.label10.hInstancia = acerca.hInstancia;
			acerca.label10.dwEstilo = CL_NORMAL;
			acerca.label10.Posicion.left = 10;
			acerca.label10.Posicion.top = 110;
			acerca.label10.Posicion.right = 300;
			acerca.label10.Posicion.bottom = 18;
			acerca.label10.lpszTexto = "Directorio Windows";
			acerca.label10.Crear();
			acerca.label10.Fuente(14, false, false, false, "ARIAL"); 
			// --> label 11
			acerca.label11.hWndPadre = acerca.frame3.hWnd;
			acerca.label11.hInstancia = acerca.hInstancia;
			acerca.label11.dwEstilo = CL_NORMAL;
			acerca.label11.Posicion.left = 10;
			acerca.label11.Posicion.top = 125;
			acerca.label11.Posicion.right = 300;
			acerca.label11.Posicion.bottom = 18;
			acerca.wininfo.WinDir(); 
			acerca.label11.lpszTexto = acerca.wininfo.szbuffer;
			acerca.label11.Crear();
			acerca.label11.Fuente(14, !false, false, false, "ARIAL"); 
			// --> Boton ver terminos de licencia de este programa
			acerca.boton1.hWndPadre = hWnd;
			acerca.boton1.hInstancia = acerca.hInstancia;
			acerca.boton1.dwEstilo = CB_NORMAL;
			acerca.boton1.lpszTexto = "Licencia";
			acerca.boton1.Posicion.left = 195;
			acerca.boton1.Posicion.top = 290;
			acerca.boton1.Posicion.right = 110;
			acerca.boton1.Posicion.bottom = 30;
			acerca.boton1.WndProcAddressButton = WndProcBoton1Acerca; 
			acerca.boton1.Crear();
			acerca.boton1.Fuente(14, false, false, false, "ARIAL");
			// --> Boton aceptar
			acerca.boton2.hWndPadre = hWnd;
			acerca.boton2.hInstancia = acerca.hInstancia;
			acerca.boton2.dwEstilo = CB_NORMAL;
			acerca.boton2.lpszTexto = "Aceptar";
			acerca.boton2.Posicion.left = 310;
			acerca.boton2.Posicion.top = 290;
			acerca.boton2.Posicion.right = 80;
			acerca.boton2.Posicion.bottom = 30;
			acerca.boton2.WndProcAddressButton = WndProcBoton2Acerca; 
			acerca.boton2.Crear();
			acerca.boton2.Fuente(14, false, false, false, "ARIAL");
			acerca.boton2.Foco(); 
			break;
		}
		case WM_COMMAND:{
			if(acerca.boton1.hWnd == (HWND) lParam){
				acerca.boton1.RestaurarIcono();
				acerca.Destruir(); 								
				texto.Texto(file.AbrirArchivo("licencia.txt")); 				
				EnableMenuItem(GetMenu(win.hWnd), ID_EDICIN_BUSCARYREEMPLAZAR, MF_ENABLED);	
				texto.Foco(); 
				break;
			}
			if(acerca.boton2.hWnd == (HWND) lParam){
				acerca.boton2.RestaurarIcono();
				acerca.Destruir(); 								
				texto.Foco(); 
				break;
			}
			break;
		}
		case WM_DESTROY:{
		  	PostQuitMessage(0);
			break;
		}
		default:{
			return DefWindowProc(hWnd, uMensaje, wParam, lParam);
			break;
		}
  }
   return 0;
}

// --> MANEJO DEL FOCO DEL TECLADO


LRESULT CALLBACK WndProcBoton1Acerca(HWND hWnd, UINT uMensaje, WPARAM wParam, LPARAM lParam){
		switch(uMensaje){
		case WM_KEYUP:
			if(wParam==VK_TAB||wParam==VK_RIGHT||wParam==VK_LEFT){
				acerca.boton2.Foco();  
				break;
			}	
			if(wParam==VK_RETURN){
				SendMessage(GetParent(hWnd), WM_COMMAND, (WPARAM) 1, (LPARAM) hWnd);
				break;
			}	
			break;
		default:
			return CallWindowProc(acerca.boton1.WndProcAddress , hWnd, uMensaje, (WPARAM) wParam, (LPARAM) lParam); 	 
			break;
		}
		return 0;
}

LRESULT CALLBACK WndProcBoton2Acerca(HWND hWnd, UINT uMensaje, WPARAM wParam, LPARAM lParam){
		switch(uMensaje){
		case WM_KEYUP:
			if(wParam==VK_TAB||wParam==VK_RIGHT||wParam==VK_LEFT){
				acerca.boton1.Foco();  
				break;
			}	
			break;
		case WM_KEYDOWN:
			if(wParam==VK_RETURN){
				SendMessage(GetParent(hWnd), WM_COMMAND, (WPARAM) 1, (LPARAM) hWnd);
				break;
			}	
			break;
		default:
			return CallWindowProc(acerca.boton2.WndProcAddress , hWnd, uMensaje, (WPARAM) wParam, (LPARAM) lParam); 	 
			break;
		}
		return 0;
}



