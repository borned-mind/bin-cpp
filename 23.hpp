#include<vector>


namespace Grammar{
	enum class priority : char{
		low=1, normal, high
	};
	struct prioryty_container{
		char kind;
		priority prior;
	};

	const prioryty_container priority_vals[] ={
			{'n', priority::low},

			{'-', priority::low},
			{'+', priority::low},

			{'/', priority::normal},
			{'*', priority::normal},

			
		//	{'(', priority::high},
		//	{')', priority::high},
			{'!', priority::high}
			
	};
	constexpr auto size_priority = sizeof(priority_vals);
}

struct Token{
	Token(char kind) : kind(kind), val(0) {}
	Token(char kind, double val) : kind(kind), val(val) {}
	Token(void) : kind(0), val(0){}
	char kind;
	double val;
};



class Token_Stream{
	public:
		void putback(char kind, double val);
		void putback(char kind);
		void putback(double val);
		void putback(Token t);
		void setPriority(void);

		Token get(void);
		std::vector<Token> get_buffer(void){
			std::vector<Token> tmp=this->buffer;
			this->buffer={};
			return tmp;
		}
		void getline(void);
		
		Token_Stream(void) : buffer(0) {}
	private:
		std::vector<Token> buffer;

		//Token_Stream * next;
};

class parser{
	public:


		void 	primary( double &, std::vector<Token>::const_iterator&, std::vector<Token>::const_iterator  );

		double expression();

		std::vector<Token> get_token();
	private:
		long long int factorial(long long int to);

};
