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
    
    
