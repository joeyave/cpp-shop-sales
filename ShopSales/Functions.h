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

void cust_destroy();

void prod_destroy();

void cust_print();

void prod_print();

int find_max();