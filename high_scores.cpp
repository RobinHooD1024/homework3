#include <iostream>
#include <fstream>
#include <string>
#include "high_scores.h"
#include <map>

const std::string high_scores_filename = "high_scores.txt";

void print_hs() {
    std::ifstream in_file{high_scores_filename};
    map <string, int> best_scores;
    if (!in_file.is_open()) {
        std::cout << "Failed to open file for read: " << high_scores_filename << "!" << std::endl;
    }

    std::cout << "High scores table:" << std::endl;

    std::string username;
    int high_score = 0;
    while (true) {
        // Read the username first
        in_file >> username;
        // Read the high score next
        in_file >> high_score;
        if (best_scores.count(username) == 0) {
            best_scores.insert({username, high_score});
        } else {
            if (best_scores.at(username) > high_score) {
                best_scores.at(username) = high_score;
            }
        }
        // Ignore the end of line symbol
        in_file.ignore();
//        scores.insert(std::pair(username, high_score));

        if (in_file.fail()) {
            break;
        }

        // Print the information to the screen
//        std::cout << username << '\t' << high_score << std::endl;

    }
    for (auto x : best_scores) {
      cout << x.first << " " << x.second << endl;
    }

}

void save_and_print_hs(string name, int attempts) {


	// Write new high score to the records table
	{
		// We should open the output file in the append mode - we don't want
		// to erase previous results.
		std::ofstream out_file{high_scores_filename, std::ios_base::app};
		if (!out_file.is_open()) {
			std::cout << "Failed to open file for write: " << high_scores_filename << "!" << std::endl;
		}

		// Append new results to the table:
		out_file << name << ' ';
		out_file << attempts;
		out_file << std::endl;
	} // end of score here just to mark end of the logic block of code

	// Read the high score file and print all results
}