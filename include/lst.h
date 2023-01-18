#include "lst_elm.h"
#ifndef _LST_
#define _LST_

struct lst_t {
	struct lst_elm_t * head;
	struct lst_elm_t * tail;
	int numelm;
}; 
struct lst_t * new_lst();

void del_lst(struct lst_t ** ptrL );
bool empty_lst(const struct lst_t * L);
void cons(struct lst_t * L, int v);
void queue(struct lst_t * L, int v);
void print_lst(struct lst_t * L );
void insert_after(struct lst_t * L, const int value, struct lst_elm_t * place);
void insert_ordered(struct lst_t * L, const int value);

#endif
