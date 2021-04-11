#include <vector>
#include <iterator>
#include <numeric>
#include <iostream>

class zip_iterator
{
	using dvecit = std::vector<double>::iterator;
	dvecit m_it1;
	dvecit m_it2;
public:
	zip_iterator(dvecit it1, dvecit it2)
	: m_it1(it1), m_it2(it2) {}

	zip_iterator& operator++()
	{
		m_it1++;
		m_it2++;
		return *this;
	}

	std::pair<double, double> operator*() const{
		return {*m_it1, *m_it2};
	}

	bool operator!=(const zip_iterator& other){
		return m_it1 != other.m_it1 && m_it2 != other.m_it2; 
	}

	bool operator==(const zip_iterator& other){
		return !(*this != other);
	}

};

class zip_range
{
	using dvec = std::vector<double>;
	using dvecit = dvec::iterator;
	dvec& m_first;
	dvec& m_second; 
public:
	zip_range(dvec& first, dvec& second)
	: m_first(first), m_second(second)
	{}
	zip_iterator begin(){
		return {m_first.begin(), m_second.begin() };
	}
	zip_iterator end(){
		return {m_first.end(), m_second.end() };
	}

};

namespace std {
template <>
struct iterator_traits<zip_iterator> {
	using iterator_category = std::forward_iterator_tag;
	using value_type = std::pair<double, double>;
	using difference_type = long int;
};
}


int main(void)
{
	std::vector<double> a {1.0, 2.0, 3.0};
	std::vector<double> b {4.0, 5.0, 6.0};
	const auto add_product ([](double sum, const auto &p) {
		return sum + p.first * p.second;
	});
	zip_range range(a, b);
	const auto dot_product (std::accumulate(
		std::begin(range), std::end(range), 0.0, add_product)
	);
	std::cout << dot_product << std::endl;
	return 0;
}