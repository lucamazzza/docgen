#include "../include/cmds.hh"
#include "../include/const.hh"
#include <iostream>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << D_DESCR << std::endl << D_USAGE << std::endl;
    }
    else if (std::string(argv[1]) == "--init") {
        runInit();
    } else if (std::string(argv[1]) == "--export") {
        runExport();
    } else {
        std::cerr << "Invalid command. Use --init or --export." << std::endl;
    }
}
