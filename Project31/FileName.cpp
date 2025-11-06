#include <iostream>
#include <string>
using namespace std;

int main(void) {

	int cardNumber;
	cout << "Please enter 8-digit credit card number: ";
	cin >> cardNumber;

	int digits[8];

	int digit;
	int counter = 0;
	while (cardNumber > 0) {
		digit = cardNumber % 10;
		cardNumber /= 10;
		digits[counter] = digit;
		counter++;
	}

	int sumOfDigits = 0;
	for (int i = 0; i <= 7; i += 2) {
		sumOfDigits += digits[i];
	}



	int sumOfDoubled = 0;
	int numOne;
	int numTwo;


	for (int i = 1; i <= 7; i += 2) {

		digits[i] *= 2;

		string number = to_string(digits[i]);
		string digitOne = number.substr(0, 1);

		numOne = stoi(digitOne);



		sumOfDoubled += numOne;
	
	}

	for (int i = 1; i <= 5; i += 2) {
	


		string number = to_string(digits[i]);

		string digitTwo = number.substr(1, 2);

		numTwo = stoi(digitTwo);


		sumOfDoubled += numTwo;
		

	}
	

	if ((sumOfDoubled + sumOfDigits) % 10 == 0) {
		cout << "Card is valid.";
	}
	else {
		cout << "Card is not valid.";
	}
}