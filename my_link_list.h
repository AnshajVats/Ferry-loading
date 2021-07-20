/*
Program: Ferry Loading

Author: Anshaj vats

Date: 10/19/2020

Time spent: 5 hours

Purpose: practice with queue


*/


#ifndef MY_LINK_LIST_H
#define MY_LINK_LIST_H
#include "status.h"
typedef void* MY_QUEUE;

MY_QUEUE init_default_queue(void);
Status enqueue(MY_QUEUE hQueue,int value);
Status dequeue(MY_QUEUE hQueue);
int front(MY_QUEUE hQueue);
void destory_queue(MY_QUEUE* phQueue);
Boolean Queue_empty(MY_QUEUE hQueue);

#endif // !








