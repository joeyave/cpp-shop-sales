#pragma once

#include "pch.h"
#include <string>
#include <iostream>
#include <fstream>

// Stuctures
struct Customer
{
	struct
	{
		int customerID;
		int productID;
		std::string productName;
		int productCost;
		int orderNum[4];
	} val;
	Customer* next;
};

struct Sublist
{
	int customerID;
	Sublist* next;
};

struct Product
{
	struct
	{
		int productID;
		Sublist* sub_head;
		int orderNum[4];
		int totalCost;
	} val;
	Product* next;
};

// Global variables
extern Customer* cust_head;
extern Product* prod_head;

// Functions
void cust_create(std::ifstream& in);

void prod_create();

int find_node(int ID);

void delete_node(int ID);

void insert_node(std::ifstream& in);

void cust_destroy();

void prod_destroy();

void console_input(Customer* temp);

void cust_print(std::ofstream& out);

void prod_print(std::ofstream& out);