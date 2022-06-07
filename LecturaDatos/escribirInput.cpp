#include <string>
#include <fstream>
#include <vector>
#include <utility> // std::pair

using namespace std;

void write_csv(string filename, vector<pair<string, vector<int>>> dataset){
 
    // Create an output filestream object
    ofstream myFile(filename);
    
    // Send column names to the stream
    for(int j = 0; j < dataset.size(); ++j)
    {
        myFile << dataset.at(j).first;
        if(j != dataset.size() - 1) myFile << ","; // No comma at end of line
    }
    myFile << "\n";
    
    // Send data to the stream
    for(int i = 0; i < dataset.at(0).second.size(); ++i)
    {
        for(int j = 0; j < dataset.size(); ++j)
        {
            myFile << dataset.at(j).second.at(i);
            if(j != dataset.size() - 1) myFile << ","; // No comma at end of line
        }
        myFile << "\n";
    }
    
    // Close the file
    myFile.close();
}

int main() {
    // Make three vectors, each of length 100 filled with 1s, 2s, and 3s
    vector<int> vec1(100, 1);
    vector<int> vec2(100, 2);
    vector<int> vec3(100, 3);
    
    // Wrap into a vector
    vector<pair<string, vector<int>>> vals = {{"One", vec1}, {"Two", vec2}, {"Three", vec3}};
    
    // Write the vector to CSV
    write_csv("three_cols.txt", vals);
    
    return 0;
}