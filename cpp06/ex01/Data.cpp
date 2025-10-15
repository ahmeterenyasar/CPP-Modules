/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:30:00 by ayasar            #+#    #+#             */
/*   Updated: 2025/10/15 14:02:07 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : number(0), text(""), value(0.0), character('\0') {}

Data::Data(int n, const std::string& t, double v, char c) 
    : number(n), text(t), value(v), character(c) {}

Data::~Data() {}
