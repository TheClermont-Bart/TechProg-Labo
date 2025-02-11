#include <stdio.h>
#include <stdlib.h>
int subSearch(int* arr,int n, int key, int start){

  if(start >= n) return -1;
  if(start > -1 && arr[start] == key){
      return start;
  }
  int a = subSearch(arr,n,key,start+2); // O(n)
  int b = subSearch(arr,n,key,start+1); // O(n)
  if(a != -1) return a;
  if(b != -1) return b;
  return -1;
}

int search(int* arr,int n, int key){
  return subSearch(arr,n,key,-2); // O(n)
}

//Main fourni à titre d'exemple
int main()
{
	int arr[] = {4,7,6,5,9,1,2}; // O(1)
    int index = search(arr,7,2); // O(n) O(n)

    printf("Index : %i",index);

	return 0;
}
//  2 * O(n) = O(2^n)
