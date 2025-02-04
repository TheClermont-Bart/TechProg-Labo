#include <stdio.h>


void sort(int arr[], int n)
{
    int i;
    int y;
    int id_minimum;

    for (i = 0; i < n-1; ++i)
    {
        id_minimum = i;
        for (y = i+1; y < n; ++y){
            if (arr[y] < arr[id_minimum])
                id_minimum = y;
        }

        int temp = arr[id_minimum];
        arr[id_minimum] = arr[i];
        arr[i] = temp;  
    }
}

int main()
{
	int arr[] = {128, 42, 16, 40, 198};
	int n = sizeof(arr)/sizeof(arr[0]);
	sort(arr, n);
	printf("Sorted array is: ");
    int i = 0;
    for(; i < n-1; ++i ){
        printf(" %i,",arr[i]);
    }
    printf(" %i\n",arr[i]);
	return 0;
}