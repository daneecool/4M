#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <numeric>
using namespace std;

double max(vector<double> data, int n){
    
    double w = 0;
    double t = w + 1;

    // Largest value
    for (int i=0; i<n; i++)
    {
        if (data[i] > w)
        w = data[i];
    }

    return w;
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
    double w = max(data,n);
    cout << "Sum of data: " << sum << "\n";
    cout << "Biggest number: " << w << "\n";
    return 0;
}
