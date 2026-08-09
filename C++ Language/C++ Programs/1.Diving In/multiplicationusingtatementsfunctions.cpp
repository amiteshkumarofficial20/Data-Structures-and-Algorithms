#include <iostream>

int product(int first_number,int second_number){
    int result = first_number * second_number;
    return result;
}
int main(){
    int first_number;
    std::cin >> first_number;
    int second_number;
    std::cin >> second_number;

    std::cout << "First number : " << first_number << std::endl; 
    std::cout << "Second number : " << second_number << std::endl; 

    int Product = first_number * second_number;
    std::cout << "Product : " << Product << std::endl; 

    Product = product(first_number,second_number);
    std::cout << "Product : " << Product << std::endl; 

}