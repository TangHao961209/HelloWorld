/*
 * other.h
 *
 *  Created on: 2020��4��8��
 *      Author: b1508
 */

#ifndef OTHER_H_
#define OTHER_H_

extern const int MAX_NAME_LENGTH = 20 ;  //������������ʹ�ó�������
extern void printok(char *name1);
//extern char name[MAX_NAME_LENGTH];
typedef int ElemType;
typedef int Status;
typedef struct
{
	int n;           //˳��������ݵĸ���
	int maxLength;   //��󳤶�
	ElemType *element;  //Ԫ�ص����ͣ�ָ�����
}SeqList;   //˳���
/*
 * ˳���Ĳ���
 */
extern Status Find(SeqList L,int i,ElemType *x);   //����
#endif /* OTHER_H_ */
