// Triangle Area
#include <stdio.h>

int main()
{
	double base, height;
	double area;
	
	// user input
	printf("Input the base of the triangle: ");
	scanf_s("%lf", &base);
	
	printf("Input the height of the triangle: ");
	scanf_s("%lf", &height);

	// calculate area
	area = 0.5 * base * height;

	// output
	printf("The area of the triangle is: %lf\n", area);
	return 0;
}