## Python implementations ##
import math

# Insertion sort
def insertionSort(a):
  for j in range(1, len(a)):
    key = a[j]
    i = j - 1
    while i >= 0 and a[i] > key:
      a[i + 1] = a[i]
      i = i - 1
    a[i + 1] = key

# Selection sort
def selectionSort(a):
  for i in range(0, len(a) - 1):
    k = i
    for j in range(i + 1, len(a)):
      if a[j] < a[k]:
        k = j
    a[i], a[k] = a[k], a[i]

# Bubble sort
def bubbleSort(a):
  for i in range(0, len(a) - 1):
    for j in range(len(a) - 1, i, -1):
      if a[j] < a[j - 1]:
        a[j], a[j - 1] = a[j - 1], a[j]

# Merge sort
def mergeSort(A, p = 0, r = None):
  if r is None:
    r = len(A)
  if (r - p > 1):
    q = int((p + r) / 2)
    mergeSort(A, p, q)
    mergeSort(A, q, r)
    merge(A, p, q, r)

def merge(A, p, q, r):
  n1 = q - p
  n2 = r - q
  L = [None] * (n1 + 1)
  R = [None] * (n2 + 1)

  for i in range(0, n1):
    L[i] = A[p + i]
  for j in range(0, n2):
    R[j] = A[q + j]

  L[n1] = math.inf;
  R[n2] = math.inf;

  i = 0
  j = 0

  for k in range(p, r):
    if L[i] <= R[j]:
      A[k] = L[i]
      i = i + 1
    else:
      A[k] = R[j]
      j = j + 1

# Quick sort
def quickSort(A, p = 0, r = None):
  if r is None:
    r = len(A) - 1
  if p < r:
    q = partition(A, p, r)
    quickSort(A, p, q - 1)
    quickSort(A, q + 1, r)

def partition(A, p, r):
  x = A[r]
  i = p - 1
  for j in range(p, r):
    if A[j] <= x:
      i = i + 1
      A[i], A[j] = A[j], A[i]
  A[i + 1], A[r] = A[r], A[i + 1]
  return i + 1
