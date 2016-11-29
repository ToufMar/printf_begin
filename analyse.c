#include "printf.h"

//flag de mise en page
void   fill_flag(char c, t_global *g)
{
  if (c == '#')
    g->flag.diez = 1;
  else if (c == '0')
    g->flag.zero = 1;
  else if (c == '-')
    g->flag.moins = 1;
  else if (c == '+')
    g->flag.plus = 1;
  else if (c == ' ')
    g->flag.esp = 1;
}

//flag de conversion
int  fill_flag2(char *s, t_global *g, int *i)
{
    if (s[*i] == 'h' && s[*i + 1] == 'h')
    {
      g->flag2.hh = 1;
      *i = *i + 1;
    }
    else if (s[*i] == 'h' && s[*i + 1] != 'h')
      g->flag2.h = 1;
    else if (s[*i] == 'l' && s[*i + 1] == 'l')
    {
        g->flag2.ll = 1;
        *i = *i + 1;
    }
    else if (s[*i] == 'l' && s[*i + 1] != 'l')
      g->flag2.l = 1;
    else if (s[*i] == 'j')
      g->flag2.j = 1;
    else if (s[*i] == 'z')
      g->flag2.z = 1;
    if ((g->flag2.hh + g->flag2.h + g->flag2.ll + g->flag2.l +
       + g->flag2.j + g->flag2.z) > 1)
       return (1);
    return (0);
}

void fill_conver(t_global *g, char c)
{
  if (c == 's')
    g->conv.s = 1;
  else if (c == 'S')
    g->conv.S = 1;
  else if (c == 'p')
    g->conv.p = 1;
  else if (c == 'd')
    g->conv.d = 1;
  else if (c == 'D')
    g->conv.D = 1;
  else if (c == 'i')
    g->conv.i = 1;
  else if (c == 'o')
    g->conv.o = 1;
  else if (c == 'O')
    g->conv.O = 1;
  else if (c == 'u')
    g->conv.u = 1;
  else if (c == 'U')
    g->conv.U = 1;
  else if (c == 'x')
    g->conv.x = 1;
  else if (c == 'X')
    g->conv.X = 1;
  else if (c == 'c')
    g->conv.c = 1;
  else if (c == 'C')
    g->conv.C = 1;
}

int check_end(char c, t_global *g, int *cpt)
{
  char *s2;
  int i;

  i = 0;
  s2 = "sSpdDioOuUxXcC";
  while (s2[i])
  {
    if (s2[i] == c)
    {
      *cpt = *cpt + 1;
      fill_conver(g, c);
    }
    if (*cpt > 1)
      return (0);
    i++;
  }
  return (1);
}

//check ce qu'il y a apres le %
int  analyse_perc(char *s, t_global *g, int i)
{
  char *s_flag;
  int j;
  int cpt;

  cpt = 0;
  s_flag = "#0-+";
  i++;
  while (s[i] && check_end(s[i], g, &cpt))
  {
    j = 0;
    while (s_flag[j])
    {
      if (s[i] == s_flag[j] || s[i] == ' ')
        fill_flag(s[i], g);
      j++;
    }
    if (fill_flag2(s, g, &i))
    {
        printf("error\n");
        return (1);
    }
    i++;
  }
//  printf("# = %d, 0 = %d, h = %d, x = %d\n", g->flag.diez, g->flag.zero, g->flag2.hh, g->conv.x);
  printf("%d\n", i);
  return(i);
}
