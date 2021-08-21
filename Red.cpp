#include <iostream>
#include "PC.hpp"
#include "Red.hpp"
#include <string>
#include <cstring>
using namespace std;
Red::Red() {

}
void Red::crear(PC *p) {
	redes.push_back(p);
}
void Red::ver() {
	for(int i=0; i<redes.size(); i++) {
		PC* aux = redes.at(i);
		cout<<(i)<<") "<<"ID: "<<aux->getIP()<< "\n";
		cout<<"   Mask IP: "<<aux->getMASK()<< "\n";
		cout<<"   Host: "<<aux->getHOST()<< "\n";
	}
}
void Red::ingresarPC(int b) {
	string respuesta;
	char *tok;
	int r=0;
	PC* aux = redes.at(b);
	cout<<"MENU\n"
	    <<"Comandos acessibles:\n"
	    <<"show\n"
	    <<"ping_(un IP adress)\n"
	    <<"salida\n"
	    <<"Instrucciones: Despues del'#' ingrese el comando\n ";
	do {
		cout<<aux->getHOST()<<"#";
		if(r==0){
		cin.ignore();
		r++;
	}
		getline(cin,respuesta);
		if(respuesta=="show") {
			aux->show();
		} else {
			string check="ping";
			int j=0;
			bool t=false;
			for(int i=0; i<4; i++) {
				if(respuesta[i]==check[j]) {
					j++;
				}
			}
			if(j==check.length()) {
				t=true;
			}
			if(t) {
				string copy="";
				for(int j=5; j<respuesta.length(); j++) {
					copy+=respuesta[j];
				}
				int nm=redes.size();
				int veri[nm];
				for(int j=0; j<redes.size(); j++) {
					PC* aux1 = redes.at(j);
					veri[j]=(int)aux1->ping(copy);
				}
				cout<<"Pinging to "<<copy<<" with 32 bytes of data: \n";
				int tt=0;
				for(int j=0; j<nm; j++) {
					if(veri[j]==1) {
						if(j==b) {
							cout<<"a"<<endl;
							tt=1;
						} else {
							tt=2;
						}
					} else {
						tt=3;
					}
				}
				for(int i=0; i<redes.size(); i++) {
					if(tt==1) {
						cout<<"Reply from "<<copy<<" : bytes=32 time=37ms TPL=46"<<endl;
					} else if(tt=2) {
						cout<<"Reply from "<<copy<<" : Destination host unreachable"<<endl;
					} else if(tt==3) {
						cout<<"Request timed out"<<endl;
					}
				}
				if(tt==1||tt==2) {

					cout<<"Ping statistics for "<<copy<<": "<<endl;
					cout<<"  Packets: "<<redes.size()<<" Recieved ="<<redes.size()<<" Loss ="<<0<<"(0%)"<<endl;
				} else {
					cout<<"Ping statistics for "<<copy<<": "<<endl;
					cout<<"  Packets: "<<redes.size()<<" Recieved ="<<0<<" Loss ="<<redes.size()<<"(100%)"<<endl;
				}
			}

		}
	} while(respuesta!="salida");
}