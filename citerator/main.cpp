#include <iostream>
#include <iterator>

class citerator_centinale{};

class citerator{
	const char* m_str;
public:
	citerator(const char* str)
	: m_str(str){}

	char operator*(){
		return *m_str;
	}
	citerator& operator++(){
		m_str++;
		return *this;
	}
	bool operator!=(citerator_centinale){
		return m_str != nullptr && *m_str!='\0';
	}
};

class crange
{
	const char* m_str{nullptr};
public:
	crange(const char* str)
	: m_str(str) {}
	citerator begin(){ return citerator(m_str);}

	citerator_centinale end(){ return citerator_centinale();}
};

int main(int argc, char**argv){
	if (argc < 2){
		std::cerr << "Wrong input" << std::endl;
	}
	for (const auto c: crange(argv[1])){
		std::cout << c;
	}
	std::cout << std::endl;
	return 0;
}