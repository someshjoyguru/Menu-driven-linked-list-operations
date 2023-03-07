// preprocessing header files
#include <stdio.h>  //for standard input and output operations
#include <stdlib.h> //for using malloc function for dynamic memory allocation
#include <string.h> //to perform operations on strings

// declared all functions and structures to avoid errors
typedef struct node node;
node *create(int);
node *insertlast(node *, node *);
node *insertbegin(node *, node *);
node *insertanyposition(node *, node *, int);
node *deletelast(node *);
node *deletebegin(node *);
node *deleteanyposition(node *);
void printLinkedlist(node *);

// structure defined here
struct node
{
    int value;
    struct node *next;
};

// node creation
node *create(int n)
{
    node *p = (node *)malloc(sizeof(node));
    p->value = n;
    p->next = NULL;
    return p;
}

// linked list functions

// 1.insert last function
node *insertlast(node *c, node *l)
{
    node *temp = l;
    node *prev = l;
    if (l == NULL)
    {
        l = c;
    }
    else
    {
        while (temp != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = c;
    }
    printLinkedlist(l);
    return l;
}

// 2.insert begin function
node *insertbegin(node *c, node *l)
{
    if (l == NULL)
    {
        l = c;
    }
    else
    {
        node *temp = l;
        l = c;
        l->next = temp;
    }
    printLinkedlist(l);
    return l;
}

// 3.insert at any position function
node *insertanyposition(node *c, node *l, int p)
{
    node *temp = l;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    if (p > count)
    {
        printf("position is greater than number of counts.\n");
    }
    else
    {
        temp = l;
        node *prev = l;
        for (int i = 0; i < p - 1; i++)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = c;
        c->next = temp;
    }
    printLinkedlist(l);
    return l;
}

// 4.delete last function
node *deletelast(node *l)
{
    node *temp = l;
    node *prev = l;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    if (count == 1)
    {
        free(l);
        l = NULL;
        printLinkedlist(l);
        return l;
    }
    temp=l;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);

    printLinkedlist(l);
    return l;
}

// 5.delete begin function
node *deletebegin(node *l)
{
    node *temp = l;
    node *prev = l;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    if (count == 1)
    {
        free(l);
        l = NULL;
        printLinkedlist(l);
        return l;
    }
    temp = l;
    l = l->next;
    free(temp);
    printLinkedlist(l);
    return l;
}

// 6.delete at any position function
node *deleteanyposition(node *l)
{
    int p = 1;
    printf("enter the position");
    scanf("%d", &p);
    node *temp = l;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    if (p > count)
    {
        printf("position is greater than number of counts.\n");
    }
    else if (p == 1)
    {
        l = deletebegin(l);
    }
    else if (p == count)
    {
        l = deletelast(l);
    }
    else
    {
        temp = l;
        node *prev = l;
        for (int i = 0; i < p - 1; i++)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        free(temp);
        printLinkedlist(l);
    }
    return l;
}

// 7.print linked list function
void printLinkedlist(node *l)
{
    node *temp = l;
    while (temp != NULL)
    {
        printf("%d->", temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
    return;
}

int main()
{
    printf("Name : Somesh Ghosh\n");
    printf("Reg. No. : 2022UGEC013\n");
    node *l = NULL;
    node *x = NULL;
    int c, n, i = 1;
    char p[4];
    char y[] = "y";
    char Y[] = "Y";
    int k, q, m;
    while (i == 1)
    {
        printf("enter your choice\t1:INSERT\t2.DELETE\n");
        scanf("%d", &c);
        if (c == 1)
        {
            printf("enter number\n");
            scanf("%d", &n);
        }
        switch (c)
        {
        case 1:
            if (l == NULL)
            {
                x = create(n);
                l = insertlast(x, l);
                break;
            }
            else
            {
                printf("enter the choice for inserting\t1:BEGIN\t2:LAST\t3:any position");
                scanf("%d", &k);
                switch (k)
                {
                case 1:
                    x = create(n);
                    l = insertbegin(x, l);
                    break;
                case 2:
                    x = create(n);
                    l = insertlast(x, l);
                    break;
                case 3:
                    printf("enter the position");
                    scanf("%d", &q);
                    x = create(n);
                    l = insertanyposition(x, l, q);
                    break;
                default:
                    printf("WRONG CHOICE\n");
                    break;
                }
            }
            break;

        case 2:
            if (l == NULL)
            {
                printf("no element to delete");
                break;
            }
            else
            {
                printf("enter the choice for deleting\t1:BEGIN\t2:LAST\t3:any position");
                scanf("%d", &m);
                switch (m)
                {
                case 1:
                    l = deletebegin(l);
                    break;
                case 2:
                    l = deletelast(l);
                    break;
                case 3:
                    l = deleteanyposition(l);
                    break;
                default:
                    printf("WRONG CHOICE\n");
                    break;
                }
            }
            break;
        default:
            printf("WRONG CHOICE");
        }
        printf("DO YOU WANT TO CONTINUE press Y or y for continue : ");
        scanf("%s", p);
        i = 0;
        if ((!strcmp(y, p)) | (!strcmp(Y, p)))
        {
            i = 1;
        }
    }
    return 0;
}