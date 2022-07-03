#include <REGX52.H>
void delay_ms(int n)//延时函数
{
	int i;
	while (n--)
	{
		for(i=0;i<115;i++);
	}
}
void main()
{
	//实现通过一个开关来控制led
	//if(P3_0==0)
	//{
		//P2=0xfe;
	//}
	//else
	//{
		//P2=0xff;
	//}
	
	
	
	//每按一下按钮灯暗灭交替
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



//实现按一下按钮，初始为0的二进制加1，用led显示
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

//功能：当按下P3_0的按钮led向右边亮，按下P3_1的按钮灯向左边亮。
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
				if(i>0x80)//当第八个灯亮时再按一下P30回到第一个灯亮
				{
					i=1;
				}
				P2=~i;
				while (P3_0==0);//当P3_0按钮松开时继续下去，不松开在这里空循环
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