//============================================================================
// Name        : HelloWorld.cpp
// Author      : TangHao
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "HelloWorld.h"
#include <string.h>
using namespace std;

int main() {
	demo1  demo;
	strncpy(demo.name,"Bob",MAX_NAME_LENGTH);
	//demo.name = "Bob";      »á±¨char[4] char[20]µÄ´í
	demo.years = 20;
	demo1 *demo2 = &demo;
	cout << "name: "<< demo2->name <<"\n years: "<<demo2->years<<endl; // prints !!!Hello World!!!
	cout<<"just for git test"<<endl;
	return 0;
}
