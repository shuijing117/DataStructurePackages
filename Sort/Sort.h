/*************************************************************************
    > File Name: Sort.h
    > Author: liuxuandong
    > Develop: Ubuntu 14.04/vim 7.4/gcc 4.8.4
    > Mail: 100431075@qq.com 
    > Created Time: Sat 10 Oct 2015 07:53:16 PM CST
 ************************************************************************/
#ifndef _SORT_H_

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define		TRUE			1
#define		FALSE			0
	
#define		LAPSE_RATE		1.3

typedef int BOOL;
typedef int datatype;

typedef struct Node {
	datatype data;
	struct Node *next;
}Node;

void Swap(datatype *a, datatype *b);

static BOOL HeapAdjust(datatype *array, int size, int s);
static BOOL GetMax(datatype *array, int size, int *max);
static BOOL GetMin(datatype *array, int size, int *min);
static int GetBit(const int number);

BOOL InsertionSort(datatype *array, int size);
BOOL BinaryInsertionSort(datatype *array, int size);
BOOL ShellSort(datatype *array, int size);
BOOL SelectionSort(datatype *array, int size);
BOOL BubbleSort(datatype *array, int size);
BOOL QuickSort(datatype *array, int low, int high);
BOOL MergeSort(datatype *array, int low, int high);
BOOL HeapSort(datatype *array, int size);
BOOL HighOrderRadixSort(datatype *array, int size);
BOOL LowOrderRadixSort(datatype *array, int size);
BOOL BucketSort(datatype *array, int size, int numberLimits);
BOOL PigeonholeSort(datatype *array, int size);
BOOL CocktailSort(datatype *array, int size);
BOOL GnomeSort(datatype *array, int size);
BOOL OddEvenSort(datatype *array, int size);
BOOL PatienceSort(datatype *array, int size);
BOOL BeadSort(datatype *array, int size);
BOOL CombSort(datatype *array, int size);
BOOL BogoSort(datatype *array, int size);

BOOL BogoSort(datatype *array, int size)
{
	int i, j;
	int tag;

	if(array == NULL) {
		return FALSE;
	}

	srand((unsigned int)time(NULL));

	while(TRUE) {
		tag = TRUE;
		for(i = 1; i < size; i++) {
			if(array[i] < array[i-1]) {
				tag = FALSE;
				break;
			}
		}

		if(tag) {
			break;
		}

		for(i = 0; i < size; i++) {
			j = rand() % size;
			Swap(array + i, array + j);
		}
	}

	return TRUE;
}

BOOL CombSort(datatype *array, int size)
{
	int i, j;
	int increment;

	if(array == NULL ) {
		return FALSE;
	}

	increment = size;

	while(TRUE) {
		increment = (int)(increment / LAPSE_RATE);
		for(i = 0; i < increment; i++) {
			for(j = i+increment; j < size; j += increment) {
				if(array[j] < array[j-increment]) {
					Swap(array+j, array+j-increment);
				}
			}
		}

		if(increment <= 1) {
			break;
		}
	}	

	return TRUE;
}

BOOL BeadSort(datatype *array, int size)
{
	char **bead;
	int i, j, k, n, len;

	if(array == NULL) {
		return FALSE;
	}

	GetMax(array, size, &len);

	bead = (char **)calloc(size, sizeof(char *));
	if(bead == NULL) {
		return FALSE;
	}

	for(i = 0; i < size; i++) {
		bead[i] = (char *)calloc(len, sizeof(char));
		if(bead[i] == NULL) {
			return FALSE;
		}
	}

	for(i = 0; i < size; i++) { 
		for(j = 0; j < array[i]; j++) {
			bead[i][j] = 1;
		}
	}

//	for(i = 0; i < size; i++) {
//		for(j = 0; j < len; j++) {
//			printf("%d ", bead[i][j]);
//		}
//		printf("\n");
//	}

	for(j = 0; j < len; j++) {
		i = k = size-1;
		while(i >= 0) {
			if(bead[i--][j] == 1) {
				bead[k--][j] = 1;
			}
		}

		while(k >= 0) {
			bead[k--][j] = 0;
		}
	}
	
//	printf("\n\n"); 
//	
//	for(i = 0; i < size; i++) { 
//		for(j = 0; j < len; j++) {
//			printf("%d ", bead[i][j]);
//		}
//		printf("\n");
//	}

	for(i = 0; i < size; i++) {
		j = n = 0;
		while(j < len) {
			if(bead[i][j++] == 0) {
				break;
			}
			n++;
		}

		array[i] = n;
	}

	return TRUE;
}

BOOL PatienceSort(datatype *array, int size)
{
	int i, j;
	Node **bucket;
	Node *p;

	if(array == NULL) {
		return FALSE;
	}

	bucket = (Node **)calloc(size, sizeof(Node *));
	if(bucket == NULL) {
		return FALSE;
	}

	for(i = 0; i < size; i++) {
		j = 0;
		while(bucket[j] != NULL && (bucket[j])->data < array[i])
			j++;

		p = (Node *)malloc(sizeof(Node));
		if(p == NULL) {
			return FALSE;
		}
		p->data = array[i];

		if(bucket[j] != NULL) {
			p->next = bucket[j];
		} else {
			p->next = NULL;
		}

		bucket[j] = p;
	}

//	printf("\n");
//
//	i = j = 0;
//	while(bucket[j] != NULL) {
//		p = bucket[j++];
//		while(p != NULL) {
//			printf("%d ", p->data);
//			p = p->next;
//		}
//		printf("\n");
//	}
//
//	printf("\n");


	i = j = 0;
	while(bucket[j] != NULL) {
		p = bucket[j];
		while(p != NULL) {
			array[i++] = p->data;
			p = p->next;
		}
		j++;
	}

//	for(i = 0; i < size; i++)
//		printf("%d ", array[i]);
//	printf("\n");

	InsertionSort(array, size);

	return TRUE;
}

BOOL OddEvenSort(datatype *array, int size)
{
	int i;
	int tag;

	if(array == NULL) {
		return FALSE;
	}

	while(tag) {
		tag = FALSE;

		for(i = 1; i < size-1; i += 2) {
			if(array[i] > array[i+1]) {
				Swap(array+i, array+i+1);
				tag = TRUE;
			}
		}

		for(i = 0; i < size-1; i += 2) {
			if(array[i] > array[i+1]) {
				Swap(array+i, array+i+1);
				tag = TRUE;
			}
		}
	}


	return TRUE;
}

BOOL GnomeSort(datatype *array, int size)
{
	int i = 0;

	if(array == NULL) {
		return FALSE;
	}

	while(i < size) {
		if(i == 0 || array[i-1] <= array[i]) {
			i++;
		} else {
			Swap(array + i-1, array + i);
			i--;
		}
	}

	return TRUE;
}

BOOL CocktailSort(datatype *array, int size)
{
	int i, j;
	int tag;

	if(array == NULL) {
		return FALSE;
	}

	for(i = 0; i <= size / 2; i++) {
		tag = TRUE;

		for(j = i; j < size-i-1; j++) {
			if(array[j] > array[j+1]) {
				Swap(array+j, array+j+1);
				tag = FALSE;
			}
		}

		if(tag) {
			return TRUE;
		}

		for(j = j-1; j > i; j--) {
			if(array[j] < array[j-1]) {
				Swap(array+j, array+j-1);
				tag = FALSE;
			}
		}

		if(tag) {
			return TRUE;
		}
	}

	return TRUE;
}

static int GetBit(const int number)
{
	int n = number;
	int bit = 0;

	while(n > 0) {
		n /= 10;
	}

	return bit;
}

static BOOL GetMin(datatype *array, const int size, int *min)
{
	int i;

	if(array == NULL) {
		return FALSE;
	}

	*min = array[0];
	for(i = 1; i < size; i++) {
		if(array[i] < *min) {
			*min = array[i];
		}
	}

	return TRUE;
}

static BOOL GetMax(datatype *array, const int size, int *max)
{
	int i;

	if(array == NULL) {
		return FALSE;
	}

	*max = array[0];
	for(i = 1; i < size; i++) {
		if(array[i] > *max) {
			*max = array[i];
		}
	}

	return TRUE;
}

BOOL PigeonholeSort(datatype *array, const int size)
{
	int i, j, max, min;
	int *pigeonhole = NULL;

	if(array == NULL) {
		return FALSE;
	}

	GetMax(array, size, &max);
	GetMin(array, size, &min);
	
	pigeonhole = (int *)calloc(max-min+1, sizeof(int));
	if(pigeonhole == NULL) {
		return FALSE;
	}

	for(i = 0; i < size; i++) {
		pigeonhole[array[i]-min]++;
	}

	for(i = 0, j = 0; i <= max-min; i++) {
		while(pigeonhole[i] > 0) {
			array[j++] = i+min;
			pigeonhole[i]--;
		}
	}

	return TRUE;
}

BOOL BucketSort(datatype *array, const int size, const int numberLimits)
{
	int i, j;
	Node **temp;
	Node *p, *s;

	if(array == NULL) {
		return FALSE;
	}

	temp = (Node **)calloc(numberLimits / 10 + 1, sizeof(Node *));
	if(temp == NULL) {
		return FALSE;
	}


	for(i = 0; i < size; i++) {
		p = temp[array[i] / 10];

		s = (Node *)malloc(sizeof(Node));
		if(s == NULL) {
			return FALSE;
		}
		s->data = array[i];
		s->next = NULL;

		if(p == NULL)
		{
			temp[array[i] / 10] = s;
		} else {
			if(p->data > s->data) {
				s->next = p;
				temp[array[i] / 10] = s;
			} else {
				while(p->next != NULL && p->next->data < s->data)
					p = p->next;

				s->next = p->next;
				p->next = s;
			}
		}
		
	}

	for(i = 0, j = 0; i < numberLimits / 10 + 1; i++) {
		p = temp[i];
		while(p) {
			array[j++] = p->data;
			p = p->next;
		}
	}

	return TRUE;
}

BOOL LowOrderRadixSort(datatype *array, const int size)
{
	return TRUE;
}

BOOL HighOrderRadixSort(datatype *array, const int size)
{
	return FALSE;
}

static BOOL HeapAdjust(datatype *array, const int size, int s)
{
	int i, temp;

	if(array == NULL) {
		return FALSE;
	}

	temp = array[s];
	for(i = 2*s+1; i < size; i = 2*i+1) {
		if(i < size-1 && array[i] < array[i+1]) {
			++i;
		}

		if(temp >= array[i])
			break;

		array[s] = array[i];
		s = i;
	}
	array[s] = temp;

	return TRUE;
}

BOOL HeapSort(datatype *array, const int size)
{
	int i;

	if(array == NULL) {
		return FALSE;
	}

	for(i = size/2; i > 0; i--) {
		HeapAdjust(array, size, i-1);
	}

	for(i = size-1; i > 0; i--) {
		Swap(array+i, array);
		HeapAdjust(array, i, 0);
	}

	return TRUE;
}

BOOL MergeSort(datatype *array, const int low, const int high)
{
	int i, j, k;
	int mid;
	int *temp;

	if(array == NULL) {
		return FALSE;
	}

	if(low >= high) {
		return FALSE;
	}

	temp = (int *)malloc(sizeof(int)*(high-low+1));
	if(temp == NULL) {
		return FALSE;
	}

	mid = (low + high) / 2;

	MergeSort(array, low, mid);
	MergeSort(array, mid+1, high);

	i = low;
	j = mid+1;
	k = 0;
	while(i <= mid && j <=high) {
		if(array[i] < array[j]) {
			temp[k++] = array[i++];
		} else {
			temp[k++] = array[j++];
		}
	}

	while(i <= mid) {
		temp[k++] = array[i++];
	}

	while(j <= high) {
		temp[k++] = array[j++];
	}

	for(i = 0; i <= high-low; i++) {
		array[low+i] = temp[i];
	}

	return TRUE;
}

BOOL QuickSort(datatype *array, const int low, int high)
{
	int i = low;
	int j = high;
	int temp;
	
	if(array == NULL) {
		return FALSE;
	}

	if(low >= high) {
		return FALSE;
	}

	temp = array[low];

	while(i != j) {
		for( ; j > i && array[j] > temp; j--) 
			;

		if(j > i) {
			array[i] = array[j];
			i++;
		}

		for( ; i < j && temp > array[i]; i++) 
			;
		
		if(i < j) {
			array[j] = array[i];
			j--;
		}
	}

	array[i] = temp;
	QuickSort(array, low, i-1);
	QuickSort(array, i+1, high);

	return TRUE;
}

BOOL BubbleSort(datatype *array, const int size)
{
	int i, j;
	int tag;

	if(array == NULL) {
		return FALSE;
	}

	for(i = 0; i < size; i++) {
		tag = TRUE;

		for(j = 0; j < size-i-1; j++) {
			if(array[j] > array[j+1]) {
				Swap(array+j, array+j+1);
				tag = FALSE;
			}
		}

		if(tag) {
			break;
		}
	}

	return TRUE;
}

BOOL SelectionSort(datatype *array, const int size)
{
	int i, j, k;

	if(array == NULL) {
		return FALSE;
	}

	for(i = 0; i < size; i++) {
		k = i;
		for(j = i+1; j < size; j++) {
			if(array[k] > array[j]) {
				k = j;
			}
		}
		Swap(array+i, array+k);
	}

	return TRUE;
}

BOOL ShellSort(datatype *array, int size)
{
	int i, j, temp;
	int increment = size;

	if(array == NULL) {
		return FALSE;
	}

	while(increment > 1) {
		increment = increment / 3 + 1;
		for(i = increment; i < size; i++) {
				temp = array[i];
				for(j = i-increment; j >= 0; j -= increment) {
					if(temp >= array[j]) {
						break;
					}
					array[j+increment] = array[j];
				}
				array[j+increment] = temp;
		}
	}

	return TRUE;
}

BOOL BinaryInsertionSort(datatype *array, int size)
{
	int i, j, low, high, mid;
	int temp;

	if(array == NULL) {
		return TRUE;
	}

	for(i = 1; i < size; i++) {
		low = 0;
		high = i-1;
		temp = array[i];

		while(low <= high) {
			mid = (low + high) / 2;
			if(array[mid] > temp) {
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}

		for(j = i; j > low; j--) {
			array[j] = array[j-1];
		}
		array[low] = temp;
	}

	return TRUE;
}

BOOL InsertionSort(datatype *array, int size)
{
	int i, j;
	int temp;

	if(array == NULL) {
		return FALSE;
	}

	for(i = 1; i < size; i++) {
		temp = array[i];
		for(j = i-1; j >= 0; j--) {
			if(temp >= array[j]) {
				break;
			} 
			array[j+1] = array[j];
		}
		array[j+1] = temp;
	}

	return TRUE;
}

void Swap(datatype *a, datatype *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

#endif
