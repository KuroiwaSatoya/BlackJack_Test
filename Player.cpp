#include <iostream>
#include "Player.h"
#include "Shoe.h"

using namespace std;

//�Q�[�����s

Player::Player() {
	*name = "player";
}

void Player::playBase(Shoe* shoe) {

	cout << "===================="<< endl << *name << "�̃^�[��" << endl;
	showHand();
	//stand����܂Ń��[�v����
	while (true) {
		cout << "hit or stand >> ";

		//����
		char str[16]; //������^
		cin >> str; //����������
		//hit�����͂��ꂽ�ꍇ
		if (strcmp(str, "hit") == 0) {
			//�J�[�h�̔z�z
			hit(shoe);

			//��D�̕\��
			cout << "====================" << endl;
			cout << *name << endl;
			showHand();
			cout << "====================" << endl;
		}
		else if (strcmp(str, "stand") == 0) {
			//�I������
			break;
		}
	}
}

void Player::printName() {
	cout << *name;
}
