#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>	
#include"Properties.h"

//��ȡ�ļ���Ч����
int getLines_ConfigFile(FILE* file) {
	char buf[1024] = { 0 };
	int lines = 0;
	while (fgets(buf, 1024, file) != NULL)
	{
		if (isValid_ConfigFile(buf)) {
			continue;
		}
		memset(buf, 0, 1024);
		++lines;
	}
	//���ļ�ָ�����õ��ļ��Ŀ�ͷ
	fseek(file, 0, SEEK_SET);
	return lines;
}
//���������ļ�
void loadFile_ConfigFile(const char* filePath, char** fileData, int* line) {
	FILE* file = fopen(filePath, "r");
	if (NULL == file) {
		return;
	}
	int lines = getLines_ConfigFile(file);

	char** temp = malloc(sizeof(char*) * lines);
	char buf[1024] = { 0 };
	int index = 0;
	while (fgets(buf, 1024, file) != NULL) {
		if (!isValid_ConfigFile(buf)) {
			continue;
		}
		temp[index++] = malloc(strlen(buf) + 1);
		strcpy(temp[index++], buf);
		memset(buf, 0, 1024);
	}
	*fileData = temp;
	*line = lines;
}
//���������ļ�
void parseFile_ConfigFile(char ** fileData, int lines, struct ConfigInfo** info) {
	struct ConfigInfo* myinfo = malloc(sizeof(struct ConfigInfo) * lines);
	memset(myinfo, 0, sizeof(struct ConfigInfo) * lines);
	for (int i = 0; i < lines; ++i) {
		char* pos = strchr(fileData[i], ':');
		strncpy(myinfo[i].key, fileData[i], pos - fileData[i]);
		strncpy(myinfo[i].val, pos +1 , strlen(pos+1)-1);

	}
	//�ͷ��ļ���Ϣ
	for (int i = 0; i < lines; ++i) {
		if (fileData[i] != NULL) {
			free(fileData[i]);
			fileData[i] = NULL;
		}
	}
	*info = myinfo;
}
//��ȡָ��������Ϣ
char* getInfo_ConfigFile(const char* key, struct ConfigInfo* info,int line) {
	for (int i = 0; i < line; ++i) {
		if (strcmp(key, info[i].key) == 0) {
			return info[i].val;
		}
	}
	return NULL;
}
//�ͷ������ļ���Ϣ
void destroInfo_ConfigFile(struct ConfigInfo* info) {
	if (NULL == info) {
		return;
	}
	free(info);
	info = NULL;
}
//�жϵ�ǰ���Ƿ���Ч
int isValid_ConfigFile(const char* buf) {
	if (buf[0]=="#" || buf[0]=='\n' || strchr(buf, ';') == NULL) {
		return 0;
	}
	return 1;
}
void main() {

}
