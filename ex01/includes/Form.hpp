/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 17:34:45 by aberenge          #+#    #+#             */
/*   Updated: 2025/08/06 19:45:40 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		bool				is_signed;
		const int			grade_sign;
		const int			grade_exec;
	public:
		Form();
		Form(const std::string &name, int gradeToSign, int gradeToExecute);
		Form(const Form &other);
		~Form();

		Form &operator=(const Form &other);
		friend std::ostream	&operator<<(std::ostream &out, const Form &f);

		const std::string	getName(void) const;
		bool				getSigned(void) const;
		int					getGradeSign(void) const;
		int					getGradeExec(void) const;

		void				beSigned(const Bureaucrat &bureaucrat);

		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif
