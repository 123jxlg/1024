#include "game.h";
void menu()
{
	printf("************************************\n");
	printf("******  1 play   0 exit  ***********\n");
	printf("************************************\n");
}
void play(){
	char board1[ROWS][COLS];
	char show[ROWS][COLS];
	//InitBoard(board1[ROWS][COLS], ROWS, COLS,'0');
    //InitBoard(show[ROWS][COLS], ROWS, COLS, '*');
	mensert(board1, '0', sizeof(board1[0][0]*ROWS*COLS));
	DisplayBoard(board1[ROWS][COLS], ROW, COL);
}
int main(){
	int input = 0;
	do{
		menu();
		printf("��ѡ��:>");
		scanf("%d\n", &input);
		switch (input)
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
	}
	while (input);
	system("pause");
	return 0;
}