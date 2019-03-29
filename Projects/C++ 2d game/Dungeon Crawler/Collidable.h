#pragma once
#include "GameObject.h"

class Collidable//KLASA KT�R� Z KT�REJ DZIEDZICZ� WSZYSTKIE OBIEKTY, KT�RE B�D� MIA�Y KOLIZJE --- DODATKOWE DZIEDZICZENIE, NIE MA PROBLEMU PRZY KONSTRUKTORZE, BO NIE MA �ADYCH WARTO�CI!
{
public:
	virtual float GetPosX() = 0;//dodane w klasach, kt�re maj� mie� kolizje  <-- p�niej si� usunie albo z gameobject getx albo tutaj si� to wykorzysta, zobaczy si� co lepsze
	virtual float GetPosY() = 0;//dodane w klasach, kt�re maj� mie� kolizje 
	virtual float getBoundX() = 0;
	virtual float getBoundY() = 0;
	virtual int IDnum() = 0;//dodane w klasach, kt�re maj� mie� kolizje 
	//virtual float GetSize() = 0;//mo�e si� przyda, a mo�e nie
	virtual void ProcessCollision(Collidable* otherObject) = 0;//dodane w klasach, kt�re maj� mie� kolizje <--- tutaj wchodzimy w momencie, kiedy chcemy sprawdzi�, czy wyst�pi�a jaka� kolizja
	//p�ki co doda�em to na razie tylko do ruchu w lewo w source, ale powinno si� wykonywa� w ka�dej chwili, nie tylko dla ruchu (bo strza�y, inne potworki odbijaj�ce si� od �cian itp..)
	//grunt, �eby zacz�o dzia�a� chocia� dla ruchu w lewo, to ju� potem to zajebi�cie zrobi� :>
	virtual void kill() = 0;
	virtual ~Collidable() {}//wirtualny destruktor, bo s� funkcje virtual
};
