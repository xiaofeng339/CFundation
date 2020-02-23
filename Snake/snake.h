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
	//节点
	//struct Point {
	//	//数据域
	//	int x;
	//	int y;

	//	//指针域
	//	Point* next;
	//};
	
	//初始化蛇
	void initSanke();
	//销毁节点
	void destroyPoint();
	//添加节点
	void addPoint(int x, int y);
	//删除节点
	void delPoint();

	//设定难度
	//获取刷屏时间
	int getSleepTime();
	//获取蛇身段
	int countList();
	//获取分数
	int getScore();
	//返回值代表  移动是否成功
	bool move(char key);
private:
	list<pair<int, int>> lSnake;
	Wall& wall;
	Food& food;
	bool isRool;
};
