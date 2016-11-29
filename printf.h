#ifndef PRINTF_H
#define PRINTF_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_conver
{
  int s;
  int S;
  int p;
  int d;
  int D;
  int i;
  int o;
  int O;
  int u;
  int U;
  int x;
  int X;
  int c;
  int C;
}
              t_conver;

typedef struct s_flag
{
  int diez;
  int zero;
  int moins;
  int plus;
  int esp;
}
              t_flag;

typedef struct s_flag2
{
  int hh;
  int h;
  int l;
  int ll;
  int j;
  int z;
  int cpt;
}
            t_flag2;

typedef struct s_llist
{
  char    *str;
  struct s_llist  *next;

}
              t_llist;

typedef struct s_global
{
  struct s_flag     flag;
  struct s_flag2    flag2;
  struct s_conver   conv;
  struct s_llist    list;
  va_list           ap;
}
              t_global;
int  analyse_perc(char *s, t_global *g, int i);

#endif
