/**
 * @file producto.c
 * @brief Funciones relacionadas con la estructura Producto
*/
#include "product.h"

/**
 * @brief Función que crea una estructura Producto
 * 
 * @param nombre Cadena de caracteres con el nombre del producto
 * @param edad Cantidad del producto
 * @return Producto Estructura 
 */
Producto crear_producto(char* nombre, int cantidad, int precio)
{
	Producto p;
	p.nombre = (char*)malloc(strlen(nombre) + 1);
	if (p.nombre == NULL)
	{
		printf("Error: No se pudo asignar memoria para el nombre\n");
		exit(1);
	}
	strcpy(p.nombre, nombre);
	
	if (cantidad < 0) cantidad = 0;
	p.cantidad = cantidad;

    p.proveedor = (char*)malloc(6); 
	if (p.proveedor == NULL)
	{
		printf("Error: No se pudo asignar memoria para el proveedor\n");
		exit(1);
	}
	for (int i = 0; i < 5; i++)
	{
		p.proveedor[i] = 'a' + (rand() % 26);
	}
	p.proveedor[5] = '\0';

	p.precio = precio;
	
	return p;
}

/**
 * @brief Imprime información de una estructura Producto
 * 
 * @param p Estructura Producto a imprimir
*/
void print_producto(Producto p)
{
	printf("Nombre: %s\n", p.nombre);
	printf("Cantidad:   %d\n", p.cantidad);
	printf("Proveedor: %s\n", p.proveedor);
	printf("Precio:  %d\n", p.precio);
}

/**
 * @brief Elimina la memoria asignada a una estructura Producto
 * 
 * @param p Estructura Prodcuto para eliminar
*/
void eliminar_producto(Producto p)
{
	free(p.nombre);
	free(p.proveedor);
}