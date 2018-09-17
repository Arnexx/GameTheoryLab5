#include <iostream>
#include <vector>
#include <ctime>
#include "LineSegmentSearchGame.h"
using namespace std;

int main()
{
	srand(time(0));
	LineSegmentSearchGame game(0.1, 10000);
	game.solveAnalytical();
	game.solveNumerical();

	system("pause");
	return 0;
}
