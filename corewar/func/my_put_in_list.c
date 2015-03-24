/*
** my_put_in_list.c for push_swap in /home/pallua_j/rendu/Progelem/CPE_2014_Pushswap/function
**
** Made by jules palluau
** Login   <pallua_j@epitech.net>
**
** Started on  Tue Dec  2 14:17:15 2014 jules palluau
** Last update Wed Mar 18 14:10:17 2015 jules palluau
*/

#include "corewar.h"

t_list		*my_put_start_list(t_list *list, int pc)
{
  t_list	*elem;

  elem = malloc(sizeof(elem));
  elem->prev = NULL;
  elem->next = NULL;
  elem->pc = pc;
  if (list == NULL)
    return (elem);
  elem->next = list;
  elem->next->prev = elem;
  return (elem);
}

t_list		*my_put_end_list(t_list *list, int pc)
{
  t_list	*elem;
  t_list	*tmp;

  elem = malloc(sizeof(elem));
  elem->prev = NULL;
  elem->next = NULL;
  elem->pc = pc;
  if (list == NULL)
    return (elem);
  tmp = list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = elem;
  elem->prev = tmp;
  return (list);
}
