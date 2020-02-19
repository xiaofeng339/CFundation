//1.目的为了让类只有一个实例，实例不需要自己释放
//2.将默认构造和拷贝构造私有化
//3.内部维护一个对象指针
//4.私有化唯一指针
//5.对外提供getInstance方法来访问这个指针
//6.保证类中只能实例化唯一个对象
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>	
using namespace std;

//创建主类
//需求 单例模式 为了创建类中的对象，并保证只有一个对象实例
class ChairMan {
private:
	ChairMan() {}
    
	static ChairMan* singleMan;
	//拷贝私有化
	ChairMan(const ChairMan&c){} 

public:
	static ChairMan* getInstance() {
		return singleMan;
	}
};
ChairMan* ChairMan::singleMan = new ChairMan;