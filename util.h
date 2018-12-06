#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

string trim_string(string value);
bool is_white_space(char value);
vector<pair<string, string>> readFile();
void printOutput(vector<pair<string, double>> dna, string first);

//trim_string built by TA from past labs
string trim_string(string value) {
	auto start = value.begin();
	auto end = value.rbegin();
	int length = value.length();
	while (is_white_space(*start)) start++;
	while (is_white_space(*end)) { end++; length--; }
	return string(start, start + length);
}

//is_white_space built by TA from past labs
bool is_white_space(char value) {
	return value == '\t' || value == '\n' || value == '\r' || value == '\f' || value == ' ' || value == '-';
}

//read in species and their dna sequenes into a vector of pairs of strings
vector<pair<string, string>> readFile() {
	vector<pair<string, string>> sequences;
	pair<string, string> pair;
	ifstream file;
	string word;
	string dna;
	file.open("dna-samples.txt");

	//if opening "dna-samples.txt" fails, try opening lab12.txt
	if (file.fail())
		file.open("examples.txt");

	//until no more species names exist
	while (getline(file, word)) {
		word = trim_string(word);

		//trim_string does not remove \r correctly for some reason
		word.erase(remove(word.begin(), word.end(), '-'), word.end());
		word.erase(remove(word.begin(), word.end(), '\r'), word.end());
		getline (file, dna, '-');

		//using getline like this does not allow me to use trim_string the way
		//it is meant to be used
		dna.erase(remove(dna.begin(), dna.end(), '\n'), dna.end());
		dna.erase(remove(dna.begin(), dna.end(), '\r'), dna.end());
		pair = make_pair(word, dna);
		sequences.push_back(pair);
	}
	return sequences;
}

//when comparing pairs, use second (int) instead of first
//pulled from -- http://bit.ly/2UkGQGl
bool sortbysec(const pair<string, int> &a, const pair<string, int> &b) {
  return (a.second < b.second);
}

//print out the species pairs and their distance using closest to determine
//which pairs are correct
void printOutput(vector<pair<string, double>> dna, string closest) {
	cout << endl << "Percent Difference Between Species" << endl << endl;
	for (auto i : dna) {
		if (i.first.find(closest) != string::npos)
    	cout << i.first << ": " << i.second << "%" << endl;
	}
	cout << endl;
}
