#ifndef MERGESORT_HPP_INCLUDED
#define MERGESORT_HPP_INCLUDED

#include <limits>

#include <algorithm>
#include <iterator>
#include <iostream>

/* Forward declarations of auxiliary functions. */

template <typename T>
void merge(std::vector<T>&, std::size_t, std::size_t, std::size_t);

template <typename T>
void mergeSort(std::vector<T>&, std::size_t, std::size_t);

/* Primary sorting function. */

template <typename T>
void mergeSort(std::vector<T>& A) { mergeSort(A, 0, A.size()); }

/* Definitions of auxiliary functions. */

template <typename T>
void mergeSort(std::vector<T>& A, std::size_t p, std::size_t r) {
  if (r - p > 1) {
    std::size_t q = (p + r) / 2;
    mergeSort(A, p, q);
    mergeSort(A, q, r);
    merge(A, p, q, r);
  }
}

template <typename T>
void merge(std::vector<T>& A, std::size_t p, std::size_t q, std::size_t r) {
  auto n1 = q - p;
  auto n2 = r - q;
  auto L = new T[n1 + 1], R = new T[n2 + 1];
  for (auto i = 0; i < n1; ++i)
    L[i] = A[p + i];
  for (auto j = 0; j < n2; ++j)
    R[j] = A[q + j];
  L[n1] = std::numeric_limits<T>::max();
  R[n2] = std::numeric_limits<T>::max();
  auto i = 0;
  auto j = 0;
  for (auto k = p; k < r; ++k) {
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i = i + 1;
    }
    else {
      A[k] = R[j];
      j = j + 1;
    }
  }
}

#endif // MERGESORT_HPP_INCLUDED