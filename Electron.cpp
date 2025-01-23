#include "Electron.h"

Electron::Electron(const Coordinate& place,const Velocity& velocity,const Weight& m) {
	this->place = place;
	this->velocity = velocity;
	this->m = m;
}

//Electron�̏�Ԃ�����dt�i�߂�֐��B������f�͈ʒu�Ƒ��x���󂯎���ė͂�Ԃ��֐�
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
