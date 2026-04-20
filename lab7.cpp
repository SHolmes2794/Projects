// ================================================================
// Student CSV Analyser — Read, Parse, and Compute Statistics
// ================================================================
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip> // For setprecision and setw
using namespace std;

int main() 
{
	ifstream file("courses.csv");
	if (!file) 
	{ 
		cout << "Error: Cannot open courses.csv" << endl; return 1; 
	}

	// ?? Accumulators ????????????????????????????????????????
	int count = 0; double total = 0; double high = 0; double low = 100;
	int mathC = 0; int physC = 0;
	string topName = "", lowName = "";
	string topSubject = "", lowSubject = "";

	// ?? Skip header ?????????????????????????????????????????
	string line;
	getline(file, line);

	// ?? Print table header ??????????????????????????????????
	cout << left << setw(10) << "Name"
		<< setw(15) << "Subject"
		<< setw(15) << "Score/MaxScore"
		<< setw(12) << "Percentage"
		<< "PASS/FAIL" << endl;
	cout << string(62, '-') << endl;

	// ?? Main loop — read, parse, display, accumulate ?????????
	while (getline(file, line)) 
	{
		string name, subject, scoreStr, maxScoreStr;
		stringstream ss(line);
		getline(ss, name, ',');
		getline(ss, subject, ',');
		getline(ss, scoreStr, ',');
		getline(ss, maxScoreStr, ',');
		double score = stod(scoreStr);
		double maxScore = stod(maxScoreStr);
		double percentage = score / maxScore * 100;
		string status = (percentage >= 60) ? "PASS" : "FAIL";

		string score_text = scoreStr + "/" + maxScoreStr;

		// Display formatted row
		cout << fixed << setprecision(1);
		cout << left << setw(10) << name
			<< setw(15) << subject
			<< setw(15) << score_text
			<< setw(12) << percentage
			<< status << endl;
		
		// Accumulate
		count++; total += percentage;
		if (score > high) { high = score; topName = name; topSubject = subject; }
		if (score < low) { low = score; lowName = name; lowSubject = subject;  }

		if (subject == "Mathematics") { mathC++; }
		if (subject == "Physics") { physC++; }

	}
	file.close();

	// ?? Print summary ?????????????????????????????????????????
	cout << string(62, '=') << endl;
	cout << fixed << setprecision(2);
	cout << endl << "Average Percentage:   " << total / count << endl;
	cout << "Highest Mark:         " << high << "  (" << topName << ", " << topSubject << ")" << endl;
	cout << "Lowest Mark:          " << low  << "  (" << lowName << ", " << lowSubject << ")" << endl;
	cout << "Mathematics Classes:  " << mathC << endl;
	cout << "Physics Classes:      " << physC << endl;
	return 0;
}