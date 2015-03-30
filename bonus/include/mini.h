/*
** mini.h for  in /home/belfio_u/rendu/EXOTEST/FDF
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Tue Oct 28 09:26:37 2014 ugo belfiore
** Last update Mon Mar 30 14:20:55 2015 ugo belfiore
*/

#ifndef MINI_H_
#define MINI_H_

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <math.h>
#include <time.h>
#include "fmod.h"
#include <pthread.h>

/*
** define: couleur en hexadécimale.
*/

#define COLOR_YELLOW 0xFFFF00
#define COLOR_BLACK 0x000000
#define COLOR_WHITE 0xFFFFFF
#define COLOR_RED 0xFF0000
#define COLOR_GREEN 0x33FF00
#define COLOR_PURPLE 0xFF00FF
#define COLOR_BLUE 0x0033FF
#define COLOR_GREY 0x202020

/*
** define: clavier.
*/

#define KEY_ENTER 65293
#define KEY_ESC 65307
#define KEY_REFRESH 65471
#define KEY_KILL 107
#define KEY_RIGHT 65363
#define KEY_LEFT 65361
#define KEY_UP 65362
#define KEY_DOWN 65364

/*
** define: math
*/

#define MAX(a,b) ((a) > (b)) ? (a) : (b)
#define MIN(a,b) ((a) < (b)) ? (a) : (b)
#define MY_ABS(a) ((a) < 0) ? (-a) : (a)
#define PI 3.14159265

/*
** structure cercle
*/

typedef struct	s_circle
{
  int		x_mid;
  int		y_mid;
  int		x;
  int		y;
  int		r;
  int		di;
}		t_circle;

/*
** stucture son
*/

typedef struct	s_sound
{
  FMOD_SYSTEM	*system;
  FMOD_SOUND	*bonus1;
}		t_sound;

/*
** tructure picture
*/

typedef struct	s_pic
{
  void		*back;
  char		*bData;
  int		bpp;
  int		size;
  int		end;
  int		save1;
  int		save2;
}		t_pic;

typedef struct	s_obj
{
  int		color_particle;
  int		priorite_cible;
  double	XPos;
  double	YPos;
  double	XVel;
  double	YVel;
  int		vel;
  int		angl;
  double	turn;
  int		tail_x[3];
  int		tail_y[3];
}		t_obj;

typedef struct	s_mod
{
  t_obj		**tab;
  int		y_file;
  int		x_file;
  double	x_cible[5];
  double	y_cible[5];
}		t_mod;

/*
** data: structure principale contenant les pointeurs
**	de fenêtreet d'image, contient le tableau **tab,
*/

typedef struct	s_data
{
  void		*mlx_ptr;
  void		*win_ptr;
  void		*img_ptr;
  char		*bigData;
  int		x_max;
  int		y_max;
  int		colo;
  int		bpp;
  int		sizeline;
  int		endian;
  t_mod		m;
  t_sound	sd;
  t_pic		p;
}               t_data;

/*
** fonction divers.
*/

void	tab_init(t_data *d);
void	pic_init(t_data *d);
void	aff_particule(t_data *d, int i, int j);
void	aff_win();
void	aff_pix_img(t_data *d, int x, int y);
void	aff_pix_img_i(t_data *d, int x, int y);
void	aff_circle(t_data *d, int x, int y, int r);
void	aff_rec(t_data *d, int x1, int y1, int x2, int y2);
void	aff_rec_i(t_data *d, int x1, int y1, int x2, int y2);
void	sound_init(t_data *d);
void	quitt(t_data *d);

/*
** fonction evenement minilibix
*/

int	manage_key(int keycode, void *param);
int	manage_expose(void *param);

#endif