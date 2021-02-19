#ifndef INSERTIONSORT_HPP_INCLUDED
#define INSERTIONSORT_HPP_INCLUDED

#include <vector>

template <typename T>
void insertionSort(std::vector<T>& a) {
  for (auto j = 1; j < a.size(); ++j) { // c1 * n
    auto key = a[j];                    // c2 * n-1
    auto i = j - 1;                     // c3 * n-1
    while (i >= 0 && a[i] > key) {      // c4 * SUM[j=1..n-1](tj), best case tj=1 for all j, worst case tj=j+1 for all j, average case tj=(j+1)/2]
      a[i + 1] = a[i];                  // c5 * SUM[j=1..n-1](tj-1)
      i = i - 1;                        // c6 * SUM[j=1..n-1](tj-1)
    }
    a[i + 1] = key;                     // c7 * n-1
  }
  // outside the loop, done!
}

// T(n) = c1*n + c2*(n-1) + c3*(n-1) + c4*SUM[j=1..n-1](tj) + c5*SUM[j=1..n-1](tj-1) + c6*SUM[j=1..n-1](tj-1) + c7*(n-1)

// Best case:
//      = c1*n + c2*(n-1) + c3*(n-1) + c4*SUM[j=1..n-1](1) + c5*0 + c6*0 + c7*(n-1)
//      = c1*n + c2*(n-1) + c3*(n-1) + c4*(n-1) + c5*0 + c6*0 + c7*(n-1)
//      = c1*n + c2*(n-1) + c3*(n-1) + c4*(n-1) + c7*(n-1)
//      = c1*n + c2*n - c2 + c3*n - c3 + c4*n - c4 + c7*n - c7
//      = c1*n + c2*n + c3*n + c4*n + c7*n - c2 - c3 - c4 - c7
//      = (c1+c2+c3+c4+c7)*n + (-c2 - c3 - c4 - c7)
//      = An + B
//      ~ Theta(n)

// Worst case:
//      = c1*n + c2*(n-1) + c3*(n-1) + c4*SUM[j=1..n-1](j+1) + c5*SUM[j=1..n-1](j) + c6*SUM[j=1..n-1](j) + c7*(n-1)
//      = c1*n + c2*(n-1) + c3*(n-1) + c4*(n*(n+1)/2 - 1) + c5*((n-1)*n/2) + c6*((n-1)*n/2) + c7*(n-1)
//      = c1*n + c2*n - c2 + c3*n - c3 + c4*((n^2+n)/2 - 1) + c5*((n^2-n)/2) + c6*((n^2-n)/2) + c7*n - c7
//      = c1*n + c2*n - c2 + c3*n - c3 + c4/2*n^2 + c4/2*n - c4 + c5/2*n^2 - c5/2*n + c6/2*n^2 - c6/2*n + c7*n - c7
//      = (c4/2 + c5/2 + c6/2)*n^2 + (c1 + c2 + c3 + c4/2 - c5/2 - c6/2 + c7)*n - (c2 + c3 + c4 + c7)
//      = (c4+c5+c6)/2*n^2 + (c1+c2+c3+(c4-c5-c6)/2+c7)*n + -(c2+c3+c4+c7)
//      = An^2 + Bn + C
//      ~ Theta(n^2)

// Average case:
//      = c1*n + c2*(n-1) + c3*(n-1) + c4*SUM[j=1..n-1]((j+1)/2) + c5*SUM[j=1..n-1](j/2) + c6*SUM[j=1..n-1](j/2) + c7*(n-1)
//      = c1*n + c2*(n-1) + c3*(n-1) + c4/2*(n*(n+1)/2 - 1) + c5/2*((n-1)*n/2) + c6/2*((n-1)*n/2) + c7*(n-1)
//      = c1*n + c2*n - c2 + c3*n - c3 + c4/2*((n^2+n)/2 - 1) + c5/2*((n^2-n)/2) + c6/2*((n^2-n)/2) + c7*n - c7
//      = c1*n + c2*n - c2 + c3*n - c3 + c4/4*n^2 + c4/4*n - c4/2 + c5/4*n^2 - c5/4*n + c6/4*n^2 - c6/4*n + c7*n - c7
//      = (c4/4 + c5/4 + c6/4)*n^2 + (c1 + c2 + c3 + c4/4 - c5/4 - c6/4 + c7)*n - (c2 + c3 + c4/2 + c7)
//      = (c4+c5+c6)/4*n^2 + (c1+c2+c3+(c4-c5-c6)/4+c7)*n + -(c2+c3+c4/2+c7)
//      = An^2 + Bn + C
//      ~ Theta(n^2)

#endif // INSERTIONSORT_HPP_INCLUDED