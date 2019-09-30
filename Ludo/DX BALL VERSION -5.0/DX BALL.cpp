# include "iGraphics.h"
# include <string.h>
# include <math.h>
# include <stdlib.h>

float ball_x,ball_y,dx,dy,bat_x;
int mox,boxx[100],boxy[100],i,wall,vanish,attach=0,compass,up=375;
float fx,bat_y,fy,mx=500,r=3.14159/180;
int level=-2,levscore=1,t=0,life=5,crossscore=84;

void start(void)
{
	bat_x=500;bat_y=30;ball_x = 500;ball_y = 55;	dx = 7;dy = 8;fx = 15;
    iSetColor(68, 54, 44);
    iFilledCircle(ball_x, ball_y, 14, 100);
	iSetColor(167, 164, 124);
	iFilledCircle(ball_x, ball_y, 11, 100);
    iSetColor(249, 125, 236);
	iText(10, 580, "Press p for pause, r for resume, END for exit.", GLUT_BITMAP_TIMES_ROMAN_24);
    iSetColor(255, 210, 0);
    iFilledEllipse(bat_x, bat_y, 100, 10);
	iSetColor(253, 105, 233);
	iFilledEllipse(bat_x, bat_y, 98, 8);
}

void box()
{
	for(i=0;i<84;i++)
	{
		iSetColor(219,219,112);
        iFilledRectangle(boxx[i],boxy[i],60,20);
		iSetColor(0,205,205);
		iFilledRectangle(boxx[i]+3,boxy[i]+3,54,14);
	}
}

void boxnum()
{
	for(i=0;i<14;i++)
	{
		boxx[i]=40+i*65;
		boxy[i]=520;
	}
	for(i=14;i<28;i++)
	{
		boxx[i]=40+(i-14)*65;
		boxy[i]=480;
	}
	for(i=28;i<42;i++)
	{
		boxx[i]=40+(i-28)*65;
		boxy[i]=440;
	}
	for(i=42;i<56;i++)
	{
		boxx[i]=40+(i-42)*65;
		boxy[i]=400;
	}
	for(i=56;i<70;i++)
	{
		boxx[i]=40+(i-56)*65;
		boxy[i]=360;
	}
	for(i=70;i<84;i++)
	{
		boxx[i]=40+(i-70)*65;
		boxy[i]=320;
	}
}

void iDraw()
{
	iClear();
	if(life==0)level=0;
	if(level==-2)
	{
		iShowBMP(100, 0, "first.bmp");
		iSetColor(0, 0, 0);
        iFilledRectangle(400, 100, 200, 50);
	    iSetColor(255, 36, 0);
		iFilledEllipse(500, 125, 100, 25);
	   	iSetColor(249, 125, 236);
	   	iText(450, 115, "Press Here", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if(level==-1)
	{
        iShowBMP(0, 0, "1.bmp");
		iSetColor(0, 0, 0);
		iFilledRectangle(400, 350, 200, 50);
		iSetColor(255, 36, 0);
	    iFilledEllipse(500, 375, 100, 25);
		iSetColor(0, 0, 0);
		iFilledRectangle(400, 250, 200, 50);
		iSetColor(255, 36, 0);
	    iFilledEllipse(500, 275, 100, 25);
		iSetColor(249, 125, 236);
		iText(450, 370, "Start Game", GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(249, 125, 236);
		iText(475, 270, "Exit", GLUT_BITMAP_TIMES_ROMAN_24);
	}
    if(level==0)
	{
	}
	if(level==1)
	{
        iShowBMP(0, 0, "1.bmp");
	    iSetColor(255, 255, 255);
        iFilledCircle(ball_x, ball_y, 14, 100);
	    iSetColor(255, 64, 64);
	    iFilledCircle(ball_x, ball_y, 11, 100);
        iSetColor(249, 125, 236);
	    iText(10, 580, "Press p for pause, r for resume, END for exit.", GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255, 64, 64);
		iText(up, 300, "Press UP to Start Game", GLUT_BITMAP_TIMES_ROMAN_24);
		if(fx==0 && up!=375)
		{
			iSetColor(255, 64, 64);
			iText(400, 300, "GAME PAUSED", GLUT_BITMAP_TIMES_ROMAN_24);
		}
        iSetColor(255, 210, 0);
     	iFilledEllipse(bat_x, bat_y, 100, 10);
	    iSetColor(255, 20, 147);
	    iFilledEllipse(bat_x, bat_y, 98, 8);
		iSetColor(255, 210, 0);
		iFilledCircle(bat_x-90, bat_y, 10);
		iSetColor(255, 20, 147);
		iFilledCircle(bat_x-90, bat_y, 7);
		iSetColor(255, 210, 0);
		iFilledCircle(bat_x+90, bat_y, 10);
		iSetColor(255, 20, 147);
		iFilledCircle(bat_x+90, bat_y, 7);
	    box();
	    if(t==0)boxnum();
	}
		if(level==2)
	{
        iShowBMP(0, 0, "1.bmp");
	    iSetColor(68, 54, 44);
        iFilledCircle(ball_x, ball_y, 14, 100);
	    iSetColor(167, 164, 124);
	    iFilledCircle(ball_x, ball_y, 11, 100);
        iSetColor(249, 125, 236);
	    iText(10, 580, "Press p for pause, r for resume, END for exit.", GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(255, 210, 0);
     	iFilledEllipse(bat_x, bat_y, 100, 10);
	    iSetColor(253, 105, 233);
	    iFilledEllipse(bat_x, bat_y, 98, 8);
		iSetColor(157, 214, 124);
		iFilledCircle(bat_x-95, bat_y, 5);
		iFilledCircle(bat_x+95, bat_y, 5);
        box();
	    if(t==0)boxnum();
	}
}

void iMouseMove(int mx, int my)
{
}

void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if((mx>=400) && (mx<=600) && (my>=350) && (my<=400) && (level==-1))
		{
			iSetColor(166, 42, 42);
		    iFilledRectangle(400, 350, 200, 50);
			PlaySound("sounds/s touchbat.wav",NULL,SND_ASYNC);
	 		level=1;
		}
		if((mx>=400) && (mx<=600) && (my>=250) && (my<=300) && (level==-1))
		{
			iSetColor(166, 42, 42);
		    iFilledRectangle(400, 350, 200, 50);
			exit(0);
		}
		if((mx>=400) && (mx<=600) && (my>=100) && (my<=150) && (level==-2))
		{
			level = -1;
		}
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{	
	}
}
void iKeyboard(unsigned char key)
{
	if(key == 'p')
	{
		fx=0;
		iPauseTimer(0);
	}
	if(key == 'r')
	{
		fx=15;
		iResumeTimer(0);
	}
	if(key == 'm')
	{
		level=-1;
	}
}
void iSpecialKeyboard(unsigned char key)
{
	if(key == GLUT_KEY_UP)
	{
		up=5000;
		if(attach==0)
		{
			dx = 4;
		    dy = 7;
		    fx = 15;
		}
	}
	if(key == GLUT_KEY_END)
	{exit(0);}
	if(key == GLUT_KEY_LEFT)
	{
		if(bat_x>110)
		{bat_x=bat_x-fx;}
	}
	if(key == GLUT_KEY_RIGHT)
	{
		if(bat_x<890)
		{bat_x=bat_x+fx;}
	}
}

void ball_direction()
{
	if((((ball_x>=bat_x-114) && (ball_x<=bat_x-104)) || ((ball_x>=bat_x+104) && (ball_x<=bat_x+114))) && (ball_y<=bat_y+24))
	{
		if(ball_x==0 || ball_x==1000){life=life-1;start();attach=0;}
		dx=12;
		dy = -dy;
		if((ball_x>=bat_x-114) && (ball_x<=bat_x-104) && ((vanish < ball_x) || (wall==1)))
		{dx = -dx;compass=0;}
		if((ball_x>=bat_x+104) && (ball_x<=bat_x+114) && ((vanish > ball_x) || (wall==2)) && (compass==1))
		{dx = -dx;compass=1;}
		dy = 45*tan (r*5); 
		PlaySound("sounds/s touchbat.wav",NULL,SND_ASYNC);
	}
	if((((ball_x>=bat_x-103) && (ball_x<=bat_x-94)) || ((ball_x>=bat_x+94) && (ball_x<=bat_x+103))) && (ball_y<=bat_y+24))
	{
		dx=12;
		dy = -dy;
		if((ball_x>=bat_x-103) && (ball_x<=bat_x-94) && ((vanish < ball_x) || (wall==1)))
		{dx = -dx;compass=0;}
		if((ball_x>=bat_x+94) && (ball_x<=bat_x+103) && ((vanish > ball_x) || (wall==2)) && (compass==1))
		{dx = -dx;compass=1;}
		dy = 10*tan (r*15); 
		PlaySound("sounds/s touchbat.wav",NULL,SND_ASYNC);
	}
	if((((ball_x>=bat_x-93) && (ball_x<=bat_x-84)) || ((ball_x>=bat_x+84) && (ball_x<=bat_x+93))) && (ball_y<=bat_y+24))
	{
		dx=12;
		dy = -dy;
		if((ball_x>=bat_x-93) && (ball_x<=bat_x-84) && ((vanish < ball_x) || (wall==1)))
		{dx = -dx;compass=0;}
		if((ball_x>=bat_x+84) && (ball_x<=bat_x+93) && ((vanish > ball_x) || (wall==2)) && (compass==1))
		{dx = -dx;compass=1;}
		dy = 8*tan (r*20); 
		PlaySound("sounds/s touchbat.wav",NULL,SND_ASYNC);
	}
	if((((ball_x>=bat_x-83) && (ball_x<=bat_x-74)) || ((ball_x>=bat_x+74) && (ball_x<=bat_x+83))) && (ball_y<=bat_y+24))
	{
		if(ball_x<974){dx=12;}
		if(ball_x>=974 && ball_x<986){ball_x=ball_x-12;dx=12;}
		dy = -dy;
		if((ball_x>=bat_x-83) && (ball_x<=bat_x-74) && ((vanish < ball_x) || (wall==1)))
		{dx = -dx;compass=0;}
		if((ball_x>=bat_x+74) && (ball_x<=bat_x+83) && ((vanish > ball_x) || (wall==2)) && (compass==1))
		{dx = -dx;compass=1;}
		dy = 7*tan (r*25); 
		PlaySound("sounds/s touchbat.wav",NULL,SND_ASYNC);
	}
	if((((ball_x>=bat_x-73) && (ball_x<=bat_x-64)) || ((ball_x>=bat_x+64) && (ball_x<=bat_x+73))) && (ball_y<=bat_y+24))
	{
		dx=10;
		dy = -dy;
		if((ball_x>=bat_x-73) && (ball_x<=bat_x-64) && ((vanish < ball_x) || (wall==1)))
		{dx = -dx;compass=0;}
		if((ball_x>=bat_x+64) && (ball_x<=bat_x+73) && ((vanish > ball_x) || (wall==2)) && (compass==1))
		{dx = -dx;compass=1;}
		dy = 6*tan (r*30); 
		PlaySound("sounds/s touchbat.wav",NULL,SND_ASYNC);
	}
	if((((ball_x>=bat_x-63) && (ball_x<=bat_x-54)) || ((ball_x>=bat_x+54) && (ball_x<=bat_x+63))) && (ball_y<=bat_y+24))
	{
		dx=10;
		dy = -dy;
		dy = 5*tan (r*35); 
		PlaySound("sounds/s touchbat.wav",NULL,SND_ASYNC);
	}
	if((((ball_x>=bat_x-53) && (ball_x<=bat_x-44)) || ((ball_x>=bat_x+44) && (ball_x<=bat_x+53))) && (ball_y<=bat_y+24))
	{
		dx=10;
		dy = -dy;
		dy = 5*tan (r*40); 
		PlaySound("sounds/s touchbat.wav",NULL,SND_ASYNC);
	}
	if((((ball_x>=bat_x-43) && (ball_x<=bat_x-34)) || ((ball_x>=bat_x+34) && (ball_x<=bat_x+43))) && (ball_y<=bat_y+24))
	{
		dx=10;
		dy = -dy;
		dy = 4*tan (r*43); 
		PlaySound("sounds/s touchbat.wav",NULL,SND_ASYNC);
	}
	if((((ball_x>=bat_x-33) && (ball_x<=bat_x-24)) || ((ball_x>=bat_x+24) && (ball_x<=bat_x+33))) && (ball_y<=bat_y+24))
	{
		dx=8;
		dy = -dy;
		dy = 4*tan (r*47); 
		PlaySound("sounds/s touchbat.wav",NULL,SND_ASYNC);
	}
	if((((ball_x>=bat_x-23) && (ball_x<=bat_x-14)) || ((ball_x>=bat_x+14) && (ball_x<=bat_x+23))) && (ball_y<=bat_y+24))
	{
		dx=5;
		dy = -dy;
		dy = 3*tan (r*50); 
		PlaySound("sounds/s touchbat.wav",NULL,SND_ASYNC);
	}
	if((((ball_x>=bat_x-13) && (ball_x<=bat_x-4)) || ((ball_x>=bat_x+4) && (ball_x<=bat_x+13))) && (ball_y<=bat_y+24))
	{
		dx=5;
		dy = -dy;
		dy = 3*tan (r*53);
		PlaySound("sounds/s touchbat.wav",NULL,SND_ASYNC);
	}
	if((((ball_x>=bat_x-0) && (ball_x<=bat_x-3)) || ((ball_x>=bat_x+0) && (ball_x<=bat_x+3))) && (ball_y<=bat_y+24))
	{
		if(ball_x==0 || ball_x==1000){life=life-1;start();attach=0;}
		if(ball_x>26){dx=12;}
		if(ball_x>=12 && ball_x<26){ball_x=ball_x+12;dx=12;}
		dx=5;
		dy = -dy;
		dy = 3*tan (r*56);
		PlaySound("sounds/s touchbat.wav",NULL,SND_ASYNC);
	}
}
void ballChange()
{
	ball_x += dx;
	ball_y += dy;
	if(ball_x >= 986 || ball_x <= 14)dx = -dx;
	if(ball_x >= 986){wall=2;}
	if(ball_x <= 14) {wall=1;}
	if(ball_y >= 586)dy = -dy;
	if(ball_y <= 0){life=life-1;start();attach=0;}
	ball_direction();
	for(i=0;i<84;i++)
	{
		if(ball_x>=boxx[i]-11 && ball_x<=boxx[i]-14 && ball_y>=boxy[i] && ball_y<=boxy[i]+20 )
		{
		    attach=1;
	        dx=-dx;
			PlaySound("sounds/break.wav",NULL,SND_ASYNC);
			levscore++;
			if((levscore%crossscore)==0)
			{
		        level=level+1;
				t=0;
			}
			boxx[i]=5000;
			box();
			level=1;
			t=1;
		}

		if(ball_x>=boxx[i]+70 && ball_x<=boxx[i]+74 && ball_y>=boxy[i] && ball_y<=boxy[i]+20 )
		{
			attach=1;
			dx=-dx;
			PlaySound("sounds/break.wav",NULL,SND_ASYNC);
			levscore++;
			if((levscore%crossscore)==0)
			{
				level=level+1;
				t=0;
			}
			vanish=boxx[i];
			boxx[i]=5000;
			box();
			level=1;
			t=1;
		}
		if(ball_x>=boxx[i]-15 && ball_x<=boxx[i]+69 && ball_y>=boxy[i]-14 &&ball_y<=boxy[i]+34)
		{
			attach=1;
			dy=-dy;
			PlaySound("sounds/break.wav",NULL,SND_ASYNC);
			levscore++;
			if((levscore%crossscore)==0)
			{
				level=level+1;
				t=0;
			}
			boxx[i]=5000;
			box();
			level=1;
			t=1;
		}
	}
}
void batChange()
{
	/*if(mox<100)
	{mox=mox+105;}
	if(mox>900)
	{mox=mox-100;}
	if(bat_x<mox && bat_x>0)   // FOR MOUSE MOVING GAME
	{bat_x += fx;}
	if(bat_x<mox && bat_x<0)
	{bat_x -= fx;}
	if(bat_x>mox && bat_x>0)
	{bat_x -= fx;}*/
	if(bat_x <= 100 || bat_x >= 900)fx = -fx;
}
int main()
{
	iSetTimer(1, ballChange);
	iSetTimer(10, batChange);
	dx = 0;
	dy = 0;
	fx = 0;
	mx = 0;
	ball_x = 500;
	ball_y = 55;
	bat_x = 500;
    bat_y = 30;
	iInitialize(1000, 600, "SAKIB");
	return 0;
}