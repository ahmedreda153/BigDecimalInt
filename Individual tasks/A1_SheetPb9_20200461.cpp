#include <iostream>
#include <fstream>
#include <string.h>
#include<algorithm>
using namespace std;



int main()
{
    int  choice;
    string file1, file2;
    ifstream in1, in2;

    cout<<"What you want for your comparison word by word or character by character ?"<<endl;
    cout<<"1 for word by word"<<endl;
    cout<<"2 for character by character"<<endl;
    cin>>choice;
    cin>>file1>>file2;
    if(choice==2)
    {

        in1.open( file1.c_str(), ios::binary );
        in2.open( file2.c_str(), ios::binary );

        if (!in1)
        {
            cout << "Couldn't open the file  " << file1<<endl;
            return 1;
        }

        if (!in2)
        {
            cout << "Couldn't open the file " << file2 << endl;
            return 1;
        }
        // fstream file1("file1.txt"), file2("file2.txt");
        string st1,st2;
        int i;
        i = 0;

        while(!in1.eof() || !in2.eof())
        {
            getline(in1,st1);
            getline(in2,st2);
            i++;
            if(st1!=st2)
            {
                cout << i << " it will not be equal "<< "\n";
                cout << "   " << st1 << "\n";
                cout << "   " << st2 << "\n";
            }
        }
    }
    else if(choice ==1)
    {
        in1.open( file1.c_str(), ios::binary );
        in2.open( file2.c_str(), ios::binary );
        if (!in1)
        {
            cout << "Couldn't open the file  " << file1<<endl;
            return 1;
        }

        if (!in2)
        {
            cout << "Couldn't open the file " << file2 << endl;
            return 1;
        }
        // fstream file1("file1.txt"), file2("file2.txt");
        string st1,st2;
        int i;
        i = 0;

        while(!in1.eof() || !in2.eof())
        {
            in1>>st1;
            in2>>st2;
            if(st1!=st2)
                  {
                cout << " it will not be equal ,the different words are: "<< "\n";
                cout << "   " << st1 << "\n";
                cout << "   " << st2 << "\n";
                return 1;
            }



        }
        cout<<"it's equel"<<endl;

    }

    return 0;
}
