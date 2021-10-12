#pragma once

#include <iostream>
#include <fstream>
#include <chrono>
#include <functional>
#include <memory>
#include <stdexcept>

#include <string>
#include <vector>
#include <array>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>

struct Timmer {
    static double globalTimmer;
    
    double* time;
    std::chrono::steady_clock::time_point start, end;
    
    Timmer() {
        time = &globalTimmer;
        start = std::chrono::high_resolution_clock::now();
    }

    Timmer(double* time) {
        this->time = time;
        start = std::chrono::high_resolution_clock::now();
    }

    ~Timmer() {
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> dur = end - start;
        double t = dur.count();
        globalTimmer = t;
        *time = t;
    }

};

const std::string getCurrentDateTime(const char* outputTime) {
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), outputTime, &tstruct);
    return buf;
}
