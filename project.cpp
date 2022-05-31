#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;

struct vowels
{
    char line[150];
    int vowels , consonants , digits , spaces ,even,odd ,symbols = 0;

    void getData();
    void displayData();
    void filing();
}v;

void vowels::getData()
{
        cout << "Enter a line of string: ";
    cin.getline(v.line, 150);
    for(int i = 0; v.line[i]!='\0'; ++i)
    {
        if(v.line[i]=='a' || v.line[i]=='e' || v.line[i]=='i' ||
           v.line[i]=='o' || v.line[i]=='u' || v.line[i]=='A' ||
           v.line[i]=='E' || v.line[i]=='I' || v.line[i]=='O' ||
           v.line[i]=='U')
        {
            ++v.vowels;
        }
        else if((v.line[i]>='a'&& v.line[i]<='z') || (v.line[i]>='A'&& v.line[i]<='Z'))
        {
            ++v.consonants;
        }
        else if(v.line[i]>='0' && v.line[i]<='9')
        {
            ++v.digits;

         if (v.line[i] % 2==0 )
         	++v.even;
		 else
		    ++v.odd;
        }
        else if (v.line[i]==' ')
        {
            ++v.spaces;
        }
        else
        ++v.symbols;
    }
}

void vowels::displayData()
{
    cout << endl << "\t\tOUTPUT" << endl;
    cout << "Vowels: " << v.vowels << endl;
    cout << "Consonants: " << v.consonants << endl;
    cout << "Digits: " << v.digits << endl;
    cout << "White spaces: " << v.spaces << endl;
    cout << "Even No: " << v.even << endl;
    cout << "Odd No: " << v.odd << endl;
	cout << "Symbols: " << v.symbols << endl;
}

void vowels::filing()
{
    ofstream File;
    File.open( "file.data" , ios::binary | ios::out | ios::app);
    v.getData();
    File.write(( char* ) &v , sizeof(v) );
    File.close();
    cout << endl << "STRING DATA HAS BEEN SAVED IN FILE" << endl << endl;
}


int main()
{
    vowels obj1;

    obj1.filing();
    obj1.displayData();

    return 0;
}
