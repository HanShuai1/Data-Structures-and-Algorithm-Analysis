#include <stdio.h>
#include <stdlib.h>
#define Cutoff (10)
int Median3(int A[], int Left, int Right);
void Qsort(int A[], int Left, int Right);
void InsertionSort( int A[], int N );
void Swap(int *x,int *y);
// This is a very sophisticated quick sort implementation.
//这是一个非常精巧的快速排序实现。
int main()
{

	int A[23] = {3,4,3,5,6,7,8,34,34,21,432,234,231,11,111,123,13,56,45,34,13,56,45,34,24,12,134,12324,12,134,123,45,74,35,12,12};
	printf("before ordering \n");
	for(int i = 0; i<23; i++)
	printf("%d\t", A[i] );
    Qsort( A, 0, 22);
    printf("\n After ordering\n");
	for(int i = 0; i<23; i++)
	printf("%d\t", A[i] );
    system("pause");
    return 0;
}

/**
  * Return median of left, center, and right.
  * 返回left、 center 和 right 三项的中值
  * Order these and hide the pivot. 
  * 将它们排序并隐匿枢纽元
  */
int Median3( int A[], int Left, int Right)
{
	int Center = (Left + Right ) / 2;

	if( A[ Left ] > A[ Center ] )
		Swap( &A[ Left ], &A[ Center ] );
	if( A[ Left ] > A[ Right ] )
		Swap( &A[ Left ], &A[ Right ]);
	if( A[ Center ] > A[ Right ])
		Swap( &A[ Center ], &A[Right]);
	// Place pivot at position right - 1
        // 将枢纽元置于 right - 1 处
	Swap( &A[ Center ], &A[ Right - 1] );
	return A[ Right - 1 ];
}
/**
  * Internal quicksort method that makes recursive calls.
  * 进行递归调用的内部快速排序方法。
  * Uses median-of-three partitioning and a cutoff of 10.
  * 使用三数中值分割法，以及截止范围是10的截止技术。
  * A is an array of comparable items.
  * A 是要排序的可比较数组
  * Left is the left-most index of the subarray.
  * Left 是子数组最左元素的下标。
  * Right is the right-most index of the subarray.
  * Right 是子数组最右元素的下标。
  */

void Qsort(int A[], int Left, int Right)
{
	int i,j;
	int Pivot;

	if( Left + Cutoff <= Right)
	{
		Pivot = Median3(A, Left, Right);
		i = Left; j = Right - 1;
		for(; ;)
		{
			while( A[++i] < Pivot){}
			while( A[--j] > Pivot){}
			if( i < j )
				Swap( &A[ i ], &A[ j ]);
			else
				break;
		}
		Swap( &A[ i ], &A[ Right - 1 ] ); //Restore pivot.(恢复枢纽元)

		Qsort(A, Left, i - 1); // Sort small elements
		Qsort(A, i + 1, Right); // Sort large elements

	}
	else     // Do an insertion sort on the subarray.(对子数组进行以此插入排序。)
		InsertionSort( A + Left, Right - Left + 1 );
}
void InsertionSort(int A[] , int N )
{
	int j, P;
	int Tmp;
	for( P = 1; P < N; P++)
	{
		Tmp = A[ P ];
		for( j = P; j > 0 && A[ j-1 ] > Tmp; j--)
		{
			Tmp = A[ P ];
			for( j = P; j > 0 && A[ j - 1 ] > Tmp; j-- )
				A[ j ] = A[ j - 1 ];
			A[ j ] = Tmp;
		}
	}

}
 void Swap(int *x,int *y)
 {
 	int temp;
    temp=*x;
    *x=*y;
    *y=temp;
 }
