int f(int y){
	if(y == 0 || y== 1){
		return y;
	}
	return f(y-1)+ f(y-2);
}
int main(){
	int c;
	c =4;
	c=f(4);
	c = c+ 5;

}
