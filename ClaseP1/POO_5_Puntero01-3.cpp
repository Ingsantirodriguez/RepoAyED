#include <cstdlib>
#include <iostream>

using namespace std;
//void swap(int,int);
//void swap(int *a, int *b);                  // Pasaje de parametros por valor
void swap(int &a, int &b);                    // Al definirlo asi se hace un pasaje por referencia

int main(int argc, char *argv[])
{   int x,y;
    int *px,*py;
    x=55; y=-22;
    /*
    cout<<"\n x="<<x;
    cout<<"\n y="<<y;
    cout<<"\n tama�o entero= "<<sizeof(int);
    px=&x; py=&y;                             // Se le asigna la direccion de x al puntero px, idem con y, py
    cout<<"\n px="<<px;
    cout<<"\n py="<<py;
    cout<<"\n *px="<<*px;
    cout<<"\n *py="<<*py;
    *px=7; cout<<"\n *px="<<*px<<"  x="<<x;   // Modificando *px modifico x
    
    py=px; cout<<"\n *py="<<*py<<"  y="<<y;   // Ahora py apunta a la direccion de x

    cout<<"\n px="<<px;
    cout<<"\n py="<<py;
    py++;                                     // *py ahora apunta a "y" ya que este se encuentra un lugar de memoria mas adelante 
    */

    cout<<endl<<"----------------------";
    cout<<"\n x="<<x<<"  y="<<y;
    swap(x,y);
    cout<<"\n x="<<x<<"  y="<<y;
     cout<<endl<<"----------------------";
    

    /*
     int v[5]={23,1,-8,14,7};
     px=&v[0];   py=v;                      // El nombre de un arreglo es un puntero cte. al primer elemento del arreglo
                                            // *px y *py  apuntan ambos a &v[0]==v
     cout<<"\n *px="<<*px<<"  *py="<<*py;
     cout<<"\n  px="<<px<<"  py="<<py;
     
     for(int i=0;i<5;i++){
         cout<<endl<<px[i]<<"  "<<*(px+i)   // px==v, px no cambia // muestra el contenido del primer elemento incrementado 
             <<"  "<<*(v+i)<<"  "<<*py++;   // // Primero muestra el contenido y luego se incrementa la direccion
     }
     cout<<endl<<"px= "<<px;
     cout<<endl<<"v= "<<v;
     cout<<endl<<"py= "<<py;
     */
     
         
    cout<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}

/*
void swap(int a, int b)
{ int c;
  cout<<"\n a="<<a<<"  b="<<b;
  c=a; a=b; b=c;
  cout<<"\n a="<<a<<"  b="<<b;   
     
}
void swap(int *a, int *b)
{ int c;
  cout<<"\n a="<<*a<<"  b="<<*b;
  c=*a; *a=*b; *b=c;
  cout<<"\n a="<<*a<<"  b="<<*b;   
     
}
*/
void swap(int &a, int &b)                   // La sintaxis de la funcion es la misma que la primera
{int c;
  cout<<"\n a="<<a<<"  b="<<b;
  c=a; a=b; b=c;
  cout<<"\n a="<<a<<"  b="<<b;   
}

  
