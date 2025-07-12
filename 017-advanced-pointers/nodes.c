#include <stdio.h>
#include <stdlib.h>

struct node{
	int value; // actual value
	struct node *next; // pointer to next node
};

// func prototypes
struct node *add_to_list(struct node *list, int val);
void print_linked_list(struct node *list);

int main(){
	
	struct node *first = NULL; // initialize to null pointer at first
	
	//struct node *new_node = malloc(sizeof(struct node));
	//new_node->value = 10;

	//printf("Node value: %d\n", new_node->value);
	
	first = add_to_list(first, 10);
	first = add_to_list(first, 20);
	first = add_to_list(first, 30);

	print_linked_list(first);

	return 0;
}

// func to add new nodes to linked list
struct node *add_to_list(struct node *list, int val){
	struct node *new_node; 
	new_node = malloc(sizeof(struct node));

	// throw error if malloc cant allocate mem
	if(new_node == NULL){
		printf("Error: malloc failed to allocate memory in *add_to_list\n");
		exit(EXIT_FAILURE);
	}

	
	new_node->value = val; // store value
	new_node->next = list; // new_node -> (existing nodes) -> NULL; make new node point to the top node in linked list 

	return new_node;
}


void print_linked_list(struct node *list){
	int i;

	// traverse linked list while its not NULL
	for(i=0;  list != NULL; list = list->next, i++)
		printf("Element %d:\t%d\n", i, list->value);

}
