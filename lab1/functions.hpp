#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <algorithm>
#include <iostream>
#include <string>

// Объединение 2 массивов и удаление дубликатов.
void mergeSortAndRemoveDuplicates(char *arr, size_t size);

// Проверка на то, что это все буквы.
bool allLetters(const std::string &str);

// Удаление дубликатов.
std::string removeDuplicates(const std::string &str);

// Правильный ввод массива A
void ParceA(std::string &lineA);

// Правильный ввод массива B
void ParceB(std::string &lineB);

// Сортировка.
char *SelectSort(char *str, size_t sizeS);

// Вывод.
void Print(const char *arr, size_t size);

// Заполнение массива.
void Completion(char *arr, size_t size, const std::string &line);

#endif