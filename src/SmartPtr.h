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
namespace android{                            //�����ռ��ʹ��

template <class T> class SmartPtr{
public:
	inline SmartPtr(T *p = 0) : ptr(p){};    //���캯������Ϊ�������� ==>  ���캯��Ĭ������������
	~SmartPtr(){delete ptr;};
	void say();
	T *ptr;
};

//��ģ��ĳ�Ա��������ʵ��
template <class T>
void SmartPtr<T>::say(){
	printf("��ӡptrֵ %d \n",*ptr);
}

#if 0
template<typename T>
class sp{
public:
	inline sp():m_ptr(0){};//m_ptr�ĳ�ʼ��    ��ʼ���б�
	sp(T *other);
	sp(const sp<T>& other);
	sp(sp<T>&& other);
	template<typename U>  sp(U *other);     //��Щ��Ϊʲô����
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
    if (other) //������캯���βε�ָ�벻Ϊnull����ָ��ļ�����1������������
        other->incStrong(this);
}

template<typename T>
sp<T>::sp(const sp<T>& other): m_ptr(other.m_ptr){      //ʵ��Ϊsp<T>���͵Ķ��������β�Ϊ����
    if (m_ptr)
    	m_ptr->incStrong(this);
}

template<typename T>
sp<T>::sp(sp<T>&& other): m_ptr(other.m_ptr){      //����C++11�е��ƶ����캯��
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
        otherPtr->incStrong(this);//����other�е�ָ��m_ptrҪ��һ�������ˣ�����incStrong()
    if (m_ptr)
        m_ptr->decStrong(this);//��ǰ��ָ����Ҫ��other���棬��ôĿǰ��ָ��m_ptr�����ü�����Ҫ��1
    m_ptr = otherPtr;
    return *this;
}

template<typename T>
sp<T>& sp<T>::operator =(sp<T>&& other) {
    if (m_ptr)
        m_ptr->decStrong(this);//�������ƶ���ֵ���Ὣother�е�m_ptrֱ���ƶ��������m_ptr��֮ǰҪ��decStrong
    m_ptr = other.m_ptr;
    other.m_ptr = nullptr;
    return *this;
}

template<typename T>
sp<T>& sp<T>::operator =(T* other) {
    if (other)
        other->incStrong(this);//ֱ��ָ�븳ֵ�͸�����
    if (m_ptr)
        m_ptr->decStrong(this);
    m_ptr = other;
    return *this;
}

template<typename T> template<typename U>
sp<T>& sp<T>::operator =(const sp<U>& other) {//���ǵ��������ำֵ
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
