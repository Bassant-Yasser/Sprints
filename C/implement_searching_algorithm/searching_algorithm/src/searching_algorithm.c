#include <stdio.h>
#include <stdlib.h>

typedef unsigned char   uint8_t;
typedef char   int8_t;
typedef unsigned int   uint32_t;

int8_t binarySearch(uint32_t *arr, uint32_t number, uint32_t left, uint32_t right);

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main(void) {
	unsigned int arr[5] = {2, 5, 15, 1, 20};
	qsort(arr, 5, sizeof(int), cmpfunc);

	printf("Array after sorting: \n");
	for(int i = 0; i < 5; i++)
	{
		printf("%d  ", arr[i]);
	}
	int number = binarySearch(arr, 19, 0, 4);
	printf("\nThe element 1 is at index %d", number);
}

int8_t binarySearch(uint32_t *arr, uint32_t number, uint32_t left, uint32_t right)
{
	if(left > right)
	{
		return -1;
	}
	if (left == right)
	{
		if (number == arr[left]) return left;
		else return -1;
	}

	int mid = (left+right)/2;

	if (number == arr[mid]) return mid;

	if (number < arr[mid])
		return binarySearch (arr, number, left, mid-1);
	if (number > arr[mid])
		return binarySearch(arr, number, mid+1, right);
}

