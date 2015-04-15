#include <bits/stdc++.h>
#include "PerlinNoise2D.h"
// #include "ValueNoise2D.h"

using namespace std;
int main()
{
  FILE *bmp;

  int size = 128;
  unsigned int bitmap[size*size];
  unsigned char bmpHeader[54] = {
    'B', 'M', /* [ 0] �t�@�C���^�C�v */
    246, 0, 0, 0, /* [ 2] �t�@�C���T�C�Y */
    0, 0, 0, 0, /* [ 6] �\�� */
    54, 0, 0, 0, /* [10] �r�b�g�}�b�v�f�[�^�̃V�[�N�ʒu */
    40, 0, 0, 0, /* [14] ��������n�܂�w�b�_�̍��� */
    128, 0, 0, 0, /* [18] �r�b�g�}�b�v�̕� */
    128, 0, 0, 0, /* [22] �r�b�g�}�b�v�̍��� */
    0x01, 1, /* [26] �v���[���� */
    32, 0, /* [28] 1�s�N�Z��������̃r�b�g�� �i�ۑ肪4�o�C�g�w�肳��Ă����̂�32bit�ɕύX�j */ 
    0, 0, 0, 0, /* [30] ���k�^�C�v */
    192, 0, 0, 0, /* [34] �r�b�g�}�b�v�f�[�^�̒��� */
    0x20, 0x2e, 0, 0, /* [38] �x(px/m) */
    0x20, 0x2e, 0, 0, /* [42] �x(px/m) */
    0, 0, 0, 0, /* [46] �J���[�C���f�b�N�X�� */
    0, 0, 0, 0, /* [50] �d�v�ȃJ���[�C���f�b�N�X�� */
  };
  bmp = fopen("perlin.bmp", "wb");
  // ValueNoise2D perlin;
  PerlinNoise2D perlin;
  // PerlinNoise1D perlin;
  // perlin.setRange(size, size);
  perlin.setPersistence(0.65);
  perlin.setOcterve(1);

  perlin.generate();
  perlin.printData();
  for(int i = 0; i < size;i++){
    for(int j = 0; j < size; j++){
      int val = 256*((perlin.get(i*size+j)+1.0)/2.0);
      bitmap[i*size+j] = 256*256*val + 256*val + val; 
    }
  }
  fseek(bmp, 0L, SEEK_SET);
  fwrite(bmpHeader, 1, 54, bmp);
  fwrite(bitmap, 4, size*size, bmp);
  fclose(bmp);
  return 0;
}
