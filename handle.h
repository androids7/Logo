
//    printf("has entered handle\n");
   
    scanf("%s",st);
    len=strlen(st);
//    printf("got then word : %s\n",st);
    if (st[0]=='[')
    {
        memset(newstring,0,80);
        strcpy(string,newstring);
        return 3;
    }   
    }
    if (strcmp(st,"THING")==0)
    {
       typ=handle();
       int ctf=checkname(typ,string);
       if (ctf==1)
       {
           x=findidentifier(string);
           memset(string, 0, sizeof(string));
           if (identifier.type[x]==1)
           {
               strcpy(string,identifier.stringvalue[x]);
               return 1;
           }
           if (identifier.type[x]==2)
           {
               integer=identifier.intvalue[x];
               return 2;
           }
       }
       if (ctf==0)
       {
           return 0;
       }    
    }  
    if (strcmp(st,"(")*strcmp(st,")")*strcmp(st,"+")*strcmp(st,"-")*strcmp(st,"*")*strcmp(st,"/")==0)
    {
        strcpy(string,st);
        return 1;
    }
    if  ((st[0]>='0')&&(st[0]<='9'))
    {
        integer=0;
        for (i=0;i<len;i++)
        {
            integer=integer*10+st[i]-'0';
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
    }else if (st[0]==':')
    {
        for (j=1;j<len;j++)
        {
            string[j-1]=st[j];
        }
        int ctf=checkname(1,string);
        if (ctf==1)
        {
            x=findidentifier(string);
            if (identifier.type[x]==2)
            {
                integer=identifier.intvalue[x];
                return 2;
            }
        }else {return 0;}
        if (x==0)
        {
            printf("error:this word is not defined!\n");
            return 0;
        }
        strcpy(string,identifier.stringvalue[x]); 
        return 1;         
    }
    else {
              printf("error:%s can't be here!\n",st);
              return 0;
         }
}

        


