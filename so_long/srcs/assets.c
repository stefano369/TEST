#include "so_long.h"

int load_assets(t_game *game, t_assets *assets)
{
    if (!load_textures(game->mlx, assets) || !load_obj(game->mlx, assets))
    {
        free_assets(game->mlx, assets);
        free_map(game->map);
        mlx_destroy_window(game->mlx, game->win);
        mlx_destroy_display(game->mlx);
        return 1;
    }
    return 0;
}

void *load_sprite(void *mlx, char *path)
{
    int width, height;
    void *sprite;

    sprite = mlx_xpm_file_to_image(mlx, path, &width, &height);
    if (!sprite)
    {
        ft_printf("Error: Could not load sprite from %s\n", path);
        exit(EXIT_FAILURE);
    }
    return sprite;
}

int load_textures(void *mlx, t_assets *assets)
{
    assets->wall = load_sprite(mlx, "assets/wall.xpm");
    if (!assets->wall)
        return 0;

    assets->floor = load_sprite(mlx, "assets/floor.xpm");
    if (!assets->floor)
    {
        mlx_destroy_image(mlx, assets->wall);
        return 0;
    }

    return 1;
}

int load_obj(void *mlx, t_assets *assets)
{
    assets->player = load_sprite(mlx, "assets/player.xpm");
    if (!assets->player)
        return 0;

    assets->collectible = load_sprite(mlx, "assets/collectible.xpm");
    if (!assets->collectible)
    {
        mlx_destroy_image(mlx, assets->player);
        return 0;
    }

    assets->exit = load_sprite(mlx, "assets/exit.xpm");
    if (!assets->exit)
    {
        mlx_destroy_image(mlx, assets->player);
        mlx_destroy_image(mlx, assets->collectible);
        return 0;
    }

    return 1;
}

void free_assets(void *mlx, t_assets *assets)
{
    if (assets->wall)
    {
        mlx_destroy_image(mlx, assets->wall);
        assets->wall = NULL;
    }
    if (assets->floor)
    {
        mlx_destroy_image(mlx, assets->floor);
        assets->floor = NULL;
    }
    if (assets->player)
    {
        mlx_destroy_image(mlx, assets->player);
        assets->player = NULL;
    }
    if (assets->collectible)
    {
        mlx_destroy_image(mlx, assets->collectible);
        assets->collectible = NULL;
    }
    if (assets->exit)
    {
        mlx_destroy_image(mlx, assets->exit);
        assets->exit = NULL;
    }
}