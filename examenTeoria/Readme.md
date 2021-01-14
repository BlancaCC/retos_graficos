# Carpeta con el fin de prepararse el examen final de teoría   


## Indice de contenido relevante   


### Tema 2  

- Sintaxis y operaciones válidas de vectories: Tema 1 t228

```c++

// declaraciones de tuplas y de valores escalares 
Tupla3f a,b,c ;
float s,l ;

 s = a.dot(b) ; // producto escalar (usando método dot) 
 s = a|b ; // producto escalar (usando operador binario | )
 a = b.cross(c) ; // producto vectorial a = b × c (solo para tuplas de 3 valores)
 l = a.lengthSq() ;
 // l = kak2 (calcular módulo al cuadrado) a = b.normalized();
 // a = copia normalizada de b (b no cambia)

```  


- Conocer la estructura de la tabla triángulo 

`Tupla3f  p = vertices[triangulos[i](0)];
`
