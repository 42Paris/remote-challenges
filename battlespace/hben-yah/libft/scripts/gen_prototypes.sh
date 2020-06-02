#!/bin/sh
echo "/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prototypes.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: \c" > includes/ft_prototypes.h

date "+%Y/%m/%d %H:%M:%S" | tr -d '\n' >> includes/ft_prototypes.h

echo " by hben-yah          #+#    #+#             */
/*   Updated: \c" >> includes/ft_prototypes.h

date "+%Y/%m/%d %H:%M:%S" | tr -d '\n' >> includes/ft_prototypes.h

echo " by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROTOTYPES_H
# define FT_PROTOTYPES_H

/*
** ft_Prototypes
*/
" >> includes/ft_prototypes.h
find srcs -name '*.c' -exec cat {} \; | grep -v static | grep -A 1 -E "^[a-z]+" | grep -v -E "(;|	return|	while|	if|=|->|\?|:|{|}|\-\-)" | sed -e s/\)' '*$/\)\;/g |
tr -s '	' '	' | sed -e 's/	/		/g' | sed -e 's/^int/int	/g' | sed -e 's/^	/			/g' >> includes/ft_prototypes.h
echo "
#endif" >> includes/ft_prototypes.h
#find srcs -name '*.c' -exec cat {} \; | tr -s '\t\n' ' ' | grep -E "([a-z0-9_*]+ )?[a-z0-9_*]+ [a-z0-9_*]+\([a-z0-9_,() *]+\) {" -o | sed -e 's/ {//g' | sed -e 's/ /                            /'
#find srcs -name '*.c' -exec cat {} \; | grep -A 1 -E "([a-z0-9_()*]+[       \n]+)?([a-z0-9_()*]+[    \n]+)\([a-z0-9_(), *]+\)"
#find srcs -name '*.c' -exec cat {} \; | grep -v static | grep -A 1 -E "^[a-z]+" | grep -v -E "(;|return|while|if|=|->|\?|:|{|}|\-\-)" | tr -d '\n' | sed -e s/\)/\)\;%/g | sed -e s/,/,%/g | tr % '\n'