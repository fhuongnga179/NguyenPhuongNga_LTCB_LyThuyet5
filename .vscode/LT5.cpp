// 0850080033_NguyenPhuongNga_08THMT

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <climits>
#include <unordered_map>
using namespace std;

// ==========================================================
// 1
double tinhCanhHuyen(double canh1, double canh2)
{
    double canhHuyen = sqrt(canh1 * canh1 + canh2 * canh2);
    return canhHuyen;
}
// 2
void daoNguoc(int &a, int &b, int &c)
{
    int temp = a;
    a = c;
    b = b;
    c = temp;
}
// 3
int tinhBieuThuc(int a, int b, int c, int x)
{
    return a * x * x + b * x + c;
}

// 5
bool kiemTraDoiXung(int arr[], int n)
{
    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        if (arr[left] != arr[right])
        {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

// 6
void findUniqueValues(const vector<int> &arr)
{
    unordered_map<int, int> frequencyMap;
    vector<int> uniqueValues;

    for (int num : arr)
    {
        frequencyMap[num]++;
    }

    for (const auto &entry : frequencyMap)
    {
        if (entry.second == 1)
        {
            uniqueValues.push_back(entry.first);
        }
    }

    cout << "Các giá trị xuất hiện đúng 1 lần trong mảng: ";
    if (uniqueValues.empty())
    {
        cout << "Không có giá trj nào.";
    }
    else
    {
        for (int num : uniqueValues)
        {
            cout << num << " ";
        }
    }
    cout << endl;
}

// 7
int findIndexOfLargestNegative(const vector<int> &arr)
{
    int index = -1; // Khởi tạo biến index là -1, nghĩa là không tìm thấy phần tử âm trong mảng
    int largestNegative = INT_MIN;

    for (int i = 0; i < arr.size(); ++i)
    {
        if (arr[i] < 0 && arr[i] > largestNegative)
        {
            largestNegative = arr[i];
            index = i;
        }
    }

    return index;
}

// ===========================================================
int main()
{
    cout << "Nhập câu hỏi của bài LAB3 - Bài tập cơ bản?" << endl;
    cout << "1. Tính cạnh huyền từ 2 cạnh góc vuông" << endl;
    cout << "2. Số đảo ngược" << endl;
    cout << "3. Nhập giá trị x nhỏ hơn 100 " << endl;
    cout << "4. Bài tập bắt buộc: Nhập dãy số tăng dần và xuất số nguyên tố " << endl;
    cout << "5. Bài tập bắt buộc: Kiểm tra xem mảng có đối xứng hay không " << endl;
    cout << "6. Bài tập bắt buộc: Phần tử chỉ xuất hiện đúng một lần " << endl;
    cout << "7. Bài tập bắt buộc: Phần tử có giá trị âm trong mảng" << endl;

    cout << "Số nhập là: ";

    int n;
    cin >> n;
    switch (n)
    {
        // =========================================
    case 1: // c2=a2+b2
    {
        double a, b;
        cout << "Nhập 2 cạnh góc vuông: ";
        cin >> a >> b;
        double canhHuyen = tinhCanhHuyen(a, b);
        cout << "Độ dài cạnh huyền của tam giác vuông là: " << canhHuyen << endl;
        break;
    }

    case 2:
    {
        int a, b, c;
        cout << "Nhập vào 3 số a, b, c: ";
        cin >> a >> b >> c;
        cout << "Số nhập là: a = " << a << ", b = " << b << ", c = " << c << endl;
        daoNguoc(a, b, c);
        cout << "Đảo ngược số: a = " << a << ", b = " << b << ", c = " << c << endl;
        break;
    }
    case 3:
    {
        int a, b, c;
        cout << "Nhap gia tri cho a, b, c (ca hai phai la so nguyen): ";
        cin >> a >> b >> c;

        int x;
        cout << "Nhap gia tri cho x (so nguyen nho hon 100): ";
        cin >> x;

        if (x >= 100)
        {
            cout << "Gia tri cua x phai nho hon 100. Vui long nhap lai." << endl;
            return 1;
        }

        int ketQua = tinhBieuThuc(a, b, c, x);
        cout << "Gia tri cua ax^2 + bx + c voi x = " << x << " la: " << ketQua << endl;
        break;
    }

    case 5:
    {
        int n;
        cout << "Nhập số lượng phần tử trong mảng: ";
        cin >> n;

        if (n <= 0)
        {
            cout << "Số lượng phần tử không hợp lệ." << endl;
            return 1;
        }

        int arr[n];
        cout << "Nhập các phần tử: ";
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        if (kiemTraDoiXung(arr, n))
        {
            cout << "Mảng đối xứng." << endl;
        }
        else
        {
            cout << "Mảng không đối xứng." << endl;
        }
        break;
    }

    case 6:
    {
        int n;
        cout << "Nhập kích thước mảng: ";
        cin >> n;

        vector<int> arr(n);
        cout << "Nhập các phần tử trong mảng::" << endl;
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }

        findUniqueValues(arr);

        return 0;
        break;
    }

    case 7:
    {
        int n;
        cout << "Nhập kích thước mảng: ";
        cin >> n;

        vector<int> arr(n);
        cout << "Nhập các phần tử trong mảng::" << endl;
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }

        int index = findIndexOfLargestNegative(arr);

        if (index == -1)
        {
            cout << "Không có phần tử âm trong mảng." << endl;
        }
        else
        {
            cout << "Vị trí phần tử âm lớn nhất trong mảng: " << index << endl;
        }
    }

    default:
    {
        cout << "Không có bài tập";
        break;
    }
    }
}