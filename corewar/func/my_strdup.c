/*
** my_strdup.c for my_strdup in /home/pallua_j/rendu/Piscine_C_J08/ex_01
** 
** Made by jules palluau
** Login   <pallua_j@epitech.net>
** 
** Started on  Wed Oct  8 11:29:19 2014 jules palluau
** Last update Wed Jan 21 09:14:42 2015 jules palluau
*/

#include "mysh.h"

char	*my_strdup(char *src)
{
  int	l;
  int	x;
  char	*str;

  x = 0;
  l = my_strlen(src) + 1;
  str = malloc(l);
  while (src[x] != '\0')
    {
      str[x] = src[x];
      x++;
    }
  return (str);
}
