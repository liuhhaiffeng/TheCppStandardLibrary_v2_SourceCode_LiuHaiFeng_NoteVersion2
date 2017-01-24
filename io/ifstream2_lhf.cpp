/* The following code example is taken from the book
 * "The C++ Standard Library - A Tutorial and Reference, 2nd Edition"
 * by Nicolai M. Josuttis, Addison-Wesley, 2012
 *
 * (C) Copyright Nicolai M. Josuttis 2012.
 * Permission to copy, use, modify, sell and distribute this software
 * is granted provided this copyright notice appears in all copies.
 * This software is provided "as is" without express or implied
 * warranty, and with no claim as to its suitability for any purpose.
 */
// header files for file I/O
#include <iostream>
#include <fstream>
#include <sstream>

void printFileTwice (const char* filename)
{
    // open file
    std::ifstream file(filename);

    // print contents the first time
    // Returns the associated stream buffer. If there is no associated stream buffer, returns NULL.
	std::cout << '\n' << "第一次打印:" << '\n';
    std::cout << file.rdbuf();

    // seek to the beginning
    file.seekg(0);

    // print contents the second time
	std::cout << "第二次打印:" << '\n';
    std::cout << file.rdbuf();
}

void printFileTest1(const char* filename)
{
	std::ifstream file(filename);

	std::ostringstream os;
	os << file.rdbuf();
	std::string text(os.str());
	std::cout << '\n' << "text:" << '\n';
	std::cout << text << '\n';
}

int main (int argc, char* argv[])
{
    // print all files passed as a command-line argument twice
    for (int i=1; i<argc; ++i) {
        printFileTwice(argv[i]);
		printFileTest1(argv[i]);
    }

}
