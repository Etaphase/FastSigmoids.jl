function generate_testfile(io::IO)
  write(io, """
  #include <numeric>
  #include <iostream>
  #include <vector>
  #include <stdlib.h>
  #include "./include/P32e2.h"   // <== 32 bit posit, exponent 2

  using namespace std;

  void initializevector(vector <float> &fv){
    for (int idx = 0; idx < 4; ++idx){
      fv[idx] = ((float) rand()) / ((float) RAND_MAX);  // warning, requires posix standard.
    }
  }

  //transfertoposit iterates over the floating point vector and converts it to
  //a vector of P32e2 objects.

  void transfertoposit(vector <P32e2> &pv, vector <float> &fv){
    for (int idx = 0; idx < 4; ++idx){
      pv[idx] = (P32e2) fv[idx];                       //note the very simple type coercion operator
    }
  }

  //positdotproduct performs a dot product on two <P32e2> vectors, but you could
  //have written this as STL paramaterized function like the STL inner product itself is.

  P32e2 positdotproduct(vector <P32e2> &pv1, vector <P32e2> &pv2){

    //just use the STL dot product.  Since the + and * operators are overloaded
    //this works just fine with no modification.

  }

  // a utility function to print out float vectors.
  void describevector(vector <float> &fv, char const * label){
    cout << label << ": < ";
    for (int idx=0; idx < 4; ++idx){
      cout << fv[idx] << " ";
    }
    cout << "> \\n";
  }

  int main(){

    //don't hesitate to allocate these guys on the stack.  A P32e2 object should
    //only take 32 bits of space, just like a standard float.  There's no extra
    //spinach in the objects, and certainly no virtual functions to create
    //overhead.

    P32e2 v1 = (P32e2) 1.5;
    P32e2 v2 = (P32e2) -1.25;

    // basic type coercion to and from  both float AND for screen or file output
    // you really should really do these conversions.  Another possibility is
    // to output as hexadecimal using your favorite int to hexstring utility and
    // accessing the .data public member data.

    cout << "v1(dec): " << (double) v1 << endl;
    cout << "v2(dec): " << (double) v2 << endl;
    cout << "v1(hex): " << hex << v1.data << endl;
    cout << "v2(hex): " << hex << v2.data << endl;

    //the expected arithmetic operations are implemented.  See README.md for more
    //details.

    cout << "v1 + v2:" << (float) (v1 + v2) << endl;
    cout << "v1 - v2:" << (float) (v1 - v2) << endl;
    cout << "v1 * v2:" << (float) (v1 * v2) << endl;
    cout << "v1 / v2:" << (float) (v1 / v2) << endl;
    cout << "sqrt(v1)" << (float) sqrt(v1)  << endl;


    //allocate, on the stack two float vectors and enough space for the corresponding
    //posit versions.

    vector <float> f1(4);
    vector <float> f2(4);

    vector <P32e2> p1(4);
    vector <P32e2> p2(4);

    //fill them with "random" values.

    initializevector(f1);
    initializevector(f2);

    //print them out.

    describevector(f1, "first  vector: ");
    describevector(f2, "second vector: ");

    //convert to posit.

    transfertoposit(p1, f1);
    transfertoposit(p2, f2);

    // calculate the dot product using the STL library.
    // requires #include<numeric>
    //
    //   the STL inner_product(...) functions guarantee results if addition
    //   and multiplication operatiors have been defined on the templated type.

    P32e2 res = inner_product(p1.begin(), p1.end(), p2.begin(), (P32e2) 0.0);

    cout << "result scalar: " << (float) res << '\\n';

    return 0;
  }

  """)
end
