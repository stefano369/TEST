#include "so_long.h"

int initd_readm(void **mlx, t_game *game, const char *file_path) {
    *mlx = mlx_init();
    if (!*mlx)
        return 1;
    game->mlx = *mlx;
    game->map = read_map(file_path, game);
    if (!game->map) {
        mlx_destroy_display(*mlx);
        free(game->map);
        return 1;
    }
    return 0;
}

int create_window(t_game *game)
{
    game->win = mlx_new_window(game->mlx, game->cols * 64, game->rows * 64, "so_long");
    if (!game->win)
    {
        free_map(game->map);
        mlx_destroy_display(game->mlx);
        return 1;
    }
    return 0;
}

void render_map(void *mlx, void *win, t_assets *assets, char **map)
{
    int x, y;

    y = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            mlx_put_image_to_window(mlx, win, assets->floor, x * TILE_SIZE, y * TILE_SIZE);
            if (map[y][x] == '1')
                mlx_put_image_to_window(mlx, win, assets->wall, x * TILE_SIZE, y * TILE_SIZE);
            else if (map[y][x] == 'P')
                mlx_put_image_to_window(mlx, win, assets->player, x * TILE_SIZE, y * TILE_SIZE);
            else if (map[y][x] == 'C')
                mlx_put_image_to_window(mlx, win, assets->collectible, x * TILE_SIZE, y * TILE_SIZE);
            else if (map[y][x] == 'E')
                mlx_put_image_to_window(mlx, win, assets->exit, x * TILE_SIZE, y * TILE_SIZE);
            x++;
        }
        y++;
    }
}