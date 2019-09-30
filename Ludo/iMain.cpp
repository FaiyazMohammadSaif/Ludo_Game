
#include "iGraphics.h"
#include<cstdlib>
#include <stdlib.h>     /* srand, rand */
#include <time.h>

int whatScreen,len;
char player_one_number[100],player_two_number[100];
int active_player;
char firstName[100],secondName[100],tempStr[100];
int got_six=0;
int can_play[]={0,0};
int prev_pos[]={0,0};
int roll_flag[]={0,0};
int move_guti_flag[]={0,0};
int make_prompt_flag[]={0,0};
int num_play[]={0,0};
int num_home[]={0,0};
int winner=0;

int selected_guti[]={0,0};

int option=0;
int green_board[19][2],red_board[19][2],yellow_board[18][2],blue_board[18][2];
int player_1_pos[]={-1,-1,-1,-1};
int player_2_pos[]={-1,-1,-1,-1};

int player1_path[]={1,2,3,4,5,115,112,109,106,103,100,101,102,105,108,111,114,117,200,201,202,203,204,205,211,217,216,215,214,213,212,302,305,308,311,314,317,316,315,312,309,306,303,300,17,16,15,14,13,12,6,7,8,9,10,11,18};
int player2_path[]={216,215,214,213,212,302,305,308,311,314,317,316,315,312,309,306,303,300,17,16,15,14,13,12,6,0,1,2,3,4,5,115,112,109,106,103,100,101,102,105,108,111,114,117,200,201,202,203,204,205,211,210,209,208,207,206,218};

void checkCanMove();
void drawPlayerGuti(int playerNum,int pos);
void makePrompt(int num);
void checkWinner();
/*
	function iDraw() is called again and again by the system.
*/
void iDraw()
{


	//place your drawing codes here
	iClear();
	if(whatScreen==0)
	{
		//Menu Screen

		iShowBMP(1,1,"ludoimage1.bmp");
		iSetColor(255, 255, 255);
		iFilledRectangle(100 ,300, 100, 50);
		iSetColor(0,0,0);
	    iText(125,320,"Play",GLUT_BITMAP_TIMES_ROMAN_24);

		//iSetColor(255,0,0);
		//iText(315,520,"LUDO",GLUT_BITMAP_TIMES_ROMAN_24);

		iSetColor(255,255,255);
		iFilledRectangle(100,235,100,50);
		iSetColor(0,0,0);
		iText(123,257,"Help",GLUT_BITMAP_TIMES_ROMAN_24);

		iSetColor(255,255,255);
		iFilledRectangle(100,170,100,50);
		iSetColor(0,0,0);
		iText(122,192,"About",GLUT_BITMAP_TIMES_ROMAN_24);


        iSetColor(255,0,0);
		iRectangle(100,105,100,50);
		iText(125,127,"Exit",GLUT_BITMAP_TIMES_ROMAN_24);




	}
	else if(whatScreen==1)
	{

		iShowBMP(1,1,"greenplayerimage.bmp");
		iSetColor(34,177,76);
	    iText(150,320,"Enter your name",GLUT_BITMAP_TIMES_ROMAN_24);
	    iSetColor(255,255,255);
	    iFilledRectangle(350,290,150,70);
	    iSetColor(0,0,0);
	    iText(360,320,tempStr,GLUT_BITMAP_TIMES_ROMAN_24);
	    iSetColor(34,177,76);
	    iText(150,390,"Player 1",GLUT_BITMAP_TIMES_ROMAN_24);

	}
	else if(whatScreen==2)
	{
		iShowBMP(1,1,"redplayerimage.bmp");
		iSetColor(255,0,0);
	    iText(150,320,"Enter your name",GLUT_BITMAP_TIMES_ROMAN_24);

	    iSetColor(255,255,255);
	    iFilledRectangle(350,290,150,70);

	    iSetColor(0,0,0);
	    iText(360,320,tempStr,GLUT_BITMAP_TIMES_ROMAN_24);

	    iSetColor(255,0,0);
	    iText(150,390,"Player 2",GLUT_BITMAP_TIMES_ROMAN_24);

	}
	else if(whatScreen==4)
	{
		iSetColor(255,0,0);
		if(winner==1)
	    iText(150,390,"Player 1 has won",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(winner==2)
			iText(150,390,"Player 2 has won",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(whatScreen==5)
	{

	   iShowBMP(1,1,"helppage.bmp");
	   iSetColor(0,0,0);
	   iText(20,20,"Back to main menu",GLUT_BITMAP_TIMES_ROMAN_24);

	}
   else if(whatScreen==6)
	{

	   //iShowBMP(1,1,"developerspage.bmp");
	   iSetColor(255,255,255);
	   iText(20,20,"Back to main menu",GLUT_BITMAP_TIMES_ROMAN_24);
	   iSetColor(255,0,0);
	   iText(100,500,"Developers-",GLUT_BITMAP_TIMES_ROMAN_24);
	   iText(100,400,"Jabin Rubayat Rashna",GLUT_BITMAP_TIMES_ROMAN_24);
       iText(100,200,"Faiyaz Mohammad Saif",GLUT_BITMAP_TIMES_ROMAN_24);
	   iShowBMP(450,350,"rashnapic.bmp");
	   iShowBMP(450,150,"mahinpic.bmp");

   }
	else
	{
		//Ludo Board
		iShowBMP(1,1,"backpageimage.bmp");
		iShowBMP(150,50,"board.bmp");

		iSetColor(0,6,255);
		iFilledRectangle(150,50,240,250);

		iSetColor(255,0,0);
		iFilledRectangle(285+212,50,251,250);

		iSetColor(34,177,76);
		iFilledRectangle(150,285+118,239,235);

		iSetColor(246,255,0);
		iFilledRectangle(385+112,285+118,250,235);

		iShowBMP(220,285+190,"greencounter.bmp");
        iSetColor(34,177,76);
		if(player_1_pos[0]==-1)
		{
			iFilledCircle(240,285+235,10,50);
		}
		if(player_1_pos[1]==-1)
		{
			iFilledCircle(240,285+205,10,50);
		}
		if(player_1_pos[2]==-1)
		{
			iFilledCircle(310,285+235,10,50);
		}
		if(player_1_pos[3]==-1)
		{
			iFilledCircle(310,285+205,10,50);
		}










    	iShowBMP(285+280,150,"redcounter.bmp");
        iSetColor(255,0,0);


		if(player_2_pos[0]==-1)
		{
			iFilledCircle(285+300,170,10,50);
		}
		if(player_2_pos[1]==-1)
		{
			iFilledCircle(285+300,200,10,50);
		}
		if(player_2_pos[2]==-1)
		{
			iFilledCircle(285+370,170,10,50);
		}
		if(player_2_pos[3]==-1)
		{
			iFilledCircle(285+370,200,10,50);
		}








    	iShowBMP(285+280,285+190,"yellowcounter.bmp");
        iSetColor(246,255,0);
		iFilledCircle(285+370,285+235,10,50);
        iSetColor(246,255,0);
		iFilledCircle(285+370,285+205,10,50);
		iSetColor(246,255,0);
		iFilledCircle(285+310,285+235,10,50);
        iSetColor(246,255,0);
		iFilledCircle(285+310,285+205,10,50);


		iShowBMP(220,150,"bluecounter.bmp");
        iSetColor(0,6,255);
		iFilledCircle(240,170,10,50);
        iSetColor(0,6,255);
		iFilledCircle(240,200,10,50);
		iSetColor(0,6,255);
		iFilledCircle(310,170,10,50);
        iSetColor(0,6,255);
		iFilledCircle(310,200,10,50);



		//testing position
		int temp_position[]={170,387};
		int i;
		for(i=0;i<18;i++)
		{
			int multi=40;
			if(i%6==0&&i!=0)
			{
				temp_position[0]=170;
				temp_position[1]-=35;
			}
			green_board[i][0]=temp_position[0];
			green_board[i][1]=temp_position[1];
			//iSetColor(147, 147, 147);
			//iFilledCircle(temp_position[0],temp_position[1],10);
			temp_position[0]+=multi;

		}
		green_board[18][0]=450;
		green_board[18][1]=370;


		temp_position[0]=410;
		temp_position[1]=620;
		for(i=0;i<18;i++)
		{
			int multi=36;
			if(i%3==0&&i!=0)
			{
				temp_position[0]=410;
				temp_position[1]-=40;
			}
			yellow_board[i][0]=temp_position[0];
			yellow_board[i][1]=temp_position[1];
			//iSetColor(147, 147, 147);
			//iFilledCircle(temp_position[0],temp_position[1],10);
			temp_position[0]+=multi;

		}


		temp_position[0]=520;
		temp_position[1]=385;
		for(i=0;i<18;i++)
		{
			int multi=40;
			if(i%6==0&&i!=0)
			{
				temp_position[0]=520;
				temp_position[1]-=35;
			}
			red_board[i][0]=temp_position[0];
			red_board[i][1]=temp_position[1];
			//iSetColor(147, 147, 147);
			//iFilledCircle(temp_position[0],temp_position[1],10);
			temp_position[0]+=multi;

		}
		red_board[18][0]=480;
		red_board[18][1]=370;

		temp_position[0]=405;
		temp_position[1]=280;
		for(i=0;i<18;i++)
		{
			int multi=36;
			if(i%3==0&&i!=0)
			{
				temp_position[0]=405;
				temp_position[1]-=42;
			}
			blue_board[i][0]=temp_position[0];
			blue_board[i][1]=temp_position[1];
			//iSetColor(147, 147, 147);
			//iFilledCircle(temp_position[0],temp_position[1],10);
			temp_position[0]+=multi;

		}

		//int l1=sizeof(player1_path)/sizeof(player1_path[0]);
		//for(i=0;i<l1;i++)
		//{

		//}

		//printf("player 1 %d\n",l1);

		//end testing position

	    iSetColor(0,0,0);
	    iText(5,550,"Back to Menu",GLUT_BITMAP_TIMES_ROMAN_24);

        iSetColor(34,177,76);
		iText(5,510,firstName,GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(34,177,76);
		iText(5,210,firstName,GLUT_BITMAP_TIMES_ROMAN_24);

		iSetColor(255,0,0);
		iText(5,350,secondName,GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(255,0,0);
		iText(5,110,secondName,GLUT_BITMAP_TIMES_ROMAN_24);


		iSetColor(255, 255, 255);
		iRectangle(150,50,600,590);

		iSetColor(34,177,76);
		iFilledRectangle(5,150,100,50);

		iSetColor(0,0,0);
		iText(30,170,"Roll",GLUT_BITMAP_TIMES_ROMAN_24);

        iSetColor(255,0,0);
		iFilledRectangle(5,50,100,50);

		iSetColor(0,0,0);
		iText(30,70,"Roll",GLUT_BITMAP_TIMES_ROMAN_24);

		checkCanMove();
		checkWinner();
		if(can_play[0]==1)
		{
			if(move_guti_flag[0]==1)
			{
				move_guti_flag[0]=0;
				roll_flag[0]=0;
				active_player=2;
				int dice_num=atoi(player_one_number);
				for(int i=0;i<4;i++)
				{
					if(player_1_pos[i]!=-1&&player_1_pos[i]<=56&&player_1_pos[i]+dice_num<56)
					{

						if(selected_guti[0]!=i)
						{
							player_1_pos[i]-=dice_num;
						}
					}
				}
			}
			//printf("%d%d\n",player_1_pos[0],prev_pos);
			if(roll_flag[0]==0)
			{
				for(int i=0;i<4;i++)
				{
					if(player_1_pos[i]!=-1)//&&player_1_pos[i]<=56
					{
						drawPlayerGuti(1,player_1_pos[i]);
					}
				}

			}
			else
			{
				int dice_num=atoi(player_one_number);

				for(int i=0;i<4;i++)
				{
					if(player_1_pos[i]!=-1&&player_1_pos[i]<=56&&player_1_pos[i]+dice_num<56)//&&player_1_pos[i]<=56
					{
						drawPlayerGuti(1,player_1_pos[i]-dice_num);
					}
					else if(player_1_pos[i]+dice_num>56)
					{
						drawPlayerGuti(1,player_1_pos[i]);
					}
				}

			}




		}
		if(can_play[1]==1)
		{

			if(move_guti_flag[1]==1)
			{
				move_guti_flag[1]=0;
				roll_flag[1]=0;
				active_player=1;
				int dice_num=atoi(player_two_number);
				for(int i=0;i<4;i++)
				{
					if(player_2_pos[i]!=-1)
					{

						if(selected_guti[1]!=i&&player_2_pos[i]<=56&&player_2_pos[i]+dice_num<56)
						{
							player_2_pos[i]-=dice_num;
						}
					}
				}
			}
			//printf("%d%d\n",player_1_pos[0],prev_pos);
			if(roll_flag[1]==0)
			{
				int dice_num=atoi(player_two_number);
				for(int i=0;i<4;i++)
				{
					if(player_2_pos[i]!=-1&&player_2_pos[i]<=56)
					{
						drawPlayerGuti(2,player_2_pos[i]);
					}
				}
			}
			else
			{
				int dice_num=atoi(player_two_number);

				for(int i=0;i<4;i++)
				{
					if(player_2_pos[i]!=-1&&player_2_pos[i]<=56&&player_2_pos[i]+dice_num<56)
					{
						drawPlayerGuti(2,player_2_pos[i]-dice_num);
					}
					else if(player_2_pos[i]+dice_num>56)
					{
						drawPlayerGuti(2,player_2_pos[i]);
					}
				}
			}




		}
		if(active_player==1)
		{
			iSetColor(255, 255, 255);
			if(got_six==1)
			{
				can_play[0]=1;
				/*if(player_1_pos[0]==-1)
				{
					player_1_pos[0]=0;
					num_play[0]=1;
					iText(5,465,"Six!! Roll again",GLUT_BITMAP_HELVETICA_18);
					printf("No prompt\n");
				}
				else*/
				if(num_play[0]>0)
				{
					if(player_1_pos[num_play[0]-1]==0)
					{
						iText(5,465,"Roll The dice",GLUT_BITMAP_HELVETICA_18);
					}
					else if(player_1_pos[num_play[0]-1]!=0)
					{
						// printf("make prompt for 1:%d\n",make_prompt_flag[0]);
						if(make_prompt_flag[0]==1)
						{
							iText(5,465,"6!!Choose option",GLUT_BITMAP_HELVETICA_18);
							makePrompt(1);
						}



					}
				}
				else
				{
					if(player_1_pos[num_play[0]]==0)
					{
						iText(5,465,"Roll The dice",GLUT_BITMAP_HELVETICA_18);
					}
					else if(player_1_pos[num_play[0]]!=0)
					{
						// printf("make prompt for 1:%d\n",make_prompt_flag[0]);
						if(make_prompt_flag[0]==1)
						{
							iText(5,465,"6!!Choose option",GLUT_BITMAP_HELVETICA_18);
							makePrompt(1);
						}



					}
				}
				if(roll_flag[0]==1)
				{
					iSetColor(255,255,255);
					iText(5,465,"Select Guti to move \n\r#",GLUT_BITMAP_HELVETICA_18);
						iText(10,440,player_one_number,GLUT_BITMAP_HELVETICA_18);

				}
				if(option!=0&&make_prompt_flag[0]==1)
				{
					if(option==1)
					{
						player_1_pos[num_play[0]]=0;
						num_play[0]++;
						option=0;
						make_prompt_flag[0]=0;

					}
					else if(option==2)
					{
						make_prompt_flag[0]=0;
						option=0;
						roll_flag[0]=1;
					}
				}

			}
			else
			{
				if(can_play[0]==1)
				{
					if(roll_flag[0]==0)
					{
						iText(5,465,"Roll The dice ",GLUT_BITMAP_HELVETICA_18);
					}
					else
					{
						iText(5,465,"Select Guti to move \n\r",GLUT_BITMAP_HELVETICA_12);
						iText(10,440,player_one_number,GLUT_BITMAP_HELVETICA_18);

					}
				}
				else
				{
					iText(5,465,"Your Turn Now",GLUT_BITMAP_HELVETICA_18);
				}

			}


			iText(5,300,player_two_number,GLUT_BITMAP_HELVETICA_18);
		}
		else if(active_player==2)
		{
			iSetColor(255, 255, 255);
			if(got_six==1)
			{
				can_play[1]=1;

				//iText(5,300,"Six!! Roll again",GLUT_BITMAP_HELVETICA_18);
				//cpy start

				/*if(player_2_pos[0]==-1)
				{
					player_2_pos[0]=0;
					num_play[1]=1;
					iText(5,300,"Six!! Roll again",GLUT_BITMAP_HELVETICA_18);
					printf("No prompt\n");
				}
				else*/
				if(num_play[1]>0)
				{
					if(player_2_pos[num_play[1]-1]==0)
					{
						iSetColor(255,255,255);
						iText(5,300,"Roll The dice",GLUT_BITMAP_HELVETICA_18);
					}
					else if(player_2_pos[num_play[1]-1]!=0)
					{
						if(make_prompt_flag[1]==1)
						{
							iText(5,300,"6!!Choose option",GLUT_BITMAP_HELVETICA_18);
							makePrompt(2);
						}



					}
				}
				else
				{
					if(player_2_pos[num_play[1]]==0)
					{
						iSetColor(255,255,255);
						iText(5,300,"Roll The dice",GLUT_BITMAP_HELVETICA_18);
					}
					else if(player_2_pos[num_play[1]]!=0)
					{
						if(make_prompt_flag[1]==1)
						{
							iText(5,300,"6!!Choose option",GLUT_BITMAP_HELVETICA_18);
							makePrompt(2);
						}



					}
				}

				if(roll_flag[1]==1)
				{
					iSetColor(255,255,255);
					iText(5,300,"Select Guti to move \n\r",GLUT_BITMAP_HELVETICA_12);
						iText(10,280,player_two_number,GLUT_BITMAP_HELVETICA_18);

				}
				if(option!=0&&make_prompt_flag[1]==1)
				{
					if(option==1)
					{
						player_2_pos[num_play[1]]=0;
						num_play[1]++;
						option=0;
						make_prompt_flag[1]=0;

					}
					else if(option==2)
					{
						make_prompt_flag[1]=0;
						option=0;
						roll_flag[1]=1;
					}
				}
				//cpy end
			}
			else
			{
				if(can_play[1]==1)
				{
					if(roll_flag[1]==0)
					{
						iText(5,300,"Roll The dice",GLUT_BITMAP_HELVETICA_18);
					}
					else
					{
						iText(5,300,"Select Guti to move \n\r",GLUT_BITMAP_HELVETICA_12);
						iText(10,280,player_two_number,GLUT_BITMAP_HELVETICA_18);

					}
				}
				else
				{
					iText(5,300,"Your Turn Now",GLUT_BITMAP_HELVETICA_18);
				}
				//iText(5,300,"Your Turn Now",GLUT_BITMAP_HELVETICA_18);
			}

			iText(5,440,player_one_number,GLUT_BITMAP_HELVETICA_18);
		}
	}







}
void makePrompt(int num)
{

	if(num==1)
	{

		iSetColor(255, 255, 255);
		if(num_play[0]<4)
		iFilledRectangle(5,440,60,20);
		if(num_play[0]>0)
			iFilledRectangle(75,440,60,20);
		iSetColor(0, 0, 0);
		if(num_play[0]<4)
		{
			iText(15,445,"Add Guti",GLUT_BITMAP_TIMES_ROMAN_10);
		}
		if(num_play[0]>0)
			iText(80,445,"Move This",GLUT_BITMAP_TIMES_ROMAN_10);
	}
	else if(num==2)
	{
		iSetColor(255, 255, 255);
		if(num_play[1]<4)
			iFilledRectangle(5,270,60,20);
		if(num_play[1]>0)
			iFilledRectangle(75,270,60,20);
		iSetColor(0, 0, 0);
		if(num_play[1]<4)
			iText(15,275,"Add Guti",GLUT_BITMAP_TIMES_ROMAN_10);
		if(num_play[1]>0)
			iText(80,275,"Move This",GLUT_BITMAP_TIMES_ROMAN_10);
	}

}
void checkWinner()
{
	int flag=0;
	for(int i=0;i<4;i++)
	{
		if(player_1_pos[i]!=56)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	{
		flag=0;
		for(int i=0;i<4;i++)
		{
			if(player_2_pos[i]!=56)
			{
				flag=2;
				break;
			}
		}
		if(flag=0)
		{
			winner=2;
			whatScreen=4;
		}
	}
	else
	{
		winner=1;
		whatScreen=4;

	}

}
void drawPlayerGuti(int playerNum,int position)
{
	int board,index;
	float pos[2];
	if(playerNum==1)
	{
		if(position>56)
		{
			position=56;
		}
		board=player1_path[position]/100;
		index=player1_path[position]%100;

	}
	else if(playerNum==2)
	{
		if(position>56)
		{
			position=56;
		}
		board=player2_path[position]/100;
		index=player2_path[position]%100;
	}
	if(board==0)
	{
		pos[0]=green_board[index][0];
		pos[1]=green_board[index][1];

	}
	else if(board==1)
	{
		pos[0]=yellow_board[index][0];
		pos[1]=yellow_board[index][1];

	}
	else if(board==2)
	{
		pos[0]=red_board[index][0];
		pos[1]=red_board[index][1];
	}
	else if(board==3)
	{
		pos[0]=blue_board[index][0];
		pos[1]=blue_board[index][1];

	}
	iSetColor(0,0,0);
	iCircle(pos[0],pos[1],11);
	if(playerNum==1)
	{
		iSetColor(23, 239, 0);
	}
	else
	{
		iSetColor(242, 42, 52);
	}

	iFilledCircle(pos[0],pos[1],10);
}
int* getXYFromPosition(int position,int playerNum)
{
	int board,index;
	int pos[2];
	if(playerNum==1)
	{
		board=player1_path[position]/100;
		index=player1_path[position]%100;
	}
	else
	{
		board=player2_path[position]/100;
		index=player2_path[position]%100;
	}
	if(board==0)
	{
		pos[0]=green_board[index][0];
		pos[1]=green_board[index][1];

	}
	else if(board==1)
	{
		pos[0]=yellow_board[index][0];
		pos[1]=yellow_board[index][1];

	}
	else if(board==2)
	{
		pos[0]=red_board[index][0];
		pos[1]=red_board[index][1];
	}
	else if(board==3)
	{
		pos[0]=blue_board[index][0];
		pos[1]=blue_board[index][1];

	}
	return pos;

}

int rollDice()
{
	srand(time(NULL));
	int num=rand() % 6 + 1;
	return num;
}
void checkCanMove()
{
	iSetColor(255, 255, 255);
	if(can_play[0]==0)
	{
		iText(5, 490, "You can not move.", GLUT_BITMAP_HELVETICA_12);
	}
	else
	{
		iText(5, 490, "You can move now", GLUT_BITMAP_HELVETICA_12);
	}
	if(can_play[1]==0)
	{
		iText(5, 320, "You can not move", GLUT_BITMAP_HELVETICA_12);
	}
	else
	{
		iText(5, 320, "You can move now", GLUT_BITMAP_HELVETICA_12);
	}
}
/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{

	printf("Mouse Clicked\n");
	printf("isRoll 1: %d isRoll 1: %d\n",roll_flag[0],roll_flag[1]);
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		if(mx>=100 && mx<=200 &&my>=300 &&my<=350 && whatScreen==0)
		{
			whatScreen=1;
		}
		if(mx>=7 && mx<=27 &&my>=18 && my<=38 && whatScreen==0)
		{
		    whatScreen=1;
		}
		if(mx>=100 && mx<=300 &&my>=230 && my<=280 && whatScreen==0)
		{
		    whatScreen=5;
		}
		if(mx>=100 && mx<=300 &&my>=180 && my<=215 && whatScreen==0)
		{
		    whatScreen=6;
		}
		if(mx>=100 && mx<=150 && my>=110  && my<=160 && whatScreen==0)
		{
			exit(1);
		}
		if(mx>=4 && mx<=104 && my>=530 && my<=580 && whatScreen==3)
		{
		  whatScreen=0;
		}
        //if(mx>=4 && mx<=104 && my>=530 && my<=580 && whatScreen==5)
		//{
		 // whatScreen=0;
		//}
        //if(mx>=4 && mx<=104 && my>=530 && my<=580 && whatScreen==6)
		//{
		  //whatScreen=0;
		//}
        if(mx>=10 && mx<=200 && my>=10 && my<=100 && whatScreen==5)
		{
		  whatScreen=0;
		}
        if(mx>=10 && mx<=200 && my>=10 && my<=100 && whatScreen==6)
		{
		  whatScreen=0;
		}
		if(whatScreen==3)
		{
			int dice_num=rollDice();
			printf("Num of guti of player 1: %d\n",num_play[0]);
			if(roll_flag[0]==0&&roll_flag[1]==0)
			{
				if(mx>=5 && mx<=105 &&my>=150 &&my<=200)
				{

					printf("%d\n",dice_num);


					if(active_player==1)
					{

						itoa (1,player_two_number,10);
						itoa (dice_num,player_one_number,10);

						if(dice_num!=6)
						{

							got_six=0;
							if(can_play[0]==1)
							{
								roll_flag[0]=1;
								prev_pos[0]=player_1_pos[0];

								for(int i=0;i<4;i++)
								{
									if(player_1_pos[i]!=-1)
									{

										if(56-player_1_pos[i]>=dice_num)
										{


											player_1_pos[i]+=dice_num;
										}
									}
								}

								printf("player 1 pos:%d  board:%d\n",player1_path[player_1_pos[0]],player1_path[player_1_pos[0]]/100);
							}
							else
							{
								active_player=2;
							}


						}
						else
						{
							got_six=1;

								if(make_prompt_flag[0]==0)
								{

									make_prompt_flag[0]=1;




								}


						}
					}
				}
				else if(mx>=5 && mx<=105 &&my>=50 &&my<=100)
				{
					if(active_player==2)
					{
						itoa (1,player_one_number,10);
						itoa (dice_num,player_two_number,10);

						if(dice_num!=6)
						{
							// active_player=1;
							got_six=0;
							if(can_play[1]==1)
							{
								// if(56-player_2_pos[0]>=dice_num)
								// {
									// prev_pos[1]=player_2_pos[0];
									// roll_flag[1]=1;
									// player_2_pos[0]+=dice_num;
								// }
								roll_flag[1]=1;
								prev_pos[1]=player_2_pos[0];
								for(int i=0;i<4;i++)
								{
									if(player_2_pos[i]!=-1)
									{

										if(56-player_2_pos[i]>=dice_num)
										{


											player_2_pos[i]+=dice_num;
										}
									}
								}
								printf("player 2 pos:%d  board:%d\n",player2_path[player_2_pos[0]],player2_path[player_2_pos[0]]/100);
									// if(56-player_2_pos[0]>=dice_num)
									// player_2_pos[0]+=dice_num;

							}
							else
							{
								active_player=1;
							}
						}
						else
						{
							got_six=1;
							if(make_prompt_flag[1]==0)
							{

								make_prompt_flag[1]=1;



							}

						}
					}
				}
			}
			if(roll_flag[0]==1)
			{
				if(can_play[0]==1&&active_player==1)
				{
					int dice_num=player_1_pos[0]-prev_pos[0];


					for(int i=0;i<4;i++)
					{
						if(player_1_pos[i]!=-1)
						{
							int* pos=getXYFromPosition(player_1_pos[i]-dice_num,1);
							int x=pos[0],y=pos[1];
							if(mx>=x-20 && mx<=x+20 && my<=y+20 && my>=y-20)
							{
								printf("---------------- %d-------\n",i);
								move_guti_flag[0]=1;
								selected_guti[0]=i;
								break;
							}
						}
					}

				}

			}
			else if(roll_flag[1]==1)
			{
				printf("---player 2 can flag:%d active_player:%d\n\n",can_play[1],active_player);
				if(can_play[1]==1&&active_player==2)
				{
					// int* pos=getXYFromPosition(prev_pos[1],2);
					// int x=pos[0],y=pos[1];

					// printf("-------------player 2: mx:%d my:%d x:%d y:%d\n",mx,my,x,y);
					// if(mx>=x-20 && mx<=x+20 && my<=y+20 && my>=y-20)
					// {
						// printf("----------------");
						// move_guti_flag[1]=1;
					// }
					//h
					int dice_num=player_2_pos[0]-prev_pos[1];


					for(int i=0;i<4;i++)
					{
						if(player_2_pos[i]!=-1)
						{
							int* pos=getXYFromPosition(player_2_pos[i]-dice_num,2);
							int x=pos[0],y=pos[1];
							if(mx>=x-20 && mx<=x+20 && my<=y+20 && my>=y-20)
							{
								printf("---------------- %d-------\n",i);
								move_guti_flag[1]=1;
								selected_guti[1]=i;
								break;
							}
						}
					}
					//j

				}
			}
			printf("has prompt1:%d\n",make_prompt_flag[0]);
			printf("has prompt2:%d\n",make_prompt_flag[1]);
			if(make_prompt_flag[0]==1)
			{
				if(can_play[0]==1&&active_player==1)
				{
					if(mx>=5 && mx<=65 &&my>=440 &&my<=460)
					{
						option=1;
					}
					else if(mx>=75 && mx<=135 &&my>=440 &&my<=460)
					{
						option=2;
						printf("option 2 selected.... to move %d\n",player_1_pos[0]-prev_pos[0]);
						if(56-player_1_pos[0]>=6)
						{
							prev_pos[0]=player_1_pos[0];

							for(int i=0;i<4;i++)
							{
								if(player_1_pos[i]!=-1)
								{

									if(56-player_1_pos[i]>=6)
									{


										player_1_pos[i]+=6;
									}
								}
							}

						}


					}
				}
			}
			else if(make_prompt_flag[1]==1)
			{
				if(can_play[1]==1&&active_player==2)
				{
					printf("in prompt mx:%d my:%d\n",mx,my);
					if(mx>=5 && mx<=65 &&my>=270 &&my<=290)
					{
						option=1;
					}
					else if(mx>=75 && mx<=135 &&my>=270 &&my<=290)
					{
						option=2;
						printf("option 2 selected.... to move %d\n",player_2_pos[0]-prev_pos[1]);
						prev_pos[1]=player_2_pos[0];
						for(int i=0;i<4;i++)
						{
							if(player_2_pos[i]!=-1)
							{

								if(56-player_2_pos[i]>=6)
								{


									player_2_pos[i]+=6;
								}
							}
						}


					}
				}
			}


		}






	}
	//if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	//{
		//place your codes here

	//}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	//if(key == 'q')
	//{
		//do something with 'q'
	//}
	//place your codes for other keys here
	int i;
	if(whatScreen == 1)
	{
		if(key == '\r')
		{

			strcpy(firstName, tempStr);
			printf("%s\n", firstName);
			for(i = 0; i < len; i++)
				tempStr[i] = 0;
			whatScreen=2;
			len = 0;
		}
		else
		{
			tempStr[len] = key;
			len++;
		}
	}
	else if(whatScreen == 2)
	{
		if(key == '\r')
		{

			strcpy(secondName, tempStr);
			printf("%s\n", secondName);
			for(i = 0; i < len; i++)
				tempStr[i] = 0;
			whatScreen=3;
			active_player=1;
			len = 0;
		}
		else
		{
			tempStr[len] = key;
			len++;
		}
	}

//	if(key == 'x')
//	{
		//do something with 'x'
//		exit(0);
//	}

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
void iSpecialKeyboard(unsigned char key)
{

	//if(key == GLUT_KEY_END)
	//{
	//	exit(0);
	//}
	//place your codes for other keys here
}

int main()
{
	//place your own initialization codes here.
	whatScreen=0;
	len=0;
	tempStr[0]= 0;
	active_player=0;
	player_one_number[0]=0;
	player_two_number[0]=0;
	iInitialize(800,650,"Ludo");
	return 0;
}
