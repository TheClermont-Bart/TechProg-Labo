#include "labo.h"

/*
* Programmer l'algorithme de fibonacci. Commencer par faire l'algorithme de base et par la suite ajouter la memoization.
* Faire attention lorsque vous utilisez un type pour une variable qui represente un nombre, int ne depasse pas 2^31-1 ou 2,147,483,647
*/
long long memoization[75] = { 0 };
long long fibonacci(int n) {
	if (n == 75) {
		return memoization[n];
	}
	if (n <= 1) {
		return n;
	}
	if (memoization[n] != 0 ) {
		return memoization[n];
	}

	memoization[n] = fibonacci(n - 1) + fibonacci(n - 2);

	return memoization[n];
};

/*
* Creer un Noeud, assigner lui la valeur de data, metter c'est reference a NULL et retourner le noeud.
*/
TreeNode* tree_create_node(void* data){
	TreeNode* Treenode = (TreeNode*)allocate(sizeof(TreeNode));

	Treenode->data = data;
	Treenode->left = NULL;
	Treenode->right = NULL;

	return Treenode;
}

/*
* Ajouter le noeud  node dans la propriete left ou right qui est NULL de root. On priorise de left a right. Si right et left son NULL on le met dans left.
* Si jamais aucun des noeuds est NULL, ajouter rien.
*/
void tree_add_node(TreeNode* root, TreeNode* node){
	if (root->left == NULL && root->right == NULL) {
		root->left = node;
		return;
	}
	if (root->left != NULL && root->right != NULL) {
		return;
	}
	if (root->left == NULL) {
		root->left = node;
		return;
	}
	if (root->right == NULL) {
		root->right = node;
		return;
	}
}

/*
* Programmer l'algorithme de depth first search afin de trouver la cle. Pour programmer cet algorithme, vous avez besoins d'une pile/stack, ca definition est fourni.
*/
int dfs(TreeNode* root, void* key){
	Stack* s;
	stack_init(s);
	int nodes_visited = 0;

	if (root->data == key) {
		nodes_visited++;
		return nodes_visited;
	}

	stack_push(s,root);

	while (root->left != NULL && root->data != key) {
		stack_pop(s);
		stack_push(s, root->right);
		stack_push(s, root->left);
		nodes_visited++;
		root = root->left;
	}

	while (root->left == NULL && root->right != NULL && root->data != key) {
		stack_pop(s);
		stack_push(s, root->right);
		stack_push(s, root->left);
		nodes_visited++;
		root = root->left;
	}

	return nodes_visited;
}

/*
* Programmer l'algorithme de breath first search afin de trouver la cle. Pour programmer cet algorithme, vous avez besoins d'une file/queue, ca definition est fourni.
*/
int bfs(TreeNode* root, void* key){}