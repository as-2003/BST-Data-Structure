/*
-------------------------------------
File:    bst.h
Project: a7
file description
-------------------------------------
Author:  Anousheh Shahid
ID:      210179080
Email:   shah9080@mylaurier.ca
Version  2023-03-08
-------------------------------------
*/
#ifndef BST_H
#define BST_H

typedef struct record {
  char name[40];
  float score;
} RECORD;

typedef struct tnode {
    RECORD data;
    struct tnode *left;
    struct tnode *right;
} TNODE;

/* create new node with given name and score */
TNODE *new_node(char *name, float score);

/* clean the tree */
void clean_tree(TNODE **rootp);

/* search bst by data.name */
TNODE *search(TNODE *root, char *name); 

/* insert record (name, score) into bst using data.name as key */
void insert(TNODE **rootp, char *name, float score); 

/* delete node of data.name from bst */
void delete(TNODE **rootp, char *name);  

#endif