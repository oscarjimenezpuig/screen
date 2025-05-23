/*
============================================================
  Fichero: inout.c
  Creado: 22-05-2025
  Ultima Modificacion: divendres, 23 de maig de 2025, 12:30:06
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "inout.h"

#define KPSIZ 128

static u2 cx=0;
static u2 cy=0;
static u1 ratio=1;
static u1 inverse=0;
static u1 keyprs[KPSIZ];

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

static void keyprsinit() {
	static u1 defined=0;
	if(!defined) {
		u1* ptr=keyprs;
		while(ptr!=keyprs+KPSIZ) *ptr++=0;
		defined=1;
	}
}

static u1 metakey(KeySym k) {
	const u1 METAS=9;
	const KeySym KS[]={XK_Escape,XK_Delete,XK_Left,XK_Right,XK_Up,XK_Down,XK_Shift_L,XK_Shift_R,XK_space,XK_Enter};
	const u1 KC[]={ESCAPE,DELETE,LEFT,RIGHT,UP,DOWN,SHIFT,SHIFT,SPACE,ENTER};
	const KeySym* ptr=KS;
	while(ptr!=KS+METAS) {
		if(*ptr==k) return KC[ptr-KS];
		ptr++;
	}
	return 0;
}

static u1 alphanum(KeySym k) {
	char* ck=x_keystr(k);
	if(*(ck+1)=='\0') {
		if(*ck>='a' && *ck<='z') return *ck;
		else if(*ck>='0' && *ck<='9') return *ck;
	}
	return 0;
}
	
u1* inkey() {
	keyprsinit();
	KeySym k;
	s1 ks=x_inkey(&k);
	if(ks) {
		u1 code=metakey(k);
		if(!code) {
			code=alphanum(k);
		}
		if(code) {
			u1 value=(ks==1)?1:0;
			keyprs[code]=value;
		}
	}
	return keyprs;
}
	
u1 isprs(u1 key) {
	if(key<KPSIZ) {
		return keyprs[key];
	}
	return 0;
}

static u1 searchkey() {
	//detecta la tecla pulsada
	u1* ptr=keyprs;
	while(*ptr!=keyprs+KPSIZ){
		if(*ptr) return ptr-keyprs;
	}
	return 0;
}

u1 input(u1 l,char* s) {
	u2 cxo;
	cxo=cx;

	

}

//prueba

#include <stdio.h>

int main() {
	Color a={255,255,0};
	Color b={0,0,0};
	ini(a,b,400,400);
	at(10,10);
	attr(4,0);
	ston("HOLA");
	fls();
repeat:
	inkey();
	if(!isprs(ESCAPE)) goto repeat; 
	end();
}

