/*
============================================================
  Fichero: screen.c
  Creado: 28-04-2025
  Ultima Modificacion: dimarts, 29 d’abril de 2025, 14:38:05
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "screen.h"

#define SOM 4 //tamaño del mini

static Matrix* ptrmat=NULL;
static X_Color ink,paper;

u1 scrnew(Matrix m) {
	if(m) {
		ptrmat=malloc(sizeof(Matrix));
		if(ptrmat) {
			*ptrmat=m;
			u1 cs,rs;
			mtrdim(m,&cs,&rs);
			if(x_init(cs*SOM,rs*SOM)) {
				ink=X_WHITE;
				paper=X_BLACK;
				x_background(paper);
				return 1;
			}
		}
	}
	return 0;
}

void scrdel() {
	if(ptrmat) {
		mtrdel(ptrmat);
		free(ptrmat);
		x_end();
	}
}

static void minishow(u1 r,u1 c,u2 v) {
	u2 f=1;
	u1 rr=0;
	u1 rc=0;
	while(rr<SOM) {
		if(f & v) {
			X_Point p={rc+c,rr+r};
			x_point(p,ink);
		}
		f=f<<1;
		++rc;
		if(rc==SOM) {
			++rr;
			rc=0;
		}
	}
}

void scrflsh() {
	u1 r,c;
	u2 v;
	while(mtrchg(*ptrmat,&r,&c,&v)) {
		minishow(r*SOM,c*SOM,v);
	}
	x_flush();
}

//prueba

int main() {
	Matrix m=mtrnew(100,100);
	mtrset(m,1,1,33825);
	mtrset(m,2,2,33825);
	mtrset(m,3,3,33825);
	scrnew(m);
	scrflsh();
	getchar();
	mtrclr(m);
	scrflsh();
	getchar();
	scrdel();
	return 0;
}		
				

