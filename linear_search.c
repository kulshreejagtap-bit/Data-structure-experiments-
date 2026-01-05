#include<stdio.h>
void main() {
    int n,j,flag=0;
	int key,a[100],pos=-1;
	scanf("%d",&n);
	for(j=0;j<n;j++){
		scanf("%d",&a[j]);
	}
	scanf("%d",&key);
	for(j=0;j<n;j++){
		if (a[j]==key){
			flag=1;
			pos=j;
			break;
		}

}
	if (flag == 1) {
		printf("found at position %d\n", pos);
	} else {
		printf("%d not found\n", key);
	}
}
