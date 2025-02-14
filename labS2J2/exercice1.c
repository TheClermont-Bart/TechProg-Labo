#include<stdio.h>
#define RANGE 10 // O(1)

int max (int a[], int n){
   int max = a[0];
   for (int i = 1; i < n; i++) // O(n)
      if (a[i] > max)
         max = a[i];
   return max;
}// O(n)

void sort (int a[], int n){
   int bucket[RANGE][RANGE], bucket_count[RANGE]; // 0(1)
   int i, j, k, r, NUM_DIGIT = 0; 
   int dividor = 1; // O(1)
   int msd = max (a, n); // O(n)
   while (msd > 0){ // O(logn) -> msd/10
      NUM_DIGIT++;
      msd /= 10;
   }
   for (int d_count = 0; d_count < NUM_DIGIT; d_count++){ // O(1)
      for (i = 0; i < RANGE; i++){ // O(1)
         bucket_count[i] = 0;
      }
      for (i = 0; i < n; i++){ // O(n)
         r = (a[i] / dividor) % RANGE;
         bucket[r][bucket_count[r]] = a[i];
         bucket_count[r] += 1;
      }
      i = 0;
      for (k = 0; k < RANGE; k++){ // O(1)
         for (j = 0; j < bucket_count[k]; j++){ // O(1)
            a[i] = bucket[k][j];
            i++;
         }
      }
      dividor *= RANGE;
   }
}
int main (){
   int i, n;
   int arr[] = { 12, 11, 13, 5, 6, 7 };

   sort (arr, n);
   return 0;
} // O(nlogn)