#ifndef _LSTELMT_
#define _LSTELMT_
struct lst_elm_t {
  int x;
  struct lst_elm_t * suc;
}; 

struct lst_elm_t * new_lst_elm(int value);
void del_lst_elm_t(struct lst_elm_t ** ptrE);
int getX ( struct lst_elm_t * E );
struct lst_elm_t * getSuc ( struct lst_elm_t * E );
void setX (struct lst_elm_t * E, int v );
void setSuc ( struct lst_elm_t * E, struct lst_elm_t * S );

#endif
