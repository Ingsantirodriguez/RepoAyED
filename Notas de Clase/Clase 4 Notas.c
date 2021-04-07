Clase Teorica 4
Recursion:

f(x)=.....f()...

Condiciones:

1) Condicion de corte de la recursion
2) Garantizar que la condicion se alcance

Funcion definida por tramos:

f(x) = { ....  Condicion de corte se da  
	..f..  si no de da el corte
	}
Ej: 
	fact(x) = { 1		si x = 1
		    x*fact(x-1) si x > 1
		  }
//x es natural

Recursion Simple: existe una unica llamada a la funcion del cuerpo

	f = ... f ... para cada

Recursion Multiple:

	f = ... f ... f ...

Ventaja: Escribir en forma compacta una formula, y a veces es mas simple, o la unica forma de formular

Despliegue de la recursividad:

fact(5) = 5 * fact(4)
	= 5 * 4 * fact(3)
	.
	.
	= 5 * 4 * 3 * 2 * 1
	= 5 * 4 * 3 * 2
	= 5 * 4 * 6
	= 5 * 24
	= 120
Division Entera:

13/4 = 3, resto 1. Esto es porque 13 = 4*3 + 1

13 dividendo	(dv)
4  divisor		(dr)
3  cociente		(co)
1  resto		(re)

// Testear los siguientes programas.

Programa:

int divEnt(int dv,int dr,int co)

struct po {
	int cociente;
	int resto;
}

void main()
{
	par_ord = divEnt(dv,dr,0);
}

int divEnt(dv,dr,co)
{
	if(dv<dr){
		return (dv,co);
	}
	else{
		divEnt(dv-dr,dr,co+1);
	}
}

Ejemplo: Secuencia de Fibonacci


f(x)=1	x == 1
	=1	x == 2
	=f(x-1)+f(x-2)	x>2

int fib(x)
{
	if(x<=2){
		return 1;
	}
	else{
		return fib(x-1)+fib(x-2);
	}
}

Alternativa con recursividad simple:

int fib2(int y, int a1, int a2, int x){
	if (y==x){
		return a1+a2;
	}
	else {
		return fib2(y+1,a1+a2,a1,x);
	}

int fib(int x){
	if (x<=2){
		return 1;
	}
	else {
		return fib2(3,1,1,x);
	}
}

// TAREA: FIBONACCI ITERATIVO
