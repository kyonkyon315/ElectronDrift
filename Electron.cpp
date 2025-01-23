#include "Electron.h"

Electron::Electron(const Coordinate& place,const Velocity& velocity,const Weight& m) {
	this->place = place;
	this->velocity = velocity;
	this->m = m;
}

//Electronの状態を時刻dt進める関数。引数のfは位置と速度を受け取って力を返す関数
void Electron::upDate(std::function< Force(const Coordinate&, const Velocity&) >f, const Time& dt) {
	Force forceNow = f(place, velocity);
	Velocity newVelocity = velocity 
		+ (
			f(place+velocity*dt,velocity+ forceNow / m *dt)

			+ forceNow
		) 
		/ m * dt / 2.;
	Coordinate newPlace = place
		+ (velocity * 2. + forceNow / m  * dt) * dt / 2.;
	//std::cout << forceNow<<"\n";
	velocity = newVelocity;
	place = newPlace;
}
