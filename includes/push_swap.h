/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somenvie <somenvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 00:12:31 by somenvie          #+#    #+#             */
/*   Updated: 2025/12/20 14:33:51 by somenvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

t_list	*parsing(int argc, char **argv);
t_list	*lst_creator(int argc, char **argv);
int		parsing_digits(int argc, char **argv);
int		check_quoted(int argc, char **argv);
int		ft_atol(const char *nptr);

#endif