#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "labo.h"

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

static Stack* temp;
static 	Person persons[32] = { 0 };
static 	Person sorted_persons[32] = { 0 };
int test_code(FILE* f) {
	int out = 0;
	char* ligne = NULL;
	size_t len = 0;
	size_t read;
	int ligneCount = 0;

	size_t num_persons = 0;
	int line = __LINE__;
	int hline = 0;
	while ((read = getline(&ligne, &len, f)) != -1) {
		char text[512] = { 0 };
		int i = 0;
		char chr = ligne[i];
		int isSearched = 0;
		Person p = persons[num_persons];
		while (i < read) {
			while (chr != ',' && chr != ' ' && chr != '\0') {
				text[strlen(text)] = chr;
				++i;
				chr = ligne[i];
			}
			if (strcmp(text, "name") == 0) {
				isSearched = 1;
				memset(text, 0, strlen(text));
			}
			else if (strcmp(text, "age") == 0) {
				isSearched = 1;
				memset(text, 0, strlen(text));
			}
			else if (isSearched && p.name[0] == '\0') {
				strcpy(p.name,text);
				memset(text, 0, strlen(text));
				isSearched = 0;
			}
			else if (isSearched && p.name[0] != '\0') {
				p.age =  atoi(text);
				memset(text, 0, strlen(text));
				isSearched = 0;
			}
			chr = ligne[++i];
		}
		persons[num_persons] = p;
		num_persons++;
		ligneCount++;
	}
	Stack* s = new_stack(num_persons);
	temp = new_stack(num_persons);
	if (s != NULL) {
		for (int i = 0; i < num_persons; ++i) {
			push(s, &persons[i]);
		}
		push(s, &persons[0]);
		push(s, &persons[0]);
		if (s->top >= s->max_size) {
			fprintf(stderr, "Vous ne prévenez pas l'overflow.\n");
			pop(s);
			pop(s);
			out = -1;
		}
		for (int i = num_persons -1; i > -1; --i) {
			Person* p = pop(s);
			if (p->name != persons[i].name || p->age != persons[i].age) {
				fprintf(stderr, "Element wasn't in the right order. There maybe an issue with either push or pop.\n");
				out = -1;
			}
		}
		push(s, &persons[num_persons -1]);
		Person* p = peek(s);
		if (p->name != persons[num_persons - 1].name || p->age != persons[num_persons - 1].age) {
			fprintf(stderr, "peek n'a pas retourner exactement la même Personne.\n");
			out = -1;
		}
		p = peek(s);
		if (p == NULL) {
			fprintf(stderr, "peek semble modifier la mémoire de la stack...\n");
			out = -1;
		}
		pop(s);
		p = peek(s);
		if (p != NULL || s->data[0] == NULL) {
			fprintf(stderr, "peek ne retourne pas NULL lorsque vide ou il push un NULL pointeur.\n");
			out = -1;
		}

		for (int i = 0; i < num_persons; ++i) {
			push(s, &persons[i]);
		}
		reverseStack(s);
		for (int i = 0; i < num_persons; ++i) {
			Person* p = pop(s);
			if (p->name != persons[i].name || p->age != persons[i].age) {
				fprintf(stderr, "reverseStack n'a pas fonctionner.\n");
				out = -1;
			}
		}
		memset(s->data, 0, sizeof(void*) * s->max_size);
		for (int i = 0; i < num_persons-3; ++i) {
			push(s, &persons[i]);
		}
		for (int i = 1; i < 4; ++i) {
			push(s, &persons[num_persons - i]);
		}
		sortStack(s);
		for (int i = 0; i < num_persons; ++i) {
			Person* p = pop(s);
			if (p->name != persons[i].name || p->age != persons[i].age) {
				fprintf(stderr, "L'ordre dans la stack n'est pas bonne.\n");
				out = -1;
			}
		}
	}
	else {
		fprintf(stderr, "new_stack implementation fails to create the stack...\n");
		out = -1;
	}
	

	return out;
}

#define HEAP_SIZE 2048 * 2048 * 4
static uint8_t* heap = NULL;
static size_t heap_top = 0;
void* allocate(size_t size) {
	size_t old_top = heap_top;
	heap_top += size;
	assert(heap_top <= HEAP_SIZE);
	return &heap[old_top];
}

int main(int argc, char** argv) {
	heap = (uint8_t*)malloc(HEAP_SIZE);
	assert(heap != NULL);

	int result = 0;
	FILE* input =fopen("test_input.txt","r");
	if (input != NULL) {
		result = test_code(input);
	}
	else {
		fprintf(stderr, "test_input file didn't exist.\n");
	}

	if(input != NULL)
		fclose(input);

	return result;
}
