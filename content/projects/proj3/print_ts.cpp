/*
 * print_ts.cpp
 *
 *  Created on: Mar 12, 2020
 *  Author: wchang 00960978
 *  prof: K. Perkins @ CNU
 *  assignment: SP20-CS410: p3
 */

#include <iostream>
#include <mutex>
#include "print_ts.h"

using namespace std;
mutex m;

void PRINT1(string &t1) {
	m.lock();
	cout << t1 << endl;
	m.unlock();
}

void PRINT2(string &t1, string &t2) {
	m.lock();
	cout << t1 << t2 << endl;
	m.unlock();
}

void PRINT3(string &t1, string &t2, string &t3) {
	m.lock();
	cout << t1 << t2 << t3 << endl;
	m.unlock();
}

void PRINT4(string &t1, string &t2, string &t3, string &t4) {
	m.lock();
	cout << t1 << t2 << t3 << t4 << endl;
	m.unlock();
}

void PRINT5(string &t1, string &t2, string &t3, string &t4, string &t5) {
	m.lock();
	cout << t1 << t2 << t3 << t4 << t5 << endl;
	m.unlock();
}
