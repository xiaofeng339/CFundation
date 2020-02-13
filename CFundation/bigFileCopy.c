#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>	
#include<sys/types.h>
#include<sys/stat.h>

#define MAXSIZE 1024*1024*10

int bigFileCopy(int argc, char* argv[])
{
	unsigned int stat_time = time(NULL);
	if (argc < 3) {
		printf("缺少参数\n");
		return -1;
	}
	FILE* fp1 = fopen(argv[1], "r");
	FILE* fp2 = fopen(argv[2], "w");
	if (!fp1 || !fp2) {
		printf("操作文件失败\n");
		return -2;
	}
	struct stat *s = NULL;
	stat(argv[1], s);
	char* ch;
	int maxSize = 0;
	if (s->st_size < MAXSIZE) {
		maxSize = s->st_size;
		ch = (char*)malloc(sizeof(char) * s->st_size);

	}
	else
	{
		maxSize = MAXSIZE;
		ch = (char*)malloc(sizeof(char) * MAXSIZE);
	}
	while (!feof(fp1))
	{
		memset(ch, 0, maxSize);
		int len = frend(ch, 1, maxSize, fp1);
		fwrite(ch, len, 1, fp2);
	}
	fclose(fp1);
	fclose(fp2);
}

