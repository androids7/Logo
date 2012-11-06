#include "set.h"
#include "findidentifier.h"
#include "check.h"
extern int integer;
extern int ifexpression;
extern identifiertype identifier;
char word[80],operater[80],bope[80];
int typ,len,num[80],knum,kope,i,j,btype[80],bnum[80],fa[80],lson[80],rson[80],k,ans,rroot;
extern char string[80];
extern int ifexpression;
int ifre=0;
char ch;
int calc(int x)
{
    int i,j;
    //printf("calc %d.....\n",x);
    if (btype[x]==1) return bnum[x];
    switch (bope[x])
    {
        case '+':i=calc(lson[x])+calc(rson[x]);return i;break;
        case '-':i=calc(lson[x])-calc(rson[x]);return i;break;
        case '*':i=calc(lson[x])*calc(rson[x]);return i;break;
        case '/':i=calc(lson[x])/calc(rson[x]);return i;break;
        default:break;
    }
}
int maketree(int x,int root)
{
    int i,j;
    //printf("maketree begin\n"); 
    rroot=root;
    if ((bope[x]=='+')||(bope[x]=='-'))
    {
        //printf("find %c\n",bope[x]);
        fa[root]=x;
        lson[x]=root;
        rson[x]=x+1;
        rroot=x;
        if (x+2<=k)
        {
          //printf("do make\n");
          //printf("x=%d,root=%d!",x,root);
          maketree(x+2,x);
        }
          
    }
    else
    {
        fa[x]=root;
        lson[x]=rson[root];
        rson[x]=x-1;
        rson[root]=x;
        if (x+2<=k)
        maketree(x+2,root);
    }
    return 0;
}        
int doexpression()
{
      for (i=kope;i>0;i=i-1)
      {
          if (operater[i]=='(') break;
      }
      j=i;
      k=1;
      for (i=j+1;i<=kope;i++)
      {
          btype[k]=1;
          bnum[k]=num[i];
          k++;
          btype[k]=2;
          bope[k]=operater[i];
          k++;
      }         
      btype[k]=1;
      bnum[k]=num[knum]; 
//          printf("k=%d\n",k);
      for (i=1;i<=k;i++)
//            printf("%c%d\t",bope[i],bnum[i]); 
      fa[1]=2;
      lson[2]=1;
      rson[2]=3;
      //i=2;    
      rroot=2;
      if (k>4)
      maketree(4,2);
//            printf("dao le\n");
//            printf("%d\n",rroot);
      knum=j;
      ans=calc(rroot);
      num[knum]=ans;
      kope=j-1; 
      if (ifre) 
      {
          integer=ans;
          printf("ans=%d\n",ans);
          return 2;
      }
}
int expression()
{
    //printf("begin to do expression\n");
    kope=0;
    knum=0;
    typ=2;
    char exp[80]="";
    int expj=0;
    ifexpression=0;
    gets(exp);
    /*ÐèÒªÉ¾³ý*/integer=1; 
    do{
    printf("now string=%s\n",string);
    printf("now number=%d\n",integer);
    printf("now type=%d\n",typ);
    //len=strlen(string);
    if  (typ==2)
    {
        knum++;
        num[knum]=integer;
    }
    if (typ==1)
    {
        //printf("find a operater\n");
        if ((string[0]==')'))
        {
            doexpression();
        }   
        else 
        { 
          kope++;
          operater[kope]=string[0];
        }
    }
    if (exp[expj]==0)  break;
    if ((exp[expj]=='+')||(exp[expj]=='-')||(exp[expj]=='*')||(exp[expj]=='/')||(exp[expj]='(')||(exp[expj]=')'))
    {
       //printf("findstring\n");
       string[0]=exp[expj];
       string[1]='\0';
       //printf("finish\n");
       do{
         expj++;
         }while (exp[expj]==' ');
       typ=1;
    }
    else
    if (exp[expj]=':')
    {
        //printf("find :\n");
        memset(string,0,80);
        int i=0;
        while ((exp[expj]!=' ')&&(exp[expj]!=0))
        {
              string[i]=exp[expj];
              expj++;
        }
        int ctf=checkname(1,string);
        if (ctf==0) 
        {
            return 0;
        }
        int x=findidentifier(string);
        if (x==0)
        {
            printf("error:this word is not defined!\n");
            return 0;
        }
        if  (identifier.type[x]==1)
        {
            printf("string can't be calculated in a expression!\n");
            return 0;
        }
        integer=identifier.intvalue[x];
        while (exp[expj]==' ')
        {
              expj++;
        }
    }else
    {
        printf("find digit\n"); 
        integer=0;
        while ((exp[expj]>='0')&&(exp[expj]<='9'))
        {
              integer=integer*10+exp[expj]-'0';
              expj++;
        }
        typ=2;
        while (exp[expj]==' ')
        {
              expj++;
        }
    }
    printf("finish\n");
    }while (1);
    ifre=1;
    doexpression();
    return 2;
}
int main()
{
    while(1)
    {
        expression();
    }
}
    
