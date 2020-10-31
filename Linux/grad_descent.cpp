#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <ctime>

#include "Functions.h"


using namespace std;
//using namespace ttmath;

int main()
{
  double start_time = clock();
  int n = 10000;
	LONG alf  =0.001;//originaly is 1
	LONG beta =0.001;//originaly is 1
	LONG gam = 0.999999999999999999999999999;// step for alfa orig 0.5
	vector<LONG>B;
	makeXVec(B);
	vector<LONG>X=B;
	for (int i = 0; i < n; i++) {
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
        cout << "Alfa,beta: " << alf<< endl;
		VecOut(X1);
   
    cout << "Function value on this iteration:" << RosenbrockFunc(X) << endl;
    if (StopQ(X1, U) < 0.000001) {
      cout << "Function is optimized. Here the results:" << endl;
      cout << RosenbrockFunc(U) << endl;
      cout << RosenbrockFunc(X1) << endl;
      VecOut(X1);
      break;
    } else {
		alf = alf * gam;
		beta = beta * gam;
		X = X1;
	}
	 cout << "Iteration number: " <<i<< endl;
  }
  double end_time = clock(); 
  double search_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
  cout <<"Function optimisation time is:"<<search_time << endl;
  return 0;
}
