/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 19:55:53 by sabdulki          #+#    #+#             */
/*   Updated: 2023/08/24 19:03:26 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*create_rem(t_list *node)
{
	int		i_ln;
	int		i_rem;
	t_list	*rem;

	if (!node)
		return (NULL);
	i_ln = 0;
	i_rem = 0;
	rem = malloc(sizeof(t_list));
	if (!rem)
		return (NULL);
	i_ln = slen(node->content, 1);
	if (node->content[i_ln] == '\n') 
		i_ln++;
	rem->content = malloc(sizeof(char) * (slen(node->content, 0) - i_ln + 1));
	rem->next = NULL;
	if (!rem->content)
		return (free_linked_list(rem));
	while (i_ln < slen(node->content, 0) && node->content[i_ln])
		rem->content[i_rem++] = node->content[i_ln++];
	rem->content[i_rem] = '\0';
	return (rem);
}

char	*fill_line(t_list *node)
{
	int		i_line;
	int		i_node;
	char	*line;
	int		chars;

	i_line = 0;
	i_node = 0;
	chars = count_chars_in_line(node);
	if (chars == 0)
		return (NULL);
	line = malloc(sizeof(char) * (chars + 1));
	if (!line)
		return (NULL);
	while (node)
	{
		while (node->content[i_node] != '\0' && node->content[i_node] != '\n')
			line[i_line++] = node->content[i_node++];
		if (node->content[i_node] == '\n')
			line[i_line++] = '\n';
		i_node = 0;
		node = node->next;
	}
	line[i_line] = '\0';
	return (line);
}

int	count_chars_in_line(t_list *node)
{
	int		chars;

	chars = 0;
	while (node)
	{
		chars += slen(node->content, 1);
		if (node->next == NULL)
			break ;
		node = node->next;
	}
	if (node && node->content[slen(node->content, 1)] == '\n')
		chars++;
	return (chars);
}

t_list	*make_a_node(int fd)
{
	t_list	*node;
	int		read_chars;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	node->next = NULL;
	if (!node->content)
		return (free_linked_list(node));
	read_chars = read(fd, node->content, BUFFER_SIZE);
	if (read_chars == -1 || read_chars == 0) 
		return (free_linked_list(node));
	node->content[read_chars] = '\0';
	return (node);
}

char	*get_next_line(int fd)
{
	static t_list	*rem;
	t_list			*node;
	t_list			*lst;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	if (rem && ft_strchr(rem->content, '\n'))
		node = rem;
	else
		node = make_a_node(fd);
	if (!node && !rem)
		return (NULL);
	lst = node;
	while (lst && !(ft_strchr(lst->content, '\n')))
	{
		lst->next = make_a_node(fd);
		if (lst->next == NULL)
			break ;
		lst = lst->next;
	}
	line = create_line(node, rem);
	rem = create_rem(lst);
	free_linked_list(node);
	return (line);
}

// int main(void)
// { 
// 	int fd;
// 	char *str;
// 	//fd = open("./alternate_line_nl_no_nl.txt", O_RDONLY);
// 	fd = open("./text.txt", O_RDONLY);

// 	str = get_next_line(fd);
// 	printf("gnl 1: %s", str);
// 	free(str);

// 	str = get_next_line(fd);
// 	printf("gnl 2: %s", str);
// 	free(str);

// 	str = get_next_line(fd);
// 	printf("gnl 3: %s", str);
// 	free(str);

// 	str = get_next_line(fd);
// 	printf("gnl 4: %s", str);
// 	free(str);

// 	str = get_next_line(fd);
// 	printf("gnl 5: %s", str);
// 	free(str);

// 	// printf("\ngnl 6: %s", get_next_line(fd));
// 	// printf("\n---gnl 6 ended---\n");
// 	// printf("\ngnl 7: %s", get_next_line(fd));
// 	// printf("\n---gnl 7 ended---\n");
// 	// printf("\ngnl 8: %s", get_next_line(fd));
// 	// printf("\n---gnl 8 ended---\n");
// 	// printf("\ngnl 9: %s", get_next_line(fd));
// 	// printf("\n---gnl 9 ended---\n");
// 	// printf("\ngnl 10: %s", get_next_line(fd));
// 	// printf("\n---gnl 10 ended---\n");
// 	// close(fd);
// }