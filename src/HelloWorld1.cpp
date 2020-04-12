#include <stdio.h>
#include <iostream>
//#include <execinfo.h>  特定于 Linux的
#include<unistd.h>
#include<stdlib.h>
//#include <libunwind.h> 特定于 Linux的


using namespace std;
const int max_length = 5;
void printok(char *name1){

	printf("%s Hello World \n",name1);
	cout<<name1<<endl;
	char test[max_length] = {'B','o','b'};  //并没有报错？？？   栈上创建
	char *test1 = new char[max_length];  //堆上创建
	test1 = "Bob";
	//char test[max_length] = "Bob";    //Bob是字符常量const char[4]
	//cout<<&test<<endl;
	//cout<<"test = "<<*test<<endl;
	//cout<<&test1<<endl;     //数组变量的内存地址
	//cout<<*test1<<endl;    //*数组变量首地址的值
	printf("test = %s,*test = %c,&(*test) = %x,&test = %x \n",test,*test,&(*test),&test);
	printf("test1 = %s,*test1 = %c,&(*test1) = %x,&test1 = %x \n",test1,*test1,&(*test1),&test1);
	for(int i = 0;i <= (int)(sizeof(test)/sizeof(test[0]))-1;i++){
		printf("test[%d] = %c \t",i,test[i]);
		if(i == (int)(sizeof(test)/sizeof(test[0]))-1 ){
			cout<<endl;
		}
	}
	//delete[] test1; //删除数组空间  什么时候调用？

	 //分配动态一维数组
	    int *arr=new int[max_length];
	    arr[0] =1;
	    printf("arr[0] = %d \n",arr[0]);
/*
	    for(int i=0;i<max_length;i++)
	        cin>>arr[i];
	    for(int i=0;i<max_length;i++)
	       cout<<arr[i]<<" ";
*/
	    //释放arr数组
	    delete[] arr;
	    printf("arr[0] = %d \n",arr[0]);
}
/*
 * just for linux
 */
#ifdef Linux
void debugfunction(void)
{
   int j, nptrs;
   #define SIZE 100
   void *buffer[100];
   char **strings;
   nptrs = backtrace(buffer, SIZE);
   printf("backtrace() returned %d addresses\n", nptrs);
   /* The call backtrace_symbols_fd(buffer, nptrs, STDOUT_FILENO)
    *  would produce similar output to the following: */

   strings = backtrace_symbols(buffer, nptrs);
   if (strings == NULL) {
       perror("backtrace_symbols");
       exit(EXIT_FAILURE);
   }

   for (j = 0; j < nptrs; j++)
       printf("%s\n", strings[j]);
   free(strings);
}
#endif
#ifdef Linux
// Call this function to get a backtrace.
void backtrace() {
  unw_cursor_t cursor;
  unw_context_t context;

  // Initialize cursor to current frame for local unwinding.
  unw_getcontext(&context);
  unw_init_local(&cursor, &context);

  // Unwind frames one by one, going up the frame stack.
  while (unw_step(&cursor) > 0) {
    unw_word_t offset, pc;
    unw_get_reg(&cursor, UNW_REG_IP, &pc);
    if (pc == 0) {
      break;
    }
    printf("0x%lx:", pc);

    char sym[256];
    if (unw_get_proc_name(&cursor, sym, sizeof(sym), &offset) == 0) {
      printf(" (%s+0x%lx)\n", sym, offset);
    } else {
      printf(" -- error: unable to obtain symbol name for this frame\n");
    }
  }
}
#endif
