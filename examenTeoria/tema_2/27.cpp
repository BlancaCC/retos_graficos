/**
Usa la función del problema anterior para construir estas dos nuevas 
figuras, en las cuales hay un número variable de instancias de la 
figura original, dispuestas en circulo (vemos los ejemplos para 5 y 
8 instancias, respectivamente).
 */



Para 5 sería gancho_x(5)
Para 8 sería gancho_x(8)

void gancho_x( int n) // número de lados 
{
  glMatrixMode( GL_MODELVIEW ); // De coordenadas objeto a coordenada de ojo
                                // ¿tranforma coordenadas objeto al mundo?

  //¿AÑADIR CÓDIGO TRASLACIÓN Y ESCALADO A MODEL VIEW ?
  // diapositiva tema2 86

  float angulo = 360.0/n;
  
  for( unsigned i = 0 ; i <  n; i + )
   {
     gancho();
     glTranslatef( 0.0, +2.0, 0.0 ); // (2) traslación +2 en Y
     glRotatef( angulo, 0.0,0.0,1.0 ); // (1) rotar
   }
}
