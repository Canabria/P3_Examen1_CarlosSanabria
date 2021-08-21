#include<string>
#include<iostream>
#include <vector>
#include "PC.hpp"
class Red{
	private:
		  vector<PC*> redes;
	public:
		Red();
		void crear(PC*);
		void ver();
		void ingresarPC(int i);
		~Red();
};