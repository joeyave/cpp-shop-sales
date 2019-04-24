// ShopSales.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Functions.h"
#include "MergeSort.h"

int main()
{
	char read_path[] = "C:\\Users\\josep\\source\\repos\\c++\\ShopSales\\ShopSales\\TXT files\\readfile.txt";
	char write_path[] = "C:\\Users\\josep\\source\\repos\\c++\\ShopSales\\ShopSales\\TXT files\\writefile.txt";
	char insert_path[] = "C:\\Users\\josep\\source\\repos\\c++\\ShopSales\\ShopSales\\TXT files\\insert_file.txt";

	// Opens file for reading
	std::ifstream read_file(read_path);

	if (!read_file.is_open())
	{
		std::cout << "Wrong path of file doesn't exist.";
		return 1;
	}

	// Opens file for writing
	std::ofstream write_file(write_path, std::ofstream::app);

	if (!write_file.is_open())
	{
		std::cout << "Wrong path of file doesn't exist.";
		return 2;
	}

	// Opens file for writing
	std::ifstream insert_file(insert_path);

	if (!insert_file.is_open())
	{
		std::cout << "Wrong path of file doesn't exist.";
		return 3;
	}

	create_list(read_file);
	MergeSort(&cust_head);
	print_list(write_file, cust_head);

	create_prod_list(cust_head);
	print_prod_list(write_file, prod_head);
	
	destroy(cust_head);
}