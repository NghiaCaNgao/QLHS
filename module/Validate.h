#ifndef Validate
#define Validate

#include <iostream>
#include <stdexcept>
#include <limits>

// Generic function to validate number type
template <typename T>
T validateNumber(const char *title, const char *errortext = "")
{
    bool isValid = true;
    do
    {
        try
        {
            isValid = true;
            std::cout << title;
            T value;
            std::cin >> value;
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw std::invalid_argument("Nhan vao khong phai mot so");
            }
            return value;
        }
        catch (std::invalid_argument &e)
        {
            std::cout << e.what() << std::endl;
            std::cout << errortext << std::endl;
            isValid = false;
        }
    } while (!isValid);
}

// Check the score is valid or not
float ValidateScore(const char *title, const char *errortext = "")
{
    float score = 0;
    do
    {
        score = validateNumber<float>(title, "");
        if (score < 0 || score > 10)
            std::cout << errortext << std::endl;
    } while (score < 0 || score > 10);
    return score;
}

// Check the string is valid or not
char *validateString(const char *title, const char *errortext = "")
{
    bool isValid = true;
    do
    {
        try
        {
            std::cout << title;
            char *input;
            while (iswspace(std::cin.peek()))
                std::cin.ignore();
            std::cin.get(input, 50);
            return input;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
            std::cout << errortext << std::endl;
            std::cout << "Input khong hop le. Nhap lai. " << std::endl;
            isValid = false;
        }
    } while (!isValid);
}

#endif