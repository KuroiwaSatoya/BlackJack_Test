#include <iostream>

#include "Dealer.h"
#include "Shoe.h"

using namespace std;

Dealer::Dealer() {
	*name = "dealer";
}

//ゲーム実行
void Dealer::playBase(Shoe* shoe) {
	cout << "====================" << endl << *name << "のターン" << endl;
	//スコアが16以下の場合hitを続ける
	while (getScore() < 17 && getScore() > 0) {
		//ヒットする
		hit(shoe);
		cout << "hit" << endl;
		//手札の表示
		cout << "====================" << endl;
		cout << *name << endl;
		showHand();
		cout << "====================" << endl;
	}
}

void Dealer::printName() {
	cout << *name;
}