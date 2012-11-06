extern int integer;
extern int ifexpression;
char word[80],operater[80],bope[80];
int typ,len,num[80],knum,kope,i,j,btype[80],bnum[80],fa[80],lson[80],rson[80],k,ans,rroot;
extern char string[80];
extern int ifexpression;
char ch;
extern int eoln;
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
        rson[x]=x+1;
        rson[root]=x;
        if (x+2<=k)
        maketree(x+2,root);
    }
    return 0;
}        
int doexpression()
{
      int numj=knum;
      for (i=kope;i>0;i=i-1)
      {
          if (operater[i]=='(') break;
          numj=numj-1;
      }
      j=i;
      k=1;
      if (kope==i)
      {
          ans=num[knum];        
          //printf("yes\n%d",ans); 
      }else{
      for (i=j+1;i<=kope;i++)
      {
          btype[k]=1;
          bnum[k]=num[numj];
          numj++;
          k++;
          btype[k]=2;
          bope[k]=operater[i];
          k++;
      }         
      btype[k]=1;
      bnum[k]=num[knum]; 
      {
        int i;
        for (i=1;i<=k;i++)
        {
            //printf("%c",bope[i]);
            //printf("%d ",bnum[i]);
        }
      }
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
      ans=calc(rroot);
      }
      //printf("ans=%d\n",ans);
      knum=numj;
      num[knum]=ans;
      kope=j-1; 
      if (eoln) 
      {
          integer=ans;
          return 2;
      }
}
int expression(int firsttyp)
{
    //printf("begin to do expression\n");
    kope=0;
    knum=0;
    typ=firsttyp;
    ifexpression=0;
    do{
    //printf("now string=%s\n",string);
    //printf("now number=%d\n",integer);
    //printf("now type=%d\n",typ);
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
    if (eoln) break;
    typ=getvalue();
    }while (1);
    doexpression();
    return 2;
    
}
    
