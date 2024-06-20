/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tort <cle-tort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 19:11:45 by cle-tort          #+#    #+#             */
/*   Updated: 2024/06/18 18:35:53 by cle-tort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# define FD_MAX 1024
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*ft_strdup(char *src);
int		stashcheck(char *stash, int sz);
char	*getcontent(char *tmp, char *buffer, char *stash);
char	*ft_strcpy(char *dest, char *src);

#endif
