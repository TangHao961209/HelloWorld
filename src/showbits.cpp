#include <iostream>
#include <string.h>
/*依次显示var中的每个字节的各个二进制位*/
void showbits(int var) {
	typedef unsigned char uc;
	uc* p = (uc *) &var; //从低位到高位,低端字节计算机
	uc byte;
	byte = *p;
	for (int k = 0; k <= 4; k++)
	{
		byte = *p;
		for (int i = 0; i <=7; i++)
		{
			putchar(0x80 & byte ? '1' : '0');
			byte<<=1;
		}
		putchar(' ');
		p++;
	}
	puts("");
}

static int main1() {   //两个main1函数，通过static关键字声明
	int var = 96;
	showbits(var);
	return 0;
}
