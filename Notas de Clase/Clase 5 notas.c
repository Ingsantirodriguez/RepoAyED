/*
Transformacion de un programa recursivo simple a un 
programa iterativo:

f es una funcion recursiva a la cola
f: T1xT2 -> T3

T1 es producto cartesiano de los dominios que no varian de
llamada en llamada recursiva.

T2 es producto cartesiano de los dominios que varian de
llamada en llamada recursiva.

T3 es el producto cartesiano de los dominios de la imagen.

t1:T1, t2:T2, t3:T3 quiere decir x:Natural, y:Racional  

f(t1,t2) = { h(t1,t2)	   si	d(ti,t2)
			 f(t1,s(t1,t2) si	!d(t1,t2)

d: T1 x T2 -> Booleano
h: T1 x T2 -> T3
s: T1 x T2 -> T2

Programa recursivo a la cola:

t3 f(t1,t2) {
	if(d(t1,t2))
			return h(t1,t2)
	else
			return f(t1,s(t1,t2))
}

Mismo programa Iterativo:

t3 f(t1,t2) {
	while !(d(t1,t2)) {
			t2 = s(t1,t2)
	}
	return h(t1,t2)
}

Ejemplo:
Mayor en un Arreglo:

		Version Recursiva:

		T1:Nat[] x Nat
		T2:Nat x Nat

		f(a[int]) -> int

		f(a[]) = faux(a[],SIZE:int,i:int,max:int)

		faux(a,Size,i,max) = {max							si	i==n
							  faux(a,SIZE,i+1,max(m,a[i]))	si	i<n
							 }

		s(a,SIZE,i,max) = (i+1, max(m,a[i]))

		max(x,y) = { x si x>y
					 y si x<=y
				   }

		d(x,SIZE) = (x<=SIZE)

		faux(a,SIZE,i,m) {
			if (i==n) {
				return m;
			}

			else {
				return (a,SIZE,i+1,max(m,a[i]));
			}
		}

		Version Iterativa:

		n>1;
		i=0;
		m=a[0];
		while (i!=SIZE) {
			if (a[i]>m) {
				m = a[i];
			}
			i++;
		}

Secuencia biotonica si, tiene dos subsecuencias monotonicas invertidas?????????
