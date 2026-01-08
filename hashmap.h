#ifndef HASHMAP_H
#define HASHMAP_H

#include <stddef.h>

typedef struct IntNode {
	int key;
	int value;
	struct IntNode *next;
} IntNode;

struct IntToIntHashMap{
	//TODO: fill this in
	IntNode **buckets;
	size_t size;
	size_t capacity;
};

struct IntToIntHashMap* createIntToIntHashMap(int numBuckets);

void intToIntHashMapInsert(struct IntToIntHashMap* hmap, int key, int value);

int intToIntHashMapGet(struct IntToIntHashMap* hmap, int key);

void intToIntHashMapRemove(struct IntToIntHashMap* hmap, int key);

void destroyIntToIntHashMap(struct IntToIntHashMap* hmap);

typedef struct StrNode {
	char* key;
	int value;
	struct StrNode *next;
} StrNode;

struct StrToIntHashMap{
	//TODO: fill this in
	StrNode **buckets;
	size_t size;
	size_t capacity;
};

struct StrToIntHashMap* createStrToIntHashMap(int numBuckets);

void strToIntHashMapInsert(struct StrToIntHashMap* hmap, char* key, int value);

int strToIntHashMapGet(struct StrToIntHashMap* hmap, char* key);

void strToIntHashMapRemove(struct StrToIntHashMap* hmap, char* key);

void destroyStrToIntHashMap(struct StrToIntHashMap* hmap);

#endif // HASHMAP_H
