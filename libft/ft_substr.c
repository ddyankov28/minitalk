/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:33:54 by ddyankov          #+#    #+#             */
/*   Updated: 2022/10/20 10:04:02 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	a;

	if (s)
	{
		if (start >= ft_strlen(s))
			return (ft_strdup(""));
		if (ft_strlen(s) > len)
			subs = (char *)malloc(sizeof(char) * (len + 1));
		if (ft_strlen(s) <= len)
			subs = (char *)malloc(sizeof(char) * (ft_strlen(s) - start + 1));
		if (!subs)
			return (NULL);
		a = 0;
		while (a < len && s[start + a] != '\0')
		{
			subs[a] = s[start + a];
			a++;
		}
		subs[a] = '\0';
		return (subs);
	}
	return (0);
}
