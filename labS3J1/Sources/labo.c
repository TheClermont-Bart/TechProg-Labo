#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>
#include "labo.h"


/*
* Creer un noeud et l'ajouter apres le noeud currNode.
Utiliser la fonction allocate pour allouer de la memoire.
*/
void insert(Node* currNode, void* newData) {
	Node* newNode = (Node*)allocate(sizeof(Node)); // Allouer dynamiquement de la mémoire pour le nouveau nœud
	
	newNode->data = newData;
	newNode->next = NULL;

	if (currNode->next != NULL) { //Ajouter apres le noeud currNode NULL.
		newNode->next = currNode->next;
	}
	
	currNode->next = newNode;
}


/*
* Creer un noeud et l'ajouter apres le noeud head.
Si le noeud head est vide(data) lui donner la nouvelle valeur passer.
*/
void insertHead(Node* head, void* newData) {
	// Si le nœud head est vide, lui donner la nouvelle valeur
	if (head->data == NULL) {
		head->data = newData;
	}
	else {
		// Sinon allouer dynamiquement de la mémoire pour le nouveau nœud
		Node* newNode = (Node*)allocate(sizeof(Node));
		newNode->data = newData;
		newNode->next = head->next; // Le prochain devient le next.
		head->next = newNode; // 
	}
}




/*
* Supprimer le noeud ayant la valeur de pointeur de data i.e. node->data == rmData. Par simplicite, pour supprimer faite un memset(node,0,sizeof(Node));
* Retourner le noeud juste avant celui supprimer
*/
Node* removeByData(Node* head, void* rmData) {
	Node* temp = head;
	Node* last = NULL;

	while (temp != NULL && temp->data != rmData) { // Tant que temp est pas NULL et que temp-> egale pas rmData
		last = temp; // last(NULL) prend la valeur temp(head)
		temp = temp->next; // temp(head) devien le next
		
	}
	if (temp == NULL) { // Si head est NULL ont sort
		return; 
	}

	// Un lien du nœud précédant au nœud suivant
	if (last != NULL) {
		last->next = temp->next;
	}
	else { // Si le nœud à supprimer est le head
		head = temp->next;
	}

	//last->data = temp->next;  // last->next devient temp(head)->next
	
	memset(temp, 0, sizeof(Node));

	return last;
}



/*
* Supprimer le noeud ayant le nom passer par name.Par simplicite, pour supprimer faite un memset(node,0,sizeof(Node));
* Retourner le noeud juste avant celui supprimer
*/
Node* removeByName(Node* head, char* name) {
	Node* temp = head;
	Node* last = NULL;

	while (temp != NULL && temp->data != name) { // Tant que temp est pas NULL et que temp->data egale pas name
		last = temp; // last(NULL) prend la valeur temp(head)
		temp = temp->next; // temp(head) devien le next
		
	}
	if (temp == NULL) { // Si head est NULL ont sort
		return;
	}

	// last->next = temp->next;  // last->next devient temp(head)->next
	if (last != NULL) {
		last->next = temp->next;
	}
	else { // Si le nœud à supprimer est le head
		head = temp->next;
	}

	memset(temp, 0, sizeof(Node));
	return last;
}


/*
* Trier par l'age. Utiliser l'algorithme que vous connaissez le mieux.
*/
void sort(Node* head) {
	Node* i = head;
	Node* j = i->next;
	int temp;

	for (i ;i->next != NULL;i = i->next) {

		for (j ;j != NULL;j = j->next) {

			if (i->data < j->data) {
				temp = i->data;
				i->data = j->data;
				j->data = temp;
			}
		}
	}
}