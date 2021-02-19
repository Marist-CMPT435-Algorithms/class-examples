#ifndef BUBBLESORT_HPP_INCLUDED
#define BUBBLESORT_HPP_INCLUDED

#include <vector>

template <typename T>
void bubbleSort(std::vector<T>& a)
{
  for (auto i = 0; i < a.size() - 1; ++i)       // c1 * n
    for (auto j = a.size() - 1; j > i; --j)     // c2 * SUM[i=0..n-2](n-i)
      if (a[j] < a[j - 1])                      // c3 * SUM[i=0..n-2](n-i-1)
        std::swap(a[j], a[j - 1]);              // c4 * SUM[i=0..n-2](SUM[j=n-1..i+1](tij)), where tij = 0 or 1
}

// Analysis
//
// Best case: tij = 0 for all i,j
//  T(n) = c1*n + c2*(1/2)(n^2 - n - 2) + c3*(1/2)(n^2 - 3n + 2)
//       = c1*n + (c2/2)*n^2 - (c2/2)*n - c2 + (c3/2)*n^2 - 3*(c3/2)*n + c3
//       = (c2/2+c3/2)*n^2 + (c1-c2/2-3c3/2)*n + (c3-c2)
//       = An^2 + Bn + C
//       =~ Theta(n^2)
//
// Average case: tij = 1 for about half of i,j
//  T(n) = c1*n + c2*(1/2)(n^2 - n - 2) + (c3+c4/2)*(1/2)(n^2 - 3n + 2)
//       = c1*n + (c2/2)*n^2 - (c2/2)*n - c2 + (c3/2+c4/4)*n^2 - 3*(c3/2+c4/4)*n + (c3 + c4/2)
//       = (c2/2+c3/2+c4/4)*n^2 + (c1-c2/2-3c3/2-3c4/4)*n + (c3+c4/2-c2)
//       = An^2 + Bn + C
//       =~ Theta(n^2)
// 
// Worst case: tij = 1 for all i,j
//  T(n) = c1*n + c2*(1/2)(n^2 - n - 2) + (c3+c4)*(1/2)(n^2 - 3n + 2)
//       = c1*n + (c2/2)*n^2 - (c2/2)*n - c2 + (c3/2+c4/2)*n^2 - 3*(c3/2+c4/2)*n + (c3 + c4)
//       = (c2/2+c3/2+c4/2)*n^2 + (c1-c2/2-3c3/2-3c4/2)*n + (c3+c4-c2)
//       = An^2 + Bn + C
//       =~ Theta(n^2)

// Remember that...
// SUM[i=1 to k](1) = k
// SUM[i=1 to k](k) = k(k+1)/2
// so...
// SUM[i=0 to n-2](n-i) = n + n-1 + n-2 + ... + 2 = n(n-1)/2 - 1 = (1/2)(n^2 - n - 2)
// SUM[i=0 to n-2](n-i-1) = n-1 + n-2 + ... + 1 = (n-1)(n-2)/2 = (1/2)(n^2 - 3n + 2)

#endif // BUBBLESORT_HPP_INCLUDED


