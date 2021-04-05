#include<stdio.h>

int fib(int );
void main()
{
	int n;
	printf("Ingrese un numero ");
	scanf("%d",&n);
	printf("\nEl numero %d en la serie de fibonacci es : %d",n,fib(n));
}

int fib(int n)
{
	int f1=0,f2=1,f;	//Se determinan los 2 primeros numeros de la serie
						//de fibonacci que son 0 y 1, f es el numero a 
						//calcular.
	if(n==0){			
		return 0;		//Si el numero ingresado es 0 o 1 devuelve 0 o 1
	}					//respectivamente.
	else if(n==1){
		return 1;
	}
	else {
		do{
			f=f1+f2;	//f es igual a la suma de los dos numeros previos
			f1=f2;		//f1 avanza al siguiente numero de la serie (f2)
			f2=f;		//f2 avanza al siguiente numero de la serie (f)
			n--;		//El indice n se resta en una unidad
		}while(n>1);	//Se deben realizar n-1 iteraciones para obtener
						//el n-esimo termino de la serie
	}
	
	return f;
}
