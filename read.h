extern char string[80];
int read()
{
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
