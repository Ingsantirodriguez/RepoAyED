#include <stdio.h>
#include <stdlib.h>

/*
int fact(int n)
{
	int aux=0;

	if(n<1){
		return 1;
	}

	else{
		aux=n*fact(n-1);
		printf("\n %d",aux);
		return aux;
	}
}
*/

/*
typedef struct {
	int cociente;
	int resto;
} po;

po divEnt(int dv, int dr, int co)
{
	po aux;
	aux.cociente = co;
	aux.resto = 0; 
	if(dv<dr){
		aux.resto = dv;
		printf("\n Cociente=%d, Resto=%d",aux.cociente,aux.resto);
		return aux;
	}
	else{
		return divEnt(dv-dr,dr,co+1);
	}
}
*/

int fiboMulti(int n)
{
	int aux=0;
	if(n<3){
		return 1;
	}
	else{
		aux = fiboMulti(n-1)+fiboMulti(n-2);
		printf("\n %d ",aux);
		return aux;
	}
}

int fiboSimple2(int y, int a1, int a2, int x)
{
	if (y==x){
		return a1+a2;
	}
	else {
		return fiboSimple2(y+1,a1+a2,a1,x);
	}
}

int fiboSimple(int n)
{
	int aux=0;
	if (n<=2){
		return 1;
	}
	else{
		aux = fiboSimple2(3,1,1,n);
		printf("\n %d",aux);
		return aux;
	}	
}

int main()
{
//	fact(6);
/*
	int dividendo, divisor;
	printf("\n Dividendo = ");
	scanf("%d",&dividendo);
	printf("\n Divisor = ");
	scanf("%d",&divisor);
	divEnt(dividendo,divisor,0);
*/
	int fibo;
	printf("\n Fibonacci Multiple ");
	scanf("%d",&fibo);
	fiboMulti(fibo);
	printf("\n Fibonacci Simple ");
	fiboSimple(fibo);
	return 0;
}

