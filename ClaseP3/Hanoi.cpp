#include <cstdlib>
#include <iostream>

using namespace std;

void hanoi(char a, char c, char b, int n);

int main(int argc, char *argv[])
{   
    hanoi('a','c','b',4); 
   
        system("PAUSE");
    return EXIT_SUCCESS;
}

void hanoi(char a, char c, char b, int n)	// La funcion mueve el disco actual de la posicion en el primer parametro a la del segundo parametro
{
    if(n>0){
        hanoi(a,b,c,n-1);					//mover los n-1 primeros discos de a >> b
        cout<<"Mover "<<n<<" desde "<<a<<" hasta "<<c<<endl;    //el ultimo disco lo muevo de a >> c
        hanoi(b,c,a,n-1);					// mover los n-1 primeros discos de b >> c
     }
}
