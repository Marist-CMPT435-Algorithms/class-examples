/*
 * JavaScript implementations
 */

/* Insertion sort */
function insertionSort(a) {
  for (let j = 1; j < a.length; ++j) {
    const key = a[j];
    let i = j - 1;
    while (i >= 0 && a[i] > key) {
      a[i + 1] = a[i];
      i = i - 1;
    }
    a[i + 1] = key;
  }
}

/* Selection sort */
function selectionSort(a) {
  for (let i = 0; i < a.length - 1; ++i) {
    let k = i;
    for (let j = i + 1; j < a.length; ++j)
      if (a[j] < a[k])
        k = j;
    [a[i], a[k]] = [a[k], a[i]]; // swap via destructuring
  }
}

/* Bubble sort */
function bubbleSort(a) {
  for (let i = 0; i < a.length - 1; ++i)
    for (let j = a.length - 1; j > i; --j)
      if (a[j] < a[j - 1])
        [a[j], a[j - 1]] = [a[j - 1], a[j]]; // swap via destructuring
}

/* Merge sort */
function mergeSort(A, p = 0, r = A.length) {
    if (r - p > 1) {
        const q = Math.floor((p + r) / 2);
        mergeSort(A, p, q);
        mergeSort(A, q, r);
        merge(A, p, q, r);
    }
}

function merge(A, p, q, r) {
  const n1 = q - p;
  const n2 = r - q;
  const L = new Array(n1 + 1);
  const R = new Array(n2 + 1);

  for (let i = 0; i < n1; ++i)
    L[i] = A[p + i];
  for (let j = 0; j < n2; ++j)
    R[j] = A[q + j];

  L[n1] = Infinity;
  R[n2] = Infinity;

  let i = 0;
  let j = 0;

  for (let k = p; k < r; ++k) {
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i = i + 1;
    } else {
      A[k] = R[j];
      j = j + 1;
    }
  }
}

/* Quick sort */
function quickSort(A, p = 0, r = A.length - 1) {
  if (p < r) {
    const q = partition(A, p, r);
    quickSort(A, p, q - 1);
    quickSort(A, q + 1, r);
  }
}

function partition(A, p, r) {
  const x = A[r];
  let i = p - 1;
  for (let j = p; j < r; ++j) {
    if (A[j] <= x) {
      i = i + 1;
      [A[i], A[j]] = [A[j], A[i]]; // swap via destructuring
    }
  }
  [A[i + 1], A[r]] = [A[r], A[i + 1]]; // swap via destructuring
  return i + 1;
}
