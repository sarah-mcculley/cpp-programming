#pragma once
#include <iostream>
#include <string>

class GunSlinger
{
public:
	std::string Name = "Will Kane";
	GunSlinger(std::string);
	void Shoot(GunSlinger*);
	void ImHit();
	bool getLife();
	//~GunSlinger(void);

private:
	bool lives;
	int shield;
	int health;
};


