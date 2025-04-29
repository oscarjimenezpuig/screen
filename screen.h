/*
============================================================
  Fichero: screen.h
  Creado: 28-04-2025
  Ultima Modificacion: dimarts, 29 d’abril de 2025, 12:04:21
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "xvideo.h"
#include "matrix.h"

u1 scrnew(Matrix m);
//se crea una pantalla a partir de la matriz

void scrdel();
//se libera el espacio (de la pantalla y de la matriz);

void scrflsh();
//refleja en pantalla todos los cambios
