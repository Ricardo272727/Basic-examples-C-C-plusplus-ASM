// -----------------------------------------------------------------
// Cstring.h --> Clase de funciones de cadenas diversas (30/07/2003)
// -----------------------------------------------------------------

class Cstring{
private:
	// --> Propiedades
	char szBuffer[255];          // --> para la función izquierda.
	char *Copia;                 // --> puntero a usar en la función derecha.
	char *Copia2;                // --> puntero a usar en la función AcomodarCifra
	int nLon;                    // --> Longitud de la cadena en la función derecha.
	int Bucle;                   // --> para iteraciones.
	// --> Para la rutina de formato de cifra
	int coma;
	int signo;
	char szantescoma[255];
	char szdespuescoma[255];
	char szdespuescoma2[255];
	char szdespuescoma3[255];
	char szcentimos[255];
	char szfinal[255];
public:
	// --> Métodos
	Cstring::Cstring(void);     
	Cstring::~Cstring(void);
	char *Cstring::Derecha(char *Buffer, int nLongitud);                              // --> Devuelve los n caracteres a la derecha de la cadena. 
	char *Cstring::FormatoCifra(char *Buffer);                                        // --> Formatea una cadena en forma de cifra
	char *Cstring::FormatoSimple(char *Buffer);                                       // --> Formatea una cadena en formato simple sin division de cifras ni coma decimal
	char *Cstring::AcomodarCifra(double cifra, int nLon);                             // --> Acomoda una cifra creada con gcvt
};

Cstring::~Cstring(void){
	Copia = NULL;
}

Cstring::Cstring(void){
	Copia = NULL;
}

char *Cstring::FormatoSimple(char *Buffer){
	switch(lstrlen(Buffer)){
		case 4:
			lstrcpyn(szfinal, Buffer, 2);
			break;
		case 5:
			if(lstrcmp(Derecha(Buffer, 2), "00")==0){
				lstrcpyn(szfinal, Buffer, 3);
			}else{
				lstrcpyn(szfinal, Buffer, 3);
				lstrcat(szfinal, Derecha(Buffer, 2));
			}
			break;
		case 6:
			if(lstrcmp(Derecha(Buffer, 2), "00")==0){
				lstrcpyn(szfinal, Buffer, 4);
			}else{
				lstrcpyn(szfinal, Buffer, 4);
				lstrcat(szfinal, Derecha(Buffer, 2));
			}
			break;
		case 8:
			lstrcpyn(szantescoma, Buffer, 2);
			lstrcpy(szdespuescoma, Derecha(Buffer, 6));
			lstrcpyn(szdespuescoma, szdespuescoma, 4);
			lstrcpy(szcentimos, Derecha(Buffer, 2));
			lstrcpy(szfinal, szantescoma);
			lstrcat(szfinal, szdespuescoma);
			lstrcat(szfinal, szcentimos);
			break;
		case 9:
			lstrcpyn(szantescoma, Buffer, 3);
			lstrcpy(szdespuescoma, Derecha(Buffer, 6));
			lstrcpyn(szdespuescoma, szdespuescoma, 4);
			lstrcpy(szcentimos, Derecha(Buffer, 2));
			lstrcpy(szfinal, szantescoma);
			lstrcat(szfinal, szdespuescoma);
			lstrcat(szfinal, szcentimos);
			break;
		case 10:
			lstrcpyn(szantescoma, Buffer, 4);
			lstrcpy(szdespuescoma, Derecha(Buffer, 6));
			lstrcpyn(szdespuescoma, szdespuescoma, 4);
			lstrcpy(szcentimos, Derecha(Buffer, 2));
			lstrcpy(szfinal, szantescoma);
			lstrcat(szfinal, szdespuescoma);
			lstrcat(szfinal, szcentimos);
			break;
		case 12:
			lstrcpyn(szantescoma, Buffer, 2);
			lstrcpy(szdespuescoma, Derecha(Buffer, 10));
			lstrcpyn(szdespuescoma, szdespuescoma, 4);
			lstrcpy(szdespuescoma2, Derecha(Buffer, 6));
			lstrcpyn(szdespuescoma2, szdespuescoma2, 4);
			lstrcpy(szcentimos, Derecha(Buffer, 2));
			lstrcpy(szfinal, szantescoma);
			lstrcat(szfinal, szdespuescoma);
			lstrcat(szfinal, szdespuescoma2);
			lstrcat(szfinal, szcentimos);
			break;
		case 13:
			lstrcpyn(szantescoma, Buffer, 3);
			lstrcpy(szdespuescoma, Derecha(Buffer, 10));
			lstrcpyn(szdespuescoma, szdespuescoma, 4);
			lstrcpy(szdespuescoma2, Derecha(Buffer, 6));
			lstrcpyn(szdespuescoma2, szdespuescoma2, 4);
			lstrcpy(szcentimos, Derecha(Buffer, 2));
			lstrcpy(szfinal, szantescoma);
			lstrcat(szfinal, szdespuescoma);
			lstrcat(szfinal, szdespuescoma2);
			lstrcat(szfinal, szcentimos);
			break;
		case 14:
			lstrcpyn(szantescoma, Buffer, 4);
			lstrcpy(szdespuescoma, Derecha(Buffer, 10));
			lstrcpyn(szdespuescoma, szdespuescoma, 4);
			lstrcpy(szdespuescoma2, Derecha(Buffer, 6));
			lstrcpyn(szdespuescoma2, szdespuescoma2, 4);
			lstrcpy(szcentimos, Derecha(Buffer, 2));
			lstrcpy(szfinal, szantescoma);
			lstrcat(szfinal, szdespuescoma);
			lstrcat(szfinal, szdespuescoma2);
			lstrcat(szfinal, szcentimos);
			break;
		case 16:
			lstrcpyn(szantescoma, Buffer, 2);
			lstrcpy(szdespuescoma, Derecha(Buffer, 14));
			lstrcpyn(szdespuescoma, szdespuescoma, 4);
			lstrcpy(szdespuescoma2, Derecha(Buffer, 10));
			lstrcpyn(szdespuescoma2, szdespuescoma2, 4);
			lstrcpy(szdespuescoma3, Derecha(Buffer, 6));
			lstrcpyn(szdespuescoma3, szdespuescoma3, 4);
			lstrcpy(szcentimos, Derecha(Buffer, 2));
			lstrcpy(szfinal, szantescoma);
			lstrcat(szfinal, szdespuescoma);
			lstrcat(szfinal, szdespuescoma2);
			lstrcat(szfinal, szdespuescoma3);
			lstrcat(szfinal, szcentimos);
			break;
		case 17:
			lstrcpyn(szantescoma, Buffer, 3);
			lstrcpy(szdespuescoma, Derecha(Buffer, 14));
			lstrcpyn(szdespuescoma, szdespuescoma, 4);
			lstrcpy(szdespuescoma2, Derecha(Buffer, 10));
			lstrcpyn(szdespuescoma2, szdespuescoma2, 4);
			lstrcpy(szdespuescoma3, Derecha(Buffer, 6));
			lstrcpyn(szdespuescoma3, szdespuescoma3, 4);
			lstrcpy(szcentimos, Derecha(Buffer, 2));
			lstrcpy(szfinal, szantescoma);
			lstrcat(szfinal, szdespuescoma);
			lstrcat(szfinal, szdespuescoma2);
			lstrcat(szfinal, szdespuescoma3);
			lstrcat(szfinal, szcentimos);
			break;
		case 18:
			lstrcpyn(szantescoma, Buffer, 4);
			lstrcpy(szdespuescoma, Derecha(Buffer, 14));
			lstrcpyn(szdespuescoma, szdespuescoma, 4);
			lstrcpy(szdespuescoma2, Derecha(Buffer, 10));
			lstrcpyn(szdespuescoma2, szdespuescoma2, 4);
			lstrcpy(szdespuescoma3, Derecha(Buffer, 6));
			lstrcpyn(szdespuescoma3, szdespuescoma3, 4);
			lstrcpy(szcentimos, Derecha(Buffer, 2));
			lstrcpy(szfinal, szantescoma);
			lstrcat(szfinal, szdespuescoma);
			lstrcat(szfinal, szdespuescoma2);
			lstrcat(szfinal, szdespuescoma3);
			lstrcat(szfinal, szcentimos);
			break;
	}
	return szfinal;
}

char *Cstring::FormatoCifra(char *Buffer){
	switch(lstrlen(Buffer)){
		case 1:
			lstrcpy(szfinal, Buffer);
			lstrcat(szfinal, ",00");
			break;
		case 2:
			lstrcpy(szfinal, Buffer);
			lstrcat(szfinal, ",00");
			break;
		case 3:
			lstrcpy(szfinal, Buffer);
			lstrcat(szfinal, ",00");
			break;
		case 4:
			lstrcpyn(szantescoma, Buffer, 3);
			lstrcpy(szdespuescoma, Derecha(Buffer, 2));
			lstrcpy(szfinal, szantescoma);
			lstrcat(szfinal, ",");
			lstrcat(szfinal, szdespuescoma);
			break;
		case 5:
			lstrcpyn(szantescoma, Buffer, 4);
			lstrcpy(szdespuescoma, Derecha(Buffer, 2));
			lstrcpy(szfinal, szantescoma);
			lstrcat(szfinal, ",");
			lstrcat(szfinal, szdespuescoma);
			break;
		case 6:
			lstrcpyn(szantescoma, Buffer, 2);
			lstrcpy(szcentimos, Derecha(Buffer, 2));
			lstrcpy(szdespuescoma, Derecha(Buffer, 5));
			lstrcpyn(szdespuescoma, szdespuescoma, 4);
			lstrcpy(szfinal, szantescoma);
			lstrcat(szfinal, ".");
			lstrcat(szfinal, szdespuescoma);
			lstrcat(szfinal, ",");
			lstrcat(szfinal, szcentimos);
			break;
		case 7:
			lstrcpyn(szantescoma, Buffer, 3);
			lstrcpy(szcentimos, Derecha(Buffer, 2));
			lstrcpy(szdespuescoma, Derecha(Buffer, 5));
			lstrcpyn(szdespuescoma, szdespuescoma, 4);
			lstrcpy(szfinal, szantescoma);
			lstrcat(szfinal, ".");
			lstrcat(szfinal, szdespuescoma);
			lstrcat(szfinal, ",");
			lstrcat(szfinal, szcentimos);
			break;
		case 8:
			lstrcpyn(szantescoma, Buffer, 4);
			lstrcpy(szcentimos, Derecha(Buffer, 2));
			lstrcpy(szdespuescoma, Derecha(Buffer, 5));
			lstrcpyn(szdespuescoma, szdespuescoma, 4);
			lstrcpy(szfinal, szantescoma);
			lstrcat(szfinal, ".");
			lstrcat(szfinal, szdespuescoma);
			lstrcat(szfinal, ",");
			lstrcat(szfinal, szcentimos);
			break;
		case 9:
			lstrcpyn(szantescoma, Buffer, 2);
			lstrcpy(szcentimos, Derecha(Buffer, 2));
			lstrcpy(szdespuescoma, Derecha(Buffer, 8));			
			lstrcpyn(szdespuescoma, szdespuescoma, 4);
			lstrcpy(szdespuescoma2, Derecha(Buffer, 5));
			lstrcpyn(szdespuescoma2, szdespuescoma2, 4); 
			lstrcpy(szfinal, szantescoma);
			lstrcat(szfinal, ".");
			lstrcat(szfinal, szdespuescoma);
			lstrcat(szfinal, ".");
			lstrcat(szfinal, szdespuescoma2);
			lstrcat(szfinal, ",");
			lstrcat(szfinal, szcentimos);
			break;
		case 10:
			lstrcpyn(szantescoma, Buffer, 3);
			lstrcpy(szcentimos, Derecha(Buffer, 2));
			lstrcpy(szdespuescoma, Derecha(Buffer, 8));			
			lstrcpyn(szdespuescoma, szdespuescoma, 4);
			lstrcpy(szdespuescoma2, Derecha(Buffer, 5));
			lstrcpyn(szdespuescoma2, szdespuescoma2, 4); 
			lstrcpy(szfinal, szantescoma);
			lstrcat(szfinal, ".");
			lstrcat(szfinal, szdespuescoma);
			lstrcat(szfinal, ".");
			lstrcat(szfinal, szdespuescoma2);
			lstrcat(szfinal, ",");
			lstrcat(szfinal, szcentimos);
			break;
		case 11:
			lstrcpyn(szantescoma, Buffer, 4);
			lstrcpy(szcentimos, Derecha(Buffer, 2));
			lstrcpy(szdespuescoma, Derecha(Buffer, 8));			
			lstrcpyn(szdespuescoma, szdespuescoma, 4);
			lstrcpy(szdespuescoma2, Derecha(Buffer, 5));
			lstrcpyn(szdespuescoma2, szdespuescoma2, 4); 
			lstrcpy(szfinal, szantescoma);
			lstrcat(szfinal, ".");
			lstrcat(szfinal, szdespuescoma);
			lstrcat(szfinal, ".");
			lstrcat(szfinal, szdespuescoma2);
			lstrcat(szfinal, ",");
			lstrcat(szfinal, szcentimos);
			break;
		case 12:
			lstrcpyn(szantescoma, Buffer, 2);
			lstrcpy(szcentimos, Derecha(Buffer, 2));
			lstrcpy(szdespuescoma, Derecha(Buffer, 11));			
			lstrcpyn(szdespuescoma, szdespuescoma, 4);
			lstrcpy(szdespuescoma2, Derecha(Buffer, 8));
			lstrcpyn(szdespuescoma2, szdespuescoma2, 4); 
			lstrcpy(szdespuescoma3, Derecha(Buffer, 5));
			lstrcpyn(szdespuescoma3, szdespuescoma3, 4); 
			lstrcpy(szfinal, szantescoma);
			lstrcat(szfinal, ".");
			lstrcat(szfinal, szdespuescoma);
			lstrcat(szfinal, ".");
			lstrcat(szfinal, szdespuescoma2);
			lstrcat(szfinal, ".");
			lstrcat(szfinal, szdespuescoma3);
			lstrcat(szfinal, ",");
			lstrcat(szfinal, szcentimos);
			break;
		case 13:
			lstrcpyn(szantescoma, Buffer, 3);
			lstrcpy(szcentimos, Derecha(Buffer, 2));
			lstrcpy(szdespuescoma, Derecha(Buffer, 11));			
			lstrcpyn(szdespuescoma, szdespuescoma, 4);
			lstrcpy(szdespuescoma2, Derecha(Buffer, 8));
			lstrcpyn(szdespuescoma2, szdespuescoma2, 4); 
			lstrcpy(szdespuescoma3, Derecha(Buffer, 5));
			lstrcpyn(szdespuescoma3, szdespuescoma3, 4); 
			lstrcpy(szfinal, szantescoma);
			lstrcat(szfinal, ".");
			lstrcat(szfinal, szdespuescoma);
			lstrcat(szfinal, ".");
			lstrcat(szfinal, szdespuescoma2);
			lstrcat(szfinal, ".");
			lstrcat(szfinal, szdespuescoma3);
			lstrcat(szfinal, ",");
			lstrcat(szfinal, szcentimos);
			break;
		case 14:
			lstrcpyn(szantescoma, Buffer, 4);
			lstrcpy(szcentimos, Derecha(Buffer, 2));
			lstrcpy(szdespuescoma, Derecha(Buffer, 11));			
			lstrcpyn(szdespuescoma, szdespuescoma, 4);
			lstrcpy(szdespuescoma2, Derecha(Buffer, 8));
			lstrcpyn(szdespuescoma2, szdespuescoma2, 4); 
			lstrcpy(szdespuescoma3, Derecha(Buffer, 5));
			lstrcpyn(szdespuescoma3, szdespuescoma3, 4); 
			lstrcpy(szfinal, szantescoma);
			lstrcat(szfinal, ".");
			lstrcat(szfinal, szdespuescoma);
			lstrcat(szfinal, ".");
			lstrcat(szfinal, szdespuescoma2);
			lstrcat(szfinal, ".");
			lstrcat(szfinal, szdespuescoma3);
			lstrcat(szfinal, ",");
			lstrcat(szfinal, szcentimos);
			break;
	}
	return szfinal;
}

char *Cstring::Derecha(char *Buffer, int nLongitud){
	nLon = lstrlen (Buffer);
	Copia = new char [nLongitud + 1];
	if (nLongitud < 0){
		Copia[0] = 0;
		return &Copia[0];
	}
	if (nLongitud >= nLon){
		for (Bucle = 0;Bucle < nLon;Bucle++){
			Copia[Bucle]=Buffer[Bucle];
		}
		Copia[Bucle] = 0;
		return &Copia[0];
	}
	for (Bucle = 0;Bucle < nLongitud;Bucle++){
		Copia[Bucle] = Buffer[Bucle + (nLon - nLongitud)];
	}
	Copia[Bucle] = 0;
	return &Copia[0];
	delete [] Copia;
}

char *Cstring::AcomodarCifra(double cifra, int nLon){
	int coma=0;
	int signo=0;
	Copia2 = new char [nLon + 1];
	ecvt(cifra, nLon, &coma, &signo);
	gcvt(cifra, nLon, Copia2);
	lstrcpyn(Copia2, Copia2, coma+1);
	return Copia2;
	delete [] Copia2;
}