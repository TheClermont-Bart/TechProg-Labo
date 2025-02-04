#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


/* This code is public domain -- Will Hartung 4/9/09 */
static size_t getline(char** lineptr, size_t* n, FILE* stream) {
	char* bufptr = NULL;
	char* p = bufptr;
	size_t size;
	int c;

	if (lineptr == NULL) {
		return -1;
	}
	if (stream == NULL) {
		return -1;
	}
	if (n == NULL) {
		return -1;
	}
	bufptr = *lineptr;
	size = *n;

	c = fgetc(stream);
	if (c == EOF) {
		return -1;
	}
	if (bufptr == NULL) {
		bufptr = malloc(128);
		if (bufptr == NULL) {
			return -1;
		}
		size = 128;
	}
	p = bufptr;
	while (c != EOF) {
		if ((p - bufptr) > (size - 1)) {
			size = size + 128;
			bufptr = realloc(bufptr, size);
			if (bufptr == NULL) {
				return -1;
			}
		}
		*p++ = c;
		if (c == '\n') {
			break;
		}
		c = fgetc(stream);
	}

	*p++ = '\0';
	*lineptr = bufptr;
	*n = size;

	return p - bufptr - 1;
}

void test_code(FILE* f) {
	char* ligne = NULL;
	size_t len = 0;
	size_t read;
	int ligneCount = 0;

	static char lastLine[1024] = { 0 };
	static int numbers[256] = { 0 };
	static size_t num_len = 0;
	while ((read = getline(&ligne, &len, f)) != -1) {
		if (ligneCount <= 1) {
			static int sorted_nums[256] = { 0 };
			char text[512] = { 0 };
			int i = 0;
			char chr = ligne[i];
			while (i < read) {
				while (chr != ',' && chr != '\0') {
					text[strlen(text)] = chr;
					++i;
					chr = ligne[i];
				}
				if (ligneCount == 0)
					numbers[num_len] = atoi(text);
				else
					sorted_nums[num_len] = atoi(text);
				memset(text, 0, len);
				num_len++;
				chr = ligne[++i];
			}
			if (ligneCount == 1) {
				static int isGood = 1;
				insertionSort(numbers, num_len);
				for (int i = 0; i < num_len; ++i) {
					if (numbers[i] != sorted_nums[i]) {
						isGood = 0;
						break;
					}
				}
				if (isGood) {
					printf("Tu as bien programmer: insertionSort !\n");
				}
				else {
					printf("Tu as un erreur dans: insertionSort !\n");
				}
				memset(numbers, 0,sizeof(int) * num_len);
				num_len = 0;
			}
			else {
				num_len = 0;
			}
		}
		else if (ligneCount <= 3) 
		{
			static int sorted_nums[256] = { 0 };
			char text[512] = { 0 };
			int i = 0;
			char chr = ligne[i];
			while (i < read) {
				while (chr != ',' && chr != '\0') {
					text[strlen(text)] = chr;
					++i;
					chr = ligne[i];
				}
				if (ligneCount == 2)
					numbers[num_len] = atoi(text);
				else
					sorted_nums[num_len] = atoi(text);
				memset(text, 0, len);
				num_len++;
				chr = ligne[++i];
			}
			if (ligneCount == 3) {
				static int isGood = 1;
				static int nums[] = { 147,12,1,0 };
				quickSort(numbers,0, num_len-1);
				for (int i = 0; i < num_len; ++i) {
					if (numbers[i] != sorted_nums[i]) {
						isGood = 0;
						break;
					}
				}
				if (isGood) {
					printf("Tu as bien programmer: quickSort !\n");
				}
				else {
					printf("Tu as un erreur dans: quickSort !\n");
				}
			}
			else {
				num_len = 0;
			}
		}
		ligneCount++;
	}

}
int main(int argc, char** argv) {
	
	FILE* input = fopen("test_input.txt","r");
	if (input != NULL) {
		test_code(input);
	}

	if(input != NULL)
		fclose(input);

	return 0;
}
