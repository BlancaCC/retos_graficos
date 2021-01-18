const Tupla2f vertices [n];

//MODO INMEDIATO POR RAM

glEnableClienteState(GL_VERTEX);
glColor3f(0.0f,0.5f,1.0f); 
GLVertexPointer(2, GL_FLOAT, 0, vertices.data()); //n_elementos, tipo, offset, pntr
glDrawArrays( GL_POLIGONS, 0, vertices.size() );


glColor3f(0.0f,0.0f,1.0f); 
GLVertexPointer(2, GL_FLOAT, 0, vertices.data()); //n_elementos, tipo, offset, pntr
glDrawArrays( GL_POLYGONS, 0, vertices.size() );

glDisableClientState( GL_VERTEX_ARRAY );


