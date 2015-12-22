/*************************************************************************
    > File Name: StringMatching/StringMatching.c
    > Author: liuxuandong
    > Develop: Ubuntu 14.04/vim 7.4/gcc 4.8.4
    > Mail: 100431075@qq.com 
    > Created Time: Tue 22 Dec 2015 10:18:03 AM CST
 ************************************************************************/

#include "StringMatching.h"

static BOOL GetNext(const char *pStr, int *next)
{
	int i = 0, j = -1;

	if(pStr == NULL || next == NULL) {
		return FALSE;
	}

	next[0] = -1;

	while(i < strlen(pStr)) {
		if(j == -1 || pStr[i] == pStr[j]) {
			i++;
			j++;
			next[i] = j;
		} else {
			j = next[j];
		}
	}

	printf("next[]:  ");
	for(i = 0; i < strlen(pStr); i++)
		printf("%d ", next[i]);
	printf("\n");

	return TRUE;
}

int KMPMatching(const char *mStr, const char *pStr)
{
	int i = 0, j = 0;
	int *next;

	if(mStr == NULL) {
		return -1;
	}

	next = (int *)malloc(sizeof(int) * (strlen(pStr)+1));
	if(next == NULL) {
		return -1;
	}

	GetNext(pStr, next);

	while(i < strlen(mStr) && j < strlen(pStr)) {
		if(mStr[i] == pStr[j]) {
			i++;
			j++;
		} else {
			j = next[j];
			if(j == -1) {
				j = 0;
				i++;
			}
		}
	}

	free(next);

	if(j == strlen(pStr)) {
		return i-strlen(pStr);
	} else {
		return -1;
	}
}

int BruteForceMatching(const char *mStr, const char *pStr)
{
	int i, j;
	int mStrLen = strlen(mStr);
	int pStrLen = strlen(pStr);
//	int count = 0;

	for(i = 0; i < mStrLen; i++) {
		for(j = 0; j < pStrLen; j++) {
			if(i+j > mStrLen) {
				return -1;
			}

			if(mStr[i+j] != pStr[j]) {
				break;
			}

			if(j+1 == pStrLen) {
				return i;
			}
		}
	}
	return -1;
}