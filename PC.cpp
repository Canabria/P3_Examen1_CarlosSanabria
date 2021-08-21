#include <iostream>
#include "PC.hpp"
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;
PC::PC() {
}
PC::PC(string id, string mask, string host) {
	this->ip=id;
	this->mask=mask;
	this->host=host;
}
void PC::setIP(string ip) {
	this->ip=ip;
}
void PC::setMASK(string mask) {
	this->mask=mask;
}
void PC::setHOST(string host) {
	this->host=host;
}
string PC::getIP() {
	return ip;
}
string PC::getMASK() {
	return mask;
}
string PC::getHOST() {
	return host;
}
bool PC::ping(string r) {
	string binario1="";
	string binario2="";
	for(int c=0; c<r.length(); c++) {
		char character=r[c];
		int ascii=character;
		if(ascii>=48&&ascii<=57) {
			binario1+=character;
		}
	}
	for(int c=0; c<ip.length(); c++) {
		char character=ip[c];
		int ascii=character;
		if(ascii>=48&&ascii<57) {
			binario2+=character;
		}
	}
	int n1=r.length();
	int n2=ip.length();
	bool t=false;
	int bin1=atoi(binario1.c_str());
	int bin2=atoi(binario2.c_str());
	if(bin1==bin2) {
		t=true;
	}
	return t;
}
string PC::binario(int r) {
	string binario="";
	if( r > 0) {
		while(r > 0) {
			if(r %2 == 0 ) {
				binario = "0" + binario;
			} else {
				binario = "1" + binario ;
			}//fin del else
			r = (int)r/2;
		}//fin del while
	} else if( r == 0) {
		binario = "0";
	}
	return binario;
}
void PC::show() {
	cout<<"ID: "<<ip<< "\n";
	cout<<"Mask IP: "<<mask<< "\n";
}