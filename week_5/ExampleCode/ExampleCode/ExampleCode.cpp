/*
* script: ExampleCode.cpp
* action: This program demonstrates problem 8 from page 1574
* author: D.M
* date: 05JUL25
*/

#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> intList;
    int i;

    /* This loop calculates the values in this manner
	* i = 0: 0* (0 + 1) = 0
	* i = 1: 1 * (1 + 1) = 2
	* i = 2: 2 * (2 + 1) = 6
	* i = 3: 3 * (3 + 1) = 12
	* i = 4: 4 * (4 + 1) = 20
    */
    for (i = 0; i < 5; i++)
        intList.push_back(i * (i + 1));

    // This loop will out the results of the previous list
    // 0 2 6 12 20
    for (auto p : intList)
        cout << p << " ";
    cout << endl;

}


