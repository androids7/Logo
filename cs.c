#include<stdio.h>
#include<string.h>
char string[80];
int read()
{
    printf("enter read\n");
    char ch;
    memset(string,0,80);
    ch=0;
    int j=0;
    ch=getchar();
    while (ch==' ')
    {
          ch=getchar();
    }
    string[j]=ch;
    j++;
    while ((ch!=' ')&&(ch!='\n'))
    {
       ch=getchar();
       string[j]=ch;
       j++;
    }
    string[j-1]='\0';
    if (ch=='\n') 
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
    {
      i=read();
      printf("string=%s,i=%d",string,i);
    }
    return 0;
}
    
