/*
** header.c for corewar in /home/pallua_j/rendu/Progelem/CPE_2014_corewar/corewar/src
** 
** Made by jules palluau
** Login   <pallua_j@epitech.net>
** 
** Started on  Wed Mar 18 11:36:07 2015 jules palluau
** Last update Tue Mar 24 12:11:59 2015 jules palluau
*/

#include "corewar.h"

int	reverse_endian(int x)
{
  int	en;

  en = ((x << 8) & 0xFF00FF00) | ((x >> 8) & 0x00FF00FF);
  return ((en << 16) | ((en >> 16) & 0xFFFF));
}

int	check_magic(t_champ *c)
{
  if (c->head.magic == COREWAR_EXEC_MAGIC)
    c->endian = 0;
  else if (reverse_endian(c->head.magic) == COREWAR_EXEC_MAGIC)
    c->endian = 1;
  else
    exit(0);
  return (0);
}

int	*my_order2(t_vm *vm, int *test, int v)
{
  int	y;

  y = 0;
  while (y < 5)
    {
      if (test[y] > 0)
	{
	  vm->c[v].player = test[y];
	  test[y] = 0;
	}
      y++;
    }
  return (test);
}

void		my_order(t_vm * vm, int x, int v)
{
  static int	*test;

  if (v == 0)
    test = init_order();
  if ((x > 0 || x < 5) && test[x] == x)
    {
      test[x] = 0;
      vm->c[v].player = x;
    }
  else if (x == 42)
    test = my_order2(vm, test, v);
  else if (test[x] == 0 && x > 0 && x < 5)
    {
      my_printf("prog_number %d already used\n", x);
      exit(-1);
    }
  else
    aff_error("[ERROR]: Invalid prog_number!\n");
}

int		my_header(char *av, t_vm *vm, int y, int add)
{
  static int	x = 0;

  if (av == NULL)
    aff_error("Corewar executable missing\n");
  if ((vm->c = realloc(vm->c, sizeof(vm->c[0]) * (x + 1))) == NULL)
    aff_error("Can't perform malloc\n");
  if ((vm->c[x].fd = open(av, O_RDONLY)) == -1)
    my_printf("%s is not a corewar executable\n", av);
  read(vm->c[x].fd, &vm->c[x].head, sizeof(header_t));
  check_magic(&vm->c[x]);
  if (vm->c[x].endian == 1)
    vm->c[x].head.prog_size = reverse_endian(vm->c[x].head.prog_size);
  my_printf("Prog_name:%s\nComment:%s\nProg_size:%d\n", vm->c[x].head.prog_name, vm->c[x].head.comment, vm->c[x].head.prog_size);
  my_order(vm, y, x);
  if (add >= 0 && add < MEM_SIZE)
    vm->c[x].add = add;
  else if (add >= MEM_SIZE)
    aff_error("[ERROR]: address bigger than MEM_SIZE!\n");
  x++;
  return (0);
}
