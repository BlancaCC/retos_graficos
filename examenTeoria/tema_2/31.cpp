
/**
Supón que dispones de una función llamada figura_simple que dibuja con
 OpenGL la figura que aparece a la izquierda (un cuadrado de lado unidad 
con la esquina inferior izquierda en el origen, con un triángulo inscrito). 
Esta función llama a glVertex para especificar las posiciones de los vértices
 de los polígonos de dicha figura. Usando exclusivamente llamadas a dicha 
función, construye otra función llamada figura_compleja que dibuja la figura 
de la derecha. Para lograrlo puedes usar manipulación de la pila de la matriz
 modelview (glPushMatrix y glPopMatrix), junto con glTranslatef y glScalef.

 */


// Suponemso que para figura_simple el centro de la figura es el incentro


void figura_compleja() {

  
  
  float ecc = sqrt(1.0/2); //escala cuadrado centro

  glPushMatrix();
  // figura centro
  glScalef(ecc, ecc, 1);
  mi_rotate_z(-45);
  glScalef(1, -1, 1);
  glTranslatef(-1.0/2,-1.0/2,0 );
  figura_simple();

  glPopMatrix(); 
 glPushMatrix();
  

//figura derecha
  
  glScalef(1, 1/2, 1);
  glTranslatef(1,-1/4,0 );
  glScalef(1, -1, 1);
  glTranslatef(-1.0/2,-1.0/2,0 );
  figura_simple();
 
  glPopMatrix();

  //figura izquierda
  glPushMatrix(); 
  glScalef(1/2, 1/2, 1);
  glTranslatef(-1,-1/4,0 );
  glTranslatef(-1.0/2,-1.0/2,0 );
  
  figura_simple();
  glPopMatrix(); 

  
}

void mi_rotate_z(float a) {

const GLfloat  mat[16] =
  {
    cos(a), -sin(a), 0,0,
    sin(a), cos(a), 0,0,
    0,0,1,0,
    0,0,0,1
  };
 
 glPushMatrix( mat); 
    
}
