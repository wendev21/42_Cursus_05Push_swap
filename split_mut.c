/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_mut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:01:41 by wecorzo-          #+#    #+#             */
/*   Updated: 2023/11/27 16:46:29 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(char *str_n, char c)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	while (str_n[i])
	{
		if (str_n[i] != c && str_n[i + 1] || str_n[i + 1] == '\0')
			words++;
		i++;

	}
	return (words);
}

char	*get_next_word(char *str_n, char c)
{
	static int l_po;
	char		*next_word;
	int			len;
	int			i;

	i = 0;
	len = 0;
	l_po = 0;
	while (str_n[l_po] == c)
			i++;
	while (str_n[l_po + len] != 0 && str_n[l_po + len])
		len++;
	next_word = malloc(sizeof(char) * len);
	if (!next_word)
		return (NULL);
	while ((str_n[l_po] != c) && str_n[l_po])
		next_word[i++] = str_n[l_po++];
	next_word[i] = '\0';
	return (next_word);
}
char	**split_mut(char *str_n, char c)
{
	char 	**ptr;
	int 	i;
	int		wordcount;
	int		wordlen;

	wordcount = count_words(str_n, c);
	if (!wordcount)
		exit (1);
	ptr = malloc(sizeof(char *) * wordcount + 1);
	if (!ptr)
		return (NULL);
	while (wordcount-- >= 0)
	{
		if (i == 0)
		{
			ptr[i] = malloc(sizeof(char));
			if (!ptr[i])
				return (NULL);
			ptr[i++][0] = '\0';
			continue ;
		}
		ptr[i++] = get_next_word(str_n, c);
	}
	ptr[i] = NULL;

	return (ptr);
}
int main()
{
	char *str_n = "5 4 78 9 2 5 5";
	char **arr = split_mut(str_n, ' ');
	int i;

	i = 0;
	if (!arr)
		return (1);
	while (arr[1] !=  NULL)
	{
		printf("palabra %d%s \n", i +1, arr[i]);
	}
	return (0);
}