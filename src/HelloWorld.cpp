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
#define LOG_TAG "Hello_World"
using namespace std;
//char name[MAX_NAME_LENGTH];
void printok(char *name1);
int main1() {
	demo1  demo;
	strncpy(demo.name,"Bob",MAX_NAME_LENGTH);
	//strncpy(name,"Bob",MAX_NAME_LENGTH);
	//demo.name = "Bob";      //会报char[4] char[20]的错
	demo.years = 20;
	demo1 *demo2 = &demo;
	cout << "name: "<< demo2->name <<"\n years: "<<demo2->years<<endl; // prints !!!Hello World!!!
	cout<<"just for git test"<<endl;

	char *name1 = "Bob";
	printok(name1);

#ifdef Resolved
	SeqList *L;
	int mSize =10;
	int index = 5;
	int Status = 0;
	ElemType *x;
	Status = Init(L,mSize);
	Find(L,index,x);
	//顺序表的初始化
#endif 
	return 0;
}


