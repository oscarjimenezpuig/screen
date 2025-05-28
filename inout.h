/*
============================================================
  Fichero: inout.h
  Creado: 22-05-2025
  Ultima Modificacion: dimecres, 28 de maig de 2025, 16:28:38
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

s1 kread();
//devuelve un numero positivo si la tecla es press o negativo si es release, 0 si no hay pulsacion:
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

u1 kison(u1 key);
//dice si una tecla esta siendo pulsada

void koff(u1 key);
//desconecta una tecla

u1 stin(char* prompt,u1 len,char* str);
//entrada de una cadena caracter a caracter:
//LEFT/RIGHT desplaza por los caracteres
//UP/DOWN se muestran los diferentes caracteres
//ENTER se almacena la cadena que tenemos hasta ese momento
//ESCAPE se obtiene la cadena vacia

