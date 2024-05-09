#include <iostream>
#include <string>
#include <algorithm>

bool one(const char* A, size_t sizeA, const char* B, size_t sizeB, char *result, size_t &sizeR)
{
    bool foundAll = true;
    for (size_t i = 0; i < sizeA; i++){
        bool found = false;
        for (size_t j = 0; j < sizeB; j++){
            if (A[i] == B[j]){
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

void two(const char* A, size_t sizeA, const char* B, size_t sizeB, char* result, size_t &sizeR)
{
    for (size_t i = 0; i < sizeA; i++)
    {
        result[sizeR++] = A[i];
    }
    for (size_t i = 0; i < sizeB; i++)
    {   
        bool found = true;
        for (size_t j = 0; j < sizeA; j++){
            if (B[i] == A[j]) found = false;
        }
        if (found) result[sizeR++] = B[i];
    }
}

void three(const char* A, size_t sizeA, const char* B, size_t sizeB, char *result, size_t &sizeR)
{
    for (size_t i = 0; i < sizeA; i++){
        for (size_t j = 0; j < sizeB; j++){
            if (A[i] == B[j]){
                result[sizeR++] = A[i];
                break;
            }
        }
    } 
}

void four(const char* A, size_t sizeA, const char* B, size_t sizeB, char* result, size_t& sizeR)
{
    for (size_t i = 0; i < sizeA; i++)
    {
        int cnt = 0;
        for (size_t j = 0; j < sizeB; j++)
        {
            if (B[j] == A[i]) { cnt++; break; }
        }
        if (cnt == 0) { result[sizeR++] = A[i]; }
        if (cnt != 0) { result[0] = '\0'; }
    }
}

std::string removeDuplicates(const std::string& str) {
    std::string result;
    for (char c : str) {
        if (result.find(c) == std::string::npos) {
            result += c;
        }
    }
    return result;
}

char *StringSort(char *str, size_t sizeS)
{
    std::sort(str, str+sizeS);
    return str;
}

void Print(const char* arr, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

void Completion(char *arr, size_t size, const std::string& line) {
    size_t index = 0;
    for (char c : line) {
        if (std::isalpha(c)) {
            arr[index++] = c;
        }
    }
}

bool isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool allLetters(const std::string& str) {
    for (char c : str) {
        if (!isLetter(c)) {
            return false;
        }
    }
    return true;
}

int main(){
    std::string lineA;
    std::string lineB;

    while (true) {
        std::cout << "\nInput A: ";
        std::cin >> lineA;
        if (allLetters(lineA)) {
            lineA = removeDuplicates(lineA);
            break;
        }
        else std::cout << "\x1b[31mLine entry error\x1b[0m\n";
    }

    while (true) {
        std::cout << "\nInput B: ";
        std::cin >> lineB;
        if (allLetters(lineB)) {
            lineB = removeDuplicates(lineB);
            break;
        }
        else std::cout << "\x1b[31mLine entry error\x1b[0m\n";
    }


    size_t sizeA = lineA.size();
    size_t sizeB = lineB.size();

    char* A = new char[sizeA];
    char* B = new char[sizeB];

    Completion(A, sizeA, lineA);
    Completion(B, sizeB, lineB);

    std::cout << "\n";
    std::cout << "\x1b[36m\x1b[1mA:\x1b[0m "; Print(A, sizeA);
    std::cout << "\x1b[36m\x1b[1mB:\x1b[0m "; Print(B, sizeB);
    std::cout << "\n";

    
    while (true){

        int option;
        std::cout << "\nSelect the desired option: \n1.AcB\t2.A+B\t3.A*B\t4.A\\B\t\x1b[31;5m5.Exit\x1b[0m\n";
        std::cin >> option;
        char* result;
        size_t sizeR;
        //if (std::is_same<option, int>)
        switch (option){
            case 1:
                sizeR = (sizeA < sizeB) ? sizeA : sizeB;
                result = new char[sizeR];
                sizeR = 0;
                std::cout << "\x1b[4mA is a subset of B\x1b[0m: "; (one(A, sizeA, B, sizeB, result, sizeR)) ? std::cout << "\x1b[32mTrue\x1b[0m\n" : std::cout << "\x1b[31mFalse\x1b[0m\n";
                delete[] result;
                break;
            case 2:
                sizeR = sizeA + sizeB;
                result = new char[sizeR];
                sizeR = 0;
                two(A, sizeA, B, sizeB, result, sizeR);
                std::cout << "\x1b[4mUnion\x1b[0m: "; Print(result, sizeR);
                delete[] result;
                break;
            case 3:
                sizeR = (sizeA < sizeB) ? sizeA : sizeB;
                result = new char[sizeR];
                sizeR = 0;
                three(A, sizeA, B, sizeB, result, sizeR);
                std::cout << "\x1b[4mIntersection\x1b[0m: "; Print(result, sizeR); 
                delete[] result;
                break;
            case 4:
                sizeR = sizeA;
                result = new char[sizeR];
                sizeR = 0;
                four(A, sizeA, B, sizeB, result, sizeR);
                if (result[0] != '\0') { std::cout << "\x1b[4mDifference\x1b[0m: "; Print(result,sizeR); }
                else {std::cout << "\x1b[31mThere are no such values\x1b[0m\n";}
                delete[] result;
                break;
            case 5:
                delete[] A;
                delete[] B;
                return 0;
            default:
                std::cout << "\x1b[31mError, input not number in 1-5\x1b[0m\n";
        }
    }
}
