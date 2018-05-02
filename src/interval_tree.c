#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

#include "interval_tree.h"
#include "interval_tree_generic.h"
#include "rbtree.h"

#define START(node) ((node)->start)
#define LAST(node)  ((node)->last)

INTERVAL_TREE_DEFINE(struct interval_tree_node, rb,
                     unsigned long, __subtree_last,
                     START, LAST,, interval_tree)

/* This should be added to the interval_tree_generic.h I guess. - EBS */


void interval_tree_free(const struct rb_root *root){

  struct rb_node *rb_node;
  struct rb_node *temp;
  struct interval_tree_node *it_node;

  rb_node = rb_first_postorder(root);
  temp = rb_node;

  /* printf("We are in interval_tree_free\n"); */
  do {
    it_node = rb_entry(temp, struct interval_tree_node, rb);
    free(it_node);
    /* printf("Freeing it node (%lu, %lu, %d)\n", it_node->start, it_node->last, it_node->val); */

    rb_node = rb_next_postorder(rb_node);
    /* free(it_node); */
    /* it_node = rb_entry(rb_node, struct interval_tree_node, rb); */
    /* printf("Next it node (%lu, %lu, %d)\n", it_node->start, it_node->last, it_node->val); */
    temp = rb_node;
  } while (rb_node);

}
