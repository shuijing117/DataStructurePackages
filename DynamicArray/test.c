/*************************************************************************
    > File Name: test.c
    > Author: liuxuandong
    > Mail: 100431075@qq.com 
    > Created Time: Sun 27 Sep 2015 05:02:35 PM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "DynamicArray.h"

void Print(DynamicArray array);
int compare(datatype data1, datatype data2);

int compare(datatype data1, datatype data2)
{
	return data1 == data2;
}

void Print(DynamicArray array)
{
	int i;

	for(i = 0; i < array.count; i++) {
		printf("%d:%d ", i+1, array.data[i]);
	}
	printf("\n");
}

int main(void)
{
	int i;
	int data;

	srand((int)time(NULL));

	DynamicArray array, subArray;

	InitArray(&array, 20);
	InitArray(&subArray, 20);

	for(i = 0; i < 20; i++)
		array.data[i] = rand() % 100;
	array.count = 20;

	Print(array);

	InsertArray(&array, 43, 4);
	Print(array);
	InsertArray(&array, 32, 19);
	Print(array);
	InsertArray(&array, 12, 10);
	Print(array);

	DeleteArray(&array, 3);
	Print(array);

	GetElem(array, 2, &data);
	printf("3 : %d\n", data);
	GetElem(array, 0, &data);
	printf("1 : %d\n", data);
	GetElem(array, 87, &data);
	printf("Error : %d\n", data);

	GetSubArray(array, &subArray, 0, 5);
	Print(subArray);

	GetRandomElem(array, &data);
	printf("%d\n", data);

	CombineArray(&array, subArray);
	Print(array);

	scanf("%d", &data);
	printf("%d\n", Find(array, data, compare));

	DestoryArray(&subArray);
	DestoryArray(&array);

	return 0;
}


