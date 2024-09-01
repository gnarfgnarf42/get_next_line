/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscholz <sscholz@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 20:46:35 by sscholz           #+#    #+#             */
/*   Updated: 2024/08/27 20:46:38 by sscholz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE
# endif

# include <unistd.h>
# include <stdlib.h>

void	cleanup_remainder(char **remainder);
size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *dest, const void *src, size_t num);
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *s);
char	*read_and_store(int fd, char *remainder);
char	*extract_line(char **remainder);
char	*ft_strndup(const char *s, size_t n);

#endif /* GET_NEXT_LINE_H */