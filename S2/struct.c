#include <stdio.h>

struct employee
{
        char name[50];
        int age, sal;
};
struct employee  emp[50];



int main() 
{
    int n,i=0;
    printf("Enter number of employees: ");
    scanf("%d", &n);
    printf("-----------------------\n ");
    for (i=0;i<n;i++)
    {
            printf("Enter employee name: ");
            scanf("%s",emp[i].name);
            printf("Enter employee age: ");
            scanf("%d",&emp[i].age);
            printf("Enter employee salary: ");
            scanf("%d",&emp[i].sal);
            printf("-----------------------\n ");
    }
    printf("++Employee Data++\n");
    printf("%-10s%-8s%-8s\n", "Name", "Age", "Salary");    
    for (i=0;i<n;i++)
    {
            printf("%-10s%-8d%-8d\n",emp[i].name,emp[i].age,emp[i].sal);
    }
    printf("-----------------------\n ");
    return 0;
}