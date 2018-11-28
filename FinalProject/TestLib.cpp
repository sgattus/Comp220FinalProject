//
// Created by Toby Dragon on 9/4/18.
//
#include <iostream>
#include "TestLib.h"

void printAssertEquals(int expected, int actual){
    if (expected == actual){
        std::cout << "pass" << std::endl;
    }
    else {
        std::cout << "FAIL, expected: " << expected << "\tactual: " << actual << std::endl;
    }
}

void printAssertEquals(float expected, float actual, float threshold){
    float diff = (expected - actual);
    if (diff < 0){
        diff = -diff;
    }
    if (diff <= threshold){
        std::cout << "pass" << std::endl;
    }
    else {
        std::cout << "FAIL, expected: " << expected << "\tactual: " << actual << std::endl;
    }
}

void printAssertEquals(bool expected, bool actual){
    if (expected == actual){
        std::cout << "pass" << std::endl;
    }
    else {
        std::cout << std::boolalpha;
        std::cout << "FAIL, expected: " << expected << "\tactual: " << actual << std::endl;
    }
}

void printAssertEquals(std::string expected, std::string actual){
    if (expected == actual){
        std::cout << "pass" << std::endl;
    }
    else {
        std::cout << "FAIL, expected: " << expected << "\tactual: " << actual << std::endl;
    }
}

void printAssertEquals(int* a1, int *a2, int size){
    int failCount = 0;
    for (int i=0; i<size; i++){
        if (a1[i] != a2[i]) {
            failCount++;
        }
    }
    if (failCount <=0){
        std::cout << "pass" << std::endl;
    }
    else {
        std::cout << "FAIL, failCount: " << failCount << std::endl;
    }
}

void printAssertArrayEqual(int* a1, int *a2, int size){
    int failCount = 0;
    for (int i=0; i<size; i++){
        if (a1[i] != a2[i]) {
            failCount++;
        }
    }
    if (failCount <=0){
        std::cout << "pass" << std::endl;
    }
    else {
        std::cout << "FAIL, failCount: " << failCount << std::endl;
    }
}