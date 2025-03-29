/*
Implementation of static hash table with Linear Probing
*/

#include <stdio.h>

#define KEY 10

int getKey(int data)
{
    return data % KEY;
}

void insert(int table[KEY], int key, int data)
{
    if (table[key] == -1)
    {
        table[key] = data;
    }
    else
    {
        printf("\nCollision occured at %d\n", key);
        insert(table, key + 1, data);
    }
}

void main()
{
    int table[KEY];
    int data;

    for (int i = 0; i < KEY; i++)
        table[i] = -1;

    while (1)
    {
        printf("\nEnter element: ");
        scanf("%d", &data);
        int key = getKey(data);
        insert(table, key, data);

        printf("\n");
        for (int i = 0; i < KEY; i++)
        {
            printf("%d\t%d\n", i, table[i]);
        }
    }
}