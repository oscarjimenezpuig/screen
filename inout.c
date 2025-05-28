/*
============================================================
  Fichero: inout.c
  Creado: 22-05-2025
  Ultima Modificacion: dimecres, 28 de maig de 2025, 16:30:30
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
	const u1 METAS=10;
	const KeySym KS[]={XK_Escape,XK_Delete,XK_Left,XK_Right,XK_Up,XK_Down,XK_Shift_L,XK_Shift_R,XK_space,XK_Return};
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
	
s1 kread() {
	keyprsinit();
	KeySym k;
	s1 ks=x_inkey(&k);
	if(ks) {
		u1 code=metakey(k);
		if(!code) {
			code=alphanum(k);
		}
		if(code) {
			keyprs[code]=(ks==1);
			return (ks==1)?code:-code;
		}
	}
	return 0;
}
	
u1 kison(u1 key) {
	if(key<KPSIZ) {
		return keyprs[key];
	}
	return 0;
}

void koff(u1 key) {
	if(key<KPSIZ) keyprs[key]=0;
}

static u1 chrptd(s1 dir) {
	const u1 LEN=68;
	char* const CRC="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ!\"#$%&/()[]/*+,-.:;><?@=\\^_{}|~ ";
	static char* ptr=CRC;
	if(dir==1) {
		ptr++;
		if(*ptr=='\0') ptr=CRC;
	} else if(dir==-1) {
		if(*ptr=='0') {
			ptr=CRC+LEN;
		}
		ptr--;
	}
	return *ptr;
}

static void erainp(char* intro,u1 len) {
	char* ptr=intro;
	u2 f=0;
	u2 c=0;
	while(*ptr!='\0') {
		soff(' ',c,f,ratio,NFL,1);
		c+=8*ratio;
		ptr++;
	}
	for(u2 l=0;l<len;l++) {
		soff(' ',c,f,ratio,NFL,1);
		c+=8*ratio;
	}
}

static void visinp(char* intro,char* str,u1 pos) {
	char* ptr=intro;
	u2 f=0;
	u2 c=0;
	while(*ptr!='\0') {
		son(*ptr,c,f,ratio,NFL,inverse);
		c+=8*ratio;
		ptr++;
	}
	ptr=str;
	while(*ptr!='\0') {
		son(*ptr,c,f,ratio,NFL,(pos==ptr-str));
		c+=8*ratio;
		ptr++;
	}
}
static u1 arrinp(char* str) {
	char* ptr=str;
	while(*ptr!='\0') ptr++;
	ptr--;
	while(*ptr==' ') ptr--;
	ptr++;
	*ptr='\0';
	return ptr-str;
}

u1 input(char* prompt,u1 len,char* str) {
	for(u1 k=0;k<len;k++) str[k]=' ';
	str[len]='\0';
	u1 finish=0;
	u1 poses=0;
	visinp(prompt,str,poses);
	fls();
	while(!finish) {
		s1 code=kread();
		if(code>0) {
			if(code==LEFT && poses>0) {
				poses--;
			} else if(code==RIGHT && poses<len) {
				poses++;
			} else if(code==UP) {
				str[poses]=chrptd(-1);
			} else if(code==DOWN) {
				str[poses]=chrptd(1);
			} else if(code==ENTER) {
				finish=1;
			} else if(code==ESCAPE) {
				*str='\0';
				finish=1;
			}
			koff(code);
			erainp(prompt,len);
			if(!finish) visinp(prompt,str,poses);
			fls();
		}
	}
	return arrinp(str);
}


				



//prueba

#include <stdio.h>

int main() {
	Color a={255,255,0};
	Color b={0,0,0};
	ini(a,b,400,400);
	attr(4,1);
	char hola[6];
	printf("len=%i\n",input("HOLA",5,hola));
	at(100,200);
	attr(5,0);
	ston(hola);
	fls();
repeat:
	if(kread()!=ESCAPE) goto repeat; 
	end();
}

