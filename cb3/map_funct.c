/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_funct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:19:42 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/01/27 18:21:57 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

void	free_all(char *str, char **s)
{
	free(str);
	free_memory(s);
}
void		map_funct(char *line)
{
	if (line[0] == 'R' && line[1] == ' ')
		treat_resolution(line);
	else if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
	   treat_North(line);
	else if (line[0] =='S' && line[1] == 'O' && line[2] == ' ')
	   treat_south(line);
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		treat_east(line);
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		treat_west(line);
	else if (line[0] == 'C' && line[1] == ' ')
		treat_c(line);
	else if (line[0] == 'F' && line[1] == ' ')
		treat_f(line);
	else if (line[0] == 'S' && line[1] == ' ')
		treat_sprite(line);
	else if (params())
		read_map_line(line); 
	else 
	{
		ft_putstr("ERROR \n some of parameters arje wrong");
		exit(0);
	}
		
}
void		treat_resolution(char *line)
{
	int num;
	char **split;
	num = numbers_of_parameters(line, ' ');
	if (num != 3)
	{
		ft_putstr("Error :\nwrong number of parameters");
		exit(0);
	}
	if (g_height != 0 && g_width != 0)
	{
		ft_putstr("ERROR \n Double inclusion");
		exit(0);
	}
	split = ft_split(line, ' ');
	if (is_digit(&split[1][0]) && is_digit(&split[2][0]))
	{
		resolution(ft_atoi(&split[1][0]),ft_atoi(&split[2][0]));
	}
	else
	{
		ft_putstr("Error :\nwrong resolution");
		exit(0);
	}
	free_memory(split);
  
}
void		treat_c(char *line)
{
  
	int num;
	char **split;
	char **split2;
	num = 0;
	split = ft_split(line,' ');
	split2 = ft_split(&split[1][0], ',');
	num = numbers_of_parameters(&split[1][0], ',');
	
	 if (g_cr != -1 && g_cb != -1 && g_cb != -1)
	{
		ft_putstr("Error \n Double inclusion In ceiling");
		exit(0);
	}
	//if (num != 3)
	// {
	// 	ft_putstr("Error :\nwronsg number of parameters");
	// 	exit(0);
	// }
   
	if (is_digit(&split2[0][0]) && is_digit(&split2[1][0]) && is_digit(&split2[2][0]))
		get_c(ft_atoi(&split2[0][0]), ft_atoi(&split2[1][0]), ft_atoi(&split2[2][0]));
	else
	{
		ft_putstr("Error :\n wrong Colors");
		exit(0);
	}
	free_memory(split);
	free_memory(split2);
   
}
void		treat_f(char *line)
{
	int num;
	char **split;
	char **split2;
	
	split = ft_split(line,' ');
	split2 = ft_split(&split[1][0], ',');
	num = numbers_of_parameters(&split[1][0],',');
	 if (g_fr != -1 && g_fg != -1 && g_fb != -1 )
	{
		ft_putstr("ERROR \n Double inclusion in floor ");
		exit(0);
	}
	if (num != 3)
	{
		ft_putstr("Error :\nwrong number of parameters");
		exit(0);
	}
   
	if (is_digit(&split2[0][0]) && is_digit(&split2[1][0]) && is_digit(&split2[2][0]))
		get_f(ft_atoi(&split2[0][0]),ft_atoi(&split2[1][0]), ft_atoi(&split2[2][0]));
		else
		{
			ft_putstr("Error :\nWrong Colors");
			exit(0);
		}
		free_memory(split2);
		free_memory(split);      
}

 void		treat_North(char *line)
{
	int num;
	char **split;
	char *str;
	str = ft_strdup("");
	if (g_no != NULL)
	{
		ft_putstr("ERROR \n Double Inclusion");
	}
	split = ft_split(line, ' ');
	num = numbers_of_parameters(line,' ');
  
	if (num != 2)
	{
		ft_putstr("Error :\n Bad syntax in NO");
		exit(0);
	}
	check_ext(&split[1][0], 'N');
	free_all(str,split);
}

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
free_all(str,split);
 
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
	free_all(str,split);
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
	free_all(str,split);
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
free_all(str,split);
}
