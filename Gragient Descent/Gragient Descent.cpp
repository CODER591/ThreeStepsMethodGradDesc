// Gragient Descent.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include "../Dependencies/ttmath/ttmath.h"
#include "../Dependencies/ttmath/ttmathbig.h"
using namespace std;
using namespace ttmath;

typedef  double LONG;
//typedef long double LONG;
//typedef Big<1, 200> LONG;
//typedef Big<1, 20> LONG;
//typedef Big<1, 1> LONG;
//typedef Big<1, 50> LONG;

//original in pow 1,50 args
LONG Pow(LONG a,int powr)
{
  LONG tmp = 1;
  for(int i=0;i<powr;i++)
  {
    tmp *=a;
  }
  return tmp;
}
LONG Abs(LONG a)
{
  if (a < 0) {
    return a*(-1);
  }
  else { return a; }
}
template <typename T>//+
void makeXVec(vector<T>&X) 
{
	X.push_back(-1.2);//1
	X.push_back(1);//2
	X.push_back(-1.2);//3
	X.push_back(1);//4
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
LONG RosenbrockFunc(vector<T>&X)
{
  LONG sum = 0;
  /*if(X.size()==2)
  {
    return T(100) * (X[1] - Pow(X[0], 2))*(X[1] - Pow(X[0], 2)) + (1 - X[0])*(1 - X[0]);
  }*/
	for (int i = 1; i <=int(X.size()/2); i++)
	{
		sum += (T(100) * Pow(X[2 * i-1] - Pow(X[(2 * i)-1-1], 2), 2)) + Pow(T(1) - X[(2 * i) - 1-1], 2);
	}
	return sum;
}
template <typename T>//+
void h1(vector<T>&X,vector<T>&H1)
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
void h2(vector<T>&X, vector<T>&H2)
{
	for (int i = 0; i < int(X.size() / 2); i++)
	{
		H2[i] = 0;
	}
	
	for (int i = int(X.size() / 2); i <X.size(); i++)
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

// x^2 + y^2
//only 2 arguments

//
//template <typename T>
//LONG Func(vector<T>&X)
//{
//  return Pow(X[0],2)+Pow(X[1],2);
//}
//template <typename T>//+
//void h1(vector<T>&X,vector<T>&H1)
//{
//      H1[0] = T(2) * X[0];
//    	H1[1] =T(0);
//}
//template <typename T>//+
//void h2(vector<T>&X, vector<T>&H2)
//{
//    	H2[0] = T(0);
//      H2[1] = T(2) *X[1];
//}
template <typename T>//+
void makeU(vector<T>&X,vector<T>&H1,LONG&alfa,vector<T>&U)
{
	for (int i = 0; i < X.size(); i++)
	{
		U[i] = X[i] - T(alfa) * H1[i];
	}
}
template <typename T>//+
void sumTwoVecAndDivOnTwo(vector<T>&X, vector<T>&U,vector<T>&sumoftwo)
{
	for (int i = 0; i < X.size(); i++)
	{
		sumoftwo[i] = (X[i] + U[i]) / T(2);
	}
	
}

template <typename T>//+
void VecOut(vector<T>&A)
{
	for(int i=0;i<A.size();++i)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}

int main()
{
	
  int n = 1000;
	LONG alf  = 1;//originaly is 1
	LONG beta = 1;//originaly is 1
	LONG gam = 0.5;// step for alfa
	vector<LONG>B;
	makeXVec(B);
	vector<LONG>X=B;
  cout << RosenbrockFunc(X);
	for (int i = 0; i < n; i++)
	{
		vector<LONG>H1(X.size());
		h1(X, H1);
		//cout << "H1 in point X:"<< endl;
		//VecOut(H1);
		vector<LONG>U(X.size());
		makeU(X, H1, alf, U);
		//cout << "U vector on " << i << " iteration: " << endl;
		//VecOut(U);//+
		
		//make V vector 
		vector<LONG>V(X.size());
		vector<LONG>SumX_And_U(X.size());
		sumTwoVecAndDivOnTwo(X,U,SumX_And_U);
		vector<LONG>H1_inX_Plus_U(X.size());
		h1(SumX_And_U,H1_inX_Plus_U);
		makeU(X,H1_inX_Plus_U,beta,V);
		//cout << "V vector on " << i << " iteration" << endl;
		//VecOut(V);//+

		//make U1 vector
		vector<LONG>H2_In_V(X.size());
		h2(V,H2_In_V);
		//VecOut(H2_In_V);//+
		vector<LONG>U1(X.size());
		makeU(V,H2_In_V,beta,U1);
		//cout << "U1 vector on " << i << " iteration" << endl;
		//VecOut(U1);//+

		//make X1 vector
		vector<LONG>SumU1_And_V(X.size());
		sumTwoVecAndDivOnTwo(V, U1, SumU1_And_V);
		vector<LONG>H2_In_SumofU1AndV(X.size());
		h2(SumU1_And_V,H2_In_SumofU1AndV);
		vector<LONG>X1(X.size());
		makeU(U1,H2_In_SumofU1AndV,beta,X1);
		cout << "X Next:" << endl;
		VecOut(X1);//+
    //cout <<"func iter ="<< Func(X1) << endl;
    cout << "func iter =" << RosenbrockFunc(X1) << endl;
		if (RosenbrockFunc(U) < RosenbrockFunc(X1)) 
		{
			cout << "good" << endl;
      cout << RosenbrockFunc(U) << endl;
      cout << RosenbrockFunc(X1) << endl;
      VecOut(X1);
			break;
		}
    //if (Func(U) < Func(X1))
    //{
    //  /*cout << "STOP" << endl;
    //  cin.get();*/
    //  if (Abs(Func(U) - Func(X1))<0.000000000001) {
    //    cout << "good" << endl;
    //    //cout << Func(U) << endl;
    //    cout << "func zbig = " << Func(X1) << endl;
    //    cout << endl;
    //    VecOut(X1);
    //    break;
    //  }
    //  else
    //  {
    //    alf = alf * gam;
    //    beta = beta * gam;
    //    X = X1;
    //  }
    //}
		else 
		{ 
			alf = alf * gam;
			beta = beta * gam;
			X = X1;
		}
		//problem in numerical limits computer is too smart to count it
	}


	system("pause");
	return 0;
}
