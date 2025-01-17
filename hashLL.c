/*
For numeric keys, divide the key by the number of available 
adresses, n, and take the remainder
address = key % n 

for alphanumeric keys, divide the sum of ASCII codes in a
key by the number of available addresses, n, and take the 
remainder

resolving a collision by placing an item somewhere other than
its calculated address is called 'open addressing'
-linear probing. checking the next place until a free space is found

Load Factor = Total number of items stored (N) / size of the array (M)

collisions can also be resolved by 'chaining' aka 'closed addressing'
In chaining, the address is a pointer to the first node
of a linked list

when deleting cells, DON'T leave empty. Instead, mark as 
deleted

TC for updating cell = O(1)
TC for iterating through cells till empty space is found = O(M)

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10


typedef struct {
    char name[MAX_NAME];
    int age;
    struct person *next;
} person;

person * hash_table[TABLE_SIZE]; // hash table is an array of pointers to people structs

unsigned int hash(char *name) {
    int length = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;

    for (int i = 0; i < length; i++) {
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }

    return hash_value;
}

void init_hash_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = NULL;
    }
    // table is empty
}

void print_table() {
    printf("Start\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] == NULL) {
            printf("\t%i\t---\n", i);
        }
        else {
            printf("\t%i\t ", i);
            person *tmp = hash_table[i];
            while (tmp != NULL) {
                printf("%s - ", tmp->name);
                tmp = tmp->next;
            }
            printf("\n");
        }
    }
    printf("End\n");
}

//function to insert person into table
bool hash_table_insert(person *p) {
    if (p == NULL) return false;

    int index = hash(p->name);

    p->next = hash_table[index];
    hash_table[index] = p;

    return true;
}

//find a person in the table by their name
person *hash_table_lookup(char *name) {
    int index = hash(name);

    person *tmp = hash_table[index];
    while(tmp != NULL && strncmp(tmp->name, name, MAX_NAME) != 0) {
        tmp = tmp->next;
    }

    return tmp;
}

person *hash_table_delete(char *name) {
    int index = hash(name);

    person *tmp = hash_table[index];
    person *prev = NULL;

    while(tmp != NULL && strncmp(tmp->name, name, MAX_NAME) != 0) {
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL) return NULL;

    if (prev == NULL) {
        //deleting the head
        hash_table[index] = tmp->next;
    }
    else {
        prev->next = tmp->next;
    }
    return tmp;
}

int main() {
    init_hash_table();
    print_table();

    person emery = {.name="Emery", .age=26};
    person hattie = {.name="Hattie", .age=24};
    person owen = {.name="Owen", .age=20};
    person bruh = {.name="Bruh", .age=150};
    person billy = {.name="Billy", .age=5};
    person ron = {.name="Ron", .age=29};
    person edward = {.name="Edward", .age=53};
    person tom = {.name="Tom", .age=19};
    person wase = {.name="Wase", .age=32};
    person cree = {.name="Cree", .age=88};

    hash_table_insert(&emery);
    hash_table_insert(&hattie);
    hash_table_insert(&owen);
    hash_table_insert(&bruh);
    hash_table_insert(&billy);
    hash_table_insert(&ron);
    hash_table_insert(&edward);
    hash_table_insert(&tom);
    hash_table_insert(&wase);
    hash_table_insert(&cree);
    print_table();

    person *tmp = hash_table_lookup("Bruh");
    tmp = hash_table_lookup("Bob");

    hash_table_delete("Bruh");
    hash_table_lookup("Bruh");

    print_table();

/*
    printf("Emery => %u\n", hash("Emery"));
    printf("Hattie => %u\n", hash("Hattie"));
    printf("Owen => %u\n", hash("Owen"));
    printf("Anna => %u\n", hash("Anna"));
    printf("Allison => %u\n", hash("Allison"));
    printf("J => %u\n", hash("J"));
    printf("Susan => %u\n", hash("Susan"));
    printf("Daniels => %u\n", hash("Daniels"));
    printf("Nono => %u\n", hash("Nono"));
    printf("Caleb => %u\n", hash("Caleb"));
*/

    return 0;
}