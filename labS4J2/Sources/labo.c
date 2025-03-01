#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "labo.h"


/*
Ajouter l'element sur la queue/file.
*/
void push(Queue* q, Node* n) {
	if (q->next == NULL) { 
		q->next = q->prev = n;
	}
	else { 
		Node* last = q->next;

		n->next = last;
		last->prev = n; 

		q->next = n; 
	}
}

/*
* Enlever l'element de la queue/file et retourner le noeud. Si jamais il n'y a pas de noeud, retourner NULL.
*/
Node* pop(Queue* q){
	if (q->next == NULL) {
		return; 
	}

	Node* n = q->prev;

	if (q->prev != NULL) {
		if (q->prev == q->next) {
			q->next = q->prev = NULL;
		}
		else {
			q->prev = q->prev->prev;
		}
	}
	return n;
}



/*
* Retourner l'element de la fin de la queue/file sans l'enlever de la queue. Si jamais il n'y a pas d'element, retourner NULL.
*/
Node* peek(Queue* q){
	if (q->next == NULL) {
		return NULL;
	}
	return q->prev;
}

/*
Ajouter l'element sur la queue/file comme si elle serait une priority queue.
Utiliser l'age afin de "trie" a chaque push. 
Faut tu prendre en consideration la priority queue.
La personne au premier pop() est la plus jeune.
*/
void pushAsPriorityQueue(Queue* q, Node* n) {
	if (q->next == NULL) {
		q->next = q->prev = n;
		return;
	}

	// Je te l'envoie pas fini donc ca l'arrete ici... Je vais quand meme essayer de le finir completement demain
	Node* n2 = q->next;

	while (n2 != NULL) {

		Person* person_n = (Person*)n->data;
		Person* person_n2 = (Person*)n2->data;
		
		if (person_n->age > person_n2->age) {
		}

		n2 = n2->next;

	}
}


/*
* Triee la queue. La personne au premier pop() est la plus jeune.Vous devez utiliser push,pop et/ou peek.
* Vous ne pouvez pas utiliser le meme algorithme de tri que celui utiliser lors du labo sur la stack
*/
void sortQueue(Queue* q){}