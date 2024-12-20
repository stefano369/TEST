#include "so_long.h"

static int add_layers(char ***map, char *line, t_game *game)
{
    int length = ft_strlen(line) - (line[ft_strlen(line) - 1] == '\n');

    if (game->cols == 0)
        game->cols = length;
    else if (game->cols != length)
        return (ft_printf("Error\nMap is not rectangular.\n"), free(line), -1);

    char **temp = realloc(*map, sizeof(char *) * (game->rows + 2));
    if (!temp)
        return (ft_printf("Error\nMemory allocation failed.\n"), free(line), -1);

    *map = temp;
    (*map)[game->rows] = line;
    game->rows++;

    return (0);
}

char **read_map(const char *file_path, t_game *game)
{
    int fd = open(file_path, O_RDONLY);
    if (fd < 0)
    {
        ft_printf("Error\nUnable to open file: %s\n", file_path);
        return NULL;
    }

    char **map = NULL;
    char *line;
    game->rows = 0;
    game->cols = 0;

    while ((line = get_next_line(fd)) != NULL)
    {
        if (ft_strlen(line) <= 1)
        {
            free(line);
            continue;
        }

        if (add_layers(&map, line, game) == -1)
        {
            free_map(game->map);
            close(fd);
            return NULL;
        }
    }

    close(fd);

    if (game->rows == 0 || !map)
    {
        ft_printf("Error\nMap is empty or invalid.\n");
        free_map(game->map);
        return NULL;
    }

    map[game->rows] = NULL;

    free(line);
    return map;
}

int fp_x(t_game *game)
{
    int y = 0;
    while (game->map[y])
    {
        int x = 0;
        while (game->map[y][x])
        {
            if (game->map[y][x] == 'P')
                return x;
            x++;
        }
        y++;
    }
    return -1;
}

int fp_y(t_game *game)
{
    int y = 0;
    while (game->map[y])
    {
        int x = 0;
        while (game->map[y][x])
        {
            if (game->map[y][x] == 'P')
                return y;
            x++;
        }
        y++;
    }
    return -1;
}