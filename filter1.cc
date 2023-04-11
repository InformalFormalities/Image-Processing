//By: Declan Doss
#include <vector>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;

const int RED = 0, GREEN = 1, BLUE = 2;

void filter1(vector<vector<vector<int>>> &vec) {
	//Get the number of rows, columns, and colors in this 3D vector
	size_t rows = vec.size();
	if (!rows) exit(1);
	size_t cols = vec.at(0).size();
	if (!cols) exit(1);
	size_t colors = vec.at(0).at(0).size();
	if (!colors) exit(1);

	//Initialize redVal, greenVal, and blueVal to hold RGB values respectively. The gradient percents affects what color the sun and lines on the bottom are.
	int redVal = 0;
	int greenVal = 0;
	int blueVal = 0;
	double sunRedGradientPercent = 1, sunCyanGradientPercent = 0;
	double redGradientPercent = 1, cyanGradientPercent = 0;

	//RGB OF COLORS USED:
	//		Soft blue: 200, 235, 250
	//		Cyan: 100, 238, 255
	//		Red: Default red. Amplified at times to make it more showy.

	//Cycle through the image one row and all columns at a time.
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			//Assign RGB values accordingly.
			redVal = vec.at(i).at(j).at(RED);
			greenVal = vec.at(i).at(j).at(GREEN);
			blueVal = vec.at(i).at(j).at(BLUE);

			//Makes sun split down the middle into red and cyan, gradiented. Uses 4 boxes to accomplish this.
			//Top box.
			if (j < 790) {
				//Left side.
				if (i > 1198 and i <= 2000) {
					//If the color is close to red, gradient it.
					if (redVal > 120 and greenVal < 115 and blueVal < 115) {
						//Amplify red color first...
						vec.at(i).at(j).at(RED) *= 1.45;
						vec.at(i).at(j).at(GREEN) *= 1.45;
						vec.at(i).at(j).at(BLUE) *= 1.45;
						//...and then gradient it.
						vec.at(i).at(j).at(RED) *= sunRedGradientPercent;
						vec.at(i).at(j).at(GREEN) *= sunRedGradientPercent;
						vec.at(i).at(j).at(BLUE) *= sunRedGradientPercent;
					}
					//Else if the difference between the RGB values is greater or equal to 10, also gradient it. In English, this means if the color is more red than not.
					else if ((redVal - blueVal >= 10) and (redVal - greenVal >= 10) and (blueVal - greenVal >= 10)) {
						//Amplify red color first...
						vec.at(i).at(j).at(RED) *= 1.45;
						vec.at(i).at(j).at(GREEN) *= 1.45;
						vec.at(i).at(j).at(BLUE) *= 1.45;
						//...and then gradient it.
						vec.at(i).at(j).at(RED) *= sunRedGradientPercent;
						vec.at(i).at(j).at(GREEN) *= sunRedGradientPercent;
						vec.at(i).at(j).at(BLUE) *= sunRedGradientPercent;
					}
				}
				//Right side.
				else if (i > 2000 and i < 2800) {
					//If the color is close to red, make the pixel icy blue and gradient it.
					if (redVal > 120 and greenVal < 115 and blueVal < 115) {
						vec.at(i).at(j).at(RED) = 100 * sunCyanGradientPercent;
						vec.at(i).at(j).at(GREEN) = 238 * sunCyanGradientPercent;
						vec.at(i).at(j).at(BLUE) = 255 * sunCyanGradientPercent;
					}
					//Else if the difference between the RGB values is greater or equal to 10, also make the pixel icy blue and gradient it. In English, this means if the color is more red than not.
					else if ((redVal - blueVal >= 10) and (redVal - greenVal >= 10) and (blueVal - greenVal >= 10)) {
						vec.at(i).at(j).at(RED) = 100 * sunCyanGradientPercent;
						vec.at(i).at(j).at(GREEN) = 238 * sunCyanGradientPercent;
						vec.at(i).at(j).at(BLUE) = 255 * sunCyanGradientPercent;
					}	
				}
			}
			//Bounds check #2. From row 790 to the bottom of sun.
			//Bottom box.
			else if (j < 945) {
				//Left side.
				if (i > 1515 and i <= 2000) {
					//If the color is close to red, gradient it.
					if (redVal > 120 and greenVal < 115 and blueVal < 115) {
						//Amplify red color first...
						vec.at(i).at(j).at(RED) *= 1.45;
						vec.at(i).at(j).at(GREEN) *= 1.45;
						vec.at(i).at(j).at(BLUE) *= 1.45;
						//...and then gradient it.
						vec.at(i).at(j).at(RED) *= sunRedGradientPercent;
						vec.at(i).at(j).at(GREEN) *= sunRedGradientPercent;
						vec.at(i).at(j).at(BLUE) *= sunRedGradientPercent;
					}
					//Else if the difference between the RGB values is greater or equal to 10, also gradient it. In English, this means if the color is more red than not.
					else if ((redVal - blueVal >= 10) and (redVal - greenVal >= 10) and (blueVal - greenVal >= 10)) {
						//Amplify red color first...
						vec.at(i).at(j).at(RED) *= 1.45;
						vec.at(i).at(j).at(GREEN) *= 1.45;
						vec.at(i).at(j).at(BLUE) *= 1.45;
						//...and thne gradient it.
						vec.at(i).at(j).at(RED) *= sunRedGradientPercent;
						vec.at(i).at(j).at(GREEN) *= sunRedGradientPercent;
						vec.at(i).at(j).at(BLUE) *= sunRedGradientPercent;
					}
				}
				//Right side.
				else if (i > 2000 and i < 2800) {
					//If the color is close to red, make the pixel icy blue and gradient it.
					if (redVal > 120 and greenVal < 115 and blueVal < 115) {
						vec.at(i).at(j).at(RED) = 100 * sunCyanGradientPercent;
						vec.at(i).at(j).at(GREEN) = 238 * sunCyanGradientPercent;
						vec.at(i).at(j).at(BLUE) = 255 * sunCyanGradientPercent;
					}
					//Else if the difference between the RGB values is greater or equal to 10, also make the pixel icy blue and gradient it. In English, this means if the color is more red than not.
					else if ((redVal - blueVal >= 10) and (redVal - greenVal >= 10) and (blueVal - greenVal >= 10)) {
						vec.at(i).at(j).at(RED) = 100 * sunCyanGradientPercent;
						vec.at(i).at(j).at(GREEN) = 238 * sunCyanGradientPercent;
						vec.at(i).at(j).at(BLUE) = 255 * sunCyanGradientPercent;
					}
				}
			}
/*			//Turns the sun icy blue.
			//NOTE: Two bounds checks are requied as one of the birds that would otherwise be in-bounds of a fully encompassing square, is just barely within the color range to be turned partially icy blue.
			//Bounds check #1. From the top of sun to row 790.
			if ((i > 1193 and i < 2800) and (j < 790)) {
				//If the color is close to red, make the pixel icy blue.
				if (redVal > 120 and greenVal < 115 and blueVal < 115) {
					vec.at(i).at(j).at(RED) = 200;
					vec.at(i).at(j).at(GREEN) = 233;
					vec.at(i).at(j).at(BLUE) = 250;
				}
				//Else if the difference between the RGB values is greater or equal to 10, also make the pixel icy blue. In English, this means if the color is more red than not.
				else if ((redVal - blueVal >= 10) and (redVal - greenVal >= 10) and (blueVal - greenVal >= 10)) {
					vec.at(i).at(j).at(RED) = 200;
					vec.at(i).at(j).at(GREEN) = 233;
					vec.at(i).at(j).at(BLUE) = 250;
				}
			}
			//Bounds check #2. From row 790 to the bottom of sun.
			else if ((i > 1515 and i < 2480) and (j < 945)) {
				//If the color is close to red, make the pixel icy blue.
				if (redVal > 120 and greenVal < 115 and blueVal < 115) {
					vec.at(i).at(j).at(RED) = 200;
					vec.at(i).at(j).at(GREEN) = 233;
					vec.at(i).at(j).at(BLUE) = 250;
				}
				//Else if the difference between the RGB values is greater or equal to 10, also make the pixel icy blue. In English, this means if the color is more red than not.
				else if ((redVal - blueVal >= 10) and (redVal - greenVal >= 10) and (blueVal - greenVal >= 10)) {
					vec.at(i).at(j).at(RED) = 200;
					vec.at(i).at(j).at(GREEN) = 233;
					vec.at(i).at(j).at(BLUE) = 250;
				}
			} */
			//Bounds check for bottom part of screen where the red lines on the ground are.
			else { 
				//Gradients red from left to right, starting at beginning of screen and stopping at middle of screen.
				if ((i <= 2000) and (redVal - blueVal >= 30) and (redVal - greenVal >= 30)) {
					//Increases the red color so looks similar to the hue of cyan's.
					vec.at(i).at(j).at(RED) *= 1.48;
					vec.at(i).at(j).at(GREEN) *= 1.48;
					vec.at(i).at(j).at(BLUE) *= 1.48;

					//Reduce red color by the gradient percentage.
					vec.at(i).at(j).at(RED) *= redGradientPercent;
					vec.at(i).at(j).at(GREEN) *= redGradientPercent;
					vec.at(i).at(j).at(BLUE) *= redGradientPercent;
				}
				//Gradients cyan from left to right, starting at middle of screen to end of screen.
				//The last two conditional statements (making of box using i and j) prevents the swords from being colored in.
				else if ((i > 2000) and (redVal - blueVal >= 30) and (redVal - greenVal >= 30)) {
					//These if statements prevent three of the swords from being colored a bit blue.
					//Right side sword.
					if ((j >= 2000 and j <= 2044) and (i >= 3595 and i <= 3641)) continue;
					if ((j >= 1942 and j <= 2011) and (i >= 3615 and i <= 3645)) continue;
					if ((j >= 2043 and j <= 2053) and (i >= 3614 and i <= 3624)) continue;
					//Left side sword.
					if ((j >= 1952 and j <= 1998) and (i >= 3134 and i <= 3151)) continue;
					if ((j >= 1999 and j <= 2021) and (i >= 3136 and i <= 3154)) continue;
					if ((j >= 2022 and j <= 2075) and (i >= 3139 and i <= 3162)) continue;
					if ((j >= 2068 and j <= 2075) and (i >= 3163 and i <= 3165)) continue;
					//Lefter side sword.
					if ((j >= 1855 and j <= 2002) and (i >= 2653 and i <= 2678)) continue;

					//Reduce the cyan color by the gradient percentage.
					vec.at(i).at(j).at(RED) = 100 * cyanGradientPercent;
					vec.at(i).at(j).at(GREEN) = 238 * cyanGradientPercent;
					vec.at(i).at(j).at(BLUE) = 255 * cyanGradientPercent;
				}
			}
		}
		//Update the gradient percentages by very slight amounts in order to allow the gradient to work across the whole image correctly.
		if (i >= 1198 and i < 2000) sunRedGradientPercent -= 0.0012;
		if (i > 2000 and i <= 2800) sunCyanGradientPercent += 0.0013;
		if (i < 2000) redGradientPercent -= 0.00048;
		if (i > 2000) cyanGradientPercent += 0.00048;
	}
}
