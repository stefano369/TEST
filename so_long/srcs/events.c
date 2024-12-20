#include "so_long.h"

int X_close(t_game *game)
{
    free_assets(game->mlx, game->assets);
    mlx_destroy_window(game->mlx, game->win);
    mlx_destroy_display(game->mlx);
    free_map(game->map);
    free(game->mlx);
    exit(0);
    return (0);
}

int X_keypress(int keycode, void *param)
{
    if (keycode == 65307)
        {
            exit(0);
        }
    if (keycode == 65362)
        ft_printf("Move up\n");
    if (keycode == 65361)
        ft_printf("Move left\n");
    if (keycode == 65364)
        ft_printf("Move down\n");
    if (keycode == 65363)
        ft_printf("Move right\n");
    return (0);
}
