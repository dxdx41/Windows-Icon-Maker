#include <iostream>
#include <string>
#include <Windows.h>
#include <thread>
#include <chrono>

void usage(char** argv) {
	std::cout << "Usage: " << argv[0] << " [filename.png]\n";
}

int main(int argc, char** argv) {

	if (argc != 2) {
		usage(argv);
		return 1;
	}

	std::string file = argv[1];
	unsigned char index = file.find_last_of('.');
	std::string fileName = file.substr(0, index);

	constexpr unsigned char nSizes = 6;

	std::string sizes[nSizes]{
		"16",
		"32",
		"48",
		"64",
		"128",
		"256"
	};

	std::string commands[nSizes] = {};

	std::string magick = "magick ";

	for (int i = 0; i < nSizes; ++i) {
		commands[i] = "ffmpeg -i " + std::string(argv[1]) + " -vf scale=\"" + sizes[i] + ":" + sizes[i] + "\" " + fileName + sizes[i] + ".png";
		system(commands[i].c_str());
		magick.append(fileName + sizes[i] + ".png ");
	}

	magick.append(fileName + ".ico");

	system(magick.c_str());

	for (int i = 0; i < nSizes; ++i) {
		std::string deleteString = fileName + sizes[i] + ".png";
		DeleteFileA(deleteString.c_str());
	}

	return 0;
}