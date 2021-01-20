// Nombre: Blanca , Apellidos: Cano Camarero, DNI/Pasaporte:75577392J (DDGG IG curso 20-21)
/**
Fichero: modelo-jer.h  
Autora: Blanca Cano Camarero  
Descripción: Práctica 3, declaración de las clases derivadas de NodoGrafoEscena. Conforman el modelo jerárquico, para más información ver pdf con documentación. 
 */
#ifndef MODELO_JER_H
#define MODELO_JER_H

#include "grafo-escena.h"


//nodo raíz del grafo

class Submarino: public NodoGrafoEscena
{
 protected:
  // matrices que le dan movimiento a mi objeto

  // movimientos turbinas 
  Matriz4f * rotTurbina = nullptr; // matriz asociada al guiro de las turbinas
  Matriz4f * traslacionCuerpoSubmarino = nullptr; 
  Matriz4f * movimientoMirilla = nullptr; 
  


  void actualizarEstadoParametro( const unsigned iParam, const float t_sec);

  //funcion auxiliar para calcular ángulo de giro del submarino
  int contador_eje = 0;
  bool cambiado = true; 
  

 public:

  Submarino();

  unsigned leerNumParametros() const;

  // animaciones propias  
  void fijarRotacionTurbina(const float rot_turbina);
  void fijarMovimientoMirilla( const float vertical, const float giro); 
  void fijarMovimientoSubmarino(const float k); 
};


// ____________ RESTO DE NODOS DEL GRAFO  ________


//______CLASES PARA EL CUERPO ________
class Cuerpo : public NodoGrafoEscena
{
 public:
  Cuerpo ( Matriz4f * & rotTurbina);
};


class BaseCuerpo: public NodoGrafoEscena
{
public:
  BaseCuerpo();
};

  
class Cabina : public NodoGrafoEscena
{
public:
  Cabina(); 
};
class ParaGolpes : public NodoGrafoEscena
{
public:
  ParaGolpes(); 
};


// __________ CLASES PARA TURBINA __________
class Turbina: public NodoGrafoEscena
{
public:
  Turbina( Matriz4f * & rotacion_turbina); 
};



class Pareja: public NodoGrafoEscena
{
  public:
  Pareja( Matriz4f * & rotacion_turbina); 
}; 
class EspigaTurbina: public NodoGrafoEscena
{
public:
  EspigaTurbina(); 
};

class Aspa: public NodoGrafoEscena
{
public: Aspa(); 
};

class CamaraTurbina: public NodoGrafoEscena
{
public: CamaraTurbina( Objeto3D * & turbina);  
};


// _________- mirilla________


class MirillaAnimada: public NodoGrafoEscena
{
public: MirillaAnimada( Matriz4f * & movimientoMirilla); 
}; 

class Mirilla: public NodoGrafoEscena
{
public: Mirilla();  
};


#endif

