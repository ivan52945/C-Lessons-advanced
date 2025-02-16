#include <stdio.h>

typedef struct tree {
    int key;
    struct tree *left, *right;
} tree;

typedef struct {
    tree *node;
    int hor_dist;
} queue_item_t;

void btUpView(tree *root) {
    if (root == NULL) return;

    int hor_dist;
    int min_hor_dist = 0, max_hor_dist = 0;
    tree* hor_dist_table[1000] = {NULL};

    queue_item_t queue[1000];
    int front = 0, rear = 0;

    queue[rear].node = root;
    queue[rear].hor_dist = 0;
    rear++;

    while (front < rear) {
        queue_item_t current = queue[front];
        front++;

        hor_dist = current.hor_dist;
        tree* node = current.node;

        if (hor_dist_table[hor_dist + 500] == NULL) {
            hor_dist_table[hor_dist + 500] = node;
            if (hor_dist < min_hor_dist) min_hor_dist = hor_dist;
            if (hor_dist > max_hor_dist) max_hor_dist = hor_dist;
        }

        if (node->left != NULL) {
            queue[rear].node = node->left;
            queue[rear].hor_dist = hor_dist - 1;
            rear++;
        }

        if (node->right != NULL) {
            queue[rear].node = node->right;
            queue[rear].hor_dist = hor_dist + 1;
            rear++;
        }
    }

    for (int i = min_hor_dist; i <= max_hor_dist; i++) {
        if (hor_dist_table[i + 500] != NULL) {
            printf("%d ", hor_dist_table[i + 500]->key);
        }
    }
    printf("\n");
}