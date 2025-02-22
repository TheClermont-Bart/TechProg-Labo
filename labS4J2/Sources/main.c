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

static 	Person persons[32] = { 0 };
static 	Node nodes[32] = { 0 };
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
		Node n = { 0 };
		n.data = &persons[num_persons];
		nodes[num_persons] = n;
		num_persons++;
		ligneCount++;
	}
	Queue q = {0};
	//temp = new_stack(num_persons);
	
	push(&q, &nodes[0]);
	if (q.next != q.prev) {
		fprintf(stderr, "push n'assigne pas correctement le début et la fin lorsque la queue est vide.\n");
		out = -1;
	}
	for (int i = 1; i < num_persons; ++i) {
		push(&q,&nodes[i]);
	}
	Node* t_n = pop(&q);
	if (t_n == peek(&q)) {
		fprintf(stderr, "pop n'enlève pas le noeud de la queue.\n");
		out = -1;
	}
	t_n->prev = peek(&q);
	t_n->prev->next = t_n;
	q.prev = t_n;
	for (int i = 0; i < num_persons; ++i) {
		Person* p = pop(&q)->data;
		if (p->name != persons[i].name || p->age != persons[i].age) {
			fprintf(stderr, "Les éléments n'étaient pas dans le bonne ordre. Il y a potentiellement un problème avec push, pop ou peek.\n");
			out = -1;
		}
	}
	for (int i = 1; i < 4; ++i) {
		pushAsPriorityQueue(&q, &nodes[num_persons - i]);
	}
	for (int i = 0; i < num_persons-3; ++i) {
		pushAsPriorityQueue(&q, &nodes[i]);
	}
	for (int i = 0; i < num_persons; ++i) {
		Person* p = pop(&q)->data;
		if (p->name != persons[i].name || p->age != persons[i].age) {
			fprintf(stderr, "Les éléments n'étaient pas dans le bonne ordre. Il y a potentiellement un problème avec pushAsPriorityQueue.\n");
			out = -1;
		}
	}

	for (int i = 1; i < 4; ++i) {
		push(&q, &nodes[num_persons - i]);
	}
	for (int i = 0; i < num_persons - 3; ++i) {
		push(&q, &nodes[i]);
	}

	sortQueue(&q);
	for (int i = 0; i < num_persons; ++i) {
		Person* p = pop(&q)->data;
		if (p->name != persons[i].name || p->age != persons[i].age) {
			fprintf(stderr, "Les éléments n'étaient pas dans le bonne ordre. Il y a potentiellement un problème avec sortQueue.\n");
			out = -1;
		}
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
	FILE* input = fopen("test_input.txt","r");
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
