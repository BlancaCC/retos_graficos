/**
   Fichero: modelo-jer2.cpp 
   Autora: Blanca cano Camarero 
   Descripción: implemtación del fichero modelo-jer2
 */

#include "modelo-jer2.h"
#include "malla-ind.h"
#include "malla-revol.h"
#include "matrices-tr.h"
#include "materiales-luces.h"
#include <cmath>

// Includes propios 

// ________ implementación de funciones relativas a la animación _____

unsigned Brazo :: leerNumParametros() const
{
  // número de grado de libertad 
  return 1; 
}


void Brazo :: actualizarEstadoParametro ( const unsigned iParam, const float t_sec )
{
  assert ( iParam < leerNumParametros());

  switch(iParam)
    {
    case 0 :
      fijarGiro( t_sec);
      break;

    }
}

void Brazo::fijarGiro( const float t) {

  float angulo = 180.0/ N; 

  for(int i = 1; i<N; i++)
    * m_cubo[i] = MAT_Rotacion( angulo + angulo*cos(2*M_PI*t/4), 0,0,1.0); 
}
// _______ clase raíz ________

Brazo:: Brazo()
{
  ponerNombre("Brazo de cubos ");

  
  float angulo =  360.0 / N; 
  Objeto3D * cubo = new Cubo();
  float  color;
  
   agregar(MAT_Traslacion(1,-1, 0));

  agregar(cubo);
  for(int i = 1; i<N; i++) {
    color = 1.0*i/N; 
    agregar( MAT_Traslacion(1,1, 0));
    unsigned ind = agregar(MAT_Rotacion(angulo, 0,0,1));
    agregar( MAT_Traslacion(1,-1, 0));
  

    m_cubo[i] = leerPtrMatriz(ind); 
    agregar(new Cubillo(color));

  
  }

   
    
}

Cubillo::Cubillo( float color) {
  
  
  agregar(new Cubo()); 
  ponerColor({color, color, color});
  
}
