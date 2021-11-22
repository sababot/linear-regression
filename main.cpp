#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool custom_sort(double a, double b) /* this custom sort function sorts based on the minimum absolute value */
{
    double a1=abs(a-0);
    double b1=abs(b-0);
    return a1<b1;
}

int main()
{
	/*------------------- Variables -------------------*/
	double x[] = {1, 2, 3, 4, 5};
	double y[] = {1, 3, 3, 2, 5};

	vector<double> error; // store error values
	double devi; // calculate error on each stage (short for deviation
	double b0 = 0;
	double b1 = 0;
	double learningRate = 0.01;

	/*--------------------- Train ---------------------*/
	for (int i = 0; i < 20; i++) // there are 4 epochs and 5 values so 5 * 4 = 20
	{
		int index = i % 5; // access index after each epoch
		double p = b0 + b1 * x[index]; // calculate prediction
		devi = p - y[index]; // calculate error
		b0 = b0 - learningRate * devi; // update b0
		b1 = b1 - learningRate * devi * x[index]; // update b1
		cout << "B0 = " << b0 << " " << "B1 = " << b1 << " " << "error = " << devi << endl; // print values
		error.push_back(devi); // store error values
	}
	
	/*--------------------- Print ---------------------*/
	sort(error.begin(),error.end(),custom_sort); // error values used to sort the data
	cout<<"Optimal end values are: "<<"B0="<<b0<<" "<<"B1="<<b1<<" "<<"error="<<error[0]<<endl;

	/*-------------------- Testing --------------------*/
	cout<<"Enter a test x value: ";
	double test;
	cin>>test;
	double pred=b0+b1*test;
	cout<<endl;
	cout<<"\nThe value predicted by the model = "<< pred << endl;
}
