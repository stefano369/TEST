#include "so_long.h"

static int flood_fill(char **map, int x, int y)
{
    if (x < 0 || y < 0 || map[y] == NULL || map[y][x] == '\0')
        return 0;
    if (map[y][x] == '1' || map[y][x] == 'V')
        return 0;

    map[y][x] = 'V';

    flood_fill(map, x + 1, y);
    flood_fill(map, x - 1, y);
    flood_fill(map, x, y + 1);
    flood_fill(map, x, y - 1);

    return 1;
}

int validate_player_and_map(t_game *game)
{
    game->p_x = fp_x(game);
    game->p_y = fp_y(game);
    if (game->p_x == -1 || game->p_y == -1)
    {
        mlx_destroy_display(game->mlx);
        free_map(game->map);
        return 1;
    }

    if (!validate_map(game, game->p_x, game->p_y))
    {
        mlx_destroy_display(game->mlx);
        free_map(game->map);
        return 1;
    }

    return 0;
}

int validate_map(t_game *game, int x, int y)
{
    char **map_copy = duplicate_map(game);
    if (!map_copy)
        return 0;

    if (!flood_fill(map_copy, x, y))
    {
        free_map(map_copy);
        return 0;
    }
    y = 0;
    while (map_copy[y])
    {
        x = 0;
        while (map_copy[y][x])
        {
            if (map_copy[y][x] == 'C' || map_copy[y][x] == 'E')
            {
                free_map(map_copy);
                return 0;
            }
            x++;
        }
        y++;
    }
    free_map(map_copy);
    return 1;
}

char **duplicate_map(t_game *game)
{
    int rows = 0;
    while (game->map[rows])
        rows++;

    char **copy = malloc(sizeof(char *) * (rows + 1));
    if (!copy)
        return NULL;

    int i = 0;
    while (i < rows)
    {
        copy[i] = ft_strdup(game->map[i]);
        if (!copy[i])
        {
            while (i > 0)
                free(copy[--i]);
            free(copy);
            return NULL;
        }
        i++;
    }
    copy[rows] = NULL;
    return copy;
}

void free_map(char **map)
{
    int i = 0;

    if (!map)
        return;

    while (map[i])
    {
        free(map[i]);
        i++;
    }

    free(map);
}