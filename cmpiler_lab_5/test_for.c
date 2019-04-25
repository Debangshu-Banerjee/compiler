int main(){
	int a,c;
	int b;
	b=7;
	if(b<5){
		b=5;
		if(b!= 5){
			b=5;
		}
		switch (b){
			case 7:{
				b=8;
			}
			case 8:
				b=9;
			default :
				b= 10;	
		}
		c = 9;
	}
	else{
		b= 7;
	}
	return 0;
}