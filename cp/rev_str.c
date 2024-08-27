#include <stdio.h>

char revstr(char s[])
{
        int len=0,i=0;
        char temp;
        while (s[i]!='\0')
        {
            i++;
            len++;
        }
        for (i=0;i<(len/2);i++)
        {
            temp=s[i];
            s[i]=s[len-1-i];
            s[len-1-i]=temp;
        }
        
}



int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    revstr(str);
     printf("Reversed string: %s\n", str);
    return 0;
}