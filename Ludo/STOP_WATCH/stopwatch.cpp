/*************************************************/
/*                 STOP WATCH                    */
/*            STUDENT ID - 0905015               */
/*            SALLMAN SHAMIL SAKIB               */
/*                     CSE                       */
/*                    -BUET                      */
/*************************************************/

# include "iGraphics.h"
#include<math.h>

double px[100],py[100],r=3.1415926/180;
double secx=250,secy=290,minx,miny,horx,hory,hx[100],hy[100],mx[100],my[100];
int v,point=1,dg=6,length=90,i,j=1,k=1,l=1,horlen=60,minlen=75,start=0,nom;
int secpos=280,horpos=220,minpos=250,horr=0,secc=0,minn=0,h=1;
char num[5],nm[5],valsec[5],valmin[5],valhor[5];

void spot()                       /*POSITION OF POINTS IN CYCLING ORDER*/
{
	for(i=0,dg=0;i<15;i++,dg=dg+6)
	{
	    px[i]=250+length* sin(r*dg);
		py[i]=290-(length-(length*cos(r*dg)));
	}
	for(i=15,dg=0;i<30;i++,dg=dg+6)
	{
	    px[i]=340-(length-(length*cos(r*dg)));
		py[i]=200-length*sin(r*dg);
	}
	for(i=30,dg=0;i<45;i++,dg=dg+6)
	{
	    px[i]=250- length* sin(r*dg);
		py[i]=110+(length-(length*cos(r*dg)));
	}
	for(i=45,dg=0;i<60;i++,dg=dg+6)
	{
	    px[i]=160+(length-(length*cos(r*dg)));
		py[i]=200+length*sin(r*dg);
	}
}
void hor()                       /*POSITION OF HOUR ARM */
{
	for(i=0,dg=0;i<15;i++,dg=dg+6)
	{
	    hx[i]=250+ horlen* sin(r*dg);
		hy[i]=260-(horlen-(horlen*cos(r*dg)));
	}
	for(i=15,dg=0;i<30;i++,dg=dg+6)
	{
	    hx[i]=310-(horlen-(horlen*cos(r*dg)));
		hy[i]=200-horlen*sin(r*dg);
	}
	for(i=30,dg=0;i<45;i++,dg=dg+6)
	{
	    hx[i]=250- horlen* sin(r*dg);
		hy[i]=140+(horlen-(horlen*cos(r*dg)));
	}
	for(i=45,dg=0;i<60;i++,dg=dg+6)
	{
	    hx[i]=190+(horlen-(horlen*cos(r*dg)));
		hy[i]=200+horlen*sin(r*dg);
	}
}
void mint()                        /*POSITION OF MINUTE ARM*/
{
	for(i=0,dg=0;i<15;i++,dg=dg+6)
	{
	    mx[i]=250+ minlen*sin(r*dg);
		my[i]=275-(minlen-(minlen*cos(r*dg)));
	}
	for(i=15,dg=0;i<30;i++,dg=dg+6)
	{
	    mx[i]=325-(minlen-(minlen*cos(r*dg)));
		my[i]=200-minlen*sin(r*dg);
	}
	for(i=30,dg=0;i<45;i++,dg=dg+6)
	{
	    mx[i]=250- minlen*sin(r*dg);
		my[i]=125+(minlen-(minlen*cos(r*dg)));
	}
	for(i=45,dg=0;i<60;i++,dg=dg+6)
	{
	    mx[i]=175+(minlen-(minlen*cos(r*dg)));
		my[i]=200+minlen*sin(r*dg);
	}
}

void hou_r()                     /*POSITIN CHANGING OF HOUR ARM*/
{
	if(horr>9)horpos=215;
	if(horr<=9)horpos=220;
	if(start==1)
	{
			if(l%60==0 && l>0)l=0;
	        horx=hx[l];
	        hory=hy[l];
		    l++;
		    if(horr<=60)horr=horr+1;
		    if(horr==61)horr=1;
	}
}

void watch_design()
{
	iSetColor(0, 0, 0);
	iFilledCircle(250 ,200, 130, 10);
	iSetColor(191, 239, 255);
	iFilledCircle(250 ,200, 125, 10);
	iSetColor(0, 0, 0);
	iFilledCircle(250 ,200, 105, 100);
	iSetColor(245, 255, 250);
	iFilledCircle(250 ,200, 100);
}

void sec_arm()
{
	iSetColor(9, 249, 17);
	iLine(250, 200, secx, secy);
	iLine(249, 199, secx, secy);
	iLine(248, 198, secx, secy);
}

void min_arm()
{
	iSetColor(0, 0, 205);
	iLine(250, 200, minx, miny);
	iLine(249, 199, minx, miny);
	iLine(248, 198, minx, miny);
	iLine(251, 201, minx, miny);
	iLine(252, 202, minx, miny);
}

void hour_arm()
{
	iSetColor(255, 64, 64);
	iLine(250, 200, horx, hory);
	iLine(251, 201, horx, hory);
	iLine(252, 202, horx, hory);
	iLine(253, 203, horx, hory);
	iLine(249, 199, horx, hory);
	iLine(248, 198, horx, hory);
	iLine(247, 197, horx, hory);
}

void centre_of_watch()
{
	iSetColor(255, 64, 64);
	iFilledCircle(250 ,200, 8);
	iSetColor(0, 0, 205);
	iFilledCircle(250 ,200, 6);
	iSetColor(9, 249, 17);
	iFilledCircle(250 ,200, 3);
}

void digital_time()
{
	iSetColor(9, 249, 17);
    strcpy(valsec, itoa(secc, nm,10));
	iText(secpos, 50, valsec, GLUT_BITMAP_HELVETICA_18);
	iSetColor(0, 0, 205);
    strcpy(valmin, itoa(minn, nm,10));
	iText(minpos, 50, valmin, GLUT_BITMAP_HELVETICA_18);
	iSetColor(255, 64, 64);
    strcpy(valhor, itoa(horr, nm,10));
	iText(horpos, 50, valhor, GLUT_BITMAP_HELVETICA_18);
}

void show_number_in_bar()
{
	for(i=0,nom=0;i<90;i++)
	{
		if(i==0)
		{iSetColor(205, 127, 50);
		nom=12;
		strcpy(num,itoa(nom, nm, 10));
		iText(px[i]-4, py[i]-4, num, GLUT_BITMAP_HELVETICA_10);
		nom=0;}
		if((i%5)==0 && i>0)
		{iSetColor(205, 127, 50);
		nom++;
		strcpy(num,itoa(nom, nm, 10));
		iText(px[i]-4, py[i]-4, num, GLUT_BITMAP_HELVETICA_10);}
		if((i%5)!=0)
		{iSetColor(205, 127, 50);
		iPoint(px[i], py[i], 1);}
	}
}

void iDraw()
{
	iClear();
	iSetColor(127, 127, 127);
	iFilledRectangle(0 , 0, 500, 400);
	iSetColor(208, 32, 144);
	iText(165, 370, "STOP - WATCH", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(70, 344, "PRODUCTION OF SHAMIL G.of I.", GLUT_BITMAP_TIMES_ROMAN_24);
	if(start==0)
	{iText(175, 10, "Press 's' to START", GLUT_BITMAP_HELVETICA_18);}
	if(start==1)
	{iText(175, 10, "Press 'd' to PAUSE", GLUT_BITMAP_HELVETICA_18);}
	watch_design();
    digital_time();
	sec_arm();
	min_arm();
	if(minn==60 && h==1){hou_r();h=2;}
	if(minn==1){h=1;}
	hour_arm();
	centre_of_watch();
	spot();
	if(start==0)mint();hor();
	show_number_in_bar();
}
void iMouseMove(int mx, int my)
{
}
void iMouse(int button, int state, int mx, int my)
{
}
void iKeyboard(unsigned char key)
{
	if(key == 's')
	{start=1;}
	if(key == 'd')
	{start=0;}
}
void iSpecialKeyboard(unsigned char key)
{
}
void secon_d()
{
	if(secc>9)secpos=275;
	if(secc<=9)secpos=280;
	if(start==1)
	{
		if(j%60==0 && j>0)j=0;
	    secx=px[j];
	    secy=py[j];
	    j++;
		if(secc<=60)secc=secc+1;
		if(secc==61)secc=1;
	}
}
void minut_e()
{
	if(minn>9)minpos=245;
	if(minn<=9)minpos=250;
	if(start==1)
	{
	        if(k%60==0 && k>0)k=0;
	        minx=mx[k];
	        miny=my[k];
	        k++;
		    if(minn<=60)minn=minn+1;
		    if(minn==61)minn=1;
	}
}

int main()
{	
    iSetTimer(10, secon_d);
    iSetTimer(1000, minut_e);
	px[0]=250;
	py[0]=290;
	secx=250;
	secy=290;
	minx=250;
	miny=275;
	horx=250;
	hory=260;
	iInitialize(500, 400, "STOP WATCH");
	return 0;
}	