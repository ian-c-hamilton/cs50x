// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include "dictionary.h"
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <cs50.h>
#include <ctype.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

//Size of dictionary
int size_dict = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // Use strcasecomp to compare the two strings, ingnoring case

    // hash the word first to get the value
    int hashval = hash(word);

    // Get the head node at the location of the hash value in the hash table
    node *n = table[hashval];

    // Compare each word at the node and if it is not equal, move on to the next node
    while (n != NULL)
    {
        if (strcasecmp(word, n->word) == 0)
        {
            return true;
        }

        n = n->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    // Simple hash function that returns the index of the first letter of the word, i.e, A = 0, B = 1
    char lower = tolower(word[0]);
    int index = lower - 97;
    return index;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *dict = fopen(dictionary, "r");

    if (dictionary == NULL)
    {
        printf("Unable to open dictionary file");
        return false;
    }
    // Each word or line of the dictionary cannot be greater than the max length (46)
    char line[46];
    while (fscanf(dict, "%s", line) != EOF)
    {
        // Allocate memory for the new node which is an entry into the dictionary
        node *entry = malloc(sizeof(node));
        // If there is not enought memory, return false
        if (entry == NULL)
        {
            return false;
        }
        // Copy the dictionary line into the word field of the entry node
        strcpy(entry->word, line);

        // Hash the line of the dictionary to determine its entry point on the hash table
        int hashval = hash(line);

        // Put the dictionary line into the hash table at its hash value
        entry->next = table[hashval];
        table[hashval] = entry;
        size_dict++;

    }
    // Close the dictionary file
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    // Return the size of the disctionary
    return size_dict;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    // For each letter in the alphabet (26 head nodes), loop through each linked list, freeing every node after keeping track of the pointer to the next node
    for (int i = 0; i < N; i++)
    {
        // Create a pointer to the node before deleting it
        node *p = table[i];

        // Loop through each node starting with the head
        while (p != NULL)
        {
            // Create a temporary node so as to not strand the rest of the linked list
            node *temp = p;
            p = p->next;
            free(temp);
        }
        // Return true if every linked list has been cleared
        if (p == NULL && i == N - 1)
        {
            return true;
        }
    }
    return false;
}
