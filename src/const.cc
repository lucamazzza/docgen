#include "../include/const.h"
#include <filesystem>

// DISPLAY MESSAGES
const std::string D_DESCR {
    "docgen - fast-forward documentation generator"
};
const std::string D_USAGE {
    R"(USAGE:
            dg [options]

            Options:
            --help,     -h, -?    Show this help message
            --version,  -v        Show version information
            --init,     -i        Scaffold the needed file structure into the current project
            --export,   -e        Export the project
            --add,      -a        Add a new dependency to the project
    )"
};
const std::string D_VERSION {
    "docgen v0.1.0 (date)"
};
const std::string D_COPYRIGHT {
    "Copyright (C) 2025, Luca Mazza"
};
const std::string D_LICENSE {
    // TODO: Add license information
};
// -- SCAFFOLDING
const std::string D_SCAFFOLDING_PROCESS {
    "Scaffolding the project into "
};
const std::string D_SCAFFOLDING_SUCCESS {
    "Scaffolding completed successfully!"
};
const std::string D_SCAFFOLDING_FAILURE {
    "Scaffolding failed!"
};
// -- EXPORTING
const std::string D_EXPORTING_PROCESS {
    "Exporting the project into "
};
const std::string D_EXPORTING_SUCCESS {
    "Exporting completed successfully!"
};
const std::string D_EXPORTING_FAILURE {
    "Exporting failed!"
};
// -- DEPENDENCIES
const std::string D_DEPENDENCY_PROCESS {
    "Adding "
};
const std::string D_DEPENDENCY_ADDED_FAILURE {
    "Failed to add "
};
const std::string D_DEPENDENCY_ADDED_SUCCESS {
    "Successfully added "
};

// ERRORS
const std::string E_GENERAL_ERROR {
    "Fatal error: "
};
const std::string E_FILE_NOT_FOUND {
    "File not found: "
};
const std::string E_INVALID_ARGUMENT {
    "Invalid argument: "
};
const std::string E_INVALID_OPTION {
    "Invalid option: "
};
const std::string E_EMPTY_DIRECTORY {
    "Empty directory: "
};

// DEFAULT URLs
const std::string U_BASE_URL_GITHUB {
    "https://raw.githubusercontent.com/"
};
const std::string U_DEFAULT_PATH_GITHUB {
    "refs/heads/main"
};
const std::string U_SCAFFOLDED_TOML {
    U_BASE_URL_GITHUB + "lucamazzza/docgen/" + U_DEFAULT_PATH_GITHUB + "/examples/default/docgen.toml"
};

// PATHS
const std::string P_DEFAULT_SCAFFOLD_PATH {
    "docs"
}; 
const std::string P_DEFAULT_CONFIG_PATH {
    (std::filesystem::path{P_DEFAULT_SCAFFOLD_PATH} / "docgen.toml").string()
};

