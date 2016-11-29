#include "printf.h"

void traite_int(int d)
{
  printf("%d", d);
}

void traite_str(char *s)
{
  printf("%s", s);
}

void traite_char(char c)
{
  printf("%c", c);
}

int len(char *s)
{
  int i = 0;
  while (s[i])
    i++;
    return (i);
}

void init_conv(t_global *g)
{
  g->conv.s = 0;
  g->conv.S = 0;
  g->conv.p = 0;
  g->conv.d = 0;
  g->conv.D = 0;
  g->conv.i = 0;
  g->conv.o = 0;
  g->conv.O = 0;
  g->conv.u = 0;
  g->conv.U = 0;
  g->conv.x = 0;
  g->conv.X = 0;
  g->conv.c = 0;
  g->conv.C = 0;
}

// a initialiser au passage d'arguments!!!!!!
void init_flag(t_global *g)
{
  g->flag.diez = 0;
  g->flag.zero = 0;
  g->flag.moins = 0;
  g->flag.plus = 0;
  g->flag.esp = 0;
  g->flag2.hh = 0;
  g->flag2.h = 0;
  g->flag2.l = 0;
  g->flag2.ll = 0;
  g->flag2.j = 0;
  g->flag2.z = 0;
  g->flag2.cpt = 0;
}

void ft_print(char *format, ...)
{
  int i;
  t_global g;
  int d = 0;
  char *s;
  t_llist *l;
  int j;
  l = NULL;
  i = 0;
  init_flag(&g);
  init_conv(&g);
//  char c;
  va_start(g.ap, format);
  while (format[i])
  {
    if (format[i] == '%')
    {
      i = analyse_perc(format, &g, i);
      j = 0;
    }
    // if (*format == 's')
    // {
    //   s = va_arg(ap, char*);
    //   traite_str(s);
    //   format++;
    // }
    // else if (*format == 'c')
    // {
    //   c = va_arg(ap, int);
    //   traite_char(c);
    //   format++;
    // }
    // else if (*format == 'd')
    // {
    //     d = va_arg(ap, int);
    //     traite_int(d);
    //     format++;
    // }
    // printf("%c", *format);
    printf("%c", format[i]);
    j++;
    i++;
  }
  va_end(g.ap);
}

int main(int ac, char **av)
{
    ft_print("salut%###0hhxpede%dcava");
//    printf("%hi", (short)12);
//  printf ("Preceding with blanks: %2d \n", 1977);
//	printf("%040d", len("salut"));
}
