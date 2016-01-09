//
//  main.cpp
//  OK_Corral
//
//  Created by Sarah McCulley on 12/14/15.
//  Copyright © 2015 Sarah McCulley. All rights reserved.
//



#include "GunSlinger.h"
#include <ctime>
using namespace std;


//implementation section
GunSlinger::GunSlinger(string name)
{
    this->Name = name;
    lives = 1;
    shield = 5;
    health = 5;
}


void GunSlinger::Shoot(GunSlinger* gunman)
{
    ImHit();
}

void GunSlinger::ImHit()
{
    if (shield < 1)
    {
        health -= 1;
        if (health < 1)
        {
            lives -= 1;
        }
        
    }
    else
    {
        shield -=1;
    }
}

bool GunSlinger::getLife()
{
    return lives > 0;
}

int main()
{
    GunSlinger* gunman1 = new GunSlinger("Will Kane");
    GunSlinger* gunman2 = new GunSlinger("Frank Miller");
    srand((unsigned)time(NULL));
    cout << gunman1->Name << " has stepped into the corral." << endl;
    cout << gunman2->Name << " has stepped into the corral." << endl;
    while (gunman1->getLife() && gunman2->getLife())
    {
        if (rand()%2 ==0)
        {
            gunman1->Shoot(gunman2);
            cout << gunman1->Name << " shoots!" << endl;
            cout << gunman2->Name << " says: My protection is giving out." << endl;
        }
        else
        {
            gunman2->Shoot(gunman1);
            cout << gunman2->Name << " shoots!" << endl;
            cout << gunman1->Name << " says: My protection is giving out." << endl;
        }
        sleep(.5);
    }
    
    if (!gunman1->getLife())
    {
       cout <<  gunman1->Name << " is fatally wounded." << endl;
    }
    else
    {
          cout << gunman2->Name << " is fatally wounded." << endl;
    }
   
    cin.get();
    
    return 0;
}
