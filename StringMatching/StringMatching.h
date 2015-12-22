/*************************************************************************
    > File Name: StringMatching.h
    > Author: liuxuandong
    > Develop: Ubuntu 14.04/vim 7.4/gcc 4.8.4
    > Mail: 100431075@qq.com 
    > Created Time: Wed 30 Sep 2015 10:39:55 PM CST
 ************************************************************************/
#ifndef _STRINGMATCHING_H_
#define _STRINGMATCHING_H_

#include <string.h>
#include <malloc.h>

#define		TRUE	1
#define		FALSE	0

typedef	int BOOL;

int BruteForceMatching(const char *mStr, const char *pStr);
int KMPMatching(const char *mStr, const char *pStr);
static BOOL GetNext(const char *pStr, int *next);

#endif

