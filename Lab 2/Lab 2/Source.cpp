//Charlie Ang
//01/16/16
//CSC 2430
//Prof. Tindall
//Lab #2
//This program inputs and stores in a set of data values representing
//quiz scores and the number of students that received each score.
//It then outputs a report in a table and bar charts.

#include <iostream>
#include <iomanip>

using namespace std;

//Function prototypes
int lowestQuizScore(int a[]);
int highesstQuizScore(int a[]);
int largestFrequency(int a[]);
void tableOutput(int a[], int low, int high, int freq);
void verticalBarChart(int a[], int low, int high, int freq);
void horizontalBarChart(int a[], int low, int high, int freq);

const int MAX = 51;			//0 - 50 for 51 possible quiz score values
const int SENTINEL = -1;	//denotes end of data set 

int main()
{
	system("cls");	//clears extraneous texts

	cout << "Welcome to the Quiz Score Frequency Analyzer, by Charlie Ang" << endl;
	cout << " " << endl;	//spacing
	cout << "Enter a list of pairs of values: \"QuizScoreValue ScoreCount\". " << endl;
	cout << "Example: 35 5 indicates 5 more students received a score of 35." << endl;
	cout << "Enter \"-1 0 \" when finsihed: " << endl;

	int myArray[MAX];	//initialize array to the number of elements 

	for (int i = 0; i < MAX; i++)
	{
		myArray[i] = 0;	//initialize all elements in the array to 0 (frequency count for scores)
	}
	
	int quizScore;
	int frequency;
	cin >> quizScore >> frequency;	//reads in quiz score and reads in frequency associated with quiz score
	while (quizScore != SENTINEL)	//while quizScore does not equal -1
	{
		myArray[quizScore] += frequency;	//adds frequency to associated quiz score 
		cin >> quizScore >> frequency;
	}

	int lowestScore = lowestQuizScore(myArray);	//returns the lowest quiz score
	int highestScore = highesstQuizScore(myArray);	//returns highest quiz score
	int largestFrequencyCount = largestFrequency(myArray);	//returns largest frequency count

	cout << " " << endl;	//spacing

	//calls function to output values in table format and also output the lowest score, highest score, and largest frequency count
	tableOutput(myArray, lowestScore, highestScore, largestFrequencyCount);	

	cout << " " << endl;	//spacing

	//calls function to output a vetical bar chart
	verticalBarChart(myArray, lowestScore, highestScore, largestFrequencyCount);

	cout << " " << endl;	//spacing

	//calls function to output horizotal bar chart
	horizontalBarChart(myArray, lowestScore, highestScore, largestFrequencyCount);
}

//This function takes in an array of integers as a parameter. It then finds and returns
//the lowest quiz score (first element in array that is not equal to 0.
int lowestQuizScore(int a[])
{
	int i = 0;
	int freq = a[i];
	while (freq == 0)	//stops when it finds first quiz score with a value in it
	{
		i++;	//increment through the array
		freq = a[i];	
	}
	return i;
}

//This function takes in an array of integers as a parameter. It then finds and returns
//the highest quiz score (first element in array starting from the end and decrementing
//until it finds a quiz score that has a value in it).
int highesstQuizScore(int a[])
{
	int i = MAX - 1;	//start at end of array
	int freq = a[i];
	while (freq == 0)
	{
		i--;	//decrements through array 
		freq = a[i];
	}
	return i;
}

//This function takes in an array of integers as a parameter. It then iterates and 
//returns the largest frequency count.
int largestFrequency(int a[])
{
	int max = 0;
	for (int i = 0; i < MAX; i++)
	{
		int num = a[i];
		if (num >= max)
		{
			max = num;
		}
	}
	return max;
}

//This function takes in an array of integers, an integer for the lowest score, an integer for the highest
//score, and an integer for the largest frequency. It then outputs the values in a table format and also
//outputs the 3 values. 
void tableOutput(int a[], int low, int high, int freq)
{
	cout << "Score: Frequency" << endl;
	for (int i = low; i <= high; i++)
	{
		cout << "   " << i << ":	  " << a[i] << endl;	//print out array values in table format
	}

	cout << " " << endl;	//spacing

	cout << "The smallest score value is " << low << endl;
	cout << "The largest score value is " << high << endl;
	cout << "The largest frequency count is " << freq << endl;
}

//This function takes in an array of integers, an integer for the lowest score, an integer for the highest
//score, and an integer for the largest frequency. It then outputs a readable bar chart graph in a vertical 
//arrangement down the page from the lowest score to the highest score.
void verticalBarChart(int a[], int low, int high, int freq)
{
	cout << "Score: Frequency Vertical Bar Chart" << endl;
	cout << " " << endl;	//spacing
	for (int i = low; i <= high; i++)	//for quiz score values
	{
		cout << "   " << i << ": ";
		for (int j = 0; j < a[i]; j++)	//for frequency count 
		{
			cout << "*";
		}
		cout << endl;
	}
}

//This function takes in an array of integers, an integer for the lowest score, an integer for the highest
//score, and an integer for the largest frequency. It then outputs a readable bar chart graph in a horizontal  
//arrangement where the quiz score values appear across the page and the asterisks are displayed vertically.
void horizontalBarChart(int a[], int low, int high, int freq)
{
	cout << "Frequency: Score Horizontal Bar Chart" << endl;
	cout << " " << endl;	//spacing 

	for (int i = freq; i >= 1; i--)	//frequency starting from high to low
	{
		cout << fixed << showpoint;
		cout << "    " << "^" << setw(4) << i << ": ";
		for (int j = low; j <= high; j++)
		{
			if (i <= a[j])
			{
				cout << "  *";	//two spaces plus asterisk
			}
			else
			{
				cout << "   ";	//three spaces per number
			}
		}
		cout << endl;
	}

	cout << "---------: ";	//prints axis
	for (int i = 0; i < ((high - low) + 1); i++)
	{
		cout << "--^";
	}
	cout << endl;

	cout << "    Score:" << "  ";	//prints score numbers for axis
	for (int i = low; i <= high; i++)
	{
		cout << i << " ";
	}
	cout << endl;
}