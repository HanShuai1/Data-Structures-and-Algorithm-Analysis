#include <stdio.h>
#include <stdlib.h>
#define Cutoff (3)
int Median3(int A[], int Left, int Right);
void Qsort(int A[], int Left, int Right);
void InsertionSort( int A[], int N );
void Swap(int *x,int *y);

int main()
{

	int A[23] = {3,4,3,5,6,7,8,34,34,21,13,56,45,34,24,12,134,123,45,74,35,12,12};
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

int Median3( int A[], int Left, int Right)
{
	int Center = (Left + Right ) / 2;

	if( A[ Left ] > A[ Center ] )
		Swap( &A[ Left ], &A[ Center ] );
	if( A[ Left ] > A[ Right ] )
		Swap( &A[ Left ], &A[ Right ]);
	if( A[ Center ] > A[ Right ])
		Swap( &A[ Center ], &A[Right]);
    
	Swap( &A[ Center ], &A[ Right - 1] );
	return A[ Right - 1 ];
}

//#define Cutoff ( 3 )

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
		Swap( &A[ i ], &A[ Right - 1 ] );

		Qsort(A, Left, i - 1);
		Qsort(A, i + 1, Right);

	}
	else
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