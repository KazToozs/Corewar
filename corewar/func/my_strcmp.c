/*
** my_strcmp.c for mysh in /home/pallua_j/rendu/unix/PSU_2014_minishell1/func
** 
** Made by jules palluau
** Login   <pallua_j@epitech.net>
** 
** Started on  Thu Jan 22 11:09:17 2015 jules palluau
** Last update Tue Mar 24 10:13:37 2015 jules palluau
*/

#include "corewar.h"

int	my_strcmp(const char *s1, const char *s2)
{
  if (s1 == NULL || s2 == NULL)
    return (-1);
  while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
    {
      s1++;
      s2++;
    }
  return (*s1 - *s2);
}
