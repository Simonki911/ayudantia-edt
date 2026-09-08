#include <stdio.h>   /* <-- Para usar printf     */
#include <stdlib.h>  /* <-- Para usar srand      */
#include <time.h>    /* <-- Para usar time(NULL) */

int main(int argc, char *argv[])
{
	int n = -1;
    srand(time(NULL));
    int i;
    float nota, suma = 0;

	if (argc == 2)
	{
		n = atoi(argv[1]);

	}

    if (n <= 0)
    {
        printf("Se ha ingresado un numero no valido");

        return -1;
    }

    printf("Se recibio el numero %d por consola\n", n);

    for(i = 0; i < n; i++)
    {
        nota = 1.0 + (float)rand() / RAND_MAX *(6.0); 
        printf("La nota numero %d es %.1f \n", i + 1, nota);
        suma = suma + nota;
    }

    float promedio;
    promedio = suma / n;

    printf("El promedio de las notas es de %.1f", promedio);

	return 0;
}
