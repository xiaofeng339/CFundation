#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>	


int catEditor() {
	char fileName[256];
	printf("���������鿴���ļ���\n");
	scanf("%s", fileName);
	getchar();
	FILE* fp = fopen(fileName, "w");
	if (fp == NULL)
		return -1;

	char ch;
	while((ch=fgetc(fp))!=EOF) {
		
		printf("%c", ch);
	}

	fclose(fp);
	system("pause");
	return EXIT_SUCCESS;
}