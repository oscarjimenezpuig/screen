/*
============================================================
  Fichero: sprite.h
  Creado: 16-05-2025
  Ultima Modificacion: divendres, 16 de maig de 2025, 13:26:54
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "screen.h"

//un sprite es un conjunto de 8x8 puntos
//Tenemos espacio para 256 sprites, se contiene tambien mayusculas, signos de puntuacion y numeros
//segun su codigo ASCII

u1 snew(u1 id,u1 a,u1 b,u1 c,u1 d,u1 e,u1 f,u1 g,u1 h);
//definicion de un sprite

void son(u1 id,u2 x,u2 y);
//colocacion en modo on en pantalla de un sprite

void soff(u1 id,u2 x,u2 y);
//colocacion en modo off ne pantalla de un sprite


