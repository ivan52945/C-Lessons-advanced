#include "tree.h"
#include "stdio.h"

typedef enum {
    LEFT,
    RIGHT,
} dir_t;

tree * findBrother(tree *root, int key)
{
    tree* p = root;
    dir_t come_from;

    if(p->key == key)
        return NULL;

    while(p != NULL){
        if(p->key > key) {
            p = p->left;
            come_from = LEFT;
        }
        else if(p->key < key){
            p = p->right;
            come_from = RIGHT;
        }
        else
            break;
    }
    if(p != NULL){
        switch (come_from) {
            case LEFT:
                return p->parent->right;
            case RIGHT:
                return p->parent->left;
        }
    }
    return NULL;
}