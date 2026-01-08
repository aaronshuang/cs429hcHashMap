#include "hashmap.h"
#include <stdlib.h>
#include <string.h>

int intToIntHashFunction(int key){
	//TODO: fill this in
	return (key < 0) ? -key : key;
}

struct IntToIntHashMap* createIntToIntHashMap(int numBuckets){
	//TODO: fill this in
	struct IntToIntHashMap *hmap = malloc(sizeof(struct IntToIntHashMap)); //malloc to allocate space
	if (!hmap) return NULL;

	hmap->buckets = calloc(numBuckets, sizeof(IntNode*)); //calloc to allocate space for an array of IntNodes. 

	if (!hmap->buckets) {
		free(hmap);
		return NULL;
	}

	hmap->capacity = numBuckets;
	hmap->size = 0;

	return hmap;
}

void intToIntHashMapInsert(struct IntToIntHashMap* hmap, int key, int value){
	//TODO: fill this in
	int index = intToIntHashFunction(key) % hmap->capacity;

	IntNode *current = hmap->buckets[index];

	while (current != NULL) {
		if (current->key == key) {
			current->value = value;
			return;
		}
		current = current->next;
	}
	
	//doesn't exist so create a new IntNode
	IntNode *newNode = malloc(sizeof(IntNode));
	newNode->key = key;
	newNode->value = value;
	newNode->next = hmap->buckets[index];
	hmap->buckets[index] = newNode;
	hmap->size++;
}

int intToIntHashMapGet(struct IntToIntHashMap* hmap, int key){
	//TODO: fill this in
	int index = intToIntHashFunction(key) % hmap->capacity;

	IntNode *current = hmap->buckets[index];

	while (current != NULL) {
		if (current->key == key) {
			return current->value;
		}
		current = current->next;
	}

	return -1;
}

void intToIntHashMapRemove(struct IntToIntHashMap* hmap, int key){
	//TODO: fill this in
	int index = intToIntHashFunction(key) % hmap->capacity;

	IntNode *current = hmap->buckets[index];
	IntNode *prev = NULL;

	while (current != NULL) {
		if (current->key == key) {
			if (prev) {
				prev->next = current->next;
			}
			else {
				hmap->buckets[index] = current->next;
			}
			hmap->size--;
			free(current);
			return;
		}
		prev = current;
		current = current->next;
	}
}

void destroyIntToIntHashMap(struct IntToIntHashMap* hmap){
	//TODO: fill this in
	if (!hmap) return;
	for (int i = 0; i < hmap->capacity; i++) {
		IntNode *current = hmap->buckets[i];
		while (current != NULL) {
			IntNode *temp = current;
			current = current->next;
			free(temp);
		}
	}

	free(hmap->buckets);
	free(hmap);
}


int strToIntHashFunction(char* key){
	//TODO: fill this in
	unsigned long hash = 5381;
	int c;

	while ((c = *key++)){
		hash = ((hash << 5) + hash) + c; //bit optimization for hash * 33 + c
	}
	return (int) (hash & 0x7FFFFFFF); //clears the sign
}

struct StrToIntHashMap* createStrToIntHashMap(int numBuckets){
	//TODO: fill this in
	struct StrToIntHashMap *hmap = malloc(sizeof(struct StrToIntHashMap));
	if (!hmap) return NULL;

	hmap->buckets = calloc(numBuckets, sizeof(StrNode*));

	if (!hmap->buckets) {
		free(hmap);
		return NULL;
	}

	hmap->capacity = numBuckets;
	hmap->size = 0;

	return hmap;
}

void strToIntHashMapInsert(struct StrToIntHashMap* hmap, char* key, int value){
	//TODO: fill this in
	int index = strToIntHashFunction(key) % hmap->capacity;

	StrNode *current = hmap->buckets[index];

	while (current != NULL) {
		if (strcmp(current->key, key) == 0) {
			current->value = value;
			return;
		}
		current = current->next;
	}

	StrNode *newNode = malloc(sizeof(StrNode));
	newNode->key = key;
	newNode->value = value;
	newNode->next = hmap->buckets[index];
	hmap->buckets[index] = newNode;
	hmap->size++;
}

int strToIntHashMapGet(struct StrToIntHashMap* hmap, char* key){
	//TODO: fill this in
	int index = strToIntHashFunction(key) % hmap->capacity;

	StrNode *current = hmap->buckets[index];

	while (current != NULL) {
		if (strcmp(current->key, key) == 0) {
			return current->value;
		}
		current = current->next;
	}

	return -1;
}

void strToIntHashMapRemove(struct StrToIntHashMap* hmap, char* key){
	//TODO: fill this in
	int index = strToIntHashFunction(key) % hmap->capacity;

	StrNode *current = hmap->buckets[index];
	StrNode *prev = NULL;

	while (current != NULL) {
		if (strcmp(current->key, key) == 0) {
			if (prev) {
				prev->next = current->next;
			}
			else {
				hmap->buckets[index] = current->next;
			}
			hmap->size--;
			free(current);
			return;
		}
		prev = current;
		current = current->next;
	}
}

void destroyStrToIntHashMap(struct StrToIntHashMap* hmap){
	//TODO: fill this in
	if (!hmap) return;
	for (int i = 0; i < hmap->capacity; i++) {
		StrNode *current = hmap->buckets[i];
		while (current != NULL) {
			StrNode *temp = current;
			current = current->next;
			free(temp);
		}
	}

	free(hmap->buckets);
	free(hmap);
}


