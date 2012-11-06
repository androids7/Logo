#include<stdio.h>
#include<string.h>
extern char string[80];
int read()
{
    printf("enter read\n");
    char ch;
    memset(string,0,80);
    ch=0;
    int j=0;
    ch=getch();
    while (ch==' ')
    {
          ch=getch();
    }
    string[j]=ch;
    j++;
    while ((ch!=' ')&&(ch!='\n'))
    {
       ch=getch();
       printf("%c",ch);
       string[j]=ch;
       j++;
    }
    string[j]='\0';
    printf("string=%s",string);
    if (ch==13) 
    {
        return 1;
    }
    else 
    {
        return 0;
    } 
}   
int main()
{
    int i;
    while (1)
    i=read()
    return 0;
}
    
