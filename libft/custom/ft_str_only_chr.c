#include "../libft.h"

int	ft_str_only_chr(char *str, char searchedChar)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (str[i] != searchedChar)
			return (0);
		i++;
	}
	return (1);
}
