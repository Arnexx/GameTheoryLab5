#include "LineSegmentSearchGame.h"
#include <iomanip>



LineSegmentSearchGame::LineSegmentSearchGame()
{
}

LineSegmentSearchGame::LineSegmentSearchGame(float l, int iterationsCount)
{
	setlocale(LC_ALL, "Russian");
	this->l = l;
	this->iterationsCount = iterationsCount;
	cout.setf(ios::internal);
	cout.setf(ios::fixed);
	cout << setprecision(2) << "Игра поиска на отрезке для l = "  << l << endl;
}

void LineSegmentSearchGame::solveAnalytical()
{
	int n = int(std::floor( (1.0 / (2.0 * l))));
	float coef = float(1 - 2 * l) / (float)(n - 1);
	vector<float> firstPlayerPoints, secondPlayerPoints;
	firstPlayerPoints.resize(n);
	secondPlayerPoints.resize(n);
	for (int i = 0; i < n; i++)
	{
		firstPlayerPoints[i] = l + coef * (float)i;
		secondPlayerPoints[i] = (float)i / (float)(n - 1);
	}		
	float gamePrice = 1.0 / (float)n;
	analyticalGamePrice = gamePrice;
	setlocale(LC_ALL, "Russian");
	cout.setf(ios::internal);
	cout.setf(ios::fixed);
	cout << "Аналитическое решение: " << endl;
	cout << "Точки первого игрока: " << endl;
	cout << "[ ";
	for (int i = 0; i < firstPlayerPoints.size(); i++)
		cout << setprecision(3) << firstPlayerPoints[i] << ", ";
	cout << " ]" << endl;

	cout << "Точки второго игрока: " << endl;
	cout << "[ ";
	for (int i = 0; i < secondPlayerPoints.size(); i++)
		cout << setprecision(3) << secondPlayerPoints[i] << ", ";
	cout << " ]" << endl;
	cout << "Цена игры: " << setprecision(3) << gamePrice << endl << endl;
		
}

void LineSegmentSearchGame::solveNumerical()
{
	int firstPlayerWins = 0;
	for (int i = 0; i < iterationsCount; i++)
	{
		float x = (rand() % 100) * 0.01;
		float y = (rand() % 100) * 0.01;
		if (abs(x - y) <= l)
			firstPlayerWins++;
	}
	float gamePrice = float(firstPlayerWins) / (float)iterationsCount;
	float deltaPrice = abs(float(gamePrice - analyticalGamePrice)) / (10.0*gamePrice);
	cout << "Численное решение для " << iterationsCount << " итераций:" << endl;
	cout << "Цена игры: " << setprecision(3) << gamePrice << endl;
	cout << "Относительная погрешность численного решения: " << setprecision(3) << deltaPrice << endl;
}


LineSegmentSearchGame::~LineSegmentSearchGame()
{
}
