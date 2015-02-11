#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 24
#define TEST 0

char* easy_hashcode(char *key);
char* easy_hash_get(char map[],char *key);
char* easy_hash_init();
void easy_hash_set(char map[],char *key,char *value);
#ifdef TEST
int main(int argc,char *argv[],char *envp[])
{
	char map[]=easy_hash_init();
	easy_hash_set(map,"key","value");
	printf("%s\n",easy_hash_get(map,"key"));
	return 0;
}
#endif

char*
easy_hash_init()
{
	char *barket[SIZE];
	return barket;
}

int 
easy_hashcode(char *key)
{
	int adress=strlen(key);
	return adress;
}

char*
easy_hash_get(char map[],char *key)
{
	int adress=easy_hashcode(key);
	return map[adress];
}

void
easy_hash_set(char map[],char *key,char *value)
{
	int adress=easy_hashcode(key);
	map[adress]=value;
}
