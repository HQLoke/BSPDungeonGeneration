#include "bsp.h"

void	add_leaf(int width, int height)
{
	t_leaf	*new;

	new = calloc(1, sizeof(t_leaf));
}

void	split(t_leaf *self, int x, int y, int width, int height)
{
	bool splitH;

	self->x = x;
	self->y = y;
	self->width = width;
	self->height = height;
	splitH = probability(50.0);
	if (width > height && (float)width / (float)height >= 1.25)
		splitH = false;
	else if (height > width && (float)height / (float)width >= 1.25)
		splitH = true;
	if (splitH)
	{

	}
	else
	{

	}
}

int	main(void)
{
	t_leaf	*main;

	printf("%f\n", (float)(2 / 3));
	return (0);
}