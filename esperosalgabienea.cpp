///automata finito determinista

//jesu
#include <iostream>
#include <stdio.h>  //voy a hacer printf's a todo para ver si funciona xd 
using namespace std;  //extrañamente debo compilarlo como cpp por la extension <iostream>
// el std es por una movida de incluirlo asi de hecho

int main (int argc, char *argv[]){

    enum teestado{  //por las dudas el enum nos sirve para enumerar los estados xddd 
        q0,q1,q2,q3,q4,q5,q6,q7,qd  //declaracion de los estados ya formados peviamente
    };
    //el enum es una manera mas sencilla para dar a definir variables

    teestado estado;
    
    string cadena; //esta variable voy a usar para guardar los caracteres cambien lo si quieren
    
    int simbolo, longitud, i; //nos va a servir para corroborar el largo de las cadenas
    //printf("holaaaaaaaaaaaaaaaaaaaaa esta linea funciona y fue creada por jesu");

    //simbolo lo uso para leer caracteres de la cadena leida y a i lo usare como un indice xd

    i = longitud = 0;

    estado = q0; //por aca empezamos a nuestro afd
    
    
    cout<<"ingrese la palabra o una combinacion: "<<endl; //una forma extraña de perdir las cosas pero 
    cin>> cadena; // funciona mejor y no creamos un bucle 'for' para leer los caracteres jijiji
    //hasta aca hice (jesu)
 
    longitud = cadena.size(); // puede ser longitud cadena asi se entiende mejor

    while(longitud > i){

        simbolo = cadena[i]; //aca tomamos el valor de la cadena para comparar
        switch(estado){

            case q0:
                if (simbolo == 'A' || simbolo == 'a'){
                    estado = q1;
                }
                
                else { 
                    estado = qd;
                }break;

            case q1:
                if (simbolo == 'A' || simbolo == 'a'){  // esto se hace por cada estado
                    estado = q2;  //ahora tenemos que ver que tablita queremos que haga
                }else{
                    estado = qd;
                }break;
            case q2:
                if (simbolo == 'A' || simbolo == 'a'){
                    estado = q3;
                }
                else{
                    estado = qd;
                }break;
            case q3:
                if (simbolo == 'B' || simbolo == 'b'){
                    estado = q4;
                }
                else{
                    estado = qd;
                }break;
            
            case q4:
                if (simbolo == 'B' || simbolo == 'b'){
                    estado = q5;
                }
                else{
                    estado = qd;
                }break;
            case q5:
                if (simbolo == 'A' || simbolo == 'a'){
                    estado = q6;
                }
                else{
                    estado = qd;
                } break;
            case q6:
                if (simbolo == 'B' || simbolo == 'b'){
                    estado = q7;
                }
                else{
                    estado = qd;
                    
                }break;
            case q7:
                estado = qd;  // cualquier input extra lo manda al estado muerto :D
                break;
        

           

            
        }
        
        i++; // importantisimo incrementar la variable
        

    }
    if(estado == q7 && i == longitud) cout << "Cadena válida\n";
    else cout << "Cadena no válida\n";



    return 0; // no borren esto, recuerden que el menu esta definido como int, algo 
    //printf("");//debemos retornar algo
}
