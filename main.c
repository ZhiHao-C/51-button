#include <REGX52.H>
void delay_ms(int n)//��ʱ����
{
	int i;
	while (n--)
	{
		for(i=0;i<115;i++);
	}
}
void main()
{
	//ʵ��ͨ��һ������������led
	//if(P3_0==0)
	//{
		//P2=0xfe;
	//}
	//else
	//{
		//P2=0xff;
	//}
	
	
	
	//ÿ��һ�°�ť�ư�����
//	P2_0=1;
//	while(1)
//	{
//		if(P3_0==0)
//		{
//			delay_ms(20);
//			if(P3_0==0)
//			{
//				P2_0=!P2_0;
//			}
//			while(!P3_0);
//		}
//	}



//ʵ�ְ�һ�°�ť����ʼΪ0�Ķ����Ƽ�1����led��ʾ
//	unsigned char i=0;
//	while(1)
//	{
//		if(P3_0==0)
//		{
//			delay_ms(20);
//			if(P3_0==0)
//			{
//				i++;
//				P2=~i;
//				while(P3_0==0);
//				delay_ms(20);
//			}
//		}
//	}

//���ܣ�������P3_0�İ�ťled���ұ���������P3_1�İ�ť�����������
	unsigned int i=1;
	P2=0xfe;
	while (1)
	{
		if(P3_0==0)
		{
			delay_ms(20);
			if(P3_0==0)
			{
				i=i<<1;
				if(i>0x80)//���ڰ˸�����ʱ�ٰ�һ��P30�ص���һ������
				{
					i=1;
				}
				P2=~i;
				while (P3_0==0);//��P3_0��ť�ɿ�ʱ������ȥ�����ɿ��������ѭ��
				delay_ms(20);
			}
		}
		else if(P3_1==0)
		{
			delay_ms(20);
			if(P3_1==0)
			{
				i=i>>1;
				if(i==0)
				{
					i=0x80;
				}
				P2=~i;
				while (P3_1==0);
				delay_ms(20);
			}
		}
	}
	






}