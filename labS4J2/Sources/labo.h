#include <stdint.h>
#include <assert.h>



void* allocate(size_t size);

/*
* Declarer une structure de donnee appeler Queue qui est un noeud comme le Node de la liste doublement chainee. Declare aussi un noeud qui va avoir le nom Node.
*/

typedef struct person_t {
	char name[256];
	size_t age;
} Person;

/*
* Ajouter l'element sur la queue/file.
*/
void push(Queue* q, Node* n);

/*
* Enlever l'element de la queue/file et retourner le noeud. Si jamais il n'y a pas de noeud, retourner NULL.
*/
Node* pop(Queue* q);



/*
* Retourner l'element de la fin de la queue/file sans l'enlever de la queue. Si jamais il n'y a pas d'element, retourner NULL.
*/
Node* peek(Queue* q);

/*
* Ajouter l'element sur la queue/file comme si elle serait une priority queue. Utiliser l'age afin de "trie" a chaque push.La personne au premier pop() est la plus jeune.
* On utilise pas une fonction de tri.
*/
void pushAsPriorityQueue(Queue* q, Node* n);


/*
* Triee la queue. La personne au premier pop() est la plus jeune.Vous devez utiliser push,pop et/ou peek.
* Vous ne pouvez pas utiliser le meme algorithme de tri que celui utiliser lors du labo sur la stack
*/
void sortQueue(Queue* q);