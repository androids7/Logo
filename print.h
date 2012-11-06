extern char string[80];
extern int integer;
int print()
{
//    printf("has entered print \n");
    extern identifiertype identifier;
    char st[80],toprint[80],iname[80];
    int i,j,len,x,typ;
    typ=getvalue();
//    printf("handle finished,typ=%d",typ);
    if (typ==1) {strcpy(toprint,string);}
    if (typ==2) {printf(">>>>>>%d\n",integer);return 0;}
    if (typ==0) {return 0;}
    //doprint:;
    printf(">>>>>>%s\n",toprint);
    return 0;
}

                        
    
