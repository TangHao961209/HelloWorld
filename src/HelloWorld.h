#include "other.h"
#ifndef Hello_World
#define Hello_World
	#ifdef Hello_World
		typedef struct demo{
			//char name[MAX_NAME_LENGTH];
			char name[20];
			int  years;
		}demo1;
		const char* dbtest(int a);  //��������
		//��������Ϊinline��:��������
		inline const char* dbtest(int a) {  //����ʵ�֣�inline ��һ��"����ʵ�ֵĹؼ���"
		    return (a % 2 > 0) ? "��" : "ż";
		}
   #endif
#endif
