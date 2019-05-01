// -----------------------------------------------------------------
// Cregistro.h --> Clase para usar el registro (19/07/2003)
// -----------------------------------------------------------------

class Cregistro{
protected:
	char data[255];
	char datatmp[5];
public:
	// --> Propiedades
	LPSTR  Entrada;      // --> Nombre de la entrada a usar
	HKEY   Clave;        // --> Clave a usar
	// --> Métodos	
	void Cregistro::CrearClave(void);                                  // --> Crea una clave en el registro
	void Cregistro::GuardarValor(LPSTR lpszOpcion, LPSTR lpszData);    // --> Guarda un valor en una clave del registro
	LPSTR Cregistro::ObtenerValor(LPSTR lpszOpcion);                   // --> Obtiene el valor de una clave del registro
};


LPSTR Cregistro::ObtenerValor(LPSTR lpszOpcion){
	HKEY pKey=NULL;
	DWORD dwTipo;
	DWORD dwSize;
	dwSize = sizeof(data);
	RegOpenKeyEx(Clave, Entrada, NULL, KEY_ALL_ACCESS, &pKey);
	RegQueryValueEx(pKey, lpszOpcion, NULL, &dwTipo, (LPBYTE) data, &dwSize);
	return data;
}

void Cregistro::GuardarValor(LPSTR lpszOpcion, LPSTR lpszData){
	HKEY pKey=NULL;
	RegOpenKeyEx(Clave, Entrada, NULL, KEY_ALL_ACCESS, &pKey);
	char *datatemp = new char [lstrlen(lpszData)+1];
	lstrcpy(datatemp, lpszData);
	RegSetValueEx(pKey, lpszOpcion, 0, REG_SZ, (LPBYTE) datatemp, lstrlen(lpszData)+1); 
	RegCloseKey(pKey);
}

void Cregistro::CrearClave(void){
	HKEY pKey=NULL;
	SECURITY_ATTRIBUTES sa;
	DWORD dwDisposicion;
	ZeroMemory(&sa, sizeof(SECURITY_ATTRIBUTES));
	RegCreateKeyEx(Clave, Entrada, 0, "", 0, 
    KEY_READ | KEY_WRITE, &sa, &pKey, &dwDisposicion); 
}