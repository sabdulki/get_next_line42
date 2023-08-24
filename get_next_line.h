/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:20:12 by sabdulki          #+#    #+#             */
/*   Updated: 2023/08/24 18:49:40 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct s_list //struct_list
{
	char			*content;
	struct s_list	*next;
}	t_list; // type_list

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4
#endif

void *free_linked_list(t_list *part); //, int all);
t_list	*make_a_node(int fd); //, t_list *rem);
t_list	*create_rem(t_list *last_node);
//void	free_list(t_list *node);
char	*ft_strchr(char *c, int ch);
//char	*sum_up(char *line, t_list *rem);
char	*create_line(t_list *node, t_list *rem);
char	*ft_strjoin(char *s1, char *s2);
//char	*ft_strdup(char *s1);
char	*get_next_line(int fd);
char	*fill_line(t_list *node);
int		count_chars_in_line(t_list *node);
//int 	ft_strlen_until_n(char *str);
int		slen(char *str, int truth);
//int		ft_strlen(char *str);

#endif 