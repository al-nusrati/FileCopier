#include "FileCopier.h"  
#include <iostream>  
using namespace std;

FileCopier::FileCopier() {
	SOURCE_FILE_Path = "PROJECT REPORT.docx";
	DESTINATION_FILE_Path = "destination.txt";
}

FileCopier::~FileCopier() {
	closeFiles();
}

bool FileCopier::openSrcFile() {
	srcFile.open(SOURCE_FILE_Path, ios::binary);
	if (!srcFile.is_open()) {
		cerr << "Failed to open file: " << SOURCE_FILE_Path << '\n';
		return false;
	}
	return true;
}

bool FileCopier::readSrcFileChunk() {
	srcFile.read(buffer, CHUNK_SIZE);
	if (srcFile)
		return true;
	else
		return false;
}

void FileCopier::closeSrcFile() {
	if (srcFile.is_open()) {
		srcFile.close();
	}
}

bool FileCopier::openDstFile() {
	dstFile.open(DESTINATION_FILE_Path, ios::binary);
	if (!dstFile.is_open()) {
		cerr << "Failed to open file: " << DESTINATION_FILE_Path << '\n';
		return false;
	}
	return true;
}

bool FileCopier::writeDstFileChunk(int bytesToWrite) {
	dstFile.write(buffer, bytesToWrite);
	return true;
}

void FileCopier::closeDstFile() {
	if (dstFile.is_open()) {
		dstFile.close();
	}
}

void FileCopier::closeFiles() {
	closeSrcFile();
	closeDstFile();
}

