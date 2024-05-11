#include "option.hpp"

// AcB (собсвтенное подмножество)
bool one(const char *A, size_t sizeA, const char *B, size_t sizeB, char *result,
         size_t &sizeR) {
  bool foundAll = true;
  for (size_t i = 0; i < sizeA; i++) {
    bool found = false;
    for (size_t j = 0; j < sizeB; j++) {
      if (A[i] == B[j]) {
        found = true;
        break;
      }
    }
    if (!found) {
      foundAll = false;
      break;
    }
  }
  return foundAll;
}

// A+B
void Union(const char *A, size_t sizeA, const char *B, size_t sizeB,
           char *result, size_t &sizeR) {
  size_t i = 0, j = 0, k = 0;
  while (i < sizeA && j < sizeB) {
    if (A[i] < B[j])
      result[k++] = A[i++];
    else if (B[j] < A[i])
      result[k++] = B[j++];
    else {
      result[k++] = A[i++];
      j++;
    }
  }
  while (i < sizeA)
    result[k++] = A[i++];
  while (j < sizeB)
    result[k++] = B[j++];

  sizeR = k;
}

// A*B
void Intersection(const char *A, size_t sizeA, const char *B, size_t sizeB,
                  char *result, size_t &sizeR) {
  size_t i = 0, j = 0, k = 0;
  while (i < sizeA && j < sizeB) {
    if (A[i] < B[j])
      i++;
    else if (B[j] < A[i])
      j++;
    else {
      result[k++] = A[i++];
      j++;
    }
  }
  sizeR = k;
}

// A\B
void Difference(const char *A, size_t sizeA, const char *B, size_t sizeB,
                char *result, size_t &sizeR) {
  for (size_t i = 0; i < sizeA; i++) {
    int cnt = 0;
    for (size_t j = 0; j < sizeB; j++) {
      if (B[j] == A[i]) {
        cnt++;
        break;
      }
    }
    if (cnt == 0) {
      result[sizeR++] = A[i];
    }
    if (cnt != 0) {
      result[0] = '\0';
    }
  }
}

// A\B
void DifferenceA(const char *A, size_t sizeA, const char *B, size_t sizeB,
                 char *result, size_t &sizeR) {
  for (size_t i = 0; i < sizeA; i++) {
    int cnt = 0;
    for (size_t j = 0; j < sizeB; j++) {
      if (B[j] == A[i]) {
        cnt++;
        break;
      }
    }
    if (cnt == 0) {
      result[sizeR++] = A[i];
    }
    if (cnt != 0) {
      result[0] = '\0';
    }
  }
}

// B\A
void DifferenceB(const char *A, size_t sizeA, const char *B, size_t sizeB,
                 char *result, size_t &sizeR) {
  for (size_t i = 0; i < sizeB; i++) {
    int cnt = 0;
    for (size_t j = 0; j < sizeA; j++) {
      if (A[j] == B[i]) {
        cnt++;
        break;
      }
    }
    if (cnt == 0) {
      result[sizeR++] = B[i];
    }
    if (cnt != 0) {
      result[0] = '\0';
    }
  }
}

// A delta B
void SymmetricDifference(const char *A, size_t sizeA, const char *B,
                         size_t sizeB, char *result, size_t &sizeR) {
  sizeR = 0;

  for (size_t i = 0; i < sizeA; i++) {
    int cnt = 0;
    for (size_t j = 0; j < sizeB; j++) {
      if (A[i] == B[j]) {
        cnt++;
        break;
      }
    }
    if (cnt == 0) {
      result[sizeR++] = A[i];
    }
  }

  for (size_t i = 0; i < sizeB; i++) {
    int cnt = 0;
    for (size_t j = 0; j < sizeA; j++) {
      if (B[i] == A[j]) {
        cnt++;
        break;
      }
    }
    if (cnt == 0) {
      result[sizeR++] = B[i];
    }
  }
}

// B подмножество A
bool IsSubset(const char *A, size_t sizeA, const char *B, size_t sizeB) {
  for (size_t i = 0; i < sizeB; ++i) {
    bool found = false;
    for (size_t j = 0; j < sizeA; ++j) {
      if (B[i] == A[j]) {
        found = true;
        break;
      }
    }
    if (!found) {
      return false;
    }
  }
  return true;
}