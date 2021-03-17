#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N_PS 4

typedef struct {                // Se define un tipo compuesto llamado FECHA, la cual contiene 3 int
       int dia;
       int mes;
       int anio;
} FECHA;

typedef struct {
       char nombre[20];         // Tira de caracteres (string)
       FECHA nac;               // Fecha
       long int dni;
} persona;

void printfecha(FECHA *f){
     printf("dia:%d - mes:%d - anio:%d\n",f->dia,f->mes,f->anio);
}

void printpersona(persona *p){                                      // *p apunta al primer elemento de p1 o pp1
    printf("nombre %s,dni %ld,nac:",p->nombre,p->dni);
    printfecha(&(p->nac));
}

void cargar_ps(persona *ps){
     int i;
     for(i=0;i<N_PS;i++){
        strcpy((ps+i)->nombre,"Luisa Castro");
        (ps+i)->dni=10998760+i;
        (ps+i)->nac.dia=10+i;
        (ps+i)->nac.mes=2;
        (ps+i)->nac.anio=1980;
     }
}

void print_ps(persona *ps){
     int i;
     for(i=0;i<N_PS;i++){
         printpersona(ps+i);
     }
}

int main(int argc, char *argv[])
{
     FECHA f1, f2;              // Se definen 2 fechas
     persona p1;                // Se define una persona 
     persona *pp1;              // Se define un puntero tipo persona
	        
     pp1=(persona *)malloc(sizeof(persona));        // Se busca memoria para guardar un tipo persona y se lo convierte a puntero persona

     f1.dia=12;f1.mes=3;f1.anio=1999;               // Para cargar informacion en un objeto se usa el punto "."
     f2.dia=12;f2.mes=11;f2.anio=1998;
     strcpy(p1.nombre,"Juan Lopez");
     p1.dni=12445099;
     p1.nac.dia=1;
     p1.nac.mes=12;
     p1.nac.anio=1999;
// Como agrego datos en el puntero?
     strcpy(pp1->nombre,"Luisa Castro");            // Se usa el operador flecha "->"
     pp1->dni=10998760;
     pp1->nac.dia=10;                               // La flecha se usa solamente una vez
     pp1->nac.mes=2;
     pp1->nac.anio=1980;

     printpersona(&p1);                             // Imprime los datos de Juan Lopez
     printpersona(pp1);                             // Imprime los datos de Luisa Castro
     free(pp1);                                     // Libera espacio en la memoria heap
//   system("PAUSE");

     persona *ps;
						  
     ps=(persona *)malloc(sizeof(persona)*N_PS);
     cargar_ps(ps);
     print_ps(ps);
     free(ps);
//   system("PAUSE");

     return 0;
}
