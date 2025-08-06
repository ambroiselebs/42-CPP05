/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 17:40:41 by aberenge          #+#    #+#             */
/*   Updated: 2025/08/06 19:51:27 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void) :	name("Default"),
					is_signed(false),
					grade_sign(150),
					grade_exec(150)
{}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
	: name(name), is_signed(false), grade_sign(gradeToSign), grade_exec(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &other)
	: name(other.name), is_signed(other.is_signed), grade_sign(other.grade_sign), grade_exec(other.grade_exec)
{
}

Form::~Form(void)
{}


Form &Form::operator=(const Form &other)
{
	if (this != &other)
		is_signed = other.is_signed;
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << "Form " << form.getName() << ", signed: " << (form.getSigned() ? "yes" : "no")
		<< ", grade to sign: " << form.getGradeSign()
		<< ", grade to execute: " << form.getGradeExec();
	return (out);
}


const std::string	Form::getName(void) const
{
	return (name);
}

bool	Form::getSigned(void) const
{
	return (is_signed);
}

int	Form::getGradeSign(void) const
{
	return (grade_sign);
}

int	Form::getGradeExec(void) const
{
	return (grade_exec);
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > grade_sign)
		throw Form::GradeTooLowException();
	is_signed = true;
}


const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Form grade too high");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Form grade too low");
}
