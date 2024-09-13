#include <Novice.h>
#include"Player.h"
#include"Move.h"
#include<math.h>
#define _USE_MATH_DEFINES

const char kWindowTitle[] = "";

const int kWindowWidth = 768;
const int kWindowHeight = 768;

enum Scene {
	TITLE,

	PLAY,
	GAMEOVER,
	CLEAR
};



// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

	int titlesp = Novice::LoadTexture("./images/title.png");
	int clearsp = Novice::LoadTexture("./images/clear.png");
	int playersp = Novice::LoadTexture("./images/player.png");
	int gameoversp = Novice::LoadTexture("./images/gameover.png");

	int blocksp = Novice::LoadTexture("./images/block.png");
	int enemysp = Novice::LoadTexture("./images/em1.png");


	bool moveRight = false;
	bool moveLeft = false;
	bool alive = true;
	bool clear = false;




	Scene scene = TITLE;

	Player player{
		{355,96},
		{6,0},
		{0,0.1f},
		32,
	};


	const int blocksize = 64;

	int map[150][12] = {//マップチップ
  {1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,2,0,0,0,0,0,0,2,0,1},
  {1,0,0,0,0,5,0,0,0,0,0,1},
  {1,3,0,0,2,0,0,2,0,0,3,1},
  {1,0,0,3,0,0,0,0,3,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,3,3,0,0,0,0,1},
  {1,0,0,0,3,0,0,3,0,0,0,1},
  {1,0,0,2,0,0,0,0,2,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,3,0,0,0,0,0,0,3,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1},
	};
	//プレイヤーの四つ角
	int leftTopX = (int(player.pos.x) - player.radius) / blocksize;//左上のマップ番号X
	int leftTopY = (int(player.pos.y) - player.radius) / blocksize;//左上のマップ番号Y

	int leftBottomX = (int(player.pos.x) - player.radius) / blocksize;//左下のマップ番号X
	int leftBottomY = (int(player.pos.y) + player.radius - 1) / blocksize;//左下のマップ番号Y

	int rightTopX = (int(player.pos.x) + player.radius - 1) / blocksize;//右上のマップ番号X
	int rightTopY = (int(player.pos.y) - player.radius) / blocksize;//右上のマップ番号Y

	int rightBottomX = (int(player.pos.x) + player.radius - 1) / blocksize;//右下のマップ番号X
	int rightBottomY = (int(player.pos.y) + player.radius - 1) / blocksize;//右下のマップ番号Y
	//



	int scrool = 0;
	int scUp = 600;
	int scDown = 550;


	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		switch (scene)
		{
		case TITLE:

			if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
				scene = PLAY;
			}

			break;

		case PLAY:



			moveRight = false;
			moveLeft = false;

			if (keys[DIK_D])//Dが押されたら
			{
				moveRight = true;
			}

			if (keys[DIK_A])//Dが押されたら
			{
				moveLeft = true;
			}
			//
			if (keys[DIK_W])//Dが押されたら
			{
				player.pos.y -= 6;
			}

			if (keys[DIK_S])//Dが押されたら
			{
				player.pos.y += 6;
			}
			//
			if (keys[DIK_R] && !preKeys[DIK_R]) {
				alive = true;
				player.pos.x = 96;
				player.pos.y = 96;
				scrool = 0;

			}

			




			if (moveLeft == false && moveRight == false) {
				if (player.velo.y == 0) {

				}
			}

			Move(player, blocksize, moveRight, moveLeft, leftTopX, leftTopY, rightTopX, rightTopY, leftBottomX, leftBottomY, rightBottomX, rightBottomY, scrool, scUp, scDown, alive,clear, map);




			
			if (scrool <= 0) {
				scrool = 0;
			}

			if (alive == false) {
				scene = GAMEOVER;
			}

			if (clear == true) {
				scene = CLEAR;
			}

			break;
		case GAMEOVER:

			if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
				alive = true;
				moveRight = false;
				moveLeft = false;
				player.pos.y = 110;
				player.pos.x = 356;
				
				scrool = 0;
				scene = PLAY;

				for (int y = 0; y < 150; y++)
				{
					for (int x = 0; x < 12; x++)
					{

						if (map[y][x] == 4) {
							map[y][x] = 2;
						}
					}
				}

			}
			if (keys[DIK_ESCAPE] && !preKeys[DIK_ESCAPE]) {
				scene = TITLE;
			}
			break;
		case CLEAR:
			if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
				scene = PLAY;
				moveRight = false;
				moveLeft = false;
				player.pos.y = 110;
				player.pos.x = 356;
				clear = false;
				scrool = 0;
				scene = PLAY;

				for (int y = 0; y < 150; y++)
				{
					for (int x = 0; x < 12; x++)
					{

						if (map[y][x] == 4) {
							map[y][x] = 2;
						}
					}
				}
			}
			if (keys[DIK_ESCAPE] && !preKeys[DIK_ESCAPE]) {
				scene = TITLE;
			}
			break;
		default:
			break;
		}


		//


		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		switch (scene)
		{
		case TITLE:
			Novice::DrawSprite(0, 0, titlesp, 1, 1, 0, WHITE);
			break;


		case PLAY:

			for (int y = 0; y < 150; y++)
			{
				for (int x = 0; x < 12; x++)
				{
					if (map[y][x] == 0) {
						/*Novice::DrawBox((x * blocksize), (y * blocksize) - scrool, blocksize, blocksize, 0.0f, WHITE, kFillModeSolid);*/
					}
					if (map[y][x] == 1) {

						Novice::DrawSprite((x * blocksize), (y * blocksize) - scrool, blocksp, 1, 1, 0, WHITE);
					}
					if (map[y][x] == 2) {
						Novice::DrawSprite((x * blocksize), (y * blocksize) - scrool, enemysp, 1, 1, 0, WHITE);

					}
					if (map[y][x] == 3) {

						Novice::DrawSprite((x * blocksize), (y * blocksize) - scrool, blocksp, 1, 1, 0, BLACK);
					}
					if (map[y][x] == 4) {

						Novice::DrawSprite((x * blocksize), (y * blocksize) - scrool, blocksp, 1, 1, 0, RED);
					}

				}
			}

			Novice::DrawSprite(int(player.pos.x - 32), int(player.pos.y - 32 - scrool), playersp, 1, 1, 0, WHITE);

			Novice::ScreenPrintf(200, 200, "%d", scrool);
			Novice::ScreenPrintf(200, 230, "%f", player.pos.y);


			break;
		case GAMEOVER:
			Novice::DrawSprite(0, 0, gameoversp, 1, 1, 0, WHITE);
			break;
		case CLEAR:
			Novice::DrawSprite(0, 0, clearsp, 1, 1, 0, WHITE);
			break;
		default:
			break;
		}


		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();



	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
