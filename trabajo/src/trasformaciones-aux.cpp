/**
File: trasformaciones-aux.cpp
Autora: Blanca
Descripción matrices de transformación que no están definidas por defecto, contiene: 

- MAT_Cizalla_xy
 */

#include "matrices-tr.h"

Matriz4f MAT_Cizalla_yx( float factor)
{
  Matriz4f matriz = MAT_Ident();
  matriz(1,0) = factor;

  return matriz; 
}
  
