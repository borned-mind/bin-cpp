#include<iostream>

enum class moving : char{
	right, left, up, down
};


class room{
	private:
		char ** room_self;
		unsigned int t_x=0,t_y=0, x_size,y_size;
	public:
		room(const unsigned int x, const unsigned int y){
			this->room_self = new char*[y];
			for(unsigned int y_ = y; y_--;)
				this->room_self[y_] = new char[x];
			x_size=x;
			y_size=y;
		};
		char **& getRoom(){
			return room_self;
		};
		private:
		void move_x(int x){
			if(t_x+x < x_size) this->t_x+=x;
		};
		void move_y(int y){
			if(t_y+y < y_size) this->t_y+=y;
		};
		void moving(unsigned int x, unsigned int y){
			move_x(x);
			move_y(y);
		};
		public:
		void getMoving(void){
			char ch;
			std::cout << "Куда мне сейчас идти(1 -> право, 2-> лево, 3-> вперед(вверх), 4 -> назад(вниз): ";
			std::cin >> ch;
			switch(ch){
				case '1':
					move_x(1);
				case '2':
					move_x(-1);
				case '3':
					move_y(1);
				case '4':
					move_y(-1);
				default:
					std::cout << "Не понял!" << std::endl;
					break;
			};

		};
};


int main(void){
	room myRoom{10,10};
	//...
}
