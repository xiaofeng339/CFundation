#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>	
#include"SeqStack.h"
//算法思路
//1.从第一个字符开始扫描
//2.当遇见普通字符时忽略
//3.当遇到左符号时压入栈中
//4.当遇到左括号时压入栈中
//5，当遇到右括号时从栈中弹出栈顶符号，并惊醒匹配
//6.匹配成功：继续读入下一个字符
//7.匹配失败：立即停止，并报错
//8.结束
//9.成功：所有字符扫描完毕，且栈空
//10.失败：匹配失败或所有字符扫描完毕但栈非空

int IsLeft(char ch) {
	return ch == '(';
}
int IsRight(char ch) {
	return ch == ')';
}
void printError(const char* str,char *errMsg,char *pos) {
	printf("错误信息：%s\n", errMsg);
	printf("%s\n",str);
	int dis = pos - str;
	for (int i = 0; i < dis; ++i) {
		printf(" ");
	}
	printf("A\n");
}
void test() {
	const* str = "5+5*(6)+9/3*1)-(1+3";
	char* p = str;
	//初始化栈
	SeqStack stack = Init_SeqStack();
	while (*p != '\0') {
		//判断当前字符是否是左括号
		if (IsLeft(*p)) {
			Push_SeqStack(stack, p);
		}

		//判断当前字符是否是右括号
		if (IsRight(*p)) {
			if (Size_SeqStack(stack) > 0) {
				//弹出栈顶元素
				Pop_SeqStack(stack);
			}
			else
			{
				printError(str, "右括号没有匹配的左括号！",p);

			}
		}
		p++;
	}
	while (Size_SeqStack(stack) > 0) {
		printError(str, "没有匹配右括号！", Top_SeqStack(stack));
		Pop_SeqStack(stack);
	}
}