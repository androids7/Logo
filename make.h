//已经完成了string类型，表达式还在待进行 
/*typedef struct
{
       char name[1000][1000];
       int type[1000],number,intvalue[1000];
       char stringvalue[1000][1000];
}identifiertype;*/
//#include<stdio.h>
//#include<string.h>
//#include "tf.h"
//#include<main.h>
extern identifiertype identifier;
extern char string[80];
extern int integer;
//#include "set.h"
int make()
{
    //printf("has entered make\n");
    int i,j,k,len,m,n,changei,changetf,changej,typ,ctf;
    char name[80]="",st[80]="",inname[80]="",value[80]="";
    memset(string, 0, sizeof(string));
    integer=0;
    typ=0;
    //printf("tpy=0\n");
    typ=getname();
    //printf("do thing finished!\n");
    ctf=checkname(typ,string);
    if (ctf==1) {strcpy(name,string);}
    if (ctf==0) {return 0;}
    changetf=0; 
    for (i=1;i<=identifier.number;i++)
    {
        if (tf(identifier.name[i],name)==1)
        {
          changei=i;changetf=1;  
        }
    }
    //printf("changetf=%d\n",changetf);
    if (changetf==0)
    {
        changei=identifier.number+1;
        identifier.number++;
        strcpy(identifier.name[changei],name);
    }
    //此处开始判断应赋的值 
    //printf("changei=%d",changei);
    memset(string, 0, sizeof(string));
    integer=0;
    typ=0;
    typ=getvalue();
    //printf("handle finished!\n");
    //printf("changei=%d",changei);
    //printf("typ=%d",typ);
    if (typ==1) {identifier.type[changei]=1;strcpy(identifier.stringvalue[changei],string);}
    if (typ==2) {identifier.type[changei]=2;identifier.intvalue[changei]=integer;}
    if (typ==0) {return 0;}
    return changei;
} 
