#include <iostream>
#include <cmath>
using namespace std;

void movement(long long tower[],int from,int to){
    
    int fromTop = tower[from] % 10;//the top plate of the original tower
    int toTop = tower[to] % 10;//the top plate of the destination tower
    //check movement valid or not
    while((toTop!=0)&&(fromTop > toTop)){
        cout << "Bigger plates must not be on top of smaller ones! Please try again!\n";
        cout << "Which tower do you want to move the top plate from?(0,1,or 2):";
        cin >> from;
        cout << "and to which tower?(0,1,or 2):";
        cin >> to;
        if(tower[from]==10){
            fromTop = 10;
        }
        else{
            fromTop = tower[from] % 10;
        }
        if(tower[to]==10){
            toTop = 10;
        }
        else{
            toTop = tower[to] % 10;
        }
    }
    
    tower[from] = (tower[from]-fromTop)/10;
    tower[to] = tower[to]*10+fromTop;
    
}

void Hanoi_Solution(int plate,int from,int skip, int to){//recursive function for hanoi
    if(plate==1){
        cout << "Move plate"<< plate <<" from Tower" << from << " to Tower" << to << endl;
    }
    else{
        Hanoi_Solution(plate-1,from,to,skip);//exchange skip with from
        cout << "Move plate"<< plate <<" from Tower" << from << " to Tower" << to << endl;
        Hanoi_Solution(plate-1,skip,from,to);//exchange to with skip
    }
}

int main(){
    
    int plate=0;//number of plates
    long long end=0;//use to confirm if the user wins
    long long tower[3]={0};//the value of each element represents the plates in each tower
    int from;//the tower the user chooses to move plates from
    int to;// the tower the user chooses to move plates to
    
    //user decides the number of plates
    cout << "Please enter the number of plates:";
    cin >> plate;
    
     //set initial status(put all the plates in Tower0 in ascending order)
    for(int i=1; i<=plate; i++){
        tower[0]+=i*pow(10,i-1);
    }
    
    end = tower [0];//the final status of the destination tower should be the same as the initial one
    
    //show introduction
    cout << "Game Start!\nIntroductions\n1.Numbers from left to right means plates from bottom to top\n2.The value represents the size of the plate\n3.0 means there are no plates\n";

    //user control
    while(1){
        //print current status
        cout << "*****************************" << endl;
        cout << "Current status...\n";
        cout << "Tower0:" << tower[0] << endl;
        cout << "Tower1:" << tower[1] << endl;
        cout << "Tower2:" << tower[2] << endl;
        cout << "*****************************" << endl;

        //user wins if one of the tower has the same status with the initial status
        if((tower[1]==end)||(tower[2]==end)){
            cout << "You Win!\n";
            break;
        }
        
        //prompt for movement
        cout << "Which tower do you want to move the top plate from?(enter 0,1,2 or -1 to show solution):";
        cin >> from;
        
        if(from==-1){//user asks for solution
            cout << "Solution:\n";
            Hanoi_Solution(plate,0,1,2);//solution function
            break;
        }
        cout << "and to which tower?(0,1,or 2):";
        cin >> to;
        movement(tower,from,to);//operate movement
    }
    
    system("pause");
    return 0;
}








