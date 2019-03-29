#include "Factory.h"
#include <iostream>
#include <fstream>



Factory::Factory()
{
	killed = al_load_bitmap("killed.png");
}


void Factory::createPlayableObject(PlayableObject &po)
{
	po.init(880, 100, 5, 5, "klatk-big.png", Enums::IDS::PLAYER, 10);
	createCollisions.AddToCollisinList(&po);//dodajê gracza do wektora kolizji
}

void Factory::createEnemyObject(EnemyObject &eo)
{
	eo.init(600, 100, 4, 5, "troll_run_small.png", Enums::IDS::ENEMY, 7);
	createCollisions.AddToCollisinList(&eo);//dodajê gracza do wektora kolizji
}

std::vector<Button*> Factory::createVectorOfButtons(float width, float height)
{
	std::vector<Button*> vb;

	Button *newgame = new Button("newgame.png", (width / 2)-150, height*(1.5 / 6), Enums::FIXED_ID::NEW_GAME);
	vb.push_back(newgame);
	Button *constrols = new Button("controls.png", (width / 2) - 150, height*(2.5 / 6), Enums::FIXED_ID::CONTROLS);
	vb.push_back(constrols);
	Button *exitgame = new Button("exit.png", (width / 2) - 150, height*(3.5 / 6), Enums::FIXED_ID::EXIT);
	vb.push_back(exitgame);

	return vb;
}

std::vector<std::vector<StaticObject*>> Factory::createMap() //tu z pliku stworzymy mapê obiektów statycznych (skrzynki, drabinki, platformy itd)
{
	std::vector<std::vector<StaticObject*>> map;
	std::ifstream file;
	file.open("maptest.txt"); 
	ALLEGRO_BITMAP * platform_image = al_load_bitmap("platform.png"); //tu beda jeszcze nastepne
	ALLEGRO_BITMAP * ladder_image = al_load_bitmap("Ladder3.png");
	al_convert_mask_to_alpha(ladder_image, al_map_rgb(255, 255, 255));
	ALLEGRO_BITMAP * spikes_image = al_load_bitmap("Spikes2.png");
	ALLEGRO_BITMAP * ghost_image = al_load_bitmap("ghost.png");
	al_convert_mask_to_alpha(ghost_image, al_map_rgb(255, 255, 255));
	ALLEGRO_BITMAP * trap_image = al_load_bitmap("danger.png");
	ALLEGRO_BITMAP * chest_image = al_load_bitmap("chest.png");
	ALLEGRO_BITMAP * door_image = al_load_bitmap("images.jpg");
	int size;
	char ch;
	file >> size;

	for (int i = 0; i < 10; i++)
	{
		std::vector<StaticObject*> a;

		for (int j = 0; j < size; j++) //nie wiem czy nie trzeba bedzie pozamieniac w innej petli wierszy z kolumnami bo teraz skacze po pamieci podczas odczytu
		{

			file >> ch;
			StaticObject * so;
			if (ch == '#' || ch == 'E')
			{
				so = new Tile(j * 80, i * 80, 80, 80, Enums::IDS::PLATFORM, platform_image);
			}
			else if (ch == '|')
			{
				so = new Tile(j * 80, i * 80, 80, 80, Enums::IDS::LADDER, ladder_image);
			}
			else if (ch == '@' || ch == '0') // tu sie da jakiegos elsa ale na razie nie ma zbyt duzo udziwniaczy w pliku testowym
			{
				so = new Tile(j * 80, i * 80, 80, 80, Enums::IDS::NTH, NULL);
			}
			else if (ch == 'S')
			{
				so = new Tile(j * 80, i * 80, 80, 80, Enums::IDS::SPIKES, spikes_image);
			}
			else if (ch == 'G')
			{
				so = new Tile(j * 80, i * 80, 80, 80, Enums::IDS::GHOST, ghost_image);
			}
			else if (ch == '-')
			{
				so = new Tile(j * 80, i * 80, 80, 80, Enums::IDS::TRAP, trap_image);
			}
			else if (ch == 'H')
			{
				so = new Tile(j * 80, i * 80, 80, 80, Enums::IDS::CHEST, chest_image);
			}
			else if (ch == 'X')
			{
				so = new Tile(j * 80, i * 80, 80, 80, Enums::IDS::DOOR, door_image);
			}
			a.push_back(so);
			//createCollisions.AddToCollisinList(so);//dodajemy statyczne obiekty do vectora kolizji
		}
		map.push_back(a);
	}
	file.close();
	createCollisions.map1 = map;//doda³em to w collisionsystem, ¿eby mo¿na by³o ³atwo przejrzeæ mapê
	return map;
}
std::list<MovingObject*> Factory::createListOfCollidableObjects()
{
	std::list<MovingObject*> collidableObjects;
	std::ifstream file;
	file.open("maptest.txt");
	int size;
	char ch;
	file >> size;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < size; j++)
		{
			file >> ch;
			//tutaj ify
		}
	}
	file.close();
	return collidableObjects;

	//ruchome platformy itd
}

//Tutaj tworzymy wrogow
std::vector<EnemyObject*> Factory::createVectorOfEnemyObjects(ScoreCounter * sc)
{
	std::vector<EnemyObject*> enemyObjects;
	std::ifstream file;
	file.open("maptest.txt");
	int size;
	char ch;
	file >> size;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < size; j++)
		{
			file >> ch;
			EnemyObject * eo;
			if (ch == 'R')
			{
				eo = new RegularTroll;
				eo->initv2(sc,j * 80, i * 80, 4, 5, "troll_run_small.png", Enums::IDS::ENEMY, 7);
				createCollisions.AddToCollisinList(eo);
				enemyObjects.push_back(eo);
			}
			else if (ch == 'D')
			{
				eo = new RedTroll;
				eo->initv2(sc,j * 80, i * 80, 4, 5, "troll-red.png", Enums::IDS::ENEMY, 7);
				createCollisions.AddToCollisinList(eo);
				enemyObjects.push_back(eo);
			}
			else if (ch == 'O')
			{
				eo = new OrangeTroll;
				eo->initv2(sc,j * 80, i * 80, 4, 5, "troll-orange.png", Enums::IDS::ENEMY, 7);
				createCollisions.AddToCollisinList(eo);
				enemyObjects.push_back(eo);
			}
		}
	}
	file.close();
	return enemyObjects;
}

std::vector<GameItem*> Factory::createVectorOfKeys()
{
	std::vector<GameItem*> keys;
	return keys;

	//tu zgodnie z treœci¹ podstawka.txt stworzymy tabliê kluczy
}
std::vector<GameItem*> Factory::createVectorOfArtifacts()
{
	std::vector<GameItem*> artifacts;
	return artifacts;

	//a tu analogiczn¹ tablicê artefaktów
}
std::vector<Equipment*> Factory::createVectorOfEquipment()
{
	std::vector<Equipment*> equipment;
	return equipment;

	//tu bêdzie ca³y nasz ekwipunek (wczytywany z pliku zapisu stanu gry)
}
Spell* Factory::createSpell(int x, int y, int powerup, int dir, Enums::IDS id)
{
	Spell* spell = new Spell(x, y, powerup, dir, id);
	createCollisions.AddToCollisinList(spell);
	return spell;
}

void Factory::renderKilled()
{
	al_draw_bitmap(killed, 0, 0, 0);
}

Factory::~Factory()
{
}
