#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <numeric>
using namespace std;

double median(vector<double> data, int n){
    double r;

    if(n % 2 == 0)
        r = ((data[n/2] + data[n/2 -1]) / 2);
    else
        r = data[n/2];
    return r;
}

int main(){
    vector<double> data;
    double item;

    string filename;
    cout << "File name: ";
    cin >> filename;
    cout << "\n";
    ifstream f(filename);

    while(f >> item) {
        data.push_back(item);
    }

    double sum = accumulate(data.begin(), data.end(), 0.);
    int n = data.size();
    double r = median(data,n);
    
    cout << "Number of Elements: " << n << "\n";
    cout << "Sum: " << sum << "\n";
    cout << "Median: " << r << "\n\n";
    return 0;
}
