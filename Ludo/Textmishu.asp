
0001./*******************************************************
0002.*     MYCPLUS Sample Code - http://www.mycplus.com ;    *
0003.*                                                     *
0004.*   This code is made available as a service to our   *
0005.*      visitors and is provided strictly for the      *
0006.*               purpose of illustration.              *
0007.*                                                     *
0008.* Please direct all inquiries to saqib at mycplus.com *
0009.*******************************************************/
0010. 
0011.#include "calcu.h"  //to include functions of this project
0012.//its definition can be found at the bottom of the code
0013. 
0014.void main() //main()
0015.{
0016.menu:clrscr();  //before making clear the screen fully
0017.enum boolean{false,true}; //set false to value of 0
0018.//set true to value of 1
0019. 
0020.const char ESC=27;  //to exit
0021.char dstring[80];   //string to store the numbers as chain
0022.char tempbuf[80];   //temporary string
0023.int numchars=0;     //to count no:of characters in str
0024.char oper;      //to get the operator like +,-,*,/
0025.boolean isfirst=true;   //allow the user to use the calc first time
0026.boolean chain=false;    //chaining is allowed
0027.double number1,number2,answer; //num 1,num2, and answer
0028.char ch,mh; //get the pressed key from user
0029. 
0030. 
0031.int d,m;
0032.d=DETECT;
0033.//detect the best driver on sys
0034.initgraph(&d,&m,"F:\\tc\\bgi"); //set the graphics mode
0035. 
0036.setcolor(RED);
0037.cartoon();
0038.setfillstyle(SOLID_FILL,BLACK);
0039.floodfill(20,20,CYAN);
0040. 
0041.b[26].setit(350,250,150,150,"");
0042.b[27].setit(350,350,150,250,"");
0043.settextstyle(DEFAULT_FONT,0,1);
0044.outtextxy(200,200,"DIARY (d)");     //to display the buttons
0045.outtextxy(200,300,"CALC (c)");      //to choose calc and diary
0046.b[28].setit(630,450,0,400,"");
0047.setcolor(LIGHTBLUE);
0048.settextstyle(DEFAULT_FONT,0,1);
0049.outtextxy(130,420,"WELCOME TO THE DIGITAL WORLD:AVINASH");
0050. 
0051.setcolor(RED);
0052.settextstyle(DEFAULT_FONT,0,1);
0053. 
0054.//get the response
0055. 
0056.menu_cartoon();
0057.mh=getch();
0058.if(mh=='c') //if calc is choosed
0059.{
0060. 
0061.cartoon();
0062. 
0063. 
0064.b[26].colc(8,7);
0065.setfillstyle(SOLID_FILL,BLACK);
0066.floodfill(50,50,BLUE);
0067. 
0068.displayc(); //display the calc(fully)
0069. 
0070. 
0071. 
0072.setcolor(LIGHTBLUE);
0073. 
0074.outtextxy(370,130,"f=factorial q=1/number.");
0075.outtextxy(370,150,"w=log(n) with base 10.");    //abbreviations of calc
0076.outtextxy(370,170,"e=sqrt(n) ");
0077.outtextxy(370,190,"y=e^n b=x^y.");
0078.outtextxy(370,210,"ESC=quit");
0079. 
0080. 
0081.b[16].setit(630,400,0,250,"");  //for the results showing screen
0082.setfillstyle(SOLID_FILL,BLACK);
0083.floodfill(100,300,RED);
0084. 
0085. 
0086. 
0087.calc_cartoon(ch);
0088. 
0089.while( (ch=getch()) !=ESC) //stop when escape is pressed
0090.{
0091. 
0092. 
0093. 
0094. 
0095. 
0096.if(ch>='0'&&ch<='9'||ch=='.')
0097.{
0098. 
0099.switch(ch)
0100.{
0101.case '0':b[0].colc(8,7);  break;
0102.case '1':b[1].colc(8,7); break;
0103.case '2':b[2].colc(8,7); break;
0104.case '3':b[3].colc(8,7); break;
0105.case '4':b[4].colc(8,7); break; //all to change colors
0106.case '5':b[5].colc(8,7); break;
0107.case '6':b[6].colc(8,7); break;
0108.case '7':b[7].colc(8,7); break;
0109.case '8':b[8].colc(8,7); break;
0110.case '9':b[9].colc(8,7); break;
0111.case '.':b[10].colc(8,7); break;
0112.}
0113. 
0114. 
0115.dstring[numchars++]=ch; //to insert the num into the string
0116.dstring[numchars]='\0'; //at the last position insert NULL
0117. 
0118. 
0119. 
0120. 
0121.if(atof(dstring)>99999999999999999999.99|| numchars>20)
0122.{           //if numbers are too large to display
0123.sound(200); nosound();  //then do not insert them in str
0124.dstring[--numchars]='\0'; //keep adding NULLs
0125.}
0126.out(atof(dstring)); //display the final string
0127. 
0128. 
0129.}
0130. 
0131.else if(ch=='/'||ch=='*'||ch=='-'||ch=='+'||ch=='='||ch=='b'||ch=='y'|ch=='f'||ch=='q'||ch=='w'||ch=='e')
0132.{
0133.strcpy(tempbuf,dstring); //store str1 to a temp str
0134.numchars=0;
0135.dstring[numchars]='\0';  // insert null in str1
0136.out(atof(dstring)); //display the 0.000
0137. 
0138. 
0139.if(isfirst) //if it is the first time
0140.{
0141.number1=(chain)?answer:atof(tempbuf);
0142.isfirst=false;  //now it is not the first time
0143.//this must be the operator
0144. 
0145.a:switch(ch)    //read the operator
0146.{
0147.case '/':b[14].colc(8,7); out(0.0); oper='/'; break;
0148.case '+':
0149.case '=':
0150.b[12].colc(8,7); out(0.0);
0151.oper='+';
0152.break;
0153.case '-':b[13].colc(8,7); out(0.0); oper='-';  break;
0154.case '*':b[15].colc(8,7); out(0.0); oper='*'; break;
0155.case 'f':b[18].colc(8,7); out(factorial(tempbuf));      break;
0156.case 'q':b[17].colc(8,7); out(inverse(tempbuf));     break;
0157.case 'w':b[19].colc(8,7); out(loge(tempbuf));  break;
0158.case 'e':b[20].colc(8,7); out(sqt(tempbuf));  break;
0159.case 'y':b[22].colc(8,7); number1=exp(atof(tempbuf));
0160.out(number1);      break;
0161. 
0162.case 'b':b[25].colc(8,7);
0163.oper='b';
0164.out(0);
0165.break;
0166.}
0167.}
0168. 
0169. 
0170.else
0171.{
0172.b[12].colc(8,7);
0173.number2=atof(tempbuf);  //store temp str to num 2
0174.switch(oper)    //calculate the answer
0175.{
0176.case '/':
0177.if(number2==0.000000)
0178.{
0179.outtextxy(150,15,"Overflow");   //show error
0180.}
0181.else
0182.{
0183.answer=number1/number2;
0184.}
0185.break;
0186. 
0187.case '*':answer=number1*number2; break;
0188.case '-':answer=number1-number2; break;
0189.case '+':answer=number1+number2; break;
0190.case 'b':answer=pow(number1,number2); break;
0191.}
0192. 
0193. 
0194.if(answer>999999999999999999999.99) //if ans is too large
0195.{
0196.setcolor(GREEN);
0197.outtextxy(150,15,"Overflow");   //show error
0198.}
0199.else
0200.{
0201.out(answer); //display the answer
0202.number1=answer; //set num1=ans
0203.}
0204.isfirst=false; //not the first num, must be operator
0205.chain=true; //now chain to calculate
0206.}
0207.}
0208. 
0209.else if(ch=='C'||ch=='c') //to clear the screen
0210.{
0211.b[11].colc(8,7);
0212.isfirst=true;   //now from here this is the first time again
0213.chain=false;    //do not chain i.e no operator
0214.numchars=0;
0215.dstring[numchars]='\0'; //set the current string to NULL
0216.out(0.0);   //display 0.000
0217.}
0218. 
0219. 
0220.else  //if any other key is pressed
0221.{   //show delay and danger sounds
0222.delay(100); sound(200); delay(300); nosound();
0223.}
0224. 
0225. 
0226. 
0227.calc_cartoon(ch);
0228. 
0229. 
0230.}
0231. 
0232. 
0233.goto menu;  //goto the choosing menu
0234. 
0235. 
0236.}
0237. 
0238. 
0239.else if(mh=='d') //if diary is chosen
0240.{
0241.cartoon();
0242. 
0243.setfillstyle(SOLID_FILL,BLACK);
0244.floodfill(50,50,BLUE);
0245.displaydss();
0246.displayds();
0247.displayd(); //display the diary and buttons
0248. 
0249. 
0250. 
0251.const char ESC=27,ENTER=13,BACK=8;
0252.setcolor(BLACK);
0253.outs("1. to enter, 2. to search, 3. to change device");
0254. 
0255. 
0256.char m;
0257. 
0258. 
0259.while(  (m=getch()) !=ESC)
0260.{
0261. 
0262.if(m=='1')  //to enter things
0263.{
0264.displayds();
0265.dstorage d;
0266. 
0267.char ch;
0268. 
0269. 
0270.do
0271.{
0272. 
0273.fstream file("stored.DAT",ios::out|ios::in|ios::app);
0274.//create the file to store name and numbers
0275. 
0276. 
0277.displayds();
0278.displaydss();
0279. 
0280. 
0281. 
0282.char name[25];
0283.char till;
0284.do
0285.{
0286.setcolor(BLACK);
0287.outs("Enter the name(max 10 characters): ");
0288.//ask to enter name
0289. 
0290.int y=0;
0291.char c;
0292.while( (c=getch()) !=ENTER)
0293.{
0294. 
0295. 
0296. 
0297. 
0298.gettc(c);
0299.if(c==BACK)
0300.{
0301. 
0302.name[--y]='\0';
0303. 
0304.displaydss();
0305. 
0306.}
0307. 
0308. 
0309.else
0310.{
0311.name[y++]=c;
0312.}
0313. 
0314.name[y]='\0';
0315.setcolor(CYAN);
0316. 
0317.outss(name);
0318. 
0319. 
0320.}
0321. 
0322. 
0323.stop:outs("Want to enter again(y/n): ");
0324. 
0325. 
0326. 
0327.till=getch();
0328.gettc(till);
0329. 
0330. 
0331. 
0332.if(till=='y')
0333.{
0334.y=0;
0335.displayds();
0336.displaydss();
0337.name[0]='\0';
0338.}
0339. 
0340. 
0341. 
0342. 
0343. 
0344.else
0345.{
0346.strcpy(d.info,name);        //finally copy the name to d.info
0347.}
0348.}
0349.while(till=='y');
0350. 
0351. 
0352. 
0353.displayds();
0354. 
0355. 
0356. 
0357.do
0358.{
0359. 
0360. 
0361. 
0362. 
0363.setcolor(CYAN);
0364.again:outs("Enter the phonenumber: ");
0365.//prompt to enter phone number
0366.displaydss();
0367. 
0368. 
0369.char pass[25];
0370.int z=0;
0371.char c;
0372.while(  (c=getch())  !=ENTER)
0373.{
0374.gettc(c);
0375.if(c==BACK)     //if backspace is pressed
0376.{
0377.pass[--z]='\0';
0378.displaydss();
0379.}
0380.else
0381.{
0382.pass[z++]=c;
0383.}
0384.pass[z]='\0';
0385. 
0386. 
0387.setcolor(CYAN);
0388.outss(pass);
0389.}
0390.outs("Want to enter again(y/n): ");
0391. 
0392. 
0393.till=getch();
0394.gettc(till);
0395.if(till=='y')
0396.{
0397.displayds();
0398. 
0399.displaydss();
0400. 
0401.pass[0]='\0';
0402.}
0403.else
0404.{
0405.d.pass=atof(pass);
0406.}
0407. 
0408. 
0409.}
0410.while(till=='y');
0411. 
0412. 
0413. 
0414.file.write((char*)&d,sizeof(d));    //finally write everthing to file
0415. 
0416. 
0417.displaydss();
0418.outs("want to enter more enteries(y/n): ");
0419. 
0420.file.close();
0421. 
0422.ch=getch();
0423. 
0424.gettc(ch);
0425.}
0426.while(ch=='y'); //continue loop if 'y' is entered
0427. 
0428. 
0429. 
0430.displayds();
0431. 
0432.outs("1. to enter, 2. to search, 3. to change device");
0433. 
0434.}
0435. 
0436. 
0437.else if(m=='2')     //to search
0438.{
0439. 
0440. 
0441.displayds();
0442.displaydss();       //clear both outscreens
0443. 
0444.char ch,string[25];
0445.int z=0;
0446. 
0447.char til;
0448. 
0449.do
0450.{
0451. 
0452.outs("Enter the name(atleast the first character): ");
0453.//get the first character of name from user
0454.while( (ch=getch()) !=ENTER)
0455.{
0456. 
0457.gettc(ch);
0458.if(ch==BACK)
0459.{
0460.string[--z]='\0';
0461.displaydss();
0462.}
0463.else
0464.{
0465.string[z++]=ch;
0466.}
0467.string[z]='\0';
0468.setcolor(CYAN);
0469.outss(string);
0470.}
0471.displayds();
0472. 
0473.outs("Want to enter again(y/n): ");
0474. 
0475. 
0476.til=getch();
0477.if(til=='y')
0478.{
0479.z=0;
0480. 
0481.displayds();
0482.displaydss();
0483.}
0484.}
0485.while(til=='y');
0486. 
0487.dstorage d;
0488. 
0489.displaydss();
0490. 
0491. 
0492. 
0493.displayds();
0494. 
0495.displaydss();
0496. 
0497. 
0498.fstream file1("stored.DAT",ios::out|ios::in|ios::binary);
0499. 
0500. 
0501.file1.seekg(0);
0502. 
0503. 
0504. 
0505.while(file1.read((char*)&d,sizeof(dstorage)))
0506.{
0507. 
0508. 
0509.if(strncmpi(d.info,string,1)==0)    //if search is successful
0510.{
0511.outs("d to delete, n to see next");
0512.outss(d.info);
0513.char xg[20];
0514.gcvt(d.pass,10,xg);
0515.outtextxy(220,75,xg);
0516. 
0517. 
0518. 
0519. 
0520.ch=getch();
0521. 
0522. 
0523. 
0524. 
0525.if(ch=='d') //if d is entered to delete the entry
0526.{
0527. 
0528.del(d);
0529.}
0530.else if(ch=='n')
0531.{
0532. 
0533.displaydss();
0534.}
0535. 
0536.}
0537. 
0538. 
0539.}
0540. 
0541. 
0542.file1.close();
0543. 
0544. 
0545.displaydss();
0546.outs("1. to enter, 2. to search, 3. to device change");
0547. 
0548.}
0549. 
0550. 
0551.else if(m=='3') //change device menu
0552.{
0553.goto menu;
0554.}
0555. 
0556.else   //if any other key is pressed keep on displaying
0557.{
0558. 
0559.displayds();
0560.displaydss();
0561.outs("1. to enter, 2. to search, 3. to change device");
0562. 
0563.}
0564.}
0565. 
0566.if(m==ESC)  //however is escape is entered
0567.{
0568.goto last;
0569.}
0570. 
0571. 
0572.}
0573. 
0574.if(mh==ESC)
0575.{
0576.last: theend();
0577. 
0578. 
0579.}
0580. 
0581. 
0582.closegraph(); //close the graphics sys before exit
0583. 
0584.}
0585. 
0586.//--------------------------------
0587.//calcu.h
0588.//---------------------------------
0589. 
0590.#include<fstream.h>   // for saving calculations
0591.#include<math.h>  //for atof(), this converts string to float number
0592.#include<stdio.h> //for sprintf()
0593.#include<stdlib.h>    //for atoi(), atof();
0594.#include<graphics.h>  //for setcolor(),setfillstyle(),floodfill(),fillpoly() etc.
0595.#include<conio.h> //for clrscr(),getch()
0596.#include<iostream.h>
0597.#include<string.h>    //for strcpy(),strlen()
0598.#include<dos.h>       //for sound(),delay()
0599. 
0600. 
0601. 
0602.//main codes
0603. 
0604.void displayc();        //to create the output screen and buttons
0605.//of calculator
0606.void calc_cartoon(char ch);
0607. 
0608.void displayd();        //to do the above for diary
0609. 
0610. 
0611.void cartoon();         //to show loading graphics
0612. 
0613.void theend();          //to show ending graphics
0614. 
0615. 
0616.class button        //to create buttons
0617.{
0618. 
0619.int x,y,xc,yc;
0620.int x1,y1,x2,y2;
0621.char u1[5];
0622.public:
0623.button(int a=7,int b=8)
0624.{
0625.x=a;
0626.y=b;
0627. 
0628.}
0629. 
0630.void colc(int a=7, int b=8);    //to give pressing effect to calc buttons
0631.void cold(int a=7, int b=8);    //to give pressing effect to diary buttons
0632. 
0633. 
0634.void setit(int x11=0,int y11=0,int x22=0, int y22=0,char u[5]="");
0635.void draw();    //to draw buttons
0636.}b[50];     //we can make atleast 50 buttons
0637. 
0638. 
0639. 
0640.void button::colc(int a, int b) //to change border colors on pressings
0641.{
0642.displayc();
0643.sound(2000);
0644.x=a;
0645.y=b;
0646.draw();     //draw the button with color a,b
0647.delay(50);
0648.x=b;
0649.y=a;
0650.draw();     //draw the button with color b,a
0651.nosound();  //whole change give pressing sensation
0652.}
0653. 
0654.void button::cold(int a, int b) //to change border colors on pressings
0655.{
0656. 
0657.sound(2000);
0658.x=a;
0659.y=b;
0660.draw();     //draw the button with color a,b
0661.delay(50);
0662.x=b;
0663.y=a;
0664.draw();     //draw the button with color b,a
0665.nosound();  //whole change give pressing sensation
0666.setcolor(CYAN);
0667.}
0668. 
0669.void button::setit(int x11,int y11,int x22,int y22,char u[5])
0670.{
0671.strcpy(u1,u);
0672.x1=x11;
0673.y1=y11;     //this setit() to set the co-ordinates of various buttons
0674.x2=x22;
0675.y2=y22;
0676.draw();
0677.}
0678. 
0679.void button::draw()
0680.{
0681.setcolor(RED);
0682.rectangle(x1,y1,x2,y2);         //buttons as rectangles
0683.rectangle(x1-10,y1-10,x2+10,y2+10);
0684.setfillstyle(SOLID_FILL,10);
0685.floodfill(x1-20,y1-15,RED);
0686.settextstyle(TRIPLEX_FONT,0,1);
0687.outtextxy(x1-35,y1-39,u1);
0688.line(x2,y2,x2+10,y2+10);
0689.line(x2,y1,x2+10,y1-10);
0690.line(x1,y2,x1-10,y2+10);
0691.line(x1,y1,x1-10,y1-10);
0692.setfillstyle(SOLID_FILL,x);
0693.floodfill(x2+25,y2+5,RED);
0694.floodfill(x2+5,y2+25,RED);
0695.setfillstyle(SOLID_FILL,y);
0696.floodfill(x1-25,y1-5,RED);
0697.floodfill(x1-5,y1-25,RED);
0698.}
0699. 
0700.void displayc()     //to create the output screen and buttons
0701.{
0702. 
0703. 
0704.int p[8]={10,10,620,10,620,40,10,40};
0705.int p1[8]={0,0,630,0,630,50,0,50};
0706.setcolor(RED);
0707.setlinestyle(THICK_WIDTH,0,RED);
0708.setfillstyle(SOLID_FILL,YELLOW);
0709.fillpoly(4,p1); //create the output screen as polygon
0710.setfillstyle(SOLID_FILL,RED);
0711.fillpoly(4,p);
0712.setcolor(RED);
0713.line(0,0,10,10);
0714.line(620,10,630,0);
0715.line(0,50,10,40);
0716.line(620,40,630,50);
0717.setfillstyle(SOLID_FILL,7); //till here to create the output screen
0718. 
0719.b[40].setit(630,450,0,400,"");
0720. 
0721.settextstyle(DEFAULT_FONT,0,1);
0722. 
0723.outtextxy(130,420,"WELCOME TO THE DIGITAL WORLD:AVINASH");
0724. 
0725.b[41].setit(50,250,0,50,"");
0726.settextstyle(DEFAULT_FONT,1,1);
0727.outtextxy(25,100,"CALCULATOR");
0728. 
0729.b[0].setit(150,100,100,50,"0"); //now setting the coordinates of buttons
0730.b[1].setit(200,100,150,50,"1");
0731.b[2].setit(250,100,200,50,"2");
0732.b[3].setit(150,150,100,100,"3");
0733.b[4].setit(200,150,150,100,"4");
0734.b[5].setit(250,150,200,100,"5");
0735.b[6].setit(150,200,100,150,"6");
0736.b[7].setit(200,200,150,150,"7");
0737.b[8].setit(250,200,200,150,"8");
0738.b[9].setit(150,250,100,200,"9");
0739.b[10].setit(200,250,150,200,".");
0740.b[11].setit(250,250,200,200,"C");
0741.b[12].setit(300,100,250,50,"+=");
0742.b[13].setit(300,150,250,100,"-");
0743.b[14].setit(300,200,250,150,"/");
0744.b[15].setit(300,250,250,200,"*");
0745. 
0746. 
0747.b[17].setit(100,100,50,50,"q");
0748.b[18].setit(100,150,50,100,"f");
0749.b[19].setit(100,200,50,150,"w");
0750.b[20].setit(100,250,50,200,"e");
0751.b[21].setit(350,100,300,50,"t");
0752.b[22].setit(350,150,300,100,"y");
0753.b[23].setit(350,200,300,150,"g");
0754.b[24].setit(630,250,350,50,"");
0755.b[25].setit(350,250,300,200,"b");
0756. 
0757.}
0758. 
0759.void displayds()        //for the main output screen of diary
0760.{
0761. 
0762.int p[8]={10,10,590,10,590,50,10,50};
0763.int p1[8]={0,0,600,0,600,60,0,60};
0764.setcolor(RED);
0765.setlinestyle(THICK_WIDTH,0,RED);
0766.setfillstyle(SOLID_FILL,YELLOW);
0767.fillpoly(4,p1); //create the output screen as polygon
0768. 
0769.setfillstyle(SOLID_FILL,RED);
0770.fillpoly(4,p);
0771. 
0772.setcolor(RED);
0773.line(0,0,10,10);
0774.line(590,10,600,0);
0775.line(0,60,10,50);
0776.line(590,60,600,60);
0777. 
0778. 
0779.setfillstyle(SOLID_FILL,7); //till here to create the output screen
0780.setcolor(BLACK);
0781. 
0782. 
0783. 
0784.}
0785. 
0786.void displaydss()    //to create sub outscreen
0787.{           //of diary
0788. 
0789. 
0790. 
0791.int p2[8]={10,70,590,70,590,200,10,200};
0792.int p22[8]={0,60,600,60,600,210,0,210};
0793.setcolor(RED);
0794.setlinestyle(THICK_WIDTH,0,RED);
0795.setfillstyle(SOLID_FILL,YELLOW);
0796. 
0797. 
0798. 
0799.//create the output screen as polygon
0800.fillpoly(4,p22);
0801.setfillstyle(SOLID_FILL,RED);
0802. 
0803.fillpoly(4,p2);
0804.setcolor(RED);
0805. 
0806. 
0807. 
0808. 
0809. 
0810.line(0,60,10,70);
0811.line(590,70,600,60);
0812.line(0,210,10,200);
0813.line(590,200,600,210);
0814.setfillstyle(SOLID_FILL,7); //till here to create the output screen
0815.setcolor(CYAN);
0816. 
0817. 
0818. 
0819.}
0820. 
0821. 
0822.void displayd()     //for buttons of diary
0823.{
0824. 
0825. 
0826.b[0].setit(50,260,0,210,"a");   //now setting the coordinates of buttons
0827.b[1].setit(100,260,50,210,"b");
0828.b[2].setit(150,260,100,210,"c");
0829.b[3].setit(200,260,150,210,"d");
0830.b[4].setit(250,260,200,210,"e");
0831.b[5].setit(300,260,250,210,"f");
0832.b[6].setit(350,260,300,210,"g");
0833.b[7].setit(400,260,350,210,"h");
0834.b[8].setit(450,260,400,210,"i");
0835.b[9].setit(500,260,450,210,"j");
0836.b[10].setit(550,260,500,210,"k");
0837.b[11].setit(600,260,550,210,"l");
0838.b[12].setit(50,310,0,260,"m");
0839.b[13].setit(100,310,50,260,"n");
0840.b[14].setit(150,310,100,260,"o");
0841.b[15].setit(200,310,150,260,"p");
0842.b[16].setit(250,310,200,260,"q");
0843.b[17].setit(300,310,250,260,"r");
0844.b[18].setit(350,310,300,260,"s");
0845.b[19].setit(400,310,350,260,"t");
0846.b[20].setit(450,310,400,260,"u");
0847.b[21].setit(500,310,450,260,"v");
0848.b[22].setit(550,310,500,260,"w");
0849.b[23].setit(600,310,550,260,"x");
0850.b[24].setit(50,360,0,310,"y");
0851.b[25].setit(100,360,50,310,"z");
0852.b[26].setit(150,360,100,310,"0");
0853.b[27].setit(200,360,150,310,"1");
0854.b[28].setit(250,360,200,310,"2");
0855.b[29].setit(300,360,250,310,"3");
0856.b[30].setit(350,360,300,310,"4");
0857.b[31].setit(400,360,350,310,"5");
0858.b[32].setit(450,360,400,310,"6");
0859.b[33].setit(500,360,450,310,"7");
0860.b[34].setit(550,360,500,310,"8");
0861.b[35].setit(600,360,550,310,"9");
0862.b[36].setit(600,400,0,360,"");
0863. 
0864. 
0865.b[40].setit(600,450,0,400,"");
0866. 
0867.settextstyle(DEFAULT_FONT,0,1);
0868.outtextxy(130,420,"WELCOME TO THE DIGITAL WORLD:AVINASH");
0869. 
0870.outtextxy(250,378,"SPACE BAR");
0871. 
0872. 
0873. 
0874.}
0875. 
0876. 
0877. 
0878.void theend()   //THE ENDING CARTOON
0879.{
0880. 
0881. 
0882. 
0883.setfillstyle(SOLID_FILL,BLACK);
0884.floodfill(30,30,CYAN);
0885.settextstyle(DEFAULT_FONT,0,2);
0886. 
0887. 
0888.setcolor(RED);
0889.setfillstyle(SOLID_FILL,LIGHTRED);
0890.rectangle(620,300,0,200);
0891. 
0892.int i=0;
0893.while(!kbhit())            //UNTILL A KEY IS PRESSED
0894.{
0895.floodfill(250,250,RED);
0896.setcolor(i);
0897.settextstyle(TRIPLEX_FONT,0,5);
0898.outtextxy(20,200,"AVINASH CHANDER KASHYAP");
0899.outtextxy(20,70,"Press any key to exit!");
0900.outtextxy(200,250,"CLASS-XII");
0901.settextstyle(DEFAULT_FONT,0,2);
0902.setcolor(i);
0903.outtextxy(10,150,"MADE BY:");
0904.outtextxy(50,350,"THANK YOU FOR USING THIS SOFTWARE!");
0905.delay(5);
0906.i++;
0907.}
0908. 
0909. 
0910. 
0911.}
0912. 
0913.void cartoon()      //to make loading graphics
0914.{
0915.setfillstyle(SOLID_FILL,BLACK);
0916.floodfill(50,50,CYAN);
0917.settextstyle(TRIPLEX_FONT,0,3);
0918. 
0919. 
0920. 
0921. 
0922.setcolor(LIGHTRED);
0923. 
0924.rectangle(620,450,20,400);
0925. 
0926.for(int i=50;i<621;i++)
0927.{
0928.setcolor(i);
0929.outtextxy(250,300,"LOADING....");
0930. 
0931.sound(i+590);
0932.setfillstyle(SOLID_FILL,LIGHTRED);
0933.int p[8]={20,400,i,400,i,450,20,450};
0934.fillpoly(4,p);
0935.delay(1);
0936.}
0937. 
0938. 
0939. 
0940.for(i=0;i<300;i++)
0941.{
0942.setcolor(LIGHTRED);
0943.rectangle(i+300,200+i,300-i,200-i);
0944.delay(2);
0945.}
0946. 
0947. 
0948. 
0949. 
0950. 
0951.nosound();
0952. 
0953.}
0954. 
0955. 
0956.void menu_cartoon()     //THE MENU CARTOON
0957.{
0958.int i=0;
0959.while(!kbhit())         //UNTILL  A KEY IS PRESSED
0960.{
0961.setcolor(i);
0962.outtextxy(50,25,"to turn on diary press d");
0963.outtextxy(50,40,"to turn on calc press c");
0964.outtextxy(50,60,"ESC to exit");
0965.delay(10);
0966.i++;
0967.}
0968. 
0969.}
0970. 
0971. 
0972.void calc_cartoon(char ch)  //THE CALCULATOR CARTOON
0973.{
0974.char str[1];
0975.str[0]=ch;
0976.str[1]='\0';
0977.int i=0;
0978.while(!kbhit())
0979.{
0980.setcolor(i);
0981.settextstyle(TRIPLEX_FONT,0,7);
0982.outtextxy(100,280,"CALCULATOR");
0983.i++;
0984.setcolor(GREEN);
0985.settextstyle(DEFAULT_FONT,0,1);
0986.outtextxy(30,280,"KEY PRESSED ");
0987.outtextxy(180,280,str);
0988.}
0989.setfillstyle(SOLID_FILL,BLACK);
0990.floodfill(50,300,RED);
0991.settextstyle(TRIPLEX_FONT,0,1);
0992.}
0993. 
0994. 
0995. 
0996. 
0997.void gettc(char c)  //to get the key pressed by user and show its sensation
0998.{
0999. 
1000.//on the screen buttons
1001.switch(c)
1002.{
1003.case 'A':
1004.case 'a':b[0].cold(8,7); break;
1005.case 'B':
1006.case 'b':b[1].cold(8,7); break;
1007.case 'C':
1008.case 'c':b[2].cold(8,7); break;
1009.case 'D':
1010.case 'd':b[3].cold(8,7); break;
1011.case 'E':
1012.case 'e':b[4].cold(8,7); break;
1013.case 'F':
1014.case 'f':b[5].cold(8,7); break;
1015.case 'G':
1016.case 'g':b[6].cold(8,7); break;
1017.case 'H':
1018.case 'h':b[7].cold(8,7); break;
1019.case 'I':
1020.case 'i':b[8].cold(8,7); break;
1021.case 'J':
1022.case 'j':b[9].cold(8,7); break;
1023.case 'K':
1024.case 'k':b[10].cold(8,7); break;
1025.case 'L':
1026.case 'l':b[11].cold(8,7); break;
1027.case 'M':
1028.case 'm':b[12].cold(8,7); break;
1029.case 'N':
1030.case 'n':b[13].cold(8,7); break;
1031.case 'O':
1032.case 'o':b[14].cold(8,7); break;
1033.case 'P':
1034.case 'p':b[15].cold(8,7); break;
1035.case 'Q':
1036.case 'q':b[16].cold(8,7); break;
1037.case 'R':
1038.case 'r':b[17].cold(8,7); break;
1039.case 'S':
1040.case 's':b[18].cold(8,7); break;
1041.case 'T':
1042.case 't':b[19].cold(8,7); break;
1043.case 'U':
1044.case 'u':b[20].cold(8,7); break;
1045.case 'V':
1046.case 'v':b[21].cold(8,7); break;
1047.case 'W':
1048.case 'w':b[22].cold(8,7); break;
1049.case 'X':
1050.case 'x':b[23].cold(8,7); break;
1051.case 'Y':
1052.case 'y':b[24].cold(8,7); break;
1053.case 'Z':
1054.case 'z':b[25].cold(8,7); break;
1055.case '0':b[26].cold(8,7); break;
1056.case '1':b[27].cold(8,7); break;
1057.case '2':b[28].cold(8,7); break;
1058.case '3':b[29].cold(8,7); break;
1059.case '4':b[30].cold(8,7); break;
1060.case '5':b[31].cold(8,7); break;
1061.case '6':b[32].cold(8,7); break;
1062.case '7':b[33].cold(8,7); break;
1063.case '8':b[34].cold(8,7); break;
1064.case '9':b[35].cold(8,7); break;
1065.case ' ':b[36].cold(8,7); break;
1066.}
1067.}
1068. 
1069. 
1070. 
1071. 
1072. 
1073.class dstorage      //class defined to store numbers and names
1074.{
1075.public:
1076.char info[10];
1077.long int pass;
1078.};
1079. 
1080. 
1081. 
1082. 
1083.void out(double b)  //to read numbers and
1084.{          //display them as string
1085.//on the output screen
1086.setcolor(BLACK);
1087.char xg[80],str[80];
1088.sprintf(xg,"%20.6lf",b);   //function to convert num to str
1089. 
1090.outtextxy(150,15,xg); //func to put str on the screen
1091. 
1092. 
1093.}
1094. 
1095. 
1096.void outs(char s[]) //to read strings
1097.{           //and display them on diary (main)screen
1098. 
1099. 
1100.displayds(); //clear the outscreensetcolor(BLUE);
1101.setcolor(BLUE);
1102. 
1103.outtextxy(15,20,"DIARY:");
1104.outtextxy(90,20,s);
1105. 
1106.setcolor(CYAN);
1107.}
1108. 
1109.void outss(char s[])    //to read strings
1110.{           //and display them on diary SUB screen
1111. 
1112. 
1113. 
1114.setcolor(BLUE);
1115. 
1116.outtextxy(90,75,s);
1117. 
1118.setcolor(YELLOW);
1119.}
1120. 
1121.double factorial(char s[]) //to calculate factorial
1122.{
1123. 
1124.int x=atoi(s);
1125.double z=1;
1126. 
1127.for(int i=x;i>0;i--)
1128.{
1129.z=z*i;
1130.}
1131.return z;
1132. 
1133.}
1134. 
1135. 
1136. 
1137.double inverse(char s[]) //to calculate 1/number
1138.{
1139. 
1140.double n1=atof(s);
1141.double ans=1/n1;
1142.return ans;
1143.}
1144. 
1145. 
1146.double loge(char s[]) //to calculate log wrt e
1147.{
1148. 
1149.double n1=atof(s);
1150.double ans=log10(n1);
1151.return ans;
1152.}
1153. 
1154. 
1155.double sqt(char s[]) //to calculate square root
1156.{
1157. 
1158.double ans=sqrt(atof(s));
1159.return ans;
1160.}
1161. 
1162. 
1163.void del(dstorage d)
1164.{
1165.dstorage d1;
1166.fstream file1("stored.dat",ios::binary|ios::out|ios::in); //set the file1 to n position
1167.fstream file2("temp.dat",ios::binary|ios::out);
1168.while(file1.read((char *)&d1,sizeof(dstorage)))
1169.{
1170.if(d1.pass!=d.pass)
1171.{
1172.file2.write((char*)&d1,sizeof(d1)); //then write NULL
1173.}
1174.}
1175.displaydss();
1176.outs("deleting!!!!");
1177.delay(1000);
1178. 
1179.file2.close();
1180.file1.close();
1181.remove("stored.dat");
1182.rename("temp.dat","stored.dat");
1183.}