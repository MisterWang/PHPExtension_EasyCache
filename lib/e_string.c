#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "e_str.h"

#ifdef E_STR_DEBUG
int main(int argc,char *argv[],char *envp[])
{
    char *str=stradd("abc","def");
    char *zhstr=stradd("中文"," 啊啊啊");
    printf("%s\n%s\n",str,zhstr);
}
#endif

char* stradd(char *str,char *append)
{
    char *tem=malloc(strlen(str)+strlen(append)+1);
    strcpy(tem,str);
    strcat(tem,append);
    return tem;
}
/*
char *strsub()
{
    
}

char *
strrpl()
{
    
}*/
