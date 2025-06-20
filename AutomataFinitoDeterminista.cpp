//automata finito determinista

#include <iostream>
#include <stdio.h>
using namespace std;

int main(int argc, char *argv[]){
	
	//dejamos en claro nuestros estados a usar 
	enum testados{
		q0, q1, q2, q3, q4, q5, q6, q7, qd  //qd es el estado muerto
	};
	
	testados estado;
	
	// definicion de variables
	int i, longitud;
	i = 0; 
	longitud = 0;
	char simbolo;
	string cadena;
	
	estado = q0;
	
	//peticion de una cadena al usuario
	cout << "dame una cadena siguiendo el afd para corroborarla:" << endl;
	cin >> cadena;
	
	longitud = cadena.size();
	
	while (longitud > i){
		
		simbolo = cadena[i];
		
		switch (estado){
			
			case q0:
				
				if (simbolo == 'A' || simbolo == 'a'){
					estado = q1;
				}
				else{
					estado = qd;
				}break;
			
			case q1:
				
				if (simbolo == 'A' || simbolo == 'a'){
					estado = q2;
				}
				else{
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
				}break;
			
			
			case q6:
				
				if (simbolo == 'B' || simbolo == 'b'){
					estado = q7;
				}
				else{
					estado = qd;
				}break;
			
			case q7:
				
				if ((simbolo >= '0' && simbolo <= '9') || (simbolo >= 'a' && simbolo <= 'z') || (simbolo >= 'A' && simbolo <= 'Z') || simbolo == '#' || simbolo == '@' || simbolo == '$' || simbolo == '?'){
					
					estado = qd;
					break;
				}
				break;

				
			
		}
			
		i++;
	
	}
	
	if (estado == q7 && i == longitud){
		cout << "cadena aceptada" << endl;
	}
	else {
		cout << "cadena no aceptada" << endl;
	}
	
	
	return 0;
}