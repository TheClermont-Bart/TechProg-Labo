#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "labo.h"

/*
* Creer la fonction d'initialization. Utiliser la fonction allocate au lieu de malloc.
*/
Stack* new_stack(size_t max_size){
	Stack* newStack = (Stack*)allocate(sizeof(Stack));
	newStack->max_size = max_size;
	newStack->data = (Stack*)allocate(sizeof(Stack)*newStack->max_size);
	newStack->top = -1;
}

/*
* Ajouter l'element sur la stack. Prevener "l'overflow" de la stack.
*/
void push(Stack* s, void* newData){
	if (s->top + 1 < s->max_size) {
		s->top += 1;
		s->data[s->top] = newData;
	}
	else {
		return;
	}
}

/*
* Enlever l'element de la stack et retourner l'information. Si jamais il n'y a pas d'element, retourner NULL.
*/
void* pop(Stack* s){
	void* out = NULL;
	
	if( s->data == NULL || s->top == -1) {
		return NULL;
	}

	if ( s->top - 1 >= -1) {
		out = s->data[s->top];
		s->top -= 1;
	}
	return out;
}

/*
* Retourner l'element du top sans l'enlever de la stack. Si jamais il n'y a pas d'element, retourner NULL.
*/
void* peek(Stack* s){
	void* out = pop(s);

	if (out != NULL) {
		push(s, out);
	}
	else {
		return NULL;
	}

	return out;
}

/*
* Inverser l'ordre de la stack i.e. le haut va devenir le bas.Vous ne devez pas utilise la variable temp qui est une autre Stack.
*/
void reverseStack(Stack* s){
	Stack* newStack = new_stack(s->max_size);
	
	if (s->data == NULL || s->top == -1) {
		return NULL;
	}

	while (s->top != -1) {
		push(newStack, pop(s));
	}

	*s = *newStack; // Etape la plus toffe
}

/*
* Triee la stack.La personne sur le haut/top est la plus jeune. Vous ne pouvez pas modifier la propriete data directement. Vous devez utiliser push,pop et/ou peek.
*/
void sortStack(Stack* s){
	Stack* newStack = new_stack(s->max_size);
	while (s->top != -1) {
		Person* temp = pop(s);

		while(newStack->top != -1 && ((Person*)newStack->data[newStack->top])->age > temp->age) {
			push(s, pop(newStack));
		}
		push(newStack, temp);
	}
	while(newStack->top != -1) {
		push(s, pop(newStack));
	}
}