void insertionSort(int elements[], int n) {
	for (int i = 1; i < n ; i++) {
		int temp = elements[i];
		int j = i - 1;

		while ((temp < elements[j]) && (j >= 0)) {
			elements[j + 1] = elements[j];
			j = j - 1;
		}
		elements[j + 1] = temp;
	}
}


void quickSort(int* elements, int left, int right);