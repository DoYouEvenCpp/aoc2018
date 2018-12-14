#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <iterator>
#include <vector>
#include <fstream>
#include <cctype>
#include <numeric>
#include <set>
#include <array>
#include <map>
#include <memory>
#include <algorithm>

struct Node
{
	Node* left;
	Node* right;
	char ch;
};


struct data
{
	char from;
	char to;
};

int main()
{
	//test data
	//std::vector<data> v{ {'F', 'N'}, {'V', 'Y'}, {'B', 'W'}, {'K', 'O'}, {'E', 'H'}, {'A', 'P'}, {'Y', 'S'}, {'T', 'L'}, {'G', 'R'}, {'I', 'H'}, {'X', 'M'}, {'N', 'C'}, {'O', 'R'}, {'Z', 'R'}, {'R', 'D'}, {'M', 'C'}, {'H', 'D'}, {'C', 'U'}, {'J', 'D'}, {'L', 'Q'}, {'D', 'U'}, {'S', 'U'}, {'U', 'Q'}, {'P', 'Q'}, {'W', 'Q'}, {'X', 'R'}, {'P', 'W'}, {'B', 'U'}, {'E', 'J'}, {'T', 'R'}, {'M', 'L'}, {'M', 'P'}, {'V', 'T'}, {'T', 'U'}, {'R', 'W'}, {'V', 'A'}, {'X', 'S'}, {'V', 'U'}, {'C', 'P'}, {'J', 'S'}, {'F', 'D'}, {'Y', 'U'}, {'L', 'W'}, {'F', 'T'}, {'B', 'E'}, {'F', 'J'}, {'R', 'M'}, {'Z', 'W'}, {'K', 'E'}, {'S', 'W'}, {'U', 'P'}, {'S', 'P'}, {'D', 'W'}, {'Z', 'P'}, {'U', 'W'}, {'M', 'J'}, {'M', 'W'}, {'H', 'U'}, {'E', 'C'}, {'C', 'Q'}, {'L', 'U'}, {'Y', 'R'}, {'E', 'D'}, {'A', 'S'}, {'Z', 'J'}, {'X', 'W'}, {'C', 'D'}, {'C', 'S'}, {'G', 'N'}, {'K', 'Z'}, {'T', 'I'}, {'H', 'W'}, {'E', 'Q'}, {'R', 'J'}, {'O', 'H'}, {'O', 'J'}, {'L', 'S'}, {'A', 'H'}, {'K', 'G'}, {'I', 'X'}, {'T', 'W'}, {'O', 'W'}, {'N', 'Q'}, {'V', 'Z'}, {'H', 'S'}, {'F', 'L'}, {'X', 'Z'}, {'I', 'U'}, {'T', 'J'}, {'G', 'S'}, {'E', 'U'}, {'M', 'U'}, {'J', 'U'}, {'E', 'P'}, {'F', 'C'}, {'O', 'Q'}, {'D', 'Q'}, {'A', 'L'}, {'H', 'J'}, {'I', 'P'}, {'Y', 'D'} };
	//std::vector<data> v{ {'C', 'A'}, {'C', 'F'}, {'A', 'B'},{'A', 'D'} ,{'B', 'E'} ,{'D', 'E'} ,{'F', 'E' } };
	std::vector<data> v{ {'A', 'I'},{'M', 'Q'},{'B', 'S'},{'G', 'N'},{'Y', 'R'},{'E', 'H'},{'K', 'L'},{'H', 'Z'},{'C', 'P'},{'W', 'U'},{'V', 'L'},{'O', 'N'},{'U', 'I'},{'D', 'P'},{'Q', 'L'},{'F', 'Z'},{'L', 'N'},{'P', 'S'},{'I', 'S'},{'S', 'R'},{'T', 'N'},{'N', 'X'},{'Z', 'J'},{'R', 'J'},{'J', 'X'},{'E', 'I'},{'T', 'R'},{'I', 'N'},{'K', 'C'},{'B', 'D'},{'K', 'T'},{'E', 'P'},{'F', 'I'},{'O', 'U'},{'I', 'J'},{'S', 'Z'},{'L', 'J'},{'F', 'T'},{'F', 'P'},{'I', 'T'},{'G', 'S'},{'V', 'U'},{'F', 'R'},{'L', 'R'},{'Y', 'D'},{'M', 'E'},{'U', 'L'},{'C', 'D'},{'W', 'N'},{'S', 'N'},{'O', 'S'},{'B', 'T'},{'V', 'T'},{'S', 'X'},{'V', 'P'},{'F', 'L'},{'P', 'R'},{'D', 'N'},{'C', 'L'},{'O', 'Q'},{'N', 'Z'},{'Y', 'L'},{'B', 'K'},{'P', 'Z'},{'V', 'Z'},{'U', 'J'},{'Q', 'S'},{'H', 'F'},{'E', 'O'},{'D', 'F'},{'D', 'X'},{'L', 'S'},{'Z', 'R'},{'K', 'X'},{'M', 'V'},{'A', 'M'},{'B', 'W'},{'A', 'P'},{'W', 'Q'},{'R', 'X'},{'M', 'H'},{'F', 'S'},{'K', 'Q'},{'Y', 'Q'},{'W', 'S'},{'Q', 'T'},{'K', 'H'},{'K', 'D'},{'E', 'T'},{'Y', 'E'},{'A', 'O'},{'G', 'E'},{'C', 'O'},{'G', 'H'},{'Y', 'I'},{'V', 'S'},{'B', 'R'},{'B', 'X'},{'V', 'I'},{'N', 'J'},{'H', 'I'} };
	std::map<char, int> temp;
	std::map<char, std::vector<char>> transitions;
	for (auto& d : v)
	{
		if (transitions.count(d.from) == 0)
		{
			transitions[d.from];
		}
	}
	std::vector<char> answer;

	for (auto& d : v)
	{
		transitions[d.to].push_back(d.from);
	}

	//first
	while (transitions.size() > 0)
	{
		auto it = std::find_if(transitions.begin(), transitions.end(), [](auto& p)
		{
			return p.second.empty();
		});

		answer.push_back(it->first);
		for (auto& p : transitions)
		{
			auto& vec = p.second;
			vec.erase(std::remove_if(vec.begin(), vec.end(), [&it](char c){return c == it->first; }), vec.end());
		}
		transitions.erase(it->first);
	}
	for (auto& c : answer)
		std::cout << c;

	std::cout << std::endl;


	//second
	struct worker
	{
		int counter;
		int load;
		char ch{ ' ' };
	};

	std::map<int, worker> second_answer;
	using worker_type = std::pair<const int, worker>;
	second_answer[0];
	second_answer[1];
	second_answer[2];
	second_answer[3];
	second_answer[4];

	constexpr auto SEC_COUNT = 60;
	auto current_worker = 0;
	constexpr auto ascii_start_index = 64;

	const auto getNextWorker = [&second_answer]
	{
		return std::min_element(second_answer.begin(), second_answer.end(), [](worker_type& a, worker_type&b)
		{
			return a.second.counter < b.second.counter;
		})->first;
	};

	const auto isIdle = [&second_answer]
	{
		return std::any_of(second_answer.begin(), second_answer.end(), [](worker_type& w)
		{
			return w.second.counter == 0;
		});
	};


	const auto isAlreadyHandled = [&second_answer](char ch)
	{
		return std::any_of(second_answer.begin(), second_answer.end(), [ch](worker_type& w)
		{
			return w.second.ch == ch;
		});
	};

	const auto updateWorkersState = [&]
	{
		for (auto& worker : second_answer)
		{
			if (worker.second.counter > 0)
				--worker.second.counter;

			if (worker.second.counter == 0 && worker.second.ch != ' ')
			{
				const auto ch = worker.second.ch;
				for (auto& p : transitions)
				{
					auto& vec = p.second;
					vec.erase(std::remove_if(vec.begin(), vec.end(), [ch](char c) {return c == ch; }), vec.end());
				}
				transitions.erase(ch);
				worker.second.ch = ' ';
			}
		}
	};
	int i = 0;
	while (true)
	{
		auto it = std::find_if(transitions.begin(), transitions.end(), [&](auto& p)
		{
			return p.second.empty() && !isAlreadyHandled(p.first);
		});
		while (it != transitions.end() && !isAlreadyHandled(it->first) && isIdle())
		{
			while (second_answer[current_worker].counter > 0)
			{
				current_worker = getNextWorker();
			}
			const auto diff = SEC_COUNT + (it->first - ascii_start_index);
			second_answer[current_worker].counter = diff;
			second_answer[current_worker].load += diff;
			second_answer[current_worker].ch = it->first;
			std::cout << i << " - worker[" << current_worker << "] takes " << it->first << " which will last: " << diff << std::endl;
			it = std::find_if(it, transitions.end(), [&](auto& p)
			{
				return p.second.empty() && !isAlreadyHandled(p.first);
			});
		}
		++i;
		updateWorkersState();

		if (transitions.size() == 0)
			break;
	}


	std::cout << i << std::endl;
	return 0;
}