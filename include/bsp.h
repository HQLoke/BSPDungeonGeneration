#ifndef BSP_H
# define BSP_H

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

enum e_size{MIN_LEAF_SIZE = 6, MAX_LEAF_SIZE = 20};

typedef struct	s_leaf
{
	int				x;
	int				y;
	int				width;
	int				height;
	struct s_leaf	*left;
	struct s_leaf	*right;
}	t_leaf;

//* utils.c
bool	probability(float perc);
int		rand_int(int lower, int upper);

#endif