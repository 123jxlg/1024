#include "game.h"
void menu()
{
	printf("************************************\n");
	printf("******  1 play   0 exit  ***********\n");
	printf("************************************\n");
}
void play(){
	int ret=0;
	int count1 = 1;
	char board1[ROWS][COLS] = {0};
	char show[ROWS][COLS] = {0};
	InitBoard(board1, ROWS, COLS,'0');
	InitBoard(show, ROWS, COLS, '*');
	SetMine(board1, ROW, COL);
	DisplayBoard(board1, ROW, COL);
	DisplayBoard(show, ROW, COL);
	while (ret<(ROW*COL - EASY_COUNT))
	{
		
		int x = 0;
		int y = 0;
		printf("����������\n");
		scanf("%d", &x);
		scanf("%d", &y);
       if (x>=1&&x<=9&&y>=1&&y<=9){
		   if (board1[x][y] == 1 + '0'&&count1 != 1){
			   printf("ը����");
			   break;
			}
		   else{
			   if (board1[x][y] == 1 + '0'&&count1 == 1){
				   SetMine(board1, ROW, COL);
				   //DisplayBoard(board1, ROW, COL);
				  }
			   int count = GetMineCount(board1, x, y);
			   show[x][y] = count + '0';
			   char * p = spread(board1, x, y);
			   show[x][y - 1] = *p;
			   show[x - 1][y - 1] = *(p + 1);
			   show[x - 1][y] = *(p + 2);
			   show[x + 1][y - 1] = *(p + 3);
			   DisplayBoard(show, ROW, COL);
			   count1++;
		   }
		       
	}
		else{
			printf("��������겻�Ϸ�,����������\n");
		}

	}
	if (ret==(ROW*COL - EASY_COUNT)){
		printf("��Ŷ:��ϲ�����׳ɹ�!");
	}
}

int main(){
	int input = 0;
	do{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch(input)
		{
		case 1:
		    play();
			break;
		case 0:
			printf("�˳���Ϸ");
			break;
		default:
			printf("ѡ�����,������ѡ��");
			break;
		}
	} while(input);
	system("pause");
	return 0;
}