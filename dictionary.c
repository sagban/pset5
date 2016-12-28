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

node* hashtables[26] = {NULL};

/**
 * hash function
 */
  unsigned int hashf(const char* val)
  {
      return val[0] % 97;
  }
  

  // initilized the counter
  int dictsize = 0;
/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    
    if(hashf(word)>25)
    {
        return false;
    }
    node* cursor =  hashtables[hashf(word)];

     char temp[46];
    for(int i=0;i< strlen(word);i++)
    {
        temp[i] = tolower(word[i]);
    }
    temp[strlen(word)]='\0';
    while(cursor != NULL)
    {
        if(strcmp(temp,cursor -> word) == 0)
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
        
        while(fscanf(inptr, "%s\n", new_word -> word) != EOF)
        {
            dictsize ++;
            int x = hashf(new_word -> word);
            if(x>25)
            {
                return false;
            }
            if(hashtables[x] == NULL)
            {
                hashtables[x] = new_word;
                new_word -> next = NULL;
            }
            else
            {
                node* head = hashtables[x];
                new_word -> next = head;
                head = new_word;
            }
            
           
        }
        fclose(inptr);
        return true;
    }

}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return dictsize;
}


/**
 * this function helps in unload dictionary
 * by reccursion
 */
 void del(node* head)
 {
     node* cursor = head;
     if(cursor -> next == NULL)
     {
         free(cursor);
     }
     else
     {
         del(cursor -> next);
     }
     
 }
 

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    for(int a=0;a<26;a++)
    {
        node* head = hashtables[a];
        del(head);
    }
    return true;
}
