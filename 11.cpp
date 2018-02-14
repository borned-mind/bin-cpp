#include<iostream>

static inline void monero(const char * count_n, const int count){
	std::cout << "У вас " << count << " " << count_n << "центовых " <<  "монет." << std::endl;
}

int main(void){
	int cent1, cent5, cent10, cent25, cent50, cents;
	std::cout << "Введите ваши центы 1 5 10 25 50" << std::endl;
	std::cin >> cent1 >> cent5 >> cent10 >> cent25 >> cent50;
	monero("одно", cent1);
	monero("пяти", cent5);
	monero("десяти", cent10);
	monero("двадцатипяти", cent25);
	monero("пятьдесяти", cent50);
	cents =
		cent1 + (cent5 * 5) + (cent25*25) + (cent10*10) + (cent50*50);
	if(cents > 100)
		std::cout << "У вас " << cents/100 << " долларов " << cents%100 << " центов"<< std::endl;
	else
		std::cout << "Ваши запасы центов: " << cents << std::endl;
}
