#pragma once
#include<iostream>	
using namespace std;

template<class T>
class MyArray
{
public:
	MyArray();
	explicit MyArray(int capacity) {//��ֹ��ʽ����ת�� ����MyArray array=10;
		this->m_Capacity=capacity;
		this->m_Size = 0;
		this->pAddress = newT[this->m_Capacity];
	}
	MyArray(const MyArray& array) {
		this->m_Capacity = array.m_Capacity;
		this->m_Size = array.m_Size;
		this->pAddress = new T[this->m_Capacity];
		for (int i = 0; i < m_Size, i++) {
			this->pAddress[i] = array[i];
		}
	}
	~MyArray() {
		if (this->pAddress != NULL) {
			delete[]this->pAddress;
			this->pAddress = NULL;
		}
	}
	//��ֵ����������
	MyArray& operator(MyArray& array) {
		//���ж�ԭʼ���ݣ��о����
		if (this->pAddress != NULL) {
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
		this->m_Capacity = array.m_Capacity;
		this->m_Size = array.m_Size;
		this->pAddress = new T[this->m_Capacity];
		for (int i = 0; i < m_Size, i++) {
			this->pAddress[i] = array[i];
		}
	}
	//[]����
	//MyArray arr(10);
	//arr[0]=100
	T& operator[](int index) {
		return this->pAddress[index];
	}
	//β�巨
	void push_Back(T& val) {
		this->pAddress[this->m_Size] = val;
		this->m_Size++;
	}
	//��ȡ��С
	int getSize() {
		return m_Size;
	}
	//��ȡ����
	int getCapacity() {
		return this->m_Capacity;
	}
private:
	T* pAddress;//ָ�����ָ��
	int m_Capacity;//����
	int m_Size;
};

