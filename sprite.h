/*
============================================================
  Fichero: sprite.h
  Creado: 16-05-2025
  Ultima Modificacion: dijous, 22 de maig de 2025, 11:02:59
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "screen.h"

//un sprite es un conjunto de 8x8 puntos
//Tenemos espacio para 256 sprites, se contiene tambien mayusculas, signos de puntuacion y numeros
//segun su codigo ASCII

typedef enum {NFL=0,HOR=1,VER=2} Flip;

u1 snew(u1 id,u1 a,u1 b,u1 c,u1 d,u1 e,u1 f,u1 g,u1 h);
//definicion de un sprite

void son(u1 id,u2 x,u2 y,u1 ratio,Flip flip,u1 inverse);
//colocacion en modo on en pantalla de un sprite

void soff(u1 id,u2 x,u2 y,u1 ratio,Flip flip,u1 inverse);
//colocacion en modo off en pantalla de un sprite


