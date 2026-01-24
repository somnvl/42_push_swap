/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_apply.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so <so@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 20:05:45 by so                #+#    #+#             */
/*   Updated: 2026/01/24 22:47:24 by so               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	apply_cheapest(t_dlst **a, t_dlst **b, int cost_a, int cost_b)
{

}

/*
FUNCTION apply_cheapest(A, B, cost_a, cost_b)

    # 1) Combine rotations when both stacks rotate in the same direction
    WHILE cost_a > 0 AND cost_b > 0:
        rr(A, B)          # ra + rb
        cost_a -= 1
        cost_b -= 1

    WHILE cost_a < 0 AND cost_b < 0:
        rrr(A, B)         # rra + rrb
        cost_a += 1
        cost_b += 1

    # 2) Finish rotating A alone
    WHILE cost_a > 0:
        ra(A)
        cost_a -= 1

    WHILE cost_a < 0:
        rra(A)
        cost_a += 1

    # 3) Finish rotating B alone
    WHILE cost_b > 0:
        rb(B)
        cost_b -= 1

    WHILE cost_b < 0:
        rrb(B)
        cost_b += 1

*/