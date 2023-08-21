#include <iostream>
#include <sample01.hpp>
#include <sample02.hpp>
void printWelcomeMessage(std::string& text) {
    std::cout << text << "edited" << std::endl;
    };

void printsamplewithwelcome(std::string& text) {
    printsample(text);
    printWelcomeMessage(text);
    };