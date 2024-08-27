#include <stdio.h>

int main()
{
    int i=0,j=0,c=0,v=0,s=0;
    char str[50];
    printf("Enter a sentence/string: ");
    fgets(str,sizeof(str),stdin);  //adds \n character at end
    for (i;str[i]!='\0';i++)
    {
        if (str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u')
            v++;
        else if (str[i]==' ')
            s++;
        else if(str[i]!='\n')    //exclude \n character
            c++;
    }
    printf("The number of\n"
            "Vowels:%d\n"
            "Consonants:%d\n"
            "Whitespaces:%d\n",v,c,s);
}