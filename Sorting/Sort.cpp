#include <algorithm> // for copy() function
#include <iostream> // for cin and cout objects
#include <iterator> // for istream_ and ostream_ iterator classes
#include <set> // for set class
#include <vector> // for vector class

#include "InsertionSort.hpp"
#include "BubbleSort.hpp"
#include "MergeSort.hpp"

using namespace std;

int main() {
  set<string> choices{ "b", "i", "m" };

  // Read the choice of sort algorithm from console (standard input)
  string algoChoice;
  while (choices.find(algoChoice) == end(choices)) {
    cerr << "Choose a sort algorithm. Enter B for Bubblesort, I for "
      "InsertionSort, or M for MergeSort: ";
    cin >> algoChoice;
    transform(begin(algoChoice), end(algoChoice), begin(algoChoice), ::tolower);
  }

  // Read input array size
  cerr << "Enter the array size, N: ";

  int n;
  cin >> n;

  // Read input array
  cerr << "Enter the array elements, space-separated: ";

  vector<int> data;
  copy_n(istream_iterator<int>(cin), n, back_inserter(data));

  // Sort the array!
  if (algoChoice == "i")
    insertionSort(data);
  else if (algoChoice == "b")
    bubbleSort(data);
  else if (algoChoice == "m")
    mergeSort(data);

  // Print output array to console (standard out)
  copy(begin(data), end(data), ostream_iterator<int>(cout, " "));

  return 0;
}