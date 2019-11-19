/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumourot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:21:55 by jumourot          #+#    #+#             */
/*   Updated: 2019/11/18 13:36:10 by jumourot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

int				get_next_line(int fd, char **line);
char			*ft_strchr(const char *str, int c);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_substr(char const *s, unsigned int start, size_t len);
static char		ft*concat_all(char *dest, char const *s1, char const *s2);

#endif
