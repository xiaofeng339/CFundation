//1.Ŀ��Ϊ������ֻ��һ��ʵ����ʵ������Ҫ�Լ��ͷ�
//2.��Ĭ�Ϲ���Ϳ�������˽�л�
//3.�ڲ�ά��һ������ָ��
//4.˽�л�Ψһָ��
//5.�����ṩgetInstance�������������ָ��
//6.��֤����ֻ��ʵ����Ψһ������
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>	
using namespace std;

//��������
//���� ����ģʽ Ϊ�˴������еĶ��󣬲���ֻ֤��һ������ʵ��
class ChairMan {
private:
	ChairMan() {}
    
	static ChairMan* singleMan;
	//����˽�л�
	ChairMan(const ChairMan&c){} 

public:
	static ChairMan* getInstance() {
		return singleMan;
	}
};
ChairMan* ChairMan::singleMan = new ChairMan;