#include <stdio.h>
#include <stdlib.h>

struct poly {
    int coeff,expo;
    struct poly *next;
};
struct poly *newnode=NULL;
struct poly *pA=NULL,*pAend=NULL,*pB=NULL,*pBend=NULL,*pa=NULL,*paend=NULL,*pm=NULL,(*pmend)=NULL;

struct poly *create(int c, int e)
{
    struct poly *temp=(struct poly*)malloc(sizeof(struct poly));
    temp->coeff=c;
    temp->expo=e;
    return temp;
}

void insert(struct poly **p,struct poly **current, int c, int e)
{
    newnode=create(c,e);
    if (*p==NULL)
        *p=*current=newnode;
    else
    {
        (*current)->next=newnode;
        *current=newnode;
    }
        
}

struct poly* createPoly(int t)
{
    struct poly *p=NULL,*current=NULL;
    printf("Enter Coeff and Power: \n");
    for(int i=0;i<t;i++)
    {
        int c,e;
        scanf("%d%d",&c,&e);
        newnode=create(c,e);
        if (p==NULL )
            p=current=newnode;
        else
        {
            (current)->next=newnode;
            current=newnode;
        }
    }
    return p;
}

void display(struct poly *p)
{
    printf("\t");
    while(p->next!=NULL)
    {
        printf("%d(x^%d)+ ",p->coeff,p->expo);
        p=p->next;
    }
    printf("%d(x^%d)\n\n",p->coeff,p->expo);
}

struct poly* polyAdd(struct poly *p1, struct poly *p2)
{
    int c, e;
    struct poly *pr=NULL,*prend=NULL;
    while(p1!=NULL && p2!=NULL)
    {
        if(p1->expo==p2->expo)
        {
            c=p1->coeff+p2->coeff;
            e=p1->expo;
            insert(&pr,&prend,c,e);
            p1=p1->next;
            p2=p2->next;
        }
        else if((p1->expo)>(p2->expo))
        {
            c=p1->coeff;
            e=p1->expo;
            insert(&pr,&prend,c,e);
            p1=p1->next;
        }
        else
        {
            c=p2->coeff;
            e=p2->expo;
            insert(&pr,&prend,c,e);
            p2=p2->next;
        }
    }
    while(p1!=NULL)
    {
        c=p1->coeff;
        e=p1->expo;
        insert(&pr,&prend,c,e);
        p1=p1->next;
    }
    while(p2!=NULL)
    {
        c=p2->coeff;
        e=p2->expo;
        insert(&pr,&prend,c,e);
        p2=p2->next;
    }
    return pr;
}

void polyMult(struct poly *p1, struct poly *p2)
{
    int c, e;
    struct poly *temp=p2;
    while(p1!=NULL)
    {
        struct poly *intermediate=NULL,*intermediateEnd=NULL;
        p2=temp;
        while(p2!=NULL)
        {
            c=(p1->coeff)*(p2->coeff);
            e=(p1->expo)+(p2->expo);
            insert(&intermediate,&intermediateEnd,c,e);
            p2=p2->next;
        }
        pm=polyAdd(pm,intermediate);
        p1=p1->next;
    }
}

int main() {
    int ch,t1,t2;
    printf(" 1. Create Poly \n 2. Add Poly \n 3. Multiply Poly \n 4. Exit  ");
    do
    {
        printf("\nEnter Option :: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter number of Poly1 terms: ");
                scanf("%d",&t1);
                pA=createPoly(t1);
                display(pA);
                printf("Enter number of Poly2 terms: ");
                scanf("%d",&t2);
                pB=createPoly(t2);
                display(pB);
                printf("\n");
                break;
            case 2:
                pa=polyAdd(pA,pB);
                printf("\n    Polinomial Sum : ");
                display(pa);
                printf("\n");
                break;
            case 3:  
                polyMult(pA,pB);
                display(pm);
                printf("\n");
                break;
            case 4:
                exit(0);
            default :
                printf("\n    Invalid Option !!!");
        }
    }
    while(1);
}
        