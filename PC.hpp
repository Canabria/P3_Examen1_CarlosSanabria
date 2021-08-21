#ifndef PC_HPP
#define PC_HPP
#include<string>
#include<iostream>
using namespace std;
class PC {
	private:
		string ip;
		string mask;
		string host;
	public:
		PC();
		PC(string, string, string);
		void setIP(string);
		void setMASK(string);
		void setHOST(string);
		string getIP();
		string getMASK();
		string getHOST();
		bool ping(string);
		string binario(int);
		void show();
};
#endif