#include "functions.hpp"

// Объединение 2 массивов и удаление дубликатов.
void mergeSortAndRemoveDuplicates(char *arr, size_t size) {
  SelectSort(arr, size);
  size_t newSize = 0;
  for (size_t i = 0; i < size; ++i) {
    if (i == 0 || arr[i] != arr[i - 1]) {
      arr[newSize++] = arr[i];
    }
  }
  size = newSize;
}

// Проверка на то, что это все буквы.
bool allLetters(const std::string &str) {
  for (char c : str) {
    if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) {
      return false;
    }
  }
  return true;
}

// Удаление дубликатов.
std::string removeDuplicates(const std::string &str) {
  std::string result;
  for (char c : str) {
    if (result.find(c) == std::string::npos) {
      result += c;
    }
  }
  return result;
}

// Правильный ввод массива A
void ParceA(std::string &lineA) {
  while (true) {
    std::cout << "\nInput A: ";
    std::cin >> lineA;
    if (allLetters(lineA)) {
      lineA = removeDuplicates(lineA);
      break;
    } else
      std::cout << "\x1b[31mLine entry error\x1b[0m\n";
  }
}

// Правильный ввод массива B
void ParceB(std::string &lineB) {
  while (true) {
    std::cout << "\nInput B: ";
    std::cin >> lineB;
    if (allLetters(lineB)) {
      lineB = removeDuplicates(lineB);
      break;
    } else
      std::cout << "\x1b[31mLine entry error\x1b[0m\n";
  }
}

// Сортировка.
char *SelectSort(char *str, size_t sizeS) {
  for (size_t i = 0; i < sizeS - 1; ++i) {
    size_t k = i;
    for (size_t j = i + 1; j < sizeS; ++j) {
      if (str[j] < str[k]) {
        k = j;
      }
    }
    if (k != i) {
      std::swap(str[i], str[k]);
    }
  }
  return str;
}

// Вывод.
void Print(const char *arr, size_t size) {
  for (size_t i = 0; i < size; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "\n";
}

// Заполнение массива.
void Completion(char *arr, size_t size, const std::string &line) {
  size_t index = 0;
  for (char c : line) {
    if (std::isalpha(c)) {
      arr[index++] = c;
    }
  }
}