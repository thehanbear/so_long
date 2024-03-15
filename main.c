#include "so_long.h"

int main(int argc, char **argv)
{   
    t_game  game;

    if (argc != 2)
        return (1);
    if (verify_map_name(argv[1], ".ber") != 0)
		return (1);
    read_map(argv[1], &game);
    
    return (0);
}

