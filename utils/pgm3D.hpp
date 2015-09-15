#include <vector>
using namespace std;

class pgm3D
{
   public:
      pgm3D(string fileName);

   private:
      vector<int> values;
      int l,c,d,max,value;
};
