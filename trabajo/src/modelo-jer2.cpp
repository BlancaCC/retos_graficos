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

  float angulo = 360.0 / NUMERO_CUBOS;

  for( int i = 0; i<NUMERO_CUBOS; i++) 
    *m_cubo[i] = MAT_Rotacion( angulo*sin(t), 0,0,1.0); 
}
// _______ clase raíz ________

Brazo:: Brazo()
{
  ponerNombre("Brazo de cubos ");

  
  

  float tam_lado = 2.0;
  
  Objeto3D * cubo = new Cubo();

  //agregar(MAT_Rotacion(30, 0,0, 1));
  
  agregar(MAT_Traslacion( -1, -1, 0));
  
  agregar( cubo);
  agregar(MAT_Traslacion( 1, 1, 0));
  
  
  unsigned  indice  = agregar(MAT_Rotacion(30, 0,0, 1));
   m_cubo[0] = leerPtrMatriz(indice);
   
  agregar(MAT_Traslacion( 2, 0, 0)); 
  float color = 0; 
  agregar( new Cubillo(m_cubo[0],  color, cubo));
  
 
  
  for (int i= 1; i<NUMERO_CUBOS; i++) {
    
    m_cubo[i] = leerPtrMatriz(agregar(*m_cubo[0]));
    
    
    //agregar(MAT_Rotacion(30, 0,0, 1)); 
    agregar(MAT_Traslacion( tam_lado, 0, 0));

    
    float color = i*1.0/NUMERO_CUBOS; 
    agregar( new Cubillo(m_cubo[i],  color, cubo));
    

   
  }

  
    
}

Cubillo::Cubillo( Matriz4f * &giro, float color, Objeto3D * & cubo) {
  /**
  agregar(MAT_Traslacion( -1, -1, 0));
  
  agregar( cubo);
  agregar(MAT_Traslacion( 1, 1, 0));
  
  agregar(MAT_Rotacion(30, 0,0, 1));
  */
  agregar(MAT_Rotacion(30, 0,0, 1));
  //agregar(*giro); 
  agregar(MAT_Traslacion( 1, -1, 0));
  agregar( cubo);
  ponerColor({ color, color , color}); 
  
}
