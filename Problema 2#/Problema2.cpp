#include <iostream>
#include <cmath>
#include <vector>
#include<windows.h>


using namespace std;

	
	long factorial(int n) {
    	
		long result= 1;
		for(int i=1; i<=n; i++){
			result = result*i;
		}
    
    	return result;
	}


	long CoeficienteBinomial(int n, int k){
		
		int u= n-k;
		long result = (factorial(n))/(factorial(k)*factorial(u));
		
		return result;
	}
	
	long CoeficienteBinomialB(int n, int k){
		
		int u= n-k;
		cout<<"\t";cout<<n;cout<<"!";cout<<"/(";cout<<k;cout<<"!(";
		cout<<n;cout<<" - ";cout<<k;cout<<")!) = ";
		long result = (factorial(n))/(factorial(k)*factorial(u));
		cout<<result;cout<<"\n";
		return result;
	}
	
	long* Coeficientes(int n){
		long* coeficientes = new long[n];									
				for(int k=0; k<=n; k++){
						 long result=CoeficienteBinomial(n,k);        
						 coeficientes[k]=result;
				}
		return coeficientes;
	}
	
	long* CoeficientesB(int n){
		long* coeficientes = new long[n];									
				for(int k=0; k<=n; k++){
						 long result=CoeficienteBinomialB(n,k);        
						 coeficientes[k]=result;
				}
		return coeficientes;
	}
	
	void imprimirPolinomio(long Coeficientes[], int n){
		
		int decrement=n;
		cout<<"\n";cout<<"\t";
		for(int i =0; i<=n; i++){
			
		//Si el coeficiente es mayor a 1 y el decremento es 0
			if(Coeficientes[i]>1 && decrement==0){	
				cout<<Coeficientes[i];
			}	
		//Si el coeficiente es mayor a 1 y el decremento es 1
			if(Coeficientes[i]>1 && decrement==1){	
				cout<<Coeficientes[i];cout<<"X + ";
			}	
		//Si el coeficiente es mayor a 1 y el decremento es mayor que 1	
			if(Coeficientes[i]>1 && decrement>1){
				cout<<Coeficientes[i];cout<<"X^("; cout<<decrement; cout<<") + ";
			}	
		//Si el coeficiente es 1 y el decremento es 0		
			if(Coeficientes[i]==1 && decrement==0){	
				cout<<1;
			}
		//Si el coeficiente es 1 y el decremento tambien es 1	
			if(Coeficientes[i]==1 && decrement==1){
				cout<<"X + ";
			}
		//Si el coeficiente es 1 y el decremento es mayor que 1
			if(Coeficientes[i]==1 && decrement>1){
				cout<<"X^("; cout<<decrement; cout<<") + ";
			}			
		//Si el coeficiente es 0 y el decremento tambien es 0
			if(Coeficientes[i]==0 && decrement==0){	
				cout<<"+ 0";
			}	
		//Si el coeficiente es 0 y el decremento es 1
			if(Coeficientes[i]==0 && decrement==1){
				cout<<"0";
			}
		//Si el coeficiente es 0 y el decremento es mayor que 1	
			if(Coeficientes[i]==0 && decrement>1){
				cout<<"0";
			}			
			
			
			decrement--;
		}
		cout<<"\n";
		
	}

	
	class Menu{
	
	 	public:
	 		Menu(){
	 			imprimir_menu();
			 }
			 
			 void imprimir_menu(){
			 	Sleep(100);
	 			cout<< ".----------------------------------------------------------.\n";
	 			Sleep(100);
				cout<< "|.---.            .-.   .-.                          .---. |\n";
				Sleep(100);
				cout<< "|: .; :           : :   : :                          `--. :|\n";
				Sleep(100);
				cout<< "|:  _.'.--.  .--. : `-. : :   .--. ,-.,-.,-. .--.      ,','|\n";
				Sleep(100);
				cout<< "|: :   : ..'' .; :' .; :: :_ ' '_.': ,. ,. :' .; ;   .'.'_ |\n";
				Sleep(100);
				cout<< "|:_;   :_;  `.__.'`.__.'`.__;`.__.':_;:_;:_;`.__,_;  :____;|\n";
				Sleep(100);
				cout<< "'----------------------------------------------------------'\n";
				Sleep(100);
	
				cout<<"\n_________________________________________________________\n\n";
				Sleep(100);
				cout<<"Ingrese un numero entero no negativo 'n', por favor :   ";
				int nn;
				cin>>nn;
				
				cout<<"\n\n Seleccione una opcion entre a) y b) \n ";
				cout<<"\n	a) para generar los coeficientes del polinomio de la forma (x+1)^(n) , del valor 'n' que usted haya ingresado \n	y mostrar el resultado del polinomio";
				cout<<"\n\n	b) para mostrar los pasos para resolver x dado , f(x)=(x+1)^(n) segun el polinomio generado) \n\n ";
				
				cout<<"--> ";
				char opcion;
				cin >> opcion;
				
				long* coeficientes = new long[nn];
				
				switch (opcion) {
    				case 'a':
    					
						system("cls");
      					cout << "----Opcion b) Seleccionada----------------------------------\n\n";
      					
      					cout<<"\t__________- PASOS PARA RESOLVER EL POLINOMIO (X+1)^( ";
      					cout<<nn;
      					cout<<")  -__________\n";
      					
      					cout<<"\n(n= ";
      					cout<<nn;
      					cout<<" ): \n";
      					coeficientes= Coeficientes(nn);
    					imprimirA(coeficientes, nn);
						
						
      					
      					imprimirPolinomio(coeficientes,nn);
      					cout<<"\n";
      				break; 
      				
      				case 'b':
      					system("cls");
      					cout << "----Opcion b) Seleccionada----------------------------------\n\n";
      					
      					cout<<"\t__________- PASOS PARA RESOLVER X PARA UN POLINOMIO DE LA FORMA f(x)=(X+1)^( ";
      					cout<<nn;
      					cout<<")  -__________\n";
      					
      					cout<<"\n(n= ";
      					cout<<nn;
      					cout<<" ): \n";
      					
      					cout<<"\nPASO 1# sacar el coeficiente binomial de la forma (n/k)= n!/k!(n-k)!\n\n";
      					coeficientes= CoeficientesB(nn);
      					cout<<"\n PASO 2# Reorganizar a los coeficientes desde el orden k=0 al orden k=n\n\n";
      					
    					imprimirA(coeficientes, nn);
						cout<<"\n PASO 3# Organizar en un polinomio de grado n , donde x^n vaya descendiendo progresivamente";
						
      					
      					imprimirPolinomio(coeficientes,nn);
      					
      					cout<<"\nDar por concluido el ejercicio\n";
      					
							
      				break; 
					
      					
      				}
      				
				volver(coeficientes);

				
			 }
			 
			 void volver(long coeficientes[]){
			 	
			 	cout<<"\t\n Inserta 1 para volver al menu, y cualquier otro para terminar la operacion";
			 					 if (coeficientes != nullptr) {
        								delete[] coeficientes;
    								}
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