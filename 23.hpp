#include<vector>
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


		void 	primary( double & );

		double expression();

		std::vector<Token> get_token();
	private:
		long long int factorial(long long int to);

};
