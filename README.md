# Retos gráficos  

Cuestiones para prepararse el examen de prácticas de la asignatura de informática gráfica.  

#### Para compilar 

*Se se añaden nuevos ficheros debe recompilarse*   

- Borrar todo el contenido de la carpeta `/trabajo/cmake-unix/build`  
- Desde la carpeta build ejecutar `cmake ..`  
- `make`  

#### Para ejecutar   
- Desde el directorio `/trabajo/` ejecutar `./cmake-unix/build/pracs_ig_exe
` IMPORTANTE QUE SEA DESDE TRABAJO  

	

## Reto 1      

Conseguir y animar esta figura , para un n,  número de patas arbitrario.

<img src="https://github.com/BlancaCC/retos_graficos/blob/main/img/octopus.jpg" width="500" height="600">


Puede encontrar mi solución en `trabajo/src/modelo-jer1.cpp` y `trabajo/include/modelo-jer1.h`    


## Reto 2  

### Parte 1  

Programar un método dentro de la clase mallaInd que calcule la esfera envolvente de la malla, para ello:
1. Añadir tres atributos privados a la clase: 
- `vector<Tupla3f> esferaXZ`
- `vector<Tupla3f> esferaYZ`
- `vector<Tupla3f> esferaXY`
que contendrán las coordenadas de los puntos que compongan, respectivamente, el ecuador, el meridiano paralelo
al plano $$x=0$$ y el meridiano paralelo al plano $$z=0$$. 

2. Hallar el centro geométrico de la malla, para ello, calcular la media aritmética de todos los vértices 
que la componen (caso de haber al menos uno, en otro caso se supone el (0,0,0) )  

3. Hallar la máxima de las distancias del centro geométrico calculado anteriormente a un vértice de la malla.  
El punto calculado en 2 será el centro de la esfera envolvente y la distancia máxima calculada en 3 será el radio de dicha esfera.  

4. Calcular una cantidad representativa de puntos que pertenezcan al plano paralelo a y=0 que pasa 
por el centro geométrico y que están a una distancia igual al radio calculado en 3 y almacenarlos
en esferaXZ, análogamente con puntos paralelos a x=0 en esferaYZ y con puntos paralelos a z=0 en esferaXY  
. 
Programar el método de forma que una vez estos vértices estén calculados no se vuelvan a calcular a no ser que la malla haya cambiado.  


Esta parte ha sido resuelta en malla-ind.h y malla-ind.cpp , en concreto se han creado e implementado las siguientes funciones y métodos. 
```c++

std:: vector<Tupla3f> esferaXZ;
std:: vector<Tupla3f> esferaYZ;
std:: vector<Tupla3f> esferaXY;

Tupla3f centro_geometrico = {0,0,0};
float radio_envolvente = 0; 


Tupla3f centroGeometrico();
float calculaDistanciaMaxima();
void calculaPuntosRepresentativos(); 

  
```
### Parte 2  
Programar la visualización de la esfera envolvente usando funciones de modo inmediato , 
como GLDrawArrays o GLDrawElements uniendo cada vértice de cada vector con el siguiente,
y los últimos con los primeros, usando la "primitiva" 
GL_LINES, utilizando líneas naranjas de 0'5 px de grosor. Se pide además que se

permita activar o desactivar la visualización de la esfera pulsando la tecla U 


#### Notas sobre cómo resolverlo   

Añado la visualización en `visualizarGL` del fichero `malla-ind.cpp`

```

   if(cv.envolvente) {
     calculaTodo();
     
     if( array_envolventeXY == nullptr) {
       array_envolventeXY = new ArrayVertices( GL_FLOAT, 3, esferaXY.size(), esferaXY.data()); 
  }
     if( array_envolventeXZ == nullptr) {
       array_envolventeXZ = new ArrayVertices( GL_FLOAT, 3, esferaXZ.size(), esferaXZ.data()); 
     }

     if( array_envolventeYZ == nullptr) {
       array_envolventeYZ = new ArrayVertices( GL_FLOAT, 3, esferaYZ.size(), esferaYZ.data()); 
     }
     GLenum tipo_primitiva = GL_LINES;
     glColor3f(1,1,0);
     glLineWidth(0.4); 
     
     array_envolventeXY -> visualizarGL_MD_VAO(tipo_primitiva);
     array_envolventeXZ -> visualizarGL_MD_VAO(tipo_primitiva);
     array_envolventeYZ -> visualizarGL_MD_VAO(tipo_primitiva);

   }  
```

Por otro lado es necesario declarar la variable `envolvente` dentro de la clase `ContextoVis` que encontraréis en el fichero  `practicas.h`. 

y finalmente en el `main.cpp` declarar la acción de botón 

```
 case GLFW_KEY_U :
         cv.envolvente = ! cv.envolvente ;
         cout << "envolvente : " << (cv.envolvente ? "activado" : "desactivado") << endl << flush ;
         break ;


```


# Cosas que me gustaría recordar  

## Declaración de objetos  

Cariño, que no se te olvide crear un nueva clase escena en los ficheros de escena.cpp y escena.h (si es un include añadiendo el respectivo modelo jerarquico);  y después hacer un `push` de esos objetos en
el main. <3
