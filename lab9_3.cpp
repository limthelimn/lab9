#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int num = 0;
    float sum = 0;
    string ans;
    ifstream source;
    source.open("score.txt");

    while (getline(source,ans))
        {
            sum += atof(ans.c_str());
            num++;
        }

    cout << "Number of data = " << num << endl << setprecision(3);
    cout << "Mean = " << sum/num << endl;
    source.close();
    source.open("score.txt");
    float mean = sum/num;
    sum = 0;
    num = 0;
    while (getline(source,ans))
        {
            sum += ((atof(ans.c_str())-mean)*(atof(ans.c_str())-mean));
            num++;
        }
    float deviation = sqrt(sum/num);
    cout << "Standard deviation = " << deviation ;
    source.close();
    return 0;
}