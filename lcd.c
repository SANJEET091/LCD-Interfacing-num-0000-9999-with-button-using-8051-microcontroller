#include <REGX51.H>
/********Single pin declaration***********/
sbit sw=P3^3;
sbit rs=P3^0;
sbit rw=P3^1;
sbit en=P3^2;
/********Function Prototype***********/
void lcd_init();
void lcd_data(char);
void lcd_cmd(char);
void lcd_data_string(char[]);
void delay(int);
/********Main Function Definition***********/
void main()
{
	int x,n1,n2,n3,n4,n5,n6;
	sw=1;
	lcd_init();
lcd_data_string("DTMF Based Home ");
	lcd_cmd(0xc0);
lcd_data_string("   App control  ");
	delay(300);
	/*
	lcd_cmd(0x80);
lcd_data_string("Project Prepared");
	lcd_cmd(0xc0);
lcd_data_string("       By       ");
delay(500);
	lcd_cmd(0x80);
lcd_data_string(" Sourav Choubey ");
	lcd_cmd(0xc0);
lcd_data_string("     Sunny      ");
delay(500);
	lcd_cmd(0x80);
lcd_data_string("      Sumit     ");
	lcd_cmd(0xc0);
lcd_data_string("       Atul      ");	
	delay(500);
	lcd_cmd(0x80);
lcd_data_string("    Guided By    ");
	lcd_cmd(0xc0);
lcd_data_string("     Basak Sir   ");
	delay(500);
		*/
	lcd_cmd(0x01);//lcd clear

	while(1)
	{
		lcd_data_string(" Count:  ");
		for(x=0;x<=9999;x++)
		{
			n1=x%10;//6
			n2=x/10;//345
			n3=n2%10;//5
			n4=n2/10;//34
			n5=n4%10;//4
			n6=n4/10;//3
			lcd_data(n6+48);
			lcd_data(n5+48);
			lcd_data(n3+48);
			lcd_data(n1+48);
			while(sw==1)
			{
			
			}
			while(sw==0);
			lcd_cmd(0x89);
		}	
		lcd_cmd(0x01);
	}
}
/********Main Function End***********/
/********Other Function Definition***********/
void lcd_init()
{
	lcd_cmd(0x38);//5x7 matrix mode
	lcd_cmd(0x06);//Auto Right shift mode
	lcd_cmd(0x0E);//Display On cursor on mode
	lcd_cmd(0x80);//Home Position or 1st row 1st col mode
}
void lcd_cmd(char x)
{
	P2=x;rs=0;rw=0;en=1;delay(1);en=0;
}
void lcd_data(char x)
{
	P2=x;rs=1;rw=0;en=1;delay(10);en=0;
}
void lcd_data_string(char A[])
{
int x;
	for(x=0;A[x]!='\0';x++)
	{
		lcd_data(A[x]);
	}	
}
void delay(int m)
{
	int x,y;
	for(y=0;y<m;y++)
	for(x=0;x<1275;x++);
}