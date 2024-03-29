<<<<<<< HEAD
#ifndef Currency_
#define Currency_

#include <iostream>
#include <stdlib.h>

enum sign {plust, minust};
using namespace std;
class Currency {
   public:
      // constructor
      Currency(sign s = plust, unsigned long d = 0,
                              unsigned int c = 0);
      // destructor
      ~Currency() {}
      bool Set(sign s, unsigned long d,
                       unsigned int c);
      bool Set(float a);
      sign Sign() const {return sgn;}
      unsigned long Dollars() const {return dollars;}
      unsigned int Cents() const {return cents;}
      Currency Add(const Currency& x) const;
      Currency& Increment(const Currency& x);
      void Output() const;
   private:
      sign sgn;
      unsigned long dollars;
      unsigned int cents;
};

Currency::Currency(sign s, unsigned long d,
                           unsigned int c)
{// Create a Currency object.
   if (c > 99)
      {// too many cents
       cerr << "Cents should be < 100" << endl;
       exit(1);}
   
   sgn = s; dollars = d; cents = c;
}

bool Currency::Set(sign s, unsigned long d,
                           unsigned int c)
{// Reset value.
   if (c > 99) return false;
   sgn = s; dollars = d; cents = c;
   return true;
}
   
bool Currency::Set(float a)
{// Reset value.
   if (a < 0) {sgn = minust; a = -a;}
   else sgn = plust;
   dollars = a; // extract integer part
   // get two decimal digits
   cents = (a + 0.001 - dollars) * 100;
   return true;
}

Currency Currency::Add(const Currency& x) const
{// Add x and *this.
   long a1, a2, a3;
   Currency ans;
   // convert invoking object to signed integers
   a1 = dollars * 100 + cents;
   if (sgn == minust) a1 = -a1;
   
   // convert x to signed integer
   a2 = x.dollars * 100 + x.cents;
   if (x.sgn == minust) a2 = -a2;
   
   a3 = a1 + a2;
    
   // convert to currency representation
   if (a3 < 0) {ans.sgn = minust; a3 = -a3;}
   else ans.sgn = plust;
   ans.dollars = a3 / 100;
   ans.cents = a3 - ans.dollars * 100;
   
   return ans;
}

Currency& Currency::Increment(const Currency& x)
{// Increment by x.
   *this = Add(x);
   return *this;
}

void Currency::Output() const
{// Output currency value.
   if (sgn == minust) cout << '-';
   cout << '$' << dollars << '.';
   if (cents < 10) cout << "0";
   cout << cents;
}

#endif

=======
#ifndef Currency_
#define Currency_

#include <iostream>
#include <stdlib.h>
using namespace std;

enum sign {plust, minust};

class Currency {
   public:
      // constructor
      Currency(sign s = plust, unsigned long d = 0,
                              unsigned int c = 0);
      // destructor
      ~Currency() {}
      bool Set(sign s, unsigned long d,
                       unsigned int c);
      bool Set(float a);
      sign Sign() const {return sgn;}
      unsigned long Dollars() const {return dollars;}
      unsigned int Cents() const {return cents;}
      Currency Add(const Currency& x) const;
      Currency& Increment(const Currency& x);
      void Output() const;
   private:
      sign sgn;
      unsigned long dollars;
      unsigned int cents;
};

Currency::Currency(sign s, unsigned long d,
                           unsigned int c)
{// Create a Currency object.
   if (c > 99)
      {// too many cents
       cerr << "Cents should be < 100" << endl;
       exit(1);}
   
   sgn = s; dollars = d; cents = c;
}

bool Currency::Set(sign s, unsigned long d,
                           unsigned int c)
{// Reset value.
   if (c > 99) return false;
   sgn = s; dollars = d; cents = c;
   return true;
}
   
bool Currency::Set(float a)
{// Reset value.
   if (a < 0) {sgn = minust; a = -a;}
   else sgn = plust;
   dollars = a; // extract integer part
   // get two decimal digits
   cents = (a + 0.001 - dollars) * 100;
   return true;
}

Currency Currency::Add(const Currency& x) const
{// Add x and *this.
   long a1, a2, a3;
   Currency ans;
   // convert invoking object to signed integers
   a1 = dollars * 100 + cents;
   if (sgn == minust) a1 = -a1;
   
   // convert x to signed integer
   a2 = x.dollars * 100 + x.cents;
   if (x.sgn == minust) a2 = -a2;
   
   a3 = a1 + a2;
    
   // convert to currency representation
   if (a3 < 0) {ans.sgn = minust; a3 = -a3;}
   else ans.sgn = plust;
   ans.dollars = a3 / 100;
   ans.cents = a3 - ans.dollars * 100;
   
   return ans;
}

Currency& Currency::Increment(const Currency& x)
{// Increment by x.
   *this = Add(x);
   return *this;
}

void Currency::Output() const
{// Output currency value.
   if (sgn == minust) cout << '-';
   cout << '$' << dollars << '.';
   if (cents < 10) cout << "0";
   cout << cents;
}

#endif

>>>>>>> cd3738cb7017d9f23b96c8ade88fc93f642ed642
