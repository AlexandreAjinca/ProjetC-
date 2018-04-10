#include <iostream>
#include "CMatrice.h"

using namespace std;

int main()
{
	CMatrice<double> m1(2, 3);
	CMatrice<double> m2(3, 2);
	
	CMatrice<double> m3(2, 2);
	
	int i, j;
	int a = 1;
	for (i = 0; i<m1.getNMATLigne(); i++) {
		for (j = 0; j<m1.getNMATColonne(); j++) {
			m1(i, j) = a;
			m2(j, i) = a;
			a++;

		}
	}

	m3 = m1 * m2;

	m1.MATAffich();
	cout << "mat2 : " << endl;
	m2.MATAffich();
	cout << "mat3 : " << endl;
	m3.MATAffich();

	//CMatrice<double> m3(3, 3);
	// CMatrice<int> m3(2,2) ;
	//(m1+m2).MATAffich() ;
	cout << "\n" << endl;
	//(m1-m2).MATAffich() ;

	//(m1 + m2).MATAffich();
	//m1.MATAffich();
	cout << "HELLO" << endl;
	//(m1.MATTranspos()).MATAffich();
	//(m2 * 2).MATAffich();
	//double a = (m2*2)(1,1);
	//cout << a << endl;

	return 0;
}
