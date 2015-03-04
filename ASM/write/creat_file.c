/*
** creat_file.c for  in /home/msa_m/Epitech/C_Prog_Elem/CPE_2014_corewar/ASM/write
** 
** Made by msa_m
** Login   <msa_m@epitech.net>
** 
** Started on  Wed Mar  4 11:41:46 2015 msa_m
** Last update Wed Mar  4 14:29:31 2015 msa_m
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h> // strlen
#include <sys/types.h> // creat
#include <sys/stat.h> // creat
#include <fcntl.h> // creat
#include <stdio.h>

void	creat_file(char *name)
{
  char	*file;
  char	*cor;
  int	c;
  int	i;
  
  cor = ".cor";
  if ((file = malloc(sizeof(char) * (strlen(name)) + 3)) == NULL)
    exit(-1);
  c = 0;
  while (name[c] != '.' && name[c] != '\0')
    {
      file[c] = name[c];
      c++;
    }
  i = 0;
  while (cor[i] != '\0')
  {
    file[c] = cor[i];
    c++;
    i++;
  }
  printf("%s\n", file);
  creat(file, O_CREAT | O_RDWR);
  free(file);
}

int	main(int ac, char **av)
{
  if (ac >= 2)
    creat_file(av[1]);
}
