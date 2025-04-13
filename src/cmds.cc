#include "../include/cmds.h"
#include "../include/const.h"
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std::filesystem;

void runInit() {
    std::cout << D_SCAFFOLDING_PROCESS << P_DEFAULT_SCAFFOLD_PATH << std::endl;

    path docsPath{P_DEFAULT_SCAFFOLD_PATH};
    path assetsPath{docsPath / "assets"};
    path contentPath{docsPath / "content"};
    path pluginsPath{docsPath / "plugins"};
    path themesPath{docsPath / "themes"};
    path configPath{docsPath / "docgen.toml"};
    std::string srcUrl{U_SCAFFOLDED_TOML};

    try {
        create_directories(assetsPath);
        create_directories(contentPath);
        create_directories(pluginsPath);
        create_directories(themesPath);

        std::ostringstream cmd;
        cmd << "wget" << " --no-verbose --show-progress -O " << configPath.string() << " " << srcUrl;
        system(cmd.str().c_str());

        std::cout << D_SCAFFOLDING_SUCCESS << std::endl;
    } catch (const filesystem_error& e) {
        std::cerr << D_SCAFFOLDING_FAILURE << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
