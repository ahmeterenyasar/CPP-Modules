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
    std::cout << "=== Test 1: Valid bureaucrat creation ===" << std::endl;
    try {
        Bureaucrat bob("Bob", 75);
        std::cout << bob << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 2: Grade too high (0) ===" << std::endl;
    try {
        Bureaucrat invalid("Invalid", 0);
        std::cout << invalid << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 3: Grade too low (151) ===" << std::endl;
    try {
        Bureaucrat invalid("Invalid", 151);
        std::cout << invalid << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 4: Increment grade ===" << std::endl;
    try {
        Bureaucrat alice("Alice", 3);
        std::cout << alice << std::endl;
        alice.increseGrade();
        std::cout << "After increment: " << alice << std::endl;
        alice.increseGrade();
        std::cout << "After increment: " << alice << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 5: Increment grade beyond limit ===" << std::endl;
    try {
        Bureaucrat topBureaucrat("Top", 1);
        std::cout << topBureaucrat << std::endl;
        topBureaucrat.increseGrade();
        std::cout << "After increment: " << topBureaucrat << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 6: Decrement grade ===" << std::endl;
    try {
        Bureaucrat charlie("Charlie", 148);
        std::cout << charlie << std::endl;
        charlie.decreseGrade();
        std::cout << "After decrement: " << charlie << std::endl;
        charlie.decreseGrade();
        std::cout << "After decrement: " << charlie << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 7: Decrement grade beyond limit ===" << std::endl;
    try {
        Bureaucrat bottomBureaucrat("Bottom", 150);
        std::cout << bottomBureaucrat << std::endl;
        bottomBureaucrat.decreseGrade();
        std::cout << "After decrement: " << bottomBureaucrat << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 8: Copy constructor ===" << std::endl;
    try {
        Bureaucrat original("Original", 50);
        Bureaucrat copy(original);
        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy: " << copy << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 9: Edge cases (grades 1 and 150) ===" << std::endl;
    try {
        Bureaucrat highest("Highest", 1);
        Bureaucrat lowest("Lowest", 150);
        std::cout << highest << std::endl;
        std::cout << lowest << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== All tests completed ===" << std::endl;
    return 0;
}