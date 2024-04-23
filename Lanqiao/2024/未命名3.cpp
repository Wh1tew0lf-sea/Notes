#include <iostream>
#include <vector>

using namespace std;
int N;
int H[10000];
vector<int> nums;
// ���һ�����Ƿ�Ϊ����
bool isPrime(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// ��������Ѱ����С����������
vector<int> findSmallestPrimes(const vector<int>& nums) {
    vector<int> primes;
    for (int num : nums) {
        if (isPrime(num)) {
            primes.push_back(num);
            if (primes.size() == 3) {
                break;
            }
        }
    }
    return primes;
}

int main() {
      cin >> N;
	for(int i=0;i<N;i++){
		cin >> H[i];
		nums.push_back(H[i]);
	}

    // Ѱ����С����������
    vector<int> smallestPrimes = findSmallestPrimes(nums);

    // ������
    if (smallestPrimes.size() >= 3) {
        for (int prime : smallestPrimes) {
            cout << prime << " ";
        }
        cout << endl;
    } else {
        cout << cout << nums[0]<<' '<<nums[1]<<' '<<nums[2];
    }

    return 0;
}
