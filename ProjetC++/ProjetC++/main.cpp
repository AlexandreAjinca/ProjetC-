#include <iostream>
#include "CMatrice.h"

using namespace std;

int main()
{
	CMatrice<double> m1(2, 3);
	CMatrice<double> m2(3, 3);

	//CMatrice<int> m3(2,2) = m1+m2 ;
	int i, j;
	int a = 1;
	for (i = 0; i<2; i++) {
		for (j = 0; j<3; j++) {
			m1(i, j) = a;
			a++;
			//m2(i, j) = 2;
			//cout << m1(i,j)+m2(i,j) << endl;
		}
	}
	CMatrice<double> m3(3, 3);
	// CMatrice<int> m3(2,2) ;
	//(m1+m2).MATAffich() ;
	cout << "\n" << endl;
	//(m1-m2).MATAffich() ;

	//(m1 + m2).MATAffich();
	m1.MATAffich();
	cout << "HELLO" << endl;
	(m1.MATTranspos()).MATAffich();
	//(m2 * 2).MATAffich();
	//double a = (m2*2)(1,1);
	//cout << a << endl;

	return 0;
}
