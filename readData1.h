#ifndef READDATA_H
#define READDATA_H

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <assert.h>

using namespace std;

class readData{
public:

    readData(string filename);
    int row =1000;
    int N = 128;
    vector <vector<double>> dataPointsVec;
    void printData();
};



readData::readData(string filename){


    FILE *pf = fopen(filename.c_str(), "r");
    assert(pf);
    int row = 1000;
    int col = 128;
    for(int i = 0; i<row; i++)
    {
        vector<double> one_line_data(col);
        for(int j = 0; j<col; j++)
        {

           int num = fscanf(pf, "%lf", &one_line_data[j]);
           assert(num == 1);
        }
        if (i == 0)
        {
            printf("%lf %lf\n", one_line_data[0], one_line_data[127]);
        }
        dataPointsVec.push_back(one_line_data);
    }
    fclose(pf);



    /*
	fstream file;
    vector<double> dataPointVec(N);
	// Read file

	file.open(filename, ios::in); // Open file
	if (file.is_open())
	{
		cout << "File correctly opened" << endl;
        while (file.good())
        {
            for (int col=0; col<N; col++) {
                file >> dataPointsVec[row][col]; // fill the row with col elements
            }
            dataPointsVec.push_back(dataPointVec); // add a new row,
            row++; // Keep track of actual row
        }
	}
	else
	{
	   cout << "Unable to open file" << endl;
    }

	file.close();
	*/

}

void readData::printData(){

   double dataPoints[row][N];
   for(int i=0; i<row; i++)
   {
        for(int j=0; j<N; j++)
        {
             dataPoints[i][j]=dataPointsVec[i][j];
            // cout<<"A"<<i<<j<<endl;

        }
   }
 //  cout<<dataPoints[0][0]<<endl;
  cout<<dataPoints[999][0]<<endl;
 //cout<<dataPointsVec.size()<<endl;
 //cout<<dataPointsVec.back()[0]<<endl;

 };


#endif // READDATA_H
