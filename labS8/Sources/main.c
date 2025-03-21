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


Stack stack_init(size_t max_size) {
	Stack s;
	s.max = max_size;
	s.top = -1;
	s.elements = allocate(sizeof(void*) * s.max);
	return s;
}

void stack_push(Stack* s, void* element) {
	if (s->max != s->top + 1) {
		s->top++;
		s->elements[s->top] = element;
	}
}

void* stack_pop(Stack* s) {
	if (s->top > -1) {
		void* elem = s->elements[s->top];
		s->elements[s->top] = NULL;
		--s->top;
		return elem;
	}
	return NULL;
}
void queue_init(Queue* q) {
	q->next = q->prev = NULL;
	q->count = 0;
}
void queue_push(Queue* q, void* data) {
	Node* n = allocate(sizeof(Node));
	n->data = data;
	n->prev = n->next = NULL;
	if (q->prev == NULL) {
		q->prev = q->next = n;
	}
	else {
		Node* temp = q->next;
		q->next = temp->prev = n;
		n->next = temp;
	}
}
void* queue_pop(Queue* q) {
	if (q->prev != NULL) {
		Node* temp = q->prev;
		if(temp->prev != NULL)
			temp->prev->next = NULL;
		q->prev = temp->prev;
		q->count++;
		return temp->data;
	}
}

#define HEAP_SIZE 1024 * 1024
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
	int n = 75;//ou 75 pour être slow
	for (int i = 0; i <= n; ++i) 
		printf("%lld\n", fibonacci(i));
	//Pour vous corriger verifier les nombres ici: https://coolconversion.com/math/fibonacci-tables/75

	TreeNode* root = tree_create_node("A");
	tree_add_node(root, tree_create_node("B"));
	tree_add_node(root, tree_create_node("C"));

	tree_add_node(root->left, tree_create_node("D"));
	tree_add_node(root->left, tree_create_node("E"));

	tree_add_node(root->right, tree_create_node("F"));

	int nodes_visited = dfs(root, "F");
	if (nodes_visited == 6) {
		printf("Vous avez potentiellement bien programmer la fonction depth first search\n");
	}
	else {
		printf("Vous n'avez pas bien programmer la fonction depth first search, vous avez visité %i nodes et on veut visiter 6 nodes\n",nodes_visited);
	}
	nodes_visited = 0;
	nodes_visited = bfs(root, "F");
	if (nodes_visited == 6) {
		printf("Vous avez potentiellement bien programmer la fonction breath first search\n");
	}
	else {
		printf("Vous n'avez pas bien programmer la fonction breath first search, vous avez visité %i nodes et on veut visiter 6 nodes\n", nodes_visited);
	}

	return 0;
}
