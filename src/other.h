/*
 * other.h
 *
 *  Created on: 2020年4月8日
 *      Author: b1508
 */

#ifndef OTHER_H_
#define OTHER_H_

extern const int MAX_NAME_LENGTH = 20 ;  //数组声明必须使用常量定义
extern void printok(char *name1);
//extern char name[MAX_NAME_LENGTH];
typedef int ElemType;
typedef int Status;
typedef struct
{
	int n;           //顺序表中数据的个数
	int maxLength;   //最大长度
	ElemType *element;  //元素的类型，指针变量
}SeqList;   //顺序表
/*
 * 顺序表的操作
 */
extern Status Find(SeqList L,int i,ElemType *x);   //查找
#endif /* OTHER_H_ */
