/**
Fichero: modelo-jer2.h  
Autora: Blanca Cano Camarero  


Implementación del reto 2
 */
#ifndef MODELO_JER2_H
#define MODELO_JER2_H

#include "grafo-escena.h"


//nodo raíz del grafo

class Brazo: public NodoGrafoEscena
{
 protected:

  
  // matrices que le dan movimiento a mi objeto

  // movimientos turbinas
  
  const int N = 5;  // numero de cubos (tinee que coincidir con el de abajo
  
  Matriz4f * m_cubo[5];// = nullptr; // matriz de giro


  void actualizarEstadoParametro( const unsigned iParam, const float t_sec);


  

 public:

  
  Brazo();

  unsigned leerNumParametros() const;

  // animaciones propias  
  void fijarGiro(const float t);
  
 
};




// ____________ RESTO DE NODOS DEL GRAFO  ________


//______CLASES PARA EL CUERPO ________


class Cubillo: public NodoGrafoEscena
{
public:
  Cubillo(float color); 
}; 
#endif

