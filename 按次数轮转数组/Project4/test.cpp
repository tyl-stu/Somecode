#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void display(vector<int> &v)
{
	for (int i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	cout << endl;
}

void reverse(vector<int>& nums, int start, int end)
{
	while (start < end)
	{
		swap(nums[start], nums[end]);
		start++;
		end--;
	}
}

void rotate(vector<int>& nums, int k) {
	/* 方法1 -- 超时 */
	//while (k--)
	//{
	//	nums.insert(nums.begin(), nums[nums.size() - 1]);
	//	//nums.erase(nums.end());
	//	nums.pop_back();
	//	cout << "现数组：";
	//	display(nums);
	//}

	/* 方法2  -- 超时 */
	/*int tmp;
	int n = nums.size() - 1;
	while (k--)
	{
	tmp = nums[n];
	while (n > 0)
	{
	nums[n] = nums[n - 1];
	n--;
	}
	nums[0] = tmp;
	n = nums.size() - 1;
	cout << "现数组：";
	display(nums);
	}*/

	/* 方法三 -- 用新的数组进行操作 */
	/*vector<int> newArr(nums.size());
	for (int i = 0; i < nums.size(); i++)
	{
	newArr[(i + k) % nums.size()] = nums[i];
	}
	nums.assign(newArr.begin(), newArr.end());
	cout << "\n现数组：";
	display(nums);
	cout << "\n";*/

	/*方法四 -- 在原数组上进行操作*/
	k %= nums.size();
	if (k != 0)
	{
		//先小部分翻转，再大部分翻转
		/*reverse(nums, 0, nums.size() - k - 1);
		reverse(nums, nums.size() - k, nums.size() - 1);
		reverse(nums, 0, nums.size() - 1);*/
		//先大部分翻转，再小部分翻转
		reverse(nums, 0, nums.size() - 1);
		reverse(nums, 0, k - 1);
		reverse(nums, k, nums.size() - 1);
	}
	cout << "\n现数组：";
	display(nums);
	cout << "\n"; 
}

void test()
{
	// 插入数据
	vector<int> nums;
	for (int i = 1; i < 8; i++)
		nums.push_back(i);
	cout << "\n原数组：";
	display(nums);

	rotate(nums, 3);
}

int main()
{
	test();
	system("pause");
	return 0;
}