// Description: This function generates a list of random numbers and sorts the list using three different methods.
//          The amount of work for each of these methods is calculated in the code and written to an output file, to display
//          which of the methods requires the most/least amount of work.
// Filename: COMPARINGSORTS
// Names: Kierin Noreen & Carter Mooring
// Date: October 1, 2018
// Gonzaga University, CPSC 122, Dr. Yerion

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
using namespace std;

// description: This function creates a line of random numbers and stores it
// pre: the list must be declared
// post: the list is filled with random numbers
void createList(int list[]);

// description: This function copies numbers and stores them in new memory locations
// pre: list must be filled with values and selectionList, insertionList, and bubbleList have not been filled
// post: selectionList, insertionList, and bubbleList are all filled with the same valeus as list
void saveList(int list[], int selectionList[], int insertionList[], int bubbleList[]);

// description: This function sorts a list by moving the largest value to the end of the list
// pre: selectionList has been assigned values, sizeOfList has been assigned
//    a value, largestIndex has been assigned a vaule, and countOfSelectionWork has been assigned a value
// post: whole list is sorted from least to greatest
void selectionSort(int selectionList[], int sizeOfList, int largestIndex, int& countOfSelectionWork);

// description: This function searches for the largest value and returns the index of that number
// pre: selectionList must be filled with values, and sizeOfList and countOfSelectionWork hold values
// post: all the parameters are the same, however the index of the largest value is returned and countOfSelectionWork increased
int findIndexofLargest(int selectionList[], int sizeOfList, int& countOfSelectionWork);

// description: This function swaps two numbers
// pre: first and second must hold values and countOfSelectionWork holds a value
// post: first now has second's value and vice versa and countOfSelectionWork increases
void selectionSwap(int& first, int& second, int& countOfSelectionWork);

// description: This function swaps two numbers
// pre: first and second must hold values and countOfBubbleWork holds a value
// post: first now has second's value and vice versa and countOfBubbleWork increases
void bubbleSwap(int& first, int& second, int& countOfBubbWork);

// description: This function sorts the list by comparing first and second value and determining
//            if they need to be swapped, then interates further up the list to compare again.
// pre: insertionList has been assigned values, sizeOfList has been assigned,
//            a value, countOfInsertionWork has been assigned a value
// post: returns a sorted list from least to greatest value
void insertionSort(int insertionList[], int sizeOfList, int& countOfInsertionWork);

// description: This function sorts a list of numbers in ascending order
// pre: bubbleList is full of random values, sizeOfList holds a value, and countOfBubbleWork holds a value
// post: bubbleList is sorted in ascending order, sizeOfList is the same, and countOfBubbleWork increases
void bubbleSort(int bubbleList[], int sizeOfList, int& countOfBubbleWork);

// Description: This function opens an output file to print to
// Pre: The outfile is not opened
// Post: The outfile is opened and ready to be printed to
void openOutputFile(ofstream& outfile);

const int MAXSIZE = 6000;

main()
{
  int list[MAXSIZE];
  int selectionList[MAXSIZE];
  int insertionList[MAXSIZE];
  int bubbleList[MAXSIZE];
  int largestIndex = 0;
  int countOfSelectionWork = 0;
  int countOfInsertionWork = 0;
  int countOfBubbleWork = 0;

  ofstream outfile;

  int seed = time(0);
	srand(seed);

  openOutputFile(outfile);
  createList(list);
  saveList(list, selectionList, insertionList, bubbleList);

  outfile << "  Selection Sort" << endl << "_________________" << endl;
  for(int size = 100; size <= MAXSIZE; size += 100)
  {
    selectionSort(selectionList, size, largestIndex, countOfSelectionWork);
    outfile << setw(6) << size << "    ";
    outfile << countOfSelectionWork << endl;
    countOfSelectionWork = 0;
  }

  outfile << endl << "  Insertion Sort" << endl << "_________________" << endl;
  for(int size = 100; size <= MAXSIZE; size += 100)
  {
    insertionSort(insertionList, size, countOfInsertionWork);
    outfile << setw(6) << size << "    ";
    outfile << countOfInsertionWork << endl;
    countOfInsertionWork = 0;
  }

  outfile << endl << "   Bubble Sort" << endl << "_________________" << endl;
  for(int size = 100; size <= MAXSIZE; size += 100)
  {
    bubbleSort(bubbleList, size, countOfBubbleWork);
    outfile << setw(6) << size << "    ";
    outfile << countOfBubbleWork << endl;
    countOfBubbleWork = 0;
  }

  outfile.close();

  return 0;
}

// description: This function creates a line of random numbers and stores it
// pre: the list must be declared
// post: the list is filled with random numbers
void createList(int list[])
{
	for (int k = 0; k < MAXSIZE; k++)
	{
		list[k] = rand() % 4232;
	}
}

// description: This function copies numbers and stores them in new memory locations
// pre: list must be filled with values and selectionList, insertionList, and bubbleList have not been filled
// post: selectionList, insertionList, and bubbleList are all filled with the same valeus as list
void saveList(int list[], int selectionList[], int insertionList[], int bubbleList[])
{
  for (int k = 0; k < MAXSIZE; k++)
	{
    selectionList[k] = list[k];
    insertionList[k] = list[k];
    bubbleList[k] = list[k];
  }
}

// description: This function sorts a list by moving the largest value to the end of the list
// pre: selectionList has been assigned values, sizeOfList has been assigned
//    a value, largestIndex has been assigned a vaule, and countOfSelectionWork has been assigned a value
// post: whole list is sorted from least to greatest
void selectionSort(int selectionList[], int sizeOfList, int largestIndex, int& countOfSelectionWork)
{
    countOfSelectionWork += 2; // =, -
    countOfSelectionWork += 2; // >= (last time)
    for (int j = (sizeOfList - 1); j >= 1; j--)
    {
        countOfSelectionWork += 2; // =, -, >=
        largestIndex = findIndexofLargest(selectionList, j + 1, countOfSelectionWork); countOfSelectionWork += 2; // =, +
        selectionSwap(selectionList[largestIndex], selectionList[j], countOfSelectionWork);
        countOfSelectionWork += 2; //  -- (1A, 1D)
    }
}

// description: This function searches for the largest value and returns the index of that number
// pre: selectionList must be filled with values, and sizeOfList and countOfSelectionWork hold values
// post: all the parameters are the same, however the index of the largest value is returned and countOfSelectionWork increased
int findIndexofLargest(int selectionList[], int sizeOfList, int& countOfSelectionWork)
{
    int largestIndex = 0; countOfSelectionWork++; // =
    countOfSelectionWork += 1; // =
    countOfSelectionWork++; // < (last time)
    for (int k = 1; k < sizeOfList; k++)
    {
        countOfSelectionWork += 1; // <
        countOfSelectionWork += 5; // [k], >, [largestIndex]
        if (selectionList[k] > (selectionList[largestIndex]))
        {
            largestIndex = k; countOfSelectionWork += 1; // =
        }
        countOfSelectionWork += 2; // ++;
    }
    return largestIndex; countOfSelectionWork++; // return
}

// description: This function swaps two numbers
// pre: first and second must hold values and countOfSelectionWork holds a value
// post: first now has second's value and vice versa and countOfSelectionWork increases
void selectionSwap(int& first, int& second, int& countOfSelectionWork)
{
   int temp;

   temp = first; countOfSelectionWork++; // =
   first = second; countOfSelectionWork++; // =
   second = temp; countOfSelectionWork++; // =
}

// description: This function swaps two numbers
// pre: first and second must hold values and countOfBubbleWork holds a value
// post: first now has second's value and vice versa and countOfBubbleWork increases
void bubbleSwap(int& first, int& second, int& countOfBubbleWork)
{
   int temp;

   temp = first; countOfBubbleWork++; // =
   first = second; countOfBubbleWork++; // =
   second = temp; countOfBubbleWork++; // =
}

// description: This function sorts the list by comparing first and second value and determining
//            if they need to be swapped, then interates further up the list to compare again.
// pre: insertionList has been assigned values, sizeOfList has been assigned,
//            a value, countOfInsertionWork has been assigned a value
// post: returns a sorted list from least to greatest value
void insertionSort(int insertionList[], int sizeOfList, int& countOfInsertionWork)
{
    countOfInsertionWork++; // =
    countOfInsertionWork++; // < (last time)
    for (int j = 1; j < sizeOfList; j++)
    {
        countOfInsertionWork += 1; // <
        int nextItem = insertionList[j]; countOfInsertionWork += 3; //=, [](count as 2 work of addition(D) and multiplication(M)
        int k = j; countOfInsertionWork++; // =
        countOfInsertionWork++; // > (last time)
        while ((k > 0) && (insertionList[k - 1] > nextItem))
        {
          countOfInsertionWork += 6; // >, and, -, [](count as 2 work of addition(D) and multiplication(M), >
          insertionList[k] = insertionList[k - 1]; countOfInsertionWork += 6; //[](count as 2 work of addition(D) and multiplication(M),
                          // =, -, [](count as 2 work of addition(D) and multiplication(M)
          k--; countOfInsertionWork += 2; // -- (1A, 1D)
          insertionList[k] = nextItem; countOfInsertionWork += 3; // -, [](count as 2 work of addition(D) and multiplication(M), =
        }
        countOfInsertionWork += 2; //-- (1A, 1D)
    }
}

// description: This function sorts a list of numbers in ascending order
// pre: bubbleList is full of random values, sizeOfList holds a value, and countOfBubbleWork holds a value
// post: bubbleList is sorted in ascending order, sizeOfList is the same, and countOfBubbleWork increases
void bubbleSort(int bubbleList[], int sizeOfList, int& countOfBubbleWork)
{
  bool hasSwapped = false; countOfBubbleWork++; // =
  int pass = 1; countOfBubbleWork++; // =
  countOfBubbleWork += 3; // !, &&, < (last time)
  while (!hasSwapped && (pass < sizeOfList))
  {
    countOfBubbleWork += 3; // !, &&, <
    hasSwapped = true; countOfBubbleWork++; // =
    countOfBubbleWork ++; // = (i = 0)
    countOfBubbleWork += 2; //<, - (last time)
    for(int i = 0; i < (sizeOfList - pass); i++)
    {
      countOfBubbleWork += 2; // <, -
      countOfBubbleWork += 6; // [i], >, [i + 1], +
      if(bubbleList[i] > bubbleList[i + 1])
      {
        bubbleSwap(bubbleList[i], bubbleList[i + 1], countOfBubbleWork); countOfBubbleWork++; // +
        hasSwapped = false; countOfBubbleWork++; // =
      }
      countOfBubbleWork += 2; // ++
    }
    pass++; countOfBubbleWork += 2; // ++
  }
}

// Description: This function opens an output file to print to
// Pre: The outfile is not opened
// Post: The outfile is opened and ready to be printed to
void openOutputFile(ofstream& outfile)
{
  outfile.open("out.dat");
  if (outfile.fail())
  {
    cout << "Error opening file name out.dat" << endl;
    exit(1); // the only time this is allowed
  }
}
