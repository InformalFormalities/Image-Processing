//By: Declan Doss, Khushkaranpreet Grewal, & Luis Sanchez
#include <vector>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;

const int RED = 0, GREEN = 1, BLUE = 2;

void filter2(vector<vector<vector<int>>> &vec) {
	size_t rows = vec.size();
	if (!rows) exit(1);
	size_t cols = vec.at(0).size();
	if (!cols) exit(1);
	size_t colors = vec.at(0).at(0).size();
	if (!colors) exit(1);

	//redGradient must start at 1 as it gradients from the left to right.
	//cyanGradient must start at 0 as it gradients from right to left.
	double redGradient = 1;
	double cyanGradient = 0;

	//For ever row and column...
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			//Creates vertical lines which are used to cause the red/cyan gradienting without changing the picture fundamentally.
			if ((i + 5) % 2) {
				//If we're at the left side of the picture...
				if (i < 1970){
					//...set the color (red) with the gradient.
					vec[i][j][RED] = 128 * redGradient;
					vec[i][j][GREEN] = 35 * redGradient;
					vec[i][j][BLUE] = 4 * redGradient;
				}
				//Else if we're at the right side of the picture...
				else {
					//...set the color (cyan) with the gradient.
					vec[i][j][RED] = 179 * cyanGradient;
					vec[i][j][GREEN] = 237 *cyanGradient;
					vec[i][j][BLUE] = 252 * cyanGradient;
				}
			}
		}
		//For each column, reduce the gradient for red.
		if (i < 1970) redGradient -= 0.00048;
		//For each column, increase the gradient for cyan.
		else if (i > 1970) cyanGradient += 0.00048;
	}
}
