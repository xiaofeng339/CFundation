#include "snake.h"
#include<Windows.h>
void gotoxy1(HANDLE hOut1, int x, int y)
{
	COORD pos;
	pos.X = x;             //������
	pos.Y = y;            //������
	SetConsoleCursorPosition(hOut1, pos);
}
HANDLE hOut1 = GetStdHandle(STD_OUTPUT_HANDLE);//������ʾ���������


Snake::Snake(Wall &tempWall,Food &tempfood):wall(tempWall),food(tempfood)
{

	isRool = false;
}

void Snake::initSanke()
{
	destroyPoint();
	addPoint(5, 3);
	addPoint(5, 4);
	addPoint(5, 5);

}

void Snake::destroyPoint()
{
	/*Point* pCur = pHead;
	while (pHead != NULL) {
		pCur = pHead->next;
		delete pHead;
		pHead = pCur;
	}*/
	while (lSnake.empty() != true) {

		//��������Ϊ' '
		pair<int, int>p = lSnake.front();
		lSnake.pop_front();
	}
}

void Snake::addPoint(int x, int y)
{
	////�����½ڵ�
	//Point* newPoint = new Point;
	//newPoint->x = x;
	//newPoint->y = y;
	//newPoint->next = NULL;
	////���ԭ��ͷ��Ϊ�ո�Ϊ����
	//if (pHead != NULL)
	//{
	//	wall.setWall(pHead->x, pHead->y, '=');
	//	gotoxy1(hOut1, pHead->y * 2, pHead->x);
	//	cout << "="; 
	//}
	//newPoint->next = pHead;
	//pHead = newPoint;//����ͷ��
	//wall.setWall(pHead->x, pHead->y, '@');
	//gotoxy1(hOut1, pHead->y * 2, pHead->x);
	//cout << "@";

	pair<int, int> p;
	if (lSnake.empty() != true) {
		p = lSnake.front();
		wall.setWall(p.first, p.second, '=');
		gotoxy1(hOut1, p.second * 2, p.first);
		cout << "=";
	}
	lSnake.push_front(make_pair(x, y));
	p = lSnake.front();
	wall.setWall(p.first, p.second, '@');
	gotoxy1(hOut1, p.second * 2, p.first);
	cout << "@";
	
	
}

void Snake::delPoint()
{
	//	if (pHead == NULL || pHead->next == NULL) {
	//		return;
	//	}
	//	Point* pCur = pHead->next;
	//	Point* pPre = pHead;
	//	while (pCur->next != NULL) {
	//		pPre = pPre->next;
	//		pCur = pCur->next;
	//	}
	//	//ɾ��β�ڵ�
	//	wall.setWall(pCur->x, pCur->y, ' ');
	//	gotoxy1(hOut1, pCur->y * 2, pCur->x);
	//	cout << " ";
	//	delete pCur;
	//	pCur = NULL;
	//	pPre->next = NULL;
	
	pair<int, int> p = lSnake.back();
	wall.setWall(p.first, p.second, ' ');
	gotoxy1(hOut1, p.second * 2, p.first);
	cout << " ";
	lSnake.pop_back();
}


int Snake::getSleepTime()
{
	int sleepTime = 0;
	int size = countList();
	if (size < 5) {
		sleepTime = 300;
	}
	else if (size >= 5 && size <= 8) {
		sleepTime = 200;
	}
	else
	{
		sleepTime = 100;
	}
	return sleepTime;
}

int Snake::countList()
{
	
	return lSnake.size();
}

int Snake::getScore()
{
	int size = countList();
	int score = (size - 3) * 100;
	return score;
}

bool Snake::move(char key)
{
	/*int x = pHead->x;
	int y = pHead->y;*/
	pair<int, int> p = lSnake.front();
	int x = p.first;
	int y = p.second;
	switch (key)
	{
	case UP:
		x--;
		break;
	case DOWN:
		x++;
		break;
	case LEFT:
		y--;
		break;
	case RIGHT:
		y++;
		break;
	default:
		break;
	}

	//�ж� �������һ����������β�ͣ���Ӧ������
	pair<int, int>cur = lSnake.back();//��β

	if (cur.first == x &&cur.second == y) {
		//����β��
		isRool = true;
	}
	else
	{
		//�ж��û�����λ���Ƿ�ɹ�
		if (wall.getWall(x, y) == '*' || wall.getWall(x, y) == '=') {
			addPoint(x, y);
			delPoint();
			system("cls");
			wall.drawWall();
			cout << "�÷֣�" << getScore() << endl;
			cout << "game over!!!" << endl;
			return false;
		}
		
	}
	//�ƶ��ɹ� ������
		//�Ե�ʳ�� δ�Ե�ʳ��
	if (wall.getWall(x, y) == '#') {
		addPoint(x, y);
		//��������ʳ��
		food.setFood();

	}
	else {
		addPoint(x, y);
		delPoint();
		if (isRool == true) {
			wall.setWall(x, y, '@');
			gotoxy1(hOut1, 2 * y, x);
			cout << "@";
		}
		
	}
	return true;
}
