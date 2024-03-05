// CA1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<iomanip>
#include<stdlib.h>

using namespace std;
int main()
{
	
	int menu, Num[12],sum = 0,small=0,large=0, V, temp;
	double avr = 0, scale;


	
	

	do
	{
		cout << "\t1. ENTER VALUES\n";
		cout << "\t2. DISPLAY\n";
		cout << "\t3. TOTAL\n";
		cout << "\t4. AVERAGE\n";
		cout << "\t5. LARGEST\n";
		cout << "\t6. SMALLEST\n";
		cout << "\t7. OCCURRENCES OF VALUE\n";
		cout << "\t8. SCALE UP\n";
		cout << "\t9. REVERSE\n";
		cout << "\t10. ZERO BASE\n";
		cout << "\t11. Exit\n";

		cin >> menu;

		cout << endl << endl;
		//project done by Dylan O'Shea
		
		switch (menu)
		{
			
		case 1:
			system("CLS");
			cout << "enter 12 integers: " << endl;
			for (int i = 0; i<12; ++i)
			{
				cin >> Num[i];
			}
			cout << endl << endl;
			break;
			
		case 2:
			system("CLS");
			cout << "Entered Values Are: " << endl;
			for (int i=0; i<12; ++i)
			{
				cout << Num[i] << " ";
			}
			cout << endl << endl;
			break;
			system("CLS");
		case 3:
			for (int i = 0; i < 12; ++i)
			{
				sum += Num[i];
				
			}
			cout << "Sum of the Array is: " << sum << endl << endl;
			break;
			system("CLS");
		case 4:
			for (int i = 0; i < 12; ++i)
			{
				avr += Num[i];
				

			}
			avr /= 12;
			cout << "Average of the Array is: " << fixed  << setprecision(2) 
					<< avr << endl << endl;
			break;
			system("CLS");
		case 5:
			for(int i=0; i < 12; ++i)
			{ 
				for (i = 0; i < 12; ++i)
				{
					if (large < Num[i])
						large = Num[i];
				}
			}
			cout << "Displaying largest Element: " << large << endl;
			break;
			system("CLS");
		case 6:
			for (int i = 0; i < 12; ++i)
			{
				for (i = 0; i < 12; ++i)
				{
					if (Num[i] < small)
						small = Num[i];
				}
			}
			cout << "Displaying smallest Element: " << small << endl << endl;
			break;
			system("CLS");
		case 7:
			for (int i = 0; i < 12; i++)
			{
				for (V = i + 1; V < 12; V++)
				{
					if (Num[i] > Num[V])
					{
						temp = Num[i];
						Num[i] = Num[V];
						Num[V] = temp;
					}
				}
			}
			cout << "Ordered Integers are: " << endl << endl;
			for (int i = 0; i < 12; i++)
			{
				cout << Num[i] << " ";
			}
			cout << endl;
			break;
			system("CLS");
		case 8:
			cout << "enter a scale factor (example: 2): ";
			cin >> scale;
			cout << "scaled numbers are: " << endl;
			for (int i = 0; i < 12; ++i)
			{
				Num[i] *= scale;

				cout << Num[i] << " " ;
			}
			cout << endl << endl;
			break;
		
		case 9:
			for (int i = (12 - 1); i >= 0; i--)
			{
				cout << Num[i] << " ";
			}
			cout << endl;
			break;
			
		case 10:
			cout << "all negative numbers split: " << endl;
			for (int i = 0; i < 12; ++i)
			{
				if (Num[i] < 0)
				{
					Num[i] = 0;
				}
				cout << Num[i] << " ";
			}
			break;


		case 11:
			break;


		default:
			cout << "Invalid option" << endl;
		}
	} while (menu != 11);
}

