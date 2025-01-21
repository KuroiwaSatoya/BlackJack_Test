#include <iostream> //入出力

#include "Shoe.h"
#include "Player.h"
#include "Dealer.h"

using namespace std;

//
// 試験用ブラックジャックソース
// 正常動作していない。
//

// ★★★★★★★★★★★★★★★★
static void showResult(Person** p, int i)
{
	cout << "============================" << endl;
	cout << "            result          " << endl;
	cout << "============================" << endl;
	cout << "============================" << endl;
	cout << "player" << endl;
	p[i]->showHand();
	cout << "============================" << endl;
	cout << "dealer" << endl;
	p[3]->showHand();
	cout << "============================" << endl;

	if (p[i]->getScore() > p[3]->getScore()) {
		cout << "Player Win!" << endl;
	}
	else if (p[i]->getScore() < p[3]->getScore()) {
		cout << "Player Lose" << endl;
	}
	else {
		cout << "Push" << endl;
	}
}

static void showHand(Person* p)
{
	//手札の表示
	cout << "====================" << endl;
	p->printName();
	cout << endl;
	p->showHand();
	cout << "====================" << endl;

}

//メイン関数
int main() {
	// 確認
	srand((unsigned int)time(NULL));

	enum PERSON
	{
		PLAYER1, PLAYER2, PLAYER3, DEALER
	};

	//各オブジェクトの生成
	Shoe shoe;
	Person* persons[] = { new Player, new Player, new Player, new Dealer};
	//const char* name[] = {"player", "dealer"};
	const int num = sizeof(persons) / sizeof(Person*);

	//----カードの配布 ... 初期
	cout << "====================" << endl;
	for (int i = 0; i < num; i++)
	{
		persons[i]->hit(&shoe);
		showHand(persons[i]);
	}
	//プレイヤーに2枚目を配布
	for (int i = 0; i < num - 1; i++) {
		persons[i]->hit(&shoe);
		showHand(persons[i]);
	}

	//ディーラーに2枚目を配布
	persons[DEALER]->hit(&shoe);


	// ----　勝負開始
	for (int i = 0; i < num - 1; i++) {
		persons[i]->playBase(&shoe);
	}
	persons[DEALER]->playBase(&shoe);

	for (int i = 0; i < num - 1; i++) {
		showHand(persons[i]);
		//バーストしているかどうか判別
		if (persons[i]->play(&shoe)) {
			//バーストせずstandした

			//ディーラーの手札を表示
			showHand(persons[DEALER]);

			//ディーラーの自動実行
			persons[DEALER]->play(&shoe);

			//結果の表示
			showResult(persons, i);
		}
		else {
			cout << "Burst Player Lose" << endl;
		}
		cout << "====================" << endl;
	}
	return 0;
}