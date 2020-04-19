/*
 * SmartPtr.h
 *
 *  Created on: 2020年4月19日
 *      Author: b1508
 */
#include<string.h>
#ifndef SMARTPTR_H_
#define SMARTPTR_H_
/*
 * 类模板的运用template  智能指针sp  强指针的运用
 */
 template <class T> class SmartPtr{
public:
	SmartPtr(T *p = 0) : ptr(p){};
	~SmartPtr(){delete ptr;};
	void say();
	T *ptr;
};

//类模板的成员函数类外实现
template <class T>
void SmartPtr<T>::say(){
	printf("打印ptr值 %d",*ptr);
}


#endif /* SMARTPTR_H_ */
