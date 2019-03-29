#pragma once
#include <vector>
#include <list>
#include "StaticObject.h"
#include "MovingObject.h"
#include "GameItem.h"
#include "Equipment.h"
#include "Tile.h"
#include "Globals.h"
#include "Player.h"
#include "Button.h"
#include "CollisionSystem.h"
#include "CollidableObject.h"
#include "Spell.h"
#include "Enemy.h"
#include "EnemyObject.h"
#include "PlayableObject.h"
#include "RegularTroll.h"
#include "RedTroll.h"
#include "OrangeTroll.h"
#include "ScoreCounter.h"


class Factory
{
	ALLEGRO_BITMAP * killed;
public:
	Factory();

	void createPlayableObject(PlayableObject &po);
	void createEnemyObject(EnemyObject &eo);

	std::vector<std::vector<StaticObject*>> createMap();
	std::list<MovingObject*> createListOfCollidableObjects();
	std::vector<GameItem*> createVectorOfKeys();
	std::vector<GameItem*> createVectorOfArtifacts();
	std::vector<Equipment*> createVectorOfEquipment();
	std::vector<Button*> createVectorOfButtons(float width, float height);
	std::vector<EnemyObject*> createVectorOfEnemyObjects(ScoreCounter * sc);
	Spell* createSpell(int x, int y, int powerup, int dir, Enums::IDS id);
	CollisionSystem createCollisions;//dodajemy kolizje, tzn. dziêki temu bêdziemy dodawaæ obiekty do vektora kolizji //MO¯E NIE POWINNO BYC PUBLIC?
	void renderKilled();
	~Factory();
};

