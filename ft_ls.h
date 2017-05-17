/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 20:27:40 by alcornea          #+#    #+#             */
/*   Updated: 2017/04/18 20:28:50 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FT_LS_H
# define	FT_LS_H

#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <dirent.h>
#include <sys/errno.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <grp.h>
#include <uuid/uuid.h>
#include <sys/types.h>
#include <pwd.h>
#include <time.h>

# define BLACK    "\033[0;30m"
# define RED      "\033[0;31m"
# define GREEN    "\033[0;32m"
# define YELLOW   "\033[0;33m"
# define BLUE     "\033[0;34m"
# define PURPLE   "\033[0;35m"
# define CYAN     "\033[0;36m"
# define GREY     "\033[0;37m"

# define DEFAULT_COLOR "\033[0m"

typedef struct s_posib
{
  char a;
  char l;
  char r;
  char t;
  char s;
  char rec;
  char op_color;
  char **path;
  char *p_name;
  int nb_path;
  size_t size[5];
  size_t total;
}              t_posib;

typedef struct		s_data
{
	char			*name;
	char			*mode;
	char			*nlink;
	char			*uid;
	char			*grp;
	char			*size;
	char			*date;
  char      *link;
  int  sec_date;
  struct stat st;
	struct s_data	*next;
  struct s_data *left;
  struct s_data *right;
}					t_data;


char *get_argument(int ac, char **av, t_posib *option);
void  set_option(char *str, t_posib *option);
void	init_elements(t_data *elem);
void list(t_posib *option);
t_data *read_directories(char *bpath, char *path,  t_posib *option, int *nb);
size_t get_total(char *path, t_data *data, t_posib *option);
char *check_permissions(mode_t mode);
void check_time(t_data *data, time_t mtime);
void	insert_elem(t_data **idata, t_data *new, t_posib *option);
int  list_recursive(t_posib *option, char *path, int i);
void print(t_data **data, t_posib *option);
void sort_path(char ***str, int size, char r);
int stat_dir(char *path);
int error(int nb, char *str);




#endif
