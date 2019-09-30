
 /* # include "iGraphics.h"

int ball_x, ball_y;/*ball_x=x co-ordinate of ball's centre    ball_y=y co-ordinate of ball's centre*/
/*int dx, dy;        /*this variables are for defining the value of changing ball_x,ball_y*/

/* 
	function iDraw() is called again and again by the system.
*/
/*void iDraw()
{
	//place your drawing codes here	

	iClear();

	iSetColor(255, 100, 10);	
	iFilledCircle(ball_x, ball_y, 15);

    iSetColor(255, 255, 255);
	iText(10, 10, "Press p for pause, r for resume, END for exit.");
}

/* 
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
/*void iMouseMove(int mx, int my)
{
	//place your codes here
}

/* 
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
/*void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed. 
*/
/*void iKeyboard(unsigned char key)
{
	if(key == 'p')
	{
		//do something with 'q'
		iPauseTimer(0);
	}
	if(key == 'r')
	{
		iResumeTimer(0);
	}
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use 
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6, 
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12, 
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP, 
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT 
*/
/*void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
	//place your codes for other keys here
}

void ballChange(){
	ball_x += dx;
	ball_y += dy;

	if(ball_x > 985 || ball_x < 15)dx = -dx;
	if(ball_y > 585 || ball_y < 15)dy = -dy;
}

int main()
{
	//place your own initialization codes here. 
	iSetTimer(10, ballChange);              /*after which time 'balchange' function will work*/
/*	dx = 5;
	dy = 7;
	ball_x = 500;
	ball_y = 15;
	iInitialize(1000, 600, "BallDemo");/*resolutiion of your code*/
   
/*	iSetColor(202,255,112);
	return 0;
}	






/*******************************************************
*     MYCPLUS Sample Code - http://www.mycplus.com     *
*                                                     *
*   This code is made available as a service to our   *
*      visitors and is provided strictly for the      *
*               purpose of illustration.              *
*                                                     *
* Please direct all inquiries to saqib at mycplus.com *
*******************************************************/

#include "calcu.h"	//to include functions of this project
//its definition can be found at the bottom of the code

void main()	//main()
{
menu:clrscr();  //before making clear the screen fully
enum boolean{false,true}; //set false to value of 0
//set true to value of 1

const char ESC=27;	//to exit
char dstring[80];	//string to store the numbers as chain
char tempbuf[80];	//temporary string
int numchars=0;		//to count no:of characters in str
char oper;		//to get the operator like +,-,*,/
boolean isfirst=true;	//allow the user to use the calc first time
boolean chain=false;	//chaining is allowed
double number1,number2,answer; //num 1,num2, and answer
char ch,mh;	//get the pressed key from user


int d,m;
d=DETECT;
	//detect the best driver on sys
initgraph(&d,&m,"F:\\tc\\bgi"); //set the graphics mode

setcolor(RED);
cartoon();
setfillstyle(SOLID_FILL,BLACK);
floodfill(20,20,CYAN);

b[26].setit(350,250,150,150,"");
b[27].setit(350,350,150,250,"");
  settextstyle(DEFAULT_FONT,0,1);
outtextxy(200,200,"DIARY (d)");		//to display the buttons
outtextxy(200,300,"CALC (c)");		//to choose calc and diary
b[28].setit(630,450,0,400,"");
setcolor(LIGHTBLUE);
settextstyle(DEFAULT_FONT,0,1);
outtextxy(130,420,"WELCOME TO THE DIGITAL WORLD:AVINASH");

setcolor(RED);
asettextstyle(DEFAULT_FONT,0,1);

	//get the response

menu_cartoon();
mh=getch();
if(mh=='c')	//if calc is choosed
{

cartoon();


b[26].colc(8,7);
setfillstyle(SOLID_FILL,BLACK);
floodfill(50,50,BLUE);

displayc();	//display the calc(fully)



   setcolor(LIGHTBLUE);

outtextxy(370,130,"f=factorial q=1/number.");
outtextxy(370,150,"w=log(n) with base 10.");	//abbreviations of calc
outtextxy(370,170,"e=sqrt(n) ");
outtextxy(370,190,"y=e^n b=x^y.");
outtextxy(370,210,"ESC=quit");


b[16].setit(630,400,0,250,"");	//for the results showing screen
setfillstyle(SOLID_FILL,BLACK);
floodfill(100,300,RED);



 calc_cartoon(ch);

while( (ch=getch()) !=ESC) //stop when escape is pressed
{





if(ch>='0'&&ch<='9'||ch=='.')
{

switch(ch)
{
case '0':b[0].colc(8,7);  break;
case '1':b[1].colc(8,7); break;
case '2':b[2].colc(8,7); break;
case '3':b[3].colc(8,7); break;
case '4':b[4].colc(8,7); break;	//all to change colors
case '5':b[5].colc(8,7); break;
case '6':b[6].colc(8,7); break;
case '7':b[7].colc(8,7); break;
case '8':b[8].colc(8,7); break;
case '9':b[9].colc(8,7); break;
case '.':b[10].colc(8,7); break;
}


dstring[numchars++]=ch;	//to insert the num into the string
dstring[numchars]='\0'; //at the last position insert NULL




if(atof(dstring)>99999999999999999999.99|| numchars>20)
{			//if numbers are too large to display
sound(200); nosound();	//then do not insert them in str
dstring[--numchars]='\0'; //keep adding NULLs
}
out(atof(dstring));	//display the final string


}

else if(ch=='/'||ch=='*'||ch=='-'||ch=='+'||ch=='='||ch=='b'||ch=='y'|ch=='f'||ch=='q'||ch=='w'||ch=='e')
{
strcpy(tempbuf,dstring); //store str1 to a temp str
numchars=0;
dstring[numchars]='\0';  // insert null in str1
out(atof(dstring)); //display the 0.000


if(isfirst) //if it is the first time
{
number1=(chain)?answer:atof(tempbuf);
isfirst=false;  //now it is not the first time
		//this must be the operator

a:switch(ch)	//read the operator
{
case '/':b[14].colc(8,7); out(0.0); oper='/'; break;
case '+':
case '=':
b[12].colc(8,7); out(0.0);
 oper='+';
break;
case '-':b[13].colc(8,7); out(0.0); oper='-';  break;
case '*':b[15].colc(8,7); out(0.0); oper='*'; break;
case 'f':b[18].colc(8,7); out(factorial(tempbuf));   	break;
case 'q':b[17].colc(8,7); out(inverse(tempbuf));  	 break;
case 'w':b[19].colc(8,7); out(loge(tempbuf));  break;
case 'e':b[20].colc(8,7); out(sqt(tempbuf));  break;
case 'y':b[22].colc(8,7); number1=exp(atof(tempbuf));
out(number1);      break;

case 'b':b[25].colc(8,7);
oper='b';
out(0);
break;
}
}


else
{
b[12].colc(8,7);
number2=atof(tempbuf);	//store temp str to num 2
switch(oper)	//calculate the answer
{
case '/':
if(number2==0.000000)
{
outtextxy(150,15,"Overflow");	//show error
}
else
{
answer=number1/number2;
}
break;

case '*':answer=number1*number2; break;
case '-':answer=number1-number2; break;
case '+':answer=number1+number2; break;
case 'b':answer=pow(number1,number2); break;
}


if(answer>999999999999999999999.99) //if ans is too large
{
setcolor(GREEN);
outtextxy(150,15,"Overflow");	//show error
}
else
{
out(answer); //display the answer
number1=answer; //set num1=ans
}
isfirst=false; //not the first num, must be operator
chain=true;	//now chain to calculate
}
}

else if(ch=='C'||ch=='c') //to clear the screen
{
b[11].colc(8,7);
isfirst=true; 	//now from here this is the first time again
chain=false;    //do not chain i.e no operator
numchars=0;
dstring[numchars]='\0'; //set the current string to NULL
out(0.0);	//display 0.000
}


else  //if any other key is pressed
{	//show delay and danger sounds
delay(100); sound(200); delay(300); nosound();
}



calc_cartoon(ch);


}


goto menu;	//goto the choosing menu


  }


else if(mh=='d') //if diary is chosen
{
cartoon();

setfillstyle(SOLID_FILL,BLACK);
floodfill(50,50,BLUE);
displaydss();
displayds();
displayd();	//display the diary and buttons



const char ESC=27,ENTER=13,BACK=8;
setcolor(BLACK);
outs("1. to enter, 2. to search, 3. to change device");


char m;


while(  (m=getch()) !=ESC)
{

if(m=='1')	//to enter things
{
displayds();
dstorage d;

char ch;


do
{

fstream file("stored.DAT",ios::out|ios::in|ios::app);
		//create the file to store name and numbers


displayds();
displaydss();



char name[25];
char till;
do
{
setcolor(BLACK);
outs("Enter the name(max 10 characters): ");
		//ask to enter name

int y=0;
char c;
while( (c=getch()) !=ENTER)
{




  gettc(c);
if(c==BACK)
{

name[--y]='\0';

displaydss();

}


else
{
name[y++]=c;
}

name[y]='\0';
setcolor(CYAN);

outss(name);


}


stop:outs("Want to enter again(y/n): ");



till=getch();
gettc(till);



if(till=='y')
{
y=0;
displayds();
displaydss();
name[0]='\0';
}





else
{
strcpy(d.info,name);		//finally copy the name to d.info
}
}
while(till=='y');



displayds();



do
{




setcolor(CYAN);
again:outs("Enter the phonenumber: ");
			//prompt to enter phone number
displaydss();


char pass[25];
int z=0;
char c;
while(  (c=getch())  !=ENTER)
{
gettc(c);
if(c==BACK)		//if backspace is pressed
{
pass[--z]='\0';
displaydss();
}
else
{
pass[z++]=c;
}
pass[z]='\0';


setcolor(CYAN);
outss(pass);
}
outs("Want to enter again(y/n): ");


till=getch();
gettc(till);
if(till=='y')
{
displayds();

displaydss();

pass[0]='\0';
}
else
{
d.pass=atof(pass);
}


}
while(till=='y');



file.write((char*)&d,sizeof(d));	//finally write everthing to file


displaydss();
outs("want to enter more enteries(y/n): ");

file.close();

ch=getch();

gettc(ch);
}
while(ch=='y');	//continue loop if 'y' is entered



displayds();

  outs("1. to enter, 2. to search, 3. to change device");

}


else if(m=='2')		//to search
{


displayds();
displaydss();		//clear both outscreens

char ch,string[25];
int z=0;

char til;

do
{

outs("Enter the name(atleast the first character): ");
			//get the first character of name from user
while( (ch=getch()) !=ENTER)
{

gettc(ch);
if(ch==BACK)
{
string[--z]='\0';
displaydss();
}
else
{
string[z++]=ch;
}
string[z]='\0';
setcolor(CYAN);
outss(string);
}
displayds();

outs("Want to enter again(y/n): ");


til=getch();
if(til=='y')
{
z=0;

displayds();
displaydss();
}
}
while(til=='y');

dstorage d;

displaydss();



displayds();

displaydss();


fstream file1("stored.DAT",ios::out|ios::in|ios::binary);


file1.seekg(0);



while(file1.read((char*)&d,sizeof(dstorage)))
{


if(strncmpi(d.info,string,1)==0)	//if search is successful
{
outs("d to delete, n to see next");
outss(d.info);
char xg[20];
gcvt(d.pass,10,xg);
outtextxy(220,75,xg);




ch=getch();




if(ch=='d')	//if d is entered to delete the entry
{

del(d);
}
else if(ch=='n')
{

displaydss();
}

}


}


file1.close();


displaydss();
outs("1. to enter, 2. to search, 3. to device change");

}


else if(m=='3')	//change device menu
{
goto menu;
}

 else	//if any other key is pressed keep on displaying
 {

displayds();
displaydss();
outs("1. to enter, 2. to search, 3. to change device");

}
}

if(m==ESC)	//however is escape is entered
{
goto last;
}


}

if(mh==ESC)
{
last: theend();


}


closegraph(); //close the graphics sys before exit

}

//--------------------------------
//calcu.h
//---------------------------------

#include<fstream.h>	// for saving calculations
#include<math.h>	//for atof(), this converts string to float number
#include<stdio.h>	//for sprintf()
#include<stdlib.h>	//for atoi(), atof();
#include<graphics.h>	//for setcolor(),setfillstyle(),floodfill(),fillpoly() etc.
#include<conio.h>	//for clrscr(),getch()
#include<iostream.h>
#include<string.h>	//for strcpy(),strlen()
#include<dos.h>		//for sound(),delay()



//main codes

void displayc();		//to create the output screen and buttons
				//of calculator
void calc_cartoon(char ch);

void displayd();		//to do the above for diary


void cartoon();			//to show loading graphics

void theend();			//to show ending graphics


class button		//to create buttons
{

int x,y,xc,yc;
int x1,y1,x2,y2;
char u1[5];
public:
 button(int a=7,int b=8)
 {
 x=a;
 y=b;

 }

void colc(int a=7, int b=8);	//to give pressing effect to calc buttons
void cold(int a=7, int b=8);	//to give pressing effect to diary buttons


void setit(int x11=0,int y11=0,int x22=0, int y22=0,char u[5]="");
void draw();	//to draw buttons
}b[50];		//we can make atleast 50 buttons



void button::colc(int a, int b)	//to change border colors on pressings
{
displayc();
sound(2000);
x=a;
y=b;
draw();		//draw the button with color a,b
delay(50);
x=b;
y=a;
draw();		//draw the button with color b,a
nosound();	//whole change give pressing sensation
}

void button::cold(int a, int b)	//to change border colors on pressings
{

sound(2000);
x=a;
y=b;
draw();		//draw the button with color a,b
delay(50);
x=b;
y=a;
draw();		//draw the button with color b,a
nosound();	//whole change give pressing sensation
setcolor(CYAN);
}

void button::setit(int x11,int y11,int x22,int y22,char u[5])
{
strcpy(u1,u);
x1=x11;
y1=y11;		//this setit() to set the co-ordinates of various buttons
x2=x22;
y2=y22;
draw();
}

void button::draw()
{
setcolor(RED);
rectangle(x1,y1,x2,y2);			//buttons as rectangles
rectangle(x1-10,y1-10,x2+10,y2+10);
setfillstyle(SOLID_FILL,10);
floodfill(x1-20,y1-15,RED);
settextstyle(TRIPLEX_FONT,0,1);
outtextxy(x1-35,y1-39,u1);
line(x2,y2,x2+10,y2+10);
line(x2,y1,x2+10,y1-10);
line(x1,y2,x1-10,y2+10);
line(x1,y1,x1-10,y1-10);
setfillstyle(SOLID_FILL,x);
floodfill(x2+25,y2+5,RED);
floodfill(x2+5,y2+25,RED);
setfillstyle(SOLID_FILL,y);
floodfill(x1-25,y1-5,RED);
floodfill(x1-5,y1-25,RED);
}

void displayc()		//to create the output screen and buttons
{


int p[8]={10,10,620,10,620,40,10,40};
int p1[8]={0,0,630,0,630,50,0,50};
setcolor(RED);
setlinestyle(THICK_WIDTH,0,RED);
setfillstyle(SOLID_FILL,YELLOW);
fillpoly(4,p1); //create the output screen as polygon
setfillstyle(SOLID_FILL,RED);
fillpoly(4,p);
setcolor(RED);
line(0,0,10,10);
line(620,10,630,0);
line(0,50,10,40);
line(620,40,630,50);
setfillstyle(SOLID_FILL,7);	//till here to create the output screen

b[40].setit(630,450,0,400,"");

 settextstyle(DEFAULT_FONT,0,1);

outtextxy(130,420,"WELCOME TO THE DIGITAL WORLD:AVINASH");

b[41].setit(50,250,0,50,"");
settextstyle(DEFAULT_FONT,1,1);
outtextxy(25,100,"CALCULATOR");

b[0].setit(150,100,100,50,"0");	//now setting the coordinates of buttons
b[1].setit(200,100,150,50,"1");
b[2].setit(250,100,200,50,"2");
b[3].setit(150,150,100,100,"3");
b[4].setit(200,150,150,100,"4");
b[5].setit(250,150,200,100,"5");
b[6].setit(150,200,100,150,"6");
b[7].setit(200,200,150,150,"7");
b[8].setit(250,200,200,150,"8");
b[9].setit(150,250,100,200,"9");
b[10].setit(200,250,150,200,".");
b[11].setit(250,250,200,200,"C");
b[12].setit(300,100,250,50,"+=");
b[13].setit(300,150,250,100,"-");
b[14].setit(300,200,250,150,"/");
b[15].setit(300,250,250,200,"*");


b[17].setit(100,100,50,50,"q");
b[18].setit(100,150,50,100,"f");
b[19].setit(100,200,50,150,"w");
b[20].setit(100,250,50,200,"e");
b[21].setit(350,100,300,50,"t");
b[22].setit(350,150,300,100,"y");
b[23].setit(350,200,300,150,"g");
b[24].setit(630,250,350,50,"");
b[25].setit(350,250,300,200,"b");

}

void displayds()		//for the main output screen of diary
{

int p[8]={10,10,590,10,590,50,10,50};
int p1[8]={0,0,600,0,600,60,0,60};
setcolor(RED);
setlinestyle(THICK_WIDTH,0,RED);
setfillstyle(SOLID_FILL,YELLOW);
fillpoly(4,p1); //create the output screen as polygon

setfillstyle(SOLID_FILL,RED);
fillpoly(4,p);

setcolor(RED);
line(0,0,10,10);
line(590,10,600,0);
line(0,60,10,50);
line(590,60,600,60);


setfillstyle(SOLID_FILL,7);	//till here to create the output screen
setcolor(BLACK);



}

void displaydss()    //to create sub outscreen
{			//of diary



int p2[8]={10,70,590,70,590,200,10,200};
int p22[8]={0,60,600,60,600,210,0,210};
setcolor(RED);
setlinestyle(THICK_WIDTH,0,RED);
setfillstyle(SOLID_FILL,YELLOW);



		   //create the output screen as polygon
fillpoly(4,p22);
setfillstyle(SOLID_FILL,RED);

fillpoly(4,p2);
setcolor(RED);





line(0,60,10,70);
line(590,70,600,60);
line(0,210,10,200);
line(590,200,600,210);
setfillstyle(SOLID_FILL,7);	//till here to create the output screen
setcolor(CYAN);



}


void displayd()		//for buttons of diary
{


b[0].setit(50,260,0,210,"a");	//now setting the coordinates of buttons
b[1].setit(100,260,50,210,"b");
b[2].setit(150,260,100,210,"c");
b[3].setit(200,260,150,210,"d");
b[4].setit(250,260,200,210,"e");
b[5].setit(300,260,250,210,"f");
b[6].setit(350,260,300,210,"g");
b[7].setit(400,260,350,210,"h");
b[8].setit(450,260,400,210,"i");
b[9].setit(500,260,450,210,"j");
b[10].setit(550,260,500,210,"k");
b[11].setit(600,260,550,210,"l");
b[12].setit(50,310,0,260,"m");
b[13].setit(100,310,50,260,"n");
b[14].setit(150,310,100,260,"o");
b[15].setit(200,310,150,260,"p");
b[16].setit(250,310,200,260,"q");
b[17].setit(300,310,250,260,"r");
b[18].setit(350,310,300,260,"s");
b[19].setit(400,310,350,260,"t");
b[20].setit(450,310,400,260,"u");
b[21].setit(500,310,450,260,"v");
b[22].setit(550,310,500,260,"w");
b[23].setit(600,310,550,260,"x");
b[24].setit(50,360,0,310,"y");
b[25].setit(100,360,50,310,"z");
b[26].setit(150,360,100,310,"0");
b[27].setit(200,360,150,310,"1");
b[28].setit(250,360,200,310,"2");
b[29].setit(300,360,250,310,"3");
b[30].setit(350,360,300,310,"4");
b[31].setit(400,360,350,310,"5");
b[32].setit(450,360,400,310,"6");
b[33].setit(500,360,450,310,"7");
b[34].setit(550,360,500,310,"8");
b[35].setit(600,360,550,310,"9");
b[36].setit(600,400,0,360,"");


b[40].setit(600,450,0,400,"");

 settextstyle(DEFAULT_FONT,0,1);
outtextxy(130,420,"WELCOME TO THE DIGITAL WORLD:AVINASH");

outtextxy(250,378,"SPACE BAR");



}



void theend()   //THE ENDING CARTOON
{



setfillstyle(SOLID_FILL,BLACK);
floodfill(30,30,CYAN);
settextstyle(DEFAULT_FONT,0,2);


setcolor(RED);
setfillstyle(SOLID_FILL,LIGHTRED);
rectangle(620,300,0,200);

int i=0;
while(!kbhit())            //UNTILL A KEY IS PRESSED
{
floodfill(250,250,RED);
setcolor(i);
settextstyle(TRIPLEX_FONT,0,5);
outtextxy(20,200,"AVINASH CHANDER KASHYAP");
outtextxy(20,70,"Press any key to exit!");
outtextxy(200,250,"CLASS-XII");
settextstyle(DEFAULT_FONT,0,2);
setcolor(i);
outtextxy(10,150,"MADE BY:");
outtextxy(50,350,"THANK YOU FOR USING THIS SOFTWARE!");
delay(5);
i++;
}



}

void cartoon()		//to make loading graphics
{
setfillstyle(SOLID_FILL,BLACK);
floodfill(50,50,CYAN);
settextstyle(TRIPLEX_FONT,0,3);




 setcolor(LIGHTRED);

 rectangle(620,450,20,400);

for(int i=50;i<621;i++)
{
setcolor(i);
outtextxy(250,300,"LOADING....");

sound(i+590);
setfillstyle(SOLID_FILL,LIGHTRED);
int p[8]={20,400,i,400,i,450,20,450};
fillpoly(4,p);
delay(1);
}



for(i=0;i<300;i++)
{
setcolor(LIGHTRED);
rectangle(i+300,200+i,300-i,200-i);
delay(2);
}





nosound();

}


void menu_cartoon()     //THE MENU CARTOON
{
int i=0;
while(!kbhit())         //UNTILL  A KEY IS PRESSED
{
setcolor(i);
outtextxy(50,25,"to turn on diary press d");
outtextxy(50,40,"to turn on calc press c");
outtextxy(50,60,"ESC to exit");
delay(10);
i++;
}

}


void calc_cartoon(char ch)  //THE CALCULATOR CARTOON
{
char str[1];
str[0]=ch;
str[1]='\0';
int i=0;
while(!kbhit())
{
setcolor(i);
settextstyle(TRIPLEX_FONT,0,7);
outtextxy(100,280,"CALCULATOR");
i++;
setcolor(GREEN);
settextstyle(DEFAULT_FONT,0,1);
outtextxy(30,280,"KEY PRESSED ");
outtextxy(180,280,str);
}
setfillstyle(SOLID_FILL,BLACK);
floodfill(50,300,RED);
settextstyle(TRIPLEX_FONT,0,1);
}




void gettc(char c)	//to get the key pressed by user and show its sensation
{

		//on the screen buttons
switch(c)
{
case 'A':
case 'a':b[0].cold(8,7); break;
case 'B':
case 'b':b[1].cold(8,7); break;
case 'C':
case 'c':b[2].cold(8,7); break;
case 'D':
case 'd':b[3].cold(8,7); break;
case 'E':
case 'e':b[4].cold(8,7); break;
case 'F':
case 'f':b[5].cold(8,7); break;
case 'G':
case 'g':b[6].cold(8,7); break;
case 'H':
case 'h':b[7].cold(8,7); break;
case 'I':
case 'i':b[8].cold(8,7); break;
case 'J':
case 'j':b[9].cold(8,7); break;
case 'K':
case 'k':b[10].cold(8,7); break;
case 'L':
case 'l':b[11].cold(8,7); break;
case 'M':
case 'm':b[12].cold(8,7); break;
case 'N':
case 'n':b[13].cold(8,7); break;
case 'O':
case 'o':b[14].cold(8,7); break;
case 'P':
case 'p':b[15].cold(8,7); break;
case 'Q':
case 'q':b[16].cold(8,7); break;
case 'R':
case 'r':b[17].cold(8,7); break;
case 'S':
case 's':b[18].cold(8,7); break;
case 'T':
case 't':b[19].cold(8,7); break;
case 'U':
case 'u':b[20].cold(8,7); break;
case 'V':
case 'v':b[21].cold(8,7); break;
case 'W':
case 'w':b[22].cold(8,7); break;
case 'X':
case 'x':b[23].cold(8,7); break;
case 'Y':
case 'y':b[24].cold(8,7); break;
case 'Z':
case 'z':b[25].cold(8,7); break;
case '0':b[26].cold(8,7); break;
case '1':b[27].cold(8,7); break;
case '2':b[28].cold(8,7); break;
case '3':b[29].cold(8,7); break;
case '4':b[30].cold(8,7); break;
case '5':b[31].cold(8,7); break;
case '6':b[32].cold(8,7); break;
case '7':b[33].cold(8,7); break;
case '8':b[34].cold(8,7); break;
case '9':b[35].cold(8,7); break;
case ' ':b[36].cold(8,7); break;
}
}





class dstorage		//class defined to store numbers and names
{
public:
char info[10];
long int pass;
};




void out(double b)  //to read numbers and
{		   //display them as string
		   //on the output screen
setcolor(BLACK);
char xg[80],str[80];
sprintf(xg,"%20.6lf",b);   //function to convert num to str

outtextxy(150,15,xg); //func to put str on the screen


}


void outs(char s[])	//to read strings
{			//and display them on diary (main)screen


displayds(); //clear the outscreensetcolor(BLUE);
setcolor(BLUE);

outtextxy(15,20,"DIARY:");
outtextxy(90,20,s);

setcolor(CYAN);
}

void outss(char s[])	//to read strings
{			//and display them on diary SUB screen



setcolor(BLUE);

outtextxy(90,75,s);

setcolor(YELLOW);
}

double factorial(char s[]) //to calculate factorial
{

int x=atoi(s);
double z=1;

for(int i=x;i>0;i--)
{
z=z*i;
}
return z;

}



double inverse(char s[]) //to calculate 1/number
{

double n1=atof(s);
double ans=1/n1;
return ans;
}


double loge(char s[]) //to calculate log wrt e
{

double n1=atof(s);
double ans=log10(n1);
return ans;
}


double sqt(char s[]) //to calculate square root
{

double ans=sqrt(atof(s));
return ans;
}


void del(dstorage d)
{
dstorage d1;
fstream file1("stored.dat",ios::binary|ios::out|ios::in); //set the file1 to n position
fstream file2("temp.dat",ios::binary|ios::out);
while(file1.read((char *)&d1,sizeof(dstorage)))
{
if(d1.pass!=d.pass)
{
file2.write((char*)&d1,sizeof(d1));	//then write NULL
}
}
displaydss();
outs("deleting!!!!");
delay(1000);

file2.close();
file1.close();
remove("stored.dat");
rename("temp.dat","stored.dat");
}