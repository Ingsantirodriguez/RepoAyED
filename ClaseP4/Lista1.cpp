// Listas_01.cpp 
//
#include <cstdlib>
#include <iostream>
#include <sstream>								// Libreria para usar ostringstream

using namespace std;

template <class T> class Nodo {
private:
    T dato;										// Dato del nodo
    Nodo* next;									// Puntero al siguiente nodo
public:
    Nodo() { next = NULL; };					// Constructor sin dato y con puntero a NULL
    Nodo(T a) { dato = a; next = NULL; };		// Constructor con dato especificado y puntero a null
    void set_dato(T a) { dato = a; };			// Setea el dato del nodo actual
    void set_next(Nodo* n) { next = n; };		// Setea a que otro nodo apunta el puntero
    T get_dato() { return dato; };				// Devuelve el dato almacenado
    Nodo* get_next() { return next; };			// Devuelve el puntero
    bool es_vacio() { return next == NULL; }	// Devuelve true si apunta a NULL
};

template <class T> class Lista {
private: Nodo<T>* czo;							// Objeto nodo inicial
public:
    Lista() { czo = new Nodo<T>(); };			// Constructor sin especificaciones. Crea un puntero a un obj nodo cuyo puntero next
												// apunta a null
    Lista(Nodo<T>* n) { czo = n; };				// Constructor especificando el nodo czo
    //~Lista(void);								// Destructor
    void add(T d);								// Crea un nuevo nodo con un dato d al principio de la lista
    bool esvacia(void);							// Devuelve true si la lista esta vacia
    T cabeza(void);								// Devuelve el dato que encabeza la lista
    Lista* resto(void);							// Devuelve un puntero a una lista encabezada a partir del segundo elemento
    string toPrint(string p);					// Imprime todos los elementos de la lista
    T suma(T i);								// Imprime la suma de los elementos de la lista
	int size();
	void borrar(void);
	void borrar_last();
	void concat(Lista<T>* l1);
	Lista* copy(void);
	void tomar(int n);
};
template <class T>
void Lista<T>::add(T d)
{
    Nodo<T>* nuevo = new Nodo<T>(d);			// Crea un puntero tipo nodo que apunta a un nodo que tiene el dato d
    nuevo->set_next(czo);						// El puntero next del nuevo nodo apunta a la direccion donde apunta czo, que es la
												// del nodo que esta al tope de la lista y es tambien el mas reciente.
    czo = nuevo;								// czo apunta ahora al nodo recientemente creado.
}
template <class T>
bool Lista<T>::esvacia(void)
{
    return czo->es_vacio();						// Retorna true si czo apunta a NULL
}
template <class T>
T Lista<T>::cabeza(void)
{
    if (esvacia()) {
        cout << " Error, Cabeza de lista vacia";
        return NULL;
    }
    return czo->get_dato();						// Si czo apunta a un nodo, se devuelve el dato de este.
}

template <class T>
Lista<T>* Lista<T>::resto(void)					// Devuelve un puntero a una lista que comienza con el segundo nodo.
{
    Lista* l = new Lista(czo->get_next());		// Lo hace creando una lista donde czo apunta al segundo elemento
    return (l);
}

template <class T>
string Lista<T>::toPrint(string p)				// Funcion recursiva que imprime todos los elementos de la lista. Donde p es el
{												// mensaje al terminar de imprimir la lista.
    if (this->esvacia()) {						// Si la lista esta vacia retorna el mensaje. Tambien es el caso base.
        return p;
    }
    else {
        //std::ostringstream stm;
        ostringstream stm;
        stm << this->cabeza() << "-" << this->resto()->toPrint(p) << endl; // Imprime el primer elemento y despues recursivamente
        //cout<<endl<<" stm.str()= "<<stm.str()<<endl;					   // sigue imprimiendo los demas elementos con la funcion
        return stm.str();												   // resto().
    }
}

template <class T>
T Lista<T>::suma(T i)										// Suma recursivamente los elementos de la lista
{   
	//cout<<" i al entrar= "<<i<<endl;
    if (this->esvacia()) {									// Caso base
        return i;
    }
    else {

        //cout<<"this->cabeza()= "<<this->cabeza()<<endl;   
        return this->resto()->suma(i + this->cabeza());		// Le aplica la funcion suma al resto de la lista actual pasandole la
    }														// cabeza de la lista actual como parametro.
}

/*//////////////////////////
// Empiezan los Ejercicios//
*///////////////////////////

template <class T>
int Lista<T>::size()
{
	int aux=0;
    Lista<T>* l2 = this;	// Crea un puntero a la lista en la que estamos trabajando	
	while(!l2->esvacia()){	// Mientras esta lista no sea vacia ejecuta
		aux += 1;			// aumenta la variable aux que lleva la cuenta del numero de nodos 
		l2=l2->resto();		// Usa la funcion resto para que la lista comience con el siguiente elemento
	}
	return aux;
}

template <class T>
void Lista<T>::borrar(void)
{
	if (this->esvacia()){									// Si la lista es vacia no borra nada y tira un mensaje
		cout << "Lista vacia, nada que borrar" << endl;
	}
	else {
		Nodo<T>* cabeza = czo;		// Crea un puntero a un nodo que apunta a czo
		czo=czo->get_next();		// czo ahora apunta al segundo elemento de la lista
		delete cabeza;				// Se borra el primer elemento
	}
}

template <class T>
void Lista<T>::borrar_last()
{
	if (this->esvacia()){
		cout << "Lista vacia, nada que borrar" << endl;
	}
	else {
		int size=this->size();
		Nodo<T>* aux = czo;
		while (size>1){				// Mientras el tamano de size sea mayor a 1, aux apunta al siguiente nodo
			aux=aux->get_next();	// de esta manera al llegar al ultimo elemento (size==1) lo borra.
			cout << aux->get_dato()<< endl;
			size--;
		}
		delete aux->get_next();
		aux->set_next(NULL);
	}
}

template <class T>
void Lista<T>::concat(Lista<T>* l1)
{
	while (!l1->esvacia()){			// Mientras la lista pasada como parametro (l1) no sea vacia, se agrega el primer elemento
		this->add(l1->cabeza());	// de l1 a la lista this y luego setea al segundo elemento como primero (funcion resto()) 
		l1 = l1->resto();			// Asi, al salir del while() ya se copiaron todos los valores de l1 en la lista this.
	}
}

template <class T>
Lista<T>* Lista<T>::copy(void)			// Devuelve una copia de la lista
{
	Lista<T>* l1 = new  Lista<T>();		// Crea la lista donde se va a copiar todo
	Nodo<T>* node = this->czo;			// Este nodo va recorriendo la lista this
	int size = this->size();
	while (size>0){
		l1->add(node->get_dato());		// Se agrega a l1 el dato en node
		node = node->get_next();		// node ahora apunta al siguiente elemento de la lista
		size--;
	}
	return l1;							// Se devuelve la lista
}

template <class T>
void Lista<T>::tomar(int n)
{
	int i=this->size();					// La variable i es el tamanio de la lista
	while (i>n){						// Mientras el tamanio de la lista sea mayor al numero pasado como parametro
		this->borrar_last();			// borra el ultimo elemento de la lista. Cuando i==n sale del bucle
		i --;						
	}									// Cuando i==n sale del bucle
}

int main()
{
	Lista<string>* l = new Lista<string>();
	Lista<string>* l1 = new Lista<string>();
	l->add(" 11x");
	l->add(" 22y");
	l->add(" 33z");
	l->add(" 44a");
	l->add(" 55b");
	cout << "l= "<<l->toPrint("fin") << endl;
	cout << "size of l = " << l->size() << endl;
	l->borrar();	// Debe borrar 55b
	cout << "Luego de borrar()" << endl << " l= "<<l->toPrint("fin") << endl;
	l->borrar_last(); // Debe borrar 11x
	cout << "Luego de borrar_last()" << endl << " l= "<<l->toPrint("fin") << endl;
	l1->add(" 11x");
	l1->add(" 55b");
	l->concat(l1);	// Deben aparecer 11x y 55b en l
	cout << "Luego de concat(l1) si l1 tiene 11x y 55b " << endl << "l= "<<l->toPrint("fin") << endl;
	l->tomar(3);
	cout << "Luego de toma(3)" << endl << "l= "<<l->toPrint("fin") << endl;
    system("PAUSE");
    return EXIT_SUCCESS;

}

/*
int size();// cantidad de nodos de la lista // Hecho
void borrar(void); //borra la cabeza // Hecho
void borrar_last();//borra el ultimo // Hecho
void concat(Lista* l1);// le transfiere los datos de l1 a this // Hecho
Lista* copy(void);// hace una copia de la lista // Hecho
void tomar(int n);//deja "vivos" los n primeros nodos y borra el resto // Hecho
*/
