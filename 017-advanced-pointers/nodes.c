#include <stdio.h>
#include <stdlib.h>

struct node{
	int value; // actual value
	struct node *next; // pointer to next node
};

// func prototypes
struct node *add_to_list(struct node *list, int val);
void print_linked_list(struct node *list);
struct node *search_list(struct node *list, int value);
struct node *delete_from_linked_list(struct node *list, int value);


int main(){
	
	struct node *first = NULL; // initialize to null pointer at first
	
	//struct node *new_node = malloc(sizeof(struct node));
	//new_node->value = 10;

	//printf("Node value: %d\n", new_node->value);
	
	first = add_to_list(first, 10);
	first = add_to_list(first, 20);
	first = add_to_list(first, 30);

	print_linked_list(first);

	int value = 0;
	struct node *p;

	for(; value >= 0; ){
		printf("Enter value to search: ");
		scanf("%d", &value);

		if(value < 0){
			printf("Exiting program...\n");
			break;
		}

		//p = search_list(first, value);
		p = delete_from_linked_list(first, value);

		if(p!=NULL)
			printf("%d retrieved at node %d\n", value, p);
		else
			printf("Value not found\n");


		print_linked_list(first);

	}
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


struct node *search_list(struct node *list, int value){
	// struct node *p;

	// more optimized loop, since it iterates while value hasnt been found.
	// it will also stop when it gets to the end of the list; ie list == NULL
	for(; list!=NULL && list->value!=value; list = list->next)
		;

	return list;

	//for(p=list; p != NULL; p = p->next)
	//	if(p->value == value)
	//		return p

	//return NULL;
}



struct node *delete_from_linked_list(struct node *list, int value){
	struct node *cur, *prev;

	for(
			prev=NULL, cur=list; // set initial values of prev pointer to null and curr to first addr of list
			cur!=NULL && cur->value!=value; // iterate while curr is not NULL and value hasnt been found
			prev = cur, cur=cur->next) // point prev to current, and point curr to next address
		;

	if(cur == NULL) // value not found in list
		return list;

	else if (prev == NULL) // value to be removed is first node
		list = list->next;

	else // node to be removed is found but not as the first node
		prev->next = cur->next;


	free(cur); // deallocate memory holding this struct node
	
	return list;
}
