// -----------------------------------------------------------------
// Cado.h --> Clase para usar ActiveX Data Object (17/07/2003)
// -----------------------------------------------------------------

#pragma warning (disable: 4146)
#import "librerias//msado15.dll" rename_namespace("ADODB") rename("EOF", "AdoEof")
using namespace ADODB; // el namespace es ADODB
#pragma warning (default: 4146)

//PROTOTIPOS PARA CADENAS DE CONEXION
// ACCESS ->*.MDB
// L"DRIVER=MICROSOFT ACCESS DRIVER (*.MDB);DBQ=data.mdb"

// SQL SERVER POR OLEDB
//Provider=SQLOLEDB.1;Integrated Security=SSPI;Persist Security Info=False;User ID=HSUAREZ\Administrador;Initial Catalog=empleados;Data Source=HSUAREZ

class Cado{
public:
	// --> Propiedades
	_ConnectionPtr     Conexion;                // --> Puntero a la conexion activa de la base de datos 
	_RecordsetPtr      rs;                      // --> Puntero al recordset activo
	_bstr_t            CadenaConexion;          // --> Cadena de conexión (usar L antes de los literales "") 
	_bstr_t            NombreUsuario;           // --> Nombre de usuario de la conexion  (usar L antes de los literales "") 
	_bstr_t            Password;                // --> Password de la conexión  (usar L antes de los literales "") 
	char               ComandoSQL[260];         // --> Buffer puede usarse para almacenar el comando sql
	// --> Métodos
	Cado::Cado(void);                                     // --> Constructor de la clase
	Cado::~Cado(void);                                    // --> Destructor
	BOOL Cado::Conectar(void);                            // --> Conecta a la base de datos indicada en la cadena de conexión
	void Cado::EjecutarComandoSQL(_bstr_t ComandoSQL);    // --> Ejecuta un comando SQL
	_bstr_t Cado::ValorCampo(_bstr_t NombreCampo);        // --> Devuelve el valor de un campo especifico
	int Cado::NumeroRegistros(void);                      // --> Devuelve el numero de registros en el recordset activo  	
	void Cado::MoverSiguiente(void);                      // --> Mueve el recordset al siguiente registro	
	void Cado::MoverUltimo(void);                         // --> Mueve el recordset al ultimo registro
	void Cado::MoverPrimero(void);                	      // --> Mueve el recordset al primer registro
	void Cado::Desconectar(void);                         // --> Cierra la conexión activa a la base de datos
	void Cado::CerrarRecordset(void);                     // --> Cierra el recordset activo
};

Cado::Cado(void){
	::CoInitialize(NULL);
	Conexion = NULL;
	rs = NULL;
}

Cado::~Cado(void){
	Conexion.Detach();  // para mantener la estabilidad en Win9x
	::CoUninitialize(); 
	Conexion = NULL;
	rs = NULL;
}

void Cado::Desconectar(void){
	try{
		if (Conexion->State==1) Conexion->Close();
	}catch(_com_error &e){
		MessageBox(NULL, e.ErrorMessage(),"ERROR", MB_OK|MB_ICONERROR);  
	}
}

void Cado::CerrarRecordset(void){
	try{
		if (rs->State==1) rs->Close();
	}catch(_com_error &e){
		MessageBox(NULL, e.ErrorMessage(),"ERROR", MB_OK|MB_ICONERROR);  
	}
}

void Cado::MoverPrimero(void){
	try{
		rs->MoveFirst();
	}catch(_com_error &e){
		MessageBox(NULL, e.ErrorMessage(),"ERROR", MB_OK|MB_ICONERROR);  
	}
}

void Cado::MoverUltimo(void){
	try{
		rs->MoveLast();
	}catch(_com_error &e){
		MessageBox(NULL, e.ErrorMessage(),"ERROR", MB_OK|MB_ICONERROR);  
	}
}

void Cado::MoverSiguiente(void){
	try{
		rs->MoveNext();
	}catch(_com_error &e){
		MessageBox(NULL, e.ErrorMessage(),"ERROR", MB_OK|MB_ICONERROR);  
	}
}

int Cado::NumeroRegistros(void) {
	try{
		return rs->RecordCount;
	}catch(_com_error &e){
		MessageBox(NULL, e.ErrorMessage(),"ERROR", MB_OK|MB_ICONERROR);  
		return -1;
	}
}

_bstr_t Cado::ValorCampo(_bstr_t NombreCampo){
	try{
		return (_bstr_t) rs->Fields->GetItem(NombreCampo)->Value;
	}catch(_com_error &e){
		MessageBox(NULL, e.ErrorMessage(),"ERROR", MB_OK|MB_ICONERROR);  
		return "";
	}
}

void Cado::EjecutarComandoSQL(_bstr_t ComandoSQL){
	try{
		rs = NULL;
		rs.CreateInstance(__uuidof(Recordset));
		rs->PutRefActiveConnection(Conexion);
		rs->Open(ComandoSQL, vtMissing, adOpenForwardOnly, adLockReadOnly, adCmdText);
	}catch(_com_error &e){
		MessageBox(NULL, e.ErrorMessage(),"ERROR", MB_OK|MB_ICONERROR);  
	}
}

BOOL Cado::Conectar(void){
	try{
		Conexion = NULL;
		Conexion.CreateInstance(__uuidof(Connection));
		Conexion->Open(CadenaConexion, NombreUsuario, Password, 0);
		return true;
	}catch(_com_error &e){
		MessageBox(NULL, e.ErrorMessage(),"ERROR DE LA BASE DE DATOS", MB_OK|MB_ICONERROR);  
		exit(0);
		return false;
	}
}

