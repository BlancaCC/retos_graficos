/**

ENUNCIADO 
1. Completar el código de la siguiente función:

   ```c++
   void dibuja_elipse_2d(int n, float a, float b, Tupla3f c, float theta)
   ```

   que dibuja una elipse en 2D compuesta por $n$ vértices y de radio horizontal $a$,
 radio vertical $b$, centrado en el punto $c$ y girado $\theta$ (`theta`) grados con respecto al eje X.
 La función debe implementarse de la forma más eficiente posible, en el sentido de que para dos llamadas consecutivas
 para un mismo $n$ no se recalculan los vértices de nuevo, usando para ello las variables globales auxiliares que se 
consideren oportunas. Para visualizarla, usar modo inmediato pero **NO** utilizar `glBegin` ni `glEnd`. El interior de 
la elipse se debe ver de color gris y el contorno de algún color más oscuro. Si es necesario, se puede manipular la matriz 
de MODELVIEW pero asegurando que se deja en el mismo estado que antes de modificarla. Utilizar código C++ y llamadas de OpenGL 
sin apoyarse en el material de prácticas más allá de las tuplas.
 */


vector<Tupla3f> vertices;
int tam = 0;

void dibuja_elipse_2d(int n, float a, float b, Tupla3f c, float theta) {

  // comprobamos si no se ha creado y en tal caso se crea

  if(tam != n) {
    circulo.resize(n);
    tam = n; 

    // añadi vértices para un círculo, luego se escalará

    float angulo = 2.0 * M_PI /n;
    float x,y,z=0.0; 

    
    for( int i = 0; i<n; i++) {
      x = cos(i*angulo);
      y = sin(i*angulo);

      vertices[i] = {x,y,z};
    }
  }

  // VAMOS A REGISTRAR LA TABLA
  

   // transformaciones
  
  glMatrixMode(GL_MODELVIEW);
  glPushMAtrix();
  glLoadIdentity();

  glRotate(theta, 1.0, 0, 0); // angulo que se pide en el problema
  glTranslate(c[0], c[1], c[2]); // translación sobre tal punto
  glScale( a,b,1);  // forma elipse 

  
  
  //glBindVertexArray( 0 ); // ACTIVA VAO POR DEFECTO

  glBindBuffer(GL_ARRAY_BUFFER, 0);    // esto el profesor no lo pone
  
  glEnableClienteState(GL_VERTEX_ARRAY);

  glVertexPointer(3, GL_FLOAT, 0, vertices.data()); 


  // contorno
  glColor3f(0.2, 0.2, 0.2); // color gris oscuro
  glDrawArrays( GL_LINE_LOOP, 0, vertices.size() );
  /** otra opción sería 

      glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // porque por defecto el poígono es de relleno 
      glDrawArrays(GL_POLYGON, 0, vertices.size()); 
      glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // restauramos el relleno
  */


  // relleno
  glColor3f(0.8, 0.8, 0.8); // gris claro

    glDrawArrays(GL_POLYGON, 0, vertices.size()); 

  
 
    glDisableClienteState(GL_VERTEX_ARRAY);
    glPopMatrix(); 

}
