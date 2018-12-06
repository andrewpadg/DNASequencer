/*
 * Name: Andrew Padgett
 * Date Submitted: 12/06/18
 * Lab Section 04
 * Assignment Name: Lab 12
 */

#pragma once

#include "util.h"
#include "edit_distance.h"

using namespace std;

void process();

void process() {
  vector <pair<string, string>> sequences;
  vector <pair<string, double>> orderedSequences;
  sequences = readFile();

  //loop through the species. j starts at i + 1 to ensure comparisons are not
  //repeated
  for (unsigned int i = 0; i < sequences.size(); i++) {
    for (unsigned int j = i + 1; j < sequences.size(); j++) {
        orderedSequences.push_back(compare(sequences[i], sequences[j]));
    }
  }

  //sort species pairs by the their distance apart.
  sort(orderedSequences.begin(), orderedSequences.end(), sortbysec);

  //the closest two species will always be in the front after sorting.
  //pull the first species from that pair and use to print results
  string closest = orderedSequences[0].first;
  closest = closest.substr(0, closest.find('-'));

  printOutput(orderedSequences, closest);
}
