/**
Fichero: modelo-jer1.h  
Autora: Blanca Cano Camarero  
Descripción: Práctica 3, declaración de las clases derivadas de NodoGrafoEscena. Conforman el modelo jerárquico, para más información ver pdf con documentación. 
 */
#ifndef MODELO_JER1_H
#define MODELO_JER1_H

#include "grafo-escena.h"


//nodo raíz del grafo

class Pulpo: public NodoGrafoEscena
{
 protected:

  
  // matrices que le dan movimiento a mi objeto

  // movimientos turbinas 
  Matriz4f * m_pata = nullptr;
  Matriz4f * m_pareja_patas = nullptr; 


  void actualizarEstadoParametro( const unsigned iParam, const float t_sec);


  

 public:

  Pulpo();

  unsigned leerNumParametros() const;

  // animaciones propias  
  void fijarMovimientoPata(const float t);
  
 
};


// ____________ RESTO DE NODOS DEL GRAFO  ________


//______CLASES PARA EL CUERPO ________


class Pata: public NodoGrafoEscena
{
public:
  Pata( Matriz4f * & m_pata);
  Pata( );
  
};

class ParejaPatas: public NodoGrafoEscena
{
public:
  ParejaPatas( Matriz4f * & m_pata ,  Matriz4f * & m_pareja_patas); 
}; 

class NPatas: public NodoGrafoEscena
{
public:
  NPatas( Matriz4f * & m_pata, Matriz4f * & m_pareja_patas); 
};



class Bola: public NodoGrafoEscena
{
public:
  Bola( ); 
}; 


#endif

