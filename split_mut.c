/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_mut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:01:41 by wecorzo-          #+#    #+#             */
/*   Updated: 2023/12/04 12:40:01 by wecorzo-         ###   ########.fr       */
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
		if (str_n[i] != c && (str_n[i + 1] == c || str_n[i + 1] == '\0'))
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

	while (str_n[l_po] == c && str_n[l_po + 1] != '\0')
			l_po++;
	while (str_n[l_po + len] != 0 && str_n[l_po + len] != c)
		len++;
	next_word = malloc(sizeof(char) * (len + 1));
	if (!next_word)
		return (NULL);
	while ((str_n[l_po] != c) && str_n[l_po])
		next_word[i++] = str_n[l_po++];
	l_po++;
	//revisr strlen por ft_strlen
	if (strlen(str_n) <= l_po)
		l_po = 0;
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
	i = 0;
	while (i < wordcount)
	{
		ptr[i++] = get_next_word(str_n, c);
	}
	ptr[i] = NULL;

	return (ptr);
}
/*
int main(int argc, char **argv) {
    char **result;
    int j, i;

    j = 1;
    while (argc > j) {
        result = split_mut(argv[j], ' ');

        i = 0;
        while (result[i] != NULL) {
            printf("%d  %s\n", (i + 1), result[i]);
            free(result[i]);  // Free the memory allocated for each word
            i++;
        }

        free(result);  // Free the array of pointers
        j++;
    }

    return 0;
}*/
