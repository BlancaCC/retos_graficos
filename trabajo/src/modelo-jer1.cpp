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
#include "colores-aux.h"
#include "trasformaciones-aux.h"

// ________ implementación de funciones relativas a la animación _____
Octopus::Octopus() {

  ponerNombre("Pulpillo");
  agregar(new SegmentoPata(m_pata)); 

  
  
}


Pata::Pata ( Matriz4f * & m_patas) {

  
  
}

SegmentoPata::SegmentoPata (Matriz4f * & m_patas) {

  agregar( new Esfera());

  agregar(MAT_Traslacion(0.0, 1.0, 0.0));
  agregar(MAT_Escalado( 0.5,0,5, 0.5)); 
  agregar (new Cilindro( 4, 20));
  
}

