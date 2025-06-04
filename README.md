# screen
Creacion de representaciones en pantallas de monocolor usando x-video
archivo screen:
  tipos:
    u1 -> unsigned char
    u2 -> unsigned short
    u4 -> unsigned int
    s1 -> signed char
    Color {
      u1 r,g,b;
    }
  funciones: 
    u1 ini(Color ink,Color paper,u2 w,u2 h) -> Definicion de pantalla a partir del color de la tinta, del fondo y de su tamaño
    void end() -> libera el espacio de la pantalla
    void fls() -> hace flush y muestra la pantalla actualizada
    void rfl(u2 x,u2 y,u2 w,u2 h)-> hace flush en el rectangulo determinado por x,y,w,h
    void on(u2 x,u2 y) -> se conecta el pixel de la posicion dada
    void off(u2 x,u2 y) -> se desconecta el pixel de la posicion dada
    u1 get(u2 x,u2 y) -> se consigue el estado del pixel de la posicion dada
    void clr() -> se borra toda la pantalla, todos los pixeles en off
archivo sprite:
  tipos:
    Attribute -> NAT (Sin atributos) FLV (Flip vertical) FLH (Flip horizontal) INV (Inverso)
  funciones:
    void snew(u1 id,u1 a,u1 b,u1 c,u1 d,u1 e,u1 f,u1 g,u1 h) -> definicion de un sprite 8x8 a partir de la identidad del sprite y de los 8 valores u1
    void son(u1 sprite,u2 x,u2 y,u1 ratio,Attribute attribute) -> se conectan los pixeles del sprite en la posicion dada con la ratio y los atributos dados
    void soff(u1 sprite,u2 x,u2 y,u1 ratio,Attribute attribute) -> se desconectan los pixeles del sprite en la posicion dada con la ratio y los atributos dados
archivo inout:
  constantes de metateclas:
    ESCAPE,DELETE,LEFT,RIGTH,UP,DOWN,SHIFT,SPACE,ENTER
  funciones:
    void ston(u2* x,u2* y,s1 dx,s1 dy,u1 ratio,Attribute attribute,char* s)-> cadena en on en la posicion con la ratio y attributos dados, el desplazamiento por cada caracter viene dado por dx y dy
    void stoff(u2* x,u2* y,s1 dx,s1 dy,u1 ratio,Attribute attribute,char* s) -> cadena en off, idem que al poner una cadena
    s1 kread() -> devuelve un numero positivo si la tecla es press o negativo si es release, 0 si no hay pulsacion. Devuelve codigo ascii en teclas numericas, alfanumericas y signos y los valores de las metateclas.
    u1 kison(u1 key) -> dice si una tecla por su codigo esta siendo pulsada
    void koff(u1 key) -> apaga una tecla
    u1 stin(u2 x,u2 y,s1 dx,s1 dy,u1 ratio,Attribute attribute,char* prompt,u1 len,char* str) -> entrada de una cadena caracter a caracter, se coloca un prompt en la posicion dada con el desplazamiento de las letras dados, los atributos y la ratio vienen dados. len es la longitud maxima de la cadena que entraremos, esta cadena se guardara en str. La funcion devuelve la longitud real de la cadena. 
Las teclas usadas para hacer stin son:
  LEFT/RIGHT desplaza por los caracteres
  UP/DOWN se muestran los diferentes caracteres
  ENTER se almacena la cadena que tenemos hasta ese momento
  ESCAPE se obtiene la cadena vacia
  SHIFT pasamos de numerica a alfanumerica a signos.
archivo geometry:
  funciones:
    void ron(u2 xi,u2 yi,u2 xf,u2 yf) -> conexion de una recta con origen xi,yi y final xf,yf
    void roff(u2 xi,u2 yi,u2 xf,u2 yf) -> desconexion de una recta con origen xi,yi y final xf,yf
    void pon(u1 edges,u2* edge) -> conexion de un poligono a partir del numero de vertices y las coordenadas. El poligon es cerrado.
    void poff(u1 edges,u2* edge) -> desconexion de un poligono (igual que la conexion de un poligono)
    
    
