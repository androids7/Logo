#include<stdio.h>
#include<string.h>
int input()
{
    char c,d;
    char s[1000];
    char st[1000];
    char b[1000][1000];
    int i,j,k,l,m,n,len;
    gets(s);
    //puts(s);
    n=strlen(s);
    //printf("%c",s[0]);
    strcpy(st,"");
    //puts(s);
    i=0;
    k=0;
    len=0;
    while (i<=n)
    {     
          c=s[i];
          if (c==' ') 
            {
                    if (len!=0) 
                    {
                              k++;
                              for(j=0;j<len;j++) 
                                b[k][j]=st[j];
                    }
                    len=0;
                    //记得处理""的字符串  
           }
          else{    
          st[len]=c;
          len++;
          }
          i++;
          //puts(st);
    }
     if (len!=0) 
     {
       k++;
       for(j=0;j<len;j++) 
       b[k][j]=st[j];
     }
    //puts(st);
    for (i=1;i<=k;i++)
    {
      printf("%s\n",b[i]);
      
      //printf(" ");
      
    }
    //printf("%d",n);
    //printf("%s",s);
    //puts(s);
   // printf("%s",st);
    scanf("%d",n);
    return 0; 
} 
int main()
{
    input();
}
