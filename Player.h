#pragma once

#include "Person.h"

//プレイヤークラス
class Player : public Person
{
private:
	const char* name[];
public:
	Player();
	//ゲーム実行
	void playBase(Shoe* shoe);
	void printName();
};
