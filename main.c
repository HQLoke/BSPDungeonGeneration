#include "bsp.h"

void	binary_split(t_leaf **self, int x, int y, int width, int height)
{
	bool	splitH;
	int		max;
	int		split;
	t_leaf	*tmp;

	*self = calloc(1, sizeof(t_leaf));
	tmp = *self;
	tmp->x = x;
	tmp->y = y;
	tmp->width = width;
	tmp->height = height;
	tmp->left = NULL;
	tmp->right = NULL;
	splitH = probability(50.0);
	if (width > height && (float)width / (float)height >= 1.25)
		splitH = false;
	else if (height > width && (float)height / (float)width >= 1.25)
		splitH = true;
	if (splitH == true)
		max = height - MIN_LEAF_SIZE;
	else
		max = width - MIN_LEAF_SIZE;
	if (max <= MIN_LEAF_SIZE)
		return ;
	split = rand_int(MIN_LEAF_SIZE, max);
	if (splitH)
	{
		binary_split(&tmp->left, x, y, width, split);
		binary_split(&tmp->right, x, y + split, width, height - split);
	}
	else
	{
		binary_split(&tmp->left, x, y, split, height);
		binary_split(&tmp->right, x + split, y, width - split, height);
	}
}

int	teach_them(void)
{
	printf("Usage: ./bsp [starting x-coordinate] [starting y-coordinate] ");
	printf("[map width] [map height]\n");
	return (1);
}

int	main(int argc, char **argv)
{
	t_leaf	*main;

	if (argc != 5)
		return (teach_them());
	binary_split(&main, atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));
	// fill_map();
	return (0);
}