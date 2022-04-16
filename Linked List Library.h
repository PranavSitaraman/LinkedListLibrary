#ifndef LINKED_LIST
#define LINKED_LIST
#include<stdio.h>
#include<stdlib.h>
using namespace std;
enum possible { INT, FLOAT, DOUBLE, BOOL, CHAR, OTHER };
struct value
{
	void* pointer;
	possible type;
};
struct node
{
	node* prev;
	value data;
	node* next;
};
void printval(value x)
{
	if (x.type == INT)
	{
		printf("%d", *(int*)(x.pointer));
	}
	else if (x.type == CHAR)
	{
		printf("%c", *(char*)(x.pointer));
	}
	else if (x.type == FLOAT)
	{
		printf("%f", *(float*)(x.pointer));
	}
	else if (x.type == DOUBLE)
	{
		printf("%lf", *(double*)(x.pointer));
	}
	else if (x.type == BOOL)
	{
		if (*(int*)(x.pointer))
		{
			printf("true");
		}
		else
		{
			printf("false");
		}
	}
};
struct linkedlist
{
	node* head = NULL;
	node* tail = NULL;
	linkedlist()
	{
		head = (node*)calloc(1, sizeof(node));
		tail = (node*)calloc(1, sizeof(node));
		head->next = tail;
		tail->prev = head;
	};
	void enqueue(value a)
	{
		node* end = (node*)malloc(sizeof(node));
		node* second = tail->prev;
		tail->prev = end;
		end->next = tail;
		end->data.pointer = a.pointer;
		end->data.type = a.type;
		end->prev = second;
		second->next = end;
	};
	value dequeue(void)
	{
		value val = (head->next)->data;
		head->next = (head->next)->next;
		free((head->next)->prev);
		(head->next)->prev = head;
		return val;
	};
	void push(value a)
	{
		node* begin = (node*)malloc(sizeof(node));
		node* second = head->next;
		head->next = begin;
		begin->prev = head;
		begin->data.pointer = a.pointer;
		begin->data.type = a.type;
		begin->next = second;
		second->prev = begin;
	};
	value pop(void)
	{
		value val = (head->next)->data;
		head->next = (head->next)->next;
		free((head->next)->prev);
		(head->next)->prev = head;
		return val;
	};
	bool empty()
	{
		if (head->next == tail && tail->prev == head)
		{
			return true;
		}
		return false;
	};
	void insert(int size, value a)
	{
		node* point = head;
		for (int i = 1; i < size; i++)
		{
			point = point->next;
		}
		node* second = point->next;
		node* insertion = (node*)malloc(sizeof(node));
		point->next = insertion;
		insertion->prev = point;
		insertion->data.pointer = a.pointer;
		insertion->data.type = a.type;
		insertion->next = second;
		second->prev = insertion;
	};
	void destroy(int size)
	{
		node* point = head;
		for (int i = 1; i < size; i++)
		{
			point = point->next;
		}
		point->next = (point->next)->next;
		free((point->next)->prev);
		(point->next)->prev = point;
	}
	value read(int size)
	{
		node* point = head;
		for (int i = 0; i < size; i++)
		{
			point = point->next;
		}
		return point->data;
	}
	void write(int size, value a)
	{
		node* point = head;
		for (int i = 0; i < size; i++)
		{
			point = point->next;
		}
		point->data.pointer = a.pointer;
		point->data.type = a.type;
	}
	void print()
	{
		node* point = head->next;
		while (point != tail)
		{
			printval(point->data);
			printf(" ");
			point = point->next;
		}
	}
	~linkedlist()
	{
		node* point = head;
		point = point->next;
		while (point != tail)
		{
			free(point->prev);
			point = point->next;
		}
	}
};
#endif