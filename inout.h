/*
============================================================
  Fichero: inout.h
  Creado: 22-05-2025
  Ultima Modificacion: dijous, 22 de maig de 2025, 11:50:53
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "sprite.h"

#define STRSIZ 256

typedef char String[256];

void at(u2 x,u2 y);
//coloca el cursor en una posicion

void attr(u1 ratio,u1 inverse);
//establecimiento de la ratio y del inverse (atributos)

void ston(char* s);
//pone una cadena (el cursor avanza un caracter)

void stoff(char* s);
//quita la cadena (el cursor avanza un caracter)

u1 inkey();
//devuelve una de las teclas reconocidas, se incorporan:
//escape=27
//delete=127
//left=26
//right=25;
//up=24
//down=23
