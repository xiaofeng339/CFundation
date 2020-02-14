//防止头文件重复包含
#pragma once
#include<stdio.h>

struct ConfigInfo
{
	char key[64];
	char val[128];

	};

//目的为了C++中能够调用C写的函数
#ifdef _cplusplus
extern "C" {
#endif
	//获取文件有效行数
	int getLines_ConfigFile(FILE* file);
	//加载配置文件
	void loadFile_ConfigFile(const char* filePath, char** fileData, int* line);
	//解析配置文件
	void parseFile_ConfigFile(char** fileData, int lines, struct ConfigInfo** info);
	//获取指定配置信息
	char * getInfo_ConfigFile(const char* key, struct ConfigInfo* info,int line);
	//释放配置文件信息
	void destroInfo_ConfigFile(struct ConfigInfo* info);
	//判断当前行是否有效
	int isValid_ConfigFile(const char* buf);
#ifdef _cplusplus
	}
#endif // _cplusplus
