/*
** my_vm.c for corewar in /home/pallua_j/rendu/Progelem/CPE_2014_corewar/corewar/src
** 
** Made by jules palluau
** Login   <pallua_j@epitech.net>
** 
** Started on  Wed Mar 18 18:28:27 2015 jules palluau
** Last update Mon Mar 23 15:30:05 2015 jules palluau
*/

#include "corewar.h"

int	my_vm(char **av)
{
  t_vm	*vm;

  if ((vm = malloc(sizeof(*vm))) == NULL)
    aff_error("Can't perform malloc\n");
  check_option(av, vm);
  return (0);
}
