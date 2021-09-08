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

    string file1,file2;
    
    //Input data file
    cout << "Input file name: ";
    cin >> file1;
    ifstream fin(file1);
    ofstream fout(file2);

    while(fin >> item) 
    {
        data.push_back(item);
    }
    fin.close();
    
    //Sort data file to another textfile
    cout << "Output file name: ";
    cin >> file2;
    fout.open(file2);

    double i,j,first,element;
    int n = data.size();

    for(i=n-1; i>0; i--)
    {
        first = 0;
        for(j=1; j<=i; j++)
        {
            if(data[j] > data[first])
            first = j;
        }
        //<Uncomment following three lines to sort data file in ascending order>
        //element = data[first];
        //data[first] = data[i];
        //data[i] = element;
    }

    for(double i=0; i<n; i++)
    {
        fout << data[i] << " " << "\n";
    }
    fout.close();

    double sum = accumulate(data.begin(), data.end(), 0.);
    double r = median(data,n);

    cout << "Number of Elements: " << n << "\n";
    cout << "Sum: " << sum << "\n";
    cout << "Median: " << r << "\n";
    return 0;
}