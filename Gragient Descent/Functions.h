#pragma once
//template <typename T>//-  ?
//void h1(vector<T>&X, vector<T>&H1)
//{
//	for (int i = 0; i < int(X.size() / 2); i++)//i from 0 or 1
//	{
//		if ((i + 1) % 2 == 0)//parne
//		{
//			H1.push_back(100 * 2 * (X[i] - pow(X[i - 1], 2)));
//		}
//		if ((i + 1) % 2 != 0)//ne parne
//		{
//			H1.push_back(-400 * X[i] * (X[i + 1] - pow(X[i], 2)) - 2 * (1 - X[i]));
//		}
//
//	}
//	for (int i = int(X.size() / 2); i < X.size(); i++)// indexes no matter because we need count not indexes
//	{
//		H1.push_back(0);
//	}
//}
//template <typename T>//-
//void h2(vector<T>&X, vector<T>&H2)
//{
//	for (int i = 0; i < int(X.size() / 2); i++)
//	{
//		H2.push_back(0);
//	}
//
//	for (int i = int(X.size() / 2); i < X.size(); i++)
//	{
//		if ((i + 1) % 2 == 0)//parna
//		{
//			H2.push_back(100 * 2 * (X[i] - pow(X[i - 1], 2)));
//		}
//		if ((i + 1) % 2 != 0)//ne parna
//		{
//			H2.push_back(-400 * X[i] * (X[i + 1] - pow(X[i], 2)) - 2 * (1 - X[i]));
//		}
//
//	}
//}
