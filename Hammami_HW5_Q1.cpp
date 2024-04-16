#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <deque>
#include <string>
#include "MyList.h" 

/*************************************************************************
** Author : Marwa Hammami
** Program : hw5, q1
** Date Created : April 15, 2024
** Date Last Modified : April 15, 2024
** Usage : No command line arguments
**
** Problem:
Accept the following information from the user (keyboard):
- Hw1, hw2 and hw3 (out of 100)
- Midterm (out of 100)
- Final exam (out of 100)
Calculate the total grade out of 100 based on the following grading scale:
Hws --> 30% (10% each)
Midterm --> 30%
Final Exam --> 40%
*************************************************************************/

using namespace std;

// Define a structure to hold a profile with fullname and state
struct Profile {
    string fullname;
    string state;
    
    // Define equality operator to compare profiles
    bool operator==(Profile rhs) {
        return fullname == rhs.fullname;
    }
    
    // Define inequality operator to compare profiles
    bool operator!=(Profile rhs) {
        return fullname != rhs.fullname;
    }
};

// Overload the output stream operator to print Profile objects
ostream& operator<<(ostream &out, Profile &user) {
    out << user.fullname << "--" << user.state;
    return out;
}

// Function to search for a profile in a deque and update its details if found
bool searchDeque(deque<Profile> &dq, Profile &president) {
    for (auto &p : dq) {
        if (p.fullname == president.fullname) {
            president = p; // Update president with found details
            return true;   // Profile found
        }
    }
    return false; // Profile not found
}

int main() {
    queue<Profile> pQueue; // Create a queue to store profiles
    deque<Profile> pDeque; // Create a deque to store profiles
    Profile temp; // Temporary profile variable
    string line; // String to hold each line read from file
    
    // Open the file containing presidents' details
    ifstream file("presidentsWstates.txt");
    if (file.is_open()) {
        // Read each line from the file
        while (getline(file, line)) {
            stringstream ss(line);
            getline(ss, temp.fullname, '\t'); // Read fullname
            getline(ss, temp.state, '\t');    // Read state
            
            // Insert the profile into the queue and deque
            pQueue.push(temp);          // Inserting into queue
            pDeque.push_front(temp);    // Inserting into deque
        }
        file.close(); // Close the file after reading
    } else {
        cerr << "Unable to open the file." << endl; // Display error if file cannot be opened
        return 1; // Exit with error code
    }
    
    // Print queue members using pop and front
    cout << "Printing queue members by using pop and front***********************" << endl;
    while (!pQueue.empty()) {
        cout << pQueue.front() << endl;
        pQueue.pop();
    }

    // Print deque members using iterator
    cout << "Printing deque members with iterator***********************" << endl;
    for (auto iter = pDeque.begin(); iter != pDeque.end(); ++iter) {
        cout << *iter << endl;
    }

    // Print deque members using indices
    cout << "Printing deque members with indices***********************" << endl;
    for (size_t i = 0; i < pDeque.size(); ++i) {
        cout << pDeque[i] << endl;
    }
    
    return 0; // Exit successfully
}
