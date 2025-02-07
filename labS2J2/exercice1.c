#include<stdio.h>
#define RANGE 10

int max (int a[], int n){
   int max = a[0];
   for (int i = 1; i < n; i++)
      if (a[i] > max)
         max = a[i];
   return max;
}

void sort (int a[], int n){
   int bucket[RANGE][RANGE], bucket_count[RANGE];
   int i, j, k, r, NUM_DIGIT = 0;
   int dividor = 1;
   int msd = max (a, n);
   while (msd > 0){
      NUM_DIGIT++;
      msd /= 10;
   }
   for (int d_count = 0; d_count < NUM_DIGIT; d_count++){
      for (i = 0; i < RANGE; i++){
         bucket_count[i] = 0;
      }
      for (i = 0; i < n; i++){
         r = (a[i] / dividor) % RANGE;
         bucket[r][bucket_count[r]] = a[i];
         bucket_count[r] += 1;
      }
      i = 0;
      for (k = 0; k < RANGE; k++){
         for (j = 0; j < bucket_count[k]; j++){
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
}