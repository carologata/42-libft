/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cogata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:09:01 by cogata            #+#    #+#             */
/*   Updated: 2023/07/24 14:09:03 by cogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(char const *s, char c)
{
	int	i;
	int	count_flag;
	int	count_word;

	i = 0;
	count_word = 0;
	count_flag = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			count_flag = 1;
		else if (s[i] != c && count_flag == 1)
		{
			count_word = count_word + 1;
			count_flag = 0;
		}
		i++;
	}
	return (count_word);
}

char	**ft_init_words(char const *s, char **words, int k, int count_letters)
{
	int	l;

	l = 0;
	while (l < count_letters)
	{
		words[0][l] = s[k];
		k++;
		l++;
	}
	words[0][l] = '\0';
	return (words);
}

char	**ft_logic(char const *s, char **words, char c, int count_word)
{
	int	i;
	int	j;
	int	count_letters;

	i = 0;
	j = 0;
	while (i < count_word)
	{
		count_letters = 0;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j] != '\0')
		{
			count_letters = count_letters + 1;
			j++;
		}
		words[i] = malloc((count_letters + 1) * sizeof(char));
		if (words[i] == NULL)
			return (NULL);
		else
			ft_init_words(s, &words[i], j - count_letters, count_letters);
		i++;
	}
	words[count_word] = NULL;
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	int		count_word;

	count_word = ft_count_words(s, c);
	words = malloc((count_word + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	ft_logic(s, words, c, count_word);
	return (words);
}

/* #include <stdio.h>

int	main(void)
{
	char **p;
	char const *s = "ABCDE df dfasd  dfads f  dfa ";
	p = ft_split(s, ' ');

	int i = 0;
	while (i < 6)
	{
		printf("%s\n", p[i]);
		i++;
	}
} */