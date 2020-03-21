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
	string str = "UVW";

	startThreads(str, 10, P3, 4, 100);
	this_thread::sleep_for(chrono::milliseconds(400));
	setCancelThreads(true);
	joinThreads();

	return 0;
}
