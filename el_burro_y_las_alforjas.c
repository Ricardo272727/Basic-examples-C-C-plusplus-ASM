

/*=============================================
El burro es un animal actualmente en peligro de extinción, debido principalmente a que ya no es necesario para el trabajo en el campo. 
No ocurría así antiguamente, cuando este animal, noble, fuerte, pero sobre todo testarudo, ayudaba a los hombres en el transporte de sus 
cosechas y enseres. Utilizado mucho en el antiguo Egipto, era normal ver caravanas de pollinos avanzar con sus dos alforjas por los caminos.

Yafeu, el joven administrador de las propiedades de Amenophis a orillas del Nilo, debe cargar la cosecha de trigo en su caravana de 
asnos para trasladarla a la capital. Los campesinos han recogido la cosecha en sacos, cuyos pesos no son necesariamente iguales. 
Cada burro lleva un par de alforjas, colgadas una a cada lado del lomo. En cada alforja se lleva un saco, que puede ser de cualquier peso 
aunque es importante que las dos alforjas lleven el mismo peso para que el burrito vaya equilibrado y no se caiga.

Yafeu tiene mucho trabajo, y le aburre dedicar todo un día a emparejar los sacos.
 Este año le han recomendado un estudiante asegurándole que le ahorrará mucho tiempo. 
Está dispuesto a darle una buena recompensa si eso es cierto.
Entrada

La entrada comienza con un entero que indica el número de casos de prueba que vendrán a continuación. Cada caso consta de dos líneas. 
La primera contiene el número de burros disponibles y el número de sacos que hay que cargar (ambos entre 1 y 1.000.000). 
En la línea siguiente aparecen los pesos en gramos de cada saco separados por espacios. Cada uno pesa como mucho 20 Kg (valores entre 1 y 20.000).
Salida

Para cada caso de prueba se indicará el máximo número de burros que se pueden cargar.

==============================================*/
//1pedir numerode casos,burros y sacos
//2almacenar en un arrego los pesos de los sacos y determinar numero de posibles parejas de sacos para hacer funcion buscar_sacos_iguales
//3buscar en el arreglo dos sacos de igual peso
//4asignarle a un burro los sacos y llevar la cuenta de cuantos burros ya despachaste
//5volver a 3 hasta que no haya burros 
//6escribir salida
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int p_sacos[1000000];
	int i,casos,j;
	long int burros,sacos;
	printf("Escribe el numero de casos:\n");scanf("%d",&casos);

	for (i = 1; i <= casos; i++)
	{	printf("\n========caso %d============\n",i);
		printf("escribe el numero de burros disponibles y de sacos a cargar: 'burros' 'sacos': \n");
		scanf("%ld %ld",&burros,&sacos);
		for (j = 0; j < sacos;j++)
		{
			printf("\npeso del saco (gramos) %d:",j+1);
			scanf("%d",&p_sacos[j]);
		}		
	}
	
	
	

	return 0;
}
