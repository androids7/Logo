int tf(char sa[80],char sb[80])
{
     int i,len1,len2;
     len1=strlen(sa);
     len2=strlen(sb);
     if (len1!=len2) return 2;
     for (i=0;i<len1;i++)
     {
         if (sa[i]!=sb[i]) return 2;
     }
     return 1;
}

//int main()
//{
//    char s1[1000],s2[1000];
//    while (1==1){
//    gets(s1);
//    gets(s2);
//    if (tf(s1,s2)) printf("Yes\n");
//      else printf("No\n");
//}
//}
