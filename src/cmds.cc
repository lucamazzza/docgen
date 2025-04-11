#include "../include/cmds.h"
#include <filesystem>
#include <fstream>
#include <iostream>

using namespace std::filesystem;

void runInit() {
    path docsPath = "docs";
    path assetsPath = docsPath / "assets";
    path contentPath = docsPath / "content";
    path pluginsPath = docsPath / "plugins";
    path configPath = docsPath / "docgen.toml";

    try {
        create_directories(assetsPath);
        create_directories(contentPath);
        create_directories(pluginsPath);

        std::ofstream configFile(configPath);
        configFile << "# docgen Configuration" << std::endl;
        configFile << "[config]" << std::endl;
        configFile << "  title = \"My Documentation\"" << std::endl;
        configFile << "  description = \"A description of the documentation...\"" << std::endl;
        configFile << "  author = \"Your Name\"" << std::endl;
        configFile << "  version = \"1.0\"" << std::endl;
        configFile << "  theme = \"default\"" << std::endl;
        configFile << "  output = \"out\"" << std::endl;

        std::cout << "Docs structure init successful" << std::endl;
    } catch (const filesystem_error& e) {
        std::cerr << "Error creating directories: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
