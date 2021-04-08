// Listas_01.cpp 
//
#include <cstdlib>
#include <iostream>
#include <sstream>

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
    Lista() { czo = new Nodo<T>(); };			// Constructor sin especificaciones
    Lista(Nodo<T>* n) { czo = n; };				// Constructor especificando el nodo czo
    //~Lista(void);								// Destructor
    void add(T d);								// Crea un nuevo nodo con un dato d al principio de la lista
    bool esvacia(void);							// Devuelve true si la lista esta vacia
    T cabeza(void);								// Devuelve el dato que encabeza la lista
    Lista* resto(void);							// Devuelve un puntero a una lista encabezada a partir del segundo elemento
    string toPrint(string p);					// Imprime todos los elementos de la lista
    T suma(T i);								// Imprime la suma de los elementos de la lista
};
template <class T>
void Lista<T>::add(T d)
{
    Nodo<T>* nuevo = new Nodo<T>(d);			// Crea un puntero tipo nodo que apunta a un nodo que tiene el dato d
    nuevo->set_next(czo);						// El puntero next del nuevo nodo apunta a czo
    czo = nuevo;								// Ahora el nuevo nodo creado es el czo 
}
template <class T>
bool Lista<T>::esvacia(void)
{
    return czo->es_vacio();
}
template <class T>
T Lista<T>::cabeza(void)
{
    if (esvacia()) {
        cout << " Error, Cabeza de lista vacia";
        return NULL;
    }
    return czo->get_dato();
}

template <class T>
Lista<T>* Lista<T>::resto(void)
{
    Lista* l = new Lista(czo->get_next());
    return (l);
}

template <class T>
string Lista<T>::toPrint(string p)
{
    if (this->esvacia()) {
        return p;
    }
    else {
        //std::ostringstream stm;
        ostringstream stm;
        stm << this->cabeza() << "-" << this->resto()->toPrint(p) << endl;
        //cout<<endl<<" stm.str()= "<<stm.str()<<endl;
        return stm.str();
    }
}

template <class T>
T Lista<T>::suma(T i)
{    //cout<<" i al entrar= "<<i<<endl;
    if (this->esvacia()) {
        return i;
    }
    else {

        //cout<<"this->cabeza()= "<<this->cabeza()<<endl;   
        return this->resto()->suma(i + this->cabeza());
    }
}

int main()
{
    Lista<string>* l = new Lista<string>();
    Lista<int>* r = new Lista<int>();
    Lista<string>* l2 = new Lista<string>();
    l->add(" 11x");
    l->add(" 22y");
    l->add(" 33z");
    r->add(100);
    r->add(22);
    cout << "l= "<<l->toPrint("fin") << endl;
    cout << "r= " << r->toPrint("fin") << endl;
    cout << "suma:" << r->suma(0) << endl;

    system("PAUSE");
    return EXIT_SUCCESS;

}

/*
int size();// cantidad de nodos de la lista
void borrar(void); //borra la cabeza
void borrar_last();//borra el ultimo
void concat(Lista* l1);// le transfiere los datos de l1 a this
Lista* copy(void);// hace una copia de la lista
void tomar(int n);//deja "vivos" los n primeros nodos y borra el resto
*/
