#include "so_long.h"

void setup_hooks(t_game *game)
{
    mlx_hook(game->win, 2, 1L << 0, X_keypress, game);
    mlx_hook(game->win, 17, 0, X_close, game);
}