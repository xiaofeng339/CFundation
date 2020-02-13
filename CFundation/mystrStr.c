#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>	

char* mystrStr(const char* str, const char* substr) {
	const char* mystr = str;
	const char* mysub = substr;
	while (*mystr != '\0') {
		if (*mystr != *mysub) {
			++mystr;
			continue;
		}
		//¡Ÿ ±±‰¡ø
		char* temp_mystr = mystr;
		char* temp_mysub = mysub;
		while (*temp_mysub != '\0') {
			if (*temp_mystr != *temp_mysub) {
				++mystr;
				break;
			}
			++temp_mystr;
			++temp_mysub;
		}
		if (*temp_mysub == '\0') {
			return (char*)mystr;
		}
		
	}
	return NULL;
}

