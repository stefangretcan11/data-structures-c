#pragma once

typedef struct node_type
{
    int id;
    struct node_type *left, *right;
    int frecventa;
} NodeT;


void fatalError(const char *msg);
void postorder(NodeT *p);
void inorder(NodeT *p);
int leaf_node(NodeT *node);
int noduri_interne(NodeT *node);
int inaltime(NodeT *node);
void preorder(NodeT *p);
NodeT *createBinTree(int branch, NodeT *parent);
NodeT *createBinTreeFromFile(FILE* f);
NodeT *search(NodeT *root, int key);
void print_path_to_root(NodeT *target, NodeT *current, NodeT *parent);
void inversare_completa(NodeT *root);
void aparitii(NodeT *root, int x);
void destroy_tree(NodeT *root);