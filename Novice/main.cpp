#include <Novice.h>
#include"Player.h"
#include"Move.h"
#include<math.h>
#define _USE_MATH_DEFINES

const char kWindowTitle[] = "";

const int kWindowWidth = 720;
const int kWindowHeight = 720;

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



	bool moveRight = false;
	bool moveLeft = false;






	Scene scene = TITLE;

	Player player{
		{96,96},
		{4,0},
		{0,0.1f},
		32,
	};


	const int blocksize = 64;

	int map[150][12] = {//マップチップ
  {1,1,1,1,1,1,1,1,1,1,1,0},
  {1,0,0,0,0,0,0,0,0,0,0,0},
  {1,0,0,0,0,0,0,0,0,0,0,0},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,1,1,0,1},
  {1,0,0,0,0,0,0,0,1,1,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0},
  {1,0,0,0,0,0,0,0,0,0,0,0},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,1,0,0,0,1},
  {1,0,0,0,0,0,0,1,0,0,0,1},
  {1,1,0,0,0,0,0,1,1,0,0,1},
  {1,0,0,1,1,1,0,1,1,0,0,0},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,1,1,0,1},
  {1,0,0,0,0,0,0,0,1,1,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0},
  {1,0,0,0,0,0,0,0,0,0,0,0},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,1,0,0,0,1},
  {1,0,0,0,0,0,0,1,0,0,0,1},
  {1,1,1,0,0,0,0,1,1,0,0,1},
  {1,0,0,1,1,1,0,1,1,0,0,0},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0},
  {1,0,0,0,0,0,0,0,0,0,0,0},
  {1,0,1,0,0,0,0,0,0,0,0,0},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,1,1,0,1},
  {1,0,0,0,0,0,0,0,1,1,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,1,0,0,0,0,0,0,0,0,0},
  {1,0,0,0,0,0,0,0,0,0,0,0},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,1,0,0,0,1},
  {1,0,0,0,0,0,0,1,0,0,0,1},
  {1,1,0,0,0,0,0,1,1,0,0,1},
  {1,0,0,1,1,1,0,1,1,0,0,0},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,1,1,0,1},
  {1,0,1,0,0,0,0,0,1,1,0,1},
  {1,1,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0},
  {1,0,0,0,0,0,0,0,0,0,0,0},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,1,0,0,0,1},
  {1,0,1,0,0,0,0,1,0,0,0,1},
  {1,1,0,0,0,0,0,1,1,0,0,1},
  {1,0,0,1,1,1,0,1,1,0,0,0},
  {1,1,1,1,1,1,0,1,1,1,1,1},
  {1,1,1,1,1,1,0,1,1,1,1,1},
  {1,1,1,1,1,1,0,1,1,1,1,0},
  {1,0,0,0,0,0,0,0,0,0,0,0},
  {1,0,0,0,0,0,0,0,0,0,0,0},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,1,1,0,1},
  {1,0,0,0,0,0,0,0,1,1,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0},
  {1,0,0,0,0,0,0,0,0,0,0,0},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,1,0,0,0,1},
  {1,0,0,0,0,0,0,1,0,0,0,1},
  {1,1,0,0,0,0,0,1,1,0,0,1},
  {1,0,0,1,1,1,0,1,1,0,0,0},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,1,1,0,1},
  {1,0,0,0,0,0,0,0,1,1,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0},
  {1,0,0,0,0,0,0,0,0,0,0,0},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,1,0,0,0,1},
  {1,0,0,0,0,0,0,1,0,0,0,1},
  {1,1,1,0,0,0,0,1,1,0,0,1},
  {1,0,0,1,1,1,0,1,1,0,0,0},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0},
  {1,0,0,0,0,0,0,0,0,0,0,0},
  {1,0,1,0,0,0,0,0,0,0,0,0},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,1,1,0,1},
  {1,0,0,0,0,0,0,0,1,1,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,1,0,0,0,0,0,0,0,0,0},
  {1,0,0,0,0,0,0,0,0,0,0,0},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,1,0,0,0,1},
  {1,0,0,0,0,0,0,1,0,0,0,1},
  {1,1,0,0,0,0,0,1,1,0,0,1},
  {1,0,0,1,1,1,0,1,1,0,0,0},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,1,1,0,1},
  {1,0,1,0,0,0,0,0,1,1,0,1},
  {1,1,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0},
  {1,0,0,0,0,0,0,0,0,0,0,0},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,1,0,0,0,1},
  {1,0,1,0,0,0,0,1,0,0,0,1},
  {1,1,0,0,0,0,0,1,1,0,0,1},
  {1,0,0,1,1,1,0,1,1,0,0,0},
  {1,1,1,1,1,1,1,1,1,1,1,1},
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
	int scUp = 300;
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

			if (keys[DIK_R] && !preKeys[DIK_R]) {
				player.pos.x = 96;
				player.pos.y = 96;
				scrool = 0;

			}

			if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {

				player.acce.y *= -1;
			}




			if (moveLeft == false && moveRight == false) {
				if (player.velo.y == 0) {

				}
			}

			Move(player, blocksize, moveRight, moveLeft, leftTopX, leftTopY, rightTopX, rightTopY, leftBottomX, leftBottomY, rightBottomX, rightBottomY, scrool, scUp, scDown, map);




			if (player.pos.x >= 3750 && player.pos.y > 900) {
				scene = CLEAR;
			}
			if (scrool <= 0) {
				scrool = 0;
			}





			break;
		case GAMEOVER:

			if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
				scene = PLAY;
				player.pos.x = 96;
				player.pos.y = 960;
				scrool = 0;

			}
			if (keys[DIK_ESCAPE] && !preKeys[DIK_ESCAPE]) {
				scene = TITLE;
			}
			break;
		case CLEAR:
			if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
				scene = PLAY;
				player.pos.x = 96;
				player.pos.y = 960;
				scrool = 0;

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
