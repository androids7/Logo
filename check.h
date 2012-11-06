int checkname(int type,char st[80])
{
    //printf("check %s\ntpye=%d\n",st,type); 
    int ans;
    if (type==2) 
    {
        ans=2;
    }
    if ((type==1)&&((st[0]>='a')&&(st[0]<='z')||(st[0]>='A')&&(st[0]<='Z')))
    {
        ans=1;
    }else 
    {
        ans=2;
    }
    if (type==0)
    {
        ans=4;
    }
    if (ans==2)  
    {
      printf("error:This word can't be used as a var!\n"); 
    }
    return ans%2;
}
