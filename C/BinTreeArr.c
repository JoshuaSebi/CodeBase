#include <stdio.h>
int a[15];

void createBin(int root, int i)
{
    a[i]=root;
    int opt;
    int data;
    printf("Left child? (1 for Yes, 0 for No): ");
    scanf("%d",&opt);
    if(opt==1)
    {
        printf("Enter left child of %d: ", root);
        scanf("%d",&data);
        createBin(data,(2*i+1));
    }
    printf("Right child? (1 for Yes, 0 for No): ");
    scanf("%d",&opt);
    if(opt==1)
    {
        printf("Enter right child of %d: ", root);
        scanf("%d",&data);
        createBin(data,(2*i+2));
    }
}

void preorder(int i)
{
    if(i>=15||a[i]==-1){
        return;
    }
    printf("%d\t",a[i]);
    preorder(2*i+1);
    preorder(2*i+2);
}

void postorder(int i)
{
    if(i>=15||a[i]==-1){
        return;
    }
    postorder(2*i+1);
    postorder(2*i+2);
    printf("%d\t",a[i]);
}

void inorder(int i)
{
    if(i>=15||a[i]==-1){
        return;
    }
    inorder(2*i+1);
    printf("%d\t",a[i]);
    inorder(2*i+2);
}

void creation()
{
    for (int i=0;i<15;i++)
    {
        a[i]=-1;
    }
    int data;
    printf("Enter Root data: ");
    scanf("%d",&data);
    createBin(data,0);
}

void main()
{
    int c;
    char ch;
    do
    {
        printf("The operations are \n");
        printf("1.Creation\n2.Preorder\n3.Inorder\n4.Postorder\n");
        printf("Enter your choice :");
        scanf("%d",&c);
        switch(c){
            case 1:
                creation();
                break;
            case 2:
                preorder(0);
                break;
            case 3:
                inorder(0);
                break;
            case 4:
                postorder(0);
                break;
            default:
                printf("Invalid entry");
    }
    printf("\nDo you want to continue (y/n) ? :");
    scanf(" %c",&ch);
    }
    while(ch=='y'||ch=='Y');
}