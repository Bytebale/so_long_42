# include "so_long_bonus.h"
# include "../gnl/get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	char		*tmp_dest;
	const char	*tmp_src;

	if (!dest && !src)
		return (0);
	if (dest == src || len == 0)
		return (dest);
	tmp_dest = (char *) dest;
	tmp_src = (const char *) src;
	while (len--)
		*tmp_dest++ = *tmp_src++;
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	char	*tmp;
	size_t	len;

	len = ft_strlen((char *) s1) + 1;
	tmp = malloc(sizeof(char) * len);
	if (!tmp)
		return (NULL);
	tmp = ft_memcpy(tmp, s1, len);
	return (tmp);
}

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	const char	*s;
	const char	*lasts;
	char		*d;
	char		*lastd;

	d = dest;
	s = src;
	if (!dest && !src)
		return (0);
	if (d < s)
		while (len--)
			*d++ = *s++;
	else
	{
		lasts = s + (len - 1);
		lastd = d + (len - 1);
		while (len--)
			*lastd-- = *lasts--;
	}
	return (dest);
}

char	*ft_strjoin_bl(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	stot_len;
	char	*tmp;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	s1_len = ft_strlen((char *) s1);
	s2_len = ft_strlen((char *) s2);
	stot_len = s1_len + s2_len + 1;
	tmp = malloc(sizeof(char) * stot_len);
	if (!tmp)
		return (0);
	ft_memmove(tmp, s1, s1_len);
	ft_memmove(tmp + s1_len, s2, s2_len);
	tmp[stot_len - 1] = '\0';
	return (tmp);
}
