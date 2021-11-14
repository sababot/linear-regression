#include "math.h"
#include <iostream>

using namespace std;

/*------------------- Variables -------------------*/
const char* FILENAME = "test.csv";
int MAX_ITERATION = 1000;
float LEARNING_RATE = 0.1;

/*-------------------- Weights --------------------*/
class Wieghts
{
private:
	int MAX_WEIGHTS;

public:
	float* values;
	int number_weights;

	Weights(){};

	Weights(int number_predictor)
	{
		number_weights = number_predictor;
		values = (float *) std::calloc(number_weights, sizeof(float));
	};

	void update(float **X, float *y, float *y_pred, float learning_rate, int length)
	{
		float multiplier = learning_rate/length;

		// Update each weight
		for (int i = 0; i < number_weights; i++)
		{
			float sum = (sum_residual(X, y, y_pred, i, length));
			printf("Sum = %f\n", sum);
			values[i] = values[i] - multiplier * sum;
		}
	}
}

int main()
{
	// Code
}
