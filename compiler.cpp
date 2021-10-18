#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstring>
#include <typeinfo>
#include <sstream>

//credit: https://sourcecodeera.com/blogs/Samath/Splitting-a-string-into-a-vector-using-C.aspx
std::vector<std::string> split(std::string str, char delimiter) {
  std::vector<std::string> result;
  std::stringstream ss(str); // Turn the string into a stream.
  std::string tok;
  
  while(std::getline(ss,tok,delimiter)) {
    result.push_back(tok);
  }
  
  return result;
}

int main() {
    std::string input;
    std::cout << "enter radio filename: ";
    std::getline(std::cin, input);
    std::cout << input << std::endl;
    std::vector <std::string> lines;{};
    std::string currentLine;
    std::ifstream file(input);

    while (std::getline (file, currentLine)) {
        lines.push_back(currentLine);
    };

    file.close();

    std::ofstream writeFile("output.c");

    writeFile << "#include <stdio.h>\n";
    writeFile << "#include <string.h>\n";
    writeFile << "int main(){\n";

    int i=1;
    for (std::string line : lines) {
        std::vector<std::string> sep = split(line, ' ');

        if (line.rfind("out!", 0) == 0) {
            writeFile << "printf(" << line.substr(5) << ");\nprintf(\"\\n\");\n"; 
        } 
        else if (line.rfind("out", 0) == 0) {
            writeFile << "printf(" << line.substr(4) << ");\n"; 
        } 
        else if (line.rfind(";;", 0) == 0) {
            
        }
        else if (line.rfind("@structure", 0) == 0) {
            writeFile << "typedef struct {\n";
        }
        else if (line.rfind("@strout", 0) == 0) {
            writeFile << "printf(\"%s\", " << line.substr(8) << ");\n"; 
        } 
        else if (line.rfind("@intout", 0) == 0) {
            writeFile << "printf(\"%d\", " << line.substr(8) << ");\n"; 
        } 
        else if (line.rfind("@floatout", 0) == 0) {
            writeFile << "printf(\"%f\", " << line.substr(9) << ");\n"; 
        }
        else if (line.rfind("@!define", 0) == 0) {
            writeFile << sep[1] << " " << sep[2] << "() {\n";
        }
        else if (line.rfind("@define", 0) == 0) {
            writeFile << sep[1] << " " << sep[2] << " (";
        }
        else if (line.rfind("@param", 0) == 0) {
            writeFile << sep[1] << " " << sep[2] << ",";
        }
        else if (line.rfind("@finalparam", 0) == 0) {
            writeFile << sep[1] << " " << sep[2] << "){\n";
        }
        else if (line.rfind("@call", 0) == 0) {
            writeFile << sep[1] << "(" << line.substr(sep[0].size() + 1 + sep[1].size() + 1) << ");\n";
        }
        else if (line.rfind("@!call", 0) == 0) {
            writeFile << sep[1] << "();\n";
        }
        else if (line.rfind("@str", 0) == 0) {
            writeFile << "char* " << line.substr(5) << ";\n"; 
        } 
        else if (line.rfind("@int", 0) == 0) {
            writeFile << "int " << line.substr(5) << ";\n"; 
        } 
        else if (line.rfind("@float", 0) == 0) {
            writeFile << "float " << line.substr(7) << ";\n"; 
        }
        else if (line.rfind("@double", 0) == 0) {
            writeFile << "double " << line.substr(8) << ";\n"; 
        }
        else if (line.rfind("@redefine", 0) == 0) {
            writeFile << sep[1] << " = " << line.substr(sep[0].size() + 1 + sep[1].size() + 3) << ";\n"; 
        }
        else if (line.rfind("end", 0) == 0) {
            writeFile << "}\n";
        }
        else if (line.rfind("if", 0) == 0) {
            writeFile << "if(" << line.substr(3) << "){\n";
        }
        else if (line.rfind("else if", 0) == 0) {
            writeFile << "else if(" << line.substr(8) << "){\n";
        }
        else if (line.rfind("elif", 0) == 0) {
            writeFile << "else if(" << line.substr(5) << "){\n";
        }
        else if (line.rfind("else", 0) == 0) {
            writeFile << "else {\n";
        }
        else if (line.rfind("while", 0) == 0) {
            writeFile << "while(" << line.substr(6) << "){\n";
        }
        else if (line.rfind("for", 0) == 0) {
            writeFile << "for(" << line.substr(4) << "){\n";
        }
        else if (line.rfind("@nl", 0) == 0) {
            writeFile << "printf(\"\\n\");\n";
        }
        else if (line.rfind("@property", 0) == 0) {
            if (sep[1] == "str") {
                writeFile << "char * " << sep[2] << ";\n";
            } else if (sep[1] == "float") {
                writeFile << "float *" << sep[2] << ";\n";
            } else if (sep[1] == "double") {
                writeFile << "double * " << sep[2] << ";\n";
            } else if (sep[1] == "int") {
                writeFile << "int " << sep[2] << ";\n";
            }
        }
        else if (line.rfind("@endstructure", 0) == 0) {
            writeFile << "} " << sep[1] << ";\n";
        } 
        else {
            std::cout << "ERR: Line " << i << "\n" << line << "\n";
            break;
        }

        i++;
    }
    writeFile << "return 0;\n}";
    writeFile.close();
}
