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
	//demo.name = "Bob";      //�ᱨchar[4] char[20]�Ĵ�
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
	//˳���ĳ�ʼ��
#endif 
	return 0;
}
void func_test_eat(Animal *animal){
    animal->eat();
    //animal->~Animal(); //�������������Լ����ã�
    //animal->Animal();//���캯�������Լ�����
}

/*
 * �������麯���Ϳ��Բ�����д�ú���
 */
/*
void func_test_eat(Cat *animal){  //ֻ�����أ�����ʹ���麯��==>�ڻ����еķ���ʹ��vitural�ؼ�������
    animal->eat();
    animal->~Animal(); //�������������Լ����ã�
    //animal->Animal();//���캯�������Լ�����
}
*/
int main2(){
	Animal *animal1 = new Animal();
	animal1->eat();
	func_test_eat(animal1);
	Cat *cat1 = new Cat();
	cat1->eat();
	func_test_eat(cat1);  //Ӧ���ǵ����������д����
	delete cat1;//���ø������������
	return 0;
}


int main(){
	main1();
	main2();
	for(int i = 0;i < 100;i++){
		printf("i:%d ��ż�ԣ�%s \n",i,dbtest(i));
	}
	return 0;
}
