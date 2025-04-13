#ifndef CONST_H
#define CONST_H

#pragma once
#include <string>

// DISPLAY MESSAGES
extern const std::string D_DESCR;
extern const std::string D_USAGE;
extern const std::string D_VERSION;
extern const std::string D_COPYRIGHT;
extern const std::string D_LICENSE;
// -- SCAFFOLDING
extern const std::string D_SCAFFOLDING_PROCESS;
extern const std::string D_SCAFFOLDING_SUCCESS;
extern const std::string D_SCAFFOLDING_FAILURE;
// -- EXPORTING
extern const std::string D_EXPORTING_PROCESS;
extern const std::string D_EXPORTING_SUCCESS;
extern const std::string D_EXPORTING_FAILURE;
// -- DEPENDENCIES 
extern const std::string D_DEPENDENCY_INSTALL_PROCESS;
extern const std::string D_DEPENDENCY_INSTALL_SUCCESS;
extern const std::string D_DEPENDENCY_INSTALL_FAILURE;

// ERROR MESSAGES
extern const std::string E_GENERAL_ERROR;
extern const std::string E_FILE_NOT_FOUND;
extern const std::string E_INVALID_ARGUMENT;
extern const std::string E_INVALID_OPTION;
extern const std::string E_EMPTY_DIRECTORY;

// DEFAULT URLs
extern const std::string U_BASE_URL_GITHUB;
extern const std::string U_DEFAULT_PATH_GITHUB;
extern const std::string U_SCAFFOLDED_TOML;
extern const std::string U_SCAFFOLDED_THEME;

// PATHS
extern const std::string P_DEFAULT_SCAFFOLD_PATH;
extern const std::string P_DEFAULT_CONFIG_PATH;
extern const std::string P_DEFAULT_INSTALL_PATH;
extern const std::string P_DEFAULT_MIRRORFILE_PATH;

#endif
