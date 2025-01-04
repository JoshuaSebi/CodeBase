#include <stdio.h>
#include <stdlib.h>

struct poly
{
    int coeff;
    int expo;
    struct poly *next; 
};

struct poly *p1=NULL, *p2=NULL, *p3=NULL,*newnode;

struct poly* createnode(int c, int e)
{
    struct poly *term=(struct poly*)malloc(sizeof(struct poly));
    term->coeff=c;
    term->expo=e;
    term->next=NULL;
    return term;
}

void insert_term(struct poly **head,int c,int e)
{
    struct poly *temp=NULL;
    newnode=createnode(c,e);
    //Add beginning
    if (*head==NULL || (*head)->expo < e)
    {
        newnode->next = *head;
        (*head) = newnode;
    }
    else{
        temp=(*head);
        while (temp->next!=NULL && e < temp->expo)
        {
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
}

void create_poly(struct poly **head, int n)
{
    int c,e;
    for (int i=0 ; i<n ; i++)
    {
        printf("Enter Coefficient & Power :: ");
        scanf("%d%d",&c,&e);
        insert_term(head,c,e);
    }
}


void poly_mult(struct poly **result)
{   
    struct poly *temp1=p1,*temp2=p2;
    

}

void display(struct poly *head)
{
    struct poly *current=head;

    if (head==NULL) 
    {
        printf("Polynomial is empty.\n");
        return;
    }
    while (current->next!=NULL)
    {
        printf("%d(x^%d) + ", current->coeff, current->expo);
        current = current->next;
    }
    printf("%d(x^%d)\n", current->coeff, current->expo);
}


int main() {
    int n1,n2;
    printf("Enter number of terms for 1st Polynomial :: ");
    scanf("%d",&n1);
    create_poly(&p1,n1);
    display(p1);
    printf("Enter number of terms for 2nd Polynomial :: ");
    scanf("%d",&n2);
    create_poly(&p2,n2);
    display(p2);
    return 0;
}