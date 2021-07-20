/*
Program: Ferry Loading

Author: Anshaj vats

Date: 10/19/2020

Time spent: 5 hours

Purpose: practice with queue


*/

#include <stdio.h>
#include<stdlib.h>
#include "my_link_list.h"

typedef struct queue Queue;

typedef struct node Node;
struct node
{
	int data;
	Node* next;
	
};

struct queue
{
	Node* front;
	Node* rear;
};

MY_QUEUE init_default_queue(void)
{
	Queue* temp = NULL;
	temp = (Queue*)malloc(sizeof(Queue));
	if (temp != NULL)
	{
		temp->front = NULL;
		temp->rear = NULL;
	}
	return temp;
}



Status enqueue(MY_QUEUE hQueue, int value)
{
	Queue* pQueue = (Queue*)hQueue;
	Node* temp = NULL;
	
	temp = (Node*)malloc(sizeof(Node));
	if (temp == NULL)
	{
		printf("failed to allocate memory\n");
		return FAILURE;
	}
	temp->data = value;
	temp->next = NULL;

	if (pQueue->rear == NULL)
	{
		pQueue->rear = temp;
		pQueue->front = temp;
		return SUCCESS;

	}

	pQueue->rear->next = temp;
	pQueue->rear = temp;
	return SUCCESS;
}

Status dequeue(MY_QUEUE hQueue)
{
	Queue* pQueue = (Queue*)hQueue;

	if (pQueue->front == NULL)
	{
		return SUCCESS;
	}

	Queue* temp = pQueue->front;
	pQueue->front = pQueue->front->next;

	if (pQueue->front == NULL)
	{
		pQueue->rear = NULL;
	}

	free(temp);
	return SUCCESS;


}


 int front(MY_QUEUE hQueue)
{
	Queue* pQueue = (Queue*)hQueue;
	
	return pQueue->front->data;

}


Boolean Queue_empty(MY_QUEUE hQueue)
{
	Queue* pQueue = (Queue*)hQueue;

	return (pQueue->rear == NULL);
	


}
void destory_queue(MY_QUEUE* phQueue)
{
	Queue* pQueue = (Queue*)*phQueue;
	Node* tmp;

	while (pQueue-> front != NULL)
	{
		tmp = pQueue->front;
		pQueue->front = pQueue->front->next;
		free(tmp);
	}
	pQueue->rear = NULL;
	free(pQueue);
	*phQueue = NULL;

	
	
}


