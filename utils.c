#include "bsp.h"

//* argument perc is up to 1 decimal place only, for example 48.8% success rate
bool	probability(float perc)
{
	int num;
	int rand;

	num = (int) (perc * 10);
	rand = rand_int(1, 1000);
	if (rand <= num)
		return (true);
	return (false);
}

int	rand_int(int lower, int upper)
{
	struct timeval	time;
	int				ret;

	gettimeofday(&time, NULL);
	srand(time.tv_usec);
	usleep(1);
	ret = rand() % (upper - lower + 1) + lower;
	return(ret);
}
