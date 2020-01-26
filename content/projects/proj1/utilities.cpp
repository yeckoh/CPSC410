/*
 * utilities.cpp
 *
 *  Created on: Jan 26, 2020
 *      Author: wc
 */

#include <iostream>
#include <vector>
#include <string.h>
#include <fstream>
#include <sstream>
#include "utilities.h"

using namespace std;

vector<process_stats> myv;

// clear vector and load
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

	auto assign = [](int& process_field, const string& tk) -> void {process_field = stoi(tk);};

	while(getline(fin, line)) {
		stringstream line_stream(line);

		getline(line_stream, token, CHAR_TO_SEARCH_FOR);
		assign(new_process.process_number, token);
		getline(line_stream, token, CHAR_TO_SEARCH_FOR);
		assign(new_process.start_time, token);
		getline(line_stream, token, CHAR_TO_SEARCH_FOR);
		assign(new_process.cpu_time, token);

		myv.push_back(new_process);
	}
	fin.close();
	return SUCCESS;
}


// Create, not Update wrt CRUD
int saveData(const char* filename) {
	ofstream fout(filename, fstream::out);
	if(!fout.is_open())
		return COULD_NOT_OPEN_FILE;

	for(vector<process_stats>::iterator itr = myv.begin();itr != myv.end(); ++itr) {
		fout << itr->process_number << ',' <<
				itr->start_time 	<< ',' <<
				itr->cpu_time 		<< '\n';
	}
	fout.close();
	return SUCCESS;
}




void sortData(SORT_ORDER mySortOrder) {

}

process_stats getNext() {
	process_stats ret = myv.front();
	myv.erase(myv.begin());
	return ret;
}
