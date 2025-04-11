#include "../include/cmds.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std::filesystem;

void runExport() {
  path docsPath = "docs";
  path contentPath = docsPath / "content";
  path exportPath = docsPath / "out";
  path outPdfPath = exportPath / "out.pdf";
  path outTexPath = exportPath / "tmp";

  try {
    create_directories(exportPath);

    std::ofstream latexFile(outTexPath / "__compiled.tex");
    latexFile << "\\documentclass{article}" << std::endl;
    latexFile << "\\usepackage{graphicx}" << std::endl;
    latexFile << "\\usepackage[utf8]{inputenc}" << std::endl;
    latexFile << "\\usepackage{hyperref}" << std::endl;
    latexFile << "\\title{Documentation}" << std::endl;
    latexFile << "\\begin{document}" << std::endl;
    latexFile << "\\maketitle" << std::endl;

    std::cout << "Converting Markdown sources to LaTeX..." << std::endl;
    for (const auto &entry : directory_iterator(contentPath)) {
      if (entry.path().extension() == ".md") {
        std::string mdFile = entry.path().string();
        std::ostringstream cmd;
        cmd << "pandoc " << mdFile << "-t latex -o "
            << outTexPath / "__compiled.tex";
        int result = std::system(cmd.str().c_str());
        if (result != 0) {
          std::cerr << "Error converting " << mdFile << " to LaTeX."
                    << std::endl;
          return;
        }
        std::ifstream tmpTex(outTexPath / "__compiled.tex");
        latexFile << tmpTex.rdbuf();
        tmpTex.close();
      }
    }
    latexFile << "\\end{document}" << std::endl;
    latexFile.close();

    showProgress("Compiling LaTeX to PDF...");
    std::ostringstream cmd;
    cmd << "pdflatex -output-directory=" << exportPath << " "
        << outTexPath / "__compiled.tex";
    int result = std::system(cmd.str().c_str());
    if (result != 0) {
      std::cerr << "Error compiling LaTeX to PDF." << std::endl;
      return;
    }
    remove(outTexPath);
    std::cout << "\033[1;32mPDF exported successfully: " << outPdfPath
              << "\033[0m\n";
  } catch (const std::filesystem::filesystem_error &e) {
    std::cerr << "Error creating directories: " << e.what() << std::endl;
    return;
  }
}
