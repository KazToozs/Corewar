/*
** init.c for corewar in /home/pallua_j/rendu/Progelem/CPE_2014_corewar/corewar/src
** 
** Made by jules palluau
** Login   <pallua_j@epitech.net>
** 
** Started on  Wed Mar 18 18:36:03 2015 jules palluau
** Last update Tue Mar 24 12:14:13 2015 jules palluau
*/

#include "corewar.h"

int	prog_number(char **av, t_vm *vm, int *x)
{
  if ((my_strcmp(av[(*x)], "-n")) == 0 && (my_strcmp(av[(*x) + 2], "-a")) == 0)
    {
      my_header(av[(*x) + 4], vm, my_getnbr(av[(*x) + 1]),
		my_getnbr(av[(*x) + 3]));
      (*x) += 5;
    }
  else if ((my_strcmp(av[(*x)], "-n")) == 0)
    {
      my_header(av[(*x) + 2], vm, my_getnbr(av[(*x) + 1]), -1);
      (*x) += 3;
    }
  else if ((my_strcmp(av[(*x)], "-a")) == 0)
    {
      my_header(av[(*x) + 2], vm, 42, my_getnbr(av[(*x) + 1]));
      (*x) += 3;
    }
  else
    {
      my_header(av[(*x)], vm, 42, -1);
      (*x)++;
    }
  return (0);
}

int	check_option(char **av, t_vm *vm)
{
  int	x;

  x = 1;
  vm->nb_cycle = 0;
  vm->c = NULL;
  while (av[x])
    {
      if ((my_strcmp(av[x], "-dump")) == 0)
	{
	  vm->nb_cycle = my_getnbr(av[x + 1]);
	  x += 2;
	}
      prog_number(av, vm, &x);
    }
  return (0);
}
