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

static Node head = { NULL };
static 	Person persons[32] = { 0 };
int test_code(FILE* f) {
	int out = 0;
	char* ligne = NULL;
	size_t len = 0;
	size_t read;
	int ligneCount = 0;

	size_t num_persons = 0;
	Node* n = NULL;
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
		if (num_persons <= 1) {
			insertHead(&head, &persons[num_persons]); hline = __LINE__;
			n = head.next;
			if(num_persons == 1)
				assert(n != NULL);
		}
		else {
			insert(n, &persons[num_persons]); line = __LINE__;
			n = n->next;
		}
		num_persons++;
		ligneCount++;
	}
	//Validate insertion
	if (head.data == NULL) {
		fprintf(stderr, "Make sure the head Node gets set on insertHead, at line %i\n", hline);
		out = -1;
	}
	int i = 0;
	Node* node = &head;
	while (i < num_persons) {
		Person* p = (Person*)node->data;
		if (p != NULL && (strcmp(p->name, persons[i].name) != 0 || p->age != persons[i].age)) {
			fprintf(stderr, "Insertion failed on person %s with age %i, at line %i\n", persons[i].name, (int)persons[i].age,line);
			out = -1;
		}
		node = node->next;
		++i;
	}
	Node* l = removeNode(head.prev); line = __LINE__;
	Person* p = NULL;
	if(l != NULL)
		p = l->data;
	if (p == NULL || (strcmp(p->name, persons[num_persons-1].name) != 0 && p->age != persons[num_persons-1].age)) {
		fprintf(stderr, "Deletion failed on person %s with age %i, at line %i\n", persons[num_persons - 1].name, (int)persons[num_persons - 1].age, line);
		out =  -1;
	}
	if (l != NULL)
		insertTail(&head, l->data);
	if (l->data != head.prev->data || head.prev->next != &head) {
		fprintf(stderr, "Insertion at Tail failed\n");
		out = -1;
	}
	char* names[128] = { 0 };
	alphabetise(&head, names);
	for (int i = 1; i < num_persons; ++i) {
		if ((int)names[i - 1][0] > (int)names[i][0] || ((int)names[i - 1][1] > (int)names[i][1] && (int)names[i - 1][0] == (int)names[i][0])) {
			fprintf(stderr, "Alphabetise failed to order the names\n");
			for (int y = 0; y < num_persons; ++y) {
				fprintf(stderr, "Name index %i name %s\n",y,names[y]);
			}
			out = -1;
		}
	}
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

	if(input != NULL)
		fclose(input);

	return result;
}
