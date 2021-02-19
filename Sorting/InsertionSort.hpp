#ifndef INSERTIONSORT_HPP_INCLUDED
#define INSERTIONSORT_HPP_INCLUDED

#include <vector>

template <typename T>
void insertionSort(std::vector<T>& a) {
  for (auto j = 1; j < a.size(); ++j) {  // c1    n
    auto key = a[j];               // c2    n-1
    auto i = j - 1;                // c3    n-1
    while (i >= 0 && a[i] > key) { // c4    SUM_j=1_to_n-1(tj) [ best case tj=1 for all j, worst case tj=j+1 for all j, average case tj=(j+1)/2]
      a[i + 1] = a[i];        // c5   SUM_j=1_to_n-1(tj-1)
      i = i - 1;              // c6   SUM_j=1_to_n-1(tj-1)
    }
    a[i + 1] = key;           // c7   n-1
  }
  // outside the loop, done!
}

// T(n) = c1*n + c2*(n-1) + c3*(n-1) + c4*SUM_j=1_to_n-1(tj) + c5*SUM_j=1_to_n-1(tj-1) + c6*SUM_j=1_to_n-1(tj-1) + c7*(n-1)

// Best case
//      = c1*n + c2*(n-1) + c3*(n-1) + c4*(n-1) + c5*0 + c6*0 + c7*(n-1)
//      = c1*n + c2*(n-1) + c3*(n-1) + c4*(n-1) + c7*(n-1)
//      = c1*n + c2*n - c2 + c3*n - c3 + c4*n - c4 + c7*n - c7
//      = c1*n + c2*n + c3*n + c4*n + c7*n - c2 - c3 - c4 - c7
//      = (c1+c2+c3+c4+c7)*n + (-c2 - c3 - c4 - c7)
//      = An + B

// Worst case
//      = c1*n + c2*(n-1) + c3*(n-1) + c4*(n-1) + c5*0 + c6*0 + c7*(n-1)

#endif // INSERTIONSORT_HPP_INCLUDED