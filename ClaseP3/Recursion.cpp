#include <cstdlib>
#include <iostream>

using namespace std;

void impre(int v[],int n);

int main(int argc, char *argv[])
{   
    int v[6]={17,15,-8,30,5,-2};
    
	cout<<"impre vector"<<endl; impre(v,5);    
   
        system("PAUSE");
    return EXIT_SUCCESS;
}
                                    // El nombre de un arregle es un puntero al primer elemento del arreglo
void impre(int v[],int n)           // Escribir v[] es lo mismo que *v. v es un puntero local de la funcion impre
{   if(n==0)cout<<v[n]<<endl;       // Caso base, corta la recursion
    else{ 
          //cout<<"estoy yendo";
          //cout<<v[n]<<endl;
          impre(v,n-1);
          //cout<<"estoy retornando"<<endl;
          cout<<v[n]<<endl;
          
          
    } 
}

