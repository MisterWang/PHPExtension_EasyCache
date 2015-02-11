#ifndef E_LINK_H
#define E_LINK_H
typedef struct e_link_list
{
	char *key;
	char *value;
	struct e_link_list *next;
}elink;

elink *
e_link_init(void);
void 
e_link_set(elink *list,char *key,char *value);
elink *
e_link_get(elink *list,char *key);
elink *
e_link_get_pre(elink *list,char *key);
void 
e_link_mknull(elink *list);
void
e_link_remove(elink *list,char *key);
void
e_link_print(elink *list);
void
e_link_free(elink *list);
void e_link_node_free(elink *node);
#endif
