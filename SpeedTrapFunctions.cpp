#include <iostream> 
#include <cstdlib> 
#include <ctime>
#include <iomanip>

using namespace std;

int main() {

	int speedLimit;
	int driverSpeed;
	double fine;
	char x;
	srand((unsigned)time(0));

	while (1) {
		speedLimit = (25 + rand() % 40);
		cout << "The speed limit is : " << speedLimit << endl;

		driverSpeed = getDriverSpeed();

		fine = calculateFine(driverSpeed, speedLimit);

		cout << "The speed limit is : " << speedLimit << endl;
		cout << "The driver's speed was : " << driverSpeed << endl;
		cout << "The speeding fine is : $";
		std::cout << std::fixed << std::setprecision(2) << fine << endl;

		cout << "\nDo want more calculation of speed violation fine : Enter y ";
		cin >> x;
		if (x == 'y' || x == 'Y')
		{
			continue;
		}
		else
		{
			break;
		}
	}

	return 0;

}

int getDriverSpeed() {
	int driverSpeed;
	cout << "Enter the driver's speed: ";
	cin >> driverSpeed;

	return driverSpeed;
}

double calculateFine(int driverSpeed, int speedLimit) {
	const double rate = 60.25;
	double fine;

	if (driverSpeed <= speedLimit) {
		fine = 0.0;
	}

	else if (driverSpeed <= (speedLimit + 5)) {
		fine = rate;
	}

	else if (driverSpeed <= (speedLimit + 10)) {
		fine = rate + rate * 0.05;
	}

	else if (driverSpeed < (speedLimit + 20)) {
		fine = rate + rate * 0.10;
	}

	else if (driverSpeed >= (speedLimit + 20)) {
		fine = rate + rate * 0.20;
	}
	return fine;
}

