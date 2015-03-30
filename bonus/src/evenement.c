/*
** evenement.c for  in /home/belfio_u/rendu/Allum1
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Mon Feb  2 18:47:55 2015 ugo belfiore
** Last update Mon Mar 30 14:28:09 2015 ugo belfiore
*/

#include "../lib/minilibx/mlx.h"
#include "../include/mini.h"
#include "../include/my.h"

/*
** evenememnt clavier
*/

int		manage_key(int keycode, void *param)
{
  t_data	*d;

  d = (t_data *)param;
  if (keycode == KEY_KILL || keycode == KEY_ESC)
    quitt(d);
  if (keycode == KEY_REFRESH)
    {
      tab_init(d);
      pic_init(d);
    }
  if (keycode == KEY_LEFT)
    d->m.x_cible[0] -= 20;
  if (keycode == KEY_RIGHT)
    d->m.x_cible[0] += 20;
  if (keycode == KEY_UP)
    d->m.y_cible[0] -= 20;
  if (keycode == KEY_DOWN)
    d->m.y_cible[0] += 20;
  return (0);
}

/*
** evenement expose
** est appelé dès que la fenêtre à besoin d'être recalculé
** PS: est appelé aussi la première fois que le pregramme s'active.
*/

int		manage_expose(void *param)
{
  t_data	*d;

  d = (t_data *)param;
  mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->p.back, 0, 0);
  return (0);
}

/*
** evenement frame
** est appelé à chaque frame du corwar, l'utiisation de usleep
**	permet de ralentir le processus.
*/

/* void	*thread_1(void *arg) */
/* { */
/*   printf("Nous sommes dans le thread.\n"); */
/*   /\* Pour enlever le warning *\/ */
/*   (void) arg; */
/*   pthread_exit(NULL); */
/* } */

int		manage_frame(void *param)
{
  t_data	*d;
  int		j;
  int		i;
  double	tmp_a;

  d = (t_data *)param;
  usleep(4000);
  i = -1;
  j = -1;
  aff_rec_i(d, d->m.x_cible[0] - 3, d->m.y_cible[0] - 3,
  	    d->m.x_cible[0] + 3, d->m.y_cible[0] + 3);
  while (++j < d->m.y_file)
    {
      while (++i < d->m.x_file)
  	{
	  if (!(random() % 5))
	    {
	      tmp_a = (atan2(((d->m.tab[j][i].YPos - d->m.y_cible[0]) * -1),
			     (d->m.tab[j][i].XPos - d->m.x_cible[0]) * 1))
		* (180.0 / PI) + 180;
	      d->m.tab[j][i].angl +=
		MAX(MIN((((int)(tmp_a - d->m.tab[j][i].angl + 540) % 360)
			 - 180), d->m.tab[j][i].turn),
		    -1 * d->m.tab[j][i].turn);
	      d->m.tab[j][i].XVel = cos(d->m.tab[j][i].angl / 180.0 * PI) *
		d->m.tab[j][i].vel;
	      d->m.tab[j][i].YVel= - sin(d->m.tab[j][i].angl / 180.0 * PI) *
		d->m.tab[j][i].vel;
	    }
	  d->m.tab[j][i].XPos += d->m.tab[j][i].XVel;
	  d->m.tab[j][i].YPos += d->m.tab[j][i].YVel;
	  aff_particule(d, i, j);
  	}
      i = -1;
    }
  mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->p.back, 0, 0);
  return (0);
}

/*
** c'est ici que s'opère toute les opérations de la fenêtre
** la boucle loop se répète et appelera tout les évenement nécessaire.
*/

void		aff_win()
{
  t_data	d;

  d.m.x_cible[0] = 700;
  d.m.y_cible[0] = 450;
  d.x_max = 1400;		//size en x
  d.y_max = 900;		//size en y
  d.colo = COLOR_PURPLE;	//initialise la couleur
  sound_init(&d);		//initialise les sons
  d.mlx_ptr = mlx_init();
  if (d.mlx_ptr == NULL)
    exit(0);
  d.win_ptr = mlx_new_window(d.mlx_ptr, d.x_max, d.y_max, "corwar");
  d.img_ptr = mlx_new_image(d.mlx_ptr, d.x_max, d.y_max);
  d.bigData = mlx_get_data_addr(d.img_ptr, &d.bpp, &d.sizeline, &d.endian);
  tab_init(&d);			//initialise le tableau
  pic_init(&d);			//initialise les image

  mlx_expose_hook(d.win_ptr, &manage_expose, (void *)(&d));
  mlx_hook(d.win_ptr, 3, 3, &manage_key, (void *)(&d));
  mlx_loop_hook(d.mlx_ptr, &manage_frame, (void *)(&d));
  mlx_loop(d.mlx_ptr);
}
