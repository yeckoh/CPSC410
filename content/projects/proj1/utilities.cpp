/*
 * utilities.cpp
 *
 *  Created on: Jan 26, 2020
 *  Author: wchang 00960978
 *  prof: K. Perkins @ CNU
 *  assignment: SP20-CS410: p1
 */

#include <vector>
#include <algorithm>
#include <string.h>
#include <fstream>
#include <sstream>
#include "utilities.h"

using namespace std;

vector<process_stats> myv;

// clear list container and load file data into the list.
int loadData(const char* filename) {
	myv.clear();
	ifstream fin(filename, fstream::in);

	if(!fin.is_open())
		return COULD_NOT_OPEN_FILE;
	if(fin.peek() == ifstream::traits_type::eof()) {
		fin.close();
		return COULD_NOT_READ_FILE;
	}

	string line = "";
	string token = "";
	process_stats new_process;
	auto assign = [&](int& process_field) -> void {process_field = stoi(token);};

	while(getline(fin, line)) {
		stringstream line_stream(line);
		getline(line_stream, token, CHAR_TO_SEARCH_FOR);
		assign(new_process.process_number);
		getline(line_stream, token, CHAR_TO_SEARCH_FOR);
		assign(new_process.start_time);
		getline(line_stream, token, CHAR_TO_SEARCH_FOR);
		assign(new_process.cpu_time);
		myv.push_back(new_process);
	} // endof.while
	fin.close();
	return SUCCESS;
}


// save list data to a file, overwriting if one already exists.
int saveData(const char* filename) {
	ofstream fout(filename, fstream::out);
	if(!fout.is_open())
		return COULD_NOT_OPEN_FILE;

	for(vector<process_stats>::iterator itr = myv.begin();itr != myv.end(); ++itr) {
		fout << itr->process_number << ',' <<
				itr->start_time 	<< ',' <<
				itr->cpu_time 		<< '\n';
	} // endof.for
	fout.close();
	return SUCCESS;
}

// sort the vector data. std::sort(start, end, lambda)
void sortData(SORT_ORDER mySortOrder) {
	switch(mySortOrder) {
	case SORT_ORDER::CPU_TIME:
		std::sort(myv.begin(), myv.end(), [](const process_stats& l, const process_stats& r) {return l.cpu_time < r.cpu_time;});
	break;
	case SORT_ORDER::PROCESS_NUMBER:
		std::sort(myv.begin(), myv.end(), [](process_stats l, process_stats r) {return l.process_number < r.process_number;});
	break;
	case SORT_ORDER::START_TIME:
		std::sort(myv.begin(), myv.end(), [](process_stats l, process_stats r) {return l.start_time < r.start_time;});
	} // endof.switch
}

// return the first element in the list while removing it from the list.
process_stats getNext() {
	process_stats ret = myv.front();
	myv.erase(myv.begin());
	return ret;
}
