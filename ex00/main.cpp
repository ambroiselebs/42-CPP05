/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 09:40:54 by aberenge          #+#    #+#             */
/*   Updated: 2025/08/06 12:01:07 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	test_valid_bureaucrats(void)
{
	std::cout << "=== Testing Valid Bureaucrats ===" << std::endl;
	try
	{
		Bureaucrat john("John", 1);
		Bureaucrat jane("Jane", 75);
		Bureaucrat bob("Bob", 150);

		std::cout << john << std::endl;
		std::cout << jane << std::endl;
		std::cout << bob << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void	test_invalid_grades(void)
{
	std::cout << "\n=== Testing Invalid Grades ===" << std::endl;
	try
	{
		Bureaucrat tooHigh("TooHigh", 0);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat tooLow("TooLow", 151);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void	test_increment_decrement(void)
{
	std::cout << "\n=== Testing Increment/Decrement ===" << std::endl;
	try
	{
		Bureaucrat mike("Mike", 2);
		std::cout << mike << std::endl;

		mike.incrementGrade();
		std::cout << "After increment: " << mike << std::endl;

		mike.incrementGrade(); // Should throw exception
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat sara("Sara", 149);
		std::cout << sara << std::endl;

		sara.decrementGrade();
		std::cout << "After decrement: " << sara << std::endl;

		sara.decrementGrade(); // Should throw exception
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

int main(void)
{
	test_valid_bureaucrats();
	test_invalid_grades();
	test_increment_decrement();
	return (0);
}
