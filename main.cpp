//
//  main.cpp
//  BST
//
//  Created by Prashanti Pokharel on 10/6/21.
//
#include "Stock.h"
#include "Tree.h"
#include <iostream>
#include <time.h>
#include <fstream>
#include<cstdlib>
#include<ctime>
using namespace std;


int main()
{
    //Question 2
    BinarySearchTree<int> bst;
    srand(time(NULL));
    for (int i=0; i<10; i++)
    {
        int number = rand() % 5000 + 1;
        bst.insert(number);
    }
    cout<<"Inorder: "<<endl;
    bst.inOrder(cout);
    cout<<endl;
    cout<<"Preorder: "<<endl;
    bst.preOrder(cout);
    cout<<endl;
    cout<<"Postorder: "<<endl;
    bst.postOrder(cout);
    cout<<endl;
    bst.height();
    cout<<"The tree height is : "<<bst.height()<<endl;
    bst.destroy();
    cout<<"Tree height after destroying is : " << bst.height()<<endl;
    
    //Question 3

    BinarySearchTree<Stock> stk;
    Stock s;
    string st,
    name,
    symbol,
    array[3];
    int num=0;
    ifstream fin("Stock.txt");
    if (!fin)

    {
        cout<<"Cannot open file"<<endl;
    }
    while (getline(fin, st))
    {
        array[num]=st;
        num++;
        if(num>=3)
        {
            s=Stock(array[0], array[1], stod(array[2]));
            stk.insert(s);
            num=0;
        }
    }
    fin.close();
    char opt=' ';
    char choice=' ';
    string usersymbol, usname, ussymbol;
    double usprice;
    cout<<endl;

    do
    {
        cout << "A - Display a stock's name" << endl;
        cout << "B - Display a stock's price" << endl;
        cout << "C - Remove a stock" << endl;
        cout << "D - Insert a new stock" << endl;
        cout << "E - Display all stocks" << endl;
        cout << "F - Exit" << endl;
        cout<<endl;
        cout << "Input your Choice: "; cin >> choice;

        if (tolower(choice) == 'a')
        {
            cout << "Enter a stock symbol: ";
            cin >> usersymbol;
            Stock searchn("", usersymbol, 0);
            Stock* resultn = stk.search(searchn);
            if (resultn!= nullptr)
            {
                cout << "The name of the Stock is: " << resultn->getName() << ".\n";
            }
            else
            {
                cout << "Stock not found. Enter another symbol";
            }
            cout << endl;
        }
        else if (tolower(choice) == 'b')
        {
            cout << "Enter a stock symbol: ";
            cin >> usersymbol;
            Stock searchp("", usersymbol, 0);
            Stock* resultp = stk.search(searchp);
            if (resultp != nullptr)
            {
                cout << "The price of the Stock is: " << resultp->getPrice() << ".\n";
            }
            else
            {
                cout << "Stock not found. Please input valid stock symbol.\n";
            }
            cout << endl;
        }
        else if (tolower(choice) == 'c')
        {
            cout << "Enter the symbol of stock to remove: ";
            cin >> usersymbol;
            Stock removes("", usersymbol, 0);
            Stock* results = stk.search(removes);
            if (results != nullptr)
            {
                stk.deleteNode(*results);
                cout << "The Stock has been deleted.\n";
            }

        }
        else if (tolower(choice) == 'd')
        {
            cout << "Enter the name for new Stock: "; cin >> usname;
            cout << "\nEnter the symbol for new Stock: ";
            cin >> ussymbol;
            cout << "\nEnter the price for new StockL: ";
            cin >> usprice;
            Stock usstock(usname, ussymbol, usprice);
            stk.insert(usstock);
            cout << "The Stock has been inserted successfully\n";
        }
        else if (tolower(choice) == 'e')
        {
            cout << "The stocks displayed in inorder: \n";
            stk.inOrder(cout);
        }
        else if (tolower(choice) == 'f')
        {
            ofstream fout("saved_stocks.txt", std::ofstream::out);
            stk.inOrder(fout);
            system("cls");
            return 0;
        }
        else
        {
            cout<< "Please choose between (A/B/C/D/E/F)" << endl << "\n\n";
        }
        cout << "Another choice? (Y/N) ";
        cin >> opt;
        system("cls");

    } while ((tolower(opt) != 'y' || tolower(opt) != 'n'));
    system("pause");
    return 0;
}
   
