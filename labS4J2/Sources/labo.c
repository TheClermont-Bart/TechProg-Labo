#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "labo.h"


/*
Ajouter l'element sur la queue/file.
*/
void push(Queue* q, Node* n) {
	if (q->next == NULL) { // Si la file est vide
		q->next = q->prev = n; // Le nouveau noeud n est ajouter comme premier element de la file
	}
	else { // Si file pas vide
		Node* last = q->next;//Creer nouveau noeud avec la reference du dernier

		n->next = last; // Le suivant du nouveau noeud devien le dernier JE BUG
		last->prev = n; // 
		q->next = n;
	}
}

/*
* Enlever l'element de la queue/file et retourner le noeud. Si jamais il n'y a pas de noeud, retourner NULL.
*/
Node* pop(Queue* q){
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
	return q->prev;
}

/*
Ajouter l'element sur la queue/file comme si elle serait une priority queue. 
Utiliser l'age afin de "trie" a chaque push.
La personne au premier pop() est la plus jeune.
On utilise pas une fonction de tri.
*/
void pushAsPriorityQueue(Queue* q, Node* n){
	
}


/*
* Triee la queue. La personne au premier pop() est la plus jeune.Vous devez utiliser push,pop et/ou peek.
* Vous ne pouvez pas utiliser le meme algorithme de tri que celui utiliser lors du labo sur la stack
*/
void sortQueue(Queue* q){}