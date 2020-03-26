/*
 * main.cpp
 *
 *  Created on: Mar 12, 2020
 *  Author: wchang 00960978
 *  prof: K. Perkins @ CNU
 *  assignment: SP20-CS410: p3
 */

#include <string>
#include <thread>
#include "print_ts.h"
#include "tester.h"

using namespace std;

int main() {
	string str1 = "UVW";
	string str2 = "XYZ";
	string str3 = "ABC";

	startThreads(str1, 7, P3, 4, 100);
	startThreads(str2, 7, P1, 4, 200);
	startThreads(str3, 7, P2, 4, 300);
	this_thread::sleep_for(chrono::milliseconds(700));
	setCancelThreads(true);
	joinThreads();

	return 0;
}
