#include <iostream>
using namespace std;
class Weapons{
   public:
   void weaponsDescription(){
     cout<<"Weapons are used for DESTRUCTION!!!"<<endl;
   }
};

class HotWeapons: public Weapons{
  public:
  void hotWeaponsDescription(){
     cout<<"Hot Weapons uses Gun Powder!!!"<<endl;
   }
};

class Bombs: public HotWeapons{
  public:
  void bombsDescription(){
     cout<<"Bombs blow up!!!"<<endl;
   }
};

class NuclearBombs: public Bombs{
  public:
   void nuclearBombsDescription(){
     cout<<"Nuclear bombs blow up and use nuclear fission and fusion!!!"<<endl;
   }
};

int main() {
   NuclearBombs weapon;
    weapon.weaponsDescription();
    weapon.hotWeaponsDescription();
    weapon.bombsDescription();
    weapon.nuclearBombsDescription();

    return 0;
}