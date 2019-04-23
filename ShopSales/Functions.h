#pragma once

#include "pch.h"
#include <string>
#include <iostream>
#include <fstream>

struct Info
{
	int customerID;
	int productID;
	std::string productName;
	int productCost;
	int orderNum[4];
};

struct Node
{
	Info val;
	Node* next;
};

void create_list(Node* strct, std::ifstream& in);

void print_list(Node* strct, std::ofstream& out);

int find_node(int ID);

void delete_node(Node* strct, int ID);

void insert_node(Node* strct, std::ifstream& in);

void destroy();

void console_input(Node* temp);
