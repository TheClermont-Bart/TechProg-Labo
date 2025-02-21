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

	if (currNode != NULL) {
		currNode->next = NULL;
		currNode->prev = NULL;
	}

	return currNode;
}
/*
* Ajouter dans le tableau le nom de chacun en ordre alphabetic. Par simplicite, considerer seulement les deux premiere lettre.
*/
void alphabetise(Node* head, char* names[]){
	Node* i = head; // Position 1
	Node* j = i->next; // Position 2
	int count = 0;

	for (i = head; i->next != NULL; i = i->next) { // Deux loops pour pointer different index
		for (j = i->next; j->next != NULL; j = j->next) {
			Person* person_1 = (Person*)i->data; 
			Person* person_2 = (Person*)j->data;
			Person temp;
			if (person_1->name[0] > person_2->name[0] && person_2->name != names[count])
			{ 
				names[count] = person_2->name;
				count++;
			}
		}
	}
}

