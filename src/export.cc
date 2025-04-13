#include "../include/cmds.h"
#include "../include/const.h"
#include "../include/toml.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std::filesystem;

void runExport() {
  std::cout << D_EXPORTING_PROCESS << P_DEFAULT_SCAFFOLD_PATH << std::endl;
  toml::table tbl{toml::parse_file(P_DEFAULT_CONFIG_PATH)};
  const std::string &title{tbl["title"].value_or("Documentation")};
  const std::string &description{tbl["description"].value_or("Documentation")};
  const std::string &author{tbl["author"].value_or("Author Name")};
  const std::string &version{tbl["version"].value_or("1.0.0")};
  const std::string &theme{tbl["theme"].value_or("default")};
  const bool &toc{tbl["toc"].value_or(true)};

  std::cout << tbl;
  path docsPath{P_DEFAULT_SCAFFOLD_PATH};
  path contentPath{docsPath / "content"};
  path exportPath{docsPath / "out"};
  path outPdfPath{exportPath / "out.pdf"};
  path outTexPath{exportPath / "tmp"};
  path themePath{docsPath / "themes"};
  path logPath{exportPath / "build.log"};

  try {
    create_directories(outTexPath);

    std::ifstream themeFile;
    if (theme != "default") {
      path themeDir{themePath / theme};
      if (!exists(themeDir)) {
        std::cerr << "Theme not found: " << theme << ". Using default theme"
                  << std::endl;
      } else {
        themeFile.open(themeDir / "theme.tex");
      }
    } else {
      std::cout << "Using default theme" << std::endl;
      themeFile.open(themePath / "default.tex");
    }

    std::ofstream latexFile{outTexPath / "__compiled.tex"};
    if (themeFile && latexFile) {
        std::string line;
        while (getline(themeFile, line)) {
            latexFile << line << "\n";
            std::cout << line << "\n";
        }
    }
    themeFile.close();

    latexFile << "\\title{" << title << "}\n";
    latexFile << "\\author{" << author << "}\n";
    latexFile << "\\begin{document}\n";
    latexFile << "\\maketitle\n";
    latexFile << "\\newpage\n";
    if (toc)
      latexFile << "\\tableofcontents\n";
    latexFile << "\\newpage\n";

    for (const auto &entry : directory_iterator(contentPath)) {
      if (entry.path().extension() == ".md") {
        std::string mdFile{entry.path().string()};
        std::ostringstream cmd;
        cmd << "pandoc \"" << mdFile << "\" -t latex -o "
            << outTexPath / "__compiled.tex";
        int result{std::system(cmd.str().c_str())};
        if (result != 0) {
          std::cerr << "Error converting " << mdFile << " to LaTeX."
                    << std::endl;
          return;
        }
        std::ifstream tmpTex{outTexPath / "__compiled.tex"};
        latexFile << tmpTex.rdbuf();
        tmpTex.close();
      }
    }
    latexFile << "\\end{document}\n";
    latexFile.close();

    std::ostringstream cmd;
    cmd << "pdflatex --interaction=nonstopmode -output-directory=" << outTexPath
        << " " << (outTexPath / "__compiled.tex").string() << " > " << logPath
        << " 2>&1 && mv " << outTexPath / "__compiled.pdf" << " " << outPdfPath;
    int result{std::system(cmd.str().c_str())};
    if (result != 0) {
      std::cerr << D_EXPORTING_FAILURE << std::endl;
      return;
    }
    //remove_all(outTexPath);
    std::cout << "\033[1;32m" << D_EXPORTING_SUCCESS << outPdfPath
              << "\033[0m\n";
  } catch (const std::filesystem::filesystem_error &e) {
    std::cerr << E_GENERAL_ERROR << e.what() << std::endl;
    return;
  }
}
