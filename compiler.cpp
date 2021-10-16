#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstring>
#include <typeinfo>


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

    std::ofstream writeFile("output.c"); // this one has AIDS (limited edition!!) :3

    writeFile << "#include <stdio.h>\n";
    writeFile << "#include <string.h>\n";
    writeFile << "int main(){\n";

    int i=1;
    for (std::string line : lines) {
        //std::cout << line << std::endl;

        //std::cout << line;

        if (line.rfind("out!", 0) == 0) {
            writeFile << "printf(" << line.substr(5) << ");\nprintf(\"\\n\");\n"; 
        } 
        else if (line.rfind("out", 0) == 0) {
            writeFile << "printf(" << line.substr(4) << ");\n"; 
        } 
        else if (line.rfind(";;", 0) == 0) {
            
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
        else {
            std::cout << "ERR: Line " << i << "\n" << line << "\n";
            break;
        }

        i++;


    }
    writeFile << "return 0;\n}";
    writeFile.close();

    

}