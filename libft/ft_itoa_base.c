#include "libft.h"

int	convert_len(long nbr, int tbase)
{
	int	len;

	len = 0;
	if (nbr < 0)
	{
		len ++;
		nbr *= -1;
	}
	while (nbr > tbase)
	{
		len++;
		nbr /= tbase;
	}
	len++;
	return (len);
}

char	*ft_itoa_base_write(char *final, int i, char *base, long nb)
{
	int	len;
	int	tbase;

	tbase = 0;
	while (base[tbase] && tbase <= 255)
		tbase++;
	if (nb < 0)
		nb *= -1;
	len = convert_len(nb, tbase);
	final[i + len] = 0;
	while (len > 0)
	{
		final[i + len - 1] = base[(nb % tbase)];
		nb /= tbase;
		len--;
	}
	return (final);
}

char	*ft_itoa_base(int nbr, char *base)
{
	int			tbase;
	int			len;
	char		*final;

	tbase = 0;
	while (base[tbase] && tbase <= 255)
		tbase++;
	len = convert_len(nbr, tbase);
	final = malloc(sizeof(char) * (len + 1));
	if (!final)
		return (NULL);
	if (nbr < 0)
	{
		final[0] = '-';
		return (ft_itoa_base_write(final, 1, base, nbr));
	}
	return (ft_itoa_base_write(final, 0, base, nbr));
}
