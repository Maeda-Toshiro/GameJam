#include "Move.h"
#include<Novice.h>



void Move(Player& player, int blocksize, bool& moveRight, bool& moveLeft, int& leftTopX, int& leftTopY, int& rightTopX, int& rightTopY, int& leftBottomX, int& leftBottomY,
	int& rightBottomX, int& rightBottomY, int& scrool, int& scUp, int& scDown, bool& alive,bool&clear, int map[150][12])
{

	player.velo.y += player.acce.y;



	leftTopY = (int(player.pos.y) - player.radius) / blocksize;
	rightTopY = (int(player.pos.y) - player.radius) / blocksize;
	leftTopX = (int(player.pos.x) - player.radius) / blocksize;
	rightTopX = (int(player.pos.x) - player.radius) / blocksize;
	leftBottomX = (int(player.pos.x) - player.radius-1) / blocksize;
	leftBottomY = (int(player.pos.y) + player.radius - 1) / blocksize;
	rightBottomX = (int(player.pos.x) + player.radius - 1) / blocksize;
	rightBottomY = (int(player.pos.y) + player.radius - 1) / blocksize;

	if (moveRight == true)
	{
		rightTopX = (int(player.pos.x) + player.radius - 1) / blocksize;
		rightTopY = (int(player.pos.y) - player.radius) / blocksize;

		rightBottomX = (int(player.pos.x) + player.radius - 1) / blocksize;
		rightBottomY = (int(player.pos.y) + player.radius - 1) / blocksize;


		if (map[rightTopY][rightTopX] == 0 && map[rightBottomY][rightBottomX] == 0) {
			player.pos.x += player.velo.x;

		}
		if (map[rightTopY][rightTopX] == 4 || map[rightBottomY][rightBottomX] == 4) {
			player.pos.x += player.velo.x;

		}
	}
	//800=960-160aa
	//800=1270-470

	if (moveLeft == true)
	{
		leftTopX = (int(player.pos.x) - player.radius) / blocksize;
		leftTopY = (int(player.pos.y) - player.radius) / blocksize;

		leftBottomX = (int(player.pos.x) - player.radius) / blocksize;
		leftBottomY = (int(player.pos.y) + player.radius - 1) / blocksize;


		if (map[leftTopY][leftTopX] == 0 && map[leftBottomY][leftBottomX] == 0) {
			player.pos.x -= player.velo.x;


		}
		if (map[leftTopY][leftTopX] == 4 || map[leftBottomY][leftBottomX] == 4) {
			player.pos.x -= player.velo.x;


		}

	}


	if (player.pos.y - scrool >= scDown) {
		scrool -= int(player.velo.y);

	}
	if (player.pos.y - scrool <= scUp) {
		scrool += int(player.velo.y);

	}


	



	/*if (map[leftBottomY][leftBottomX] == 1 || map[rightBottomY][rightBottomX] == 1) {
		player.pos.y = float(leftBottomY * blocksize - player.radius);
		player.velo.y = 0;


	}*/
	if (map[leftBottomY][leftBottomX] == 2) {
		
		player.velo.y = 0;
		map[leftBottomY][leftBottomX] = 4;

	}
	if (map[rightBottomY][rightBottomX] == 2) {
		
		player.velo.y = 0;
		map[rightBottomY][rightBottomX] = 4;

	}
	if (map[leftTopY][leftBottomX] == 2 || map[rightTopY][rightBottomX] == 2) {

		player.velo.y = 0;
		alive = false;

	}


	if (map[leftBottomY][leftBottomX] == 3 || map[rightBottomY][rightBottomX] == 3) {

		player.velo.y = 0;
		alive = false;

	}
	if (map[rightTopY][rightTopX] == 3 || map[rightBottomY][rightBottomX] == 3) {
		player.velo.y = 0;
		alive = false;

	}
	if (map[leftTopY][leftTopX] == 3 || map[leftBottomY][leftBottomX] == 3) {
		player.velo.y = 0;
		alive = false;

	}
	if (map[leftTopY][leftBottomX] == 3 || map[rightTopY][rightBottomX] == 3) {
		
		player.velo.y = 0;
		alive = false;
	}

	if (map[leftBottomY][leftBottomX] == 5 || map[rightBottomY][rightBottomX] == 5) {
		player.velo.y = 0;
		clear = true;

	}

	

	if (map[leftTopY][leftBottomX] == 1 ) {
	
		moveLeft = false;
	}

	if ( map[rightTopY][rightBottomX] == 1) {

		moveRight = false;
	}
	player.pos.y += player.velo.y;



}