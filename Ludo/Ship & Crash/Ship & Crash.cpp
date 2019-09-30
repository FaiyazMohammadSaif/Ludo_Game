
# include "iGraphics.h"
int step=1,ship_x,ship_y,sx,sy;
int gun_x,gun_y,gx,gy;
int missile=0,missile_x,missile_y,my,crash=0,temp1;
int temp2,tp,ship_num=0,target_fill=0,life=3;

void iDraw()
{	
	iClear();
	if(step==1)
	{
		iShowBMP(0, 0, "p_back1.bmp");
		iSetColor(0, 0, 255);
		iFilledRectangle(ship_x+18, ship_y-12, 50, 25);
		iSetColor(238, 118, 0);
		iFilledRectangle(ship_x+15, ship_y-10, 56, 23);
		iFilledRectangle(ship_x+12, ship_y-8, 62, 21);
		iFilledRectangle(ship_x+9, ship_y-6, 68, 19);
		iFilledRectangle(ship_x+6, ship_y-4, 74, 17);
		iFilledRectangle(ship_x+3, ship_y-2, 80, 15);
		iFilledRectangle(ship_x, ship_y, 86, 13);
		iSetColor(0, 0, 255);
		iFilledRectangle(ship_x, ship_y+10, 86, 3);
		iSetColor(255, 64, 64);
		iFilledEllipse(gun_x, gun_y, 10, 25);
		iSetColor(34, 139, 34);
		iFilledEllipse(gun_x, gun_y, 8, 23);
		iSetColor(255, 64, 64);
		iFilledEllipse(gun_x+50, gun_y, 10, 25);
		iSetColor(34, 139, 34);
		iFilledEllipse(gun_x+50, gun_y, 8, 23);
		iSetColor(255, 64, 64);
		iFilledRectangle(gun_x+15, gun_y, 20, 60);
		iSetColor(34, 139, 34);
		iFilledRectangle(gun_x+17, gun_y+2, 16, 56);
		iSetColor(255, 64, 64);
		iFilledRectangle(gun_x, gun_y, 50, 10);
		iSetColor(34, 139, 34);
		iFilledRectangle(gun_x+2, gun_y+2, 46, 6);
		if(missile==1)
		{
			iSetColor(255, 64, 64);
			iFilledCircle(missile_x+7, missile_y+40, 10);
		    iFilledRectangle(missile_x, missile_y, 14, 40);
			iSetColor(34, 139, 34);
		    iFilledRectangle(missile_x+2, missile_y+2, 10, 36);
			iSetColor(255, 64, 64);
			iFilledCircle(missile_x+7, missile_y-8, 10, 6);
		}
		if(crash==1)
		{
			missile_x=610;
			temp1=ship_x;
			temp2=ship_y;
			missile_x=5000;
	        missile_y=2000;	
	        ship_x=1000;
	        ship_y=480;
			iSetColor(255, 64, 64);
			iFilledCircle(temp1+10, temp2, 10, 6);
			iSetColor(255, 64, 64);
			iFilledCircle(temp1+5, temp2, 10, 6);
			iSetColor(255, 64, 64);
			iFilledCircle(temp1-5, temp2, 10, 6);
			iSetColor(255, 64, 64);
			iFilledCircle(temp1-10, temp2, 10, 6);
			crash=0;
		}
		iSetColor(0, 0, 255);
		iFilledRectangle(temp1+28, temp2-32, 50, 25);
		iSetColor(238, 118, 0);
		iFilledRectangle(temp1-45, temp2-43, 56, 23);
		iFilledRectangle(temp1-35, temp2-30, 62, 21);
		iFilledRectangle(temp1+19, temp2-16, 68, 19);
		iFilledRectangle(temp1+26, temp2-24, 74, 17);
		iFilledRectangle(temp1+33, temp2-12, 80, 15);
		iFilledRectangle(temp1, temp2, 86, 13);
		iSetColor(0, 0, 255);
		iFilledRectangle(temp1, temp2+10, 86, 3);
	}
}

void iMouseMove(int mx, int my)
{
}

void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
	}
}

void iKeyboard(unsigned char key)
{
	if(key == 'p')
	{
		gx=0;
		my=0;
		iPauseTimer(0);
	}
	if(key == 'r')
	{
		gx=15;
		my=10;
		iResumeTimer(0);
	}
}

void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
	if(key == GLUT_KEY_UP)
	{
		if(step==1 && missile_y>=600)
		{missile=1;
		missile_x=gun_x+18;
		missile_y=gun_y+72;
		PlaySound("sounds/missile_reliese.wav",NULL,SND_ASYNC);}
	}
	if(key == GLUT_KEY_LEFT)
	{
		if(gun_x>=30)
		{gun_x -=gx;}
	}
	if(key == GLUT_KEY_RIGHT)
	{
		if(gun_x<=930)
		{gun_x +=gx;}	
	}
}
void crash_dust()
{
	temp2 -=tp;
}
void missile_through()
{
	missile_y +=my;
}
void ship_pos()
{
	ship_x -=sx;
	if(ship_x<-50)
	{
	    if((ship_num-target_fill)>=2)
		{step=2;}
		ship_x=1000;
		ship_num=ship_num+1;
	}
	if(missile_y>600)
	{missile=0;}
	if((missile_x>=ship_x-14)&&(missile_x<=ship_x+94)&&(missile_y>=ship_y-62)&&(missile_y<=ship_y+23))
	{
		missile_y=610;
		target_fill=target_fill+1;
		crash=1;
		PlaySound("sounds/ship_crash.wav",NULL,SND_ASYNC);

	}
}
void gun_position()
{
}

int main()
{
	iSetTimer(10, ship_pos);
	iSetTimer(5, missile_through);
	iSetTimer(2, crash_dust);
	//iSetTimer(50, gun_position);
	tp=10;
	sx=10;
	gx=5;
	my=10;
	missile_x=5000;
	missile_y=2000;	
	ship_x=1000;
	ship_y=480;
	gun_x=300;
	gun_y=30;
	printf("%d\n",target_fill);
	printf("%d\n",ship_num);
	iInitialize(1000, 600, "demo");
	return 0;
}	