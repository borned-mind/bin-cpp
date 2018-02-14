#include<iostream>
#include<vector>
#include<time.h>
#include<stdlib.h>

int main(void){
	long double salt;
	srand(time(NULL));
	std::cout << "Загадайка любое числишко: " ;
	std::cin >> salt;
	srand(rand()%1+salt);
	std::vector<int> v = {rand()%10,rand()%10,rand()%10,rand()%10};
	std::vector<int> vp(4);
	char cows, bull;
	bool is_cows;
	while(vp != v){
		is_cows=true;
		cows=bull=0;
		std::cout << "Введите четырех числа через пробел: ";
		for( auto & x : vp ){
			std::cin>>x;
			while(x > 9){
				std::cout << "Числа не могут быть больше 9!"<<std::endl;
				std::cin >> x;
			}
			if(!std::cin) {
				std::cerr << "не опознал знак я, прости" << std::endl;
				std::cerr << "на сегодня с тебя игр достаточно" << std::endl;
				return 1;
			}
		}
		for ( unsigned char i = 0;i<v.size();i++ )
			{
				if(vp[i] != v[i]) is_cows=false;
				if(is_cows) cows++;
				else if( v[i] == vp[i] ) bull++;
			}
		std::cout << int(cows) << " коровы " << (int)bull << " быков" << std::endl;
	}
	main();
}
