#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *p = NULL, *tmp, *tmp1;

void insert_end(int element);
void insert_beg(int element);
void delete_end();
void delete_beg();
void display();

int main() {
    int val, n;
    char ch;

    do {
        printf("\n******************* MENU ******************");
        printf("\n1. Insert at END");
        printf("\n2. Insert at BEG");
        printf("\n4. Delete at END");
        printf("\n5. Delete at BEG");
        printf("\n6. Display");
        printf("\n7. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &n);

        switch (n) {
            case 1:
                printf("\nEnter the value to be inserted: ");
                scanf("%d", &val);
                insert_end(val);
                break;

            case 2:
                printf("\nEnter the value to be inserted: ");
                scanf("%d", &val);
                insert_beg(val);
                break;

            case 4:
                delete_end();
                break;

            case 5:
                delete_beg();
                break;

            case 6:
                display();
                break;

            case 7:
                exit(0);

            default:
                printf("\nWrong choice");
        }

        printf("\nDo you want to continue (y/n)? ");
        scanf(" %c", &ch);   // space before %c to ignore newline

    } while (ch == 'y' || ch == 'Y');

    return 0;
}

void insert_end(int element) {
    tmp1 = (struct node *)malloc(sizeof(struct node));
    tmp1->data = element;
    tmp1->next = NULL;

    if (p == NULL) {
        p = tmp1;
    } else {
        tmp = p;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = tmp1;
    }
}

void insert_beg(int element) {
    tmp1 = (struct node *)malloc(sizeof(struct node));
    tmp1->data = element;
    tmp1->next = p;
    p = tmp1;
}

void delete_end() {
    if (p == NULL) {
        printf("\nList is empty");
        return;
    }

    if (p->next == NULL) {
        free(p);
        p = NULL;
        return;
    }

    tmp = p;
    while (tmp->next->next != NULL) {
        tmp = tmp->next;
    }

    free(tmp->next);
    tmp->next = NULL;
}

void delete_beg() {
    if (p == NULL) {
        printf("\nList is empty");
        return;
    }

    tmp = p;
    p = p->next;
    free(tmp);
}

void display() {
    if (p == NULL) {
        printf("\nList is empty\n");
        return;
    }

    tmp = p;
    printf("\nList: ");
    while (tmp != NULL) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}
