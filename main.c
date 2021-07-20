/*
Program: Ferry Loading

Author: Anshaj vats

Date: 10/19/2020

Time spent: 5 hours

Purpose: practice with queue


*/

#include<stdio.h>
#include<stdlib.h>
#include"my_link_list.h"

void clear_keyboard_buffer();
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
		
		array[i]=knows_the_number_of_trips_needed(cases);
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

	size_ferry = l*100;
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
			while ((!Queue_empty(Queue_left)) && front(Queue_left) <= size_ferry)
			{
				size_ferry -=front(Queue_left);
				dequeue(Queue_left);
			}

			state = RIGHT;
			size_ferry = l * 100;
			
		}

		else if(state==RIGHT)
		{
			while ((!Queue_empty(Queue_right)) && front(Queue_right) <= size_ferry)
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
