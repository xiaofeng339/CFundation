#pragma once
#include <iostream>	
using namespace std;
class MyArray {
public:
	MyArray();//Ĭ�Ϲ��죬Ĭ��100����
	MyArray(int capacity);
	MyArray(const MyArray& array);
	~MyArray();

	//β�巨
	void push_Back(int val);
	//��λ��ȡֵ
	int getData(int index);
	//��λ����ֵ
	void setData(int index, int val);
private:
	int* pAddress;//ָ�������洢���ݵ�ָ��
	int m_Size;//�����С
	int m_Capacity;
};