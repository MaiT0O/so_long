#include "../libft.h"

int	ft_strcmp(char *first, char *second)
{
    size_t	i;

    i = 0;
    while (first[i] && second[i])
    {
        if (first[i] != second[i])
            return ((unsigned char)first[i] - (unsigned char)second[i]);
        i++;
    }
    return ((unsigned char)first[i] - (unsigned char)second[i]);
}
