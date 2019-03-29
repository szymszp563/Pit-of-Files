#include "ControlsScreen.h"



ControlsScreen::ControlsScreen()
{
}

void ControlsScreen::interactiveTextAction(int &gs, int mx, int my)
{
	if (mx >= iT.x &&mx <= iT.x + iT.bx)
		if (my >= iT.y && my <= iT.y + iT.by)
			gs = GameState::TITLE;
}

void ControlsScreen::draw(int mx, int my)
{
	al_draw_bitmap(ctrlsIMAGE, 0, 0, NULL);
	if ((mx >= iT.x &&mx <= iT.x + iT.bx) && (my >= iT.y && my <= iT.y + iT.by))
		al_draw_text(ctrlsFONT, al_map_rgb(0, 255, 255), iT.x, iT.y, NULL, "BACK");
	else
		al_draw_text(ctrlsFONT, al_map_rgb(255, 255, 255), iT.x, iT.y, NULL, "BACK");
}


ControlsScreen::~ControlsScreen()
{
	al_destroy_bitmap(ctrlsIMAGE);
	al_destroy_font(ctrlsFONT);
}
