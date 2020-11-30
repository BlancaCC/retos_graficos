## Modelo jerárquico .h  
```c++
class Cosa: public NodoGrafoEscena
{
 protected:
 
  // matrices que le dan movimiento a mi objeto
  Matriz4f * movi = nullptr;
  
  void actualizarEstadoParametro( const unsigned iParam, const float t_sec);


 public:

  Cosa();

  unsigned leerNumParametros() const;

  // animaciones propias  
  void fijarMovimiento(const float t);
  
 
};


class Cosa2: public NodoGrafoEscena
{
public:
  Pata( Matriz4f * & movi);
  Pata( );
  
};
```


## Modelo jerárquico .cpp  

```c++
unsigned Cosa :: leerNumParametros() const
{
  // número de grado de libertad 
  return 1; 
}

void Cosa::fijarMovimiento( const float t)
{

  * movi = MAT_Rotacion( rot_turbina, 1.0, 0.0, 0.0); 
}


void Cosa :: actualizarEstadoParametro ( const unsigned iParam, const float t_sec )
{
  assert ( iParam < leerNumParametros());

  switch(iParam)
    {
    case 0 :
      fijarMovimiento( 3t_sec);
      break;
      
    }
}


// ejemplo de agregar 

Cosa::Cosa()
{
  ponerNombre("Examen");
  
  Objeto3D * inst_objeto = new Turbina(rotTurbina);
  agregar(inst_objeto);
  
  // animación de movimiento del cuerpo general
  unsigned indice = agregar (MAT_Ident()); 

  
  agregar( new Cuerpo(rotTurbina));

  agregar(MAT_Rotacion(90.0, 0.0, 0.0, 1.0 ));
  agregar(MAT_Traslacion( -2.2,1.2, 0.0));
  agregar(MAT_Escalado(0.5, 0.5, 0.5)); 
  

  traslacionCuerpoSubmarino = leerPtrMatriz(indice);  
  
}

Cosa2:: Cosa2(Matriz4f * & movi ){}

```
