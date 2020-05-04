/*
 * SeqList.cpp
 *
 *  Created on: 2020��4��12��
 *      Author: b1508
 */
//#include "other.h"
#include <stdlib.h>
#define ERROR 0
#define OK 1
#define Overflow 2  //����
#define Underflow 3 //����
#define Notresnet 4 //Ԫ�ز�����
#define Duplicate 5//Ԫ���ظ�

/*
 * ���Ա�ĳ�ʼ��
 */
#ifdef Resolved
Status Init(SeqList *L,int mSize){
	L->maxLength = mSize;
	L->n = 0;
	L->element = malloc(sizeof(ElemType)*mSize);//���ٿռ�
	if(!L->element){
		return ERROR;
	}
	return OK;
}
/*
 * ˳������Find(L,i,x)
 */
Status Find(SeqList L,int i,ElemType *x){
	if(i<0 || i>L.n-1){
		return ERROR;
	}
	*x = L.element[i];
	return OK;
}
#endif


