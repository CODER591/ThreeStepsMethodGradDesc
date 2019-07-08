#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <ctime>


//#include "../Dependencies/ttmath/ttmath.h"
//#include "../Dependencies/ttmath/ttmathbig.h"


//typedef  double LONG;
typedef long double LONG;
//typedef Big<1, 200> LONG;
//typedef Big<1, 10> LONG;
//typedef Big<1, 3> LONG;
//typedef Big<1, 20> LONG;
//typedef Big<1, 1> LONG;
//typedef Big<1, 50> LONG;

using namespace std;
LONG Pow(LONG a, int powr)
{
  LONG tmp = 1;
  for (int i = 0; i < powr; i++)
  {
    tmp *= a;
  }
  return tmp;
}
LONG Abs(LONG a)
{
  if (a < 0) {
    return a * (-1);
  }
  else { return a; }
}
template <typename T>//+
void makeXVec(vector<T> & X)
{
  X.push_back(-1.2);//1
  X.push_back(1);//2
  //X.push_back(-1.2);//3
  //X.push_back(1);//4
  //X.push_back(-1.2);//5
  //X.push_back(1);//6
  //X.push_back(-1.2);//7
  //X.push_back(1);//8
  //X.push_back(-1.2);//9
  //X.push_back(1);//10
  //X.push_back(-1.2);//11
  //X.push_back(1);//12
  //X.push_back(-1.2);//13
  //X.push_back(1);//14
  //X.push_back(-1.2);//15
  //X.push_back(1);//16
  //X.push_back(-1.2);//17
  //X.push_back(1);//18
  //X.push_back(-1.2);//19
  //X.push_back(1);//20

}
//rosnbrock func driv

template <typename T>//+
LONG RosenbrockFunc(vector<T> & X)
{
  LONG sum = 0;
  /*if(X.size()==2)
  {
    return T(100) * (X[1] - Pow(X[0], 2))*(X[1] - Pow(X[0], 2)) + (1 - X[0])*(1 - X[0]);
  }*/
  for (int i = 1; i <= int(X.size() / 2); i++)
  {
    sum += (T(100) * Pow(X[2 * i - 1] - Pow(X[(2 * i) - 1 - 1], 2), 2)) + Pow(T(1) - X[(2 * i) - 1 - 1], 2);
  }
  return sum;
}
template <typename T>//+
void h1(vector<T> & X, vector<T> & H1)
{
  for (int i = 0; i < int(X.size() / 2); i++)
  {
    if ((i + 1) % 2 == 0)
    {
      H1[i] = T(100 * 2) * (X[i] - Pow(X[i - 1], 2));
    }
    if ((i + 1) % 2 != 0)
    {
      H1[i] = T(-400) * X[i] * (X[i + 1] - Pow(X[i], 2)) - T(2) * (T(1) - X[i]);
    }

  }
  for (int i = int(X.size() / 2); i < X.size(); i++)
  {
    H1[i] = 0;
  }
}
template <typename T>//+
void h2(vector<T> & X, vector<T> & H2)
{
  for (int i = 0; i < int(X.size() / 2); i++)
  {
    H2[i] = 0;
  }

  for (int i = int(X.size() / 2); i < X.size(); i++)
  {
    if ((i + 1) % 2 == 0)//parna
    {
      H2[i] = T(100 * 2) * (X[i] - Pow(X[i - 1], 2));
    }
    if ((i + 1) % 2 != 0)//ne parna
    {
      H2[i] = T(-400) * X[i] * (X[i + 1] - Pow(X[i], 2)) - T(2) * (T(1) - X[i]);
    }

  }
}
template <typename T>//+
void makeU(vector<T>& X, vector<T>& H1, LONG& alfa, vector<T>& U)
{
  for (int i = 0; i < X.size(); i++)
  {
    U[i] = X[i] - T(alfa) * H1[i];
  }
}
template <typename T>//+
void sumTwoVecAndDivOnTwo(vector<T>& X, vector<T>& U, vector<T>& sumoftwo)
{
  for (int i = 0; i < X.size(); i++)
  {
    sumoftwo[i] = (X[i] + U[i]) / T(2);
  }

}

template <typename T>//+
void VecOut(vector<T> & A)
{
  for (int i = 0; i < A.size(); ++i)
  {
    cout << A[i] << " ";
  }
  cout << endl;
}
template <typename T>//+
void FileVecOut(vector<T> & A)
{
  ofstream myfile;
  myfile.open("res.txt");

  for (int i = 0; i < A.size(); ++i)
  {
    myfile << A[i] << " ";
  }
  cout << endl;
  myfile.close();
}

template <typename T>
LONG StopQ(vector<T> & X_1, vector<T> & X_) {
  //norma v neperer difer prostori is max from elements
  //VecX1-VecX2 <eps 
  vector<T>tmp;
  for (int i = 0; i < X_1.size(); ++i) {

    tmp.push_back(Abs(X_1[i] - X_[i]));
  }
  return *std::max_element(tmp.begin(), tmp.end());
}
// x^2 + y^2 in n size case
//template <typename T>
//LONG Func(vector<T>&X)
//{
//  LONG sum = 0;
//  for(int i=0;i<X.size();i++)
//  {
//    sum += Pow(X[i], 2);
//  }
//  return sum;
//}
//template <typename T>//+
//void h1(vector<T>&X,vector<T>&H1)
//{
//  for (int i = 0; i < int(X.size() / 2); i++)
//  {
//    H1[i] = T(2) * X[i]; 
//  }
//  for (int i = int(X.size() / 2); i < X.size(); i++)
//  {
//    H1[i] = 0;
//  }
//}
//template <typename T>//+
//void h2(vector<T>&X, vector<T>&H2)
//{
//  for (int i = 0; i < int(X.size() / 2); i++)
//  {
//    H2[i] = 0;
//  }
//  for (int i = int(X.size() / 2); i < X.size(); i++)
//  {
//    H2[i] = T(2) * X[i];
//  }
//}
