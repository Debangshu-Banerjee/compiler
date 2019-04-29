int main(){

int i;
float k;
k = 1.0;
for(i = 0;i<10;++i){
  print(i);
  k = k + 1;
  print(k);
  switch(i){
      case 1:{
        print(1);
        break;
      }
      case 2:{
        print(i);
        break;
      }
      case 3:{
        continue;
        print(i);
        break;
      }
  }
}




}
