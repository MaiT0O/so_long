#include "so_long.h"

void    display_character(t_game *game, t_perso *perso)
{
    mlx_clear_window(game->mlx_ptr, game->win_ptr);
    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, perso->img, perso->x, perso->y);
}

int	move(int keycode, t_perso *perso)
{
	if (keycode == 122) 	// Z
		perso->y -= 10;
	else if (keycode == 115)// S
		perso->y += 10;
	else if (keycode == 113)// Q
		perso->x -= 10;
	else if (keycode == 100)// D
		perso->x += 10;
	display_character(perso);
	return (0);
}

int	key_press(int keycode, t_game *game, t_perso *perso)
{
	if (keycode == 65307)
		close_window(game);
	move(keycode, perso);
	return (0);
}

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	exit(0);
	return (0);
}