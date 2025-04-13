#include "../include/cmds.h"
#include <iostream>
#include <thread>
#include <chrono>

void showProgress(const std::string &message, int duration) {
    std::cout << message;
    for (int i = 0; i < duration; ++i) {
        std::cout << ".";
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    std::cout << "\n";
}
