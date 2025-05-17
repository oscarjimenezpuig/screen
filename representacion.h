/*
============================================================
  Fichero: representacion.h
  Creado: 17-05-2025
  Ultima Modificacion: dissabte, 17 de maig de 2025, 06:27:10
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include <math.h>

#include "screen.h"

typedef u1 (*Funcion)(double*,double,double);

void representa(Color ink,Color paper,Funcion funcion,double escala);
