/**
   ENUNCIADO
2. Realizar una segunda versión de la función del ejercicio anterior pero usando esta vez modo diferido con un VAO 
y enviando las tablas que se consideren necesarias a la GPU. 
La función debe implementarse de la forma más eficiente posible,
 en el sentido de que para dos llamadas consecutivas para un mismo $n$ no se recalculan los vértices de nuevo, 
usando para ello las variables globales auxiliares que se consideren oportunas (que reutilices los VAOs dicho de forma entendible). 
 **/


// vao: VERTEX ARRAY OBJECTS: es una estructura de datos que forma parte del estado de OpenGL y que contiene todoa la información sobre la secuencia de vértices

// La definimos (si incluir normales, ni colores ni nada, solo lo básico para este ejercicio



void dibuja_elipse_2d_md(int n, float a, float b, Tupla3f c, float theta) {


  // VAO

  GLuint id_vao; // nombre del vao

  glGenVertexArray(1, &id_vao); // crear 1 vao
  glBindVertexArray(id_vao);    // activar vao

  // GREAMOS VBO

  //tamaño en Bytes
  unsigned long tam = sizeof(Tupla3f) * (unsigned long) vertices.size();

  GLuint id_vbo;

  glGenBuffers(1, &id_vbo); //crear 1 VBO
  // parra el primer parámetro GL_ELEMENT_BUFFER (indices)
  glBinBuffer(GL_ARRAY_BUFFER, id_vbo); // tipo tabla, activa VBO activar

  // reservar memeoria en la GPU y transferir los bytes
  glBufferData(GL_ARRAY_BUFFER, tam, vartices.data(), GL_STATIC_DRAW);

  //indicamos a OPENGL la locacalizacion (puntero a memoria y offset de VBO)

  // caso para array vertex, esto aparece en fijarPuntero
  // num variables por tupla, tipo de valoes, 0, offset = 0
  
  glVertexPointer( 3, GL_FLOAT, 0,0);

  glClienteState(GL_VERTEX_ARRAY);

  // dibujar relleno
  glColor3f( 0.8,0.8,0.8); // gris clarito
  glDrawArrays(GL_POLYGON, 0, vertices.size());

  // dibujar contorno

  //glLineWidth(2); //ancho píxeles
  glColor3f(0.2,0.2, 0.2); // gris oscuro
  glDrawArrays(GL_POLYGON, 0, vertices.size());

  //desactivamos VBO

  glBindBuffer(GL_ARRAY_BUFFER, 0);
}
