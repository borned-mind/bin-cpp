
#include<iostream>
#include<vector>
#include<string>

const std::vector<std::string> disliked={
	"brocolli",
	"sooqa",
	"fag",
	"faggot",
	"shit",
	"zooma",
	"nigger"

};

int main(void){
	std::cout << "Write some words and after control+D(linux)/control+Z(window)" << std::endl;

	std::vector<std::string> words;
	for(std::string i;std::cin>>i;)
		words.push_back(i);
	for(auto first : words)
		for(auto second : disliked)
			if(first == second)
				std::cout << first << "=BLEEP!" << std::endl;
	for(auto first: words)
		words.pop_back();
}
