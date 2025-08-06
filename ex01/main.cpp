/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 17:50:37 by aberenge          #+#    #+#             */
/*   Updated: 2025/08/06 19:54:57 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void	testBasicSigning(void)
{
	std::cout << "=== TEST SIGNATURE BASIQUE ===" << std::endl;

	try
	{
		Bureaucrat alice("Alice", 30);
		Bureaucrat bob("Bob", 100);
		Form taxForm("Déclaration d'impôts", 50, 25);

		std::cout << "Bureaucrates:" << std::endl;
		std::cout << "  " << alice << std::endl;
		std::cout << "  " << bob << std::endl;
		std::cout << "Form: " << taxForm << std::endl;

		std::cout << "\nTentative de signature par Alice (grade 30 vs requis 50):" << std::endl;
		alice.signForm(taxForm);
		std::cout << "Après signature: " << taxForm << std::endl;

		std::cout << "\nTentative de signature par Bob (grade 100 vs requis 50):" << std::endl;
		bob.signForm(taxForm);
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	testFormCreation(void)
{
	std::cout << "=== TEST CREATION DES FORMS ===" << std::endl;

	try
	{
		Form validForm("Formulaire Fiscal", 50, 25);
		std::cout << "✓ Form valide créé: " << validForm << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "✗ Erreur inattendue: " << e.what() << std::endl;
	}

	try
	{
		Form gradeZero("Grade Zéro", 0, 25);
		std::cout << "✗ Ne devrait pas arriver ici!" << std::endl;
	}
	catch (const Form::GradeTooHighException &e)
	{
		std::cout << "✓ Exception attendue (grade 0): " << e.what() << std::endl;
	}

	try
	{
		Form grade151("Grade 151", 25, 151);
		std::cout << "✗ Ne devrait pas arriver ici!" << std::endl;
	}
	catch (const Form::GradeTooLowException &e)
	{
		std::cout << "✓ Exception attendue (grade 151): " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	testEdgeCases(void)
{
	std::cout << "=== TEST CAS LIMITES ===" << std::endl;

	try
	{
		Bureaucrat pdg("PDG", 1);
		Bureaucrat stagiaire("Stagiaire", 150);
		Form formFacile("Form Facile", 150, 150);
		Form formDifficile("Form Difficile", 1, 1);

		std::cout << "Test form facile avec stagiaire:" << std::endl;
		std::cout << "  " << stagiaire << std::endl;
		std::cout << "  " << formFacile << std::endl;
		stagiaire.signForm(formFacile);
		std::cout << "  Résultat: " << formFacile << std::endl;

		std::cout << "\nTest form difficile avec PDG:" << std::endl;
		std::cout << "  " << pdg << std::endl;
		std::cout << "  " << formDifficile << std::endl;
		pdg.signForm(formDifficile);
		std::cout << "  Résultat: " << formDifficile << std::endl;

		std::cout << "\nTest form difficile avec stagiaire (devrait échouer):" << std::endl;
		stagiaire.signForm(formDifficile);
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	testCopyAssignment(void)
{
	std::cout << "=== TEST COPIE ET ASSIGNATION ===" << std::endl;

	try
	{
		Form original("Form Original", 75, 50);
		Bureaucrat signer("Signataire", 50);

		std::cout << "Form original avant signature: " << original << std::endl;
		signer.signForm(original);
		std::cout << "Form original après signature: " << original << std::endl;

		Form copie = original;
		std::cout << "Form copie (constructeur de copie): " << copie << std::endl;

		Form autre("Autre Form", 100, 80);
		std::cout << "Autre form avant assignation: " << autre << std::endl;
		autre = original;
		std::cout << "Autre form après assignation: " << autre << std::endl;
		std::cout << "Note: seul le statut 'signé' est copié, pas le nom (const)" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	testMultipleSigning(void)
{
	std::cout << "=== TEST SIGNATURES MULTIPLES ===" << std::endl;

	try
	{
		Form document("Document Important", 75, 50);
		Bureaucrat manager("Manager", 70);
		Bureaucrat assistant("Assistant", 80);

		std::cout << "Document initial: " << document << std::endl;

		std::cout << "\nTentative 1 - Manager (grade 70 vs requis 75):" << std::endl;
		manager.signForm(document);
		std::cout << "État: " << document << std::endl;

		std::cout << "\nTentative 2 - Assistant sur même document:" << std::endl;
		assistant.signForm(document);
		std::cout << "État final: " << document << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

int	main(void)
{
	std::cout << "🏢 TESTS DU SYSTÈME BUREAUCRATIQUE 🏢" << std::endl;
	std::cout << "=====================================\n" << std::endl;

	testFormCreation();
	testBasicSigning();
	testEdgeCases();
	testCopyAssignment();
	testMultipleSigning();

	std::cout << "✅ Tous les tests terminés!" << std::endl;
	return (0);
}

