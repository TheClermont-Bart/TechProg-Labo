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

void quickSort(int* elements, int left, int right)
{
	if (left >= right) {
		return ;
	}

	int pivot = elements[left];
	int i = left + 1;
	int j = right;
	int temp;

	while (i <= j) {
		while (i <= right && elements[i] <= pivot) {
			i++;
		}
		while (elements[j] > pivot) {
			j--;
		}
		if (i < j) {
			temp = elements[i];
			elements[i] = elements[j];
			elements[j] = temp;
			i++;
			j--;
		}
	}
	temp = elements[left];
	elements[left] = elements[j];
	elements[j] = temp;

	quickSort(elements, left, j - 1);
	quickSort(elements, j + 1, right);
}



/*
int compare(int a, int b) {
	int x = a;
	int y = b;
	return x - y;
}
void quickSort(int* elements, int left, int right)
{
	int x = elements[left];
	int y = elements[left + 1];

	qsort(elements, 8, sizeof(int), compare(x,y));

}*/