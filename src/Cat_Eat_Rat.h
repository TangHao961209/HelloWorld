/*
 * Cat_Eat_Rat.h
 *
 *  Created on: 2020��4��12��
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
	 * virtual�����ã�������������д����,Ϊֻ��ʹ�û��� Animal ָ����ܹ����׵ĵ����������������д���ܡ�
	 * ����������д�����麯��ʱ��Ҳ���Ե��û����麯���Ĺ���==>������д
	 * �����麯��ÿ�������һ�����������������������������Զ���Ϊÿ�����󴴽�һ�����صġ���ָ�롱__vptr����ָ��������
	 * ���������ϵ�����
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
	void eat(){   //���ڵ��ø���Ĺ��캯��
		cout<<"I'm eating a cat"<<endl;
	}
	Cat(){
		cout<<"Cat create"<<endl;
	}
	~Cat(){     //��ʾ�������˸������������,�ȵ����������������
		cout<<"Cat go"<<endl;
	}
};




#endif /* CAT_EAT_RAT_H_ */
