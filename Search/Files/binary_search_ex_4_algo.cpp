#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
#define eps 0.0000000000001
double alpha(double a, double b, double c){
	return acos((b*b + c*c - a*a)/(2*b*c));
	//trả về radian
	//đl cosin cos A = (b*b + c*c - a*a)/(2*b*c)
}
double r[10005];
int main(){
	int n;cin>>n;
	for (int i = 0; i<n; i++) cin>>r[i];
	double left = 0, right = 1e9;
	//cout<<alpha(15,32,43)<<endl;
	//cout<<acos((double)331/344);
	
	//cout<<eps; eps = 1e-9
	
	while (abs(left - right) > eps){
		//chặt cạnh của hình tròn ra sao cho sai số gần bằng epsilon
		double mid = (left + right)/2;
		//tính 2 góc đầu tiên
		double angle = alpha(r[0] + r[n - 1], mid + r[0] , mid + r[n-1]);
		//tính các góc còn lại
		for (int i = 1; i<n; i++)
			angle += alpha(r[i] + r[i-1], mid + r[i] , mid + r[i-1]);
		//so sánh góc sau khi cộng với góc tròn 2*PI rad = 360 degree
		if (angle < 2*M_PI) right = mid;else left = mid;
	}
	//in ra bán kính // có thể in left hoặc right
	cout<<fixed<<setprecision(8)<<(left + right)/2<<endl<<left<<endl<<right;
}