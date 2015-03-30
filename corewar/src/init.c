/*
** init.c for  in /home/pallua_j/rendu/Progelem/CPE_2014_corewar/corewar/src
** 
** Made by jules palluau
** Login   <pallua_j@epitech.net>
** 
** Started on  Tue Mar 24 11:58:54 2015 jules palluau
** Last update Wed Mar 25 13:13:02 2015 jules palluau
*/

#include "corewar.h"

/*
** Initialisation d'un tableau d'int pour attribuer les numéros de joueurs.
*/

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

/*
** Initialisation de l'arène et remplissage de l'arène de \0.
*/

int	init_arena(t_vm *vm)
{
  int	x;

  x = 0;
  if ((vm->arena = malloc(sizeof(char) * MEM_SIZE)) == NULL)
    aff_error("Can't perform malloc\n");
  while (vm->arena[x])
    {
      vm->arena[x] = '\0';
      x++;
    }
  return (0);
}
