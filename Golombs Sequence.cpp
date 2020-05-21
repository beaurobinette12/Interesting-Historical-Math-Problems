/*Written 5/21/2020 by Beau Robinette for fun 
This program displays all the numbers of Golombs 
sequence up to the user specified index. (limited
to 1000)* The numbers are displayed in rows of 10*/

#include <iostream>
#include <iomanip>

//Function prototype to get input from a user, returns the last index
int get_input();

//Function prototype to fill in an array with Golombs sequence
void fill_array(int*, int);

//Function prototype to display the sequence 
void display(int*, int);

using namespace std;

int main() {

	//Declare relevant variables
	int last_index;
	int* sequence; 

	//Run on a loop until the user enters 0
	do {

		//Get the size from the user 
		last_index = get_input();

		//Allocate an array of that size
		sequence = new int[last_index];

		//Fill the array with Golombs sequence 
		fill_array(sequence, last_index);

		//Display the array 
		display(sequence, last_index);

		//Deallocate the array
		delete [] sequence;

	} while (last_index != 0);


}

//Function defintion to get input from user
int get_input() {

	//Declare relevant variables
	int last_index;
	bool valid_input = false;

	do {
		//Get input from user
		cout << "Enter the index you want to go up to, enter 0 to quit: ";
		cin >> last_index;

		//Error checking and size limitation
		if (cin.fail() || last_index < 0 || last_index > 1000) {
			cout << "Error invalid input\n";
			valid_input = false;
		}
		else {
			valid_input = true;
		}
	} while (!valid_input);

	return last_index;
}

//Function definition to create golombs sequence 
void fill_array(int* sequence, int size) {

	//Declare relevant variables
	int amount_of_numbers = 1, uninitialized_index = 0, ending_index = 0, total_numbers_placed = 0, index = 1;
	bool still_going = true;

	//Fill the array
	while(still_going) {

		//Find out how many integers are supposed to be in the sequence based on the index
		amount_of_numbers = index;

		//Find the starting position
		uninitialized_index = ending_index;

		//Put that amount of integers in the sequence starting at the current index 
		for (int count = 0; count < amount_of_numbers; count++) {
			sequence[uninitialized_index + count] = index; 
			ending_index = uninitialized_index + count + 1;
			total_numbers_placed += 1;

			//Check if we've run out of space
			if (total_numbers_placed == size) {
				still_going = false;
				break;
			}
		}

		//Increment the index 
		index += 1;
	}
}

//Function definition to display the sequence 
void display(int* sequence, int size) {

	//Index variable 
	int index = 0, counter = 0;

	//Nested for loop, displays the numbers 10 at a time
	for (int index = 0; index < size; index++) {

		//If ten numbers have been outputted start a new line
		if (counter == 9) {
			counter = 0;
			cout << endl;
		}

		//Display the current number 
		cout << left << setw(3) << sequence[index];
		counter += 1;

	}
	cout << endl;
}