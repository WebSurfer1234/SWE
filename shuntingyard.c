#include <stdio.h>
typedef struct element {
    int value;
    struct element * right;
    struct element * left;
} Element;

int insert(Element * element, int value) {
    if(element->value == value) {
        return 0;
    } else {
        if(element->value < value) {
            if(element->right != NULL) {
                return insert(element->right, value);
            } else {
                Element * newElement = malloc(sizeof(Element));
                newElement->left = NULL;
                newElement->right = NULL;
                newElement->value = value;
                element->right = newElement;
                return 1;
            }
        } else {
            if(element->left != NULL) {
                return insert(element->left, value);
            } else {
                Element * newElement = malloc(sizeof(Element));
                newElement->left = NULL;
                newElement->right = NULL;
                newElement->value = value;
                element->left = newElement;
                return 1;
            }
        }
    }
}

void print(Element * node) {
    if(node->left != NULL) {
        print(node->left);
    } else {
        printf("%d", node->value);
        if(node->right != NULL) {
            print(node->right);
        }
    }
}
int main() {
    int size = 0;
    Element * root = malloc(sizeof(Element));
    root->left = NULL;
    root->right = NULL;
    root->value = 100;
    printf("Unsortiert: ");
    int i;
    for(i = 0; i < 10; i++) {
        int val =  rand() % 200 + 1;
        printf("%d", val);
        insert(root, val);
    }
    print(root);
    printf("\n\nSortiert: ");
    return 0;
}
