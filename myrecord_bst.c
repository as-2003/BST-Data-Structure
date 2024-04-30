/*
-------------------------------------
File:    myrecord_bst.c
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
#include <math.h>
#include "queue_stack.h"
#include "bst.h"
#include "myrecord_bst.h"

void add_data(BST *bst, STATS *stats, char *name, float score) {
  // your implementation
  if(search(bst->root, name) == NULL){
    insert(&(bst->root), name, score);
    int n = stats->count;
    stats->count += 1;
    float mean = stats->mean;
    stats->mean = ((float)1/((float)n+(float)1))*((float)n*(float)mean + score);
    float stddev = stats->stddev;
    stats->stddev = sqrtf(((float)1/((float)n+(float)1))*((float)n*(stddev*stddev + mean*mean)+(score*score))-(stats->mean*stats->mean));
  }
}

void remove_data(BST *bst, STATS *stats, char *name) {
  // your implementation 
  TNODE *p = search(bst->root, name);
  if(p !=NULL){
    float score = p->data.score;
    delete(&(bst->root), name);
    int count = stats->count;
    float mean = stats->mean;
    float stddev = stats->stddev;
    stats->count = count - 1;
    stats->mean = ((float)1/(float)(stats->count))*((float)count*mean - score);
    stats->stddev = sqrtf(((float)1/(float)(stats->count))*((float)count*(stddev*stddev + mean*mean) - (score*score))-(stats->mean*stats->mean));
  }
}
