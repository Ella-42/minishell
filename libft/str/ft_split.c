/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmarien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:23:29 by wmarien           #+#    #+#             */
/*   Updated: 2023/01/16 12:59:30 by wmarien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	count_strs(const char *str, char sep)
{
	int	i;
	int	ctr;

	i = 0;
	ctr = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] == sep)
			i++;
		if (str[i] != '\0')
			ctr++;
		while (str[i] != '\0' && str[i] != sep)
			i++;
	}
	return (ctr);
}

static int	ft_strlen_wrd(const char *str, char sep)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != sep)
		i++;
	return (i);
}

static char	*set_word(const char *str, char sep)
{
	char	*word;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen_wrd(str, sep);
	word = (char *)malloc((len + 1) * sizeof(char));
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(const char *s, char c)
{
	char	**strs;
	int		i;

	if (!s)
		return (0);
	strs = (char **)malloc((count_strs(s, c) + 1) * sizeof(char *));
	i = 0;
	if (!strs)
		return (0);
	while (*s != '\0')
	{
		while (*s != '\0' && *s == c)
			s++;
		if (*s != '\0')
		{
			strs[i] = set_word(s, c);
			i++;
		}
		while (*s != '\0' && *s != c)
			s++;
	}
	strs[i] = 0;
	return (strs);
}
