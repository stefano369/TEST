#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"

# define ERROR -1
# define TILE_SIZE 64

//ASSETS STRUCT
typedef struct s_assets {
    void *wall;
    void *floor;
    void *player;
    void *collectible;
    void *exit;
} t_assets;

//GAME STRUCT
typedef struct s_game {
    void    *mlx;
    void    *win;
    char    **map;
    t_assets *assets;
    int p_x;
    int p_y;
    int cols;
    int rows;
} t_game;

//graph
int initd_readm(void **mlx, t_game *game, const char *file_path);
int create_window(t_game *game);
void render_map(void *mlx, void *win, t_assets *assets, char **map);

//assets
int load_assets(t_game *game, t_assets *assets);
void *load_sprite(void *mlx, char *path);
int load_obj(void *mlx, t_assets *assets);
int load_textures(void *mlx, t_assets *assets);
void free_assets(void *mlx, t_assets *assets);

//### ### ###
//map
char **read_map(const char *file_path, t_game *game);
int fp_x(t_game *game);
int fp_y(t_game *game);

int validate_player_and_map(t_game *game);
int validate_map(t_game *game, int x, int y);
char **duplicate_map(t_game *game);

void free_map(char **map);
//### ### ###

//inputs
void setup_hooks(t_game *game);
int X_keypress(int keycode, void *param);
int X_close(t_game *game);

#endif
