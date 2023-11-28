#include "BigReal.h"
#include <bits/stdc++.h>
using namespace std;




int main() {

    BigReal i("100.5"),j("99.99");
    cout << (i > j) << endl;


    // test cases of doctor
    BigReal n1 ("11.9000000000000000000000000000000001");
    BigReal n2 ("2333333333339.1134322222222292");
    BigReal n3 = n1 + n2;
    cout << n3 << '\n';


    // testing all kind of numbers initializing
    BigReal b1("+.2"),b2("0.55"),b3("-.03"),b4(0.55);
    cout << b1  << " "<< b2+b3  << " " <<b3 <<" " << b4 << '\n';

    // testing huge numbers
    BigReal a1("1589.000458600"),a2("-1000.89752");
    cout << "First number is " << a1 << '\n';
    cout << "Second number is " << a2 << '\n';
    cout <<"x + y = " << a1 + a2 <<'\n' << "x - y = " << a1 - a2 << '\n';

    // testing < and > operators
    BigReal c1("1000.1"),c2("1000.2"),c3("-1000.05"),c4("-1000.06"), c5("1.99");
    cout << (c1 > c2) << '\n'; //false
    cout << (c1 < c2) << '\n'; //true
    cout << (c3 > c4) << '\n'; //true
    cout << (c1 > c4) << '\n'; //true
    cout << (c2 < c5) << '\n'; //false

    BigReal d1("0.55"),d2(0.05);
    cout << (d1 > d2) <<'\n'; //true

    // testing + and -
    BigReal e1("89.00000005"),e2("89.00000009"),e3("-89.00000005"),e4("-89");
    cout << (e1 + e2) <<'\n';
    cout << (e1 + e3) <<'\n';
    cout << (e1 + e4) <<'\n';

    BigReal f1("-99.99"),f2("-99.99"),f3("-53.0"),f4(90),f5("80.8");
    cout << (f1 + f2) <<'\n';
    cout << (f1 - f2) <<'\n';
    cout << (f3 + f5) <<'\n';
    cout << (f5 - f4) <<'\n';



     //testing contructor
    BigReal gg("0005");
    cout << gg << '\n';

    BigReal k("1800000000"),l("-789996541232585000.4444");

    cout << (k - l) << '\n';

    BigReal RR("0.99"), RR2("0.9900");
    cout << (RR == RR2) << '\n';

    return 0;
}
