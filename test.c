
#include<stdio.h>
#include<stdlib.h>
enum status { FAILURE, SUCCESS };
typedef enum status Status;

enum boolean { FALSE, TRUE };

typedef enum boolean Boolean;

enum state { LEFT, RIGHT };
typedef enum state State;

typedef void* MY_QUEUE;

MY_QUEUE init_default_queue(void);
Status enqueue(MY_QUEUE hQueue, int value);
Status dequeue(MY_QUEUE hQueue);
int front(MY_QUEUE hQueue);
void destory_queue(MY_QUEUE* phQueue);
Boolean Queue_empty(MY_QUEUE hQueue);
void clear_keyboard_buffer();

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
int knows_the_number_of_trips_needed(int cases);


int main(int argc, char argv[])
{



	int cases = 0;
	int i = 0;
	int cases_copy = 0;


	scanf("%d", &cases);
	clear_keyboard_buffer();
	cases_copy = cases;

	int* array = NULL;
	array = (int*)malloc(sizeof(int) * cases);
	if (array == NULL)
	{
		printf("failed to allocate memory");
		exit(1);
	}

	while (cases != 0)
	{

		cases--;

		array[i] = knows_the_number_of_trips_needed(cases);
		i++;
	}

	for (i = 0; i < cases_copy; i++)
	{
		printf("%d\n", array[i]);
	}

	free(array);
	array = NULL;
	return 0;
}

void clear_keyboard_buffer(void)
{
	char c;
	int noc;
	noc = scanf("%c", &c);
	while (noc == 1 && c != '\n')
	{
		scanf("%c", &c);
	}
}


int knows_the_number_of_trips_needed(int cases)
{
	MY_QUEUE Queue_right = init_default_queue();
	MY_QUEUE Queue_left = init_default_queue();
	int l = 0;
	int m = 0;
	int car_length = 0;
	char side;
	State state = LEFT;
	int result = 0;
	int size_ferry = 0;


	scanf("%d %d", &l, &m);
	clear_keyboard_buffer();

	size_ferry = l * 100;
	while (m != 0)
	{
		m--;

		scanf("%d  %c", &car_length, &side);
		clear_keyboard_buffer();

		if (side == 'l')
		{
			//printf("%d   %c\n", car_length, side);
			enqueue(Queue_left, car_length);

		}
		else if (side == 'r')
		{
			//printf("%d   %c\n", car_length, side);
			enqueue(Queue_right, car_length);
		}


	}





	while ((!Queue_empty(Queue_left)) || (!Queue_empty(Queue_right)))
	{


		if (state == LEFT)
		{
			while ((!Queue_empty(Queue_left)) && front(Queue_left) < size_ferry)
			{
				size_ferry -= front(Queue_left);
				dequeue(Queue_left);
			}

			state = RIGHT;
			size_ferry = l * 100;

		}

		else if (state == RIGHT)
		{
			while ((!Queue_empty(Queue_right)) && front(Queue_right) < size_ferry)
			{
				size_ferry -= front(Queue_right);
				dequeue(Queue_right);
			}

			state = LEFT;
			size_ferry = l * 100;


		}




		result++;
	}

	destory_queue(&Queue_left);
	destory_queue(&Queue_right);
	return result;

}


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

	while (pQueue->front != NULL)
	{
		tmp = pQueue->front;
		pQueue->front = pQueue->front->next;
		free(tmp);
	}
	pQueue->rear = NULL;
	free(pQueue);
	*phQueue = NULL;



}