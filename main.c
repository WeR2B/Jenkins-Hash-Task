#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "jhash.h"

struct node {
    short rep;
    char value;
    short length;
    bool printed;
    uint32_t hash;
    struct node* next;
    struct node* prev;
};

void append_value(struct node **head, char value, short length) {
    struct node *last_node = *head;
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->value = value;
    new_node->length = length;
    new_node->next = NULL;
    new_node->prev = NULL;

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

void hash_words(struct node *head) {
    char word[100];
    short i = 0;
    struct node *temp = head;

    while (temp != NULL) {
        if (temp->length == 0) {
            word[i] = temp->value;
            i++;
        } else {
            temp->hash = jhash(word, temp->length, JHASH_INITVAL);
            i = 0;
        }
        temp = temp->next;
    }
}

void detect_repeating_hashes(struct node *head) {
    struct node *current = head;

    while (current != NULL) {
        struct node *previous = current->prev;

        while (previous != NULL) {
            if (current->hash == previous->hash) {
                current->rep += 1;
                current->printed = false;
            }
            previous = previous->prev;
        }

        current = current->next;
    }
}

void print_list(struct node *head) {
    struct node *temp = head;

    while (temp != NULL) {
        if (temp->value != 10) {
            printf("%c", temp->value);
        } else {
            printf("\t:  %d\n", temp->rep + 1);
        }
        temp = temp->next;
    }
}

void free_memory(struct node *head) {
    struct node *temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    struct node *head = NULL;
    char input;
    short word_length = 0;
    bool space_flag = false;

    while ((input = getchar()) != EOF) {
        if ((input >= 65 && input <= 90) || (input >= 97 && input <= 122)) {
            word_length++;
            append_value(&head, input, 0);
            space_flag = false;
        } else if ((input == 32 || input == 10) && !space_flag) {
            space_flag = true;
            append_value(&head, 10, word_length);
            word_length = 0;
        }
    }

    hash_words(head);
    detect_repeating_hashes(head);
    print_list(head);
    free_memory(head);

    return 0;
}