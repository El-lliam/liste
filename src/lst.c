#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "lst.h"

struct lst_t * new_lst() {
	struct lst_t * L = (struct lst_t *)calloc(1,sizeof(struct lst_t));
	assert(L);
	return L;
}

void del_lst(struct lst_t ** ptrL ) {
	assert(ptrL && *ptrL);
	for(struct lst_elm_t *E = (*ptrL)->head;E; )
        {
		struct lst_elm_t * T = E;
		E = E->suc;
		del_lst_elm_t(&T);
        }
	free(*ptrL);
	*ptrL =NULL;
}

bool empty_lst(const struct lst_t * L ) {
	assert(L);
	return L->numelm == 0;
}

void cons(struct lst_t * L, int v) {
	struct lst_elm_t *E = new_lst_elm(v);
	E->suc = L->head;
	L->head = E;
	if(L->numelm==0) L->tail = E;
	L->numelm++;
}

void queue(struct lst_t * L, int v){
	struct lst_elm_t *E = new_lst_elm(v);
	L->tail->suc = E;
	L->tail = E;
	if(L->numelm==0) L->head = E;
	L->numelm++;
}

void print_lst(struct lst_t * L ) {
	printf( "[ " );
	for( struct lst_elm_t * E = L->head; E; E = E->suc) {
		printf( "%d ", E->x );
	}
	printf( "]\n\n" );
}

void insert_after(struct lst_t * L, const int value, struct lst_elm_t * place){
	if(empty_lst(L)){
		cons(L,value);
	}else{
		printf("insertion after\n");

		struct lst_elm_t *E = new_lst_elm(value);
		E->suc = place->suc;
		place->suc = E;
	}
}

void insert_ordered(struct lst_t * L, const int value){
	if(empty_lst(L) || value < getX(L->head)){
		printf("insertion au d¨¦but\n");
		cons(L,value);
	}else if(value > getX(L->tail)){
		printf("insertion ¨¤ la fin\n");
		queue(L,value);
	}else{
		printf("Insertion entre\n");
		struct lst_elm_t *E ;
		E = L->head;

		while(value > getX(E->suc)){
			E= E->suc;
			printf("E.x = %d",getX(E));
		}

		insert_after(L, value,E);
	}
}
