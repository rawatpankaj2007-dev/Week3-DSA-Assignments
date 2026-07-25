#include <stdio.h>

#define SIZE 10

int hashTable[SIZE];

int hash(int key) {
    return key % SIZE;
}

int main() {
    for(int i=0;i<SIZE;i++)
        hashTable[i]=-1;

    int keys[] = {15, 25, 35};

    for(int i=0;i<3;i++) {
        int index = hash(keys[i]);
        hashTable[index] = keys[i];
    }

    printf("Hash Table:\n");

    for(int i=0;i<SIZE;i++)
        printf("%d : %d\n", i, hashTable[i]);

    return 0;
}