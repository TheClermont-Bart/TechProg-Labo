#include "labo.h"

void insertionSort(int elements[], int n){
for (int i = 1; i < n; i++) {
	int temp = elements[i];
	int j = i - 1;

	while ((temp < elements[j]) && (j >= 0)) {
		elements[j + 1] = elements[j];
		j = j - 1;
	}
	elements[j + 1] = temp;
}
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void quickSort(int* elements, int left, int right) //Ca aurait ete le fun avoir un print du tableau dans le resultat question de voir nos manipulation .... 
{
	if (left >= right) {
		return ;
	}

	int pivot = elements[left]; //Premier elements du tableau
	int i = left + 1; 
	int j = right;
	int temp;

	while (i <= j) 
	{
		while (i <= right && elements[i] <= pivot) // O(n)
		{
			i++;
		}

		while (elements[j] > pivot) // O(n)
		{ 
			j--;
		}

		if (i < j) // O(1)
		{
			swap(&elements[i], &elements[j]);
			i++;
			j--;
		}
	}
	swap(&elements[left], &elements[j]);

	quickSort(elements, left, j - 1); //Recursion
	quickSort(elements, j + 1, right); // Recursion
}

// O(nlogn)



/*void quickSort(int* elements, int left, int right)
{
	quickSort_Recursion(elements,left,right-1);
}

int quickSort_Recursion(int* elements, int left, int right) 
{
	if (left < right) 
	{
		int pivot = partition(elements, left, right);
		quickSort_Recursion(elements, left, pivot - 1);
		quickSort_Recursion(elements, pivot + 1, right);
	}
}

int partition(int* elements, int left, int right) 
{
	int pivot = elements[right-1]; // Dernier elements du tableau
	int i = left;
	
	for (int j = left; j < right; j++) 
	{
		if (elements[j] <= pivot) 
		{
			swap(&elements[i], &elements[j]);
			i++;
		}
	}
	swap(&elements[i], &elements[right]);
	return i;
}*/