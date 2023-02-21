#pragma once

void print_guess(const std::string guess);
void guess_initialization(std::string& guess, const std::string h_w);
void guess_check(size_t& letter_occurance_pos, const std::string& h_w, const char& letter_guess, bool& found_letter, std::string& guess, int& tries); 
void while_epilogue(size_t& letter_occurance_pos, bool& found_letter, const std::string& guess, const int& tries);
std::string game_init();
void KREMALA(const std::string& h_w);