#include "bsp.h"

int	teach_them(void)
{
	printf("Usage: ./bsp [starting x-coordinate] [starting y-coordinate] ");
	printf("[map width] [map height]\n");
	return (1);
}

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

//* this is the part to randomize room size and randomness
void	create_room(t_leaf *node)
{
	if (node->left == NULL || node->right == NULL)
	{
		node->x = rand_int(node->x, node->x + 0.25 * node->width);
		node->y = rand_int(node->y, node->y + 0.25 * node->height);
		node->width = rand_int(0.5 * node->width, 0.75 * node->width);
		node->height = rand_int(0.5 * node->height, 0.75 * node->height);
		return ;
	}
	create_room(node->left);
	create_room(node->right);
}

void	fill_map(t_leaf *node, char **map)
{
	if (node->left == NULL || node->right == NULL)
	{
		for (int h = 0; h < node->height; h += 1)
			for (int w = 0; w < node->width; w += 1)
				map[node->y + h][node->x + w] = '*';
		return ;
	}
	fill_map(node->left, map);
	fill_map(node->right, map);
}

//* initialize all to space first because I can't print null character
char	**init_map(int width, int height)
{
	char	**map;

	map = calloc(height, sizeof(char *));
	for (int h = 0; h < height; h += 1)
		map[h] = calloc(width, sizeof(char));
	for (int h = 0; h < height; h += 1)
		for (int w = 0; w < width; w += 1)
			map[h][w] = ' ';
	return (map);
}

int	main(int argc, char **argv)
{
	t_leaf	*main;
	char	**map;

	if (argc != 5)
		return (teach_them());
	binary_split(&main, atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));
	create_room(main);
	map = init_map(atoi(argv[3]), atoi(argv[4]));	
	fill_map(main, map);


	//* Printing the map
	for (int h = 0; h < atoi(argv[4]); h += 1)
	{
		for (int w = 0; w < atoi(argv[3]); w += 1)
			printf("%c", map[h][w]);
		printf("\n");
	}

	return (0);
}