/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 23:09:52 by akostian          #+#    #+#             */
/*   Updated: 2025/07/22 23:25:54 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>

# include <cstring>

# include <iostream>

# define ALLOWED_CHARS "+-*/""0123456789"

int	solve(std::string input, int &result);

#endif // RPN_HPP