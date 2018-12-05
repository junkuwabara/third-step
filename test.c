#include<stdio.h>
#include<math.h>

int main()
{
	double s[] = {	65.0, 80.0, 67.0, 35.0, 58.0, 60.0, 72.0, 75.0, 68.0,
			92.0, 36.0, 50.0, 2.0,  58.5, 46.0, 42.0, 78.0, 62.0,
			84.0, 70.0 };
	double e[] = {	44.0, 87.0, 100.0, 63.0, 52.0, 60.0, 58.0, 73.0, 55.0, 
			86.0, 29.0, 56.0, 89.0, 23.0, 65.0, 84.0, 64.0, 27.0, 
			86.0, 84.0 };

	double avg_s, dev_s, sum_s, pre_s;
	double avg_e, dev_e, sum_e, pre_e;

	int n = sizeof(s) / sizeof(s[0]);
	int i, j, k, l, m;

	sum_s = sum_e = 0.0;

	double std_s[n], std_e[n], tmp, tmp2;

	for(i=0; i<n; i++) {
		sum_s += s[i];
		sum_e += e[i];
	}

	avg_s = sum_s / n;
	avg_e = sum_e / n;

	pre_s = pre_e = 0.0;

	for(j=0; j<n; j++) {
		pre_s += (s[j] - avg_s)*(s[j] - avg_s);
		pre_e += (e[j] - avg_e)*(e[j] - avg_e);
	}
	
	dev_s = sqrt(pre_s / n);
	dev_e = sqrt(pre_e / n);

	printf("理科 平均点=%lf 標準偏差=%lf 合計点=%lf \n", avg_s, dev_s, sum_s);
	printf("英語 平均点=%lf 標準偏差=%lf 合計点=%lf \n", avg_e, dev_e, sum_e);
	
	printf("偏差値は\n");
	
	for(k=0; k<n; k++) {
		std_s[k] = 50.0 + 10.0*(s[k] - avg_s)/dev_s;
		std_e[k] = 50.0 + 10.0*(e[k] - avg_e)/dev_e;
		printf("学生%d 理科=%lf 英語=%lf\n", k+1, std_s[k], std_e[k]);
	}
	
	printf("高い順に並び替え\n理科　　英語\n");

	for(l=0; l<n; l++) {
		for(m=l+1; m<n; m++) {
			if(s[l]<s[m]) {
				tmp = s[l];
				s[l] = s[m];
				s[m] = tmp;
			}
			if(e[l]<e[m]) {
                                tmp2 = e[l];
                                e[l] = e[m];
                                e[m] = tmp2;
                        }
		}
	}
	
	for(i=0; i<n; i++){
		printf("%lf  ", s[i]);
		printf("%lf\n", e[i]);
	}

	return 0;
}
