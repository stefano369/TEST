#include "so_long.h"

static int setup(t_game *game, t_assets *assets, const char *map_path)
{
    if (initd_readm(&game->mlx, game, map_path)) 
        return 0;

    if (validate_player_and_map(game))
        return 0;

    if (create_window(game))
        return 0;

    if (load_assets(game, assets))
        return 0;

    return 1;
}

int main(void)
{
    t_assets assets = {0};
    t_game   game = {0};

    game.assets = &assets;
    if (!setup(&game, &assets, "maps/map.ber"))
        return 1;

    setup_hooks(&game);

    render_map(game.mlx, game.win, &assets, game.map);
    mlx_loop(game.mlx); //game loop

    free_assets(game.mlx, &assets);
    free_map(game.map);
    mlx_destroy_window(game.mlx, game.win);
    mlx_destroy_display(game.mlx);
    return 0;
}