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
namespace android{                            //命名空间的使用

template <class T> class SmartPtr{
public:
	inline SmartPtr(T *p = 0) : ptr(p){};    //构造函数声明为内联函数 ==>  构造函数默认是内联函数
	~SmartPtr(){delete ptr;};
	void say();
	T *ptr;
};

//类模板的成员函数类外实现
template <class T>
void SmartPtr<T>::say(){
	printf("打印ptr值 %d \n",*ptr);
}

#if 0
template<typename T>
class sp{
public:
	inline sp():m_ptr(0){};//m_ptr的初始化    初始化列表
	sp(T *other);
	sp(const sp<T>& other);
	sp(sp<T>&& other);
	template<typename U>  sp(U *other);     //这些是为什么？？
	template<typename U> sp(const sp<U>& other);
	template<typename U> sp(sp<U>&& other);
	~sp();

	 // Assignment
	sp& operator = (T* other);
	sp& operator = (const sp<T>& other);
	sp& operator = (sp<T>&& other);

	template<typename U> sp& operator = (const sp<U>& other);
	template<typename U> sp& operator = (sp<U>&& other);
	template<typename U> sp& operator = (U* other);
private:
	T *m_ptr;
};

template<typename T>
sp<T>::sp(T *other): m_ptr(other){
    if (other) //如果构造函数形参的指针不为null，该指针的计数加1，这个后面解释
        other->incStrong(this);
}

template<typename T>
sp<T>::sp(const sp<T>& other): m_ptr(other.m_ptr){      //实参为sp<T>类型的对象，这里形参为引用
    if (m_ptr)
    	m_ptr->incStrong(this);
}

template<typename T>
sp<T>::sp(sp<T>&& other): m_ptr(other.m_ptr){      //这里C++11中的移动构造函数
    other.m_ptr = nullptr;
}

template<typename T> template<typename U>
sp<T>::sp(U *other): m_ptr(other){
    if (other)
        ((T*) other)->incStrong(this);
}

template<typename T> template<typename U>
sp<T>::sp(const sp<U>& other): m_ptr(other.m_ptr){
    if (m_ptr)
        ((T*) other)->incStrong(this);
}

template<typename T> template<typename U>
sp<T>::sp(sp<U>&& other): m_ptr(other.m_ptr){
	other.m_ptr = nullptr;
}

template<typename T>
sp<T>& sp<T>::operator =(const sp<T>& other) {
    T* otherPtr(other.m_ptr);
    if (otherPtr)
        otherPtr->incStrong(this);//参数other中的指针m_ptr要多一个引用了，调用incStrong()
    if (m_ptr)
        m_ptr->decStrong(this);//当前的指针需要被other代替，那么目前的指针m_ptr的引用计数需要减1
    m_ptr = otherPtr;
    return *this;
}

template<typename T>
sp<T>& sp<T>::operator =(sp<T>&& other) {
    if (m_ptr)
        m_ptr->decStrong(this);//这里是移动赋值，会将other中的m_ptr直接移动给这里的m_ptr，之前要先decStrong
    m_ptr = other.m_ptr;
    other.m_ptr = nullptr;
    return *this;
}

template<typename T>
sp<T>& sp<T>::operator =(T* other) {
    if (other)
        other->incStrong(this);//直接指针赋值就更简单了
    if (m_ptr)
        m_ptr->decStrong(this);
    m_ptr = other;
    return *this;
}

template<typename T> template<typename U>
sp<T>& sp<T>::operator =(const sp<U>& other) {//考虑到子类向父类赋值
    T* otherPtr(other.m_ptr);
    if (otherPtr)
        otherPtr->incStrong(this);
    if (m_ptr)
        m_ptr->decStrong(this);
    m_ptr = otherPtr;
    return *this;
}

template<typename T> template<typename U>
sp<T>& sp<T>::operator =(sp<U>&& other) {
    if (m_ptr)
        m_ptr->decStrong(this);
    m_ptr = other.m_ptr;
    other.m_ptr = nullptr;
    return *this;
}


template<typename T> template<typename U>
sp<T>& sp<T>::operator =(U* other) {
    if (other)
        ((T*) other)->incStrong(this);
    if (m_ptr)
        m_ptr->decStrong(this);
    m_ptr = other;
    return *this;
}

template<typename T>
sp<T>::~sp() {
    if (m_ptr)
        m_ptr->decStrong(this);
}
#endif
}





#endif /* SMARTPTR_H_ */
