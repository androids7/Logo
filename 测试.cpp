scanf("%s",st);
    //printf("%s\n",st);
    len=strlen(st);
    memset(toprint, 0, sizeof(toprint));
    if (st[0]=='"')
    {
        for (i=0;i<len;i++)
        {
            toprint[i]=st[i+1]; 
        }
        goto doprint;
    }
    memset(iname, 0, sizeof(iname));
if (st[0]==':')
    {
        //printf("has find :\n");
        //printf("%s\n",st);
        for (i=0;i<len;i++)
        {
            iname[i]=st[i+1];
        }
        //printf("the identifiername is:%s\n",iname);
        x=findidentifier(iname);
        if (x==0)
        {
            printf("error:this word is not defined!\n");
            return 0;
        }
        //printf("find identifier is:%d\n",x);
        if (identifier.type[x]==1)
        {
            strcpy(toprint,identifier.stringvalue[x]);
        } 
        else
        {
            printf("%s\n",identifier.intvalue[x]);
            return 0;
        }
    }
