#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <numeric>
using namespace std;

double mean(double sum, int n){
    double r;
    r = sum/n;
    return r;
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
    double r = mean(sum,n);
    cout << "Sum of data: " << sum << "\n";
    cout << "Mean of data: " << r << "\n";
    return 0;
}
