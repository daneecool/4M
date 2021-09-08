#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <numeric>
using namespace std;

int mode(vector<double> data, int n){
    
    int max_count = 1, z = data[0], curr_count = 1;
    for (int i = 1; i < n; i++)
    {
        if (data[i] == data[i-1])
        curr_count++;
        else
        {
            if (curr_count > max_count)
            {
                max_count = curr_count;
                z = data[i-1];
            }
            curr_count = 1;
        }
    }
    if (curr_count > max_count)
    {
        max_count = curr_count;
        z = data[n-1];
    }
    
    return z;
}

int main(int, char**){
    vector<double> data;
    double item;

    string filename;
    cout << "File name: ";
    cin >> filename;
    ifstream f(filename);

    while(f >> item) {
        data.push_back(item);
    }

    double sum = accumulate(data.begin(), data.end(), 0.);
    int n = data.size();
    double z = mode(data,n);
    cout << "Sum of data: " << sum << "\n";
    cout << "Mode: " << z << "\n";
    return 0;
}