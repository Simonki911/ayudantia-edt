/**
 * @file main.c
*/
#include "product.h"
#include <stdio.h>
#include <time.h>

void products_to_csv(Producto p[]);

int main()
{
    srand(time(NULL));

    int i, cantidad, precio;

    Producto Productos[4];

    char* nombres[] = {"Computador", "Parlante", "Audifonos", "Piano"};

    for (i = 0; i < 4; i++)
    {   
	    cantidad = rand() % 100 + 1; // Cantidad aleatoria entre 1 y 100

	    printf("Ingrese el precio de %s: ", nombres[i]);
	    scanf("%d", &precio);

	    Productos[i] = crear_producto(nombres[i], cantidad, precio);
    }

    for (i = 0; i < 4; i++)
    {
        print_producto(Productos[i]);
        printf("\n");
    }

	// Guardamos la información en un archivo CSV
	products_to_csv(Productos);
	printf("Archivo guardado en build/productos.csv\n");

	// Eliminamos la memoria asignada a cada producto
	for (i = 0; i < 4; i++) eliminar_producto(Productos[i]);

	return 0;
}

/**
 * @brief Función que crea un CSV a partir de un arreglo de Personas
*/
void products_to_csv(Producto p[])
{
	int i;
	FILE* archivo;
	archivo = fopen("build/productos.csv", "w");
	if (archivo == NULL)
	{
		printf("Error: No se pudo abrir el archivo\n");
		exit(1);
	}
	fprintf(archivo, "Nombre,Cantidad,Proveedor,Precio\n");
	for (i = 0; i < 4; i++)
	{
		fprintf(archivo, "%s,%d,%s,%d\n", p[i].nombre, p[i].cantidad, p[i].proveedor, p[i].precio);
	}
	fclose(archivo);
}