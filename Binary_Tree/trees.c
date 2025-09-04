#include<stdio.h>
#include <stdlib.h>
#include "trees.h"

void fatalError(const char *msg)
{
    printf("%s\n", msg);
    exit(1);
}

void postorder(NodeT *p) {
    if (p != NULL) {
        postorder(p->left);
        postorder(p->right);
        printf("%d ", p->id);
    }
}

void inorder(NodeT *p) {
    if (p != NULL) {
        inorder(p->left);
        printf("%d ", p->id);
        inorder(p->right);
    }
}

int leaf_node(NodeT *node) {
    if (node == NULL) return 0;
    if (node->right == NULL && node->left == NULL) return 1;
    return leaf_node(node->left) + leaf_node(node->right);
}

int noduri_interne(NodeT *node) {
    if (node == NULL) return 0;
    if (node->left != NULL || node->right != NULL) {
        return 1 + noduri_interne(node->left) + noduri_interne(node->right);
    }
    return 0;
}

int inaltime(NodeT *node) {
    if (node == NULL) return -1;
    int left_height = inaltime(node->left);
    int right_height = inaltime(node->right);
    return 1 + (left_height > right_height ? left_height : right_height);
}

void preorder(NodeT *p) {
    if (p != NULL) {
        printf("%d ", p->id);
        preorder(p->left);
        preorder(p->right);
    }
}

NodeT *createBinTree(int branch, NodeT *parent) {
    NodeT *p;
    int id;

    if (branch == 0)
        printf("Valoarea pentru radacina [0 pt null] = ");
    else if (branch == 1)
        printf("Fiul stang al nodului cu valoarea %d [0 pt null] = ", parent->id);
    else
        printf("Fiul drept al nodului cu valoarea %d [0 pt null] = ", parent->id);

    scanf("%d", &id);

    if (id == 0)
        return NULL;
    else {
        p = (NodeT *)malloc(sizeof(NodeT));
        if (p == NULL) {
            fatalError("Nu mai avem memorie in createBinTree");
        }
        p->id = id;
        p->frecventa = 1;
        p->left = createBinTree(1, p);
        p->right = createBinTree(2, p);
    }
    return p;
}

NodeT *createBinTreeFromFile(FILE* f) {
    int x;
    if (fscanf(f, "%d", &x) != 1) return NULL;

    if (x == 0) return NULL;
    else {
        NodeT *q = calloc(1, sizeof(NodeT));
        if (!q) {
            fatalError("Nu se poate aloca memoria pentru nod");
        }
        q->id = x;
        q->frecventa = 1;
        q->left = createBinTreeFromFile(f);
        q->right = createBinTreeFromFile(f);
        return q;
    }
}

NodeT *search(NodeT *root, int key) {
    if (root == NULL) return NULL;
    if (root->id == key) return root;

    NodeT *left_result = search(root->left, key);
    if (left_result != NULL) return left_result;

    return search(root->right, key);
}

void print_path_to_root(NodeT *target, NodeT *current, NodeT *parent) {
    if (current == NULL) return;

    if (current == target) {
        printf("Drumul catre radacina: %d ", current->id);
        return;
    }

    if (search(current->left, target->id) != NULL) {
        print_path_to_root(target, current->left, current);
        printf("%d ", current->id);
    } else if (search(current->right, target->id) != NULL) {
        print_path_to_root(target, current->right, current);
        printf("%d ", current->id);
    }
}

void inversare_completa(NodeT *root) {
    if (root == NULL) return;

    NodeT *temp = root->left;
    root->left = root->right;
    root->right = temp;

    inversare_completa(root->left);
    inversare_completa(root->right);
}

void aparitii(NodeT *root, int x) {
    if (root == NULL) return;
    if (root->id == x) root->frecventa++;
    aparitii(root->left, x);
    aparitii(root->right, x);
}

void destroy_tree(NodeT *root) {
    if (root != NULL) {
        destroy_tree(root->left);
        destroy_tree(root->right);
        free(root);
    }
}
