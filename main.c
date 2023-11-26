#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "jhash.h"

struct node 
{
    char *word;
    short rep;
    bool printed;
    uint32_t hash;
    struct node *prev;
    struct node *next;
};

void append_value(struct node **head, char *value, uint32_t Hash) {
    struct node *last_node = *head;
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->printed = false;
    new_node->word = strdup(value); // Allocate memory for the word
    new_node->hash = Hash;
    new_node->next = NULL;
    new_node->prev = NULL;
    new_node->rep = 1; // Initialize repetition count to 1 for new words

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    while (last_node->next != NULL) {
        last_node = last_node->next;
    }

    last_node->next = new_node;
    new_node->prev = last_node;
}

void print_words(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        if (temp->rep > 1 && !temp->printed) {
            printf("\t%s\t:\t%d\n", temp->word, temp->rep);
            temp->printed = true;
        }
        temp = temp->next;
    }
}

int main () {
    struct node *head = NULL;
    char char_input;
    short word_length = 0;
    uint32_t current_hash;
    char word[100];
    bool in_word = false;
    bool word_found = false;
    while ((char_input = getchar()) != EOF) {
        if ((char_input >= 65 && char_input <= 90) || (char_input >= 97 && char_input <= 122)) {
            if (!in_word) {
                in_word = true;
                word_length = 0;
            }
            word[word_length] = char_input;
            word_length++;
        } else if (in_word){
            in_word = false;
            word[word_length] = '\0';
            current_hash = jhash(word, word_length, JHASH_INITVAL);
            struct node *temp = head;
            word_found = false;
            while (temp != NULL) {
                if (current_hash == temp->hash && strcmp(word, temp->word) == 0) {
                    temp->rep = temp->rep + 1;
                    word_found = true;
                    break;
                }
                temp = temp->next;
            }
            if (!word_found) {
                append_value(&head, word, current_hash);
            }
        }
    }

    print_words(head);

    struct node *curr = head;
    while (curr != NULL) {
        struct node *temp_free = curr;
        curr = curr->next;
        free(temp_free->word); // Free allocated memory for word
        free(temp_free);
    }
}