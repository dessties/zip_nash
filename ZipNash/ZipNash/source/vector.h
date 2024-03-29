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
	vector->capacity = capacity; //максимальний розмір
	vector->length = 0; //початковий розмір
}
/*
ініціалізація вектора з параметрами

vector - вказівгик га структуру

цілочисельний безнаковий капасіті - найбільший розмір масиву(на скількит елементів типу int калоку виділяти память(капасіть помножити на сайз інтів(4,8?!)))
In C and C++, the size of an int is typically 4 bytes on 32-bit systems and 8 bytes on 64-bit systems.

(int *) - вказую що це масив інтів(
(int *): Результат функції malloc - це вказівник на void (void *). Однак, оскільки ми збираємося використовувати цей блок пам'яті для зберігання елементів типу int, ми виконуємо приведення типів до вказівника на int, щоб вказати компілятору, що це масив елементів типу int.)
*/

//add items
void add_item(Vector* vector, int item) {
	if (vector->length >= vector->capacity) //досягнуто максимаьну ємність
	{
		vector->capacity *= 2; //збільшив ємність в 2 рази
		vector->array = (int*)realloc(vector->capacity, sizeof(int)); //перевиділив паять для нової ємності
	}
	vector->array[vector->length++] = item;
}

void freeVector(Vector* vector) {
	free(vector->array); // Звільняємо масив
	vector->length = 0; // Скидаємо розмір
	vector->capacity = 0; // Скидаємо максимальний розмір
}


#endif
