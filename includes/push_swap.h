/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somenvie <somenvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 00:12:31 by somenvie          #+#    #+#             */
/*   Updated: 2025/12/20 01:47:45 by somenvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

int		parsing_digits(int argc, char **argv);
int		check_quoted(int argc, char **argv);
char	**ps_split(char const *s, char c);
t_list	*lst_creator(int argc, char **argv);
int		ft_atol(const char *nptr);

#endif