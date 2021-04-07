//Transformacion de programas Recursivos a Iterativos:


#include <stdio.h>
#include <stdlib.h>

// Ejemplo: Sumar todos los numeros desde 0 hasta n           

int F1Recu(int n)						// Funcion f()
{
		if (n==0){						// Funcion d()
				return n;				// Funcion h()
		}
		else {
				int aux;
				aux = n+F1Recu(n-1);	// Funcion f(s())
				printf("\nRecu %d",aux);
				return aux;
		}
}

int F1Iter(int n)
{
		int aux=0;
		while(n!=0) {						// Funcion !d()
				aux+=n;						// Funcion s()
				printf("\nIter %d",aux);
				n--;
		}
		return aux;							// Funcion h()?????
}

void main()
{
		int n=10;
		F1Recu(n);
		F1Iter(n);
}
