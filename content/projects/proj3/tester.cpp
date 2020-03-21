/*
 * tester.cpp
 *
 *  Created on: Mar 12, 2020
 *  Author: wchang 00960978
 *  prof: K. Perkins @ CNU
 *  assignment: SP20-CS410: p3
 */


#include <thread>
#include <iostream>
#include <vector>
#include "tester.h"
#include "print_ts.h"

using namespace std;

vector<std::thread> workthreads;
bool stop_working = false;

/*
 * starts cancelable threads
 * string s			-the string to print
 * numThreads 		-the number of threads to start
 * wp 				-which print statement should be used
 * numTimesToPrint 	-the number of PRINT statements each thread will call
 * millisecond_delay- how long (in milliseconds) to wait between prints
 */
void startThreads(string s, int numThreads, WHICH_PRINT wp, int numTimesToPrint, int millisecond_delay) {

		for (int i = 0; i < numThreads; ++i) {
			workthreads.push_back(thread([&]() {
				int times_thread_printed = 0;
				while(!stop_working && times_thread_printed < numTimesToPrint) {
				switch(wp) {
					case P1:
						PRINT1(s);
						break;
					case P2:
						PRINT2(s, s);
						break;
					case P3:
						PRINT3(s, s, s);
						break;
					case P4:
						PRINT4(s, s, s, s);
						break;
					case P5:
						PRINT5(s, s, s, s, s);
						break;
				}
				++times_thread_printed;
				this_thread::sleep_for(chrono::milliseconds(millisecond_delay));
				}
				if (stop_working) {
					cout << USER_CHOSE_TO_CANCEL << endl; // not threadsafe. PRINT1(const) => compiler error
				}
			}));
		}

}

/*
 * if bCanceled== true then causes all running threads to print USER_CHOSE_TO_CANCEL and then exit
 * if false then just reset logic used to cancel threads
 */
void setCancelThreads(bool bCancel) {
	stop_working = bCancel;
}

/*
 * waits for all threads to complete
 */
void joinThreads() {
	for (auto& t : workthreads) {
		t.join();
	}
}
