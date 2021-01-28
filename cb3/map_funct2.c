/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_funct2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:20:27 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/01/26 19:07:31 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		treat_south(char *line)
{
    int num;
    char **split;
    char *str;
    str = ft_strdup("");
    split = ft_split(line, ' ');
    num = numbers_of_parameters(line,' ');
	if (num != 2)
	{
		ft_putstr("Error :\n Bad syntax in South");
		exit(0);
	}
	if (g_so != NULL )
	{
		ft_putstr("ERROR \n Double inclusion");
		exit(0);
	}
    check_ext(&split[1][0], '2');
}

void		treat_east(char *line)
{
    int num;
    char **split;
    char *str;

    str = ft_strdup("");
    split = ft_split(line, ' ');
    num = numbers_of_parameters(line,' ');
	if (g_ea != NULL)
	{
		ft_putstr("ERROR \n Double inclusion");
		exit(0);
	}
	if (num != 2)
	{
		ft_putstr("Error :\n Bad syntax in EAST");
		exit(0);
	}
	check_ext(&split[1][0], 'E'); 
}

void		treat_west(char *line)
{
    int num;
    char **split;
    char *str;
    str = ft_strdup("");
    split = ft_split(line, ' ');
	num = numbers_of_parameters(line,' ');
	if (g_we != NULL)
	{
		ft_putstr("ERROR \n Double inclusion");
		exit(0);
	}
	if (num != 2)
	{
		ft_putstr("Error :\n Bad syntax in WEST");
		exit(0);
	}
 check_ext(&split[1][0], 'W'); 
}

void		treat_sprite(char *line)
{

	int num;
	char **split;
	char *str;
	str = ft_strdup("");
	split = ft_split(line, ' ');
	num = numbers_of_parameters(line,' ');
	if (g_spr != NULL)
	{
		ft_putstr("ERROR \n Double inclusion");
		exit(0);
	}

	if (num != 2)
	{
		ft_putstr("Error :\n Bad syntax in Sprite");
		exit(0);
	}
 check_ext(&split[1][0], 'S'); 
}
