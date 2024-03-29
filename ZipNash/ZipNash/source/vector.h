#ifndef VECTOR_H
#define VECTOR_H

#include<stdio.h>
#include <stdlib.h>

typedef struct {
	size_t length;
	size_t capacity;
	int* array;
} Vector;

//init vector
void init_vector(Vector* vector, int capacity){
	vector->array = (int*)calloc(capacity, sizeof(int));
	vector->capacity = capacity; //������������ �����
	vector->length = 0; //���������� �����
}
/*
����������� ������� � �����������

vector - �������� �� ���������

������������� ���������� ������ - ��������� ����� ������(�� ������� �������� ���� int ������ ������� ������(������� ��������� �� ���� ����(4,8?!)))
In C and C++, the size of an int is typically 4 bytes on 32-bit systems and 8 bytes on 64-bit systems.

(int *) - ������ �� �� ����� ����(
(int *): ��������� ������� malloc - �� �������� �� void (void *). �����, ������� �� ��������� ��������������� ��� ���� ���'�� ��� ��������� �������� ���� int, �� �������� ���������� ���� �� ��������� �� int, ��� ������� ����������, �� �� ����� �������� ���� int.)
*/

//add items
void add_item(Vector* vector, int item) {
	if (vector->length >= vector->capacity) //��������� ���������� ������
	{
		vector->capacity *= 2; //������� ������ � 2 ����
		vector->array = (int*)realloc(vector->capacity, sizeof(int)); //���������� ����� ��� ���� ������
	}
	vector->array[vector->length++] = item;
}

void freeVector(Vector* vector) {
	free(vector->array); // ��������� �����
	vector->length = 0; // ������� �����
	vector->capacity = 0; // ������� ������������ �����
}


#endif
