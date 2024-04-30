/*
-------------------------------------
File:    bst.c
Project: a7
file description
-------------------------------------
Author:  Anousheh Shahid
ID:      210179080
Email:   shah9080@mylaurier.ca
Version  2023-03-08
-------------------------------------
*/
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

// you can add auxiliary function for the insert and delete operations

TNODE *new_node(char *name, float score) {
    TNODE *node = malloc(sizeof(TNODE));
    if (node == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for new node\n");
        return NULL;
    }
    strcpy(node->data.name, name);
    node->data.score = score;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void clean_tree(TNODE **rootp) {
    if (*rootp != NULL) {
        clean_tree(&(*rootp)->left);
        clean_tree(&(*rootp)->right);
        free(*rootp);
        *rootp = NULL;
    }
}


TNODE *search(TNODE *root, char *name) {
    if (root == NULL) {
        return NULL;
    }
    int cmp = strcmp(name, root->data.name);
    if (cmp < 0) {
        return search(root->left, name);
    } else if (cmp > 0) {
        return search(root->right, name);
    } else {
        return root;
    }
}

void insert(TNODE **rootp, char *name, float score) {
    if (*rootp == NULL) {
        *rootp = new_node(name, score);
    } else {
        int cmp = strcmp(name, (*rootp)->data.name);
        if (cmp < 0) {
            insert(&(*rootp)->left, name, score);
        } else if (cmp > 0) {
            insert(&(*rootp)->right, name, score);
        } else {
            fprintf(stderr, "Error: Duplicate record with name %s\n", name);
        }
    }
}

void delete(TNODE **rootp, char *name) {
    if (*rootp == NULL) {
        fprintf(stderr, "Error: Record with name %s not found in tree\n", name);
    } else {
        int cmp = strcmp(name, (*rootp)->data.name);
        if (cmp < 0) {
            delete(&(*rootp)->left, name);
        } else if (cmp > 0) {
            delete(&(*rootp)->right, name);
        } else {
            TNODE *temp;
            if ((*rootp)->left == NULL) {
                temp = *rootp;
                *rootp = (*rootp)->right;
                free(temp);
            } else if ((*rootp)->right == NULL) {
                temp = *rootp;
                *rootp = (*rootp)->left;
                free(temp);
            } else {
                temp = (*rootp)->right;
                while (temp->left != NULL) {
                    temp = temp->left;
                }
                (*rootp)->data = temp->data;
                delete(&(*rootp)->right, temp->data.name);
            }
        }
    }
}