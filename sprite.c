/*
============================================================
  Fichero: sprite.c
  Creado: 16-05-2025
  Ultima Modificacion: divendres, 16 de maig de 2025, 13:27:10
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "sprite.h"

typedef u1 Sprite[8];

static Sprite sprites[256];

static void sprdef(Sprite s,u1* data) {
	for(u1 k=0;k<8;k++) s[k]=data[k];
}

static void ascdef() {
	//define todos los ascii
	static u1 def=0;
	if(!def) {
		def=1;
	}
}

static u1 dirall(u1 id) {
	//da las identidades redefinibles
	return 1;
}

static void sprset(u1 id,u2 x,u2 y,u1 o) {
	Sprite* s=sprites+id;
	u1* ptr=*s;
	u1 i,j;
	j=0;
	while(ptr!=*s+8) {
		i=0;
		for(u1 k=128;k>0;k=k>>1) {
			if(*ptr & k) {
				if(o) on(x+i,y+j);
				else off(x+i,y+j);
			}
			++i;
		}
		++j;
		ptr++;
	}
}

u1 snew(u1 id,u1 a,u1 b,u1 c,u1 d,u1 e,u1 f,u1 g,u1 h) {
	ascdef();
	if(dirall(id)) {
		u1 data[]={a,b,c,d,e,f,g,h};
		sprdef(sprites[id],data);
		return 1;
	}
	return 0;
}

void son(u1 id,u2 x,u2 y) {
	sprset(id,x,y,1);
}

void soff(u1 id,u2 x,u2 y) {
	sprset(id,x,y,0);
}
	
//prueba

#include <stdio.h>

int main() {
	Color green={0,255,0};
	Color black={0,0,0};
	ini(green,black,300,300);
	snew(1,0,126,126,0,0,126,126,0);
	son(1,50,50);
	fls();
	getchar();
	soff(1,50,50);
	fls();
	getchar();
	getchar();
	end();
}

