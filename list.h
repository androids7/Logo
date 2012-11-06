int list()
{
//    printf("has entered list\n");
    char word[80];
    int time,i;
    scanf("%s",word);
    if (strcmp("MAKE",word)==0)
    { 
        make(); 
        return 0;
    } 
    if (strcmp("PRINT",word)==0)
    {
        print();
        return 0;
    }
    if (strcmp("exit",word)==0)
    {
        printf("Thanks for using!\n");
        for (i=1;i<=400000000;i++);
        printf("5.....\n");
        for (i=1;i<=400000000;i++);
        printf("4.....\n");
        for (i=1;i<=400000000;i++);
        printf("3.....\n");
        for (i=1;i<=400000000;i++);
        printf("2.....\n");
        for (i=1;i<=400000000;i++);
        printf("1.....\n");
        for (i=1;i<=400000000;i++);
        return 1;
    }
    return 0;
}
