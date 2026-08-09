#include <iostream>

int addNumbers( int first_param, int second_param){
    int result = first_param + second_param;
    return result;
}

int main(){

    int first_number; // Statement
    std::cin >> first_number;
    int second_number;
    std::cin >> second_number;

    std::cout << "First number : " << first_number << std::endl; 
    std::cout << "Second number : " << second_number << std::endl; 

    int sum = first_number + second_number;
    std::cout << "Sum : " << sum << std::endl; 

    sum = addNumbers(25,7);
    std::cout << "Sum : " << sum << std::endl; //32

    sum = addNumbers(first_number,second_number);
    std::cout << "Sum : " << sum << std::endl; 

    sum = addNumbers(30,54);
    std::cout << "Sum : " << sum << std::endl; //84

    std::cout << "Sum : " << addNumbers(3,42) << std::endl; //45

    return 0;
}