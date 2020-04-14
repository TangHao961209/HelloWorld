#include "other.h"
#ifndef Hello_World
#define Hello_World
	#ifdef Hello_World
		typedef struct demo{
			//char name[MAX_NAME_LENGTH];
			char name[20];
			int  years;
		}demo1;
		const char* dbtest(int a);  //函数声明
		//函数定义为inline即:内联函数
		inline const char* dbtest(int a) {  //函数实现，inline 是一种"用于实现的关键字"
		    return (a % 2 > 0) ? "奇" : "偶";
		}
   #endif
#endif
