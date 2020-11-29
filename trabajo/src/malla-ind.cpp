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


// *****************************************************************************
// funciones auxiliares

// *****************************************************************************
// métodos de la clase MallaInd.

MallaInd::MallaInd()
{
   // nombre por defecto
   ponerNombre("malla indexada, anónima");
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

}


// -----------------------------------------------------------------------------
// calcula las dos tablas de normales

void MallaInd::calcularNormales()
{
   // COMPLETAR: en la práctica 4: calculo de las normales de la malla
   // se debe invocar en primer lugar 'calcularNormalesTriangulos'
   // .......


}




// ----------------------------------------------------------------------------


void MallaInd::visualizarGL( ContextoVis & cv )
{

  
   using namespace std ;

   
   assert( cv.cauce_act != nullptr );

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
   }

   if( !col_ver.empty()  )
     array_verts->fijarColores(GL_FLOAT, 3, col_ver.data());
   
   if(! nor_ver.empty() )
     array_verts->fijarNormales(GL_FLOAT,  nor_ver.data());
  
   if( !cc_tt_ver.empty()  )
     array_verts->fijarCoordText(GL_FLOAT, 2, cc_tt_ver.data());
   
   
   array_verts->fijarIndices (GL_UNSIGNED_INT, 3*triangulos.size(), triangulos.data() ); 
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


   //________ RETO 2 ______
   // poner if(cv.envolventes ) crear esa variable de cv y añadir en main
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
   // .................



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

   calculaTodo(); 
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
  calculaTodo(); 
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


   calculaTodo(); 
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

  calculaTodo(); 
}



// -----------------------------------------------------------------------------------------------


Tupla3f MallaInd::centroGeometrico() {

  // calcular el número de vertices

  int n =  vertices.size();

  Tupla3f  media= {0,0,0}; 
  // hacer operaciones con tupla3f

  for( int i=0; i<n; i++)
    media = media + vertices[i]; 


  centro_geometrico = media;
  
  return media; 
}



float MallaInd::calculaDistanciaMaxima() {

  float distancia = 0;
  float candidato = 0;

  int n =  vertices.size();
  
  for( int i = 0; i<n; i++) {

    if( (candidato= (centro_geometrico - vertices[i]).lengthSq()) > distancia ) {
      distancia = candidato; 
    }
  }

    distancia = sqrt(distancia);
    radio_envolvente = distancia;
    
    return distancia;
    
}


void MallaInd::calculaPuntosRepresentativos() {

  const int n = 20; // número de pundos que consideramos representativos

  float x,y, w;  // coordenadas y argumento
  
  for(int i = 0; i< n; i++) {

    w = 2*M_PI /n *i; 
    x = radio_envolvente* cos( w);
    y = radio_envolvente* sin(w);

    esferaXY.push_back( centro_geometrico + Tupla3f({x,y, 0}) );
    esferaXZ.push_back( centro_geometrico + Tupla3f({x,0, y}) );
    esferaYZ.push_back( centro_geometrico + Tupla3f({0,y, x}) ); 
    
    
  }
  
}



