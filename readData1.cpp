#include "readData1.h"


int main() {

    readData l("sample_data.txt");
    cout<<l.row<<endl;
    cout<<l.N<<endl;
    l.printData();


    return 0;
}
