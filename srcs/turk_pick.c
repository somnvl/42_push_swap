/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_pick.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so <so@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 20:05:45 by so                #+#    #+#             */
/*   Updated: 2026/01/24 22:47:12 by so               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pick_cheapest(t_dlst *a, t_dlst *b, int *cost_a, int *cost_b)
{
    
}

/*
FUNCTION pick_cheapest(A, B) -> (best_cost_a, best_cost_b)

    lenA = size(A)
    lenB = size(B)

    best_total = +infinity
    best_cost_a = 0
    best_cost_b = 0

    FOR each node x in B (from top to bottom):

        # 1) Find where x must be inserted in A (its target)
        #    target = the smallest index in A that is > x.index
        #    if none eists, target = node with the minimum index in A (wrap)
        target = find_target_in_A(A, x.index)

        # 2) Compute the rotation cost to bring x to top of B
        posB = position_of_node(B, x)              # 0 = top, 1 = second, ...
        cost_b = cost_from_position(posB, lenB)    # >0 => rb, <0 => rrb

        # 3) Compute the rotation cost to bring target to top of A
        posA = position_of_node(A, target)
        cost_a = cost_from_position(posA, lenA)    # >0 => ra, <0 => rra

        # 4) Compute the total cost (taking rr/rrr into account)
        IF cost_a and cost_b have the same sign:
            # can do rr or rrr together
            total = max(abs(cost_a), abs(cost_b))
        ELSE:
            # cannot combine
            total = abs(cost_a) + abs(cost_b)

        # 5) Keep the cheapest option
        IF total < best_total:
            best_total = total
            best_cost_a = cost_a
            best_cost_b = cost_b

    RETURN (best_cost_a, best_cost_b)
*/