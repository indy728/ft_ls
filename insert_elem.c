/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 18:17:21 by alcornea          #+#    #+#             */
/*   Updated: 2017/05/09 18:59:49 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


void	insert_elem(t_data **idata, t_data *new, t_posib *option)
{
	int value;
	t_data *tmp;

	if (*idata == NULL){
		*idata = new;
	}
	else
	{
		tmp = *idata;
		if (option->r)
			value = ft_strcmp(tmp->name, new->name);
		else if (option->t)
	  	value = tmp->sec_date - new->sec_date;
			//tmp->st.st_mtime > new->st.st_mtime;
		else if (option->s || (option->s && option->l))
			value = ft_atoi(tmp->size) - ft_atoi(new->size);
		else
			value = ft_strcmp(new->name, tmp->name);
		if (value < 0)
		{
			if (tmp->left != NULL)
				insert_elem(&tmp->left, new, option);
			else
				tmp->left = new;
		}
		else
		{
			if (tmp->right != NULL)
				insert_elem(&tmp->right, new, option);
			else
				tmp->right = new;
		}
		value = 0;
	}
}

// void	insert_elem(t_data **idata, t_data *new, t_posib *option)
// {
// 	int value;
// 	t_data *tmp;
// 	t_data *prev;
//
// 	(void)*option;
// 	if (*idata == NULL)
// 		*idata  = new;
// 	else
// 	{
// 		tmp = *idata;
// 		prev = NULL;
// 		while (tmp != NULL)
// 		{
// 			prev = tmp;
// 			value = ft_strcmp(tmp->name, new->name);
// 			if (value > 0)
// 			{
// 				tmp = tmp->left;
// 			}
// 			else
// 				tmp = tmp->right;
// 		}
// 		// value = ft_strcmp(prev->name, new->name);
// 		if(value > 0)
// 			prev->left = new;
// 		else
// 			prev->right = new;
// 	}
// }
