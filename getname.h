extern char string[80];
extern int integer;
extern char newstring[80];
/*
    return 0-->发现了错误；
    rerutn 1-->未发现错误；
*/ 
extern char string[80];
extern int integer;
extern char newstring[80];
int getname()
{
    char st[80];
    int i,x,j,typ,len;
    scanf("%s",st);
    len=strlen(st);
    //printf("st==%s\n",st);
    if (strcmp(st,"THING")==0)
    {
       typ=getname();
       int ctf=checkname(typ,string);
       if (ctf==1)
       {
           x=findidentifier(string);
           memset(string, 0, sizeof(string));
           if (x==0)
           {
               printf("error:this word is not defined!\n");
               return 0;
           }
           if (identifier.type[x]==1)
           {
               strcpy(string,identifier.stringvalue[x]);
               return 1;
           }
           if (identifier.type[x]==2)
           {
               printf("a number can't be used as a var!\n");
               return 0;
           }
       }else 
       {
           return 0;
       }    
    }  
    if (st[0]=='"')
    {
        memset(string, 0, sizeof(string));           
        for (j=1;j<len;j++)
        {
            string[j-1]=st[j];
        }
        //printf("find and do it\n");
        //printf("string=%s\n",string);
        return 1;
    }
    if (st[0]==':')
    {
        memset(string,0,80);          
        for (j=1;j<len;j++)
        {
            string[j-1]=st[j];
        }
        int ctf=checkname(1,string);
        if (ctf==1)
        {
            x=findidentifier(string);
            if (x==0)
            {
                printf("error:this word is not defined!\n");
                return 0;
            }
            if (identifier.type[x]==2)
            {
                printf("a number can't be used as a var!\n");
                return 0;
            }
            if (identifier.type[x]==1)
            {
                strcpy(string,identifier.stringvalue[x]); 
                return 1;         
            }
        }else
        {
             return 0;
        }
    }
    printf("error:%s can't be here!\n",st);
    return 0;
}
