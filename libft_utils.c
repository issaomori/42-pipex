/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gissao-m <gissao-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 21:21:49 by gissao-m          #+#    #+#             */
/*   Updated: 2022/09/14 11:42:59 by gissao-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		count_s1;
	int		count_s2;
	char	*join;
	size_t	lenght;

	count_s1 = -1;
	count_s2 = -1;
	if (s1 == 0 || s2 == 0)
		return (NULL);
	lenght = ft_strlen(s1) + ft_strlen(s2) + 1;
	join = (char *)malloc(lenght);
	if (join == 0)
		return (NULL);
	while (s1[++count_s1] != '\0')
		join[count_s1] = s1[count_s1];
    join[count_s1] = '/';
	while (s2[++count_s2] != '\0')
		join[count_s1 + count_s2] = s2[count_s2];
	join[count_s1 + count_s2] = '\0';
	return (join);
}

int	ft_strlen(const char *str)
{
	int	count_size;

	count_size = 0;
	if (str == NULL)
		return (0);
	while (str[count_size])
		count_size++;
	return (count_size);
}