// *********************************************************************
// **
// ** Informática Gráfica, curso 2019-20
// ** Implementación de la clase 'MallaRevol'
// **
// *********************************************************************

#include "ig-aux.h"
#include "tuplasg.h"
#include "lector-ply.h"
#include "matrices-tr.h"
#include "malla-revol.h"

using namespace std ;

// *****************************************************************************




// Método que crea las tablas de vértices, triángulos, normales y cc.de.tt.
// a partir de un perfil y el número de copias que queremos de dicho perfil.
void MallaRevol::inicializar
(
 const std::vector<Tupla3f> & perfil,     // tabla de vértices del perfil original
 const unsigned               num_copias  // número de copias del perfil
 )
{
  // COMPLETAR: Práctica 2: completar: creación de la malla....
  

  // hay que implementar el algoritmo tocho que se describe en el guión de prácticas en la pag 28 en adelante

  int num_vertices = perfil.size(); // número de índices, van de abajo a arriba

  Tupla3f q; //  contiene los vértices futuros
  Matriz4f matriz_rotacion;
  int k;  // vértice auxiliar para representar triángulos

  // cada copia es una instancia ángulo (2pi/(n-1)
  // instancia 0 y n-1 tienen sus vertices en el mismo sitio
  
  // primero crear table de vértices (se parte del perfil original y se inserta al final una copia de los vertices del principio)

  for( unsigned int i=0 ; i< num_copias; i++) //numero instancias
    {
      matriz_rotacion = MAT_Rotacion( (360.0 * i) / (num_copias-1), 0.0, 1.0, 0.0); 
      for( int j=0; j< num_vertices ; j++) // numéro de vértices en el perfil
	{
	  q = matriz_rotacion * perfil[j];
	  vertices.push_back(q); 
	  
	  // hay que obtener el vértice q rotando p_j un ángulo de 2pi * i /(n-1)
	  
	}
    }
  
  //segundo crear TABLA DE TRIÁNGULOS

  for(unsigned  int i = 0; i< (num_copias-1); i++)
    {
      for( int j = 0; j< (num_vertices-1); j++)
	{
	  k = i*num_vertices + j;      // índice de cierto vértice en tabla de vértices

	  // creamos cuadrado 
	  triangulos.push_back({k, k+num_vertices, k+num_vertices+1}); // x, x siguiente instancia y el de abajo de x
	  triangulos.push_back({ k, k+num_vertices+1, k+1}); //x abajo siguienre x, abajo x
	    
	}
    }


  
  


}

// -----------------------------------------------------------------------------
// constructor, a partir de un archivo PLY

MallaRevolPLY::MallaRevolPLY
(
   const std::string & nombre_arch,
   const unsigned      nperfiles
)
{
   ponerNombre( std::string("malla por revolución del perfil en '"+ nombre_arch + "'" ));
   // COMPLETAR: práctica 2: crear la malla de revolución
   // Leer los vértice del perfil desde un PLY, después llamar a 'inicializar'
   vector<Tupla3f> perfil;
   
   LeerVerticesPLY(nombre_arch, perfil); 

   inicializar(perfil, nperfiles); 
   // ...........................


}



// OBJETOS DE REVOLUCIÓN DE LA PRÁCTICA 2

Cilindro::Cilindro
(
 const int num_verts_per,
 const unsigned nperfiles
 )
{
  ponerNombre( "Cilindro generado por revolución");
  assert( num_verts_per > 1); // se necesitan un mínimo de dos vértices

  // características del cilindro
  const float alto = 1.0;
  const float radio = 1.0; 
  
  // Consideraciones de si podemos hacer las tapas en función del número de vértices disponibles 
  int num_tapas = 2;
  if( num_verts_per == 3)
    num_tapas = 1;
  else if (num_verts_per == 2)
    num_tapas = 0; 
    

  // añadimos una tapa( debe de ser la inferior por el orden de los vértices)
  
  // la idea será mantaner fijas las coordenada X Z y mover la Y.
  
  vector<Tupla3f> perfil;
  const float x = radio;
  const float z =0.0;
  float y = 0.0; // primera coordenada a introducir
  float h = alto / (num_verts_per- num_tapas-1); // distancia entre vértice y vértice del eje y

  // hacemos primera tapa si se puede
  if(num_tapas >0)
    perfil.push_back({ 0.0, y, z});

  //añadimos puntos de los laterales
   
  for( int i=0; i<num_verts_per-num_tapas; i++)
    {
      y = h*i; 
      perfil.push_back ( {x, y, z});
      
    }

  // hacemos tapa superior
  if(num_tapas >1)
     perfil.push_back({ 0.0, y, z});

  // tras esto hay que inicialiazar el perfil
  inicializar(perfil, nperfiles);
  
}


Cono::Cono
(
         const int num_verts_per,         // número de vértices del perfil original (m)
         const unsigned nperfiles         // número de perfiles (n)
 ) {
  ponerNombre( "Cono generado por revolución");
  assert( num_verts_per > 1); // se necesitan un mínimo de dos vértices, aunq

  
  // características del cono
  const float alto = 1.0;
  const float radio_base = 1.0;
  bool representar_base = true; 

  // parámetros representacion
  vector<Tupla3f> perfil;
  const float z = 0.0;
  float x = 0.0;
  float y = 0.0;

  int num_tapas = 0;
  
  //si representamos la base
  if (representar_base && num_verts_per > 2)
    {
      num_tapas = 1;
      perfil.push_back({x,y,z}); 
    }

  //representamos la generatriz del cubo
  x = radio_base;
  float h = alto /(num_verts_per - num_tapas - 1); 

  for( int i=0; i< num_verts_per - num_tapas; i++)
    {
      y = h*i;
      x =  radio_base/alto * y;

      perfil.push_back({x,y,z}); 
    }

  

  inicializar(perfil, nperfiles);
  
} 



Esfera::Esfera(
         const int num_verts_per,         // número de vértices del perfil original (M )
         const unsigned nperfiles         // número de perfiles (N )
      )
{
ponerNombre( "Esfera generada por revolución");
  assert( num_verts_per > 3); // se necesitan un mínimo de cuatro vértices, apara que quede algo parecido a una esfera


  // características de la esfera
  const float radio = 1.0;

  //parámetro para su dibujo
  vector<Tupla3f> perfil; 
  const float angulo_giro = 180 / (num_verts_per - 1);

  Matriz4f matriz_rotacion =  MAT_Rotacion( angulo_giro, 0.0, 0.0, 1.0 ); // giramso respecto a eje z

  Tupla3f p (0.0, -radio, 0.0);

  perfil.push_back(p);
  for( int i=1;  i<num_verts_per; i++)
    {
      p = matriz_rotacion * p;
      perfil.push_back(p);
    }

  inicializar(perfil, nperfiles); 

  
}
