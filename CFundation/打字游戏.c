#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>	
#include<conio.h>
#include<time.h>

void tips() {
	printf("==============������Ϸ=================\n");
	printf("=============�����������==============\n");
	printf("============��ESC �˳���Ϸ=============\n");
	char ch = _getch();
	if (ch == 27) {
		exit(0);  
	}
}
void rand_ch(char* arr) {
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 50; i++)       
	{
		arr[i] = rand() % 26 + 'a';
	} 
}

void print_ch(char* arr) {
	int start_time;
	int end_time;
	int val=0;
	for (int i = 0; i < 50; i++)
	{
		char ch = _getch();
		if (i == 0) {
			start_time = time(NULL);
		}
		if (ch == arr[i]) {
			printf("%c", ch);
			val++;
		}
		else
		{
			printf("-");
		}
	}
	end_time = time(NULL);
	printf("\n��ʱ��%d���룩\n", end_time - start_time);
	printf("��ȷ�ʣ�%.1f%%\n", val*1.0/50*100);
}
int printGame() {
	//�ֿ�
	char arr[51];
	memset(arr, 0, 51);
	
	while (1) {
		//��ʾ
		tips();
		//2.����ַ�
		rand_ch(arr);
		printf("%s\n", arr);
		//3.�����ַ�
		print_ch(arr);
	}
	//��ʾ
	tips();
	//2.����ַ�
	rand_ch(arr);
	printf("%s\n", arr);
	print_ch(arr);
	return EXIT_SUCCESS;
}