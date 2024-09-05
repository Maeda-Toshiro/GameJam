#include <Novice.h>

const char kWindowTitle[] = "学籍番号";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 720, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	float PlayrPosX = 640;
	float PlayrPosY = 0;

	//落下速度
	float speed = 1.0f;
	float speed2 = 0.1f;
	bool isflag = true;
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
		/// 
		if (keys[DIK_A]) {
			PlayrPosX -= 15;
		}
		
		if (keys[DIK_D]) {
			PlayrPosX += 15;
		}
		while (isflag==true)
		{
			PlayrPosY += speed;
			speed += speed2;
		}
		
		///
		/// ↑更新処理ここまで
		///
	
		///
		/// ↓描画処理ここから
		///
		Novice::DrawEllipse((int)PlayrPosX, (int)PlayrPosY, 10, 10, 0.0f, WHITE,kFillModeSolid);
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
