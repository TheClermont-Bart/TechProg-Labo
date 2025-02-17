#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>
#include "labo.h"

/*
* Creer un noeud et l'ajouter apres le noeud currNode. Considerer la propriete next et prev.
*/
void insert(Node* currNode, void* newData){
	Node* newNode = (Node*)allocate(sizeof(Node)); // Allouer dynamiquement de la mémoire pour le nouveau noeud

	newNode->data = newData; // Mettre les newData dans ce newNode->data
	currNode->next = newNode; // Indique que le suivant de currNode devient notre newNode
	newNode->prev = currNode; // Indique que le precedent devient le currNode
}

/*
* Creer un noeud et l'ajouter apres le noeud de fin. Si le noeud head est vide(data) lui donner la nouvelle valeur passer.
*/
void insertTail(Node* head, void* newData){
	
	if (head->data != NULL) { // S'il n'a rien dans les data du head
		head->data = newData; // Donner les newData au head
	}
	else {
		Node* newNode = (Node*)allocate(sizeof(Node));
		newNode->data = newData; // Ajout des newData
		newNode->prev = NULL; // Le precedent du newNode est le noeud de fin
	}
}

/*
* Creer un noeud et l'ajouter apres le noeud head. Si le noeud head est vide(data) lui donner la nouvelle valeur passer.
*/
void insertHead(Node* head, void* newData){

	if (head->data == NULL) { // Si le noeud head a rien dans data lui donner newData
		head->data = newData;
		return; // Important sinon il le programme continue
	}
		
		Node* newNode = (Node*)allocate(sizeof(Node)); // Creation nouveau noeud
		newNode->data = newData; // Donner newData a newNode->data
		newNode->prev = head; // Le precedent est le head
		newNode->next = head->next; // Le suivant du newNode est le suivant du head

		head->next = newNode; // Le suivant de head devient newNode
}

/*
* Enlever le noeud de la liste et retourner le noeud avec aucune reference(i.e. next et prev == NULL)
*/
Node* removeNode(Node* currNode){
	if (currNode != NULL) {
		Node* newNode = (Node*)allocate(sizeof(Node));
		newNode->data = currNode->data;
		newNode->next = NULL;
		newNode->prev = NULL;
		return newNode;
	}
	else {
		Node* temp = currNode;
		temp->prev = temp->next;
		temp->next = temp->prev;

		free(temp);
	}
	return 0;

}

/*
* Ajouter dans le tableau le nom de chacun en ordre alphabetic. Par simplicite, considerer seulement les deux premiere lettre.
*/
void alphabetise(Node* head, char* names[]){}

