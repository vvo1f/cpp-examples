/**
 * @file ex1.cpp
 * @author Salar Farahmand
 * @brief 
 *          Objective: 
                CPP projects skeleton and structure
 *          Reference: This example addresses the page#24 of u03s01 Introduction to C++ slide.
 * @version 0.1
 * @date 2026-03-07
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#ifndef MYCLASS_H
#define MYCLASS_H
// 1) why we have this #ifndef, #define, and #endif in our header files?
// answer: these are called include guards, and they are used to prevent multiple inclusions of the same header file in a C++ program. 
//          When a header file is included multiple times, it can lead to redefinition errors and other issues. 
//          The include guards ensure that the contents of the header file are only included once during the compilation process, even if the header file is included multiple times in different parts of the program.

// 2) Do we have this also for source files (.cpp files)? [Good Question! ;)]
// answer: No, we do not use include guards for source files (.cpp files) because they are not meant to be included in other files. Source files are compiled separately and then linked together

class MyClass {
    char* ptr;
    public:
        int doWork();

};

#endif