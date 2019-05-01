// ----------------------------------------------------------------
//       Clases extendidas (Classex) version 1.0 revision 2
// ----------------------------------------------------------------
// Constantes.h --> Constantes globales (16/07/2003)
// ----------------------------------------------------------------

// --> Constantes de estilo de la clase Cwindow
const CW_NORMAL          = WS_OVERLAPPEDWINDOW|WS_VISIBLE;
const CW_SPLASH          = WS_POPUP|WS_VISIBLE;
const CW_DIALOGO         = WS_DLGFRAME|WS_VISIBLE;
const CW_TITULO          = WS_CAPTION|WS_VISIBLE;
const CW_SINMAXIMIZAR    = WS_CAPTION|WS_SYSMENU|WS_MINIMIZEBOX|WS_VISIBLE;
const CW_HIJA            = WS_CHILD|WS_VISIBLE;
const CW_DIALOGOCERRAR   = WS_DLGFRAME|WS_VISIBLE|WS_SYSMENU;

// --> Constantes de operaciones de Capi->OperacionesArchivo
const OP_COPIAR    = 1;
const OP_BORRAR    = 2;
const OP_MOVER     = 3;
const OP_RENOMBRAR = 4;
 
// --> Constantes de estilo de la clase Cbutton
const CB_NORMAL          = WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON|WS_TABSTOP;
const CB_PLANO           = CB_NORMAL|BS_FLAT;
const CB_IZQUIERDA       = CB_NORMAL|BS_LEFT;
const CB_DERECHA         = CB_NORMAL|BS_RIGHT;
const CB_CENTRADO        = CB_NORMAL|BS_CENTER;

// --> Constantes de estilo de la clase Cimagen
const CI_BITMAP          = WS_CHILD|WS_VISIBLE|SS_BITMAP|SS_CENTERIMAGE|SS_NOTIFY;
const CI_ICONO           = WS_CHILD|WS_VISIBLE|SS_ICON|SS_CENTERIMAGE|SS_NOTIFY;
const CI_BITMAPNOESTIRAR = WS_CHILD|WS_VISIBLE|SS_BITMAP|SS_NOTIFY|SS_REALSIZEIMAGE;
const CI_BITMAPBORDE     = CI_BITMAP|WS_BORDER;
const CI_ICONOBORDE      = CI_ICONO|WS_BORDER;

// --> Constantes de colores de uso multiple
const COLOR_AZUL         = RGB(0,128,192);
const COLOR_GRIS         = RGB(128,128,128);
const COLOR_ROJO         = RGB(177,20,64);
const COLOR_AMARILLO     = RGB(241,230,14);
const COLOR_VERDE        = RGB(89,172,172);
const COLOR_NEGRO        = RGB(0,0,0);
const COLOR_BLANCO       = RGB(255, 255, 255);

// --> Constantes de estilo de la clase Clabel
const CL_NORMAL          = WS_CHILD|WS_VISIBLE|SS_LEFT;
const CL_DERECHA         = CL_NORMAL|SS_RIGHT;
const CL_CENTRADO        = CL_NORMAL|SS_CENTER;
const CL_BORDES          = CL_NORMAL|WS_BORDER;

// --> Constantes de estilo de la clase Clistview
const LV_NORMAL    = WS_CHILD|WS_VISIBLE|WS_BORDER|LVS_SHOWSELALWAYS|LVS_SINGLESEL;
const LV_ICONO     = LV_NORMAL|LVS_ICON;
const LV_ICONOSM   = LV_NORMAL|LVS_SMALLICON;
const LV_LISTA     = LV_NORMAL|LVS_LIST;
const LV_REPORTE   = LV_NORMAL|LVS_REPORT;

// --> Constantes de estilo de la clase Cprogressbar
const CP_NORMAL = WS_CHILD|WS_VISIBLE;
const CP_SMOOTH = WS_CHILD|WS_VISIBLE|PBS_SMOOTH;

// --> Constantes de la clase Cregistro
const HKEY CR_USUARIOACTUAL      = HKEY_CURRENT_USER;
const HKEY CR_CLASES             = HKEY_CLASSES_ROOT;
const HKEY CR_CONFIGURACIONES    = HKEY_CURRENT_CONFIG;
const HKEY CR_MAQUINALOCAL       = HKEY_LOCAL_MACHINE;
const HKEY CR_USUARIOS           = HKEY_USERS;

// --> Constantes de la clase Cstatusbar
const CS_ARRIBA = CCS_TOP|SBARS_SIZEGRIP|WS_CHILD|WS_VISIBLE;
const CS_ABAJO  = SBARS_SIZEGRIP|WS_CHILD|WS_VISIBLE;

// --> Constantes de la clase Ctab
const CTAB_NORMAL    = WS_CHILD|WS_VISIBLE|TCS_TABS;
const CTAB_BOTONES   = CTAB_NORMAL|TCS_BUTTONS;
const CTAB_TOOLTIPS  = CTAB_NORMAL|TCS_TOOLTIPS;
const CTAB_ABAJO     = CTAB_NORMAL|TCS_BOTTOM;
const CTAB_FLAT      = CTAB_BOTONES|TCS_FLATBUTTONS;
const CTAB_HOTTRACK  = CTAB_NORMAL|TCS_HOTTRACK;

// --> Constates de la clase Cedit
const CE_NORMAL         = WS_VISIBLE|WS_CHILD|ES_LEFT|WS_TABSTOP;
const CE_DERECHA        = WS_VISIBLE|WS_CHILD|ES_RIGHT|WS_TABSTOP;
const CE_PASSWORD       = WS_VISIBLE|WS_CHILD|ES_PASSWORD|WS_TABSTOP;
const CE_MULTILINEA     = CE_NORMAL|ES_MULTILINE|WS_VSCROLL;
const CE_SOLOLECTURA    = CE_NORMAL|ES_READONLY;
const CE_SCROLLTEXTO    = CE_NORMAL|ES_AUTOHSCROLL;

// --> Constantes de la clase Ctoolbar
const CTOOLBAR_NORMAL = WS_CHILD|WS_VISIBLE|TBSTYLE_TOOLTIPS|CCS_ADJUSTABLE;
const CTOOLBAR_FLAT   = WS_CHILD|WS_VISIBLE|TBSTYLE_TOOLTIPS|CCS_ADJUSTABLE|TBSTYLE_FLAT|TBSTYLE_TRANSPARENT;

// --> Constantes de la clase Ctreeview
const CTREEVIEW_NORMAL          = WS_CHILD|WS_VISIBLE;
const CTREEVIEW_LABELEDIT       = CTREEVIEW_NORMAL|TVS_EDITLABELS;
const CTREEVIEW_PLUS            = CTREEVIEW_NORMAL|TVS_HASBUTTONS;
const CTREEVIEW_LINEAS          = CTREEVIEW_NORMAL|TVS_HASLINES;
const CTREEVIEW_LINEASINICIO    = CTREEVIEW_NORMAL|TVS_LINESATROOT;
const CTREEVIEW_FOCOSELECCION   = CTREEVIEW_NORMAL|TVS_SHOWSELALWAYS;

// --> Constantes de formato del datetimepicker
const LPSTR CDATETIMEPICKER_FECHA = "DD/MM/YYYY";
const LPSTR CDATETIMEPICKER_HORAS = "HH/MM/SS";