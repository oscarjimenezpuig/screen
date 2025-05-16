/*
============================================================
  Fichero: screen.h
  Creado: 15-05-2025
  Ultima Modificacion: divendres, 16 de maig de 2025, 11:57:38
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include <stdlib.h>

#include "xvideo.h"

typedef signed char s1;
typedef unsigned char u1;
typedef unsigned short u2;
typedef unsigned int u4;

typedef struct {
	u1 r,g,b;
}Color;

u1 ini(Color ink,Color paper,u2 w,u2 h);
//inicia la pantalla con el color de tinta, de papel i las dimensiones

void end();
//libera la pantalla

void fls();
//actualizacion de la pantalla

void rfl(u2 x,u2 y,u2 w,u2 h);
//actualiza la pantalla en el rectangulo dado

void on(u2 x,u2 y);
//coloca el color del ink en una posicion

void off(u2 x,u2 y);
//coloca el color del paper en una posicion

u1 get(u2 x,u2 y);
//consigue el estado del pixel en una posicion

void clr();
//pone en off todos los pixeles y los borra





