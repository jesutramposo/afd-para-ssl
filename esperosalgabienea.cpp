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
                if (simbolo == 'C' || simbolo == 'o'){
                    estado = q1;
                }
                
                else { 
                    estado = qd;
                }break;

            case q1:
                if (simbolo == 'O' || simbolo == 'o'){  // esto se hace por cada estado
                    estado = q2;  //ahora tenemos que ver que tablita queremos que haga
                }else{
                    estado = qd;
                }break;
            case q2:
                if (simbolo == 'V' || simbolo == 'v'){
                    estado = q3;
                }
                else{
                    estado = qd;
                }break;
            case q3:
                if (simbolo == 'I' || simbolo == 'i'){
                    estado = q4;
                }
                else{
                    estado = qd;
                }break;
            
            case q4:
                if (simbolo == 'D' || simbolo == 'd'){
                    estado = q5;
                }
                else{
                    estado = qd;
                }break;
            case q5:
                if (simbolo == '1'){
                    estado = q6;
                }
                else{
                    estado = qd;
                } break;
            case q6:
                if (simbolo == '9'){
                    estado = q7;
                }
                else{
                    estado = qd;
                    
                }break;
              case q7:
                if((simbolo >= '0' && simbolo <= '9') || 
                   (simbolo >= 'a' && simbolo <= 'z') || 
                   (simbolo >= 'A' && simbolo <= 'Z') || 
                   (simbolo == '@' || simbolo == '#')){
                        cout << "hay caracteres de más-->" << cadena << endl;
                        estado = q0;
                }
                else{
                    cout << "cadena aceptada";
                }break;
                
            case qd:
                break;
        

       
        }
        
        i++; // importantisimo incrementar la variable
        

    }
    if (estado == q7){ 
        cout << "tiene coronavirus deaa" << endl;  
    } else{
        cout << "cadena no valida " << endl;
    }

    // --- AQUI AGREGO EL NUEVO AUTOMATA CON TABLA DE TRANSICION ---
    cout << endl << "Revisando la cadena para el autómata de 'a' y 'b':" << endl;

    enum estadosAB {p0, p1, p2, p3, p4, pd};
    estadosAB estadoAB = p0;

    int tablaTransicion[5][2] = {
        {p1, p2},  // desde p0: a->p1, b->p2
        {p1, p3},  // desde p1: a->p1, b->p3
        {p4, p2},  // desde p2: a->p4, b->p2
        {p3, p3},  // desde p3: a->p3, b->p3
        {p4, p4}   // desde p4: a->p4, b->p4
    };

    i = 0;
    longitud = cadena.size();

    while(i < longitud){
        simbolo = cadena[i];
        if (simbolo == 'a' || simbolo == 'A') {
            estadoAB = (estadosAB)tablaTransicion[estadoAB][0];
        }
        else if (simbolo == 'b' || simbolo == 'B') {
            estadoAB = (estadosAB)tablaTransicion[estadoAB][1];
        }
        else {
            estadoAB = pd; // estado de error si encuentra otro símbolo
            break;
        }
        i++;
    }

    if (estadoAB == p4) {
        cout << "Cadena aceptada por el autómata de 'a' y 'b'" << endl;
    } else {
        cout << "Cadena no aceptada por el autómata de 'a' y 'b'" << endl;
    }

    return 0; 
}

