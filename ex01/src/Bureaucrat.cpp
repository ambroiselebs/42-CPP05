/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 09:43:25 by aberenge          #+#    #+#             */
/*   Updated: 2025/08/06 19:47:53 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name("Default"), grade(150)
{}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooLowException();
	if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	*this = other;
}

Bureaucrat::~Bureaucrat(void)
{}


Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		this->grade = other.grade;
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return out;
}


const std::string	Bureaucrat::getName(void) const
{
	return (this->name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

void	Bureaucrat::incrementGrade(void)
{
	if (this->grade >= 150)
		throw Bureaucrat::GradeTooHighException();
	this->grade++;
}

void	Bureaucrat::decrementGrade(void)
{
	if (this->grade <= 1)
		throw Bureaucrat::GradeTooLowException();
	this->grade--;
}

void	Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << name << " couldn't sign " << form.getName()
				  << " because " << e.what() << std::endl;
	}
}


const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too high");
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too low");
}
