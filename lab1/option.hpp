#include <algorithm>
#include <iostream>
#include <string>

// AcB
bool one(const char *A, size_t sizeA, const char *B, size_t sizeB, char *result,
         size_t &sizeR);

// A+B
void Union(const char *A, size_t sizeA, const char *B, size_t sizeB,
           char *result, size_t &sizeR);

// A*B
void Intersection(const char *A, size_t sizeA, const char *B, size_t sizeB,
                  char *result, size_t &sizeR);

// A\B
void DifferenceA(const char *A, size_t sizeA, const char *B, size_t sizeB,
                 char *result, size_t &sizeR);

// B\A
void DifferenceB(const char *A, size_t sizeA, const char *B, size_t sizeB,
                 char *result, size_t &sizeR);

// A delta B
void SymmetricDifference(const char *A, size_t sizeA, const char *B,
                         size_t sizeB, char *result, size_t &sizeR);
// B подмножество A
bool IsSubset(const char *A, size_t sizeA, const char *B, size_t sizeB);