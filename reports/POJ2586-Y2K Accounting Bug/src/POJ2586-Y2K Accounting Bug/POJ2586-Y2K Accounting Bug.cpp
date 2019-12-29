/*
	Author:     Exp
	Date:       2017-12-25
	Code:       POJ 2586
	Problem:    Y2K Accounting Bug
	URL:		http://poj.org/problem?id=2586
*/

/*
	���������
	 ��֪һ����˾��ĳһ���У���ÿ����Ҫô�̶�ӯ��s��Ҫô�̶�����d����
	 ���Ǿ����ĸ���ӯ�����Ǹ��¿���ȴ���ö�֪��
	 �������Կ϶����ǣ���һ���У������������5����ӯ���ͱض��ǿ���< 0������
	 �������Ƿ����ӯ���Ŀ��ܣ�������ӯ����������ӯ����Ƕ��٣�


    ����˼·��
	  Ҫ��ȫ�����ӯ���������������ÿ��ӯ������12s
	  �������и���ǰ�᣺�����������5����ӯ���ͱض��ǿ���
	  
	  ����������̰�ķ�ȥ��⣺
	    ��1�·ݿ�ʼ��ѡ������ӯ�������������ѡ��Ϊӯ����
	      ���ҽ����޷����㡾����5�±ؿ����������ʱ�����²�ѡ�����


	  �������������٣����԰�ÿ5���µ�����ӯ���������оٳ�����
      �� �� s >= 4d ʱ ����1���µ�ӯ���ֵ���4���µĿ��𣩣�
          ���������ϣ����޷����㡾����5�±ؿ��𡿵�ǰ�ᣬ
          ���Ϊ���������������ֻ���������·ݾ�����
          �������·�Ϊ [1-12]
	      ȫ��������

      �� �� s < 4d ����2s >= 3d�� ʱ ����1���µ�ӯ���պ�С��4���µĿ���,
		  ��ʱֻ�豣֤ÿ����5����������4�����ǿ��𼴿ɣ�
		  ����̰���߼���ȫ��ӯ���·�Ϊ��sddddsddddsd
		  ��ӯ���·�Ϊ 1��6��11
		    �����·�Ϊ [2-5]��[7-10]��12
		  ȫ���������Ϊ: 3s - 9d

      �� �� 2s < 3d ����3s >= 2d��ʱ ����2���µ�ӯ���պ�С��3���µĿ���,
		  ��ʱֻ�豣֤ÿ����5����������3�����ǿ��𼴿ɣ�
		  ����̰���߼���ȫ��ӯ���·�Ϊ��ssdddssdddss
		  ��ӯ���·�Ϊ [1-2]��[6-7]��[11-12]
		    �����·�Ϊ [3-5]��[8-10]
		  ȫ���������Ϊ: 6s - 6d

      �� �� 3s < 2d ����4s >= d��ʱ ����3���µ�ӯ���պ�С��2���µĿ���,
		  ��ʱֻ�豣֤ÿ����5����������2�����ǿ��𼴿ɣ�
		  ����̰���߼���ȫ��ӯ���·�Ϊ��sssddsssddss
		  ��ӯ���·�Ϊ [1-3]��[6-8]��[11-12]
		    �����·�Ϊ [4-5]��[9-10]
		  ȫ���������Ϊ: 8s - 4d

      �� �� 4s < d ʱ ����4���µ�ӯ���պ�С��1���µĿ���,
		  ��ʱֻ�豣֤ÿ����5����������1�����ǿ��𼴿ɣ�
		  ����̰���߼���ȫ��ӯ���·�Ϊ��ssssdssssdss
		  ��ӯ���·�Ϊ [1,4]��[6-9]��[11-12]
		    �����·�Ϊ 5��10
		  ȫ���������Ϊ: 10s - 2d


*/

#include <iostream>
using namespace std;

int main(void) {
	int s, d;
	while(cin >> s >> d) {

		int surplus = 0;	// ȫ��ӯ��
		if(4 * s < d) {
			surplus = 10 * s - 2 * d;
			
		} else if(3 * s < 2 * d) {
			surplus = 8 * s - 4 * d;

		} else if(2 * s < 3 * d) {
			surplus = 6 * s - 6 * d;

		} else if(s < 4 * d) {
			surplus = 3 * s - 9 * d;

		} else {
			surplus = -1;
		}

		if(surplus < 0) {
			cout << "Deficit" << endl;
		} else {
			cout << surplus << endl;
		}
	}
	return 0;
}