/*
============================================================
  Fichero: matrix.h
  Creado: 23-04-2025
  Ultima Modificacion: divendres, 25 d’abril de 2025, 14:24:58
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#ifndef MATRIX_H
#define MATRIX_H

#include <stdlib.h>

#include "xvideo.h"

#define MTRXS 256

typedef unsigned char u1;
typedef unsigned short u2;
typedef unsigned int u4;

typedef struct Matrix* Matrix;

Matrix mtrxnew(u1 size);
//nueva matriz

void mtrxdel(Matrix* m);
//liberamos espacio de la matriz

u1 mtrxset(Matrix m,u1 r,u1 c,u2 value);
//insertamos un valor en la matriz en una posicion (si hay cambio, se guarda en la pila)

u1 mtrxget(Matrix m,u1 r,u1 c,u2* value);
//conseguimos el valor de la matriz en una posicion

u1 mtrxor(Matrix d,u1 rd,u1 cd,Matrix o,u1 not_on);
//en la matriz de destino hace la operacion OR con la matriz origen con los rangos de entrada, si not on, lo hace con el not

u1 mtrxand(Matrix d,u1 rd,u1 cd,Matrix o,u1 not_con);
//en la matriz de destino hace la operacion AND con la matriz origen con los rangos de entrada, si not on, lo hace con el not

u1 mtrxxor(Matrix d,u1 rd,u1 cd,Matrix o,u1 not_con);
//en la matriz de destino hace la operacion AND con la matriz origen con los rangos de entrada, si not on, lo hace con el not

u1 mtrxclr(Matrix m);
//limpia toda la matriz

u1 mtrxchg(Matrix m,u1* r,u1* c,u2* value);
//extrae el valor de la pila si existiera

#endif //MATRIX_H










