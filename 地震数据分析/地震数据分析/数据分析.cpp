#include<fstream>
#include<string>
#include<iostream>
#include<Windows.h>
#include<cmath>

const double value=1.5;
using namespace std;

double power_w(double arr[],int leng,int n);

int main(void){
	string filename;
	ifstream file;
	int row=0, short_wind = 0,long_wind = 0;
	double count=0, *energy=NULL,short_count= 0,long_count = 0,number=0;
	cout << "����������Ҫ�򿪵��ļ���";
	cin >>filename;
	file.open(filename.c_str());
	if(file.fail()){
	cout <<"�ļ���ʧ�ܣ�"<<endl;
	    exit(-1);
	}else{
		file>>row>>count;

		cout<<row<<"  "<<count<<endl;
	}
	if(row>=0){
	energy = new double[row];
	for(int i=0; i<row; i++){
		file>>energy[i];
	}

	cout<<"�������㳤ʱ�䴰��Ҫȡ��ֵ������";

	cin>>long_wind;
	cout <<"����������Ҫȡ�ö�ʱ�䴰�ڵĸ�����";
	cin>>short_wind;

	for(int i=long_wind-1;i<row;i++){
		long_count = power_w(energy,i,long_wind);
		short_count =  power_w(energy,i,short_wind);

		number=short_count/long_count;
		if(number>value){
			cout <<"������ܳ��ֵ�ʱ��ֵ��"<<i*count<<endl;
		}
	}
	delete [] energy;
	}
	file.close();
	system("pause");
	return 0;
}
double power_w(double arr[],int leng,int n){

	double xsquare=0;

	for(int i=0;i<n;i++){

      xsquare+= pow(arr[leng-i],2);
	}

	return xsquare/n;
}