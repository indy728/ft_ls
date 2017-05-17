/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 23:00:01 by alcornea          #+#    #+#             */
/*   Updated: 2017/05/07 23:00:02 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
    If the modification time of the file is more than 6 months in the past or future,
    then the year of the last  modification is displayed in place of the hour and minute fields.
*/
//
void  check_time(t_data *data, time_t mtime)
{
  //time_t st_mtimespec;
  char *tmp;

  tmp = ctime(&mtime);

  data->sec_date = mtime;
  data->date = ft_strsub(tmp, 4, 12);
  //data->sec_date=  st.st_mtimespec;

  // printf("sec_date: %d\n", data->sec_date);
  // printf("date:%s\n", data->date);
}
