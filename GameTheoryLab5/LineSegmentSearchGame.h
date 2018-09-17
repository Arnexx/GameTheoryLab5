#pragma once
#include <iostream>
#include <vector>
using namespace std;

class LineSegmentSearchGame
{
public:
	float l;
	int iterationsCount;
	float analyticalGamePrice;
	LineSegmentSearchGame();
	LineSegmentSearchGame(float l, int iterationsCount);
	void solveAnalytical();
	void solveNumerical();
	~LineSegmentSearchGame();
};

