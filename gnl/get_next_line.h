/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:27:53 by manugonz          #+#    #+#             */
/*   Updated: 2023/09/26 13:27:54 by manugonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5000
# endif

char	*ft_save_rest(char *next);
char	*ft_add(char *next, char *buff);
char	*ft_read_l(int fd, char *next);
char	*get_next_line(int fd);
char	*ft_extract_line(char *next);

#endif
