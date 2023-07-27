#include <iostream>
#include <fstream>;

using namespace std;

template <typename T>
class DataHelper 
{
    T data;

public:
    DataHelper(T newdata)
    {
        data = newdata;
    }
    void print()
    {
        cout << data << "\n";
    }

    void printtofile(const char* filename, bool binary = false) 
    {
        if (!binary) 
        {
            fstream myfile(filename, ios_base::out);
            if (myfile.is_open())
            {
                myfile << sizeof(T) << data;
                myfile.close();
            }
            else
            {
                cout << "No se puede abrir l archivo" << "\n";
            }
        }
        else
        {
            fstream myfile(filename, ios_base::out | ios_base::binary);
            if (myfile.is_open())
            {
                myfile << sizeof(T) << data;
                myfile.close();
            }
        }

    }

};

int main()
{
    cout << "Tamanos\n";
    cout << "int : " << sizeof(int) << "\n";
    cout << "float : " << sizeof(float) << "\n";
    cout << "double : " << sizeof(double) << "\n";
    cout << "char : " << sizeof(char) << "\n";
    cout << "string : " << sizeof(string) << "\n";

    DataHelper<char>* mychar = new DataHelper<char>('w');
    DataHelper<float>* myfloat = new DataHelper<float>(3.14159);

    DataHelper<char*>* mychars = new DataHelper<char*>((char*) "Holaaaaa?");

    mychar->print();
    myfloat->print();
    mychars->print();

    myfloat->printtofile("float.txt");
    myfloat->printtofile("float.bin", true);

    //abrir archivo
    fstream archivo("", ios_base::in| ios_base::out);
    if (archivo.is_open())
    {
        char* buffer = new char[8];
        while (!archivo.eof())
        {
            archivo.read(buffer, 8);
            cout << hex << buffer << "\n";
        }
    }

}