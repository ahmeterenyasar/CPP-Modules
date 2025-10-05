/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:19:27 by ayasar            #+#    #+#             */
/*   Updated: 2025/09/29 20:22:41 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat ahmet("Ahmet", 75);
        std::cout << ahmet << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "-----------------------------------" << std::endl;

    try {
        Bureaucrat invalid("Invalid", 0);
        std::cout << invalid << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "-----------------------------------" << std::endl;

    try {
        Bureaucrat invalid("Invalid", 151);
        std::cout << invalid << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "-----------------------------------" << std::endl;

    try {
        Bureaucrat mehmet("Mehmet", 3);
        std::cout << mehmet << std::endl;
        mehmet.increaseGrade();
        std::cout << "After increment: " << mehmet << std::endl;
        mehmet.increaseGrade();
        std::cout << "After increment: " << mehmet << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "-----------------------------------" << std::endl;

    try {
        Bureaucrat topBureaucrat("Top", 1);
        std::cout << topBureaucrat << std::endl;
        topBureaucrat.increaseGrade();
        std::cout << "After increment: " << topBureaucrat << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "-----------------------------------" << std::endl;

    try {
        Bureaucrat ayse("Ayse", 148);
        std::cout << ayse << std::endl;
        ayse.decreaseGrade();
        std::cout << "After decrement: " << ayse << std::endl;
        ayse.decreaseGrade();
        std::cout << "After decrement: " << ayse << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "-----------------------------------" << std::endl;

    try {
        Bureaucrat bottomBureaucrat("Bottom", 150);
        std::cout << bottomBureaucrat << std::endl;
        bottomBureaucrat.decreaseGrade();
        std::cout << "After decrement: " << bottomBureaucrat << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "-----------------------------------" << std::endl;

    try {
        Bureaucrat highest("Highest", 1);
        Bureaucrat lowest("Lowest", 150);
        std::cout << highest << std::endl;
        std::cout << lowest << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}