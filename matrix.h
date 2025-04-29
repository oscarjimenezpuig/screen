/*
============================================================
  Fichero: matrix.h
  Creado: 28-04-2025
  Ultima Modificacion: dimarts, 29 d’abril de 2025, 12:29:56
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include <stdlib.h>

typedef unsigned char u1;
typedef unsigned short u2;
typedef unsigned int u4;

typedef struct Matrix* Matrix;

Matrix mtrnew(u1 rs,u1 cs);
//crea una nueva matriz

void mtrdel(Matrix* m);
//libera el espacio de la matriz

u1 mtrdim(Matrix m,u1* rs,u1* cs);
//da las filas y las columnas de la matriz

u1 mtrset(Matrix m,u1 r,u1 c,u2 v);
//inserta un valor de un mini de la matriz

u1 mtrget(Matrix m,u1 r,u1 c,u2* v);
//consigue el valor de un mini de la matriz

void mtrclr(Matrix m);
//pone a 0 todos los minis de la matriz

u1 mtrchg(Matrix m,u1* r,u1* c,u2* v);
//da todos los cambios presentes actuales de una matriz



