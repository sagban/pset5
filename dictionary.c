/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>

#include "dictionary.h"


// hash table
typedef struct node
{
    char word[46];
    struct node* next;
}node;

node* hashtables[26];

/**
 * hash function
 */
  unsigned int hashf(const char* val)
  {
      return val[0] % 97;
  }
  
/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    node* cursor =  hashtables[hashf(word)];
    printf("saghar2\n");
    while(cursor != NULL)
    {
        printf("saghar44\n");
        
        for(int i=0;i<strlen(cursor -> word);i++)
        {
            putchar(tolower(cursor -> word[i]));
        }
        int a = strcmp(word,cursor -> word);
        if(a==0)
        {
            return true;
        }
        cursor = cursor -> next;
    }
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    FILE* inptr = fopen(dictionary,"r");
    if(inptr==NULL)
    {
        return false;
    }
    
    // initialized the hash function
    else
    {
        node* new_word;
        new_word = malloc(sizeof(node));
        
        for(int b=0;b<=25;b++)
        {
            hashtables[b] = NULL;
        }
    
        while(fscanf(inptr, "%s", new_word -> word) != EOF)
        {
            int x = hashf(new_word -> word);
            if(hashtables[x] == NULL)
            {
                hashtables[x] = malloc(sizeof(node));
            }
            printf("2cjdcd");
            node* cursor = hashtables[x];
            while(cursor -> next != NULL)
            {
                cursor = cursor -> next;
            }
            new_word -> next = cursor -> next;
            cursor -> next = new_word;
           
        }
        return true;
    }

}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    int count =0;
    for(int i=0;i<26;i++)
    {
        node* crawler = hashtables[i];
        while(crawler -> next != NULL)
        {
            count++;
            crawler = crawler -> next;
        }
    }
    return count;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    return false;
}
