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
		Token_Stream(void) : buffer(0), full(false){}
	private:
		Token buffer;
		bool full;
		//Token_Stream * next;
};

class parser{
	public:


		void 	primary(double &, Token&);

		double expression();

		Token get_token();
	private:

};
