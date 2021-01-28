/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:20:08 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/01/28 07:54:22 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

int     read_map()
{
    int     fd;
    char    *line;
    int i;

    fd = open("map.cub",O_RDONLY);
    while (1)
    {
        i = get_next_line(fd, &line);
        if ( !(params()))
        { 
            if (*line != '\0')
            map_funct(line);
        }
           else 
                map_funct(line);
        if (i == 0)
            break;
         free(line);
            
    }  
    free(line);     
    return (0);
}

int     main(void)
{
    player.x = -1;
    player.y = -1;
    init_param();
    read_map();
     split_map();
  check_arrays();
  check_width();
    check_map_arrays(g_map);
    fill_g_allmap();
    
    
   
   // fill_g_allmap();
 
   vars.mlx = mlx_init();
   vars.mlx_wind = mlx_new_window(vars.mlx,g_width,g_height,"CUB3D");
   //intialize_player();
    //ft_putstr("%s",g_we);
       mlx_loop_hook(vars.mlx,play,0);
   mlx_loop(vars.mlx);
  
  

   //ft_putstr("%d",g_mwidth);
   return (0);
}
