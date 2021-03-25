#include <cstdlib>
#include <iostream>

using namespace std;

int suma(int v[],int n);
int mayor(int v[],int n);
int prod(int o1, int o2);

int main(int argc, char *argv[])
{   
    int v[6]={17,15,-8,30,5,-2};
    
	// cout<<"suma vector"<<endl; 
    // suma(v,5); 
    // cout<<"mayor"<<endl;
    // mayor(v,5);  
    cout<<"multiplicacion"<<endl;
    prod(10,7);  
   
        system("PAUSE");
    return EXIT_SUCCESS;
}

int suma(int v[], int n)
{
    int sumaa = 0;
    if(n==0)
    {
        sumaa = v[n];
    }
    else
    {
        sumaa = v[n] + suma(v, n-1);
    }
    cout<<sumaa<<endl;
    return sumaa;
}

int mayor(int v[], int n)
{
    int may;
    if(n==0)
    {
        may=v[n];
    }

    else
    {
        may = mayor(v,n-1);
        if(v[n]>may)
        {
            cout<<v[n]<<endl;
            return v[n];
        }
    }
    cout<<may<<endl;
    return may;
}

int prod(int o1, int o2)
{
    int i = o1;
    int aux = 0;
    if(i==1)
    {
        aux = o2;
    }
    else
    {
        aux = o2 + prod(o1-1,o2);
    }
    cout<<aux<<endl;
    return aux;
}

