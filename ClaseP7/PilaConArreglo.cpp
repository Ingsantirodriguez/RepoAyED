#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

template <class T> class Pila {
	private:
		T d[MAX];
		int p;
	public:
		Pila() {p=-1;};
		void apilar(T x) {d[++p] = x};	// p++ primero toma a p, y luego lo suma
		T tope(void) {return d[p]};
		void desapilar(void) {p--;};	// ++p toma a p ya sumado
		bool pilaVacia() {return p==-1;};
};


int main()
{
		Pila<char> p = new Pila<char>();
		p.apilar('s');	
		p.apilar('a');
		p.apilar('n');
		p.apilar('t');
		p.apilar('i');
		return 0;
}
