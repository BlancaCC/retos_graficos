# Examen IG Teoría 2019-2020

1. Completar el código de la siguiente función:

   ```c++
   void dibuja_elipse_2d(int n, float a, float b, Tupla3f c, float theta)
   ```

   que dibuja una elipse en 2D compuesta por $n$ vértices y de radio horizontal $a$, radio vertical $b$, centrado en el punto $c$ y girado $\theta$ (`theta`) grados con respecto al eje X. La función debe implementarse de la forma más eficiente posible, en el sentido de que para dos llamadas consecutivas para un mismo $n$ no se recalculan los vértices de nuevo, usando para ello las variables globales auxiliares que se consideren oportunas. Para visualizarla, usar modo inmediato pero **NO** utilizar `glBegin` ni `glEnd`. El interior de la elipse se debe ver de color gris y el contorno de algún color más oscuro. Si es necesario, se puede manipular la matriz de MODELVIEW pero asegurando que se deja en el mismo estado que antes de modificarla. Utilizar código C++ y llamadas de OpenGL sin apoyarse en el material de prácticas más allá de las tuplas.

2. Realizar una segunda versión de la función del ejercicio anterior pero usando esta vez modo diferido con un VAO y enviando las tablas que se consideren necesarias a la GPU. La función debe implementarse de la forma más eficiente posible, en el sentido de que para dos llamadas consecutivas para un mismo $n$ no se recalculan los vértices de nuevo, usando para ello las variables globales auxiliares que se consideren oportunas (que reutilices los VAOs dicho de forma entendible). 

3. Realizar un constructor para la clase `Toro`, derivada de `MallaInd` donde se calculen sus vertices, triangulos y normales. Se puede implementar como una malla de revolución con $n_t$ copias rotadas de un polígono regular de $n_p$ vértices de radio $r_p$, centrado a una distancia $r_t$ del origen y en el plano $z=0$, perpendicular al eje Z. Se debe construir de forma que no haya vértices repetidos y el toro tiene que ser cerrado. Los parámetros $r_p$, $r_t$ son valores reales positivos, $n_p$ y $n_t$ son valores enteros positivos y mayores que 2, la función acepta los cuatro valores como parámetro

4. Dadas las matrices 3x3 correspondientes a las siguientes transformaciones lineales en 2D:

   * **R**: Matriz de rotación en torno al origen de un ángulo de $\alpha$ radianes.
   * **D**: Matriz de traslación por el vector  ($d_x,d_y )$.
   * **E**: Matriz de escalado con factores $e_x$ y $e_y$ con respecto a X e Y respectivamente.

   a) Determinar (multiplicando el caso general) si las matrices **R** y **D** son o no son conmutativas y caracterizar cuando sí son conmutativas.

   b) Misma cuestión con **R** y **E**.

   (Lleva dos años seguidos cayendo este ejercicio)

5. Codificar una funcion que, dados `t0` y `t1` dos índices de triángulos devuelva `true` si ambos triángulos comparten una arista y `false` en caso contrario. La colección completa de tuplas de índices de triangulos se encuentra en un atributo de la clase `vector<Tupla3i> triangulos`.
