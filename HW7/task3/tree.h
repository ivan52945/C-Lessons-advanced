typedef struct tree {
    int key;
    struct tree* left, * right;
    struct tree* parent;
} tree;

tree* findBrother(tree* root, int key);