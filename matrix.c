/*
============================================================
  Fichero: matrix.c
  Creado: 28-04-2025
  Ultima Modificacion: dimarts, 29 d’abril de 2025, 12:29:56
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "matrix.h"

struct Node {
	u1 r,c;
	struct Node* nxt;
};

struct Matrix {
	u1 rs,cs;
	u2* mini;
	struct Node* top;
	struct Node* bot;
};

//mini es un cuadrado 4x4 de 16 bits, rs y cs dan las columnas y las filas que tiene mini

static u1 nodpsh(Matrix m,u1 r,u1 c) {
	struct Node* nn=malloc(sizeof(struct Node));
	if(nn) {
		nn->r=r;
		nn->c=c;
		nn->nxt=NULL;
		if(!m->bot) m->bot=m->top=nn;
		else {
			m->bot->nxt=nn;
			m->bot=nn;
		}
		return 1;
	}
	return 0;
}

static u1 nodpop(Matrix m,u1* r,u1* c,u2* v) {
	if(m->top) {
		struct Node* td=m->top;
		m->top=m->top->nxt;
		if(!m->top) m->bot=NULL;
		*r=td->r;
		*c=td->c;
		*v=*(m->mini+(td->c+td->r*m->cs));
		free(td);
		return 1;
	}
	return 0;
}

static void noddel(struct Node* n) {
	if(n) {
		noddel(n->nxt);
		free(n);
	}
}

Matrix mtrnew(u1 rs,u1 cs) {
	Matrix m=malloc(sizeof(struct Matrix));
	if(m) {
		m->mini=malloc(sizeof(u2)*rs*cs);
		if(m->mini) {
			u2* ptr=m->mini;
			while(ptr!=m->mini+rs*cs) *ptr++=0;
			m->rs=rs;
			m->cs=cs;
			m->top=m->bot=NULL;
		} else {
			free(m);
			m=NULL;
		}
	}
	return m;
}

void mtrdel(Matrix* m) {
	if(m && *m) {
		noddel((*m)->top);
		free((*m)->mini);
		free((*m));
		*m=NULL;
	}
}

u1 mtrdim(Matrix m,u1* rs,u1* cs) {
	if(m) {
		*rs=m->rs;
		*cs=m->cs;
		return 1;
	}
	return 0;
}

#define inlim(A,L) ((A)<(L))
#define inm(A,B,M) (inlim((A),(M)->rs) && inlim((B),(M)->cs))

u1 mtrset(Matrix m,u1 r,u1 c,u2 v) {
	if(m && inm(r,c,m)) {
		u2* val=m->mini+c+r*m->cs;
		if(*val!=v) {
			*val=v;
			nodpsh(m,r,c);
			return 1;
		}
	}
	return 0;
}

u1 mtrget(Matrix m,u1 r,u1 c,u2* v) {
	if(m && inm(r,c,m)) {
		*v=*(m->mini+c+r*m->cs);
		return 1;
	}
	return 0;
}

#undef inlim
#undef inm

void mtrclr(Matrix m) {
	for(u1 r=0;r<m->rs;r++) {
		for(u1 c=0;c<m->cs;c++) {
			mtrset(m,r,c,0);
		}
	}
}

u1 mtrchg(Matrix m,u1* r,u1* c,u2* v) {
	if(m) return nodpop(m,r,c,v);
	return 0;
}


