#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>
#include "labo.h"

/*
* Creer un noeud et l'ajouter apres le noeud currNode.
*/
void insert(Node* currNode, void* newData){
	Node* newNode = (Node*)allocate(sizeof(Node)); 
	newNode->data = newData;
	newNode->prev = NULL;
	newNode->next = NULL;
	
	if (currNode->next != NULL) { 
		newNode->next = currNode->next;
		currNode->next->prev = newNode;
	}

	currNode->next = newNode;
	newNode->prev = currNode;
}

/*
* Creer un noeud et l'ajouter apres le noeud de fin. Si le noeud head est vide(data) lui donner la nouvelle valeur passer.
*/
void insertTail(Node* head, void* newData){
	Node* newNode = (Node*)allocate(sizeof(Node));
	newNode->data = newData;
	newNode->prev = NULL;
	newNode->next = NULL;
	
	if (head->data == NULL) {
		head->data = newData;
		head->prev = head;
		head->next = head;
		return;
	}

	newNode->next = head;
	newNode->prev = head->prev;
	head->prev = newNode;
	
}

/*
* Creer un noeud et l'ajouter apres le noeud head. Si le noeud head est vide(data) lui donner la nouvelle valeur passer.
*/
void insertHead(Node* head, void* newData) {
	

	if (head->data == NULL) {
		head->data = newData;
		head->prev = head;
		head->next = head;
		return;
	}
	insert(head, newData);
}

/*
* Enlever le noeud de la liste et retourner le noeud avec aucune reference(i.e. next et prev == NULL)
*/
Node* removeNode(Node* currNode) {
	Node* temp = (Node*)allocate(sizeof(Node));
	temp = currNode;

	if (currNode == NULL) {
		return NULL;
	}

		currNode->next = NULL;
		currNode->prev = NULL;

	return currNode;
}
/*
* Ajouter dans le tableau le nom de chacun en ordre alphabetic. Par simplicite, considerer seulement les deux premiere lettre.
*/
void alphabetise(Node* head, char* names[]){
	Node* noeud1 = head; // Position 1
	//Node* noeud2 = noeud1->next; // Position 2
	int count = 0;
	char* temp;

	for (noeud1 = head; noeud1 != NULL; noeud1 = noeud1->next) {
		names[count++] = ((Person*)noeud1->data)->name;
	}

	for (int i = 0; i < count; i++) {
		for (int j = i+1; j < count; j++) {
			if (names[i][0] > names[j][0] || (names[i][0] == names[j][0]) && names[i][1] > names[j][1]) {
				temp = names[j];
				names[j] = names[i];
				names[i] = temp;
			}
		}
		
	}

}

