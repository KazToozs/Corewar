/*
** delete_node.c for pushswap in /home/pallua_j/rendu/Progelem/CPE_2014_Pushswap/function
** 
** Made by jules palluau
** Login   <pallua_j@epitech.net>
** 
** Started on  Thu Dec  4 13:24:03 2014 jules palluau
** Last update Tue Mar 17 21:37:07 2015 jules palluau
*/

#include "corewar.h"

t_list		*delete_node(t_list *list)
{
  t_list	*tmp;

  tmp = list;
  tmp = tmp->next;
  tmp->prev->next = tmp;
  return (tmp);
}
