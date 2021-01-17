/**
   Enunciado de problema: 

Escribe el código de una función que permita dibujar un polígono 2D regular de n lados (n es un parámetro de tipo int, obviamente n > 2), 
centrado en el origen, y cuyo diámetro sea igual a 3/4 del alto del viewport actual. Se supone que la zona visible en el viewport del espacio 
de coordenadas es la que hay por defecto al empezar un programa OpenGL, es decir, entre −1 y +1 en los tres ejes. Las aristas deben ser de 
color azul oscuro, con dos pixels de ancho, y el interior debe aparecer relleno de color azul claro (celeste). Puedes usar el código fuente 
para ejemplos 2D sencillos que hay en la página web.
 */


// Nota nos hemos inspirado de la wiki:
// https://en.wikibooks.org/wiki/OpenGL_Programming/GLStart/Tut3




#define PI 3.1415926535898 

//EN MODO INMEDIATO
void dibujaPoligonoEnModoInmediato( int n ) {

  //suponemos que conocemso el alto de y el ancho de la venta, almacenados en las variables:

  //alto_ven y ancho_ven
  
  //centramos el polígono: DUDA ¿LO QUE HACEMOS ES ALEJARLO Y CON ESTO SUPUESTAMENTE SE CENTRA ?

  
  //DIAPOSITIVAS IMPORTANTES TEMA 1
  // pag 59 formas...
  //105 funciones ancho, limpiar y glPolygon

  float angulo = 2.0*PI /n;

  // determinarl radio, como tiene que ser 3/4

  float r = 3.0/4;


  //clear color and depth buffer 
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();//load identity matrix


  // color azul clarito
  glColor3f(0.0f,0.5f,1.0f); 
  
  glPolygonMode( GL_FRONT_AND_BACK, GL_FILL); // el primero siempre igual y el otro {GL_FILL, GL_LINE, GL_POINT}
  glBegin(GL_POLYGON); //RELLENO

  for (int i = 0; i < n; i++) {    
   
    glVertex2f( r*cos(angulo*i), r*sin(angulo*1)); 
  } 
  glEnd();


  // ahora nos encargamso de las aristas
  // color azul oscuro
  glColor3f(0.0f,0.5f,1.0f); 
  
  glLineWidth(2);
  glBegin(GL_LINE_LOOP);

  for (int i = 0; i < n; i++) {    
   
    glVertex2f(r*cos(angulo*i), r*sin(angulo*i)); 
  } 
  glEnd();
}


const Tupla2f vertices [n];
for (int i = 0; i < n; i++) {    
   
  vertices[i]={r*cos(angulo*i), r*sin(angulo*i)};
  } 


//MODO INMEDIATO POR RAM

glEnableClienteState(GL_VERTEX);
glColor3f(0.0f,0.5f,1.0f); 
GLVertexPointer(2, GL_FLOAT, 0, vertices.data()); //n_elementos, tipo, offset, pntr
glDrawArrays( GL_LINE_LOOP, 0, vertices.size() );


glColor3f(0.0f,0.0f,1.0f); 
GLVertexPointer(2, GL_FLOAT, 0, vertices.data()); //n_elementos, tipo, offset, pntr
glDrawArrays( GL_POLYGONS, 0, vertices.size() );

glDisableClientState( GL_VERTEX_ARRAY );










// MODO TRIÁNGULARLO SOLO 
  // color azul clarito
  glColor3f(0.0f,0.5f,1.0f); 
  
  glPolygonMode( GL_FRONT_AND_BACK, GL_FILL); // el primero siempre igual y el otro {GL_FILL, GL_LINE, GL_POINT}
  glBegin(GL_TRIANGLE); //RELLENO

  for (int i = 0; i < n; i++) {    

    glVertex2f( 0, 0); 
    glVertex2f( r*cos(angulo*i), r*sin(angulo*i)); 
    glVertex2f( r*cos(angulo*(i+1)), r*sin(angulo*(i+1))); 
  } 
  glEnd();

