/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 08:27:37 by msoria-j          #+#    #+#             */
/*   Updated: 2024/01/06 08:27:39 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub_editor.h"

int	err_arg_number(void)
{
	printf("Usage: ./cub_editor map.cub [size_x][size_y]\n");
	return (1);
}

int	err_file(char *file)
{
	printf("Could not open the file: %s\n", file);
	return (1);
}
int	err_mlx(void)
{
	printf("Error on minilbx\n");
	return (1);
}
