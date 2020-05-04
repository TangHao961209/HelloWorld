/*
 * SeqList.cpp
 *
 *  Created on: 2020年4月12日
 *      Author: b1508
 */
//#include "other.h"
#include <stdlib.h>
#define ERROR 0
#define OK 1
#define Overflow 2  //上溢
#define Underflow 3 //下溢
#define Notresnet 4 //元素不存在
#define Duplicate 5//元素重复

/*
 * 线性表的初始化
 */
#ifdef Resolved
Status Init(SeqList *L,int mSize){
	L->maxLength = mSize;
	L->n = 0;
	L->element = malloc(sizeof(ElemType)*mSize);//开辟空间
	if(!L->element){
		return ERROR;
	}
	return OK;
}
/*
 * 顺序表查找Find(L,i,x)
 */
Status Find(SeqList L,int i,ElemType *x){
	if(i<0 || i>L.n-1){
		return ERROR;
	}
	*x = L.element[i];
	return OK;
}
#endif


