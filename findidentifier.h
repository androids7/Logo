extern identifiertype identifier;
int findidentifier(char cname[80])
{
    int i,n;
    n=identifier.number;
    //printf("now the number of identifier is %d\n",n);
    for (i=1;i<=n;i++)
    {
        //printf("compare %s and %s",cname,identifier.name[i]);
        if (strcmp(cname,identifier.name[i])==0)
        {
           // printf("find the location,is %d\n",i);
            return i;
        }
    }
    return 0;
}
        
            
