#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include"wall.h"
#include"snake_STL.h"
#include"food.h"
#include<ctime>
#include<conio.h>
#include<Windows.h>

void gotoxy(HANDLE hOut, int x, int y)
{
	COORD pos;
	pos.X = x;             //������
	pos.Y = y;            //������
	SetConsoleCursorPosition(hOut, pos);
}
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//������ʾ���������


int main() {
	//����������
	srand((unsigned int) time(NULL));

	//�Ƿ�������ʾ
	bool isDead = false;
	char preKey = NULL;
	Wall wall;
	wall.initWall();
	wall.drawWall();
	Food food(wall);
	food.setFood();
	

	Snake snake(wall,food);
	snake.initSanke();

	
	gotoxy(hOut, 0, Wall::ROW);
	cout << "�÷֣�" << snake.getScore() << "��" << endl;
	

	//�����û�����
	
	while (!isDead) {
		char key = _getch();

		//�ж� �����һ������d ���ܼ�����Ϸ

		if (preKey == NULL && key == snake.LEFT) {
			continue;
		}
		do
		{
			if (key == snake.UP || key == snake.DOWN || key == snake.LEFT || key == snake.RIGHT) {
				
				if ((key == snake.LEFT &&preKey==snake.RIGHT)||
					(key == snake.RIGHT && preKey == snake.LEFT)||
					(key == snake.UP && preKey == snake.DOWN)||
					(key == snake.DOWN && preKey == snake.UP)) {
					key = preKey;
				}
				else
				{
					preKey = key;  //���ǳ�ͻ���� ���Ը��°���
				}
				
				if (snake.move(key) == true) {
					//�ƶ��ɹ� ����
					//system("cls");
					//wall.drawWall();
					gotoxy(hOut, 0, Wall::ROW);
					cout << "�÷֣�" << snake.getScore()  << endl;
					Sleep(snake.getSleepTime());
				}
				else {
					isDead = true;
					break;
				}
			}
			else
			{
				key = preKey;//ǿ�ƽ����󰴼���Ϊ��һ���ƶ��ķ���
			}
			

		} while (!_kbhit());
		

	}
	
	system("pause");
	return EXIT_SUCCESS;
}