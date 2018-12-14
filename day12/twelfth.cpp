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
#include <list>
#include <functional>
#include <cassert>
#include <chrono>
#include <deque>
#include <map>
#include <deque>

int diff = 0;

struct rule
{
	int prev2;
	int prev;
	int cur;
	int next;
	int next2;
	int res;

	std::string print() const
	{
		std::string res;
		res += prev2 ? '#' : '.';
		res += prev ? '#' : '.';
		res += cur ? '#' : '.';
		res += next ? '#' : '.';
		res += next2 ? '#' : '.';
		return res;
	}

	bool operator()(const rule& other) const
	{
		bool result = false;
		if (other.prev2 == prev2 && other.prev == prev && other.cur == cur && other.next == next && other.next2 == next2)
		{
			result = other.res == 1;
		}
		if (false && result)
			std::cout << print() << " - " << other.print() << " - " << result << std::endl;
		return result;
	}
};


std::deque<int> data { 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0};
//std::deque<int> data{ 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1 };

//const std::vector<rule> rules{ {0, 0, 0, 1, 1, 1}, {0, 0, 1, 0, 0, 1}, {0, 1, 0, 0, 0, 1}, {0, 1, 0, 1, 0, 1}, {0, 1, 0, 1, 1, 1}, {0, 1, 1, 0, 0, 1}, {0, 1, 1, 1, 1, 1}, {1, 0, 1, 0, 1, 1}, {1, 0, 1, 1, 1, 1}, {1, 1, 0, 1, 0, 1}, {1, 1, 0, 1, 1, 1}, {1, 1, 1, 0, 0, 1}, {1, 1, 1, 0, 1, 1}, {1, 1, 1, 1, 0, 1} };
std::vector<rule> rules{ {0, 0, 0, 1, 0, 1}, {1, 0, 0, 1, 1, 1}, {0, 0, 0, 0, 0, 0}, {1, 1, 0, 1, 1, 0}, {0, 1, 1, 0, 0, 1}, {0, 1, 1, 0, 1, 0}, {1, 1, 1, 1, 0, 1}, {0, 1, 0, 1, 0, 0}, {0, 0, 1, 0, 1, 0}, {0, 1, 0, 1, 1, 0}, {0, 1, 0, 0, 1, 0}, {1, 1, 0, 0, 0, 1}, {1, 0, 0, 0, 1, 1}, {1, 1, 1, 1, 1, 0}, {1, 0, 1, 1, 1, 1}, {0, 0, 1, 1, 1, 1}, {1, 1, 1, 0, 0, 0}, {1, 0, 1, 0, 1, 1}, {1, 1, 0, 0, 1, 1}, {0, 0, 1, 0, 0, 1}, {0, 1, 1, 1, 1, 0}, {1, 0, 1, 1, 0, 0}, {0, 0, 0, 0, 1, 0}, {0, 0, 0, 1, 1, 0}, {1, 0, 0, 0, 0, 0}, {1, 0, 0, 1, 0, 0}, {0, 0, 1, 1, 0, 0}, {1, 1, 1, 0, 1, 1}, {1, 0, 1, 0, 0, 1}, {1, 1, 0, 1, 0, 1}, {0, 1, 1, 1, 0, 0}, {0, 1, 0, 0, 0, 0} };


auto checkPlant = [&](std::size_t pos, std::deque<int>& data)
{
	auto ddd = 0;
	ddd = 154;
	rule r = { data[pos - 2], data[pos - 1], data[pos], data[pos + 1], data[pos + 2] };
	return std::any_of(rules.begin(), rules.end(), r);
};



auto extendIfNeeded = [&](std::deque<int>& data)
{
	const auto firstPlantPos = std::distance(data.begin(), std::find(data.begin(), data.end(), 1));
	const auto lastPlantPos = std::distance(data.rbegin(), std::find(data.rbegin(), data.rend(), 1));
	for (auto i = 0; i < 4 - firstPlantPos; ++i)
	{
		data.emplace_front();
		diff++;
	}
	for (auto i = 0; i < 4 - lastPlantPos; ++i)
	{
		data.emplace_back();
	}
};

//constexpr auto generation_numbers = 11;
constexpr auto new_seed = 50000000000;

int doMagic(int generation_numbers)
{
	auto org_begin = data.begin();
	auto org_end = data.end();
	auto& ref = data[0];
	auto& end_red = data[data.size() - 1];

	int start_diff = std::distance(data.begin(), std::find(data.begin(), data.end(), 1));

	for (auto i = 0; i < generation_numbers; ++i)
	{
		extendIfNeeded(data);
		std::deque<int> tmp = data;
		auto tmp_begin = tmp.begin();
		auto tmp_end = tmp.end();

		const auto start_pos = 2;
		const auto end_pos = tmp.size() - 2;
		for (auto pos = start_pos; pos < end_pos; ++pos)
			tmp[pos] = checkPlant(pos, data) ? 1 : 0;

		for (auto j = 0; j < tmp.size(); ++j)
			data[j] = tmp[j];
	}
	diff = -diff;
	int sum = 0;
	for (auto i = 0; i < data.size(); ++i)
	{
		if (data[i])
		{
			sum += i;
			sum += diff;
		}
	}
	///std::cout << "[" << generation_numbers << "]: " <<  sum << " size: " << data.size()  << " diff: " << -diff << std::endl;
	return sum;
}


int main()
{
	std::deque<int> data_org { 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0 };
	const std::vector<rule> rules_org{ {0, 0, 0, 1, 0, 1}, {1, 0, 0, 1, 1, 1}, {0, 0, 0, 0, 0, 0}, {1, 1, 0, 1, 1, 0}, {0, 1, 1, 0, 0, 1}, {0, 1, 1, 0, 1, 0}, {1, 1, 1, 1, 0, 1}, {0, 1, 0, 1, 0, 0}, {0, 0, 1, 0, 1, 0}, {0, 1, 0, 1, 1, 0}, {0, 1, 0, 0, 1, 0}, {1, 1, 0, 0, 0, 1}, {1, 0, 0, 0, 1, 1}, {1, 1, 1, 1, 1, 0}, {1, 0, 1, 1, 1, 1}, {0, 0, 1, 1, 1, 1}, {1, 1, 1, 0, 0, 0}, {1, 0, 1, 0, 1, 1}, {1, 1, 0, 0, 1, 1}, {0, 0, 1, 0, 0, 1}, {0, 1, 1, 1, 1, 0}, {1, 0, 1, 1, 0, 0}, {0, 0, 0, 0, 1, 0}, {0, 0, 0, 1, 1, 0}, {1, 0, 0, 0, 0, 0}, {1, 0, 0, 1, 0, 0}, {0, 0, 1, 1, 0, 0}, {1, 1, 1, 0, 1, 1}, {1, 0, 1, 0, 0, 1}, {1, 1, 0, 1, 0, 1}, {0, 1, 1, 1, 0, 0}, {0, 1, 0, 0, 0, 0} };
	int prevSum = doMagic(1);
	for (auto i = 2; i <= 1; ++i)
	{
		auto sum = doMagic(i);
		//std::cout << "[" << i << "]: sum" << sum << " diff: " << prevSum - sum << std::endl;
		data = data_org;
		rules = rules_org;
		diff = 0;
		prevSum = sum;
	}

	constexpr auto answer = 11475 + (new_seed - 500) * 22;
	std::cout << std::endl << "second puzzle answer: " << answer << std::endl;
	return 0;

}