// -----------------------------------------------------------------
// CWndImp.h --> Clase para configurar impresión (21/07/2003)
// -----------------------------------------------------------------

LRESULT CALLBACK WndProcImp(HWND hWnd, UINT uMensaje, WPARAM wParam, LPARAM lParam);
void FuncionRetornoImp(LPSTR lpszNombreImpresora, LPSTR lpszTipoHoja, int nIzquierda, int nDerecha, int nSuperior, int nInferior);
LRESULT CALLBACK WndProcComboHojaImp(HWND hWnd, UINT uMensaje, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProcComboImpresoraImp(HWND hWnd, UINT uMensaje, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProcEditMargen1Imp(HWND hWnd, UINT uMensaje, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProcEditMargen2Imp(HWND hWnd, UINT uMensaje, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProcEditMargen3Imp(HWND hWnd, UINT uMensaje, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProcEditMargen4Imp(HWND hWnd, UINT uMensaje, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProcBotonAceptarImp(HWND hWnd, UINT uMensaje, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProcBotonCancelarImp(HWND hWnd, UINT uMensaje, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProcBotonAyudaImp(HWND hWnd, UINT uMensaje, WPARAM wParam, LPARAM lParam);

class CWndImp{
public:
	// --> Propiedades
	HWND         hWndPadre;
	HINSTANCE    hInstancia;
	HICON        hIcon;
	HCURSOR      hCursor;
	Cwindow      win;
	Cframe       frame1;
	Cframe       frame2;
	Cframe       frame3;
	Ccombobox    combo1;
	Ccombobox    combo2;
	Clabel       label1;
	Clabel       label2;
	Clabel       label3;
	Clabel       label4;
	Clabel       label5;
	Cbutton      boton1;
	Cbutton      boton2;
	Cbutton      boton3;
	Cedit        edit1;
	Cedit        edit2;
	Cedit        edit3;
	Cedit        edit4;
	Cimpresora   imp;
	Capi         api;
	Cregistro    reg;
	LPSTR        lpszAyuda;
	LPSTR        lpszTitulo;
	LPSTR        lpszRegDir;
	int          nPosX;
	int          nPosY;
	// --> Métodos
	void CWndImp::Crear(void);
	void CWndImp::Destruir(void);
};

CWndImp WndImp;

void CWndImp::Destruir(void){
	win.Destruir();
	win.hWnd = NULL;
}

void CWndImp::Crear(void){
	win.hWndPadre = hWndPadre;
	win.hInstancia = hInstancia;
	win.dwEstilo = WS_CAPTION;
	win.lpszTitulo = lpszTitulo;
	win.nModoWin = SW_SHOW;
	win.Posicion.left = nPosX;
	win.Posicion.top = nPosY;
	win.Posicion.right = 400;
	win.Posicion.bottom = 295;
	win.WndProc = WndProcImp;
	win.Crear(); 
}

LRESULT CALLBACK WndProcImp(HWND hWnd, UINT uMensaje, WPARAM wParam, LPARAM lParam){
	switch(uMensaje){
		case WM_CREATE:{
			// --> Frame 1
			WndImp.frame1.hWndPadre = hWnd;
			WndImp.frame1.hInstancia = WndImp.hInstancia;
			WndImp.frame1.lpszTitulo = "Seleccione tipo de hoja";
			WndImp.frame1.Posicion.left = 5;
			WndImp.frame1.Posicion.top = 5;
			WndImp.frame1.Posicion.right = 385;
			WndImp.frame1.Posicion.bottom = 50;
			WndImp.frame1.Crear();
			WndImp.frame1.Fuente(14, false, false, false, "ARIAL"); 
			// --> Label1
			WndImp.label1.hWndPadre = hWnd;
			WndImp.label1.hInstancia = WndImp.hInstancia;
			WndImp.label1.dwEstilo = CL_NORMAL;
			WndImp.label1.Posicion.left = 160;
			WndImp.label1.Posicion.top = 25;
			WndImp.label1.Posicion.right = 200;
			WndImp.label1.Posicion.bottom = 20;
			WndImp.label1.Crear();
			WndImp.label1.Fuente(14, !false, false, false, "ARIAL"); 
			// --> Combo1
			WndImp.combo1.hWndPadre = hWnd;
			WndImp.combo1.hInstancia = WndImp.hInstancia;
			WndImp.combo1.nAncho = 140;
			WndImp.combo1.X = 15;
			WndImp.combo1.Y = 23;
			WndImp.combo1.WndProcAddressCombo = WndProcComboHojaImp; 
			WndImp.combo1.Crear(); 
			WndImp.combo1.AgregarItem("Hoja Tamaño Carta");
			WndImp.combo1.AgregarItem("Hoja Tamaño Oficio");
			WndImp.combo1.Fuente(14, false, false, false, "ARIAL");
			WndImp.combo1.SeleccionarItem(0); 
			WndImp.combo1.Foco();
			// --> Frame 2
			WndImp.frame2.hWndPadre = hWnd;
			WndImp.frame2.hInstancia = WndImp.hInstancia;
			WndImp.frame2.lpszTitulo = "Seleccione una impresora";
			WndImp.frame2.Posicion.left = 5;
			WndImp.frame2.Posicion.top = 55;
			WndImp.frame2.Posicion.right = 385;
			WndImp.frame2.Posicion.bottom = 50;
			WndImp.frame2.Crear();
			WndImp.frame2.Fuente(14, false, false, false, "ARIAL"); 
			// --> Combo 2
			WndImp.combo2.hWndPadre = hWnd;
			WndImp.combo2.hInstancia = WndImp.hInstancia;
			WndImp.combo2.nAncho = 300;
			WndImp.combo2.X = 15;
			WndImp.combo2.Y = 72;
			WndImp.combo2.WndProcAddressCombo = WndProcComboImpresoraImp; 
			WndImp.combo2.Crear(); 
			int nBucle=0;
			for(nBucle=0;nBucle<5;nBucle++){
				if(lstrlen(WndImp.imp.ObtenerImpresoraLocal(nBucle))>1){
					WndImp.combo2.AgregarItem(WndImp.imp.ObtenerImpresoraLocal(nBucle)); 
				}			
				if(lstrlen(WndImp.imp.ObtenerImpresoraRed(nBucle))>1){
					WndImp.combo2.AgregarItem(WndImp.imp.ObtenerImpresoraRed(nBucle)); 
				}			
				if(lstrlen(WndImp.imp.ObtenerImpresoraRemota(nBucle))>1){
					WndImp.combo2.AgregarItem(WndImp.imp.ObtenerImpresoraRemota(nBucle)); 
				}
			}			
			WndImp.combo2.Fuente(14, false, false, false, "ARIAL");
			WndImp.combo2.SeleccionarItem(0); 
			WndImp.combo2.Foco();
			// --> Frame 3
			WndImp.frame3.hWndPadre = hWnd;
			WndImp.frame3.hInstancia = WndImp.hInstancia;
			WndImp.frame3.lpszTitulo = "Indique los margenes de impresión";
			WndImp.frame3.Posicion.left = 5;
			WndImp.frame3.Posicion.top = 105;
			WndImp.frame3.Posicion.right = 385;
			WndImp.frame3.Posicion.bottom = 120;
			WndImp.frame3.Crear();
			WndImp.frame3.Fuente(14, false, false, false, "ARIAL"); 
			// --> Label2
			WndImp.label2.hWndPadre = hWnd;
			WndImp.label2.hInstancia = WndImp.hInstancia;
			WndImp.label2.dwEstilo = CL_NORMAL;
			WndImp.label2.Posicion.left = 15;
			WndImp.label2.Posicion.top = 125;
			WndImp.label2.Posicion.right = 350;
			WndImp.label2.Posicion.bottom = 20;
			WndImp.label2.lpszTexto = "Margen Izquierdo (en milimetros)";
			WndImp.label2.Crear();
			WndImp.label2.Fuente(14, false, false, false, "ARIAL"); 
			// --> Label3
			WndImp.label3.hWndPadre = hWnd;
			WndImp.label3.hInstancia = WndImp.hInstancia;
			WndImp.label3.dwEstilo = CL_NORMAL;
			WndImp.label3.Posicion.left = 15;
			WndImp.label3.Posicion.top = 150;
			WndImp.label3.Posicion.right = 350;
			WndImp.label3.Posicion.bottom = 20;
			WndImp.label3.lpszTexto = "Margen Derecho (en milimetros)";
			WndImp.label3.Crear();
			WndImp.label3.Fuente(14, false, false, false, "ARIAL"); 
			// --> Label4
			WndImp.label4.hWndPadre = hWnd;
			WndImp.label4.hInstancia = WndImp.hInstancia;
			WndImp.label4.dwEstilo = CL_NORMAL;
			WndImp.label4.Posicion.left = 15;
			WndImp.label4.Posicion.top = 175;
			WndImp.label4.Posicion.right = 350;
			WndImp.label4.Posicion.bottom = 20;
			WndImp.label4.lpszTexto = "Margen Superior (en milimetros)";
			WndImp.label4.Crear();
			WndImp.label4.Fuente(14, false, false, false, "ARIAL");
			// --> Label5
			WndImp.label5.hWndPadre = hWnd;
			WndImp.label5.hInstancia = WndImp.hInstancia;
			WndImp.label5.dwEstilo = CL_NORMAL;
			WndImp.label5.Posicion.left = 15;
			WndImp.label5.Posicion.top = 200;
			WndImp.label5.Posicion.right = 350;
			WndImp.label5.Posicion.bottom = 20;
			WndImp.label5.lpszTexto = "Margen Inferior (en milimetros)";
			WndImp.label5.Crear();
			WndImp.label5.Fuente(14, false, false, false, "ARIAL");
			// --> Edit 1
			WndImp.edit1.hWndPadre = hWnd;
			WndImp.edit1.hInstancia = WndImp.hInstancia;
			WndImp.edit1.dwEstilo = CE_NORMAL;
			WndImp.edit1.Posicion.left = 200;
			WndImp.edit1.Posicion.top = 120;
			WndImp.edit1.Posicion.right = 20;
			WndImp.edit1.Posicion.bottom = 20;
			WndImp.edit1.lpszTexto = "25";
			WndImp.edit1.WndProcAddressEdit = WndProcEditMargen1Imp; 
			WndImp.edit1.Crear();
			WndImp.edit1.Fuente(14, false, false, false, "ARIAL"); 
			// --> Edit 2
			WndImp.edit2.hWndPadre = hWnd;
			WndImp.edit2.hInstancia = WndImp.hInstancia;
			WndImp.edit2.dwEstilo = CE_NORMAL;
			WndImp.edit2.Posicion.left = 200;
			WndImp.edit2.Posicion.top = 145;
			WndImp.edit2.Posicion.right = 20;
			WndImp.edit2.Posicion.bottom = 20;
			WndImp.edit2.lpszTexto = "25";
			WndImp.edit2.WndProcAddressEdit = WndProcEditMargen2Imp; 
			WndImp.edit2.Crear();
			WndImp.edit2.Fuente(14, false, false, false, "ARIAL"); 
			// --> Edit 3
			WndImp.edit3.hWndPadre = hWnd;
			WndImp.edit3.hInstancia = WndImp.hInstancia;
			WndImp.edit3.dwEstilo = CE_NORMAL;
			WndImp.edit3.Posicion.left = 200;
			WndImp.edit3.Posicion.top = 170;
			WndImp.edit3.Posicion.right = 20;
			WndImp.edit3.Posicion.bottom = 20;
			WndImp.edit3.lpszTexto = "25";
			WndImp.edit3.WndProcAddressEdit = WndProcEditMargen3Imp; 
			WndImp.edit3.Crear();
			WndImp.edit3.Fuente(14, false, false, false, "ARIAL"); 
			// --> Edit 4
			WndImp.edit4.hWndPadre = hWnd;
			WndImp.edit4.hInstancia = WndImp.hInstancia;
			WndImp.edit4.dwEstilo = CE_NORMAL;
			WndImp.edit4.Posicion.left = 200;
			WndImp.edit4.Posicion.top = 195;
			WndImp.edit4.Posicion.right = 20;
			WndImp.edit4.Posicion.bottom = 20;
			WndImp.edit4.lpszTexto = "25";
			WndImp.edit4.WndProcAddressEdit = WndProcEditMargen4Imp; 
			WndImp.edit4.Crear();
			WndImp.edit4.Fuente(14, false, false, false, "ARIAL"); 
			// --> Boton aceptar
			WndImp.boton1.hWndPadre = hWnd;
			WndImp.boton1.hInstancia = WndImp.hInstancia;
			WndImp.boton1.dwEstilo = CB_NORMAL;
			WndImp.boton1.Posicion.left = 225;
			WndImp.boton1.Posicion.top = 230;
			WndImp.boton1.Posicion.right = 80;
			WndImp.boton1.Posicion.bottom = 30;
			WndImp.boton1.lpszTexto = "Aceptar";
			WndImp.boton1.WndProcAddressButton = WndProcBotonAceptarImp; 
			WndImp.boton1.Crear(); 
			WndImp.boton1.Fuente(14, false, false, false, "ARIAL"); 
			// --> Boton Cancelar
			WndImp.boton2.hWndPadre = hWnd;
			WndImp.boton2.hInstancia = WndImp.hInstancia;
			WndImp.boton2.dwEstilo = CB_NORMAL;
			WndImp.boton2.Posicion.left = 310;
			WndImp.boton2.Posicion.top = 230;
			WndImp.boton2.Posicion.right = 80;
			WndImp.boton2.Posicion.bottom = 30;
			WndImp.boton2.lpszTexto = "Cancelar";
			WndImp.boton2.WndProcAddressButton = WndProcBotonCancelarImp; 
			WndImp.boton2.Crear(); 
			WndImp.boton2.Fuente(14, false, false, false, "ARIAL"); 
			// --> Boton ayuda
			WndImp.boton3.hWndPadre = hWnd;
			WndImp.boton3.hInstancia = WndImp.hInstancia;
			WndImp.boton3.dwEstilo = CB_NORMAL;
			WndImp.boton3.Posicion.left = 310;
			WndImp.boton3.Posicion.top = 230;
			WndImp.boton3.Posicion.right = 80;
			WndImp.boton3.Posicion.bottom = 30;
			WndImp.boton3.lpszTexto = "Ayuda";
			WndImp.boton3.WndProcAddressButton= WndProcBotonAyudaImp; 
//			WndImp.boton3.Crear(); 
			WndImp.boton3.Fuente(14, false, false, false, "ARIAL"); 
			// --> Carga los datos almacenados
			WndImp.reg.Clave = CR_USUARIOACTUAL;
			WndImp.reg.Entrada = WndImp.lpszRegDir;
			for(nBucle=0;nBucle<=WndImp.combo2.NumeroItems();nBucle++){		
				if (!strcmp(WndImp.reg.ObtenerValor("impresora"), WndImp.combo2.TextoItem(nBucle))){ 
					WndImp.combo2.SeleccionarItem(nBucle); 	
				}
			}
			for(nBucle=0;nBucle<=WndImp.combo1.NumeroItems();nBucle++){		
				if (!strcmp(WndImp.reg.ObtenerValor("hoja"), WndImp.combo1.TextoItem(nBucle))){ 
					WndImp.combo1.SeleccionarItem(nBucle); 	
				}
			}
			WndImp.combo1.Foco();  
			if(lstrlen(WndImp.reg.ObtenerValor("izquierda"))>1){
				WndImp.edit1.Texto(WndImp.reg.ObtenerValor("izquierda"));
			}
			if(lstrlen(WndImp.reg.ObtenerValor("derecha"))>1){
				WndImp.edit2.Texto(WndImp.reg.ObtenerValor("derecha"));
			}
			if(lstrlen(WndImp.reg.ObtenerValor("superior"))>1){
				WndImp.edit3.Texto(WndImp.reg.ObtenerValor("superior"));
			}
			if(lstrlen(WndImp.reg.ObtenerValor("inferior"))>1){
				WndImp.edit4.Texto(WndImp.reg.ObtenerValor("inferior"));
			}
			break;
		}	
		case WM_COMMAND:{
			if(WndImp.combo1.hWnd == (HWND) lParam){
				if(WndImp.combo1.ItemSeleccionado()==0){
					WndImp.label1.Texto("Tamaño : 28 cm x 21,5 cm");  	
					break;
				}
				if(WndImp.combo1.ItemSeleccionado()==1){
					WndImp.label1.Texto("Tamaño : 33 cm x 21,5 cm");  	
					break;
				}

			}
			if(WndImp.boton1.hWnd == (HWND) lParam){
				WndImp.boton1.RestaurarIcono();
				WndImp.reg.Clave = CR_USUARIOACTUAL;
				WndImp.reg.Entrada = WndImp.lpszRegDir;
				WndImp.reg.CrearClave();
				WndImp.reg.GuardarValor("hoja", WndImp.combo1.TextoItem(WndImp.combo1.ItemSeleccionado()));     
				WndImp.reg.GuardarValor("impresora", WndImp.combo2.TextoItem(WndImp.combo2.ItemSeleccionado()));
				WndImp.reg.GuardarValor("izquierda", WndImp.edit1.Texto());
				WndImp.reg.GuardarValor("derecha", WndImp.edit2.Texto());
				WndImp.reg.GuardarValor("superior", WndImp.edit3.Texto());
				WndImp.reg.GuardarValor("inferior", WndImp.edit4.Texto());
				FuncionRetornoImp(WndImp.combo2.TextoItem(WndImp.combo2.ItemSeleccionado()), WndImp.combo1.TextoItem(WndImp.combo1.ItemSeleccionado()), atoi(WndImp.edit1.Texto()), atoi(WndImp.edit2.Texto()), atoi(WndImp.edit3.Texto()), atoi(WndImp.edit4.Texto()));  
				WndImp.Destruir(); 
				break;
			}
			if(WndImp.boton2.hWnd == (HWND) lParam){
				WndImp.boton2.RestaurarIcono();
				SetFocus(WndImp.hWndPadre); 
				WndImp.Destruir(); 
				texto.Foco(); 
				break;
			}
			if(WndImp.boton3.hWnd == (HWND) lParam){
				WndImp.boton3.RestaurarIcono();
				WndImp.api.EjecutarArchivo(WndImp.lpszAyuda, "", SW_SHOW);  
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

LRESULT CALLBACK WndProcComboHojaImp(HWND hWnd, UINT uMensaje, WPARAM wParam, LPARAM lParam){
		switch(uMensaje){
		case WM_KEYUP:
			if(wParam==VK_TAB){
				WndImp.combo2.Foco();  
				break;
			}
			break;
		default:
			return CallWindowProc(WndImp.combo1.WndProcAddress, hWnd, uMensaje, (WPARAM) wParam, (LPARAM) lParam); 	 
			break;
		}
		return 0;
}

LRESULT CALLBACK WndProcComboImpresoraImp(HWND hWnd, UINT uMensaje, WPARAM wParam, LPARAM lParam){
		switch(uMensaje){
		case WM_KEYUP:
			if(wParam==VK_TAB){
				WndImp.edit1.Foco();  
				break;
			}	
			break;
		default:
			return CallWindowProc(WndImp.combo2.WndProcAddress, hWnd, uMensaje, (WPARAM) wParam, (LPARAM) lParam); 	 
			break;
		}
		return 0;
}

LRESULT CALLBACK WndProcEditMargen1Imp(HWND hWnd, UINT uMensaje, WPARAM wParam, LPARAM lParam){
		switch(uMensaje){
		case WM_KEYUP:
			if(wParam==VK_TAB){
				WndImp.edit2.Foco();  
				break;
			}	
			break;
		default:
			return CallWindowProc(WndImp.edit1.WndProcAddress, hWnd, uMensaje, (WPARAM) wParam, (LPARAM) lParam); 	 
			break;
		}
		return 0;
}

LRESULT CALLBACK WndProcEditMargen2Imp(HWND hWnd, UINT uMensaje, WPARAM wParam, LPARAM lParam){
		switch(uMensaje){
		case WM_KEYUP:
			if(wParam==VK_TAB){
				WndImp.edit3.Foco();  
				break;
			}	
			break;
		default:
			return CallWindowProc(WndImp.edit2.WndProcAddress, hWnd, uMensaje, (WPARAM) wParam, (LPARAM) lParam); 	 
			break;
		}
		return 0;
}

LRESULT CALLBACK WndProcEditMargen3Imp(HWND hWnd, UINT uMensaje, WPARAM wParam, LPARAM lParam){
		switch(uMensaje){
		case WM_KEYUP:
			if(wParam==VK_TAB){
				WndImp.edit4.Foco();  
				break;
			}	
			break;
		default:
			return CallWindowProc(WndImp.edit3.WndProcAddress, hWnd, uMensaje, (WPARAM) wParam, (LPARAM) lParam); 	 
			break;
		}
		return 0;
}

LRESULT CALLBACK WndProcEditMargen4Imp(HWND hWnd, UINT uMensaje, WPARAM wParam, LPARAM lParam){
		switch(uMensaje){
		case WM_KEYUP:
			if(wParam==VK_TAB){
				WndImp.boton1.Foco();  
				break;
			}	
			break;
		default:
			return CallWindowProc(WndImp.edit4.WndProcAddress, hWnd, uMensaje, (WPARAM) wParam, (LPARAM) lParam); 	 
			break;
		}
		return 0;
}

LRESULT CALLBACK WndProcBotonAceptarImp(HWND hWnd, UINT uMensaje, WPARAM wParam, LPARAM lParam){
		switch(uMensaje){
		case WM_KEYUP:
			if(wParam==VK_TAB||wParam==VK_RIGHT){
				WndImp.boton2.Foco();   
				break;
			}	
			if(wParam==VK_LEFT){
				WndImp.edit4.Foco();  
				break;
			}
			if(wParam==VK_RETURN){
				SendMessage(GetParent(hWnd), WM_COMMAND, (WPARAM) 1, (LPARAM) hWnd);
				break;
			}	
			break;
		default:
			return CallWindowProc(WndImp.boton1.WndProcAddress , hWnd, uMensaje, (WPARAM) wParam, (LPARAM) lParam); 	 
			break;
		}
		return 0;
}

LRESULT CALLBACK WndProcBotonCancelarImp(HWND hWnd, UINT uMensaje, WPARAM wParam, LPARAM lParam){
		switch(uMensaje){
		case WM_KEYUP:
			if(wParam==VK_TAB||wParam==VK_RIGHT){
				WndImp.boton3.Foco();   
				break;
			}	
			if(wParam==VK_LEFT){
				WndImp.boton1.Foco();  
				break;
			}
			if(wParam==VK_RETURN){
				SendMessage(GetParent(hWnd), WM_COMMAND, (WPARAM) 1, (LPARAM) hWnd);
				break;
			}	
			break;
		default:
			return CallWindowProc(WndImp.boton2.WndProcAddress , hWnd, uMensaje, (WPARAM) wParam, (LPARAM) lParam); 	 
			break;
		}
		return 0;
}

LRESULT CALLBACK WndProcBotonAyudaImp(HWND hWnd, UINT uMensaje, WPARAM wParam, LPARAM lParam){
		switch(uMensaje){
		case WM_KEYUP:
			if(wParam==VK_TAB||wParam==VK_RIGHT){
				WndImp.combo1.Foco();  
				break;
			}	
			if(wParam==VK_LEFT){
				WndImp.boton2.Foco();  
				break;
			}
			if(wParam==VK_RETURN){
				SendMessage(GetParent(hWnd), WM_COMMAND, (WPARAM) 1, (LPARAM) hWnd);
				break;
			}	
			break;
		default:
			return CallWindowProc(WndImp.boton3.WndProcAddress , hWnd, uMensaje, (WPARAM) wParam, (LPARAM) lParam); 	 
			break;
		}
		return 0;
}


