/**
File: trasformaciones-aux.h
Autora: Blanca
Descripción matrices de transformación que no están definidas por defecto, contiene: 

- MAT_Cizalla_xy
 */


#ifndef TRASFORMACIONES_AUX
#define TRASFORMACIONES_AUX

/**
devuelve la matriz asociada a  la trasformación lineal Cizalla que desplaza la y un factor de proporcio x
 */
Matriz4f MAT_Cizalla_yx(float factor);
#endif
