#include <math.h>
#include "ig-aux.h"
#include "matrices-tr.h"
#include "grafo-escena.h"
#include "malla-revol.h"
#include "materiales-luces.h"
#include "latapeones.h"

using namespace std;


// --- práctica 5 -----
LataPeones5::LataPeones5()
{
  ponerNombre("Lata Peones");

  // añadimos latas
  Lata * lataCocaCola =  new Lata("Lata de Coca-Cola", "../recursos/imgs/lata-coke.jpg", 1);
  agregar(lataCocaCola);

  agregar( MAT_Traslacion(2,0,0));
  agregar( new Lata("Lata de Pepsi", "../recursos/imgs/lata-pepsi.jpg",2));

  agregar( MAT_Traslacion(2,0,0));
  agregar( new Lata("Lata de la UGR", "../recursos/imgs/window-icon.jpg",3));

  agregar( MAT_Traslacion(0,0,2));

  // añadimos peones 
  agregar(new PeonMadera("Peón Madera", "../recursos/imgs/text-madera.jpg"));

  agregar( MAT_Traslacion(-2,0,0));
  
  agregar(new PeonBlanco("Peón Blanco"));
  
  agregar( MAT_Traslacion(-2,0,0));
  
  agregar(new PeonNegro("Peón Blanco"));

}



// ---- práctica  4 -----

LataPeones::LataPeones()
{
  ponerNombre("Lata Peones");

  agregar( new Lata("Lata de coke", "../recursos/imgs/lata-coke.jpg", 1));

  agregar( MAT_Traslacion(0,0,1));
  
  agregar(new PeonMadera("Peón Madera", "../recursos/imgs/text-madera.jpg"));

  agregar( MAT_Traslacion(1,0,0));
  
  agregar(new PeonBlanco("Peón Blanco"));
  
  agregar( MAT_Traslacion(1,0,0));
  
  agregar(new PeonNegro("Peón Blanco"));

}


Lata::Lata(const string nombre, const std::string & texturaJPG, int identificador)
{
  //

  float factor = 1.5; // he mirado las coordenada del ply para coger una buena escala
  agregar( MAT_Escalado(factor, factor, factor));

  
   // ___tapas ___

  agregar(new LataTapaSup());
  agregar(new LataTapaInf());  
  

  // ----   Cuerpo de la lata -----

 

  Textura * tex = new Textura(texturaJPG);

  
  agregar( new Material(tex, 0.5,0.3,0.8,100) );
  agregar(new MallaRevolPLY("../recursos/plys/lata-pcue.ply",30));

  
  ponerNombre(nombre);
  ponerIdentificador(identificador); // recordemso que por defecto es -1
  
  
}


LataTapaSup::LataTapaSup()
{
  
    agregar( new Material(0.33,0.33,0.33,40)  ); 
    agregar(new MallaRevolPLY("../recursos/plys/lata-psup.ply", 20));
    
    ponerNombre("Tapa superior lata");
    ponerIdentificador(-1); // DUDA IDENTIFICADORES
}

LataTapaInf::LataTapaInf()
{

    agregar( new Material(0.33,0.33,0.33,40)  ); 
    agregar(new MallaRevolPLY("../recursos/plys/lata-pinf.ply", 20));
    ponerNombre("Tapa inferior lata");
    ponerIdentificador(-1);
}




PeonMadera :: PeonMadera( const string nombre, const string & texturaJPG)
{

  float factor = 1.0/(2*1.5); // he mirado las coordenada del ply para coger una buena escala
  agregar( MAT_Escalado(factor, factor, factor));
   ponerNombre(nombre);
  Textura * tex_madera =  new Textura(texturaJPG); 
  tex_madera ->modo_gen_ct =  mgct_coords_objeto;


  agregar(new Material(tex_madera, 0, 0.7,0.3, 1.0 )); 
  agregar(new MallaRevolPLY("../recursos/plys/peon", 20));

  ponerIdentificador(4);
 
}



PeonBlanco :: PeonBlanco ( const string nombre) 
{
  float factor = 1.0/(2*1.5); // he mirado las coordenada del ply para coger una buena escala
  agregar( MAT_Escalado(factor, factor, factor));
   ponerNombre(nombre);

  agregar(new Material( 0.1, 0.9,0.0, 1.0 )); 
  agregar(new MallaRevolPLY("../recursos/plys/peon", 20));

  ponerIdentificador(5);
};


PeonNegro :: PeonNegro ( const string nombre) 
{
  float factor = 1.0/(2*1.5); // he mirado las coordenada del ply para coger una buena escala
  agregar( MAT_Escalado(factor, factor, factor));
   ponerNombre(nombre);

   
  
   ponerColor({0,0,0});
  agregar(new Material( 0.1, 0.1,1.0, 30 )); 
  agregar(new MallaRevolPLY("../recursos/plys/peon", 20));

  ponerIdentificador(6);
};
