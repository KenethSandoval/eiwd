// sudo cp -r ogdev_util.* /usr/include/GL
#include "ogdev_util.h"
#include <fstream>

bool ReadFile(const char *fileName, std::string &outFile) {
  std::ifstream f(fileName);

  bool ret = false;
  
  if (f.is_open()) {
    std::string line;
    while (std::getline(f, line)) {
      outFile.append(line);
      outFile.append("\n");
    }

    f.close();
    ret = true;
  } else {
    ret = false;
  }

  return ret;
}
