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
		//函数定义为inline即:内联函数  通过将函数体直接插入调用处来实现的，这样可以大大减少由函数调用带来的开销，从而提高程序的运行效率。一般来说inline用于定义类的成员函数。
		//内联函数的确占用空间，但是内联函数相对于普通函数的优势只是省去了函数调用时候的压栈、跳转、返回的开销。我们可以理解为内联函数是以空间换取时间。
		inline const char* dbtest(int a) {  //函数实现，inline 是一种"用于实现的关键字"
		    return (a % 2 > 0) ? "奇" : "偶";
		}
   #endif
#endif
