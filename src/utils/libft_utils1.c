/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gissao-m <gissao-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 21:21:49 by gissao-m          #+#    #+#             */
/*   Updated: 2022/09/19 17:39:55 by gissao-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	lenght_s1;

	if (s1 == NULL || set == NULL)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1) != NULL)
		s1++;
	lenght_s1 = ft_strlen(s1);
	while (lenght_s1 && ft_strchr(set, s1[lenght_s1]))
		lenght_s1--;
	return (ft_substr((char *)s1, 0, lenght_s1 + 1));
}

char	*ft_strchr(const char *p, int ch)
{
	unsigned char	*str;
	unsigned char	i;

	i = (unsigned char) ch;
	str = (unsigned char *) p;
	while (*str != i && *str != '\0')
		str++;
	if (*str == i)
		return ((char *)str);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	cat_len_s;
	char	*dest;

	if (!s)
		return (NULL);
	cat_len_s = ft_strlen(s);
	if (cat_len_s <= len)
		len = cat_len_s - start;
	if (start > cat_len_s)
		return (ft_strdup(""));
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s + start, len + 1);
	return (dest);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t d_size)
{
	size_t	count_size;
	size_t	l_src;

	l_src = ft_strlen(src);
	count_size = 0;
	if (d_size == 0)
		return (l_src);
	while (src[count_size] != '\0' && count_size < (d_size - 1))
	{
		dst[count_size] = src[count_size];
		count_size++;
	}
	dst[count_size] = '\0';
	return (l_src);
}

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		count_size;
	int		i;

	count_size = ft_strlen(src);
	dest = (char *) malloc(sizeof(char) * (count_size + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < count_size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
