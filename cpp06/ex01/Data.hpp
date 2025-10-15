/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:30:00 by ayasar            #+#    #+#             */
/*   Updated: 2025/10/15 14:02:07 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <string>

struct Data {
    int number;
    std::string text;
    double value;
    char character;
    
    Data();
    Data(int n, const std::string& t, double v, char c);
    ~Data();
};

#endif
