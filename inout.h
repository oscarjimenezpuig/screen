/*
============================================================
  Fichero: inout.h
  Creado: 22-05-2025
  Ultima Modificacion: divendres, 23 de maig de 2025, 14:30:36
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "sprite.h"

#define STRSIZ 256

//typedef char String[256];

#define ESCAPE 27
#define DELETE 127
#define LEFT 26
#define RIGHT 25
#define UP 24
#define DOWN 23
#define SHIFT 22
#define SPACE 32
#define ENTER 1

void at(u2 x,u2 y);
//coloca el cursor en una posicion

void attr(u1 ratio,u1 inverse);
//establecimiento de la ratio y del inverse (atributos)

void ston(char* s);
//pone una cadena (el cursor avanza un caracter)

void stoff(char* s);
//quita la cadena (el cursor avanza un caracter)

u1* inkey();
//devuelve una matriz de las teclas activas, se incorporan:
//escape=27
//delete=127
//left=26
//right=25;
//up=24
//down=23
//shift=22
//space=32
//enter=1
//El resto, letras o numeros siguen su codigo ascii habitual

u1 isprs(u1 key);
//dice si una tecla esta siendo pulsada

u1 input(u1 len,char* str);
//introduccion a partir de la pantalla de cadena alfanumerica de longitud maxima len (
//evuelve la longitud real. La cadena se muestra en pantalla desde el cursor


//TODO Se ha de programar inkey para que de señal de si se pulsa tecla (o hay release) podria
//ser dando un resultado negativo
