#include <iostream>
#include <cmath>
#include <vector>
#include<windows.h>
#include <string>
#include <regex>

using namespace std;

	void TiempoEspera( int punticos){
	
		for(int i=0; i<=punticos; i++){
			Sleep(200);
			cout<<"  .";
		}
	}
		

bool NotacionFen(string fen) {
    // Expresión regular para validar la notación FEN
    regex fenRegex(
        "^([rnbqkpRNBQKP1-8]+/){7}[rnbqkpRNBQKP1-8]+\\s" // Colocación de piezas
        "[wb]\\s"                                           // Lado a mover
        "(-|K?Q?k?q?)\\s"                                    // Disponibilidad de enroque
        "(-|[a-h][36])\\s"                                   // Captura al paso
        "\\d+\\s"                                            // Regla de la cincuenta jugadas
        "\\d+$"                                            // Número de jugada
    );

    return regex_match(fen, fenRegex);
}



	
	class Menu{
	
	 	public:
	 		Menu(){
	 			imprimir_menu();
			 }
			 
			  void volver(){
			 	
			 	cout<<"\t\n Inserta 1 para volver al menu, y cualquier otro para terminar la operacion";
			 	int opcion;
			 	cin>>opcion;
			 	switch(opcion){
			 		case 1: 
			 		imprimir_menu();
			 		
			 		break;
			 		
			 		default:
			 		break;
				 }
			 }	
			 
			 void imprimir_menu(){
			 		Sleep(100);
				cout<< ".........................................................\n";
			 		Sleep(100);
				cout<< ":.---. .---.  .--. .---. .-.    .--. .-..-. .--.     ,-.:\n";
					Sleep(100);
				cout<< ":: .; :: .; :: ,. :: .; :: :   : .--': `' :: .; :  .'  ::\n";
					Sleep(100);
				cout<<"::  _.':   .': :: ::   .': :   : `;  : .. ::    :   `: ::\n";
					Sleep(100);
				cout<<":: :   : :.`.: :; :: .; :: :__ : :__ : :; :: :: :    : ::\n";
					Sleep(100);
				cout<<"::_;   :_;:_;`.__.':___.':___.'`.__.':_;:_;:_;:_;    :_;:\n";
					Sleep(100);
				cout<<".........................................................\n\n";
				
	 			Sleep(100);
	
				cout<<"\n_________________________________________________________\n\n";
				
				Sleep(100);
				cout<<"1) Dado una cadena C, valide si C se encuentra en notacion FEN (Forsyth-Edwards Notation),\
					Forsyth–Edwards Notation. FEN es un sistema estandar para describir posiciones especificas en\
					partidas de ajedrez, permitiendo reiniciar el juego desde una posicion dada. Desarrollado\
					inicialmente por David Forsyth y ampliado por Steven J. Edwards, FEN se utiliza en la Notacion\
					de Juego Portatil para definir posiciones iniciales distintas a la estándar (Wikipedia, 2025).\
					Wikipedia. (2025).Forsyth–Edwards Notation. Recuperado el 27 de octubre \n\n";
					
				cout<<"Ingrese una cadena de texto a continuacion , Por favor: ";
					
				string cadena;
				
				getline(cin,cadena);
				cout<<"\n\n";
				TiempoEspera(5);
				cout<<"\n\n";
				
				cout <<"    "<< cadena << " :  " << (NotacionFen(cadena) ? "Valido" : "Invalido")<<"\n";		
				

				cout<<"\t\n Inserta 1 para volver al menu, y cualquier otro para terminar la operacion: ";
				
			 	int opc;
			 	
			 	cin>>opc;
			 	
				switch(opc){
			 		case 1: 
			 		system("cls");
			 		imprimir_menu();
			 		
			 		break;
			 		
				 }
			 }
			 
			

	}; 
	


int main()
{
	
	Menu();
	

    return 0;
}