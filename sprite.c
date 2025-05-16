/*
============================================================
  Fichero: sprite.c
  Creado: 16-05-2025
  Ultima Modificacion: divendres, 16 de maig de 2025, 20:39:22
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "sprite.h"

typedef u1 Sprite[8];

static Sprite sprites[256];

static void sprdef(Sprite s,u1* data) {
	for(u1 k=0;k<8;k++) s[k]=data[k];
}

static void ascnew(char asc,u1* data) {
	sprdef(sprites[(u1)asc],data);
}

#define DATA(A,B,C,D,E,F,G,H) (u1[]){A,B,C,D,E,F,G,H}

static void ascdef() {
	//define todos los ascii
	static u1 def=0;
	if(!def) {
		def=1;
		ascnew('0',DATA(0,60,70,74,82,98,60,0));
		ascnew('1',DATA(0,48,80,16,16,16,124,0));
		ascnew('2',DATA(0,60,66,2,60,64,126,0));
		ascnew('3',DATA(0,60,66,12,2,66,60,0));
		ascnew('4',DATA(0,4,12,20,36,62,4,0));
		ascnew('5',DATA(0,126,64,124,2,66,60,0));
		ascnew('6',DATA(0,60,64,124,66,66,60,0));
		ascnew('7',DATA(0,126,2,4,8,16,16,0));
		ascnew('8',DATA(0,60,66,60,66,66,60,0));
		ascnew('9',DATA(0,60,66,66,62,2,60,0));
		ascnew('A',DATA(0,60,66,66,126,66,66,0));
		ascnew('B',DATA(0,124,66,124,66,66,124,0));
		ascnew('C',DATA(0,60,66,64,64,66,60,0));	
		ascnew('D',DATA(0,120,68,66,66,68,120,0));
		ascnew('E',DATA(0,126,64,120,64,64,126,0));
		ascnew('F',DATA(0,126,64,120,64,64,64,0));
		ascnew('G',DATA(0,60,66,64,78,66,60,0));
		ascnew('H',DATA(0,66,66,126,66,66,66,0));
		ascnew('I',DATA(0,124,16,16,16,16,124,0));
		ascnew('J',DATA(0,2,2,2,66,66,60,0));
		ascnew('K',DATA(0,68,72,112,72,68,66,0));
		ascnew('L',DATA(0,64,64,64,64,64,126,0));
		ascnew('M',DATA(0,66,102,90,66,66,66,0));
		ascnew('N',DATA(0,66,98,82,74,70,66,0));
		ascnew('O',DATA(0,60,66,66,66,66,60,0));
		ascnew('P',DATA(0,124,66,66,124,64,64,0));
		ascnew('Q',DATA(0,60,66,66,82,74,60,0));
		ascnew('R',DATA(0,124,66,66,124,68,66,0));
		ascnew('S',DATA(0,60,64,60,2,66,60,0));
		ascnew('T',DATA(0,124,16,16,16,16,16,0));
		ascnew('U',DATA(0,66,66,66,66,66,60,0));
		ascnew('V',DATA(0,66,66,66,66,36,24,0));
		ascnew('W',DATA(0,66,66,66,66,90,36,0));
		ascnew('X',DATA(0,66,36,24,24,36,66,0));
		ascnew('Y',DATA(0,68,40,16,16,16,16,0));
		ascnew('Z',DATA(0,126,4,8,16,32,126,0));
		ascnew('!',DATA(0,16,16,16,16,0,16,0));
		ascnew('"',DATA(0,36,36,0,0,0,0,0));
		ascnew('#',DATA(0,36,126,36,36,126,36,0));
		ascnew('$',DATA(0,16,124,80,124,20,124,16));
		ascnew('%',DATA(0,98,100,8,16,38,70,0));
		ascnew('&',DATA(0,16,40,16,42,68,58,0));
		ascnew('/',DATA(0,2,4,8,16,32,64,0));
		ascnew('(',DATA(0,8,16,16,16,16,8,0));
		ascnew(')',DATA(0,16,8,8,8,8,16,0));
		ascnew('[',DATA(0,24,16,16,16,16,24,0));
		ascnew(']',DATA(0,24,8,8,8,8,24,0));
		ascnew('\'',DATA(0,8,16,0,0,0,0,0));
		ascnew('*',DATA(0,0,40,16,124,16,40,0));
		ascnew('+',DATA(0,0,16,16,124,16,16,0));
		ascnew(',',DATA(0,0,0,0,0,16,16,32));
		ascnew('-',DATA(0,0,0,0,124,0,0,0));
		ascnew('.',DATA(0,0,0,0,0,24,24,0));
		ascnew(':',DATA(0,0,0,16,0,0,16,0));
		ascnew(';',DATA(0,0,8,0,0,8,8,16));
		ascnew('<',DATA(0,0,8,16,32,16,8,0));
		ascnew('>',DATA(0,0,32,16,8,16,32,0));
		ascnew('?',DATA(0,60,66,4,8,0,8,0));
		ascnew('@',DATA(0,60,74,86,94,64,60,0));
		ascnew('=',DATA(0,0,0,60,0,60,0,0));
		ascnew('\\',DATA(0,64,32,16,8,4,2,0));
		ascnew('^',DATA(0,16,40,68,0,0,0,0));
		ascnew('_',DATA(0,0,0,0,0,0,0,255));
		ascnew('{',DATA(0,28,16,96,16,16,28,0));
		ascnew('}',DATA(0,112,16,12,16,16,112,0));
		ascnew('|',DATA(0,16,16,16,16,16,16,0));
		ascnew('~',DATA(0,20,40,0,0,0,0,0));
	}
}

static u1 dirall(u1 id) {
	//da las identidades redefinibles
	return 1;
}

#include <stdio.h> //dbg

static void sprset(u1 id,u2 x,u2 y,u1 r,Flip f,u1 o) {
	Sprite* s=sprites+id;
	u1* ptr=*s;
	u1 i,j;
	j=(f&VER)?(r*8):0;
	while(ptr!=*s+8) {
		i=(f&HOR)?(r*8):0;
		for(u1 k=128;k>0;k=k>>1) {
			if(*ptr & k) {
				for(u1 vi=0;vi<r;vi++) {
					for(u1 vj=0;vj<r;vj++) {
						if(o) on(x+i+vi,y+j+vj);
						else off(x+i+vi,y+j+vj);
					}
				}
			}
			i=i+((f&HOR)?-r:r);
		}
		j=j+((f&VER)?-r:r);
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

void son(u1 id,u2 x,u2 y,u1 r,Flip f) {
	sprset(id,x,y,r,f,1);
}

void soff(u1 id,u2 x,u2 y,u1 r,Flip f) {
	sprset(id,x,y,r,f,0);
}
	
//prueba

#include <stdio.h>

int main() {
	Color green={0,255,0};
	Color black={0,0,0};
	ini(green,black,300,300);
	snew(1,7,15,7,98,126,98,2,14);
	son('A',50,50,10,NFL);
	fls();
	getchar();
	end();
}

