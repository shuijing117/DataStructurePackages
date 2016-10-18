/*************************************************************************
 * FileName    : DynamicSqList.c
 * Environment : Ubuntu 14.04 LTS
 *               VIM - Vi IMproved 7.4
 *               GCC 4.8.4
 * Author      : liuxuandong
 * Mail        : 1004319075@qq.com 
 * Created Time: 2016年10月17日 星期一 15时13分28秒
 * Description : 
 ************************************************************************/

#include <stdio.h>
#include <malloc.h>
#include "DynamicSqList.h"

/**
 * desc   : 初始化一个动态顺序表
 * param  : sq - 一个动态顺序表的指针
 * return : 1 - 初始化成功 0 - 初始化失败
 */
int dynamicSqList_Init(DynamicSqList *sq, int size)
{
	if ( sq ) 
	{
		sq->data = (int *)malloc(sizeof(int) * size);
		if ( ! sq->data ) 
		{
			return 0;
		}

		sq->size   = size;
		sq->length = 0;

		return 1;
	}

	return 0;
}

/**
 * desc   : 清空一个动态顺序表
 * param  : sq - 一个动态顺序表的指针
 * return : 1 - 清空成功  0 - 清空失败
 */
int dynamicSqList_Clear(DynamicSqList *sq)
{
	if ( sq ) 
	{
		sq->length = 0;

		return 1;
	}

	return 0;
}

/**
 * desc   : 获取一个动态顺序表的长度
 * param  : sq - 一个动态顺序表的指针
 * return : >=0 获取到的长度  <= 获取失败
 */
int dynamicSqList_GetLength(const DynamicSqList *sq)
{
	if ( sq ) 
	{
		return sq->length;
	}

	return -1;
}

/**
 * desc   : 根据传入的下标修改动态顺序表中的值
 * param  : sq - 一个动态顺序表的指针
 * param  : index - 要修改的元素的下标
 * param  : newData - 要修改成的数据
 * return : 1 - 修改成功  -1 - 修改失败:传入的指针为空 -2 - 修改失败:传入的index不合法
 */
int dynamicSqList_ModifyByIndex(DynamicSqList *sq, int index, int newData)
{
	if ( sq )
	{
		if (index < 0 || index >= sq->length) 
		{
			return -2;
		}

		(sq->data)[index] = newData;

		return 1;
	}

	return -1;
}

/**
 * desc   : 将动态顺序表中的一个值全部修改为另一个值
 * param  : sq - 一个动态顺序表的指针
 * param  : data - 要修改的元素
 * param  : newData - 要修改成的数据
 * return : 1 - 修改成功  -1 - 修改失败:传入的指针为空
 */
int dynamicSqList_ModifyByValue(DynamicSqList *sq, int data, int newData)
{
	if ( sq )
	{
		for (int i = 0; i < sq->length; ++i)
		{
			if ( *(sq->data + i) == data )
			{
				*(sq->data + i) = newData;
			}
		}
		
		return 1;
	}

	return -1;
}

/**
 * desc   : 根据传入的下标获取动态顺序表中的值
 * param  : sq - 一个动态顺序表的指针
 * param  : index - 要获取的数据的下标
 * param  : newData - 通过该参数将获取到的数据返回
 * return : 1 - 获取成功  -1 - 获取失败:传入的指针为空 -2 - 获取失败:传入的下标不合法
 */
int dynamicSqList_GetValue(const DynamicSqList *sq, int index, int *data)
{
	if ( sq ) 
	{
		if ( index < 0 || index >= sq->length )
		{
			return -2;
		}

		*data = *(sq->data + index);

		return 1;
	}

	return -1;
}

/**
 * desc   : 获取传入的值在动态顺序表中第一次出现的下标
 * param  : sq - 一个动态顺序表的指针
 * param  : data - 查找的数据
 * return : >=0 查找到的数据出现的下标  <0 - 查找失败
 */
int dynamicSqList_GetValueFirstIndex(const DynamicSqList *sq, int data)
{
	if ( sq )
	{
		for ( int i = 0; i < sq->length; ++i )
		{
			if ( *(sq->data + i) == data )
			{
				return i;
			}
		}
	}

	return -1;
}

/**
 * desc   : 获取传入的值在动态顺序表中最后一次出现的下标
 * param  : sq - 一个动态顺序表的指针
 * param  : data - 查找的数据
 * return : >=0 查找到的数据出现的下标  <0 - 查找失败
 */
int dynamicSqList_GetValueLastIndex(const DynamicSqList *sq, int data)
{
	if ( sq )
	{
		for ( int i = sq->length-1; i >= 0; --i) 
		{
			if ( *(sq->data + i) == data )
			{
				return i;
			}
		}
	}

	return -1;
}


/**
 * desc   : 获取传入的值在动态顺序表中出现的次数
 * param  : sq - 一个动态顺序表的指针
 * param  : data - 查找的数据
 * return : >=0 查找到的数据出现的次数  <0 - 查找失败
 */
int dynamicSqList_GetValueCount(const DynamicSqList *sq, int data)
{
	if ( sq )
	{
		int count = 0;

		for ( int i = 0; i < sq->length; ++i)
		{
			if ( *(sq->data + i) == data )
			{
				++count;
			}
		}

		return count;
	}

	return -1;
}


/**
 * desc   : 删除动态顺序表中传入的位置的值元素
 * param  : sq - 一个动态顺序表的指针
 * param  : index - 要删除的元素的下标
 * param  : data - 要删除的元素的值
 * return : 1 - 删除成功  -1 - 删除失败:传入的顺序表的指针为空 -2 - 删除失败:传入的下标不合法
 */
int dynamicSqList_DeleteByIndex(DynamicSqList *sq, int index, int *data)
{
	if ( sq )
	{
		if ( index < 0 || index >= sq->length)
		{
			return -2;
		}

		*data = *(sq->data + index);

		for (int i = index; i < sq->length-1; ++i)
		{
			*(sq->data + i) = *(sq->data + i + 1);
		}

		sq->length --;
		return 1;
	}

	return -1;
}

/**
 * desc   : 删除动态顺序表中所有值为data的元素
 * param  : sq - 一个动态顺序表的指针
 * param  : data - 要删除的元素的值
 * return : 1 - 删除成功  0 - 删除失败
 */
int dynamicSqList_DeleteByValue(DynamicSqList *sq, int data)
{
	if ( sq )
	{

		int count = 0;
		for ( int i = 0; i < sq->length; ++i)
		{
			if ( *(sq->data + i) == data)
			{
				++count;
				continue;
			}

			*(sq->data + i - count) = *(sq->data + i);
		}

		sq->length -= count;
	}

	return 0;
}

/**
 * desc   : 给动态顺序表中下标为index的位置插入一个数据
 * param  : sq - 一个动态顺序表的指针
 * param  : index - 要插入的位置
 * param  : data - 要插入的元素的值
 * return : 1 - 插入成功  -1 - 插入失败：传入的顺序表的指针为空 -2 - 插入失败：传入的下标不合法 -3 - 插入失败：顺序表的空间已满
 */
int dynamicSqList_InsertValue(DynamicSqList *sq, int index, int data)
{
	if ( sq )
	{
		if ( index < 0 || index > sq->length)
		{
			return -2;
		}

		if ( sq->length >= sq->size )
		{
			dynamicSqList_Extend(sq);
		}

		for ( int i = sq->length-1; i >= index; --i)
		{
			*(sq->data + i + 1) = *(sq->data + i);
		}

		*(sq->data + index) = data;

		sq->length ++;

		return 1;
	}

	return -1;
}

/**
 * desc   : 打印动态顺序表中的所有元素
 * param  : sq - 一个动态顺序表的指针
 */
void dynamicSqList_Print(const DynamicSqList *sq)
{
	if ( sq )
	{
		for ( int i = 0; i < sq->length; ++i)
		{
			printf("%d ", *(sq->data + i));
		}

		printf("\n");
	}
}

/**
 * desc   : 将顺序表的存储空间扩展二倍
 * param  : sq - 一个动态顺序表的指针
 * return : 1 - 扩展成功 0 - 扩展失败
 */
static int dynamicSqList_Extend(DynamicSqList *sq)
{

	if ( sq )
	{
		sq->data = (int *)realloc(sq->data, sizeof(int) * sq->size * 2);
		if ( ! sq->data )
		{
			return 0;
		}

		sq->size *= 2;

		return 1;
	}

	return 0;
}
