#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>
#include "labo.h"

/*
* Creer un noeud et l'ajouter apres le noeud currNode.
* 
Utiliser la fonction allocate pour allouer de la memoire.
*/ 
void insert(Node* currNode, void* newData) {
	Node* newNode = (Node*)allocate(sizeof(Node)); // Creer le noeud et allouer dynamiquement de la m�moire(allocate) pour ce nouveau noeud
	
	newNode->data = newData; // Rajoute nom et age dans data
	newNode->next = NULL; // Indique que le prochain noeud est la fin

	// Fin creation newNode

	if (currNode->next != NULL) { // Si le suivant du noeud actuel est pas vide 
		newNode->next = currNode->next; // Le suivant du nouveau noeud devient le suivant du noeud actuel
	}
	
	currNode->next = newNode; // Le suivant du noeud actuel est le nouveau noeud
}


/*
* Creer un noeud et l'ajouter apres le noeud head.
Si le noeud head est vide(data) lui donner la nouvelle valeur passer.
*/
void insertHead(Node* head, void* newData) {
	if (head->data == NULL) { // Si le noeud head est vide, lui donner la nouvelle valeur
		head->data = newData;
	}
	else { // Autrement creer un noeud et l'ajouter apres le noeud head.
		Node* newNode = (Node*)allocate(sizeof(Node));
		newNode->data = newData; 

		newNode->next = head->next; // Le noeud suivant le nouveau noeud devient le suivant du head
		head->next = newNode; // Le suivant du noeud head devient le nouveau noeud
	}
}




/*
* Supprimer le noeud ayant la valeur de pointeur de data i.e. node->data == rmData. Par simplicite, pour supprimer faite un memset(node,0,sizeof(Node));
* Retourner le noeud juste avant celui supprimer
*/
Node* removeByData(Node* head, void* rmData) {
	Node* temp = head;
	Node* last = NULL;

	while (temp != NULL && temp->data != rmData) { // Tant que temp est pas NULL et que temp->data egale pas rmData
		last = temp; // last(NULL) prend la valeur temp(head)
		temp = temp->next; // temp(head) pointe le suivant
		
	}
	if (temp == NULL) { // Si head est NULL ont sort
		return; 
	}

	if (last != NULL) { // Si last est different de NULL le suivant de last devient le suivant de temp
		last->next = temp->next;
	}
	else { // Autrement head devient le suivant de temp
		head = temp->next;
	}
	
	memset(temp, 0, sizeof(Node)); // Reiniatialisation de la memoire

	return last; // Retourner le noeud juste avant celui supprimer
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

	if (last != NULL) { // Si last est different de NULL last->next devient temp(head)->next
		last->next = temp->next;
	}
	else { // Autrement head devient le suivant de temp
		head = temp->next;
	}

	memset(temp, 0, sizeof(Node));
	return last; // Retourner le noeud juste avant celui supprimer
}


/*
* Trier par l'age. Utiliser l'algorithme que vous connaissez le mieux.
*/
void sort(Node* head) {
	Node* i = head; // Position 1
	Node* j = i->next; // Position 2

	for (i = head; i->next != NULL; i = i->next) { // Deux loops pour pointer different index
		for (j = i->next; j != NULL; j = j->next) {
			Person* person_1 = (Person*)i->data; // Apres de longue essaie a comparer i->data & j->data, j'ai compris que l'age n'etait pas pointer\comparer donc j'ai compris qu'il fallait aller chercher la struct pour par la suite aller chercher l'age. J'ai du demander a copilot la syntaxe pour aller la chercher en dehors de labo.c
			Person* person_2 = (Person*)j->data;
			Person temp;

			if (person_1->age > person_2->age) { // Si l'age de la person_1 est plus grande que l'age de la person_2 ont fait un swap
				temp = *person_1;
				*person_1 = *person_2;
				*person_2 = temp;
			}
		}
	}
}


