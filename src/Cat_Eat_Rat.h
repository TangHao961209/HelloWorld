/*
 * Cat_Eat_Rat.h
 *
 *  Created on: 2020年4月12日
 *      Author: b1508
 */
#include <iostream>
#ifndef CAT_EAT_RAT_H_
#define CAT_EAT_RAT_H_
using namespace std;
class Animal
{
public:
	/*
	 * virtual的作用：允许派生类重写功能,为只需使用基类 Animal 指针就能够轻易的调用所有派生类的重写功能。
	 * 派生类在重写基类虚函数时，也可以调用基类虚函数的功能==>部分重写
	 * 对于虚函数每个类会有一个虚表，对象共用虚表，编译器编译器会自动的为每个对象创建一个隐藏的“虚指针”__vptr，它指向类的虚表
	 * 避免语义上的歧义
	 */
	virtual void eat(){
		cout <<"I'm eating generic food"<<endl;;
	}
	Animal(){
		cout<<"all animal"<<endl;
	}
	~Animal(){
		cout<<"animal go";
	}
};

class Cat: public Animal{
public:
	void eat(){   //会在调用父类的构造函数
		cout<<"I'm eating a cat"<<endl;
	}
	Cat(){
		cout<<"Cat create"<<endl;
	}
	~Cat(){     //显示表达，覆盖了父类的析构函数,先调用子类的析构函数
		cout<<"Cat go"<<endl;
	}
};




#endif /* CAT_EAT_RAT_H_ */
