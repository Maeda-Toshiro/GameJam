#include "Move.h"
#include<Novice.h>



void Move(Player& player, int blocksize, bool& moveRight, bool& moveLeft, int& leftTopX, int& leftTopY, int& rightTopX, int& rightTopY, int& leftBottomX, int& leftBottomY,
	int& rightBottomX, int& rightBottomY, int& scrool, int& scUp, int& scDown, int map[150][12])
{

	player.velo.y += player.acce.y;

	if (moveRight == true)
	{
		rightTopX = (int(player.pos.x) + player.radius - 1 + int(player.velo.x)) / blocksize;
		rightTopY = (int(player.pos.y) - player.radius) / blocksize;

		rightBottomX = (int(player.pos.x) + player.radius - 1 + int(player.velo.x)) / blocksize;
		rightBottomY = (int(player.pos.y) + player.radius - 1) / blocksize;


		if (map[rightTopY][rightTopX] == 0 && map[rightBottomY][rightBottomX] == 0) {
			player.pos.x += player.velo.x;

		}
	}
	//800=960-160aa
	//800=1270-470

	if (moveLeft == true)
	{
		leftTopX = (int(player.pos.x) - player.radius - int(player.velo.x)) / blocksize;
		leftTopY = (int(player.pos.y) - player.radius) / blocksize;

		leftBottomX = (int(player.pos.x) - player.radius - int(player.velo.x)) / blocksize;
		leftBottomY = (int(player.pos.y) + player.radius - 1) / blocksize;


		if (map[leftTopY][leftTopX] == 0 && map[leftBottomY][leftBottomX] == 0) {
			player.pos.x -= player.velo.x;


		}
	}


	if (player.pos.y - scrool >= scDown) {
		scrool -= int(player.velo.y);

	}
	if (player.pos.y - scrool <= scUp) {
		scrool += int(player.velo.y);

	}


	leftBottomX = (int(player.pos.x) - player.radius) / blocksize;
	leftBottomY = (int(player.pos.y) + player.radius - 1 + int(player.velo.y)) / blocksize;
	rightBottomX = (int(player.pos.x) + player.radius - 1) / blocksize;
	rightBottomY = (int(player.pos.y) + player.radius - 1 + int(player.velo.y)) / blocksize;



	if (map[leftBottomY][leftBottomX] == 1 || map[rightBottomY][rightBottomX] == 1) {
		player.pos.y = float(leftBottomY * blocksize - player.radius);
		player.velo.y = 0;


	}



	leftTopY = (int(player.pos.y) - player.radius + int(player.velo.y)) / blocksize;
	rightTopY = (int(player.pos.y) - player.radius + int(player.velo.y)) / blocksize;

	if (map[leftTopY][leftBottomX] == 1 || map[rightTopY][rightBottomX] == 1) {
		player.pos.y = float((leftTopY + 2) * blocksize - player.radius);
		player.velo.y = 0;
	}
	player.pos.y += player.velo.y;


}
