#include <iostream>
#include "Player.h"
#include "Shoe.h"

using namespace std;

//ゲーム実行

Player::Player() {
	*name = "player";
}

void Player::playBase(Shoe* shoe) {

	cout << "===================="<< endl << *name << "のターン" << endl;
	showHand();
	//standするまでループ処理
	while (true) {
		cout << "hit or stand >> ";

		//入力
		char str[16]; //文字列型
		cin >> str; //文字列を入力
		//hitが入力された場合
		if (strcmp(str, "hit") == 0) {
			//カードの配布
			hit(shoe);

			//手札の表示
			cout << "====================" << endl;
			cout << *name << endl;
			showHand();
			cout << "====================" << endl;
		}
		else if (strcmp(str, "stand") == 0) {
			//終了処理
			break;
		}
	}
}

void Player::printName() {
	cout << *name;
}
