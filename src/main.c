#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "lst_elm.h"
#include "lst.h"

int main(){
	int v;
	struct lst_t * L = new_lst();
	scanf( "%d", &v );
	print_lst(L);
	while( v > 0 )
        {
		insert_ordered(L,v);
		scanf("%d",&v);
	    }
	print_lst(L);
	del_lst(&L);
	return EXIT_SUCCESS;
}
