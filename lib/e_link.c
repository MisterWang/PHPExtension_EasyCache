#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "e_link.h"

/* unit test */
#ifdef E_LINK_DEBUG
int main(int argc,char *argv[],char *envp[])
{
    elink *list=e_link_init();
    int i=0;
    char str[20],val[20];
    for(;i<21;i++){
        strcpy(str,"abc");
        itoa(i,val,10);
        strcat(str,val);
        e_link_set(list,str,val);
    }
    e_link_print(list);
}
#endif

elink *
e_link_init(){
	elink *list=malloc(sizeof(elink));
	list->key=NULL;
	list->value=NULL;
	list->next=NULL;
	return list;
}
void e_link_set(elink *list,char *key,char *value)
{
	elink *node=NULL;
	node=e_link_get(list,key);//update the node when the key is already exists
	if(node){//the node->value maybe smaller than value TODO
        if(strlen(node->value) < strlen(value))
            node->value=realloc(node->value,strlen(value)+1);
		strcpy(node->value,value);
	}else{
        /* the point maybe be changed */
        char *keyval=malloc(strlen(key)+1);
        char *valval=malloc(strlen(value)+1);
        strcpy(keyval,key);
        strcpy(valval,value);
		node=malloc(sizeof(elink));
		node->key=keyval;
		node->value=valval;
        node->next=NULL;

		if(list->next){
			node->next=list->next;
			list->next=node;
		}else
			list->next=node;
	}
#ifdef DEBUG
    printf("key:%s,val:%s\n",node->key,node->value);
#endif
}
elink *
e_link_get(elink *list,char *key)
{
	elink *node=NULL;
    elink *tem=list->next;
	while(tem){
		if(strcmp(tem->key,key)==0){
			node=tem;
			break;
		}
        tem=tem->next;
	}
	return node;
}
elink *
e_link_get_pre(elink *list,char *key)
{
	elink *node=NULL;
	elink *tem=list->next;
	while(tem){
		if(tem->next && strcmp(tem->next->key,key)==0){
			node=tem;
			break;
		}
        tem=tem->next;
	}
	return node;
}
void 
e_link_mknull(elink *list)
{
	elink *tem=NULL;
	elink *node=list->next;
	while(node){
		tem=node->next;
		free(node);
		node=tem;
	}
}
void e_link_remove(elink *list,char *key)
{
	elink *node=NULL;
	if(strcmp(list->next->key,key)==0)
	{
		free(list->next);
		list->next=NULL;
	}else
	{
		node=e_link_get_pre(list,key);
		elink *tem=node->next->next;
		free(node->next);
		if(tem)
			node->next=tem;
		else
			node->next=NULL;
	}
}
void
e_link_print(elink *list)
{
    elink *tem=list->next;
    while(tem){
        printf("key:%s,val:%s\n",tem->key,tem->value);
        tem=tem->next;
    }
}
void
e_link_free(elink *list)
{
    elink *node=list->next;
    elink *tem=NULL;
    while(node){
        tem=node;
        node=node->next;
        free(tem->key);
        free(tem->value);
        tem->next=NULL;
        free(tem);
    }
}
void
e_link_node_free(elink *node)
{
    free(node->key);
    free(node->value);
    node->next=NULL;
    free(node);
}
