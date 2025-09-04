#include <stdio.h>
#include <stdlib.h>
#include "trees.h"

int main() {
    NodeT *root;
    FILE *f = fopen("ArboreBinar.txt", "r");
    if (!f) {
        printf("Nu se poate deschide fisierul ArboreBinar.txt\n");
        return -1;
    }

    root = createBinTreeFromFile(f);
    fclose(f);

    if (!root) {
        printf("Arborele nu a putut fi creat\n");
        return -1;
    }

    printf("Parcurgere in preordine: ");
    preorder(root);
    printf("\n");

    printf("Parcurgere in postordine: ");
    postorder(root);
    printf("\n");

    printf("Parcurgere in inordine: ");
    inorder(root);
    printf("\n");

    int nr_frunze = leaf_node(root);
    printf("Numarul de frunze este %d\n", nr_frunze);

    printf("Noduri interne = %d\n", noduri_interne(root));

    printf("Inaltimea arborelui = %d\n", inaltime(root));

    NodeT *q = search(root, 6);
    if (q != NULL) {
        printf("Nodul 6 a fost gasit la inaltimea %d\n", inaltime(q));
        print_path_to_root(q, root, NULL);
        printf("\n");
    } else {
        printf("Nodul 6 nu a fost gasit\n");
    }

    printf("Inversarea arborelui...\n");
    inversare_completa(root);

    printf("Parcurgere in preordine dupa inversare: ");
    preorder(root);
    printf("\n");

    destroy_tree(root);

    return 0;
}