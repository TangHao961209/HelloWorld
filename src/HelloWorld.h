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
		//��������Ϊinline��:��������  ͨ����������ֱ�Ӳ�����ô���ʵ�ֵģ��������Դ������ɺ������ô����Ŀ������Ӷ���߳��������Ч�ʡ�һ����˵inline���ڶ�����ĳ�Ա������
		//����������ȷռ�ÿռ䣬�������������������ͨ����������ֻ��ʡȥ�˺�������ʱ���ѹջ����ת�����صĿ��������ǿ������Ϊ�����������Կռ任ȡʱ�䡣
		inline const char* dbtest(int a) {  //����ʵ�֣�inline ��һ��"����ʵ�ֵĹؼ���"
		    return (a % 2 > 0) ? "��" : "ż";
		}
   #endif
#endif
