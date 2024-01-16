/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_mut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:01:41 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/01/16 15:21:29 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_countwords(char const *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

int	ft_checkadd(const char *s, size_t i, size_t wordlen)
{
	if (s[i + wordlen] != '\0')
		i = wordlen + i + 1;
	else
		i = wordlen + i;
	return (i);
}

char	**ft_freeall(char **ptr, size_t i)
{
	while (i > 0)
	{
		i--;
		free(ptr[i]);
	}
	free (ptr);
	return (NULL);
}

size_t	ft_lenword(const char *s, char c, size_t i)
{
	size_t	wordlen;

	wordlen = 0;
	while (s[wordlen + i] != c && s[wordlen + i] != '\0')
		wordlen++;
	return (wordlen);
}

char	**split_mut(const char *s, char c)
{
	char	**ptr;
	size_t	i;
	size_t	wordcount;
	size_t	wordlen;

	ptr = malloc(sizeof(char *) * (ft_countwords(s, c) + 1));
	if (!ptr)
		return (ptr = NULL, NULL);
	i = 0;
	wordcount = 0;
	while (s[i])
	{
		wordlen = ft_lenword(s, c, i);
		if (s[i] != c)
		{
			ptr[wordcount] = ft_substr(s, i, wordlen);
			if (!ptr[wordcount])
				return (ft_freeall(ptr, wordcount));
			wordcount++;
		}
		i = ft_checkadd(s, i, wordlen);
	}
	ptr[wordcount] = NULL;
	return (ptr);
}
