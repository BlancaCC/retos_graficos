/**

Enunciado del ejercicio: 

En una malla indexada, queremos añadir a la estructura de datos una tabla de aristas. 
Será un puntero a un vector ari, que en cada entrada tendrá una estructura (de tipo Tupla2i) 
con un vector ind de dos enteros (los índices en la tabla de vértices de los dos vértices en los extremos de la arista). 
El orden en el que aparecen los vértices en una arista es indiferente, pero cada arista debe aparecer una sola vez.

 std::vector<Tupla2i> ari ; 


Escribe el código de una función C++ para crear y calcular la tabla de aristas a partir de la tabla de triángulos.

 Intenta encontrar una solución con la mínima complejidad en tiempo y memoria posible. 
Suponer que el número de vértices adyacentes a uno cualquiera de ellos es como mucho un valor constante k > 0,
 valor que no depende del número total de vértices, que llamamos n.

 Considerar dos casos: 

1. Los triángulos se dan con orientación no coherente: 
esto quiere decir que si un triángulo está formado por los vértices i, j, k, estos tres índices pueden aparecer en cualquier orden 
en la correspondiente entrada de la tabla de triángulos (puede aparece como i, j, k o como i, k, j, o como k, j, i, etc....) 

2. Los triángulos se dan con orientación coherente: 
esto quiere decir que si dos triángulos comparten una arista entre los vértices i y j,
 entonces en uno de los triángulos la arista aparece como (i, j) y en el otro aparece como (j, i) (decimos que en el triángulo a, b, c
 aparecen las tres aristas (a, b), (b, c) y (c, a)). Además, asumimos que la malla es cerrada, es decir, que cada arista es compartida por 
exactamente dos triángulos.
 */


// _______CASO 1 _______
// suponemso que es método de la clase mallaInd, aunque no se indique en la definición de la función
//también suponemso que en la clase ya ha sido creada la variable  std::vector<Tupla2i> ari ; 


void  creaAristaNoCoherente() 
{ // método fácil poco eficiente


  int i,j,k; // índices que habrá en nuestro vector
  std::vector<Tupla2i>::iterator it; // iterador para saber si está definido
  Tupla2i aux; 
  for( unsigned int y= 0; y<triangulos.size(); y++)
    {

   
      for(int z = 0; z<3; z++) // almacena indices (0,2)(1,2), (2,0)
        {
          aux = { triangulos[y]( z), triangulos[y]((z+1)%3) };

          
          if ( ari.end() ==  find(ari.begin(), ari.end(), aux ) )
            ari.push_back( aux);
        }
      
    }
  /**
     Nota de Blanca: Podríamos almacenar las tuplas en un set, de esta manera evitariamos la repetición. La complejidad de inserción en un set es N.log(size + N) 
   */
}


  void  creaAristaNoCoherente() 
{ // método algo más eficiente 

  int i,j,k; // índices que habrá en nuestro vector
  std::vector<Tupla2i>::iterator it; // iterador para saber si está definido
  Tupla2i aux; 
  for( unsigned int y= 0; y<triangulos.size(); y++)
    {

      // leemos índices a los que hace referencia el triángulo 
      i = triangulos[y](0);
      j = triangulos[y](1);
      k = triangulos[y](2);

      for(int z = 0; z<3; z++)
        {
          aux = { triangulos[y]( z), triangulos[y]((z+1)%3) };

          
          if ( ari.end() ==  find(ari.begin(), ari.end(), aux ) )
            ari.push_back( aux); 
      
    }
}
