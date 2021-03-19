// DEITEL pag 439 en adelante
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

class Tiempo {

public:
   Tiempo( int = 0, int = 0, int = 0); // constructor predeterminado
   ~Tiempo(); // destructor predeterminado
   // funciones establecer = set
   void estableceHora( int, int, int ); // establece hora, minuto, segundo
   void estableceHora1( int );   // establece hora
   void estableceMinuto( int );  // establece minuto
   void estableceSegundo( int ); // establece segundo

   // funciones obtener = get
   int obtieneHora1();        // obtiene hora
   int obtieneMinuto();       // obtiene minuto
   int obtieneSegundo();      // obtiene segundo

   void imprimeUniversal();         // imprime la hora en formato universal
   void imprimeEstandar();          // imprime la hora en formato est�ndar
   
   void incrementaSegundos(const int);
   void incrementaMinutos(const int );
   void incrementaHoras(const int);
private:
   int hora;     // 0 - 23 (formato de reloj de 24 horas)
   int minuto;   // 0 - 59
   int segundo;  // 0 - 59

}; // fin de la clase Tiempo

// funcion constructor para inicializar datos privados;
// llama a la funcion miembro estableceHora para asignar los valores;
// los valores predeterminados son 0 (vea la definicon de la clase)
Tiempo::Tiempo( int hr, int min, int seg ) 
{ 
   estableceHora( hr, min, seg ); 
} // fin del constructor Tiempo
Tiempo::~Tiempo(){}
// establece los valores de hora, minuto y segundo
void Tiempo::estableceHora( int h, int m, int s ) 
{ 
   estableceHora1( h );
   estableceMinuto( m );
   estableceSegundo( s );

} // fin de la funci�n estableceHora

// establece el valor de hora
void Tiempo::estableceHora1( int h ) 
{
   hora = ( h >= 0 && h < 24 ) ? h : 0; // Funciona como un if donde true va despues de "?" y else despues de ":"

} // fin de la funci�n estableceHora1

// establece el valor de minuto
void Tiempo::estableceMinuto( int m )
{ 
   minuto = ( m >= 0 && m < 60 ) ? m : 0; 

} // fin de la funci�n estableceMinuto

// establece el valor de segundo
void Tiempo::estableceSegundo( int s )
{ 
   segundo = ( s >= 0 && s < 60 ) ? s : 0; 

} // fin de la funci�n estableceSegundo

// devuelve el valor de hora
int Tiempo::obtieneHora1() 
{ 
   return hora; 

} // fin de la funci�n obtieneHora1

// devuelve el valor de minuto 
int Tiempo::obtieneMinuto() 
{
   return minuto; 

} // fin de la funci�n obtieneMinuto

// devuelve el valor de segundo 
int Tiempo::obtieneSegundo() 
{ 
   return segundo;
   
} // fin de la funci�n obtieneSegundo

// imprime Tiempo en formato universal
void Tiempo::imprimeUniversal()
{
   cout << setfill( '0' ) << setw( 2 ) << hora << ":"    
        << setw( 2 ) << minuto << ":"
        << setw( 2 ) << segundo;

} // fin de la funci�n imprimeUniversal

// print Time in standard format
// imprime Tiempo en formato est�ndar
void Tiempo::imprimeEstandar()
{
   cout << ( ( hora == 0 || hora == 12 ) ? 12 : hora % 12 )
        << ":" << setfill( '0' ) << setw( 2 ) << minuto
        << ":" << setw( 2 ) << segundo 
        << ( hora < 12 ? " AM" : " PM" );

} // fin de la funcion imprimeEstandar
void Tiempo::incrementaSegundos(const int cuenta )
{
   cout << "Incrementa segundo " << cuenta
        << " veces:\nHora inicio: ";
   imprimeEstandar();

   for ( int i = 0; i < cuenta; i++ ) {
      estableceSegundo( ( obtieneSegundo() + 1 ) % 60 );  

      if ( obtieneSegundo() == 0 )
         incrementaMinutos(1);

      cout << "\nsegundo + 1: ";
      imprimeEstandar();

   } // fin de for

   cout << endl;

} // fin de la funci�n incrementaSegundos

void Tiempo::incrementaMinutos(const int cuenta )
{
   cout << "Incrementa minuto " << cuenta
        << " veces:\nHora inicio: ";
   imprimeEstandar();

   for ( int i = 0; i < cuenta; i++ ) {
      estableceMinuto( ( obtieneMinuto() + 1 ) % 60 );  

      if ( obtieneMinuto() == 0 )
         incrementaHoras(1);

      cout << "\nminuto + 1: ";
      imprimeEstandar();

   } // fin de for

   cout << endl;

} // fin de la funci�n incrementaMinutos

void Tiempo::incrementaHoras(const int cuenta )
{
   cout << "Incrementa hora " << cuenta
        << " veces:\nHora inicio: ";
   imprimeEstandar();

   for ( int i = 0; i < cuenta; i++ ) {
      estableceHora1( ( obtieneHora1() + 1 ) % 24 );

      cout << "\nhora + 1: ";
      imprimeEstandar();

   } // fin de for

   cout << endl;

} // fin de la funci�n incrementaHoras


class Semana_Laboral {

   private:
      string nombre;             // nombre del empleado como string
      long int dni;              // dni del empleado como long int (por las dudas)
      Tiempo horarios[5][2];     // array de 5x2 que almacena datos de tipo tiempo
      
   public:
      Semana_Laboral(string name, long int doc);   // constructor que establece dni y nombre
      ~Semana_Laboral();                           // destructor
      void editarHorario(int dia, Tiempo tEntrada, Tiempo tSalida);  // cambia el horario de salida y entrada de un dia laboral, 1=lunes, 2=martes, etc
      void printHorasSemanales();      // imprime la cantidad de hs, min y seg semanales trabajadas en una semana
      void printHorario();             // imprime el array de horarios

};

Semana_Laboral::Semana_Laboral(string name, long int doc)
{
   cout << "\nConstructor de semana laboral \n";
   nombre = name;
   dni = doc;
}

Semana_Laboral::~Semana_Laboral()
{
   cout << "\nDestructor de semana laboral";
}

void Semana_Laboral::editarHorario(int dia, Tiempo tEntrada, Tiempo tSalida)
{
   int day = dia-1;                 // para que 1 modifique el primer elemento del arreglo debo restarle 1
   horarios [day][0] = tEntrada; 
   horarios [day][1] = tSalida;
}

void Semana_Laboral::printHorasSemanales()
{
   int segundosEnt = 0;          // inicializo las variables que voy a utilizar
   int segundosSal = 0;
   int segundosTrabajados = 0;
   int h, m, s;

   // resto la hora de salida en segundos con la hora de entrada en segundos para cada dia 
   // sumando todos los dias para obtener la cantidad de segundos trabajados esa semana

   for (int i=0; i<5; i++){ 
      segundosEnt = horarios[i][0].obtieneSegundo() + horarios[i][0].obtieneMinuto()*60 + horarios[i][0].obtieneHora1()*60*60;
      segundosSal = horarios[i][1].obtieneSegundo() + horarios[i][1].obtieneMinuto()*60 + horarios[i][1].obtieneHora1()*60*60;
      segundosTrabajados += segundosSal - segundosEnt;
   }

   // paso los segundos a horas, minutos y segundos y los imprimo
   // no creo un objeto de tipo tiempo porque este no permite un valor de hora
   // mayor a 24, lo que limita la cantidad de horas semanales posibles de trabajar

   h = (segundosTrabajados/60)/60;
   m = (segundosTrabajados - h*60*60)/60;
   s = segundosTrabajados - h*60*60 - m*60;
   cout << "\nEl tiempo total trabajado por semana es: " 
        << setfill( '0' ) << setw( 2 ) << h << ":"    
        << setw( 2 ) << m << ":"
        << setw( 2 ) << s;
}

void Semana_Laboral::printHorario()    // imprime el horario de entrada y de salida de todos los dias
{
   for (int i=0; i<5; i++) {
      cout << "\n";
      horarios[i][0].imprimeUniversal();
      cout << " ";
      horarios[i][1].imprimeUniversal();
   }
}

int main(int argc, char *argv[])
{ 
   /*

     Tiempo t(14,40,0),x,y(10);              // crea el objeto de Tiempo
      t.imprimeEstandar(); cout<<endl;
      x.imprimeEstandar(); cout<<endl;
      y.imprimeEstandar(); cout<<endl;
    
      //Tiempo *p= new Tiempo(11,11,11);
      //p->imprimeEstandar();cout<<endl;
      
   // establece la hora mediante funciones establece (set) individuales
   t.estableceHora1( 17 );     // establece hora en un valor v�lido
   t.estableceMinuto( 34 );   // establece minuto en un valor v�lido
   t.estableceSegundo( 25 );   // establece segundo en un valor v�lido

   // funciones obtener (get) para obtener hora, minuto y segundo
   cout << "Resultado de establecer todos los valores validos:\n" 
        << "  Hora: " << t.obtieneHora1()
        << "  Minuto: " << t.obtieneMinuto()
        << "  Segundo: " << t.obtieneSegundo();

   // establece hora mediante el uso de funciones individuales
   t.estableceHora1( 234 );     // establece hora no v�lida en 0
   t.estableceMinuto( 43 );    // establece minuto en un valor v�lido
   t.estableceSegundo( 6373 ); // establece segundo no v�lido en 0

   // despliega hora, minuto y segundo despu�s de establecer 
   // los valores no v�lidos de hora y segundo
   cout << "\n\nResultado del intento de establecer los valores no validos de minuto"
        << " y segundo:\n  Hora: " << t.obtieneHora1()
        << "  Minuto: " << t.obtieneMinuto()
        << "  Segundo: " << t.obtieneSegundo() << "\n\n";

   t.estableceHora( 11, 58, 0 );    // establece hora
   t.incrementaSegundos( 150 );  // incrementa los minutos de t en 3
   t.imprimeEstandar(); cout<<endl;



    cout<<endl<<endl;
*/
     

  Tiempo te, ts;
  te.estableceHora(8, 15, 30);               // Setea el horario de entrada de todos los dias
  ts.estableceHora(17, 5, 1);                // Setea el horario de salida de todos los dias
  Semana_Laboral sl("Santiago", 41080072);   // Crea la semana laboral dando un nombre y DNI
  for (int i = 0; i<5; i++){                 // Llena el array de los horarios
     sl.editarHorario(i+1, te, ts);
  }
  sl.printHorario();                         // Imprime los horarios semanales
  sl.printHorasSemanales();                  // Imprime la cant. de horas semanales trabajadas


    cout<<endl<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}

/*
Hacer una clase Semana_Laboral
que almacene:
el Nombre de un empleado
su documento
en un arreglo de 5 x 2 de tipo Tiempo la hora de ingreso y de salida de cada d�a
La clase debe tener m�todos para
setear la hora de ingreso y de salida para cada d�a
obtener el n�mero total de horas y minutos trabajados en la semana
todo otro m�todo que considere
*/
