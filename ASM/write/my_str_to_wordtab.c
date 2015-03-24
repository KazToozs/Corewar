/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/pallua_j/rendu/Piscine_C_J08/ex_04
** 
** Made by jules palluau
** Login   <pallua_j@epitech.net>
** 
** Started on  Thu Oct  9 09:17:50 2014 jules palluau
** Last update Mon Feb  9 19:08:15 2015 jules palluau
*/

#include "mysh.h"

int	my_condition(char x)
{
  if ((x > 96 && x < 123) 
      || (x > 64 && x < 91)
      || (x >= '0' && x <= '9')
      || (x == '/') || (x == '~')
      || (x == '-') || (x == '_') 
      || (x == '.'))
    return (0);
  return (1);
}

int     my_word_nbr(char *s)
{
  int   x;
  int   compt;

  x = 0;
  compt = 0;
  while (s[x])
    {
      if (my_condition(s[x]) == 0)
        {
          compt++;
          while (s[x] && (my_condition(s[x]) == 0))
	    x++;
        }
      else
	x++;
    }
  return (compt);
} 

int     my_char_nbr(char *s, int *y)
{
  int   compt;

  compt = 0;
  while (s[*y] && (my_condition(s[*y]) == 0))
    {
      compt++;
      (*y)++;
    }
  return (compt);
}

char    **my_str_to_wordtab(char *str)
{
  int   x;
  int   y;
  int   word;
  char  **dest;

  x = 0;
  y = 0;
  if (str == NULL)
    return (NULL);
  word = my_word_nbr(str);
  dest = malloc(sizeof(char *) * (word + 1));
  while (str[x] && word > 0)
    {
      if (my_condition(str[x]) == 0)
        {
          dest[y] = my_strdup(str + x);
          dest[y++][my_char_nbr(str, &x)] = '\0';
          word--;
        }
      x++;
    }
  dest[y] = NULL;
  return (dest);
}
