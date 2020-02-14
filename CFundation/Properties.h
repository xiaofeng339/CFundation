//��ֹͷ�ļ��ظ�����
#pragma once
#include<stdio.h>

struct ConfigInfo
{
	char key[64];
	char val[128];

	};

//Ŀ��Ϊ��C++���ܹ�����Cд�ĺ���
#ifdef _cplusplus
extern "C" {
#endif
	//��ȡ�ļ���Ч����
	int getLines_ConfigFile(FILE* file);
	//���������ļ�
	void loadFile_ConfigFile(const char* filePath, char** fileData, int* line);
	//���������ļ�
	void parseFile_ConfigFile(char** fileData, int lines, struct ConfigInfo** info);
	//��ȡָ��������Ϣ
	char * getInfo_ConfigFile(const char* key, struct ConfigInfo* info,int line);
	//�ͷ������ļ���Ϣ
	void destroInfo_ConfigFile(struct ConfigInfo* info);
	//�жϵ�ǰ���Ƿ���Ч
	int isValid_ConfigFile(const char* buf);
#ifdef _cplusplus
	}
#endif // _cplusplus
