#pragma once
#include "GameObject.h"

class Collidable//KLASA KTÓR¥ Z KTÓREJ DZIEDZICZ¥ WSZYSTKIE OBIEKTY, KTÓRE BÊDÊ MIA£Y KOLIZJE --- DODATKOWE DZIEDZICZENIE, NIE MA PROBLEMU PRZY KONSTRUKTORZE, BO NIE MA ¯ADYCH WARTOŒCI!
{
public:
	virtual float GetPosX() = 0;//dodane w klasach, które maj¹ mieæ kolizje  <-- pó¿niej siê usunie albo z gameobject getx albo tutaj siê to wykorzysta, zobaczy siê co lepsze
	virtual float GetPosY() = 0;//dodane w klasach, które maj¹ mieæ kolizje 
	virtual float getBoundX() = 0;
	virtual float getBoundY() = 0;
	virtual int IDnum() = 0;//dodane w klasach, które maj¹ mieæ kolizje 
	//virtual float GetSize() = 0;//mo¿e siê przyda, a mo¿e nie
	virtual void ProcessCollision(Collidable* otherObject) = 0;//dodane w klasach, które maj¹ mieæ kolizje <--- tutaj wchodzimy w momencie, kiedy chcemy sprawdziæ, czy wyst¹pi³a jakaœ kolizja
	//póki co doda³em to na razie tylko do ruchu w lewo w source, ale powinno siê wykonywaæ w ka¿dej chwili, nie tylko dla ruchu (bo strza³y, inne potworki odbijaj¹ce siê od œcian itp..)
	//grunt, ¿eby zaczê³o dzia³aæ chocia¿ dla ruchu w lewo, to ju¿ potem to zajebiœcie zrobiê :>
	virtual void kill() = 0;
	virtual ~Collidable() {}//wirtualny destruktor, bo s¹ funkcje virtual
};
