/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 20:30:06 by sabdulki          #+#    #+#             */
/*   Updated: 2023/08/24 17:31:05 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *c, int ch)
{
	int		i;
	char	*arr;

	i = 0;
	arr = (char *)c;
	while (arr[i] != '\0')
	{
		if (arr[i] == (char)ch)
			return (&arr[i]);
		i++;
	}
	if (arr[i] == (char)ch)
		return (&arr[i]);
	return (0);
}

int	slen(char *str, int truth)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (truth == 1)
		{
			if (str[i] == '\n')
				return (i);
		}
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i_len;
	int		i_main;
	char	*main_arr;

	if (!s1)
	{
		main_arr = malloc(sizeof(char) * 1);
		main_arr[0] = '\0'; 
	}
	if (!s1 || !s2)
		return (0);
	i_len = 0;
	i_main = 0;
	main_arr = malloc(sizeof(char) * (slen(s1, 0) + slen(s2, 0) + 1));
	if (main_arr == 0)
		return (0);
	while (i_len < slen(s1, 0))
		main_arr[i_main++] = s1[i_len++];
	i_len = 0;
	while (i_len < slen(s2, 0))
		main_arr[i_main++] = s2[i_len++];
	main_arr[i_main] = '\0';
	return (main_arr);
}

void	*free_linked_list(t_list *part) //, int all)
{
	// int	res;
	// if (all == 0)
	// {
	// 	free(part);
	// 	return (0);
	// }
	
	if (!part)
		return (NULL);
	if (part->next)
		free_linked_list(part->next); //, 1);
	if (part->content)
		free(part->content);
	//part->next = NULL;
	free(part);
	part = NULL;
	return (NULL);
}

char	*changes(t_list *node, t_list *rem)
{
	char	*line;
	char	*l;
	// t_list	*rem1;
	// static int res;
	// if ((!node && !rem))
	// 	return (NULL);
	// else if (!node && rem) // && ft_strchr(rem->content, '\n'))
	// {
	// 	if (ft_strchr(rem->content, '\n'))
	// 	{
	// 		line = fill_line(rem);
	// 		rem1 = create_rem(rem);
	// 		free_linked_list(rem);
	// 		rem = rem1;
	// 		res = 1;
	// 	}
	// 	else
	// 		return (0);
	// 	//return (line);
	// }
	// if (!node && rem && ft_strchr(rem->content, '\n'))
	// {
	// 	line = fill_line(rem);
	// 	rem1 = create_rem(rem);
	// 	free_linked_list(rem);
	// 	rem = rem1;
	// 	return (line);
	// }
	// if (!node && rem)
	// {
	// 	line = fill_line(rem);
	// 	// free_linked_list(rem);
	// 	free(rem->content);
	// 	free(rem);
	// 	rem = NULL;
	// 	return (line);
	// }
	if (node && !rem)
	{
		line = fill_line(node);
		return (line);
	}
	else if (node && rem)
	{
		l = fill_line(node);
		line = ft_strjoin(rem->content, l);
		free(l);
		free_linked_list(rem);
		return (line);
	}
	return (0);
}