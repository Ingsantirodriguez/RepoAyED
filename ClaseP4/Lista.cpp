#include <cstdlib>						
#include <iostream>
#include <iomanip>

using namespace std;

class Lista{
      private:
              int d;					// Dato que contiene cada nodo de la lista
              Lista *next;				// Puntero que tiene cada nodo, apunta al siguiente elemento de la lista
      public:
             Lista();					// Constructor
             void add(int x);			// Agrega un nuevo nodo a la lista 
			 void addLast(int x);
             void impre(void);
             bool empty(void);
};

Lista::Lista()
{     next=NULL;
}      

bool Lista::empty(void)
{  
		return next==NULL;				// Si el puntero inicial de la lista apunta a NULL (lista vacia), devuelve true
}

void Lista::add(int x)
{     Lista *aux;						// Se crea un puntero de tipo Lista 
      aux= new Lista;					// Se crea un objeto lista vacio al cual el puntero *aux apunta
      aux->d=x;							// En el nuevo abjeto lista se carga el valor de dato deseado
      aux->next=next;					// El puntero next del nuevo objeto lista creado ahora apunta a la misma direccion
	  									// que el puntero next del objeto Lista l. Si es el primer nodo creado apunta a NULL
										// si no, apunta al ultimo nodo creado.
      next=aux;							// next ahora apunta al nuevo objeto lista
}

void Lista::addLast(int x)
{
		Lista *aux;						
		if(this->empty()){					// Si la lista es vacia agrega un nodo con el metodo normal
				add(x);
		}
		else {								// Sino
				while(aux->next!=NULL){		// Mientras el puntero next del siguiente elemento NO apunte a NULL
						aux=aux->next;		// aux apunta al elemento siguiente en la lista
				}							// Al llegar al ultimo elemento se realiza lo siguiente
				aux->next= new Lista;		// El puntero next del ultimo elemento apunta a un nuevo elemento.
				aux=aux->next;				// Ahora aux apunta al recien creado ultimo elemento.
				aux->d=x;					// Le doy el valor deseado al ultimo elemento.
				}
}

void Lista::impre(void)
{      Lista *aux;										// Se crea un puntero de tipo Lista 
       if(!this->empty()){								// Si la lista no es vacia, ejecuta.
           aux=next;									// aux apunta al primer objeto o nodo de la lista
           while(aux!=NULL){							// Mientras aux!=NULL (ultimo objeto) ejecuta.
                        cout<<endl<<setw(4)<<aux->d;	// Imprime el dato del objeto actual.
                        aux=aux->next;					// Pasa al siguiente eobjeto de la lista.
                        }
       }   
       else cout<<"LISTA VACIA";              			// Imprime LISTA VACIA
}

int main(int argc, char *argv[])
{   Lista l;						// Crea el objeto lista inicial, este no tiene ningun dato y apunta a null
    l.impre();
    l.add(5);
    l.add(9);
    l.add(-3);
	l.addLast(7);
	l.addLast(8);
	l.addLast(9);
    l.impre();
    cout<<endl<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
