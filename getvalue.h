/*
return 0-->发现错误
return 1-->传回string
return 2-->传回数字
return 3-->传回[]内的内容
*/ 
extern int eoln;
extern int ifexpression; 
extern char string[80];
extern int integer;
extern char newstring[80];
int getvalue()
{
    char st[80];
    int i,x,j,typ,len;
    eoln=read();
    strcpy(st,string);
    //printf("st=%s\neoln=%d\n",st,eoln);
    len=strlen(st);
    if (st[0]=='[')
    {  
        memset(string, 0, sizeof(string)); 
        j=0;
        for (i=1;i<len;i++)
        {
            string[j]=st[i];
            j++;
        }
        string[j]=' ';
        j++;
        while (st[len-1]!=']')
        {          
            scanf("%s",st);
            len=strlen(st);
            for (i=0;i<len;i++)
            {
                string[j]=st[i];
                j++;
            }
            string[j]=' '; 
            j++;
        }
        if (st[len-1]==']')
        {
            string[j-2]='\0';
        }
        return 1;
    }   
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
                integer=identifier.intvalue[x];
                if (ifexpression==1)
                {
                    expression(2);
                }
                return 2;
            }
        }else 
        {
            return 0;
        }    
    }  
    if (strcmp(st,"(")*strcmp(st,")")*strcmp(st,"+")*strcmp(st,"-")*strcmp(st,"*")*strcmp(st,"/")==0)
    {
        strcpy(string,st);
        if (strcmp(st,"(")==0)
        if (ifexpression==1)
        {
            expression(1);
            return 2;
        }
        return 1;
    }  
    if  ((st[0]>='0')&&(st[0]<='9'))
    {
        integer=0;
        for (i=0;i<len;i++)
        {
            integer=integer*10+st[i]-'0';
        }
        //printf("a digit\n");
        //printf("ifexpfression=%d\n",ifexpression);
        if (ifexpression==1)
        {
            expression(2);
        }
        return 2;
    }         
    if  ((st[0]=='-')||(st[0]=='+'))
    { 
        integer=0;
        for (i=1;i<len;i++)
        {
            integer=integer*10+st[i]-'0';
        }
        if (st[0]=='-') integer=0-integer;
        return 2;
        if (ifexpression==1)
        {
            expression(2);
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
                integer=identifier.intvalue[x];
                if (ifexpression==1)
                {
                   expression(2);
                }
                return 2;
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
}
