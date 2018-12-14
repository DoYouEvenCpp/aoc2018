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



enum class direction
{
	up,
	down,
	left,
	right
};

struct position
{
	int x;
	int y;
};

struct cart
{
	int x;
	int y;
	direction last_move;
};

int main()
{
}