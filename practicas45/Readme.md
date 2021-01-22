# Plantilla  

```c++
// .h

#include "grafo-escena.h"
class NOMBRE : public NodoGrafoEscena 
{
   public:
   NOMBRE();
};

//.cpp

NOMBRE::NOMBRE() 
{
  
  Textura* text_ugr = new Textura("../recursos/imgs/window-icon.jpg");

  Material* material = new Material(text_ugr,0.2, 0.4, 0.4, 20);
  
  agregar(material);
  agregar(new Cubo24());
  
  
una  CuboUgr * nodo= new CuboUgr();

nodo->ponerIdentificador(1000+i);
agregar(nodo);

  ponerNombre("cubo 24 vértices");
  
  
  
}



// agregar matrices

agregar(MAT_Traslacion( -2.2,1.2, 0.0));
 agregar(MAT_Escalado(0.5, 0.5, 0.5)); 
 agregar(MAT_Rotacion(90.0, 0.0, 0.0, 1.0 ));
 
 
 
 // poner identificador
 
 ponerIdentificador( -1); // -1 herencia de la raiz, 0 ninguno, 1 pripio

```



float angulo = 2*PI/ n; 
for(int i=0; i <n; i++) {

float x = r*cos( angulo *i) + distancia, 
    y = r*sin( angulo *i), 
    z = 0.0; 
 Tupla3f m*p = { x,y,z}; 
 
 perfil.push_back(p);
 
 }
