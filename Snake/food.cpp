#include "food.h"
#include<Windows.h>
void gotox2(HANDLE hOut2, int x, int y)
{
	COORD pos;
	pos.X = x;             //������
	pos.Y = y;            //������
	SetConsoleCursorPosition(hOut2, pos);
}
HANDLE hOut2 = GetStdHandle(STD_OUTPUT_HANDLE);//������ʾ���������
Food::Food(Wall& tempWall):wall(tempWall)
{

}

void Food::setFood()
{


	while (true)
	{
		foodX = rand() % (Wall::ROW - 2) + 1;
		foodY = rand() % (Wall::COL - 2) + 1;
		//��������λ������ͷ�����������������������
		if (wall.getWall(foodX, foodY) == ' ')
		{
			wall.setWall(foodX, foodY, '#');
			gotox2(hOut2, foodY * 2, foodX);
			cout << "#";
			break;
		}
	}
	
}
