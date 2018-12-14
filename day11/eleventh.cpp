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
#include <execution>


namespace
{
	constexpr auto size = 300*300;

	template <typename T>
	struct dummyAllocator
	{
		typedef T value_type;
		dummyAllocator() = default;

		T* allocate(std::size_t n)
		{
			T* res = reinterpret_cast<T*>(block.data() + cur_pos);
			cur_pos += n;
			return res;
		}

		void deallocate(T*, std::size_t n) noexcept
		{
			cur_pos -= n;
		}

	private:
		static std::array<T, size> block;
		std::size_t cur_pos{ 0 };
	};

	template<typename T>
	std::array<T, size> dummyAllocator<T>::block = std::array<T, size>();
}


const auto getPowerLevel = [](int x, int y, int sn)
{
	const auto rackId = x + 10;
	const auto powerLvl = rackId * y;
	const auto tempA = powerLvl + sn;
	const auto tempB = tempA * rackId;
	if (tempB < 100)
	{
		return -5;
	}
	else
	{
		const int answer = tempB / 100;
		const auto dd = answer % 10;
		const auto ee = dd - 5;
		return ee;
	}
};


int main()
{
	const auto input = 2866;
	std::array<std::array<int, 300>, 300> m;
	for (auto i = 0; i < 300; ++i)
	{
		for (auto j = 0; j < 300; ++j)
			m[i][j] = getPowerLevel(i + 1, j + 1, input);
	}

	std::map<int, std::pair<int, int>> ans;

	for (auto i = 0; i < 297; i++)
	{
		for (auto j = 0; j < 297; ++j)
		{
			int sum = 0;
			for (auto k = 0; k < 3; ++k)
				for (auto l = 0; l < 3; ++l)
					sum += m[i + k][ j + l];
			ans[sum] = { i + 1, j + 1 };
		}
	}
	auto max_el = std::max_element(ans.begin(), ans.end());
	std::cout << max_el->first << " (" << max_el->second.first << ", " << max_el->second.second << ")\n";

	struct helper
	{
		int x;
		int y;
		int square;
	};
	int the_sum = 0;
	helper current;
	unsigned long long time_sum = 0;
	auto start = std::chrono::steady_clock::now();
	int temp_sum = 0;
//#pragma vector align
//#pragma loop( hint_parallel(8))
//#pragma loop( ivdep )
	for (auto size = 0; size < 300; ++size)
	{
		for (auto i = 0; i < 300 - size; i++)
		{
			for (auto j = 0; j < 300 - size; ++j)
			{
//#pragma loop( hint_parallel(8))
//#pragma loop( ivdep )
				for (auto k = 0; k < size; ++k)
					for (auto l = 0; l < size; ++l)
						temp_sum += m[i + k][j + l];
				if (temp_sum > the_sum)
				{
					the_sum = temp_sum;
					current = { i + 1, j + 1, size };
				}
				temp_sum = 0;
			}
		}
		//std::cout << "[" << size << "] took: " << time << " ms\n";
	}

	auto end = std::chrono::steady_clock::now();
	const auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	time_sum += time;
	std::cout << "\nSecond puzzle: " << the_sum << " (" << current.x << ", " << current.y << ") " << current.square
		<< " it took: " << time_sum << " ms\n";
	return 0;
}