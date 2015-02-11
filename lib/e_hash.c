#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "e_link.h"
#include "e_hash.h"


/* debug */
#ifdef DEBUG
int main(int argc,char *argv[],char *envp[])
{
	ehasht *hasht=e_hash_init(23);
    int i=0;
    char str[40],tem[40],put[40];
    for(;i<41;i++){
        strcpy(str,"abc");
        itoa(i,tem,10);
        strcat(str,tem);
        itoa(i+1,put,2);
	    e_hash_set(hasht,str,put);
        printf("size:%d,use:%d\n",hasht->size,hasht->use);  
    }
}
#endif

ehasht *
e_hash_init(int size)
{
	ebkt *bkt=malloc(size*sizeof(ebkt));
	ehasht *hasht=malloc(sizeof(ehasht));
	hasht->size=size;
	hasht->bkt=bkt;
	hasht->use=0;
    e_hash_bkt_init(hasht);
	return hasht;
}
void e_hash_bkt_init(ehasht *hasht)
{
    int i=0;
    for(;i<hasht->size;i++)
        hasht->bkt[i].element=NULL;
}
int 
e_hash_time33(char *key,int size)
{
	unsigned int hash=0;
	while(*key)
		hash=(hash << 5) + *key++;/* hash * 33 + key */
  /* map adress in bucket */
	return hash%size;
}
void
e_hash_set(ehasht *hasht,char *key,char *value)
{
	E_HASH_ELM *val=NULL;
    if((float)hasht->use/hasht->size>DIVISOR)
		e_hash_realloc(hasht,hasht->size*2);

	int adr=E_HASH_FUNCTION(key,hasht->size);//int adr=e_hash_time33(key,hasht->size);
    E_HASH_ELM *elm=hasht->bkt[adr].element;
    if(elm)
        val=E_HASH_ELM_GET(elm,key);//search key in element list
    else
    {
        /* init element list */
        elm=E_HASH_ELM_INIT();
        hasht->bkt[adr].element=elm;
    }
    if(!val)
        hasht->use++;
	E_HASH_ELM_SET(elm,key,value);
}
char * 
e_hash_get(ehasht *hasht,char *key)
{	
	int adr=E_HASH_FUNCTION(key,hasht->size);//int adr=e_hash_time33(key,hasht->size);
    E_HASH_ELM *elm=hasht->bkt[adr].element;
    if(elm)
        elm=E_HASH_ELM_GET(elm,key);
	if(elm)
		return elm->value;
	return NULL;
}
void
e_hash_dispose(ehasht *hasht)
{
    int i=0;
    E_HASH_ELM *elm=NULL;
    for(;i<hasht->size;i++)
    {
        elm=hasht->bkt[i].element;
        if(elm)
            E_HASH_ELMLIST_FREE(elm);
        hasht->bkt[i].element=NULL;
    }
	free(hasht->bkt);
    free(hasht);
}
void 
e_hash_realloc(ehasht *hasht,int size)
{
	ehasht *temhash=e_hash_init(size);
	ehasht *swap=NULL;
    /* copy to new bucket  */
	int i=0;
    E_HASH_ELM *list=NULL;
	for(;i<hasht->size;i++)
	{
        list=hasht->bkt[i].element;
        if(list){
            E_HASH_ELM *tem=list->next;
            E_HASH_ELM *wfree=NULL;
            /* rehash all element which in linkedlist */
            while(tem){
                e_hash_set(temhash,tem->key,tem->value);
                printf("realloc:%s\n",tem->key);
                wfree=tem;
                tem=tem->next;
                E_HASH_ELM_FREE(wfree);
            }
            /* free the linkedlist */
            //E_HASH_ELMLIST_FREE(list);   
        }   
	}
    swap=hasht;
    *hasht=*temhash;
    free(temhash);
    /*free linkedlist*/
    //e_hash_dispose(swap);
}
