#pragma once
#include "pch.h"
#include "Functions.h"

void FrontBackSplit(Customer* source, Customer** frontRef, Customer** backRef);
Customer* SortedMerge(Customer* a, Customer* b);
void MergeSort(Customer** headRef);