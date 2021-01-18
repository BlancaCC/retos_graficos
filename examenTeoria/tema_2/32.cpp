/**
Usando de nuevo la función figura_simple, escribe otra función llamada 
figura_compleja_rec. Esta nueva función dibuja la figura que aparece aquí.
 */

void cuadrado ( int n) {

  figura_simple();

  if (n>0)
    {

      glTranslatef(1,1/2,0 ); 
      glScalef(1/2, 1/2, 1);        
      cuadrado(n-1);

      glPopMatrix(); 
      glPopMatrix();

      glTranslatef(1,0,0 ); 
      glScalef(1/2, 1/2, 1);    
      cuadrado(n-1);
      
    }
  
}
