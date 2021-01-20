// Nombre: Blanca , Apellidos: Cano Camarero, DNI/Pasaporte:75577392J (DDGG IG curso 20-21)
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
  
