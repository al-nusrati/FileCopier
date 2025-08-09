#include "FileCopier.h"
#include "ConsoleUtils.h"
#include <iostream>
#include <iomanip>
#include "DerivedCredits.h"
using namespace std;

//*****************************************
//					MAIN
//*****************************************

int main()
{
#pragma region header

	DerivedCredits utils;

	//--- setup console
	utils.enableVirtualTerminal();
	utils.clearConsole();

	//--- show app title
	utils.setForegroundColor(ConsoleColor::BrightGreen);
	cout << "+-------------------------------+\n";
	cout << "|	  File Copier           |\n";
	cout << "+-------------------------------+\n\n";
	utils.setForegroundColor(ConsoleColor::Yellow);
	utils.hideCursor();
#pragma endregion

	//--- App BODY --------------------------------
	cout << "Starting file copy operation: " << endl;
	cout << "Copying 'PROJECT REPORT.docx' to destination." << endl;
	FileCopier copier;
	int totalBytes = 0;
	double percentage = 0;
	bool printedOnce = false;
	cout << fixed << setprecision(2) << endl;

	if (copier.openSrcFile()) {
		size_t totalLength = copier.getTotalLength();
		if (copier.openDstFile()) {
			copier.ProgressBar(176, 50);
			while (true) {
				copier.readSrcFileChunk();

				int bytesRead = copier.getBytesRead();
				totalBytes += bytesRead;

				percentage = (double)totalBytes * 100 / (totalLength);
				cout << "\r" << copier.ProgressBar(219, (int)(percentage / 2));
				cout << "\r" << percentage << "%";
				if (bytesRead == 0) {
					break;
				}
				copier.writeDstFileChunk(bytesRead);
			}
			cout << "\n\n" << totalBytes << "\n\n";
		}
	}

	copier.closeDstFile();
	//---------------------------------------------

#pragma region footer
	//--- show credits
	utils.setForegroundColor(ConsoleColor::BrightCyan);
	//credits.showCredits();
	utils.showCredits();


	//--- return / finish
	system("pause>0");
	return 0;
#pragma endregion
}