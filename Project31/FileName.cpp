#include <iostream>
#include <string>
using namespace std;

//function prototypes
bool isCardValid(int digits[], int size);
bool isNumeric(string s);
bool isCorrectLength(string s);

int main(void) {
	//tests:
	//4010046804271206
	//4010-0468-0427-1206
	//43589795

	bool done = false;

	//string type used for input
	string cardNumber;

	while (!done) {
		cout << "\nEnter 8-digit credit card # or Q to quit: ";
		cin >> cardNumber;


		if (cin.fail()) {
			done = true;
		}
		else {

			//checks if input is valid
			if (!isNumeric(cardNumber)) {
				cout << "Error - card number must contain only digits.";
				continue;
			}
			else if (!isCorrectLength(cardNumber)) {
				cout << "Error - card number must contain 16 digits.";
				continue;
			}


			//convert user input to array of ints

			int arr[16];

			for (int i = 0; i <= 15; i++) {
				string digit = cardNumber.substr(i, 1);
				int d = stoi(digit);
				arr[i] = d;
			}

			if (isCardValid(arr, 15)) {
				cout << "Card is valid";
			}
			else {
				cout << "Card is not valid.";
			}
		}

	}
	
	return 0;
}



bool isCardValid(int digits[], int size) {

	// Starting from the rightmost digit, form the sum of every other digit

	int sum = 0;
	for (int i = size; i >= 0; i -= 2) {
		sum += digits[i];
	}

	// Double each of the digits that were not included in the preceding step. 
	// get the sum of the leftover digits
	

	int sumOfDoubled = 0;

	for (int i = size-1; i >= 0; i -= 2) {
		
		int doubled = digits[i] * 2;

		//adds one place digit
		sumOfDoubled += doubled % 10;

		if (doubled > 9) {
			//adds 10s place digit
			sumOfDoubled += (doubled / 10) % 100;
		}

	}


	// Add the sums of the two preceding steps. 
	// If the last digit of the result is 0, the number is valid

	if ((sum + sumOfDoubled) % 10 == 0) {
		return true;
	}
	return false;
}

bool isNumeric(string s) {

	bool isNumeric = true;

	for (int i = 0; i < s.length(); i++) {
		if (tolower(s[i]) < 48 || tolower(s[i]) > 57) {
			isNumeric = false;
		}
	}

	return isNumeric;
}

bool isCorrectLength(string s) {

	if (s.length() == 16) { return true; }
	else { return false; }

}