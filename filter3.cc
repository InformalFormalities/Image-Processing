//By: Declan Doss, Khushkaranpreet Grewal, & Luis Sanchez
#include <vector>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;

const int RED = 0, GREEN = 1, BLUE = 2;

void filter3(vector<vector<vector<int>>> &vec, vector<vector<vector<int>>> &vec2) {
	//Don't question it. (We need cols/rows/color to go out of scope for code to work. Problem with redefining.)
	if (1 == 1) {
		//Needed to do the diagonal lines.
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
		
		//For every row and column...
	    for (int i = 0; i < rows; i++) {
	        for (int j = 0; j < cols; j++) {
				//Adds the diagonal lines seen in picture.
				if ( ( (i + j) / 3) % 2) {
					//If we're at the left side of the picture...
					if (i >= 150 and i <= 1970 and j >= 100 and j <= 2300) {
						//...set the color (red) with the gradient.
						vec[i][j][RED] = 148 * redGradient;
						vec[i][j][GREEN] = 55 * redGradient;
						vec[i][j][BLUE] = 24 * redGradient;
					}
					//Else if we're at the right side of the picture...
					else if (i > 1970 and i <= 3690 and j >= 100 and j <= 2300) {
						//...set the color (cyan) with the gradient.
						vec[i][j][RED] = 199 * cyanGradient;
						vec[i][j][GREEN] = 255 * cyanGradient;
						vec[i][j][BLUE] = 255 * cyanGradient;
					}
				}
			}
			//For each column, reduce the gradient for red.
			if (i >= 150 and i <= 1970) redGradient -= 0.00050;
			//For each column, increase the gradient for cyan.
			else if (i > 1970 and i <= 3690) cyanGradient += 0.00043;
		}

    	for (int i = 0; i < rows; i++) {
        	for (int j = 0; j < cols; j++) {
				int r = vec.at(i).at(j).at(RED);
				int g = vec[i][j][GREEN];
				int b = vec[i][j][BLUE];
	
				if (i < 150) {
					vec[i][j][RED] = 255 - r;
					vec[i][j][GREEN] = 255 - g;
					vec[i][j][BLUE] = 255 - b;
				}
				else if (i > 3690) {
					vec[i][j][RED] = 255 - r;
					vec[i][j][GREEN] = 255 - g;
					vec[i][j][BLUE] = 255 - b;
				}
				else if (j < 100) {
					vec[i][j][RED] = 255 - r;
					vec[i][j][GREEN] = 255 - g;
					vec[i][j][BLUE] = 255 - b;
				}
				else if (j > 2300) {
					vec[i][j][RED] = 255 - r;
					vec[i][j][GREEN] = 255 - g;
					vec[i][j][BLUE] = 255 - b;
				}
			}
		}
	}

	//Needed to put Kerney on picture.
	size_t rows = vec.size() < vec2.size() ? vec.size() : vec2.size();
    if (!rows) exit(1);
    size_t cols = vec.at(0).size() < vec2.at(0).size() ? vec.at(0).size() : vec2.at(0).size();
    if (!cols) exit(1);
    size_t colors = vec.at(0).at(0).size();
    if (!colors) exit(1);

	//For each row and column...
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
			//Copies all pixels over that aren't white (background color).
			if (vec2.at(i).at(j).at(RED) != 255 and vec2.at(i).at(j).at(GREEN) != 255 and vec2.at(i).at(j).at(BLUE) != 255) { 
				//This code composites vec2 on top of vec by averaging the pixel data together
				vec.at(i).at(j).at(RED) = vec2.at(i).at(j).at(RED);
				vec.at(i).at(j).at(GREEN) = vec2.at(i).at(j).at(GREEN);
				vec.at(i).at(j).at(BLUE) = vec2.at(i).at(j).at(BLUE);
			}
        }
    }
}
