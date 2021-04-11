#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <random>

static void print(const std::vector<int> &v, const char* message = nullptr)
{
	using namespace std;
	if (message != nullptr)
		cout << message << '\n';
	copy(begin(v), end(v), ostream_iterator<int>{cout, ", "});
	cout << '\n';
}

int main(int argc, char** argv)
{
	using namespace std;
	vector<int> v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
	random_device rd;
	mt19937 g {rd()};

	cout << is_sorted(begin(v), end(v)) << '\n';

	shuffle(begin(v), end(v), g);

	cout << is_sorted(begin(v), end(v)) << '\n';

	sort(v.begin(), v.end());
	cout << is_sorted(begin(v), end(v)) << '\n';
	print(v, "sorted vector");

	shuffle(begin(v), end(v), g);

	partition(v.begin(), v.end(), [](const int i){
		return i <= 5;
	});

	print(v, "parition vecotr");

	shuffle(begin(v), end(v), g);
	auto middle (next(begin(v), int(v.size()) / 2));
	partial_sort(begin(v), middle, end(v));
	print(v, "partial_sort");
	
	return 0;
}