#ifndef LATAPEONES_H
#define LATAPEONES_H

#include "objeto3d.h"
#include "grafo-escena.h"


class LataPeones5 : public NodoGrafoEscena
{
  
public:

  LataPeones5(); 
};

class LataPeones : public NodoGrafoEscena
{
  
public:

  LataPeones(); 
};

class Lata : public NodoGrafoEscena
{
    public:
  Lata(const std::string nombre, const std::string & texturaJPG, int identificador = -1);

};


class LataTapaSup : public NodoGrafoEscena
{
  
public:

  LataTapaSup(); 
};




class LataTapaInf : public NodoGrafoEscena
{
  
public:

  LataTapaInf(); 
};



class PeonMadera : public NodoGrafoEscena
{
    public:
  PeonMadera(const std::string nombre, const std::string & texturaJPG);

};


class PeonBlanco : public NodoGrafoEscena
{
    public:
  PeonBlanco(const std::string nombre);

};


class PeonNegro : public NodoGrafoEscena
{
    public:
  PeonNegro(const std::string nombre);

};

#endif
