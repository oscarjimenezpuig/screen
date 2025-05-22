/*
============================================================
  Fichero: inout.c
  Creado: 22-05-2025
  Ultima Modificacion: dijous, 22 de maig de 2025, 11:46:11
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "inout.h"

static u2 cx=0;
static u2 cy=0;
static u1 ratio=1;
static u1 inverse=0;

void at(u2 x,u2 y) {
	cx=x;
	cy=y;
}

void attr(u1 r,u1 i) {
	ratio=r;
	inverse=i;
}

static void stprt(char* s,u1 on) {
	char* ptr=s;
	while(*ptr!='\0' && ptr-s<STRSIZ) {
		if(on) son(*ptr,cx,cy,ratio,NFL,inverse);
		else soff(*ptr,cx,cy,ratio,NFL,inverse);
		ptr++;
		cx+=ratio*8;
	}
}

void ston(char* s) {
	stprt(s,1);
}

void stoff(char* s) {
	stprt(s,0);
}

//prueba

int main() {
	Color a={255,255,0};
	Color b={0,0,0};
	ini(a,b,400,400);
	at(10,10);
	attr(4,0);
	ston("HOLA");
	fls();
repeat:
	KeySym k=0;
	x_inkey(&k);
	if(k!=XK_Escape) goto repeat;
	end();
}

