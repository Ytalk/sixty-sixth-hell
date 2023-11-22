#include <stdio.h>
#include <stdlib.h>

#include "character.h"
#include "ctmbattlequeue.h"

struct desc_queue *newQueue(void){
	
	struct desc_queue *queue = (struct desc_queue*)malloc(sizeof(struct desc_queue));
	
	queue->head = NULL;
	queue->tail = NULL;
	queue->lenght = 0;
	return queue;
}

struct queue_node *queueNode(struct character *character){
	
	struct queue_node *new_queue_node = (struct queue_node*)malloc(sizeof(struct queue_node));
	
	new_queue_node->info = character;
	new_queue_node->next = NULL;
	return new_queue_node;
}

int empty_queue(struct desc_queue *queue){
	if(queue->head == NULL)
		return 1;
	else
		return 0;
}

void enqueue(struct desc_queue *queue, struct queue_node *new_queue_node){
	if(empty_queue(queue) == 1){
		queue->head = new_queue_node;
		queue->tail = new_queue_node;
	}
	else{
		queue->tail->next = new_queue_node;
		queue->tail = new_queue_node;
	}
	queue->lenght++;
}

struct queue_node *dequeue(struct desc_queue *queue){
	struct queue_node *aux = queue->head;

	if(queue->lenght > 0){
		queue->head = queue->head->next;
		queue->lenght--;
	}
	return aux;
}

int length(struct desc_queue *queue){
	return queue->lenght;
}

void makeNull(struct desc_queue *queue){
		while(empty_queue(queue) == 0){
			free(dequeue(queue));
		}
}

struct queue_node *head(struct desc_queue *queue){
	return queue->head;
}

void showQueue(struct desc_queue *queue){
	struct queue_node *first = head(queue);

	if(first == NULL)
		printf("vazia!\n");

	while(first != NULL){
		//printf("\n[titulo: %s\nartista: %s\nletra: %s\ncodigo: %i\nexecucoes: %i]\n",topo->info->title, topo->info->artist, topo->info->lyrics, topo->info->code, topo->info->exe);*/
		first = first->next;
	}
}