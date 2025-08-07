#pragma once
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class FileCopier {
private:
	// Constants
	const char* SOURCE_FILE_Path;
	const char* DESTINATION_FILE_Path;
	static const size_t CHUNK_SIZE = 1024;

	// File streams
	ifstream srcFile;
	ofstream dstFile;

public:
	size_t length = 0;
	int getBytesRead() {
		return srcFile.gcount();
	}

	int ProgressBar(int ASCII, int repeatCount = 100) {
		for (int i = 0; i < repeatCount; i++) {
			cout << char(ASCII);
		}
		return 0;
	}

	size_t getTotalLength() {
		srcFile.seekg(0, srcFile.end);
		length = srcFile.tellg();

		srcFile.seekg(0, srcFile.beg);
		return length;
	}

	char buffer[1024];

	// Source file operations
	bool openSrcFile();
	bool readSrcFileChunk();
	void closeSrcFile();

	// Destination file operations
	bool openDstFile();
	bool writeDstFileChunk(int bytesToWrite);
	void closeDstFile();

	// Utility
	void closeFiles();

	FileCopier();
	~FileCopier();

	//bool copyFile();
};
