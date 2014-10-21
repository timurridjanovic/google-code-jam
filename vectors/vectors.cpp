

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>
using namespace std;

vector<int> sort_vect(string v1, bool reverse) {
    
    vector<int> vector;
    string n = "";
    for (int i = 0; i < v1.length(); i++) {
        if (v1[i] != ' ') {
            n+=v1[i];
        } else {
            int num = atoi(n.c_str());
            vector.push_back(num);
            n = "";
        }
    }
    int num = atoi(n.c_str());
    vector.push_back(num);
    if (reverse) {
        sort(vector.rbegin(), vector.rend());
    } else {
        sort(vector.begin(), vector.end());
    }
    return vector;
}

long int handle_vectors(string v1, string v2, string n) {
    vector<int> vec1 = sort_vect(v1, false);
    vector<int> vec2 = sort_vect(v2, true);

    long int product = 0;

    for (int i = 0; i < vec1.size(); i++) {
        product += (long int) vec1[i] * (long int) vec2[i];
    }
    return product;
}

void write_to_file(long int product, int test_case) {
    ofstream file("result_vectors_large_cpp.txt", ios::out | ios::app);
    if (file.is_open()) {
        file << "Case #" << test_case << ": " << product << "\n";
        file.close();
    }
}

void open_file(string file_name) {
    ifstream file(file_name.c_str());
    if (file.is_open()) {
        string num_test_cases;
        getline(file, num_test_cases);

        string line;
        int test_case = 1;
        while (getline(file, line)) {
            string n = line;
            string v1;
            string v2;
            getline(file, v1);
            getline(file, v2);
            
            long int product = handle_vectors(v1, v2, n);
            write_to_file(product, test_case);
            test_case += 1;
        }
        file.close();
        cout << "file created" << endl;
    }
}

int main() {
    open_file("A-large-practice.in");
    return 0;
}
