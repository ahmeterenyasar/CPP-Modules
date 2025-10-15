/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 00:00:00 by ayasar            #+#    #+#             */
/*   Updated: 2025/10/15 15:21:52 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

class Base {
public:
    virtual ~Base();
};

class A : public Base {};

class B : public Base {};

class C : public Base {};


Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
