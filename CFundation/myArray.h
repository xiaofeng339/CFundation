#pragma once
#include <iostream>	
using namespace std;
class MyArray {
public:
	MyArray();//默认构造，默认100用量
	MyArray(int capacity);
	MyArray(const MyArray& array);
	~MyArray();

	//尾插法
	void push_Back(int val);
	//按位置取值
	int getData(int index);
	//按位置设值
	void setData(int index, int val);
private:
	int* pAddress;//指向真正存储数据的指针
	int m_Size;//数组大小
	int m_Capacity;
};