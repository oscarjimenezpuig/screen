/*
============================================================
  Fichero: matrix.c
  Creado: 23-04-2025
  Ultima Modificacion: divendres, 25 d’abril de 2025, 14:27:44
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "matrix.h"

struct Node {
	u1 r,c;
	struct Node* nxt;
};

struct Matrix {
	u1 size;
	u2* values;
	struct Node* first;
	struct Node* last;
};

static u1 nodpsh(struct Matrix* m,u1 r,u1 c) {
	struct Node* n=malloc(sizeof(struct Node));
	if(n) {
		n->r=r;
		n->c=c;
		n->nxt=NULL;
		if(m->first) {
			m->last->nxt=n;
			m->last=n;
		} else {
			m->first=m->last=n;
		}
		return 1;
	}
	return 0;
}

static u1 nodpop(struct Matrix* m,u1* r,u1* c) {
	if(m && m->first) {
		struct Node* td=m->first;
		m->first=m->first->nxt;
		if(m->first==NULL) m->last=NULL;
		*r=td->r;
		*c=td->c;
		free(td);
		return 1;
	} 
	return 0;
}

static void noddel(struct Node* node) {
	if(node) {
		noddel(node->nxt);
		free(node);
	}
}

Matrix mtrxnew(u1 s) {
	struct Matrix* m=malloc(sizeof(struct Matrix));
	if(m) {
		m->values=malloc(sizeof(u2)*s*s);
		if(m->values) {
			u2* ptr=m->values;
			while(ptr!=m->values+s*s) {
				*ptr++=0;
			}
			m->size=s;
			m->first=m->last=NULL;
		} else {
			free(m);
			m=NULL;
		}
	}
	return m;
}

void mtrxdel(Matrix* m) {
	if(m && *m) {
		free((*m)->values);
		noddel((*m)->first);
		free(*m);
		*m=NULL;
	}
}

u1 mtrxset(Matrix m,u1 r,u1 c,u2 v) {
	if(m && r<m->size && c<m->size) {
		u2* value=m->values+c+r*m->size;
		if(*value!=v) {
			*value=v;
			nodpsh(m,r,c);
		}
		return 1;
	}
	return 0;
}

u1 mtrxget(Matrix m,u1 r,u1 c,u2* v) {
	if(m && r<m->size && c<m->size) {
		*v=*(m->values+c+r*m->size);
		return 1;
	}
	return 0;
}

#define AND 1
#define OR 2
#define XOR 3

static u1 mtrxopr(Matrix d,u1 rd,u1 cd,Matrix o,u1 not_con,u1 op) {
	if(d && o) {
		u2* pval=o->values;
		while(pval!=o->values+(o->size*o->size)) {
			u4 pos=pval-o->values;
			u1 r=pos/o->size;
			u1 c=pos%o->size;
			u2 val=*pval;
			val=(not_con)?~val:val;
			u2* des=d->values+((c+cd)+(r+rd)*d->size);
			u2 vprv=*des;
			switch(op) {
				case AND:
					*des=*des & val;
					break;
				case OR:
					*des=*des | val;
					break;
				default:
					*des=*des ^ val;
			}
			if(vprv!=*des) nodpsh(d,r+rd,c+cd);
			pval++;
		}
		return 1;
	}
	return 0;
}

u1 mtrxor(Matrix d,u1 rd,u1 cd,Matrix o,u1 not_con) {
	return mtrxopr(d,rd,cd,o,not_con,OR);
}

u1 mtrxand(Matrix d,u1 rd,u1 cd,Matrix o,u1 not_con) {
	return mtrxopr(d,rd,cd,o,not_con,AND);
}

u1 mtrxxor(Matrix d,u1 rd,u1 cd,Matrix o,u1 not_con) {
	return mtrxopr(d,rd,cd,o,not_con,XOR);
}

#undef AND
#undef OR
#undef XOR

u1 mtrxclr(Matrix m) {
	if(m) {
		u2* ptr=m->values;
		while(ptr!=m->values+m->size*m->size) {
			if(*ptr!=0) {
				*ptr=0;
				u4 val=ptr-m->values;
				u1 c=val%m->size;
				u1 r=val%m->size;
				nodpsh(m,r,c);
			}
			ptr++;
		}
		return 1;
	}
	return 0;
}

u1 mtrxchg(Matrix m,u1* r,u1* c,u2* v) {
	if(m) {
		if(nodpop(m,r,c)) {
			*v=*(m->values+*c+(*r)*m->size);
			return 1;
		}
	}
	return 0;
}

//prueba

#include <stdio.h>

void changes(Matrix m) {
	u1 r,c;
	u2 v;
	while(mtrxchg(m,&r,&c,&v)) {
		printf("(%u,%u)->%u\n",r,c,v);
	}
}

void mtrxprt(Matrix m) {
	for(u1 r=0;r<m->size;r++) {
		for(u1 c=0;c<m->size;c++) {
			u2 v;
			mtrxget(m,r,c,&v);
			printf("%03u ",v);
		}
		printf("\n");
	}
}

#define so(A) sizeof(A)

int main() {
	printf("%li %li %li\n",so(u1),so(u2),so(u4));
	Matrix m=mtrxnew(3);
	mtrxset(m,1,1,2);
	mtrxset(m,2,2,3);
	mtrxset(m,0,0,1);
	Matrix d=mtrxnew(10);
	mtrxor(d,5,5,m,0);
	changes(d);
	mtrxprt(d);
	mtrxdel(&m);
	mtrxdel(&d);
	return 0;
}

