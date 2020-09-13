#include <stdio.h>
#include <time.h>   
#include <conio.h>   
#include <windows.h>
void start_game(); // ��ʼ��Ϸ 
void reset_game(); // ������Ϸ 

void move_left();
void move_right();
void move_up();
void move_down();

void refresh_show();    // ˢ�½�����ʾ
void add_rand_num();    // ������������������н�����2��4������֮����Ϊ2:1
void check_game_over(); // ����Ƿ������Ϸ���趨��Ϸ������־
int get_null_count();   // ��ȡ��Ϸ����Ͽ�λ������ 
void color(int m);
int board[4][4];     // ��Ϸ������壬����Ϊ��ά���� 
int score;           // ��Ϸ�ķ� 
int if_need_add_num; // �Ƿ���Ҫ�����������־��1��ʾ��Ҫ��0��ʾ����Ҫ
int if_game_over;    // �Ƿ���Ϸ������־��1��ʾ��Ϸ������0��ʾ����

int main()
{
	start_game();
}

// ��ʼ��Ϸ ��������
void start_game()
{
	reset_game();
	char cmd;
	while (1)
	{
		cmd = getch(); // ���ձ�׼�������ַ�����

		if (if_game_over) // �ж��Ƿ��Ѿ������Ϸ
		{
			if (cmd == 'y' || cmd == 'Y') // ������Ϸ
			{
				reset_game();
				continue;
			}
			else if (cmd == 'n' || cmd == 'N') // �˳�
			{
				return;
			}
			else
			{
				continue;
			}
		}

		if_need_add_num = 0; // ���趨��Ĭ����Ҫ�������������Ҫʱ���趨Ϊ 1

		switch (cmd) // ������� w��s��a��d �ַ�����������������
		{
			case 'a':
			case 'A':
			case 75:
				move_left();
				break;
			case 's':
			case 'S':
			case 80:
				move_down();
				break;
			case 'w':
			case 'W':
			case 72:
				move_up();
				break;
			case 'd':
			case 'D':
			case 77:
				move_right();
				break;
		}
		if (if_need_add_num) //Ĭ��Ϊ��Ҫ���������ʱҲͬʱ��Ҫˢ����ʾ����֮��Ȼ 
		{
			add_rand_num();
			refresh_show();
		}
	}
}

//������Ϸ ��������
void reset_game()
{
	score = 0;
	if_need_add_num = 1;
	if_game_over = 0;

	// �˽⵽��Ϸ��ʼ��ʱ���ֵ�������һ�����и� 2���������������һ�� 2��������Ϊ 0 
	int n = rand() % 16;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			board[i][j] = (n-- == 0 ? 2 : 0);
		}
	}

	// ǰ���Ѿ�������һ��2������������һ�������2����4�����趨����2�ĸ�����4������
	add_rand_num();

	// ������ˢ�½��沢��ʾ��ʱ�򣬽������Ѿ�Ĭ�ϳ������������֣������Ķ�Ϊ�գ�ֵΪ0��
	system("cls");
	refresh_show();
}

// ��������� ��������
void add_rand_num()
{
	srand(time(0));
	int n = rand() % get_null_count();// ȷ���ںδ���λ�����������
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (board[i][j] == 0)
			{
				if (n-- == 0) {//��λ�����ɵ�λ��
					board[i][j] = (rand() % 3 ? 2 : 4);//rand() % 3��ֵΪ�棨1��2��ȡǰֵ2����֮��ȡ 4 ����֤���� 2 �ĸ����� 4 �� 2 ��
					return;
				}
			}
		}
	}
}
// ��ȡ��λ������ ��������
int get_null_count()
{
	int n = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			board[i][j] == 0 ? n++ : 1;
		}
	}
	return n;
}
// �����Ϸ�Ƿ���� ��������
void check_game_over()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			// ���������Ƚϰ��ŵ�����Ԫ���Ƿ���ȣ������������Ϸ������
			if (board[i][j] == board[i][j + 1] || board[j][i] == board[j + 1][i])
			{
				if_game_over = 0;
				return;
			}
		}
	}
	if_game_over = 1;
}

/*
* �����ĸ�������ʵ�����������ƶ�ʱ�������ı仯�㷨
* ������ƶ��ı���һ�����������������ı��������෴
* �Ϻ����ƶ��ı���һ�����������������ı��������෴
* ������ƶ��ı���Ҳһ������������Ǳ���ʱ�к��л���
*/

// ���� ��������
void move_left()
{
	// ����i��������������±꣬�������ƶ�ʱ�������໥����������Ӱ��
	for (int i = 0; i < 4; i++)
	{
		// ����jΪ���±꣬����kΪ���Ƚϣ��ϲ�������±꣬ѭ������ʱk<j 
		for (int j = 1, k = 0; j < 4; j++)
		{
			if (board[i][j] > 0) // �ҳ�k�����һ����Ϊ�յ���±�Ϊj��֮����������
			{
				if (board[i][k] == board[i][j]) // ���1��k���j����ȣ���ʱ�ϲ����鲢�Ʒ�
				{
					score += board[i][k++] <<= 1;//�൱��score += board[i][k++] * 2;
					board[i][j] = 0;
					if_need_add_num = 1; // ��Ҫ�����������ˢ�½���
				}
				else if (board[i][k] == 0) // ���2��k��Ϊ�գ����j�ֵ��k��൱��j�����ƶ���k����
				{
					board[i][k] = board[i][j];
					board[i][j] = 0;
					if_need_add_num = 1;
				}
				else // ���3��k�Ϊ�գ��Һ�j���ȣ���ʱ��j�ֵ��k+1��൱���ƶ���k+1��λ�� 
				{
					board[i][++k] = board[i][j];
					if (j != k) // �ж�j���k���Ƿ�ԭ�ȾͰ���һ�����������j�ֵΪ�գ�ֵΪ0��
					{
						board[i][j] = 0;
						if_need_add_num = 1;
					}
				}
			}
		}
	}
}
// ���� �������� 
void move_up()
{
	// �������Ʋ�����������������л��������
	for (int i = 0; i < 4; i++)
	{
		for (int j = 1, k = 0; j < 4; j++)
		{
			if (board[j][i] > 0)
			{
				if (board[k][i] == board[j][i])
				{
					score += board[k++][i] <<= 1;
					board[j][i] = 0;
					if_need_add_num = 1;
				}
				else if (board[k][i] == 0)
				{
					board[k][i] = board[j][i];
					board[j][i] = 0;
					if_need_add_num = 1;
				}
				else
				{
					board[++k][i] = board[j][i];
					if (j != k)
					{
						board[j][i] = 0;
						if_need_add_num = 1;
					}
				}
			}
		}
	}
}
// ���� �������� 
void move_right()
{
	// �������Ʋ��������������j��k���������
	for (int i = 0; i < 4; i++)
	{
		for (int j = 2, k = 3; j >= 0; j--)
		{
			if (board[i][j] > 0)
			{
				if (board[i][k] == board[i][j])
				{
					score += board[i][k--] <<= 1;
					board[i][j] = 0;
					if_need_add_num = 1;
				}
				else if (board[i][k] == 0)
				{
					board[i][k] = board[i][j];
					board[i][j] = 0;
					if_need_add_num = 1;
				}
				else
				{
					board[i][--k] = board[i][j];
					if (j != k)
					{
						board[i][j] = 0;
						if_need_add_num = 1;
					}
				}
			}
		}
	}
}
// ���� ��������
void move_down()
{
	// �������Ʋ�����������������л������������j��k���������
	for (int i = 0; i < 4; i++)
	{
		for (int j = 2, k = 3; j >= 0; j--)
		{
			if (board[j][i] > 0)
			{
				if (board[k][i] == board[j][i])
				{
					score += board[k--][i] <<= 1;
					board[j][i] = 0;
					if_need_add_num = 1;
				}
				else if (board[k][i] == 0)
				{
					board[k][i] = board[j][i];
					board[j][i] = 0;
					if_need_add_num = 1;
				}
				else
				{
					board[--k][i] = board[j][i];
					if (j != k)
					{
						board[j][i] = 0;
						if_need_add_num = 1;
					}
				}
			}
		}
	}
}


// ˢ�½��� ��������
void refresh_show()
{
	// ���������λ�÷�ʽ�������Լ�����˸��system("cls")Ϊ�������������ΪWindowsƽ̨���
	COORD pos = { 0, 0 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

	printf("\n\n\n\n");
	color(3);
	printf("                game: 2048                     grade: %06d\n", score);
	printf("             --------------------------------------------------\n\n");

	// ���Ʊ��������
	printf("                        -------------\n");
	for (int i = 0; i < 4; i++)
	{
		printf("                        ��");
		for (int j = 0; j < 4; j++)
		{
			if (board[i][j] != 0)
			{
				if (board[i][j] < 10)
				{
					color(2);
					printf("  %d ", board[i][j]);
				}
				else if (board[i][j] < 100)
				{
					color(0xA);
					printf(" %d ", board[i][j]);
				}
				else if (board[i][j] < 1000)
				{
					color(0xE);
					printf(" %d", board[i][j]);
				}
				else if (board[i][j] < 10000)
				{
					color(2);
					printf("%4d", board[i][j]);
				}
				else
				{
					int n = board[i][j];
					for (int k = 1; k < 20; k++)
					{
						n >>= 1;
						if (n == 1)
						{
							printf("2^%02d", k); // ������λ��������2������ʽ��ʾ����2^13��ʽ 
							break;
						}
					}
				}
				color(3);
				printf("��");
			}
			else {
				color(3);
				printf("    ��");
			}
		}
		color(3);
		if (i < 3)
		{
			printf("\n                        �������੤���੤���੤����\n");
		}
		else
		{
			printf("\n                        �������ة����ة����ة�����\n");
		}
	}

	printf("\n");
	printf("             --------------------------------------------------\n");
	color(6);
	printf("                            W|  A<-  ->D  |S");

	if (get_null_count() == 0)
	{
		check_game_over();
		if (if_game_over) //�ж��Ƿ������Ϸ
		{
			color(4);
			printf("\r                    ��Ϸ���������¿�ʼ��Ϸ[Y/N]");
		}
	}
}
void color(int m) {
	HANDLE consolehend;
	consolehend = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consolehend, m);
}