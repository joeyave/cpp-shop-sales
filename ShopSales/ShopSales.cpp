// ShopSales.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Functions.h"
#include "MergeSort.h"

int main()
{
	char read_path[] = "C:\\Users\\josep\\source\\repos\\c++\\ShopSales\\ShopSales\\TXT files\\readfile.txt";

	// Opens file for reading
	std::ifstream read_file(read_path);

	if (!read_file.is_open())
	{
		std::cout << "Wrong path of file doesn't exist.";
		return 1;
	}

	cust_create(read_file);
	MergeSort(&cust_head);
	cust_print();

	prod_create();
	prod_print();
	
	find_max();

	cust_destroy();
	prod_destroy();
}