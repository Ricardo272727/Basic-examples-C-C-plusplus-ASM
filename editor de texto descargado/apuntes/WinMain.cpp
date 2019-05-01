// ------------------------------------------------------------
// TIPO DE PROGRAMA --> FREEWARE (CODIGO ABIERTO)
// DESCRIPCION      --> APUNTES, EDITOR DE TEXTO
// DESARROLLADOR    --> HUMBERTO SUAREZ
// VERSION          --> 1.0.0
// COMPATIBILIDAD   --> WIN9X, WINNT
// FECHA            --> 17/10/2003 10:11 A.M.
// ------------------------------------------------------------
// -- PARA LOS DESARROLLADORES --
// Apuntes, es un programa de codigo abierto, por lo cual cualquiera
// puede modificar este programa segun su conveniencia, la idea
// es poder entre todos crear una aplicacion de edicion de texto
// con capacidades similares a wordpad, word u otro editor de texto
// Me gustaria mucho que si alguno genera una modificacion que 
// mejore las capacidades del programa me enviase el codigo fuente
// a mi correo humbertosc@cantv.net para publicarlo.

// --> INCLUDES
// ------------------------------------------------------------

#ifndef WINDOWS_H_
	#include <windows.h>
#endif

#ifndef WINREG_H_
	#include <winreg.h>
#endif

#ifndef WINUSER_H_
	#include <winuser.h>
#endif

#ifndef WINBASE_H_
	#include <winbase.h>
#endif

#ifndef SHLWAPI_H_
	#include <SHLWAPI.h>
#endif

#ifndef SHLOBJ_H_
	#include <shlobj.h>
#endif

#ifndef COMMDLG_H_
	#include <commdlg.h>
#endif

#ifndef SHELLAPI_H_
	#include <shellapi.h>
#endif

#ifndef COMMCTRL_H_
	#include <commctrl.h>
#endif

#ifndef RICHEDIT_H_
	#include <richedit.h>
#endif

#ifndef WINSPOOL_H_
	#include <winspool.h>
#endif

#ifndef WINABLE_H_
	#include <winable.h>
#endif

#ifndef RICHEDIT_H_
	#include <richedit.h>
#endif

#ifndef CONSTANTES_H_
	#include "constantes.h"
#endif

#ifndef CAPI_H_
	#include "clases de uso variado//Capi.h"
#endif

#ifndef CSTRING_H_
	#include "clases de uso variado//Cstring.h"
#endif

#ifndef CRICHEDIT_H_
	#include "clases de controles//Crichedit.h"
#endif

#ifndef CSTATUSBAR_H_
	#include "clases de controles//Cstatusbar.h"
#endif

#ifndef CWINDOW_H_
	#include "clases de controles//Cwindow.h"
#endif

#ifndef CIMAGEN_H_
	#include "clases de controles//Cimagen.h"
#endif

#ifndef CLABEL_H_
	#include "clases de controles//Clabel.h"
#endif

#ifndef CBUTTON_H_
	#include "clases de controles//Cbutton.h"
#endif

#ifndef CCOMBOBOX_H_
	#include "clases de controles//Ccombobox.h"
#endif

#ifndef CEDIT_H_
	#include "clases de controles//Cedit.h"
#endif

#ifndef CFRAME_H_
	#include "clases de controles//Cframe.h"
#endif

#ifndef CCHECKBOX_H_
	#include "clases de controles//Ccheckbox.h"
#endif

#ifndef CWININFO_H_
	#include "clases de uso variado//Cwininfo.h"
#endif

#ifndef CDIALOGOS_H_
	#include "clases de uso variado//Cdialogos.h"
#endif

#ifndef CFILE_H_
	#include "clases de uso variado//Cfile.h"
#endif

#ifndef CCLIPBOARD_H_
	#include "clases de uso variado//Cclipboard.h"
#endif

#ifndef CIMPRESORA_H_
	#include "clases de uso variado//Cimpresora.h"
#endif

#ifndef CREGISTRO_H_
	#include "clases de uso variado//Cregistro.h"
#endif

#ifndef RESOURCE_H_
	#include "resource.h"
#endif

// ------------------------------------------------------------

// --> Variables Globales
// ------------------------------------------------------------
	Cwindow win;
	Crichedit texto;
	Cstatusbar statusb;
	Cdialogos diag;
	Cfile file;
	Cstring str;
	Cclipboard clip;
	Capi api;
	Cimpresora imp;
	Cframe framebuscar;
	Clabel labelbuscar;
	Cedit editbuscar;
	Clabel labelreemp;
	Cedit editreemp;
	Cbutton botonaceptarbuscar;
	Cbutton botoncancelarbuscar;
	int resp;
	char szFechaHora[255];
	char szsel[255];
	char sztest[255];
	bool bImpresion;
	Cwindow buscar;
	FINDTEXT ft;
	CHARRANGE chr;
	int nPos;
	int nFin;
// ------------------------------------------------------------

#ifndef CWNDACERCA_H_
	#include "clases complejas//CWndAcerca.h"
#endif

#ifndef CWNDIMP_H_
	#include "clases complejas//CWndImp.h"
#endif

LRESULT CALLBACK WndProcBuscar(HWND hWnd, UINT uMensaje, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK wndproceditbuscar(HWND hWnd, UINT uMensaje, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK wndprocbotoncancelarbuscar(HWND hWnd, UINT uMensaje, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK wndprocbotonaceptarbuscar(HWND hWnd, UINT uMensaje, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK wndproceditreemp(HWND hWnd, UINT uMensaje, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK wndproctexto(HWND hWnd, UINT uMensaje, WPARAM wParam, LPARAM lParam);
VOID CALLBACK TimerProcClip(HWND hwnd, UINT uMsg, UINT idEvent, DWORD dwTime);
void ChequearSalida(void);
	
void FuncionRetornoImp(LPSTR lpszNombreImpresora, LPSTR lpszTipoHoja, int nIzquierda, int nDerecha, int nSuperior, int nInferior){
	imp.nMargenIzquierdo = nIzquierda;
	imp.nMargenSuperior = nSuperior;
	imp.nMenosMargenDerecho = nDerecha;
	imp.nMenosMargenInferior = nInferior;
	lstrcpy(imp.szImpresora, lpszNombreImpresora);
	if(lstrcmp(CharUpper(lpszTipoHoja), "HOJA TAMAÑO CARTA")==0){
		imp.bHojaCarta = true;
	}else{
		imp.bHojaCarta = !true;
	}
	texto.Foco(); 
	if(bImpresion){
		imp.ImpresionPorLineas(texto.Mensaje(EM_GETLINECOUNT, 0, 0), texto, imp.bHojaCarta, fuentes, statusb.Texto(), 25);
		bImpresion=false;
	}
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
       switch(uMsg){
			case WM_CREATE:
			   // --> RICHEDIT
			   texto.hWndPadre = hWnd;
			   texto.hInstancia = win.hInstancia;
			   texto.Posicion.left = 0;
			   texto.Posicion.top = 0;
			   texto.Posicion.right = win.Posicion.right-7;
			   texto.Posicion.bottom = win.Posicion.bottom - 73;
			   texto.WndProcAddressRich = wndproctexto;
			   texto.Crear();
               // --> BARRA DE ESTADO
			   statusb.hWndPadre = hWnd;
			   statusb.hInstancia = win.hInstancia;
			   statusb.dwEstilo = CS_ABAJO;
			   statusb.Crear();
			   statusb.Texto("Listo"); 
			   texto.Foco(); 
			   fuentes.cursiva = false;
			   fuentes.negrita = false;
			   fuentes.tamano = 14;
			   fuentes.subrayado = false;
			   lstrcpy(fuentes.szfuente, "ARIAL"); 
			   texto.Fuente(fuentes.tamano, fuentes.negrita, fuentes.cursiva, fuentes.subrayado, fuentes.szfuente); 
			   SetTimer(hWnd, 0, 10, TimerProcClip);	
			   texto.Mensaje(EM_LIMITTEXT, 65000, 0); 	   
			   break;
			case WM_ACTIVATE:
			   texto.Foco();
			   break;
			case WM_COMMAND:
				switch(LOWORD(wParam)){	
					case ID_AYUDA_ACERCADE:
						if(acerca.win.hWnd == NULL){ 
							acerca.hWndPadre = hWnd;
							acerca.hInstancia = win.hInstancia;
							acerca.nPosX = 100;
							acerca.nPosY = 100;
							acerca.lpszIconoApp = "ICONO";
							acerca.lpszNombreApp = "Apuntes versión 1.0.0 Freeware | Classex 1.2";
							acerca.lpszProgramadorInfo = "2003 Humberto Suárez\nCorreo Electrónico : humbertosc@cantv.net";
							acerca.lpszTitulo = "Acerca de...";
							acerca.lpszVersionApp = "MundoC++ >> http://www.iespana.es/elmundoc/";
							acerca.hIcono = win.hIcono;
							acerca.hCursor = win.hCursor;
							acerca.Crear(); 
						}
						break;
					case ID_ARCHIVO_ABRIRDOCUMENTO:
						diag.hWndPadre = hWnd;
						diag.hInstancia = win.hInstancia;
						diag.Abrir("Archivos de texto(*.txt)\0*.txt\0", "Seleccione un archivo"); 
						if(lstrcmp(diag.szbuffer, "")!=0){
							texto.Texto(file.AbrirArchivo(diag.szbuffer));  	
							statusb.Texto(diag.szbuffer);
							texto.Foco(); 
							texto.Mensaje(EM_SETMODIFY, (WPARAM) false, 0); 
						}else{
							texto.Foco(); 
						}
						break;
					case ID_ARCHIVO_GUARDARCOMO:
						diag.hWndPadre = hWnd;
						diag.hInstancia = win.hInstancia;
						diag.Guardar("Archivos de texto(*.txt)\0*.txt\0", "Indique el nombre del archivo a almacenar"); 
						if(lstrcmp(diag.szbuffer, "")!=0){
							if(lstrcmp(CharUpper(str.Derecha(diag.szbuffer, 4)), ".TXT")!=0){
								lstrcat(diag.szbuffer, ".txt"); 
							}
						}
						file.GuardarArchivo(diag.szbuffer, texto.Texto());   					
						statusb.Texto(diag.szbuffer);
						texto.Mensaje(EM_SETMODIFY, (WPARAM) false, 0); 
						texto.Foco(); 
						break;
					case ID_FORMATO_CAMBIARCOLORDEFONDO:
						diag.hWndPadre = hWnd;
						diag.hInstancia = win.hInstancia;
						COLORREF color;
						color = diag.Color();
						if(color!=NULL){
							texto.Mensaje(EM_SETBKGNDCOLOR, 0, (LPARAM) color); 						
						}
						texto.Foco(); 
						break;
					case ID_ARCHIVO_NUEVODOCUMENTO:
						texto.Texto("");
						lstrcpy(diag.szbuffer, ""); 
						statusb.Texto("Listo"); 
						texto.Mensaje(EM_SETMODIFY, (WPARAM) false, 0); 
						EnableMenuItem(GetMenu(win.hWnd), ID_EDICIN_DESHACER, MF_GRAYED);	
						texto.Foco(); 					
						break;
					case ID_ARCHIVO_GUARDARDOCUMENTO:
						diag.hWndPadre = hWnd;
						diag.hInstancia = win.hInstancia;
						if(lstrcmp(diag.szbuffer, "")==0){
							diag.Guardar("Archivos de texto(*.txt)\0*.txt\0", "Indique el nombre del archivo a almacenar"); 							
							if(lstrcmp(CharUpper(str.Derecha(diag.szbuffer, 4)), ".TXT")!=0 && lstrlen(diag.szbuffer)>1){
								lstrcat(diag.szbuffer, ".txt"); 
							}
						}
						file.GuardarArchivo(diag.szbuffer, texto.Texto());   					
						if(lstrlen(diag.szbuffer)>1) statusb.Texto(diag.szbuffer);
						texto.Mensaje(EM_SETMODIFY, (WPARAM) false, 0); 
						texto.Foco(); 
						break;
					case ID_EDICIN_PEGAR:
						texto.Mensaje(EM_PASTESPECIAL, (WPARAM) (UINT) 0, 0); 
						break;
					case ID_EDICIN_BORRAR:
						texto.Mensaje(EM_REPLACESEL, true, (LPARAM) ""); 
						break;
					case ID_EDICIN_SELECCIONARTODO:
						texto.Mensaje(EM_SETSEL, 0, -1);  
						texto.Mensaje(EM_SCROLLCARET, 0, 0);  
						break;
					case ID_EDICIN_CORTAR:
						texto.Mensaje(EM_GETSELTEXT, 0, (LPARAM) szsel); 					 
						clip.CopiarTexto(szsel); 
						texto.Mensaje(EM_REPLACESEL, true, (LPARAM) ""); 
						break;
					case ID_EDICIN_COPIAR:
						texto.Mensaje(EM_GETSELTEXT, 0, (LPARAM) szsel); 					 
						clip.CopiarTexto(szsel); 
						break;
					case ID_EDICIN_INSERTARFECHAYHORA:
						lstrcpy(szFechaHora, api.Fecha());
						lstrcat(szFechaHora, " ");
						lstrcat(szFechaHora, api.Hora());
						texto.Mensaje(EM_REPLACESEL, true, (LPARAM) szFechaHora); 
						break;
					case ID_ARCHIVO_CONFIGURARIMPRESIN:
						if(WndImp.win.hWnd==NULL){  
							WndImp.hWndPadre = hWnd;
							WndImp.hInstancia = win.hInstancia;
							WndImp.lpszAyuda = "confimp.htm";
							WndImp.lpszRegDir = "MundoC++//Apuntes 1.0.0//";
							WndImp.lpszTitulo = "Configurar impresión";
							WndImp.nPosX = 100;
							WndImp.nPosY = 100;
							WndImp.Crear(); 
						}
						break;
					case ID_EDICIN_DESHACER:
						texto.Mensaje(EM_UNDO, 0, 0); 
						break;
					case ID_EDICIN_BUSCARYREEMPLAZAR:
						if(buscar.hWnd == NULL){
							buscar.hWndPadre = hWnd;
							buscar.hInstancia = win.hInstancia;
							buscar.dwEstilo = CW_DIALOGOCERRAR;
							buscar.hCursor = LoadCursor(NULL, IDC_ARROW);
							buscar.hIcono = LoadIcon(win.hInstancia, "ICONO");
							buscar.lpszTitulo = "Buscar y reemplazar";
							buscar.nModoWin = SW_SHOW;
							buscar.WndProc = WndProcBuscar;
							buscar.Posicion.left = 400;
							buscar.Posicion.top = 200;
							buscar.Posicion.bottom = 180;
							buscar.Posicion.right = 400;
							buscar.Crear(); 
							break;
						}
					case ID_ARCHIVO_SALIR:
						ChequearSalida();
						break;
					case ID_AYUDA_REPORTARERRORES:
						api.EjecutarArchivo("mailto:humbertosc@cantv.net?subject=Reportar errores", "", SW_SHOW);						
						break;
					case ID_AYUDA_ENVIARDUDASOSUGERENCIAS:
						api.EjecutarArchivo("mailto:humbertosc@cantv.net?subject=Dudas o sugerencias", "", SW_SHOW);						
						break;
					case ID_FORMATO_CAMBIARFUENTEDELTEXTO:
						diag.hWndPadre = hWnd;
						diag.hInstancia = win.hInstancia;
						diag.Fuente(); 
						if(lstrlen(fuentes.szfuente)>1){
							texto.Fuente(fuentes.tamano, fuentes.negrita, fuentes.cursiva, fuentes.subrayado, fuentes.szfuente);      	
						}
						break;
					case ID_ARCHIVO_IMPRIMIRDOCUMENTO:
						bImpresion = true;
						if(lstrlen(imp.szImpresora)>1){ 														
							imp.ImpresionPorLineas(texto.Mensaje(EM_GETLINECOUNT, 0, 0), texto, imp.bHojaCarta, fuentes, statusb.Texto(), 25);   
						}else{
							if(WndImp.win.hWnd==NULL){  
								WndImp.hWndPadre = hWnd;
								WndImp.hInstancia = win.hInstancia;
								WndImp.lpszAyuda = "confimp.htm";
								WndImp.lpszRegDir = "MundoC++//Apuntes 1.0.0//";
								WndImp.lpszTitulo = "Configurar impresión";
								WndImp.nPosX = 100;
								WndImp.nPosY = 100;
								WndImp.Crear(); 
							}
						}
						break;
					case ID_AYUDA_CONTENIDO:
						MessageBox(NULL, "La ayuda aun no ha sido desarrollada", "", MB_OK|MB_ICONINFORMATION);
						break;
				}
				break;
			case WM_SIZE:
				texto.Dimensionar(LOWORD(lParam) - 1, HIWORD(lParam) - 20);
				statusb.Dimensionar(20, HIWORD(lParam)); 
				break;
            case WM_DESTROY:
                PostQuitMessage(0);
                break;
			case WM_CLOSE:
				ChequearSalida();
				break;
            default:
                // permite responder a cualquier mensaje no especificado
                return DefWindowProc(hWnd, uMsg,  wParam, lParam);                    
       }
       return 0;
}

int WINAPI WinMain(HINSTANCE hInstancia, HINSTANCE hInstPrev, LPSTR lpszArgs, int nModo){
	win.hInstancia = hInstancia;
	win.dwEstilo = CW_NORMAL;
	win.hCursor = LoadCursor(NULL, IDC_ARROW);
	win.hIcono = LoadIcon(hInstancia, "ICONO");
	win.lpszTitulo = "Apuntes -- 2003 MundoC++ >> http://www.iespana.es/elmundoc/";
	win.nModoWin = nModo;
	win.WndProc = WndProc;
	win.Posicion.left = 100;
	win.Posicion.top = 50;
	win.Posicion.bottom = 460;
	win.Posicion.right = 600;
	win.lpszMenu = "MENU";
	win.hAccel = LoadAccelerators(hInstancia, "ACELERADORES");
	win.Crear(); 
	return win.msg.wParam;
}

LRESULT CALLBACK WndProcBuscar(HWND hWnd, UINT uMensaje, WPARAM wParam, LPARAM lParam){
	switch(uMensaje){
		case WM_CREATE:
			// --> FRAME
			framebuscar.hWndPadre = hWnd;
			framebuscar.hInstancia = win.hInstancia;
			framebuscar.Posicion.left = 5;
			framebuscar.Posicion.top = 2;
			framebuscar.Posicion.right = 385;
			framebuscar.Posicion.bottom = 100;
			framebuscar.Crear(); 
			// --> LABELbuscar
			labelbuscar.hWndPadre = hWnd;
			labelbuscar.hInstancia = win.hInstancia;
			labelbuscar.dwEstilo = CL_NORMAL;
			labelbuscar.lpszTexto = "Texto a buscar";
			labelbuscar.Posicion.left = 10;
			labelbuscar.Posicion.top = 15;
			labelbuscar.Posicion.right = 200;
			labelbuscar.Posicion.bottom = 18;
			labelbuscar.Crear();
			labelbuscar.Fuente(14, false, false, false, "ARIAL"); 
			// --> EDITbuscar
			editbuscar.hWndPadre = hWnd;
			editbuscar.hInstancia = win.hInstancia;
			editbuscar.dwEstilo = CE_SCROLLTEXTO;
			editbuscar.Posicion.left = 10;
			editbuscar.Posicion.top = 30;
			editbuscar.Posicion.right = 370;
			editbuscar.Posicion.bottom = 18;
			editbuscar.WndProcAddressEdit = wndproceditbuscar;
			editbuscar.Crear();
			editbuscar.Fuente(14, false, false, false, "ARIAL"); 
			// --> LabelReemp
			labelreemp.hWndPadre = hWnd;
			labelreemp.hInstancia = win.hInstancia;
			labelreemp.dwEstilo = CL_NORMAL;
			labelreemp.lpszTexto = "Reemplazar coincidencia por...";
			labelreemp.Posicion.left = 10;
			labelreemp.Posicion.top = 55;
			labelreemp.Posicion.right = 200;
			labelreemp.Posicion.bottom = 18;
			labelreemp.Crear();
			labelreemp.Fuente(14, false, false, false, "ARIAL"); 
			// --> EDITreemp
			editreemp.hWndPadre = hWnd;
			editreemp.hInstancia = win.hInstancia;
			editreemp.dwEstilo = CE_SCROLLTEXTO;
			editreemp.Posicion.left = 10;
			editreemp.Posicion.top = 70;
			editreemp.Posicion.right = 370;
			editreemp.Posicion.bottom = 18;
			editreemp.WndProcAddressEdit = wndproceditreemp;
			editreemp.Crear();
			editreemp.Fuente(14, false, false, false, "ARIAL"); 
			// --> BOTON ACEPTAR
			botonaceptarbuscar.hWndPadre = hWnd;
			botonaceptarbuscar.hInstancia = win.hInstancia;
			botonaceptarbuscar.dwEstilo = CB_NORMAL;
			botonaceptarbuscar.Posicion.left = 225;
			botonaceptarbuscar.Posicion.top = 110;
			botonaceptarbuscar.Posicion.right = 80;
			botonaceptarbuscar.Posicion.bottom = 30;
			botonaceptarbuscar.lpszTexto = "Buscar...";
			botonaceptarbuscar.WndProcAddressButton = wndprocbotonaceptarbuscar;
			botonaceptarbuscar.Crear(); 
			botonaceptarbuscar.Fuente(14, false, false, false, "ARIAL"); 
			// --> BOTON CANCELAR
			botoncancelarbuscar.hWndPadre = hWnd;
			botoncancelarbuscar.hInstancia = win.hInstancia;
			botoncancelarbuscar.dwEstilo = CB_NORMAL;
			botoncancelarbuscar.Posicion.left = 310;
			botoncancelarbuscar.Posicion.top = 110;
			botoncancelarbuscar.Posicion.right = 80;
			botoncancelarbuscar.Posicion.bottom = 30;
			botoncancelarbuscar.lpszTexto = "Cancelar";
			botoncancelarbuscar.WndProcAddressButton = wndprocbotoncancelarbuscar;
			botoncancelarbuscar.Crear(); 
			botoncancelarbuscar.Fuente(14, false, false, false, "ARIAL"); 

			editbuscar.Foco(); 
			break;
		case WM_COMMAND:
			if(botoncancelarbuscar.hWnd == (HWND) lParam){
				buscar.Destruir();
				texto.Foco(); 
				break;	
			}
			if(botonaceptarbuscar.hWnd == (HWND) lParam){
				ZeroMemory(&chr, sizeof(chr));
				ZeroMemory(&ft, sizeof(ft));
				if(lstrlen(editreemp.Texto())==0){ 
					chr.cpMin = nPos + nFin;
					chr.cpMax = -1;
					ft.chrg = chr;
					ft.lpstrText = editbuscar.Texto();
					nPos = texto.Mensaje(EM_FINDTEXT, 1, (LPARAM) &ft);
					nFin = nPos + lstrlen(editbuscar.Texto());
					if(nPos!=-1){
						texto.Mensaje(EM_SETSEL, nPos, nFin); 
						texto.Mensaje(EM_SCROLLCARET, 0, 0);  
						texto.Foco();
					}else{
						MessageBox(NULL, "No se han encontrado coincidencias con el texto indicado por usted!", "Atención", MB_OK|MB_ICONINFORMATION);
						editbuscar.Foco(); 
					}
				}else{
					chr.cpMin = 0;
					chr.cpMax = -1;
					ft.chrg = chr;
					ft.lpstrText = editbuscar.Texto();
					nPos = texto.Mensaje(EM_FINDTEXT, 1, (LPARAM) &ft);
					nFin = nPos + lstrlen(editbuscar.Texto());
					if(nPos!=-1){
						texto.Mensaje(EM_SETSEL, nPos, nFin); 
						texto.Mensaje(EM_REPLACESEL, true, (LPARAM) editreemp.Texto());  
						texto.Mensaje(EM_SCROLLCARET, 0, 0);  
						texto.Foco(); 
					}else{
						MessageBox(NULL, "No se han encontrado coincidencias con el texto indicado por usted!", "Atención", MB_OK|MB_ICONINFORMATION);
						editbuscar.Foco(); 
					}						
				}					
				break;	
			}
			break;
		case WM_DESTROY:
		  	PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, uMensaje, wParam, lParam);
			break;
  }
   return 0;
}

LRESULT CALLBACK wndproctexto(HWND hWnd, UINT uMensaje, WPARAM wParam, LPARAM lParam){
	switch(uMensaje){
		case WM_RBUTTONDOWN:
			POINT pt;
			GetCursorPos(&pt);
			TrackPopupMenu(GetSubMenu(GetMenu(win.hWnd), 1), TPM_LEFTALIGN, pt.x, pt.y,0, win.hWnd, &texto.Posicion);	
			CallWindowProc(texto.WndProcAddress, hWnd, uMensaje, (WPARAM) wParam, (LPARAM) lParam); 	 
			break;
		case WM_DESTROY:
		  	PostQuitMessage(0);
			break;
		default:
			return CallWindowProc(texto.WndProcAddress, hWnd, uMensaje, (WPARAM) wParam, (LPARAM) lParam); 	 
			break;
  }
   return 0;
}


LRESULT CALLBACK wndproceditbuscar(HWND hWnd, UINT uMensaje, WPARAM wParam, LPARAM lParam){
	switch(uMensaje){
		case WM_KEYUP:
			if(wParam==VK_TAB){
				editreemp.Foco(); 
				break;
			}	
			break;
		case WM_DESTROY:
		  	PostQuitMessage(0);
			break;
		default:
			return CallWindowProc(editbuscar.WndProcAddress, hWnd, uMensaje, (WPARAM) wParam, (LPARAM) lParam); 	 
			break;
  }
   return 0;
}

LRESULT CALLBACK wndproceditreemp(HWND hWnd, UINT uMensaje, WPARAM wParam, LPARAM lParam){
	switch(uMensaje){
		case WM_KEYUP:
			if(wParam==VK_TAB){
				botonaceptarbuscar.Foco(); 
				break;
			}	
			break;
		case WM_DESTROY:
		  	PostQuitMessage(0);
			break;
		default:
			return CallWindowProc(editreemp.WndProcAddress, hWnd, uMensaje, (WPARAM) wParam, (LPARAM) lParam); 	 
			break;
  }
   return 0;
}



LRESULT CALLBACK wndprocbotonaceptarbuscar(HWND hWnd, UINT uMensaje, WPARAM wParam, LPARAM lParam){
		switch(uMensaje){
		case WM_KEYUP:
			if(wParam==VK_TAB||wParam==VK_RIGHT){
				botoncancelarbuscar.Foco(); 
				break;
			}	
			if(wParam==VK_LEFT){
				editbuscar.Foco(); 
				break;
			}
			if(wParam==VK_RETURN){
				SendMessage(GetParent(hWnd), WM_COMMAND, (WPARAM) 1, (LPARAM) hWnd);
				break;
			}	
			break;
		default:
			return CallWindowProc(botonaceptarbuscar.WndProcAddress , hWnd, uMensaje, (WPARAM) wParam, (LPARAM) lParam); 	 
			break;
		}
		return 0;
}

LRESULT CALLBACK wndprocbotoncancelarbuscar(HWND hWnd, UINT uMensaje, WPARAM wParam, LPARAM lParam){
		switch(uMensaje){
		case WM_KEYUP:
			if(wParam==VK_TAB||wParam==VK_RIGHT){
				editbuscar.Foco(); 
				break;
			}	
			if(wParam==VK_LEFT){
				botonaceptarbuscar.Foco(); 
				break;
			}
			if(wParam==VK_RETURN){
				SendMessage(GetParent(hWnd), WM_COMMAND, (WPARAM) 1, (LPARAM) hWnd);
				break;
			}	
			break;
		default:
			return CallWindowProc(botoncancelarbuscar.WndProcAddress , hWnd, uMensaje, (WPARAM) wParam, (LPARAM) lParam); 	 
			break;
		}
		return 0;
}

void ChequearSalida(void){
	if(texto.Mensaje(EM_GETMODIFY, 0, 0)){
		int respuesta;
		respuesta = MessageBox(NULL, "el texto del documento ha cambiado, ¿Desea usted almacenar los cambios en el documento?", "Atención", MB_YESNOCANCEL|MB_ICONQUESTION);
		if(respuesta==IDYES){
			diag.hWndPadre = win.hWnd;
			diag.hInstancia = win.hInstancia;
			if(lstrcmp(diag.szbuffer, "")==0){
				diag.Guardar("Archivos de texto(*.txt)\0*.txt\0", "Indique el nombre del archivo a almacenar"); 							
				if(lstrcmp(CharUpper(str.Derecha(diag.szbuffer, 4)), ".TXT")!=0 && lstrlen(diag.szbuffer)>1){
					lstrcat(diag.szbuffer, ".txt"); 
				}
				file.GuardarArchivo(diag.szbuffer, texto.Texto());   					
				}else{
					file.GuardarArchivo(diag.szbuffer, texto.Texto());   					
				}
				ExitProcess(0);
			}else if(respuesta==IDCANCEL){
				
			}else{
				ExitProcess(0);
			}
		}else{
			ExitProcess(0);
	}						
}

VOID CALLBACK TimerProcClip(HWND hwnd, UINT uMsg, UINT idEvent, DWORD dwTime){
	if(texto.Mensaje(EM_CANPASTE, CF_TEXT, 0)!=0){
		EnableMenuItem(GetMenu(win.hWnd), ID_EDICIN_PEGAR, MF_ENABLED);	
	}else{
		EnableMenuItem(GetMenu(win.hWnd), ID_EDICIN_PEGAR, MF_GRAYED);	
	}
	texto.Mensaje(EM_GETSELTEXT, 0, (LPARAM) sztest);
	if(lstrlen(sztest)>0){
		EnableMenuItem(GetMenu(win.hWnd), ID_EDICIN_CORTAR, MF_ENABLED);	
		EnableMenuItem(GetMenu(win.hWnd), ID_EDICIN_COPIAR, MF_ENABLED);	
		EnableMenuItem(GetMenu(win.hWnd), ID_EDICIN_BORRAR, MF_ENABLED);	
	}else{
		EnableMenuItem(GetMenu(win.hWnd), ID_EDICIN_CORTAR, MF_GRAYED);	
		EnableMenuItem(GetMenu(win.hWnd), ID_EDICIN_COPIAR, MF_GRAYED);	
		EnableMenuItem(GetMenu(win.hWnd), ID_EDICIN_BORRAR, MF_GRAYED);	
	}
	if(lstrlen(texto.Texto())>0){ 
		EnableMenuItem(GetMenu(win.hWnd), ID_EDICIN_DESHACER, MF_ENABLED);	
		EnableMenuItem(GetMenu(win.hWnd), ID_EDICIN_BUSCARYREEMPLAZAR, MF_ENABLED);	
	}else{
		EnableMenuItem(GetMenu(win.hWnd), ID_EDICIN_DESHACER, MF_GRAYED);	
		EnableMenuItem(GetMenu(win.hWnd), ID_EDICIN_BUSCARYREEMPLAZAR, MF_GRAYED);	
	}
}
