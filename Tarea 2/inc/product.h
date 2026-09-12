/**
 * @file product.h
 * @brief Archivo de cabecera para la estructura del producto
*/
#ifndef PRODUCT
#define PRODUCT
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * @brief Estructura que define a un producto
*/
typedef struct _producto
{
	char* nombre; 
	int cantidad; 
    char* proveedor;
    int precio;
} Producto;

Producto crear_producto(char* nombre, int cantidad, int precio);
void print_producto(Producto p);
void eliminar_producto(Producto p);

#endif