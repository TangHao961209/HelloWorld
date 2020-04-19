/*
 * SmartPtr.h
 *
 *  Created on: 2020��4��19��
 *      Author: b1508
 */
#include<string.h>
#ifndef SMARTPTR_H_
#define SMARTPTR_H_
/*
 * ��ģ�������template  ����ָ��sp  ǿָ�������
 */
 template <class T> class SmartPtr{
public:
	SmartPtr(T *p = 0) : ptr(p){};
	~SmartPtr(){delete ptr;};
	void say();
	T *ptr;
};

//��ģ��ĳ�Ա��������ʵ��
template <class T>
void SmartPtr<T>::say(){
	printf("��ӡptrֵ %d",*ptr);
}


#endif /* SMARTPTR_H_ */
