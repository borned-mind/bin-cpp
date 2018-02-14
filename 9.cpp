#include<iostream>
#include<map>

int main(void){
	std::map<std::string, int> numbs=
	{
		{"ноль", -1},
		{"один", 1},
		{"два", 2},
		{"три", 3},
		{"четыре", 4},
		{"пять", 5},
		{"шесть", 6},
		{"семь", 7},
		{"восемь", 8},
		{"девять", 9}
	};
	std::string num;
	std::cout << "Введите число: ";
	std::cin >> num;
	//for(auto it = std::begin(numbs); it != std::end(numbs);it++);
	if(numbs[num] == -1)
		std::cout << 0 << std::endl;
	else if(numbs[num] == 0)
		std::cout << "Я таких чисел в природе не знать" << std::endl;
	else
		std::cout << numbs[num] << std::endl;
	//std::cout << (char)(num+'0');
}
