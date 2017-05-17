/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_permissions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 14:48:50 by alcornea          #+#    #+#             */
/*   Updated: 2017/05/08 16:01:41 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// The following flags are defined for the st_mode field:
//
//   S_IFMT     0170000   bitmask for the file type bitfields
//   S_IFSOCK   0140000   socket
//   S_IFLNK    0120000   symbolic link
//   S_IFREG    0100000   regular file
//   S_IFBLK    0060000   block device
//   S_IFDIR    0040000   directory
//   S_IFCHR    0020000   character device
//   S_IFIFO    0010000   FIFO
//   S_ISUID    0004000   set UID bit
//   S_ISGID    0002000   set-group-ID bit (see below)
//   S_ISVTX    0001000   sticky bit (see below)
//   S_IRWXU    00700     mask for file owner permissions
//   S_IRUSR    00400     owner has read permission
//   S_IWUSR    00200     owner has write permission
//   S_IXUSR    00100     owner has execute permission
//   S_IRWXG    00070     mask for group permissions
//   S_IRGRP    00040     group has read permission
//   S_IWGRP    00020     group has write permission
//   S_IXGRP    00010     group has execute permission
//   S_IRWXO    00007     mask for permissions for others (not in group)
//   S_IROTH    00004     others have read permission
//   S_IWOTH    00002     others have write permission
//   S_IXOTH    00001     others have execute permission

//
#include "ft_ls.h"


char check_type(mode_t mode)
{
  char perm;

  perm = '-';
  if (S_ISDIR(mode))
    perm = 'd';
  else if (S_ISREG(mode))
    perm = '-';
  else if (S_ISLNK(mode))
    perm = 'l';
  else if (S_ISBLK(mode))
    perm = 'b';
  else if (S_ISCHR(mode))
    perm = 'c';
  else if (S_ISSOCK(mode))
    perm = 's';
  else if (S_ISFIFO(mode))
    perm = 'p';
  return (perm);

}



char *check_permissions(mode_t mode)
{
  char *perm;

  perm = ft_strnew(10);
  perm = ft_memset(perm, '-', 10);
  perm[0] = check_type(mode);
  if (S_IRUSR & mode)
    perm[1] = 'r';
  if (S_IWUSR & mode)
    perm[2] = 'w';
  if (S_IXUSR & mode)
    perm[3] = 'x';
  if (S_IRGRP & mode)
    perm[4] = 'r';
  if (S_IWGRP & mode)
    perm[5] = 'w';
  if (S_IXGRP & mode)
    perm[6] = 'x';
  if (S_IROTH & mode)
    perm[7] = 'r';
  if (S_IWOTH & mode)
    perm[8] = 'w';
  if (S_IXOTH & mode)
    perm[9] = 'x';
  return(perm);
}






// #include <unistd.h>
// #include <stdio.h>
// #include <sys/stat.h>
// #include <sys/types.h>
//
// int main(int argc, char **argv)
// {
//     if(argc != 2)
//         return 1;
//
//     struct stat fileStat;
//     if(stat(argv[1],&fileStat) < 0)
//         return 1;
//
//     printf("Information for %s\n",argv[1]);
//     printf("---------------------------\n");
//     printf("File Size: \t\t%lld bytes\n",fileStat.st_size);
//     printf("Number of Links: \t%d\n",fileStat.st_nlink);
//     printf("File inode: \t\t%llu\n",fileStat.st_ino);
//
//     printf("File Permissions: \t");
//     printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
//     printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
//     printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
//     printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
//     printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
//     printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
//     printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
//     printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
//     printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
//     printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
//     printf("\nmode: %ho\n", fileStat.st_mode);
//     //char buffer[20];
//     printf ("filesystem: %o\n",S_IRUSR);
//     //printf("%s\n", );
//     printf("\n\n");
//
//     printf("The file %s a symbolic link\n", (S_ISLNK(fileStat.st_mode)) ? "is" : "is not");
//
//     return 0;
// }
