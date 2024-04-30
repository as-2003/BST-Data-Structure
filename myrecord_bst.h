/*
-------------------------------------
File:    myrecord_bst.h
Project: a7
file description
-------------------------------------
Author:  Anousheh Shahid
ID:      210179080
Email:   shah9080@mylaurier.ca
Version  2023-03-08
-------------------------------------
*/
#ifndef MYRECORD_BST_H
#define MYRECORD_BST_H

typedef struct {
  TNODE *root;
} BST;

typedef struct {
  int count;
  float mean;
  float stddev;
  float median;
} STATS;

void add_data(BST *bst, STATS *stats, char *name, float score);
void remove_data(BST *bst, STATS *stats, char *name);
#endif