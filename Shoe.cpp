#include "Shoe.h"
#include <iostream>
#include <random> //��������

using namespace std;

//�V���b�t���i�t�B�b�V���[�C�F�[�c�j
void Shoe::_shuffle()
{
	for (int i = _cardNum - 1; i > 0; --i) {
		int a = i;
		int b = rand() % (i + 1);
		swap(_cardShoe[a], _cardShoe[b]);
	}
}

//�R���X�g���N�^
Shoe::Shoe() {

	//�J�[�h�����Ă�0.... /13�ŃJ�[�h��ނƂ���
	for (int i = 0; i < CARD; i++) {
		_cardShoe[i] = i;
	}
	_cardNum = CARD; //�J�[�h�����̐ݒ�

	//�V���b�t��
	_shuffle();
}

//�J�[�h�V���[��\��(�f�o�b�O�p)
void Shoe::showShoe(SHOW_TYPE type) const 
{
	int roopCnt = NUM;
	if (type == CARD_ONLY) {	//�J�[�h�������\��
		//�J�[�h�̂ݕ\���ɂ���B
		roopCnt = _cardNum;
	}

	for (int i = 0; i < roopCnt; i++) {
		cout << _cardShoe[i] << ' ';
	}
	cout << endl;
}

//�J�[�h��1�����o��
int Shoe::takeCard() {
	//�J�[�h������0�ȉ��������ꍇ,�����Ɉ�����悤�ɂ��邽�߂�NUM�������ăV���b�t��
	if (_cardNum <= 0) {
		_cardNum = CARD;
		_shuffle();
	}

	int card = _cardShoe[--_cardNum];

	return card;
}
