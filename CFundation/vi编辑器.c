#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>	


int viEditor() {
	char fileName[256];
	printf("请您输入一个需要创建的文件：\n");
	scanf("%s", fileName);
	getchar();
	FILE* fp = fopen(fileName, "w");
	if (fp == NULL)
		return -1;			
	
	char buf[1024];
	while (1) {
		memset(buf, 0, 1024);
		//scanf("%[^\n]", buf);
		fgets(buf, 1024, stdin);
		if (!strncmp("comm=exit", buf, 9)) 
			break;
		
		int i = 0;
		while (buf[i] != '\0') {
			fputc(buf[i++ ], fp);
		}
		fflush(fp);
	}
	
	fclose(fp);
	system("pause");
	return EXIT_SUCCESS;
}