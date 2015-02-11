#ifndef E_HASH_H
#define E_HASH_H

#define DIVISOR 0.75
/* define the hash function,can be replace */
#define E_HASH_FUNCTION(ehasht,size) e_hash_time33((ehasht),(size)) 
/* bucket element */
#define E_HASH_ELM elink
#define E_HASH_ELM_INIT() e_link_init()
#define E_HASH_ELM_SET(elm,key,value) e_link_set((elm),(key),(value))
#define E_HASH_ELM_GET(elm,key) e_link_get((elm),(key))
#define E_HASH_ELM_REMOVE(elm,key) e_link_remove((elm),(key))
#define E_HASH_ELMLIST_FREE(list) e_link_free((list))
#define E_HASH_ELM_FREE(node) e_link_node_free((node))

/* hash bucket */
typedef struct e_bucket
{
	E_HASH_ELM *element;
}ebkt;
/* hash table*/
typedef struct e_hash_table
{
	ebkt *bkt;
	int size;
	int use;
}ehasht;
/**/


ehasht*
e_hash_init(int size);
void e_hash_bkt_init(ehasht *hasht);
void 
e_hash_realloc(ehasht *hasht,int size);
void 
e_hash_set(ehasht *hasht,char *key,char *value);
char *
e_hash_get(ehasht *hasht,char *key);
int
e_hash_time33(char *key,int size);
void 
e_hash_dispose(ehasht *hasht);


#endif
