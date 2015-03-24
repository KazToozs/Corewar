/*
** init.c for  in /home/pallua_j/rendu/Progelem/CPE_2014_corewar/corewar/src
** 
** Made by jules palluau
** Login   <pallua_j@epitech.net>
** 
** Started on  Tue Mar 24 11:58:54 2015 jules palluau
** Last update Tue Mar 24 12:04:13 2015 jules palluau
*/

#include "corewar.h"

int	*init_order()
{
  int	*test;
  int	y;

  y = 0;
  if ((test = malloc(sizeof(int) * 5)) == NULL)
    aff_error("Can't perform malloc\n");
  while (y < 5)
    {
      test[y] = y;
      y++;
    }
  return (test);
}
