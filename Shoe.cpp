#include "Shoe.h"
#include <iostream>
#include <random> //乱数生成

using namespace std;

//シャッフル（フィッシャーイェーツ）
void Shoe::_shuffle()
{
	for (int i = _cardNum - 1; i > 0; --i) {
		int a = i;
		int b = rand() % (i + 1);
		swap(_cardShoe[a], _cardShoe[b]);
	}
}

//コンストラクタ
Shoe::Shoe() {

	//カードを入れてく0.... /13でカード種類とする
	for (int i = 0; i < CARD; i++) {
		_cardShoe[i] = i;
	}
	_cardNum = CARD; //カード枚数の設定

	//シャッフル
	_shuffle();
}

//カードシューを表示(デバッグ用)
void Shoe::showShoe(SHOW_TYPE type) const 
{
	int roopCnt = NUM;
	if (type == CARD_ONLY) {	//カード枚数分表示
		//カードのみ表示にする。
		roopCnt = _cardNum;
	}

	for (int i = 0; i < roopCnt; i++) {
		cout << _cardShoe[i] << ' ';
	}
	cout << endl;
}

//カードを1枚取り出す
int Shoe::takeCard() {
	//カード枚数が0以下だった場合,無限に引けるようにするためにNUMを代入してシャッフル
	if (_cardNum <= 0) {
		_cardNum = CARD;
		_shuffle();
	}

	int card = _cardShoe[--_cardNum];

	return card;
}
