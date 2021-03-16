#include <stdio.h>
#include <iostream>
#include <sstream>

using namespace std;
// declaracion de la clase
class Fracc {
    protected:
            int num,den;
    public:
            Fracc(int nn=1, int dd= 1);
            ~Fracc();// Alt 126 = ~
            void set(int x, int y);
			string toString();
			Fracc sum(Fracc a);
			Fracc mul(Fracc a);
};

Fracc::Fracc(int nn,int dd)                 // Constructor de la clase Fracc, num==1, den==1
{   cout << "Soy el constructor" << endl;
    num=nn; den=dd;
}
Fracc::~Fracc()                             // Destructor de la clase Fracc
{
  cout << "\n soy el DESTRUCTOR de Fracc";
}
void Fracc::set(int x, int y){              // Metodo para setear num y den
     num=x;den=y;
}
Fracc Fracc::sum(Fracc a){                  // Metodo de suma, suma la fraccion con otra fraccion "a"
      Fracc aux;                                // Crea la fraccion "aux" que es la que se va a devolver
      aux.set(num*a.den+a.num*den,a.den*den);   // num1*den2+num2*den1/den1*den2 (suma de fracciones comun)
      return aux;      
}

Fracc Fracc::mul(Fracc a){                      // Metodo de mult, multiplica la fraccion con otra ()
      Fracc aux;
      aux.set(num*a.den,den*a.num);             // num1*den2/den1*num2 (multiplica cruzado)
      return aux;      
}

string Fracc::toString(){
    std::ostringstream stm;
    stm << num<<'/'<<den <<endl;

    return stm.str();
}

class Mixto: public Fracc {
	
    public:

            Mixto(int e=0,int n=1, int d=1):Fracc(e*d+n,d) {};
            ~Mixto();// Alt 126 = ~
            void set(int e, int x, int y);
			string toString();
/*			Tarea: implementar ambas llamando al metodo de la super-clase
			Mixto sum(Mixto a);
			Mixto mul(Mixto a);
*/
};

Mixto::~Mixto()
{
  cout << "\n soy el DESTRUCTOR de Mixto";
}
void Mixto::set(int e, int x, int y){
     Fracc::set(e*y+x,y);
}

string Mixto::toString(){
    std::ostringstream stm;
    int ent=0;
    int res=num;
    while (res>den) {
       ent++;res-=den;
    }
    stm << ent <<'-'<<res<<'/'<<den <<endl;

    return stm.str();
}


int main(int argc, char *argv[])
{
    int cc;
    Fracc a,b(3,6),c,*d;
    c=a.sum(b);
    cout<<"\nA:"+ a.toString()<<"\nB:"+ b.toString()<<"\nA+B:"+ c.toString()<<"\n";
    
    d=new Fracc(2,5);
    c=d->sum(a);
    cout<<"\nA:"+ a.toString()<<"\nD:"+ d->toString()<<"\nA+D:"+ c.toString()<<"\n";
    c=d->mul(b);
    cout<<"\nD:"+ d->toString()<<"\nB:"+ b.toString()<<"\nD*B:"+ c.toString()<<"\n";
//    system("PAUSE");
    while ((cc=getchar()) != '\n') {}    
    Mixto m1(4,5,6);
    Mixto m2(3,1,3);
    cout<<"\nM1:"+ m1.toString()<<"M2:"+ m2.toString()<<"\n";
/*    
    Mixto m3;
    m3=m1.sum(m2);
    cout<<"\nM1+M2:"+ m3.toString()<<"\n";
*/ 
//    system("PAUSE");
    while ((cc=getchar()) != '\n') {}
//    return EXIT_SUCCESS;
    return 0;
}
