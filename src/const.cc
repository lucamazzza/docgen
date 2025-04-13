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
   R"(MIT License

    Copyright (c) 2025 Luca Mazza

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS)"
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
const std::string U_SCAFFOLDED_THEME {
    U_BASE_URL_GITHUB + "lucamazzza/docgen/" + U_DEFAULT_PATH_GITHUB + "/examples/default/default.tex"
};
// PATHS
const std::string P_DEFAULT_SCAFFOLD_PATH {
    "docs"
}; 
const std::string P_DEFAULT_CONFIG_PATH {
    (std::filesystem::path{P_DEFAULT_SCAFFOLD_PATH} / "docgen.toml").string()
};

