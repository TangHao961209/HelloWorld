#include <iostream>
#include <string.h>
/*������ʾvar�е�ÿ���ֽڵĸ���������λ*/
void showbits(int var) {
	typedef unsigned char uc;
	uc* p = (uc *) &var; //�ӵ�λ����λ,�Ͷ��ֽڼ����
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

static int main1() {   //����main1������ͨ��static�ؼ�������
	int var = 96;
	showbits(var);
	return 0;
}
