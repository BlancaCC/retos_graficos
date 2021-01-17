/**
Enunciado 
Escribe el pseudocódigo para visualizar una malla con los triángulos de un color sólido y
 las aristas en modo alambre ¿ que problemas se pueden encontrar ? .

 */



Class Mallaind2 : MallaInd::visualizarGL( ContextoVis & cv ){

  ///(..)

   GLenum tipo_prim =  GL_TRIANGLES;
   
   switch (cv.modo_envio) {
   case  (ModosEnvio::inmediato_begin_end):
     array_verts->visualizarGL_MI_BVE(tipo_prim);  
     break; 
   //inmediato_vao, // CAMBIAR el nombre de este valor
   case( ModosEnvio::inmediato_drawelements):
     array_verts->visualizarGL_MI_DAE(tipo_prim); 
     break;
     
   case( ModosEnvio::diferido_vao):
     array_verts->visualizarGL_MD_VAO(tipo_prim); 

     break; 


      GLenum tipo_prim =  GL_LINES;
   
   switch (cv.modo_envio) {
   case  (ModosEnvio::inmediato_begin_end):
     array_verts->visualizarGL_MI_BVE(tipo_prim);  
     break; 
   //inmediato_vao, // CAMBIAR el nombre de este valor
   case( ModosEnvio::inmediato_drawelements):
     array_verts->visualizarGL_MI_DAE(tipo_prim); 
     break;
     
   case( ModosEnvio::diferido_vao):
     array_verts->visualizarGL_MD_VAO(tipo_prim); 

     break; 
     
   }
