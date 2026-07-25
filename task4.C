#include <stdio.h>

#define SIZE 10

int table[SIZE];

int hash(int key) {
    return key % SIZE;
}

int main() {
    for(int i=0;i<SIZE;i++)
        table[i]=-1;

    int keys[] = {15,25,35,45};

    for(int i=0;i<4;i++) {

        int index = hash(keys[i]);

        while(table[index]!=-1)
            index=(index+1)%SIZE;

        table[index]=keys[i];
    }

    printf("Hash Table:\n");

    for(int i=0;i<SIZE;i++)
        printf("%d -> %d\n",i,table[i]);

    return 0;
}