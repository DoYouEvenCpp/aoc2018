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

struct point
{
	int x;
	int y;
};


struct distance
{
	int val;
	int parent;
	bool shared;
};


constexpr std::array<point, 50> d { 118, 274, 102, 101, 216, 203, 208, 251, 309, 68, 330, 93, 91, 179, 298, 278, 201, 99, 280, 272, 141, 312, 324, 290, 41, 65, 305, 311, 198, 68, 231, 237, 164, 224, 103, 189, 216, 207, 164, 290, 151, 91, 166, 250, 129, 149, 47, 231, 249, 100, 262, 175, 299, 237, 62, 288, 228, 219, 224, 76, 310, 173, 80, 46, 312, 65, 183, 158, 272, 249, 57, 141, 331, 191, 163, 359, 271, 210, 142, 137, 349, 123, 55, 268, 160, 82, 180, 70, 231, 243, 133, 353, 246, 315, 164, 206, 229, 97, 268, 94 };
//constexpr std::array<point, 6 > d{ 1, 1, 1, 6, 8, 3, 3, 4, 5, 5, 8, 9 };
const auto getManhattanDistance = [](point a, point b)
{
	return std::abs(a.x - b.x) + std::abs(a.y - b.y);
};


int main()
{
	const auto max_x = std::max_element(d.begin(), d.end(), [](point a, point b)
	{
		return a.x < b.x;
	})->x + 2;
	const auto max_y = std::max_element(d.begin(), d.end(), [](point a, point b)
	{
		return a.y < b.y;
	})->y + 2;

	std::vector<std::vector<distance>> distances;
	for (auto i = 0; i < max_y; ++i)
	{
		distances.push_back(std::vector<distance>(max_x));
		const distance v = { std::numeric_limits<int>::max(), 0, false };
		std::fill(distances[i].begin(), distances[i].end(), v);
	}

	int parent_id = 1;

	
	/*
	first:
	for (auto p : d)
	{
		for (int i = 0; i < distances.size(); ++i)
		{
			for (int j = 0; j < distances[i].size(); ++j)
			{
				const auto current_distance = getManhattanDistance(p, {j, i});
				if (current_distance < distances[i][j].val)
				{
					distances[i][j].val = current_distance;
					distances[i][j].shared = false;
					distances[i][j].parent = parent_id;
				}
				else if (current_distance == distances[i][j].val)
				{
					distances[i][j].shared = true;
				}
			}
		}
		distances[p.y][p.x].val = 0;
		++parent_id;
	}*/

	//second:

	int second_answer = 0;
	for (int i = 0; i < distances.size(); ++i)
	{
		for (int j = 0; j < distances[i].size(); ++j)
		{
			unsigned local_dist = 0;
			for (auto p : d)
			{
				const auto current_distance = getManhattanDistance(p, { j, i });
				local_dist += current_distance;
			}
			if (local_dist < 10000)
			{
				second_answer += 1;
			}
		}
	}
	std::cout << second_answer;

	//for (auto & line : distances[0])
	//{
	//	if (!line.shared)
	//		line.val = std::numeric_limits<int>::max();
	//}

	//for (auto & line : distances[distances.size() - 1])
	//{
	//	if (!line.shared)
	//		line.val = std::numeric_limits<int>::max();
	//}

	//for (int row = 0; row < distances.size(); ++row)
	//{
	//	if (!distances[row][distances[row].size()-1].shared)
	//		distances[row][distances[row].size()-1].val = std::numeric_limits<int>::max();

	//	if (!distances[row][0].shared)
	//		distances[row][0].val = std::numeric_limits<int>::max();
	//}

	//std::map<int, std::pair<int, bool>> values;
	//for (auto&v : distances)
	//{
	//	for (auto e : v)
	//	{
	//		if (values.count(e.parent) == 0)
	//		{
	//			values[e.parent] = std::pair(0, true);
	//		}
	//		if (e.val == std::numeric_limits<int>::max())
	//		{
	//			values[e.parent].second = false;
	//			continue;
	//		}
	//		if (e.shared) continue;
	//		values[e.parent].first += 1;

	//	}
	//		/*if (e.val == std::numeric_limits<int>::max())
	//			std::cout << "I ";
	//		else if (e.shared)
	//			std::cout << ". ";
	//		else if (e.val == 0)
	//		{
	//			switch (e.parent)
	//			{
	//				case 1: std::cout << "A "; break;
	//				case 2: std::cout << "B "; break;
	//				case 3: std::cout << "C "; break;
	//				case 4: std::cout << "D "; break;
	//				case 5: std::cout << "E "; break;
	//				case 6: std::cout << "F "; break;
	//			}
	//		}
	//		else
	//			std::cout << e.val << " ";
	//	}
	//	std::cout << std::endl;*/
	//}

	//int max = 0;
	//for (auto& e : values)
	//{
	//	if (e.second.second && e.second.first > max)
	//			max = e.second.first;
	//}
	//std::cout << "max: " << max << std::endl;

	return 0;
}