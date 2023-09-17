# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aflorido <aflorido@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/26 03:03:03 by aflorido          #+#    #+#              #
#    Updated: 2023/07/26 03:24:56 by aflorido         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Remove previous garbage
rm -f libft.a
# Compile all source files into object files
find . -maxdepth 1 -name "*.c" -exec cc -Wall -Werror -Wextra -c {} ';'
# Create static library
ar -rcs libft.a *.o
# Remove already used object files
find . -maxdepth 1 -name "*.o" -delete
