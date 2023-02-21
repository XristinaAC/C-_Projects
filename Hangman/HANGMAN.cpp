#include <iostream>
#include <string>
#include <cstdlib>
#include "HANGMAN.h"

void print_guess(const std::string guess)
{
	for (size_t i = 0; i < guess.size(); ++i)
	{
		std::cout << guess[i] << " ";
	}

	std::cout << std::endl;
}

void guess_initialization(std::string &guess, const std::string h_w)
{
	guess.push_back(h_w[0]);
	for (size_t i = 1; i < h_w.size() - 1; ++i)
	{
		guess.push_back('_');
	}

	guess.push_back(h_w[h_w.size() - 1]);

	std::cout << "The word to guess looks like this: ";
	print_guess(guess);
}

void guess_check(size_t &letter_occurance_pos, const std::string &h_w, const char &letter_guess, bool &found_letter, std::string &guess, int &tries)
{
	letter_occurance_pos = h_w.find(letter_guess);
	while (letter_occurance_pos != std::string::npos)
	{
		found_letter = true;
		guess[letter_occurance_pos] = letter_guess;

		letter_occurance_pos = h_w.find(letter_guess, letter_occurance_pos + 1);
	}

	if (!found_letter)
	{
		std::cout << "Your letter guess was wrong! ";
		tries--;
	}
}

//Re-initializing variables and printing current guess state. 
void while_epilogue(size_t &letter_occurance_pos, bool &found_letter, const std::string &guess, const int& tries)
{
	letter_occurance_pos = -1;
	found_letter = false;

	std::cout << "Your guess so far is ";
	print_guess(guess);
	std::cout << " and you have " << tries << " tries left. \n";
}

std::string game_init()
{
	std::string hidden_word;

	std::cout << "Give the word to guess.\n";
	std::getline(std::cin, hidden_word);

	return hidden_word;
}

void KREMALA(const std::string &h_w)
{
	int tries = 10;
	std::string guess; 
	char letter_guess = ' ';
	size_t letter_occurance_pos = -1;
	bool found_letter = false;
	std::string given_letters = " ";

	guess_initialization(guess, h_w);

	while (true)
	{
		if (tries == 0)
		{
			std::cout << "You lost! The hidden word was: " << h_w << "\n";
			break;
		}

		std::cout << "Give your letter guess.\n";
		std::cin >> letter_guess;

		//double guess check
		size_t pos = given_letters.find(letter_guess);
		if (pos != std::string::npos)
		{
			std::cout << "You've already given that letter. Tries left: " << tries << " Try again.\n";
			continue;
		}
		given_letters.push_back(letter_guess);

		guess_check(letter_occurance_pos, h_w, letter_guess, found_letter, guess, tries);

		if (guess == h_w)
		{
			std::cout << "You WON and the hidden word was: " << h_w << "\n";
			break;
		}

		while_epilogue(letter_occurance_pos, found_letter, guess, tries);
	}
}