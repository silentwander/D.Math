#include "functions.hpp"
#include "option.hpp"

int main() {
  std::string lineA;
  std::string lineB;

  ParceA(lineA);
  ParceB(lineB);

  size_t sizeA = lineA.size();
  size_t sizeB = lineB.size();

  char *A = new char[sizeA];
  char *B = new char[sizeB];

  Completion(A, sizeA, lineA);
  Completion(B, sizeB, lineB);

  std::cout << "\n";
  std::cout << "\x1b[36m\x1b[1mA:\x1b[0m ";
  Print(A, sizeA);
  std::cout << "\x1b[36m\x1b[1mB:\x1b[0m ";
  Print(B, sizeB);
  std::cout << "\n";

  while (true) {

    int option;
    std::cout << "\nSelect the desired option: "
                 "\n1.AcB\t2.A+B\t3.A*B\t4.A\\B\t\x1b[31;5m5.Exit\x1b[0m\t6."
                 "B\\A\t7.A delta B\t8.Bc=A\t\n";
    std::cin >> option;
    char *result;
    size_t sizeR;
    // if (std::is_same<option, int>)
    switch (option) {
    case 1:
      sizeR = (sizeA < sizeB) ? sizeA : sizeB;
      result = new char[sizeR];
      sizeR = 0;
      std::cout << "\x1b[4mA is a subset of B\x1b[0m: ";
      (one(A, sizeA, B, sizeB, result, sizeR))
          ? std::cout << "\x1b[32mTrue\x1b[0m\n"
          : std::cout << "\x1b[31mFalse\x1b[0m\n";
      delete[] result;
      break;
    case 2:
      sizeR = sizeA + sizeB;
      result = new char[sizeR];
      sizeR = 0;
      Union(A, sizeA, B, sizeB, result, sizeR);
      mergeSortAndRemoveDuplicates(result, sizeR);
      std::cout << "\x1b[4mUnion\x1b[0m: ";
      Print(result, sizeR);
      delete[] result;
      break;
    case 3:
      sizeR = sizeA + sizeB;
      result = new char[sizeR];
      sizeR = 0;
      Intersection(A, sizeA, B, sizeB, result, sizeR);
      mergeSortAndRemoveDuplicates(result, sizeR);
      std::cout << "\x1b[4mIntersection\x1b[0m: ";
      Print(result, sizeR);
      delete[] result;
      break;
    case 4:
      sizeR = sizeA;
      result = new char[sizeR];
      sizeR = 0;
      DifferenceA(A, sizeA, B, sizeB, result, sizeR);
      if (result[0] != '\0') {
        std::cout << "\x1b[4mDifference\x1b[0m: ";
        Print(result, sizeR);
      } else {
        std::cout << "\x1b[31mThere are no such values\x1b[0m\n";
      }
      delete[] result;
      break;
    case 5:
      delete[] A;
      delete[] B;
      return 0;
    case 6:
      sizeR = sizeB;
      result = new char[sizeR];
      sizeR = 0;
      DifferenceB(A, sizeA, B, sizeB, result, sizeR);
      if (result[0] != '\0') {
        std::cout << "\x1b[4mDifference\x1b[0m: ";
        Print(result, sizeR);
      } else {
        std::cout << "\x1b[31mThere are no such values\x1b[0m\n";
      }
      delete[] result;
      break;
    case 7:
      sizeR = sizeA + sizeB;
      result = new char[sizeR];
      sizeR = 0;
      SymmetricDifference(A, sizeA, B, sizeB, result, sizeR);
      mergeSortAndRemoveDuplicates(result, sizeR);
      std::cout << "\x1b[4mSymmetric Difference\x1b[0m: ";
      Print(result, sizeR);
      delete[] result;
      break;
    case 8:
      std::cout << "\x1b[4mB is a subset of A\x1b[0m: ";
      (IsSubset(A, sizeA, B, sizeB)) ? std::cout << "\x1b[32mTrue\x1b[0m\n"
                                     : std::cout << "\x1b[31mFalse\x1b[0m\n";
      break;
    default:
      std::cout << "\x1b[31mError, input not number in 1-5\x1b[0m\n";
    }
  }
}
