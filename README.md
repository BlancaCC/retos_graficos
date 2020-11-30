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



## Reto 3  

Dibuja n cubos alineados que se "plieguen" en un polígono regular de n lados

<img src="https://github.com/BlancaCC/retos_graficos/blob/main/img/brazo.jpg" width="500" height="500">



## Reto 4    

Este está basado en el examen de prácticas del grupo 2 de 20-21  

Enunciados examen de las prácticas 1 y 2
Sube a la tarea un único archivo P12.zip con las carpetas include y src (con esa estructura), con las mismas prácticas ya subidas, y con los añadidos que se describen aquí:

Extiende los archivos malla-ind.h y malla-ind.cpp de tus prácticas para incluir (al final) las declaraciones e implementaciones de las nuevas clases que se indican más abajo.

### Práctica 1: clase ExtrellaZ:

Clase derivada de MallaInd, cuyo constructor acepta un parámetro n (unsigned, > 1). El constructor inicializa las tablas de vértices, triángulos y colores de una malla indexada con 2*n triángulos y 2*n+1 vértices, en forma de estrella, plana (en el plano perpendicular al eje Z) y con n puntas. Los vértices tienen coordenadas entre 0 y 1 en X y en Y (y todos tienen Z igual a cero). El centro de la estrella está en (0.5,0.5) en X e Y, y los radios hasta las puntas son de longitud 0.5.

El vértice central tiene color blanco. El resto de vértices tienen colores cuyas componentes R, G y B coinciden con sus coordenadas X, Y y Z, respectivamente.
  
  
  <img src="https://github.com/BlancaCC/retos_graficos/blob/main/img/r4_1.jpg" width="500" height="500">

### Práctica 2: clase PiramideExtrellaZ:

Es una clase derivada de MallaInd, cuyo constructor acepta un parámetro n (unsigned, > 1). El constructor inicializa las tablas de vértices, triángulos y colores de una malla indexada con 4*n triángulos y 2*n+2 vértices, en forma de pirámide, con eje el eje Z, y cuya base es idéntica a la estrella descrita en la pregunta anterior (usa una copia de ese código para crear la base). El ápice de la pirámide es el único vértice adicional, tiene coordenadas (0.5,0.5,0.5) y color blanco.

En la figura se observan ambos objetos.

Añade (como primer objeto de la escena) una instacia de EstrellaZ en el constructor de Escena1, e igualmente una instancia de PiramideEstrellaZ en el constructor de Escena2 (tmb. como primer objeto).
Recuerda que cada archivo debe tener tu apellidos, nombre y DNI en la primera línea.  

<img src="https://github.com/BlancaCC/retos_graficos/blob/main/img/r4_2.jpg" width="500" height="500">


### Enunciado examen de la práctica 3  

Sube a la tarea un único archivo con las carpetas include y src (con esa estructura), con las mismas prácticas ya subidas, las clases del examen de las prácticas 1 y 2 y con los añadidos que se describen aquí:

Extiende los archivos grafo-escena.h y grafo-escena.cpp de tus prácticas para incluir (al final) las declaraciones e implementaciones de la clase GrafoEstrellaX, con estas especificaciones:

El constructor de la clase acepta un parámetro llamado n (unsigned, >1)

En el constructor se construye un grafo de escena que tiene una instancia del objeto con una estrella plana de la práctica 1 (usa en tu grafo de escena una instancia de la misma clase que has creado para la práctica 1 en este examen, instanciala con el número de puntas indicado por n). Esa estrella es perpendicular al eje X. Tiene centro en el origen y el radio desde el centro a los vértices en las puntas es 1.3.

En cada punta de la estrella hay una instancia de la clase Cono de la práctica 2, con radio de la base 0.14, y altura 0.15, y cuyo eje es el segmento que hace de radio desde el centro de la estrella a esa punta (intenta usar una única instancia del cono para todas las puntas, instanciada con distintas transformaciones)

El objeto tiene un parámetro o grado de libertad, de forma que se puede rotar entorno al eje X (entorno al centro de la estrella). Si se activan las animaciones, gira a una velocidad de 2.5 vueltas por segundo.

En la figura de abajo se observa el objeto jerárquico (los colores de tu estrella no tienen porque coincidir con los de la figura).

Añade (como primer objeto de la escena) una instacia de esta clase en el constructor de Escena3.

Recuerda que cada archivo debe tener tu apellidos, nombre y DNI en la primera línea.

<img src="https://github.com/BlancaCC/retos_graficos/blob/main/img/r4_3.jpg" width="500" height="500">


# Cosas que me gustaría recordar  

## Declaración de objetos  

Cariño, que no se te olvide crear un nueva clase escena en los ficheros de escena.cpp y escena.h (si es un include añadiendo el respectivo modelo jerarquico);  y después hacer un `push` de esos objetos en
el main. <3
