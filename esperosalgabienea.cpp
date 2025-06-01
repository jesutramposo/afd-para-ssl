//automata finito determinista
#include <iostream>
#include <stdio.h>  //voy a hacer printf's a todo para ver si funciona xd 
using namespace std;  //extrañamente debo compilarlo como cpp por la extension <iostream>

int main (int argc, char *argv[]){

    enum teestado{  //por las dudas el enum nos sirve para enumerar los estados xddd
        q0,q1,q2,q3,q4,q5,q6,q7  //declaracion de los estados ya formados peviamente
    };

    teestado estado;
    
    string cadena; //esta variable voy a usar para guardar los caracteres cambien lo si quieren
    
    int simbolo, longitud, i; //nos va a servir para corroborar el largo de las cadenas
    //printf("holaaaaaaaaaaaaaaaaaaaaa esta linea funciona y fue creada por jesu");

    //simbolo lo uso para leer caracteres de la cadena leida y a i lo usare como un indice xd

    i = longitud = 0;

    estado = q0; //por aca empezamos a nuestro afd
    
    
    cout<<"ingrese la palabra o una convinacion: "<<endl; //una forma extraña de perdir las cosas pero 
    cin>> cadena; // funciona mejor y no creamos un bucle 'for' para leer los caracteres jijiji

    











    return 0; // no borren esto, recuerden que el menu esta definido como int, algo 
    //printf("");//debemos retronar



}