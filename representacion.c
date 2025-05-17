/*
============================================================
  Fichero: representacion.c
  Creado: 17-05-2025
  Ultima Modificacion: dissabte, 17 de maig de 2025, 06:55:14
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "representacion.h"

#define PBP 500
#define PBH 500

#define max(A,B) ((A)>(B))?(A):(B)

//origen de coordenadas en pixels
static u2 opx=0;
static u2 opy=0;

//valores maximos positivos de x y de y (coordenadas tridimensionales)
static double max=0;

static void cwd(u2* w,u2* h) {
	//calcula el centro y las dimensiones de la pantalla
	opx=PBP;
	opy=max(PBP/2,PBH);
	*w=2*opx;
	*h=2*opy;
}

static void mxs(double escala) {
	//establecen los maximos valores de x y de y a partir de la escala
	max=((double)PBP)*escala;
}

static void pry(u2* px,u2* py,double x,double y,double z,double e) {
	//proyecta un punto tridimensional en la pantalla
	double pcx=opx;
	double pcy=opy;
	double ex=x/e;
	double ey=y/e;
	double ez=z/e;
	double ppx=ex-ey;
	double ppy=ex/2+ey/2-ez;
	*px=round(ppx+pcx);
	*py=round(ppy+pcy);
}

static void img(Funcion f,double e,double x,double y) {
	//hace la imagen de una funcion
	double z=0;
	if(f && f(&z,x,y)) {
		u2 px,py;
		pry(&px,&py,x,y,z,e);
		on(px,py);
	}
}

static void rpr(Funcion f,double e) {
	//representa la funcion f
	for(double x=-max;x<=max;x=x+e) {
		for(double y=-max;y<=max;y=y+e) {
			img(f,e,x,y);
		}
	}
}

static void pau() {
	//pausa hasta que se teclee
	KeySym k;
	while(!x_inkey(&k));
}

void representa(Color i,Color p,Funcion f,double e) {
	u2 w,h;
	cwd(&w,&h);
	ini(i,p,w,h);
	mxs(e);
	rpr(f,e);
	fls();
	pau();	
	end();
}
	
//prueba

u1 esfera(double* z,double x,double y) {
	double pz=1-pow(x,2)-pow(y,2);
	if(pz>=0) {
		*z=sqrt(pz);
		return 1;
	}
	return 0;
}

u1 olas(double* z,double x,double y) {
	*z=5*sin(x);
	return 1;
}

u1 inversa(double* z,double x,double y) {
	if(x!=0 || y!=0) {
		*z=-1/(pow(x,2)+pow(y,2));
		return 1;
	}
	return 0;
}

u1 parabola(double* z,double x,double y) {
	*z=0.03*pow(x,2)+pow(y,2)-40;
	return 1;
}

u1 cubo(double* z,double x,double y) {
	*z=0.03*pow(x,3)+pow(y,3)-40;
	return 1;
}

int main() {
	Color green={0,255,0};
	Color black={0,0,0};
	representa(green,black,cubo,0.05);
	return 0;
}
	



	

