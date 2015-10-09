/*************************************************************************
    > File Name: StringMatching.h
    > Author: liuxuandong
    > Develop: Ubuntu 14.04/vim 7.4/gcc 4.8.4
    > Mail: 100431075@qq.com 
    > Created Time: Wed 30 Sep 2015 10:39:55 PM CST
 ************************************************************************/
#ifndef _STRINGMATCHING_H_

#include <string.h>
#include <malloc.h>

int BruteForceMatching(const char *mStr, const char *pStr);
int KMPMatching(const char *mStr, const char *pStr);
void GetNext(const char *pStr, int *next);

void GetNext(const char *pStr, int *next)
{
	int i = 0, j = -1;

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
}

int KMPMatching(const char *mStr, const char *pStr)
{
	int i = 0, j = 0;
	int *next;

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
	int count = 0;

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

#endif

