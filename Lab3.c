#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define max(a, b) a > b ? a : b

typedef struct node{
    struct node *left;
    struct node *right;
    struct node *par;
    int key;
}NODE;

NODE *CREATE(int broj){
    NODE *new = (NODE*)malloc(sizeof(NODE));
    new->right = new->left = 0;
    new->key = broj;
    return new;
}

void BST_INSERT(NODE *new, NODE **root){
    NODE *p = *root;
    if ( p == 0 ){
        *root = new;
    }else{
        if ( new->key == p->key ){
            printf("Postoji ta vrijednost vec!!!\n");
            return;
        }else if ( new->key < p->key ){
            BST_INSERT(new, &p->left);
        }else{
            BST_INSERT(new, &p->right);
        }
    }
}

void WRITE_PREORDER(NODE *root){
    if ( root != 0 ){
        printf("%d\n", root->key);
        WRITE_PREORDER(root->left);
        WRITE_PREORDER(root->right);
    }
}

void WRITE_INORDER(NODE *root){
    if ( root != 0 ){
        WRITE_INORDER(root->left);
        printf("%d\n", root->key);
        WRITE_INORDER(root->right);
    }
}

int bb = 0;

int IS_BALANCED(NODE *root, int height){
    if ( root == 0 ) return height;
    int d1 = IS_BALANCED(root->left, height + 1);
    int d2 = IS_BALANCED(root->right, height + 1);
    if ( abs(d1 - d2) >= 2 ){
        bb = 1;
    }
    return max(d1, d2);
}

void del(NODE *root){
    if ( root != 0 ){
        del(root->left);
        del(root->right);
        free(root);
    }
}

int main(){
    NODE *root = 0;

    int n;
    scanf("%d", &n);

    while (n--){
        int d;
        scanf("%d", &d);
        BST_INSERT(CREATE(d), &root);
    }

    WRITE_PREORDER(root);printf("\n\n");
    WRITE_INORDER(root);

    IS_BALANCED(root, 0);

    if ( !bb ){
        printf("Stablo je balansirano!!!\n");
    }else{
        printf("Stablo nije balansirano!!!\n");
    }

    del(root);
    return 0;
}
