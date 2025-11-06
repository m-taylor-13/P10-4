#include <iostream>
#include <string>
using namespace std;

//function prototype
bool isCardValid(int digits[], int size);

int main(void) {

	bool done = false;

	//int type used for input
	int cardNumber;

	while (!done) {
		cout << "\nEnter 8-digit credit card # or Q to quit: ";
		cin >> cardNumber;


		if (cin.fail()) {
			done = true;
		}
		else {

			//convert user input to array of ints

			string num = to_string(cardNumber);
			int arr[8];

			for (int i = 0; i <= 7; i++) {
				string digit = num.substr(i, 1);
				int d = stoi(digit);
				arr[i] = d;
			}

			if (isCardValid(arr, 7)) {
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