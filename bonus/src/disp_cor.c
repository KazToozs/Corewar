/*
** disp_cor.c for  in /home/belfio_u/rendu/corwarr/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Thu Feb  5 22:13:14 2015 ugo belfiore
** Last update Mon Mar 30 14:32:44 2015 ugo belfiore
*/

#include "../lib/minilibx/mlx.h"
#include "../include/mini.h"
#include "../include/my.h"

void	tab_init(t_data *d)
{
  int   j;
  int   i;

  i = -1;
  j = -1;
  d->m.y_file = 6;
  d->m.x_file = 1024;
  d->m.tab = malloc(d->m.y_file * sizeof(*d->m.tab));
  (d->m.tab == NULL) ? exit(0) : 1;
  while (++j < d->m.y_file)
    {
      d->m.tab[j] = malloc(d->m.x_file * sizeof(**d->m.tab));
      (d->m.tab[j] == NULL) ? exit(0) : 1;
      while (++i < d->m.x_file)
	{
	  d->m.tab[j][i].color_particle = 0;
	  d->m.tab[j][i].priorite_cible = 0;
	  d->m.tab[j][i].XPos = 700;
	  d->m.tab[j][i].YPos = 450;
	  d->m.tab[j][i].vel = 5 + random() % 5;
	  d->m.tab[j][i].angl = random() % 360;
	  d->m.tab[j][i].XVel += cos((d->m.tab[j][i].angl / 180.0 * PI))
				     * d->m.tab[j][i].vel;
	  d->m.tab[j][i].YVel += -sin((d->m.tab[j][i].angl / 180.0 * PI))
				     * d->m.tab[j][i].vel;
	  d->m.tab[j][i].turn = 15 + random() % 5;
	  d->m.tab[j][i].tail_x[0] = d->m.tab[j][i].XPos;
	  d->m.tab[j][i].tail_y[0] = d->m.tab[j][i].YPos;
	}
      i = -1;
    }
}

void	pic_init(t_data *d)
{
  d->p.back = mlx_xpm_file_to_image(d->mlx_ptr,"./texture/pic/back.xpm",
				      &d->p.save1, &d->p.save2);
  (!d->p.back) ? quitt(d) : 1;
  d->p.bData = mlx_get_data_addr(d->p.back, &d->p.bpp, &d->p.size, &d->p.end);
}

void	aff_particule(t_data *d, int i, int j)
{
  int	test = -1;

  d->colo = COLOR_BLACK;
  while (++test < 3)
    aff_circle(d, d->m.tab[j][i].XPos, d->m.tab[j][i].YPos, test);
}
