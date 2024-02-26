#include "Chess.h"


void Chess::draw(sf::RenderWindow& window) {
	if (alive) {
		sf::Texture pawntexture;
		std::string filename = "data/" + color + "_" + name + ".png";

		pawntexture.loadFromFile(filename);
	
		sf::Sprite pawnsprite;
		pawnsprite.setTexture(pawntexture);
		pawnsprite.setPosition(x * size, y * size);

		pawnsprite.setScale((float)size / 255, (float)size / 255);
		window.draw(pawnsprite);

	}
}

void Chess::setColor(std::string str) {
	if (str == "white" || str == "black") {
		color = str;
	}
}

void Chess::setSize(int sizein) {
	size = sizein;
}

void Chess::setCoords(int xin, int yin) {
	x = xin;
	y = yin;
	if (yin == 6) {
		direction *= -1;
	}
}

void Chess::dead() {
	alive = 0;
}

Chess::ChessStruct Chess::getSetting(){
	return ChessStruct{name, color, x, y, alive};
}

bool Chess::move(Chess* list, int x1, int y1){
	bool flag = 0;
	if (name == "pawn") {
		flag = pawn(list, x1, y1);
	}
	else if (name == "rook") {
		flag = rook(list, x1, y1);
	}
	else if (name == "knight") {
		flag = knight(list, x1, y1);
	}
	else if (name == "bishop") {
		flag = bishop(list, x1, y1);
	}
	else if (name == "queen") {
		flag = queen(list, x1, y1);
	}
	else if (name == "king") {
		flag = king(list, x1, y1);
	}


	if (flag) {
		x = x1;
		y = y1;
	}
	return flag;
}

void Chess::setName(std::string name1) {
	name = name1;
}

bool Chess::pawn(Chess* chees_pieces, int x1, int y1){
	bool flag = 1;
	for (int i = 0; i < 32; i++) {
		if (chees_pieces[i].getSetting().x == x && chees_pieces[i].getSetting().y == y + direction && chees_pieces[i].getSetting().alive) {
			flag = 0;
		}
	}
	if (x != x1) {
		flag = 0;
	}


	if (y + direction != y1) {
		flag = 0;
	}

	std::cout << x1 << x << "\n";
	if ((x1 - 1 == x || x1 + 1 == x) && y + direction == y1) {
		std::cout << 432 << "\n";
		for (int i = 0; i < 32; i++) {
			if (chees_pieces[i].getSetting().x == x1 && chees_pieces[i].getSetting().y == y1 &&
				chees_pieces[i].getSetting().alive && chees_pieces[i].getSetting().color != color) {
				flag = 1;
				chees_pieces[i].dead();
			}
		}
	}
	return flag;
}

bool Chess::rook(Chess* chees_pieces, int x1, int y1) {
	bool flag = 1;
	if (x != x1 && y != y1) {
		flag = 0;
	}
	if (x == x1) {
		int miny = y, maxy = y1;
		if (y > y1) {
			miny = y1;
			maxy = y;
		}
		for (int yp = 0; yp <= maxy - miny; yp++) {
			for (int i = 0; i < 32; i++) {
				if (chees_pieces[i].getSetting().x == x && chees_pieces[i].getSetting().y == miny + yp && 
					chees_pieces[i].getSetting().y != y && chees_pieces[i].getSetting().y != y1 &&
					chees_pieces[i].getSetting().alive) {
					flag = 0;
				}
				
			}
		}
		if (flag) {
			for (int yp = 0; yp <= maxy - miny; yp++) {
				for (int i = 0; i < 32; i++) {
					if (chees_pieces[i].getSetting().x == x1 && chees_pieces[i].getSetting().y == y1 &&
						chees_pieces[i].getSetting().alive) {
						if (chees_pieces[i].getSetting().color != color) {
							chees_pieces[i].dead();
						}
						else {
							flag = 0;
						}
					}
				}
			}
		}
	}
	 else if (y == y1) {
		int minx = x, maxx = x1;
		if (x > x1) {
			minx = x1;
			maxx = x;
		}
		for (int xp = 0; xp <= maxx - minx; xp++) {
			for (int i = 0; i < 32; i++) {
				if (chees_pieces[i].getSetting().x == minx + xp && chees_pieces[i].getSetting().y == y &&
					chees_pieces[i].getSetting().x != x && chees_pieces[i].getSetting().x != x1 &&
					chees_pieces[i].getSetting().alive) {
					flag = 0;
				}
			}
		}
		if (flag) {

			for (int xp = 0; xp <= maxx - minx; xp++) {
				for (int i = 0; i < 32; i++) {
					if (chees_pieces[i].getSetting().x == x1 && chees_pieces[i].getSetting().y == y1 &&
						chees_pieces[i].getSetting().alive) {
						if (chees_pieces[i].getSetting().color != color) {
							chees_pieces[i].dead();
						}
						else {
							flag = 0;
						}
					}
				}
			}
		}
	}
	return flag;
}


bool Chess::knight(Chess* chees_pieces, int x1, int y1) {
	bool flag = 0;
	int minx = x, maxx = x1;
	if (x > x1) {
		minx = x1;
		maxx = x;
	}
	int miny = y, maxy = y1;
	if (y > y1) {
		miny = y1;
		maxy = y;
	}
	int dx = maxx - minx;
	int dy = maxy - miny;
	if (dx == 1 && dy == 2) {
		flag = 1;
	}
	else if (dx == 2 && dy == 1) {
		flag = 1;
	}

	if (flag) {
		for (int xp = 0; xp <= maxx - minx; xp++) {
			for (int i = 0; i < 32; i++) {
				if (chees_pieces[i].getSetting().x == x1 && chees_pieces[i].getSetting().y == y1 &&
					chees_pieces[i].getSetting().alive) {
					if (chees_pieces[i].getSetting().color != color) {
						chees_pieces[i].dead();
					}
					else {
						flag = 0;
					}
				}
			}
		}
	}
	return flag;
}


bool Chess::bishop(Chess* chees_pieces, int x1, int y1) {
	bool flag = 1;
	int minx = x, maxx = x1;
	if (x > x1) {
		minx = x1;
		maxx = x;
	}
	int miny = y, maxy = y1;
	if (y > y1) {
		miny = y1;
		maxy = y;
	}
	int dx = maxx - minx;
	int dy = maxy - miny;
	if (dx != dy) {
		return 0;
	}

	int directionx;
	int directiony;
	directionx = (x1 - x) / abs(x1 - x);
	directiony = (y1 - y) / abs(y1 - y);

	for (int d = 1; d <= dx; d++) {
		for (int i = 0; i < 32; i++) {
			if (chees_pieces[i].getSetting().x == x + d * directionx && chees_pieces[i].getSetting().y == y + d * directiony &&
				chees_pieces[i].getSetting().x != x && chees_pieces[i].getSetting().x != x1 && chees_pieces[i].getSetting().y != y1 &&
				chees_pieces[i].getSetting().alive) {
				return 0;
			}
		}
	}
	if (flag) {
		for (int d = 1; d <= dx; d++) {
			for (int i = 0; i < 32; i++) {
				if (chees_pieces[i].getSetting().x == x1 && chees_pieces[i].getSetting().y == y1 &&
					chees_pieces[i].getSetting().alive) {
					if (chees_pieces[i].getSetting().color != color) {
						chees_pieces[i].dead();
					}
					else {
						flag = 0;
					}
				}
			}
		}
	}

	return flag;
}

bool Chess::queen(Chess* chees_pieces, int x1, int y1) {
	bool flag = 0;
	
	if (rook(chees_pieces, x1, y1)) {
		flag = 1;
	}
	else if (bishop(chees_pieces, x1, y1)) {
		flag = 1;
	}
	return flag;
}

bool Chess::king(Chess* chees_pieces, int x1, int y1) {
	bool flag = 0;
	int dx = abs(x1 - x);
	int dy = abs(y1 - y);
	if (dx <= 1 && dy <= 1) {
		flag = queen(chees_pieces, x1, y1);
	}
	return flag;
}