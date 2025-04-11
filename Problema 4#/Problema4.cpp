#include <iostream>
#include <cmath>
#include <vector>
#include<windows.h>
#include <chrono>
#include <thread>
#include <sstream>
#include <algorithm>

using namespace std;



	

	
	class Menu{
	
	 	public:
	 		Menu(){
	 			imprimir_menu();
			 }
			 
			 void imprimir_menu(){
			 		Sleep(100);
				cout<< "...........................................................\n";
			 		Sleep(100);
				cout<< ":.---. .---.  .--. .---. .-.    .--. .-..-. .--.     .-. :\n";
					Sleep(100);
				cout<< ":: .; :: .; :: ,. :: .; :: :   : .--': `' :: .; :   .'.' :\n";
					Sleep(100);
				cout<<"::  _.':   .': :: ::   .': :   : `;  : .. ::    :  .'.'_ :\n";
					Sleep(100);
				cout<<":: :   : :.`.: :; :: .; :: :__ : :__ : :; :: :: :  :_ ` ::\n";
					Sleep(100);
				cout<<"::_;   :_;:_;`.__.':___.':___.'`.__.':_;:_;:_;:_;    :_: :\n";
					Sleep(100);
				cout<<"...........................................................\n\n";
				
	 			Sleep(100);
	
				cout<<"\n_________________________________________________________\n\n";
				
				Sleep(100);
				cout<<"4) Para un programa en un lenguaje L, dado un cadena C escrito en L, muestre y cuente la\
				ocurrencia de la palabra E en C ";
				
				std::string cadena;

    			std::cout << "\n\nIngrese la cadena C por favor: ";
    			std::getline(std::cin, cadena);

    			// Convertir la cadena a minúsculas para hacer la búsqueda insensible a mayúsculas/minúsculas
    			std::string cadenaMinusculas = cadena;
    			std::transform(cadenaMinusculas.begin(), cadenaMinusculas.end(), cadenaMinusculas.begin(), ::tolower);

    			// Dividir la cadena en palabras
    			std::stringstream ss(cadenaMinusculas);
    			std::string palabra;
    			std::vector<std::string> palabras;

    			while (ss >> palabra) {
        palabras.push_back(palabra);
    }

    // Contar y mostrar ocurrencias de la palabra "e"
    int contador = 0;
    for (const std::string& p : palabras) {
        if (p == "e") {
            contador++;
            std::cout << "Ocurrencia encontrada: " << p << std::endl;
        }
    }

    // Mostrar el número total de ocurrencias
    std::cout << "Total de ocurrencias de 'e': " << contador << std::endl;

				
				volver();

				
			 }
			 
			 void volver(){
			 	
			 	cout<<"\t\n Inserta 1 para volver al menu, y cualquier otro para terminar la operacion";
			 					
			 	int opc;
			 	cin>>opc;
			 	system("cls");
			 	switch(opc){
			 		case 1: 
			 		imprimir_menu();
			 		
			 		break;
			 		
			 		default:
			 		break;
				 }
			 }
			 
			 int valorinvalido(int n){
			 	int nn;
			 	
			 	if(n<0){
			 		cout<<"\nel numero no puede ser menor que cero, vuelva a ingresarlo...\n\n";
			 		cin>>nn;
			 		return nn;
				 }
				if(n != floor(n)){
					cout<<"\n\n el numero tiene que ser entero , vuelva a ingresarlo...\n\n";
					cin>>nn;
					return nn;
					        
				}
				
				return n;
			 }
				
			void imprimirA(long coeficientes[], int n){
				cout<<"\n";
				for(int i=0; i<n+1; i++){
					cout<<"\t";
					cout<<coeficientes[i];
				}
				cout<<"\n";
			}
	}; 
	


int main()
{
	
	Menu();
	

    return 0;
}