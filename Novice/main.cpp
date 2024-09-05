#include <Novice.h>
#include"Playerh.h"

const char kWindowTitle[] = "学籍番号";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	Player player{
		{100,100},
		{0,0,},
		{5,1},
		20,

	};


	/*int playerSize = 20;
	int playerPosX = 100;
	int playerPosY = 100;*/
	
	//bool bottomHit = false;
	//bool sideHit = false;


	

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

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
		
		player.velo.x = 0;
		//player.velo.y = 0;
		
		//if (keys[DIK_W]) {
		player.acce.y /= 10;
			player.velo.y += player.acce.y;
			player.pos.y += player.velo.y;
		//}

		if (keys[DIK_S]) {
			player.velo.y += player.acce.y;
			player.pos.y += player.velo.y;
		}

		if (keys[DIK_A]) {
			player.velo.x += player.acce.x;
			player.pos.x -= player.velo.x;
		}

		if (keys[DIK_D]) {
			player.velo.x += player.acce.x;
			player.pos.x += player.velo.x;
		}
		/// ↑更新処理ここまで
		///
		///

		///
		/// ↓描画処理ここから
		///
		Novice::DrawBox((player.pos.x + 50), (player.pos.y + 50), player.radius, player.radius, 0, WHITE, kFillModeSolid);
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
