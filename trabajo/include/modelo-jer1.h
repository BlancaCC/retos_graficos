/**
Fichero: modelo-jer.h  
Autora: Blanca Cano Camarero  
Descripción: Práctica 3, declaración de las clases derivadas de NodoGrafoEscena. Conforman el modelo jerárquico, para más información ver pdf con documentación. 
 */
#ifndef MODELO_JER1_H
#define MODELO_JER1_H

#include "grafo-escena.h"


//nodo raíz del grafo

class Octopus: public NodoGrafoEscena
{
 protected:
  // matrices que le dan movimiento a mi objeto

  
  Matriz4f * m_pata = nullptr; 
  
  


  void actualizarEstadoParametro( const unsigned iParam, const float t_sec);
 
  

 public:

  Octopus();

  unsigned leerNumParametros() const;

  // animaciones propias  
  void fijaMovimientoPata(const float rot_turbina);
 
};


// ____________ RESTO DE NODOS DEL GRAFO  ________


//______CLASES PARA EL CUERPO ________


class Pata : public NodoGrafoEscena
{
  public Pata(Matriz4f * & m_pata); 
}; 


class SegmentoPata:: public NodoGrafoEscena {
  public SegmentoPata(Matriz4f * & m_pata); 
}(Matriz4f * & m_pata); 
#endif

