#include<iostream>
#include<string>

int inline simple_error(const char * text){
	std::cout << text << std::endl;
	return 1;
}

int inline simple_error(const std::string text){
	return simple_error(text.c_str());
}

constexpr const char * get_author_name(){
	return "сволоч";
}

int main(void){
	char sex;
	int age;
	std::string first_name, friend_name;
	std::cout << "Имя, возраст: "<< std::endl;
	std::cin >> first_name >> age;
	std::cout << "Дорогой " << first_name << ", "
	<< "\nКак твои дела? У меня хорошо!" << std::endl;
	std::cout << "Введите имя общего друга и пол: ";
	std::cin >> friend_name >> sex;

	std::cout << "Давно ли ты видал "<<friend_name << "?" << std::endl;
	std::cout << "Если увидишь попроси " << (sex == 'f'? "её" : "его") << " позвонить мне";
	std::cout << std::endl;
	std::cout<< "Введите его возраст: ";
	std::cin >> age;
	if(age <= 0 || age > 110) return simple_error("Ты наверное шутишь...");
	if(age < 12)
		std::cout << "На следующий год тебе исполнится " << (age+1) << std::endl;
	else if(age == 17)
		std::cout << "В СЛЕДУЮЩЕМ ГОДУ ТЫ ПРИКИНЬ ГОЛОСАВАТЬ СМОГЕШь!" << std::endl;
	else if(age  > 70)
		std::cout << "На пенсии не скучай, братуха" <<std::endl;
	std::cout << "Искренне твой " << get_author_name() << "_______________" << std::endl;
}
