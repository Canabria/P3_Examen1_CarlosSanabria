#include <iostream>
#include "PC.hpp"
#include "Red.hpp"
#include <string>
using namespace std;
int MENU();
int main() {
	Red * r=new Red();
	int opcion;//asigno el metodo menu a la variable opcion, menu devuelve un entero(opc)
	do {
		opcion = MENU();
		switch (opcion) {
			case 1: {
				cout << "Agregar PC " << "\n";
				cout<<"\n";
				string id="";
				string mask="";
				string host;
				cout<<"Por ingrese su ip adress"<<endl;
				cout<<"==>";
				cin.ignore();
				getline(cin,id);
				cout<<"Por ingrese su mask ip adress"<<endl;
				cout<<"==>";
				getline(cin,mask);
				cout<<"Por favor ingrese el nombre del host porfavor: "<<endl;
				cout<<"==>";
				getline(cin,host);
				PC *r1=new PC(id,mask,host);
				r->crear(r1);
				cout << "FIN Agregar a PC" << "\n";
				cout << "\n";
				break;
			}//fin del case 1
			case 2: {
				cout << "Ingresar a PC" << "\n";
				cout<<"Las PC que estas en el sistema: "<<endl;
				r->ver();
				int i=0;
				cout<<"Porfavor ingrese el indice de la PC que esta en el sistema: "<<endl;
				cout<<"==>";
				cin>>i;
				r->ingresarPC(i);
				cout<<"\n";
				cout << "FIN Ingresar a PC" << "\n";
				cout << "\n";
				break;
			}//fin del case 2
			case 3: {
				cout<<"Saliendo del sistema"<<endl;
				    break;
			}//fin del case 3
		}//Fin del switch.
		cout << "\n";
	} while (opcion != 3);
	r->~Red();
		return 0;
		
}//fin del main

int MENU() {
	int opc = 0;
	cout << "MENU" <<"\n";
	cout << "1. Agregar PC \n"
	     << "2. Ingresar a PC \n"
	     << "3. Salir " << "\n";
	cout<< "Ingrese la opcion que Desee: \n"
		<< "===>";
	cin>> opc;
	return opc;
}//fin del metodo menu