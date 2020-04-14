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
#include "Cat_Eat_Rat.h"
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
void func_test_eat(Animal *animal){
    animal->eat();
    //animal->~Animal(); //析构函数可以自己调用？
    //animal->Animal();//构造函数可以自己调用
}

/*
 * 基类有虚函数就可以不用重写该函数
 */
/*
void func_test_eat(Cat *animal){  //只能重载？可以使用虚函数==>在基类中的方法使用vitural关键字声明
    animal->eat();
    animal->~Animal(); //析构函数可以自己调用？
    //animal->Animal();//构造函数可以自己调用
}
*/
int main2(){
	Animal *animal1 = new Animal();
	animal1->eat();
	func_test_eat(animal1);
	Cat *cat1 = new Cat();
	cat1->eat();
	func_test_eat(cat1);  //应该是调用子类的重写函数
	delete cat1;//调用父类的析构函数
	return 0;
}


int main(){
	main1();
	main2();
	for(int i = 0;i < 100;i++){
		printf("i:%d 奇偶性：%s \n",i,dbtest(i));
	}
	return 0;
}
