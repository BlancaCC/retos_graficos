/**
   Enunciado del ejercicio: 

Escribe el código de la función para calcular el área total de una malla indexada de triángulos (en el sistema de referencia local del objeto). Será una función que acepta un puntero a una MallaInd y devuelve un valor real.  

 */


// suponemso que tiene acceso a la tabla de triángulo y a la tabla de vértices
// no haré referencia a cómo se consiguen las tablas vértice ni triángulos

// el funamento teórico es que el producto escalar  es un vector con normal el área del  paralpímedo que forman los dos vectores del producto

float calculaArea(const & MallaInd malla )
{
  float suma = 0;


  Tupla3f p,q,r; // almacena los vértices leído
  Tupla3f s,t;   // alamcena los vectores que forman esos vértices
  Tupla3f v;     // almacenará el vector con el producto escalar

  for( unsigned int i=0; i< triangulos.size(); i++)
    {
      p = vertices[triangulos[i](0)];
      q = vertices[triangulos[i](1)];
      r = vertices[triangulos[i](2)];

      s = q-p;
      t = r-p;

      v = s.cross(t); 

      suma +=  1.0/2* sqrt( v.lengthSq() );  // length devuelve la norma al cuadrado

    }
    
  return suma; 
}
