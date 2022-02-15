#include "push_swap.h"

size_t			ft_strlen(const char *str)
{
	char		*s;

	s = (char *)str;
	while (*s)
		s++;
	return (s - str);
}
