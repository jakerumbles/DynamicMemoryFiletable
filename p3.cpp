/******************
Jake Edwards
CSC 331-001
Dr. Ivancic
October 11th, 2017
Homework 3
******************/

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

//Implement the functions up here.
void addFile(char *filetable[], int SIZE) {

	bool isFull = false;
	int lastAvaliable;
	int i;
	for(i = 0; i < SIZE; ) {
		if(filetable[i] != NULL) { // has an item
			i++;
		}
		else {
			lastAvaliable = i;
			break;
		}
	} // end for

	if(i == 10) {
		isFull = true;
	}

	if(isFull) {
		cout << "The array is full, cannot add string." << endl;
	}
	else { // array is not full
		// prompt user for string to store
		cout << "Enter a string fewer than 100 characters." << endl;
		char *stringptr = new char[100];
		cin.ignore(); // something about ignoring a new line character idk
		cin.getline(stringptr, 100);
		filetable[lastAvaliable] = stringptr;
	}



}

void removeFile(char *filetable[], int SIZE) {

	cout << "Which location(index) do you want to free?" << endl;
	int index;
	cin >> index;

	if(index >= 0 && index < SIZE) { // user index choice is within bounds
		if(filetable[index] != NULL) { // contains an item
			delete filetable[index];
			filetable[index] = NULL;
		}
		else { // is empty
			cout << "Location is already empty..." << endl;
		}
	}
}

void printTableContents(char *filetable[], int SIZE) {
	cout << "{";
	for (int i = 0; i < SIZE; i++) {
		cout << i << ":";

		if (filetable[i] == NULL) { // filetable[i] is a null pointer meaning it is free
			if(i < 9) {
				cout << "FREE, ";
			}
			else { // just for not having a comma and a space on the last item
				cout << "FREE";
			}
		}
		else { // filetable[i] holds a non-null value
			if(i < 9) {
				cout << filetable[i] << ", ";
			}
			else {
				cout << filetable[i];
			}
		}
	} // end for
	cout << "}" << endl;
} // end printTableContents

int main(int argc, char **argv)
{
	const int SIZE = 10;
	char *filetable[SIZE];

	for (int i = 0; i < SIZE; i++)
		filetable[i] = NULL;
	cout << "Table created" << endl << endl;
	bool loop = true;
	char choice;
	do
	{
		cout << "-------------------------\n";
		cout << "(A)dd to the table.\n";
		cout << "(R)emove from the table.\n";
		cout << "(D)isplay contents of memory.\n";
		cout << "(E)xit program.\n";
		cout << "Enter choice: ";
		cin >> choice;

		switch (choice)
		{
		case 'A':
		case 'a':
			//TODO: Implement this function call
			addFile(filetable, SIZE);
			break;
		case 'R':
		case 'r':
			//TODO: Implement this function call
			removeFile(filetable, SIZE);
			break;
		case 'D':
		case 'd':
			//TODO: Implement this function call
			printTableContents(filetable, SIZE);
			break;
		case 'E':
		case 'e':
		default:
			loop = false;
			break;
		}
	} while (loop == true);

	return 0;
}
