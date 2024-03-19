#include "so_long.h"

int main(int argc, char **argv)
{   
    t_game  game;
    int     fd;

    if (argc != 2)
       print_error(1);
    init_param (&game);
    verify_map_name(argv[1], ".ber");
    fd = open(argv[1], O_RDONLY);
    read_map(fd, &game);
    close (fd);
    validate_map(&game);
    //free_game(&game);
    return (0);
}

