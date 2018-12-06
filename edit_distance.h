#pragma once

#include "util.h"

using namespace std;

pair<string, double> compare(pair<string, string> dna1, pair<string, string> dna2);
int levenshteinDistance(string s1, string current);

//Creates a vector of pairs of a string (two species) and a double (their
//difference).
//Calls levenshteinDistance to find the distance between two sequences
pair<string, double> compare(pair<string, string> dna1, pair<string, string> dna2) {

  //result holds the two species compared and the distance between them
  pair<string, double> result;
  string species = dna1.first + "-" + dna2.first;
  double distance;
  double percentChange;
  double size;

  //find distance between dna of two species
  distance = levenshteinDistance(dna1.second, dna2.second);

  //convert that distance into a percentage rounded to two decimals
  size = dna1.second.length() + dna2.second.length();
  percentChange = (distance / size) * 100;
  percentChange = round(percentChange * 100) / 100;

  result = make_pair(species, percentChange);

  return result;
}

//calculate the Levenshtein Distance between two strings
//return result as an int
//same as function as levenshteinDistance from text file searching lab
int levenshteinDistance(string s1, string s2) {
  unsigned int deletionCost;
  unsigned int insertionCost;
  unsigned int substitutionCost;
  const size_t len1 = s1.length();
  const size_t len2 = s2.length();

  //create two work vectors with the distance of the string we are comparing
  //s1 to
  vector<unsigned int> prevRow(len2 + 1);
  vector<unsigned int> row(len2 + 1);

  //initialize prevRow (previous row of distances)
  for (unsigned int i = 0; i <= len2; i++)
    prevRow[i] = i;

  for (unsigned int i = 0; i < len1; i++) {

    //calculate row (current row distances) from prevRow
    row[0] = i + 1;

    //fill in row
    for (unsigned int j = 0; j < len2; j++) {

      //calculate costs
      deletionCost = prevRow[j + 1] + 3;
      insertionCost = row[j] + 2;
      if (s1[i] == s2[j])
        substitutionCost = prevRow[j];
      else
        substitutionCost = prevRow[j] + 1;

      row[j + 1] = min(min(deletionCost, insertionCost), substitutionCost);
    }

    //copy row to prevRow for next iteration
    swap(row, prevRow);
  }

  //after last swap, results of row are in prevRow
  return prevRow[len2];
}
