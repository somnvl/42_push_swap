/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so <so@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 17:29:57 by so                #+#    #+#             */
/*   Updated: 2026/01/24 19:27:17 by so               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	has_chunk_left()
{
	
}

static int	get_chunk_size(int size)
{
	if (size <= 100)
		return (size / 5);
    if (size <= 500)
		return (size / 10);
    return (size / 15);
}

void turk_sort(int size, t_dlst **a, t_dlst **b)
{
	int	chunk_size;
	int	chunk_start;
	int	chunk_end;

    chunk_size = get_chunk_size(size);
    chunk_start = 0;
    chunk_end = chunk_start + chunk_size - 1;

    // ÉTAPE 3 : BOUCLE PRINCIPALE
    while (db_lstsize(*a) > 3)  // Tant que A a plus de 3 éléments
    {
        // Vérifier si l'élément en haut de A est dans [chunk_start..chunk_end]
        if ((*a)->index >= chunk_start && (*a)->index <= chunk_end)
        {
            pb(a, b);           // Oui → Pousser dans B
            if (db_lstsize(*b) > 1)
                rb(b);          // Placer au bon endroit dans B
        }
        else
            ra(a);              // Non → Tourner A pour trouver le prochain
        // Vérifier si le chunk actuel est vide
        if (!has_chunk_left(*a, chunk_start, chunk_end))
        {
            // Oui → Passer au chunk suivant
            chunk_start = chunk_end + 1;      // ex: 20
            chunk_end = chunk_start + chunk_size - 1;  // ex: 39
        }
    }
    
    // ÉTAPE 4 : Trier les 3 derniers éléments
    sort_three(a);
    
    // ÉTAPE 5 : Phase 2 (après)
}
