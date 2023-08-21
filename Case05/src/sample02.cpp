#include <string>
#include <iostream>
#include <sample02.hpp>
#include <sample01.hpp>
void printsample(std::string& text) {
    std::cout << "This is a sample function" << std::endl;
    std::cout << "The text is: " << text << std::endl;
    }

void printwelcomewithsample(std::string& text) {
    printWelcomeMessage(text);
    printsample(text);
    };
