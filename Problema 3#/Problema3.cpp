#include <iostream>
#include <cmath>
#include <vector>
#include<windows.h>
#include <chrono>
#include <thread>
#include <stack>
#include <cmath>
#include <cctype>

using namespace std;

void TiempoEspera( int punticos){
	
		for(int i=0; i<=punticos; i++){
			Sleep(200);
			cout<<"  .";
		}
}

// Función para convertir un operando en notación científica a double
double convertirOperando(const std::string& operando) {
    double valor = 0.0;
    size_t posE = operando.find('E');
    if (posE == std::string::npos) {
        valor = std::stod(operando);
    } else {
        double base = std::stod(operando.substr(0, posE));
        int exponente = std::stoi(operando.substr(posE + 1));
        valor = base * std::pow(10, exponente);
    }
    return valor;
}

// Función para realizar una operación aritmética
double realizarOperacion(double operando1, double operando2, char operador) {
    switch (operador) {
        case '+': return operando1 + operando2;
        case '-': return operando1 - operando2;
        case '*': return operando1 * operando2;
        case '/': return operando1 / operando2;
        default: return 0.0; // Manejo de error
    }
}

// Función para evaluar una expresión aritmética
double evaluarExpresion(const std::string& expresion) {
    std::vector<std::string> tokens; // Almacena los tokens de la expresión
    std::string tokenActual;
    for (char c : expresion) {
        if (std::isdigit(c) || c == '.' || c == 'E' || c == '-') {
            tokenActual += c;
        } else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')') {
            if (!tokenActual.empty()) {
                tokens.push_back(tokenActual);
                tokenActual.clear();
            }
            tokens.push_back(std::string(1, c));
        }
    }
    if (!tokenActual.empty()) {
        tokens.push_back(tokenActual);
    }

    std::stack<double> operandos;
    std::stack<char> operadores;
    for (const std::string& token : tokens) {
        if (std::isdigit(token[0]) || token[0] == '.' || token[0] == 'E' || token[0] == '-') {
            operandos.push(convertirOperando(token));
        } else if (token[0] == '(') {
            operadores.push('(');
        } else if (token[0] == ')') {
            while (operadores.top() != '(') {
                double operando2 = operandos.top(); operandos.pop();
                double operando1 = operandos.top(); operandos.pop();
                char operador = operadores.top(); operadores.pop();
                operandos.push(realizarOperacion(operando1, operando2, operador));
            }
            operadores.pop(); // Elimina el '('
        } else if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/') {
            while (!operadores.empty() && operadores.top() != '(' &&
                   ((token[0] == '*' || token[0] == '/') || (operadores.top() == '+' || operadores.top() == '-'))) {
                double operando2 = operandos.top(); operandos.pop();
                double operando1 = operandos.top(); operandos.pop();
                char operador = operadores.top(); operadores.pop();
                operandos.push(realizarOperacion(operando1, operando2, operador));
            }
            operadores.push(token[0]);
        }
    }

    while (!operadores.empty()) {
        double operando2 = operandos.top(); operandos.pop();
        double operando1 = operandos.top(); operandos.pop();
        char operador = operadores.top(); operadores.pop();
        operandos.push(realizarOperacion(operando1, operando2, operador));
    }

    return operandos.top();
}

	
	class Menu{
	
	 	public:
	 		Menu(){
	 			imprimir_menu();
			 }
			 
			 void imprimir_menu(){
			 		Sleep(100);
				cout<< "..........................................................\n";
			 		Sleep(100);
				cout<< ":.---. .---.  .--. .---. .-.    .--. .-..-. .--.   .----.:\n";
					Sleep(100);
				cout<< ":: .; :: .; :: ,. :: .; :: :   : .--': `' :: .; :  `--  ;:\n";
					Sleep(100);
				cout<<"::  _.':   .': :: ::   .': :   : `;  : .. ::    :   .' ' :\n";
					Sleep(100);
				cout<<":: :   : :.`.: :; :: .; :: :__ : :__ : :; :: :: :   _`,`.:\n";
					Sleep(100);
				cout<<"::_;   :_;:_;`.__.':___.':___.'`.__.':_;:_;:_;:_;  `.__.':\n";
					Sleep(100);
				cout<<"..........................................................\n";
				
	 			Sleep(100);
	
				cout<<"\n_________________________________________________________\n\n";
				
				Sleep(100);
				cout<<"3) implemente la evaluación de expresiones aritméticas considerando los operadores +,-,*,/ y los\
				operandos pueden ser ingresados en notación científica (125E25,5E-8 para denotar 12x1025, 5x10-8\
				respectivamente), la entrada al programa será una cadena de caracteres con la expresión, ejemplo\
				de expresión a evaluar: (125E10 – 1e15)/5E-85*15\n\n";
				
				cout<<"Ingrese una operación aritmetica con Notacion cientifica:  ";
				string operacion;
				getline(cin,operacion);
				
      			TiempoEspera(5);
      			double resultado = evaluarExpresion(operacion);
    			std::cout << "Resultado: " << resultado << std::endl;
      				
				volver();
				

				
			 }
			 
			 void volver(){
			 	
			 	cout<<"\t\n Inserta 1 para volver al menu, y cualquier otro para terminar la operacion";
			 					
			 	int opc;
			 	cin>>opc;
			 	system("cls");
			 	switch(opc){
			 		case 1: 
			 		Menu();
			 		
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