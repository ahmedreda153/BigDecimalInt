#include <iostream>
#include <string>
#include<iomanip>

using namespace std;

int main()
{
    string str;
    getline(cin, str);
    cout << "Original text: " << str;
    for (int j = 0; j < (int)str.size(); j++)
    {
        string he = str.substr(j,2);
        string him = str.substr(j,3);

        if (he == "he") //he is sad //he is here he
        {
            if (j==0 &&str[j+2]==' ' )
            {
                str= str.substr(0,j)+"he or she"+str.substr(j+2);
                j+=7;
            }
            if(str[j-1]==' ' && j+2==(int)str.size())
            {
                str= str.substr(0,j)+"he or she"+str.substr(j+2);
                j+=7;
            }
            if(j>0&& j+2<(int)str.size())

            {
                if(str[j-1]==' '&&str[j+2]==' ')

                {
                    str= str.substr(0,j)+"he or she"+str.substr(j+2);
                    j+=7;
                }


            }

        }


 if (him == "him") //he is sad //he is here he
        {
            if (j==0 &&str[j+3]==' ' )
            {
                str= str.substr(0,j)+"him or her"+str.substr(j+3);
                j+=7;
            }
            if(str[j-1]==' ' && j+3==(int)str.size())
            {
                str= str.substr(0,j)+"him or her"+str.substr(j+3);
                j+=7;
            }
            if(j>0&& j+2<(int)str.size())

            {
                if(str[j-1]==' '&&str[j+3]==' ')

                {
                    str= str.substr(0,j)+"him or her"+str.substr(j+3);
                    j+=7;
                }


            }

        }
        if (he == "He") //he is sad //he is here he
        {
            if (j==0 &&str[j+2]==' ' )
            {
                str= str.substr(0,j)+"He or she"+str.substr(j+2);
                j+=7;
            }
            if(str[j-1]==' ' && j+2==(int)str.size())
            {
                str= str.substr(0,j)+"He or she"+str.substr(j+2);
                j+=7;
            }
            if(j>0&& j+2<(int)str.size())

            {
                if(str[j-1]==' '&&str[j+2]==' ')

                {
                    str= str.substr(0,j)+"He or she"+str.substr(j+2);
                    j+=7;
                }


            }

        }


 if (him == "Him") //he is sad //he is here he
        {
            if (j==0 &&str[j+3]==' ' )
            {
                str= str.substr(0,j)+"Him or her"+str.substr(j+3);
                j+=7;
            }
            if(str[j-1]==' ' && j+3==(int)str.size())
            {
                str= str.substr(0,j)+"Him or her"+str.substr(j+3);
                j+=7;
            }
            if(j>0&& j+2<(int)str.size())

            {
                if(str[j-1]==' '&&str[j+3]==' ')

                {
                    str= str.substr(0,j)+"Him or her"+str.substr(j+3);
                    j+=7;
                }


            }

        }


    }

    cout <<"\nNew text: " << str << endl;

    return 0;
}