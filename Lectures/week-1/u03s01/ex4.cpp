/**
 * @file ex4.cpp
 * @author Salar Farahmand
 * @brief 
 *          Objective: 
                Example#3: combination of Example#1 (ex2.c) and Example#2 (ex3.cpp)
 *          Reference: This example addresses the page#38 of u03s01 Introduction to C++ slide.
 * @version 0.1
 * @date 2026-03-07
 * 
 * @copyright Copyright (c) 2026
 * 
 */

// C libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// POSIX library for process control and inter-process communication
#include <unistd.h>
#include <sys/wait.h>
// C++ libraries
#include <string>
#include <vector>
#include <iostream>


using namespace std;

int main() {
    // PART#1
        int l, fd[2];
    char s[100];
    setbuf (stdout, 0);
    pipe (fd);
    if (fork()!=0) {
        while (1) {
            fprintf (stdout, "Father Write: ");
            scanf ("%s", s);
            l = strlen (s) + 1;
            write (fd[1], &l, sizeof(int));
            write (fd[1], s, l*sizeof(char));
            if (strcmp (s, "end")==0) break;
            sleep (1);
        }
        wait ((int *) 0);
    } else {
        while(1) {
            read (fd[0], &l, sizeof(int));
            read (fd[0], s, l*sizeof(char));
            fprintf (stdout, "Child Read: %s\n", s);
            if (strcmp (s, "end")==0) break;
        }
        exit(0);
    }

    // PART#2
    vector<string> v;
    string s2 = "one";
    v.push_back(s2);
    s2 = "two";
    v.push_back(s2);
    s2 = "three";
    v.push_back(s2);

    for(int i = 0; i < v.size(); ++i) {
        cout << " " << v[i] << endl;
    }

    return 0;

}

