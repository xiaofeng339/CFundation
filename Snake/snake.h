#pragma once
#include<iostream>
#include"wall.h"
#include"food.h"
#include<list>
using namespace std;
class Snake {
public:
	Snake(Wall& tempWall,Food &food);
	enum {UP ='w',DOWN ='s',LEFT='a',RIGHT='d' };
	//�ڵ�
	//struct Point {
	//	//������
	//	int x;
	//	int y;

	//	//ָ����
	//	Point* next;
	//};
	
	//��ʼ����
	void initSanke();
	//���ٽڵ�
	void destroyPoint();
	//��ӽڵ�
	void addPoint(int x, int y);
	//ɾ���ڵ�
	void delPoint();

	//�趨�Ѷ�
	//��ȡˢ��ʱ��
	int getSleepTime();
	//��ȡ�����
	int countList();
	//��ȡ����
	int getScore();
	//����ֵ����  �ƶ��Ƿ�ɹ�
	bool move(char key);
private:
	list<pair<int, int>> lSnake;
	Wall& wall;
	Food& food;
	bool isRool;
};
