/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 08:27:37 by msoria-j          #+#    #+#             */
/*   Updated: 2024/01/08 13:16:39 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub_editor.h"

int	err_arg_number(void)
{
	ft_fprintf(2, "Usage: ./cub_editor map_name [map_size=10]\n");
	ft_fprintf(2, "Generates a square map (by default 10x10) to be used with cub3D project.\n");
	ft_fprintf(2, "Recommended values range from 10 to 50.\n");
	ft_fprintf(2, "  map_name: Name of the file to be generated.\n");
	ft_fprintf(2, "  map_size: Optional. Defines the number of squares per row.\n");
	print_controls();
	return (1);
}

int	err_file(char *file)
{
	printf("Could not open the file: %s\n", file);
	return (1);
}
int	err_mlx(t_mlx *m)
{
	printf("Error on minilbx\n");
	close_mlx(m);
	return (1);
}
