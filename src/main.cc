#include "../include/cmds.h"
#include <iostream>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "USAGE:" << std::endl << "  docgen --init" << std::endl
                  << "  docgen --export" << std::endl;
    }
    else if (std::string(argv[1]) == "--init") {
        runInit();
    } else if (std::string(argv[1]) == "--export") {
        runExport();
    } else {
        std::cerr << "Invalid command. Use --init or --export." << std::endl;
    }
}
