/*
** corewar.h for korewar in /home/pallua_j/rendu/Progelem/korewar/include
** 
** Made by jules palluau
** Login   <pallua_j@epitech.net>
** 
** Started on  Mon Feb 16 14:36:25 2015 jules palluau
** Last update Tue Mar 24 12:04:58 2015 jules palluau
*/

#ifndef COREWAR_H_

# define COREWAR_H_

/*
********** Include ***********
*/

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/stat.h>
#include "op.h"

/*
*********** Liste chainée ***********
*/

typedef struct	s_list
{
  struct s_list	*next;
  int		pc;
  int		carry;
  struct s_list	*prev;
}		t_list;

/*
************ Structure ***************
*/

typedef struct	s_champ
{
  int		endian;
  char		*path;
  int		fd;
  int		player;
  int		add;
  header_t	head;
}		t_champ;

typedef struct	s_vm
{
  t_champ	*c;
  int		nb_cycle;
}		t_vm;

/*
********** PROTOTYPES affichages **********
*/

int	my_printf(char *str, ...);
int	aff_error(char *str);

/*
********** Prototypes listes ***********
*/

t_list	*delete_node(t_list *list);
int	my_aff_list(t_list *list);
t_list	*my_put_start_list(t_list *list, int pc);
t_list	*my_put_end_list(t_list *list, int pc);

/*
********* Prototypes autres ************
*/

int	my_strlen(char *str);
int	my_strcmp(const char *s1, const char *s2);
int	my_strncmp(const char *s1, const char *s2, int n);
char	*my_strdup(char *src);
int	my_getnbr(char *str);
int	my_str_isnum(char *str);
int	*init_order();

/*
********* Prototypes VM ***************
*/

int	my_header(char *av, t_vm *vm, int x, int add);
int	my_vm(char **av);
int	check_option(char **av, t_vm *vm);

#endif /* !COREWAR_H_ */
