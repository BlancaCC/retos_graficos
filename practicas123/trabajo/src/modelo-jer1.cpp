/**
   Fichero: modelo-jer1.cpp 
   Autora: Blanca cano Camarero 
   Descripción: implemtación del fichero modelo-jer.cpp
 */

#include "modelo-jer1.h"
#include "malla-ind.h"
#include "malla-revol.h"
#include "matrices-tr.h"
#include "materiales-luces.h"
#include <cmath>

// Includes propios 
//#include "colores-aux.h"
//#include "trasformaciones-aux.h"

// ________ implementación de funciones relativas a la animación _____

unsigned Pulpo :: leerNumParametros() const
{
  // número de grado de libertad 
  return 1; 
}


void Pulpo::fijarMovimientoPata(const float t)
{

  float angulo = 45- sin(t)*45;

  Matriz4f giro = MAT_Rotacion(angulo  ,0.0, 0.0, 1.0 ) ;
  
  * m_pata = MAT_Rotacion(   -2*angulo  ,0.0, 0.0, 1.0 ) ;; 
  * m_pareja_patas = giro; 
  
  		    
}

void Pulpo :: actualizarEstadoParametro ( const unsigned iParam, const float t_sec )
{
  assert ( iParam < leerNumParametros());

  switch(iParam)
    {
    case 0 :
      fijarMovimientoPata( t_sec);
      break;

    }
}
// _______ clase raíz ________

Pulpo:: Pulpo()
{
  ponerNombre("Submarinillo");
  agregar(new NPatas(m_pata, m_pareja_patas)); 

}
NPatas::NPatas( Matriz4f * & m_pata, Matriz4f * & m_pareja_patas){
  int n = 3; // número de patas
  Objeto3D * pareja_pata = new ParejaPatas(m_pata, m_pareja_patas); 
  float angulo = 360.0 /n;
  
  for( int i=0; i<n; i++) {
    
    agregar(pareja_pata);
    agregar(MAT_Rotacion( angulo, 0.0, 1.0, 0 )); 
  }
}


Pata :: Pata()
{

  float escalado = 1/8.0;
  agregar (MAT_Escalado(escalado, escalado, escalado));
  escalado = 1.0 / escalado; 
  agregar(MAT_Escalado(1.0, escalado, 1.0));
  agregar( new Cilindro( 4, 15));
  ponerColor({0.2,0,0.2}); 

}


ParejaPatas :: ParejaPatas( Matriz4f * & m_pata, Matriz4f * & m_pareja_patas )
{
  Objeto3D * pata = new Pata();
  Objeto3D * bola = new Bola(); 

  unsigned ind_pareja = agregar(MAT_Ident() );

  agregar(pata);
  
  agregar( MAT_Traslacion(0,1,0) );
  
  agregar(bola); 
  unsigned pata_arriba = agregar(MAT_Ident() );
  agregar(pata);
  agregar( MAT_Traslacion(0,1,0) );
  agregar(MAT_Escalado(2,2,2)); 
  agregar(bola); 

  m_pareja_patas = leerPtrMatriz(ind_pareja);
  m_pata = leerPtrMatriz( pata_arriba ); 
  
  
}


Bola :: Bola() {
  
  float escalado = 1/8.0;
  
  agregar ( MAT_Escalado( escalado, escalado, escalado));
  agregar(new Esfera(15, 15));
  ponerColor({0.2,1,0.2}); 
}
