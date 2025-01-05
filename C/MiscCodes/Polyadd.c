#include <stdio.h>

struct polyadd{
    int coeff;
    int expo;
} poly[30];

int inp(int a, int b)
{
    for(a;a<b;a++)
    {
        printf("Power= ");
        scanf("%d",&poly[a].expo);
        printf("Coefficient= ");
        scanf("%d",&poly[a].coeff);
    }
}

int disp(int a, int b)
{
    for(a;a<b;a++)
    {
        printf("%dx^%d\n",poly[a].coeff,poly[a].expo);
    }
}


int addn(int a,int b,int c, int d,int e)
{
    while (a<b && c<d)
    {
        if (poly[a].expo>poly[c].expo)
        {
            poly[e].expo=poly[a].expo;
            poly[e].coeff=poly[a].coeff;
            a++;
        }
        else if (poly[a].expo<poly[c].expo)
        {
            poly[e].expo=poly[c].expo;
            poly[e].coeff=poly[c].coeff;
            c++;
        }
        else if(poly[a].expo==poly[c].expo)
        {
            poly[e].coeff=poly[a].coeff+poly[c].coeff;
            poly[e].expo=poly[a].expo;       
            a++;
            c++;
        }
        
    e++;
    }

    // Copy remaining elements of poly A
    while (a < b) {
        poly[e].expo = poly[a].expo;
        poly[e].coeff = poly[a].coeff;
        a++;
        e++;
    }

    // Copy remaining elements of poly B
    while (c < d) {
        poly[e].expo = poly[c].expo;
        poly[e].coeff = poly[c].coeff;
        c++;
        e++;
    }

    return e;
}
   
int main() 
{
    int startA=0,stopA;
    printf("Enter Number of Elements of A(x)=");
    scanf("%d",&stopA);
    inp(startA,stopA);
    printf("----------------------------\n");
    disp(startA,stopA);
    //-----------------------------
    int stopB;
    printf("Enter Number of Elements of B(x)=");
    scanf("%d",&stopB);
    stopB+=stopA;
    int startB=stopA;
    inp(startB,stopB);
    printf("----------------------------\n");
    disp(startB,stopB);
    //-----------------------
    int startC=stopB;
    int stopC=addn(startA,stopA,startB,stopB,startC);
    printf("Sum of Polynomials\n ");
    disp(startC,stopC);
}