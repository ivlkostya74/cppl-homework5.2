#include "Table.h"
#include <iostream>


int main()
{
   SetConsoleCP(1251);
   SetConsoleOutputCP(1251);

    
    Table <double> T1(8, 8);


    T1.printArr();

    
    T1.Size();

    try
    {
        T1(0, 0) = 3.3;
        T1(1, 1) = 7.4;
        T1(2, 2) = 9.5;
        T1(5, 4) = 10.6;
        T1[5][5] = 99;
        T1[5][6] = 88;

        T1.printArr();

     
        std::cout << T1(1, 1) << "\n";
        std::cout << T1[5][5] << "\n";

    
        Table<double> t1(2, 3);
        Table<double> t2(2, 3);

        
        t2(0, 0) = 23;
        t2(1, 2) =.28;
        t2(1, 1) = 1.2;

        std::cout << "\nОбъект t1\n";
        t1.printArr();

        std::cout << "\nОбъект t2\n";
        t2.printArr();

      
        t1 = t2;

        std::cout << "\nОбъект t1\n";
        t1.printArr();

        std::cout << "\nОбъект t2\n";
        t2.printArr();

        
        Table<double> t3(t1);
        std::cout << "\nОбъект t3\n";
        t3.printArr();
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    };

    
};