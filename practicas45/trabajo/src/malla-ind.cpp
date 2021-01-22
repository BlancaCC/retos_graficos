
// Nombre: Blanca , Apellidos: Cano Camarero, DNI/Pasaporte:75577392J (DDGG IG curso 20-21)
// *********************************************************************
// **
// ** Informática Gráfica, curso 2020-21
// ** Declaraciones de la clase Objeto3D.hpp
// **
// *********************************************************************

//#include <set>   // std::set
#include "ig-aux.h"
#include "tuplasg.h"
#include "malla-ind.h"   // declaración de 'ContextoVis'
#include "lector-ply.h"

#include "seleccion.h"

// *****************************************************************************
// funciones auxiliares

// *****************************************************************************
// métodos de la clase MallaInd.

MallaInd::MallaInd()
{
   // nombre por defecto
   ponerNombre("Malla indexada, anónima");
}
// -----------------------------------------------------------------------------

MallaInd::MallaInd( const std::string & nombreIni )
{
   // 'identificador' puesto a 0 por defecto, 'centro_oc' puesto a (0,0,0)
   ponerNombre(nombreIni) ;
}

//-----------------------------------------------------------------------------
// calcula la tabla de normales de triángulos una sola vez, si no estaba calculada

void MallaInd::calcularNormalesTriangulos()
{

   // si ya está creada la tabla de normales de triángulos, no es necesario volver a crearla
   const unsigned nt = triangulos.size() ;
   assert( 1 <= nt );
   if ( 0 < nor_tri.size() )
   {
      assert( nt == nor_tri.size() );
      return ;
   }

   // COMPLETAR: Práctica 4: creación de la tabla de normales de triángulos
   // ....

   Tupla3f p,q,r,s,t, normal_sin_normalizar;

   for( unsigned int i=0; i< triangulos.size(); i++)
     {
       p = vertices[triangulos[i](0)];
       q = vertices[triangulos[i](1)];
       r = vertices[triangulos[i](2)];

       s = q-p;
       t = r-q;

       normal_sin_normalizar = s.cross(t);

       if( normal_sin_normalizar.lengthSq() > 0)
          nor_tri.push_back(normal_sin_normalizar.normalized());

       else 
        nor_tri.push_back({0,0,0});
     }

   

}


// -----------------------------------------------------------------------------
// calcula las dos tablas de normales

void MallaInd::calcularNormales()
{
   // COMPLETAR: en la práctica 4: calculo de las normales de la malla
   // se debe invocar en primer lugar 'calcularNormalesTriangulos'
   // .......

  calcularNormalesTriangulos(); 

  nor_ver.insert( nor_ver.begin(), vertices.size(), {0.0, 0.0,  0.0});

  for(unsigned int i = 0; i<triangulos.size(); i++)
  {
        nor_ver[triangulos[i](0)]=nor_ver[triangulos[i](0)]+nor_tri[i];
        nor_ver[triangulos[i](1)]=nor_ver[triangulos[i](1)]+nor_tri[i];
        nor_ver[triangulos[i](2)]=nor_ver[triangulos[i](2)]+nor_tri[i];
  }
  for(unsigned int i = 0; i<vertices.size(); i++)
  {
    if(nor_ver[i].lengthSq()>0)
      nor_ver[i]=nor_ver[i].normalized();
   }
}




// ----------------------------------------------------------------------------


void MallaInd::visualizarGL( ContextoVis & cv )
{

   using namespace std ;
   assert( cv.cauce_act != nullptr );

   //VISUALIZAR NORMALES

   /**
      En el método visualizarGL de la clase MallaInd, al inicio del mismo, se debe comprobar si la variable cv.visualizando_normales está a true, en ese caso se llama a visualizarNormales y después acaba visualizarGL, sin nada más.
   */
   if( cv.visualizando_normales == true)
     {
        visualizarNormales();
        return;
     }
   //fin visualizar normales 

   if ( triangulos.size() == 0 || vertices.size() == 0 )
   {  cout << "advertencia: intentando dibujar malla vacía '" << leerNombre() << "'" << endl << flush ;
      return ;
   }

   // guardar el color previamente fijado
   const Tupla4f color_previo = leerFijarColVertsCauce( cv );

   // COMPLETAR: práctica 1: si el puntero 'array_verts' es nulo, crear el objeto ArrayVerts
   //   * en el constructor se dan los datos de la tabla de coordenadas de vértices (tabla 'vertices')
   //   * después hay que invocar a 'fijarIndices', usando el formato y datos de la tabla de triángulos ('triangulos')
   //   * si las tablas 'col_ver', 'cc_tt_ver' o 'nor_ver' no están vacías, hay que invocar los métodos 
   //     'fijarColores', 'fijarCoordText' y 'fijarNormales', como corresponda.

   // pag 88 de las diapositivas 
   if(array_verts == nullptr ) { // comprobamos si array_verts es nulo 
     array_verts = new ArrayVertices( GL_FLOAT, 3, vertices.size(), vertices.data());  
   
    array_verts->fijarIndices (GL_UNSIGNED_INT, 3*triangulos.size(), triangulos.data() );

   
    if( !col_ver.empty()  )
      array_verts->fijarColores(GL_FLOAT, 3, col_ver.data());
        
    if(! nor_ver.empty() )
      array_verts->fijarNormales(GL_FLOAT,  nor_ver.data());
        
    if( !cc_tt_ver.empty()  )
      array_verts->fijarCoordText(GL_FLOAT, 2, cc_tt_ver.data());
        
   } 
      
    
   // fin de mi completado 



   // COMPLETAR: práctica 1: visualizar según el modo (en 'cv.modo_envio')
   //   ** inmediato begin/end       : usar método 'visualizarGL_MI_BVE' de 'ArrayVerts'
   //   ** inmediato con una llamada : usar método 'visualizarGL_MI_DAE' de 'ArrayVerts'
   //   ** diferido (con un VAO)     : usar método 'visualizarGL_MD_VAO' de 'ArrayVerts'
   // (en cualquier caso hay que pasar como parámetro el tipo de primitiva adecuada a una malla de triángulos).
   // .....

   // determinamso parámetro visualización

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
     
   default:
     cout<< "EL MODO ENVÍO DE MALLA-IND NO ESTÁ DEFINIDI" << endl; 
   }

   // restaurar el color previamente fijado
   glColor4fv( color_previo );
}






// *****************************************************************************


// ****************************************************************************
// Clase 'MallaPLY'

MallaPLY::MallaPLY( const std::string & nombre_arch )
{
   ponerNombre( std::string("malla leída del archivo '") + nombre_arch + "'" );

   // COMPLETAR: práctica 2: leer archivo PLY e inicializar la malla
   
   LeerPLY( nombre_arch, vertices, triangulos); 


   // ..........................
   


   // COMPLETAR: práctica 4: invocar  a 'calcularNormales' para el cálculo de normales

   calcularNormales();
   // .................


}


// PARA VISUALIZAR NORMALES 
void MallaInd::visualizarNormales()
{
   using namespace std ;

   if ( nor_ver.size() == 0 )
   {
      cout << "Advertencia: intentando dibujar normales de una malla que no tiene tabla (" << leerNombre() << ")." << endl ;
      return ;
   }  
   if ( array_verts_normales == nullptr )
   {  
      for( unsigned i = 0 ; i < vertices.size() ; i++ )
      {  
         segmentos_normales.push_back( vertices[i] );
         segmentos_normales.push_back( vertices[i]+ 0.35f*(nor_ver[i]) );
      }
      array_verts_normales = new ArrayVertices( GL_FLOAT, 3, segmentos_normales.size(), segmentos_normales.data() );
   }

   array_verts_normales->visualizarGL_MI_DAE( GL_LINES );
   CError();
}

// ****************************************************************************
// Clase 'Cubo

Cubo::Cubo()
:  MallaInd( "cubo 8 vértices" )
{

   vertices =
      {  { -1.0, -1.0, -1.0 }, // 0
         { -1.0, -1.0, +1.0 }, // 1
         { -1.0, +1.0, -1.0 }, // 2
         { -1.0, +1.0, +1.0 }, // 3
         { +1.0, -1.0, -1.0 }, // 4
         { +1.0, -1.0, +1.0 }, // 5
         { +1.0, +1.0, -1.0 }, // 6
         { +1.0, +1.0, +1.0 }, // 7
      } ;



   triangulos =
      {  {0,1,3}, {0,3,2}, // X-
         {4,7,5}, {4,6,7}, // X+ (+4)

         {0,5,1}, {0,4,5}, // Y-
         {2,3,7}, {2,7,6}, // Y+ (+2)

         {0,6,4}, {0,2,6}, // Z-
         {1,5,7}, {1,7,3}  // Z+ (+1)
      } ;

}

Tetraedro::Tetraedro()
  :MallaInd( "tetraedro 4 vértices" )
{

  vertices =
    {
      { 0.0, 0.0, 0.0 }, 
      { +1.7, 0.0, 0.0 }, //1
      { 0.0, +1.7, 0.0 },
      { 0.0, 0.0, +1.7 }  //3 
    };

  triangulos =
    {
      {0,3,1}, // X
      {0,2,1}, // Y
      {0,2,3}
    };

  Tupla3f  mi_color = {0, 220, 0}; 
  ponerColor(mi_color);  
}


CuboColor::CuboColor()
  :MallaInd(" cubo colores 8 vértices" ) 
{

  vertices =
      {  { -1.0, -1.0, -1.0 }, // 0
         { -1.0, -1.0, +1.0 }, // 1
         { -1.0, +1.0, -1.0 }, // 2
         { -1.0, +1.0, +1.0 }, // 3
         { +1.0, -1.0, -1.0 }, // 4
         { +1.0, -1.0, +1.0 }, // 5
         { +1.0, +1.0, -1.0 }, // 6
         { +1.0, +1.0, +1.0 }, // 7
      } ;



   triangulos =
      {  {0,1,3}, {0,3,2}, // X-
         {4,7,5}, {4,6,7}, // X+ (+4)

         {0,5,1}, {0,4,5}, // Y-
         {2,3,7}, {2,7,6}, // Y+ (+2)

         {0,6,4}, {0,2,6}, // Z-
         {1,5,7}, {1,7,3}  // Z+ (+1)
      } ;

   //añadimos colores   
   for ( float i = 0;  i<2; i++) 
     for (float j = 0; j<2; j++)
       for (float k = 0; k<2; k++)
	 col_ver.push_back({ i, j, k } );
	 
}


//--- objetos para crear el submarino práctica 3

PrismaTrapecio::PrismaTrapecio()
  :MallaInd( "Prima base de trapecio" )
{


   vertices =
      {
	//base inferior
	{ -2.0, 0.0, -2.0},
	{ 2.0, 0.0, -2.0},
	{ -2.0, 0.0, 2.0},
	{ 2.0, 0.0, 2.0},

	//base superior
	{ -1.0, 1.0, -1.0},
	{ 1.0, 1.0, -1.0},
	{ -1.0, 1.0, 1.0},
	{ 1.0, 1.0, 1.0},
      } ;


  triangulos =
    {
      // X
      {0,2,1},{2,3,1},     //base inferior
      {4, 6,5}, {6,7,5},   //base superior

      
      //Y
      {0,4,1},{4,5,1},     // frente
      {2,3,7},{7,6,2},     // trasera

      // Z
      {1,5,7},{7,3,1},      // derecha
      {2,6,4},{4,0,2}
      
    };
 
}
// PRÁCTICA 4


Cubo24 :: Cubo24(){

  
  vertices = {
    //cara inferior  Y- (desde la esquina inferio, sentido horario)
    {-1,-1,-1}, {-1,-1,1}, {1,-1,1}, {1,-1,-1}, // [0,3] y=-1
    
    //cara superior Y+
    {-1,1,-1},  {-1,1,1},  {1,1,1},  {1,1,-1}, //[4,7]   y=+1

    // cara de enfrente Z = -1
    {-1,-1,-1}, {-1,1,-1}, {1,1,-1}, {1,-1,-1}, // [8,11]

    // cara Z = +1
    {1,-1,1}, {1,1,1}, {-1,1,1}, {-1,-1,1}, //  [12,15]

    // X+
    {1,-1,-1}, {1,1,-1}, {1,1,1}, {1,-1,1}, // [16, 19]

    // X-
    {-1,-1,1}, {-1,1,1}, {-1,1,-1}, {-1,-1,-1} // [20, 23]
  };

  triangulos = {
    //cara inferior
    {0,3,1},{1,3,2},

    //cara superior
    {4,5,7},{5,6,7},

    // cara de enfrente
    {8,9,11},{9,10,11},

    //Z+
    {12, 13,15}, {13, 14, 15},

    //X+
    {16,17,19}, {17,18,19},

    //X-
    {20, 21, 22}, {20,22,23}
  };

   cc_tt_ver = {
     //cara inferior
     {1,1},{1,0},{0,0},{0,1},
     //cara superior
     {0,0},{0,1},{1,1},{1,0},

     //cara enfrente
     {0,0},{0,1},{1,1},{1,0},

      // Z+
     {1,1},{1,0}, {0,0}, {0,1},

      //x+
     {1,1},{1,0},{0,0},{0,1},

     //X-
     {1,1},{1,0},{0,0},{0,1}
     
   };
   calcularNormales();
}




// -----------------------------------------------------------------------------------------------



// _______ práctica para el examen de ig   _________

// código copieteado del repo de jesús 

CilindroT::CilindroT()
:  MallaInd( "CilindroT" )
{

  int n=50;
  float x,y,z; 
  float r=1.0;
  z=2.0;
  
  float x_t, y_t;

  double  e; 
  int C = 4; //número de veces que se repite la textura

  float angulo = - 2.0*M_PI / (n);
  for(unsigned i=0; i<n+1; i++){
    x = r*cos(angulo*i);
    y = r*sin(angulo*i);
    vertices.push_back({x,y,0*z});
    vertices.push_back({x,y,-1*z});

    
    x_t = modf(C*float(i)/n, &e);

    cc_tt_ver.push_back({x_t, 1});
    cc_tt_ver.push_back({x_t, 0});
    
  }


  for(unsigned i=0; i<2*n; i+=2){
   
     triangulos.push_back({i,i+1,i+3});
     triangulos.push_back({i,i+3,i+2});
    
  }

    calcularNormales();
    ponerIdentificador(-1);
}

TapaCilindro::TapaCilindro()
:  MallaInd( "TapaCilindro" )
{
  int n=50;
  float x,y,z; 
  float r=1.0;

  z = 0.0;
  float x_t, y_t;

  vertices.push_back({0.0,0.0,0.0});
  cc_tt_ver.push_back({0.5, 0.5});

  float angulo = - 2.0*M_PI / (n);
  for(unsigned i=0; i<n+1; i++){
    x = r*cos(angulo*i);
    y = r*sin(angulo*i);
    vertices.push_back({x,y,z});

    x_t =  (x+r) /(2*r);
    y_t = 1 - (y+r) /(2*r);

    cc_tt_ver.push_back({x_t, y_t});
    
    
  }

  // trianglos

   for(unsigned i=1; i<n+1; i++){
   
     triangulos.push_back({0,i+1,i});
    
  }

    calcularNormales();
  ponerIdentificador(-1);
 
}


CilindroTextura::CilindroTextura( int identificador){
  Textura * textura = new Textura("../recursos/imgs/window-icon.jpg");
  //Textura * textura = new Textura("../recursos/imgs/lata-coke.jpg");
  agregar( new Material(textura, 1, 0.5, 1, 70) );

  agregar(new CilindroT());

  
   agregar(new TapaCilindro());

   ponerNombre("Cilindro con textura");
   ponerIdentificador(identificador);
}


CirculoLatas::CirculoLatas(int n) 
{

agregar(MAT_Traslacion(n*2,0,0));
   for (int i=0; i<n; i++){
      const float angulo=i*2.0*M_PI/float(n);
      agregar(MAT_Traslacion(n*cos(angulo),0,n*sin(angulo)));
      CuboUgr * nodo= new CuboUgr();

      nodo->ponerIdentificador(1000+i);
      agregar(nodo);

}



//alejandro

CuboUgr::CuboUgr(){
   Textura * tex = new Textura("../recursos/imgs/window-icon.jpg");
   agregar( new Material(tex, 0.2, 0.4, 0.4, 20) );
   agregar(new Cubo24());
   ponerNombre("Cubo 24 vertices");
}

Invocacion::Invocacion(int n){
   ponerNombre("Invocacion");
  

   agregar(MAT_Traslacion(n*2,0,0));
   for (int i=0; i<n; i++){
      const float angulo=i*2.0*M_PI/float(n);
      agregar(MAT_Traslacion(n*cos(angulo),0,n*sin(angulo)));
      CuboUgr * nodo= new CuboUgr();

      nodo->ponerIdentificador(1000+i);
      agregar(nodo);
   }
}