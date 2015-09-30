/*************************************************************************
    > File Name: StringMatching.h
    > Author: liuxuandong
    > Develop: Ubuntu 14.04/vim 7.4/gcc 4.8.4
    > Mail: 100431075@qq.com 
    > Created Time: Wed 30 Sep 2015 10:39:55 PM CST
 ************************************************************************/
#ifndef _STRINGMATCHING_H_

#include <string.h>

int SimpleMatching(const char * mStr, const char * pStr);

int SimpleMatching(const char * mStr, const char * pStr)
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

