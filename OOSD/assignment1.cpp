#include <iostream>
#include<string>

using namespace std;

//this is the array to store 
int arr[] = {0,0,0,0,0,0,0,0,0};
//this is the sequence of inputs given by users
string userInputs = "";
//this is the sequence of inputs given by computers
string computerInputs = "";

//this function will initially inform the user about the box numbering
void printNumber(){
	cout << 0 << " | " << 1 << " | " << 2 << endl;
	cout << 3 << " | " << 4 << " | " << 5 << endl;
	cout << 6 << " | " << 7 << " | " << 8 << endl << endl;
}

//this function prints the box with correct marks on it
void printBox(){
	char c[9];
	for(int i=0;i<9;i++){
		if(arr[i]==0){
			c[i] = '_';
		}
		if(arr[i]==1){
			c[i] = 'X';
		}
		if(arr[i]==2){
			c[i] = 'O';
		}
	}
	cout << c[0] << " | " << c[1] << " | " << c[2] << endl;
	cout << c[3] << " | " << c[4] << " | " << c[5] << endl;
	cout << c[6] << " | " << c[7] << " | " << c[8] << endl << endl;
}

//this function will take input from user
int takeInputFromUser(){
	int userInput;
	cout << "enter your room number:" << endl;
	cin >> userInput;
	while(arr[userInput]!=0 || userInput>8 || userInput<0){
		cout << "this position is filled already. enter your room number(0-8):" << endl;
		cin >> userInput;
	}
	userInputs.push_back(userInput+'0');
	arr[userInput] = 2;
	printBox();
	return userInput;
}

//this function will be called when computer wins
void computerWin(){
	cout << "computer won the match!!!" << endl;
}

//this is called when tie occurs
void tieCall(){
	cout << "This is a TIE!!!" << endl;
}

//this function is to play for computer
void computerTurn(int x){
	arr[x] = 1;
	computerInputs.push_back(x+'0');
	printBox();
}

//this function is when computer starts first
void startByComputer(){
	int i;
	string position;
	int userInput, nextPos;
	computerTurn(4);										//start always by placing in center
	userInput = takeInputFromUser();
	
	//after that 2 main cases are considered. 1.user places in edge 2. user places in corner
	if(userInput == 1 || userInput == 3 || userInput == 5 || userInput == 7){
		position = "edge";
		nextPos = (userInput==1 || userInput==7) ? (8 - userInput - 1) : (8 - userInput - 3);
		computerTurn(nextPos);
		userInput = takeInputFromUser();
		
		if((userInput + (computerInputs[1]-'0')) != 8){
			nextPos = 8 - (computerInputs[1]-'0');
			computerTurn(nextPos);
			computerWin();
		}else{
			nextPos = 2*(userInputs[0] - '0') - (userInputs[1] - '0');
			arr[nextPos] = 1;
			computerInputs.push_back(nextPos+'0');
			printBox();
			userInput = takeInputFromUser();
			
			if(2*userInput != (computerInputs[2]-'0')+(computerInputs[1]-'0')){
				nextPos = ((computerInputs[2]-'0')+(computerInputs[1]-'0'))/2;
				arr[nextPos] = 1;
				computerInputs.push_back(nextPos+'0');
				printBox();
				computerWin();
			}else{
				nextPos = 2*(computerInputs[0]-'0') - (computerInputs[2]-'0');
				arr[nextPos] = 1;
				computerInputs.push_back(nextPos+'0');
				printBox();
				computerWin();
			}
		}
	}else{
		nextPos = 8 - userInput;
		computerTurn(nextPos);
		userInput = takeInputFromUser();
		
		if(((userInputs[0] - '0') == 0 && (userInput == 1 || userInput == 3)) 
			|| ((userInputs[0] - '0') == 2 && (userInput == 1 || userInput == 5)) 
			|| ((userInputs[0] - '0') == 6 && (userInput == 7 || userInput == 3))
			|| ((userInputs[0] - '0') == 8 && (userInput == 5 || userInput == 7))){
			nextPos = 2*userInput - (userInputs[0] - '0');
			computerTurn(nextPos);
			userInput = takeInputFromUser();
			
			if(2*userInput != (computerInputs[2]-'0')+(computerInputs[1]-'0')){
				nextPos = ((computerInputs[2]-'0')+(computerInputs[1]-'0'))/2;
			}else{
				nextPos = 8 - (computerInputs[2]-'0');
			}
			computerTurn(nextPos);
			computerWin();
		}else{
			if(((userInputs[0] - '0') == 0 && (userInput == 2 || userInput == 6)) 
			|| ((userInputs[0] - '0') == 2 && (userInput == 0 || userInput == 8)) 
			|| ((userInputs[0] - '0') == 6 && (userInput == 0 || userInput == 8))
			|| ((userInputs[0] - '0') == 8 && (userInput == 6 || userInput == 2))){
				nextPos = (userInput + (userInputs[0] - '0'))/2;
				computerTurn(nextPos);
				userInput = takeInputFromUser();
				
				if(userInput%2 == 0){
					nextPos = (userInput+(userInputs[0]-'0'))/2;
				}else{
					if(userInput != 8 - (computerInputs[2]-'0')){
						nextPos = 8 - (computerInputs[2]-'0');
						computerTurn(nextPos);
						computerWin();
						return;
					}
					nextPos = arr[0]==0? 0 : arr[2]==0 ? 2 : arr[6]==0?6: 8;
				}
				computerTurn(nextPos);
				userInput = takeInputFromUser();
				
				for(i=0;i<9;i++){
					if(arr[i]==0){
						nextPos = i;
					}
				}
				computerTurn(nextPos);
				tieCall();

			}else{
				nextPos = (userInput==1 || userInput==7) 
				? arr[(8 - userInput - 1)]==0?(8 - userInput - 1):(8 - userInput + 1) 
				: arr[(8 - userInput - 3)]==0?(8 - userInput - 3):(8 - userInput + 3) ;
				computerTurn(nextPos);

				userInput = takeInputFromUser();
				userInputs.push_back(userInput+'0');

				if(arr[((computerInputs[2]-'0')+(computerInputs[1]-'0'))/2] == 0){
					nextPos = ((computerInputs[2]-'0')+(computerInputs[1]-'0'))/2;
					cout << "hello" << computerInputs[2] << endl;
				}else{
					nextPos = arr[0]==0? 0 : arr[2]==0 ? 2 : arr[6]==0?6: 8;
				}
				computerTurn(nextPos);
				computerWin();
			}
		}

	}
}

//this function is when user starts first
void startByUser(){
	int i;
	string position;
	int userInput, nextPos;
	userInput = takeInputFromUser();
	// 3 cases are considered. 1.user starts by center 2. By Edge 3. By Corner
	if(userInput == 4){
		nextPos = 0;
		arr[nextPos] = 1;
		computerInputs.push_back(nextPos+'0');
		printBox();
		userInput = takeInputFromUser();
		
		if(userInput == 8){
			nextPos = 6;
			arr[nextPos] = 1;
			computerInputs.push_back(4+'0');
			printBox();
			userInput = takeInputFromUser();
			
			if(userInput!=3){
				nextPos = 3;
				arr[nextPos] = 1;
				computerInputs.push_back(4+'0');
				printBox();
				computerWin();
			}else{
				nextPos = 5;
				arr[nextPos] = 1;
				computerInputs.push_back(4+'0');
				printBox();
				userInput = takeInputFromUser();
				
				if(userInput == 1){
					nextPos = 7;
				}else{
					nextPos = 1;
				}
				arr[nextPos] = 1;
				computerInputs.push_back(4+'0');
				printBox();
				userInput = takeInputFromUser();
				
				tieCall();
			}

		}else{
			if(userInput == 1 || userInput == 3){
				nextPos = 8 - userInput;
				computerTurn(nextPos);
				userInput = takeInputFromUser();
				if(userInput == 8){
					nextPos = 2*(computerInputs[1]-'0') - 8;
					computerTurn(nextPos);
					userInput = takeInputFromUser();
					if(userInput != (nextPos+ (computerInputs[0]-'0'))/2){
						nextPos = 3;
						computerTurn(nextPos);
						computerWin();
					}else{
						for(i=0;i<9;i++){
							if(arr[i]==0){
							nextPos = i;
							}
						}
						computerTurn(nextPos);
						userInput = takeInputFromUser();
						tieCall();
					}
				}else{
					nextPos = 8 - userInput;
					computerTurn(nextPos);
					userInput = takeInputFromUser();
					if(nextPos == 2*(computerInputs[1]-'0') - 8 || nextPos == (2*(computerInputs[1]-'0') - 8)/2){
						if(!(userInput == 2*(computerInputs[1]-'0') - 8 || userInput == (2*(computerInputs[1]-'0') - 8)/2)){
							nextPos = nextPos==2*(computerInputs[1]-'0') - 8 ? (2*(computerInputs[1]-'0') - 8)/2 : 2*(computerInputs[1]-'0') - 8;
							computerTurn(nextPos);
							computerWin();
							return;
						}
					}
					if(userInput == 8){
						for(i=0;i<9;i++){
							if(arr[i]==0){
							nextPos = i;
							}
						}
						computerTurn(nextPos);
						userInput = takeInputFromUser();
						tieCall();
					}else{
						if(nextPos == 2*(computerInputs[1]-'0') - 8){
							nextPos = 8;
							computerTurn(nextPos);
							computerWin();
							return;
						}
		
						computerTurn(nextPos);
						userInput = takeInputFromUser();
						tieCall();
					}
				}
			}else{
				if(userInput == 2 || userInput == 6){
					nextPos = 8 - userInput;
					computerTurn(nextPos);
					userInput = takeInputFromUser();
					if(userInput != nextPos/2){
						nextPos = nextPos/2;
						computerTurn(nextPos);
						computerWin();
					}else{
						nextPos = 8 - userInput;
						computerTurn(nextPos);
						userInput = takeInputFromUser();
						if(userInput != 8){
							nextPos = 8 - userInput;
							computerTurn(nextPos);
							userInput = takeInputFromUser();
							tieCall();
						}else{
							nextPos = arr[7]==0 ? 7 : 5;
							computerTurn(nextPos);
							userInput = takeInputFromUser();
							tieCall();
						}
					}
				}else{
					nextPos = 8 - userInput;
					computerTurn(nextPos);
					userInput = takeInputFromUser();
					if(userInput != 2*nextPos){
						nextPos = 2*nextPos;
						computerTurn(nextPos);
						computerWin();
					}else{
						nextPos = 8 - userInput;
						computerTurn(nextPos);
						userInput = takeInputFromUser();
						if(userInput != nextPos/2){
							nextPos = nextPos/2;
							computerTurn(nextPos);
							computerWin();
						}else{
							nextPos = 8 - userInput;
							computerTurn(nextPos);
							userInput = takeInputFromUser();
							tieCall();
						}
					}
				}
			}

		}
		return;
	}
	if(userInput == 0 || userInput == 2 || userInput == 6 || userInput == 8){
		computerTurn(4);
		userInput = takeInputFromUser();
		
		if(userInput == 8 - (userInputs[0]-'0')){
			computerTurn(1);
			userInput = takeInputFromUser();
			
			if(userInput!=7){
				computerTurn(7);
				computerWin();
			}else{
				nextPos = arr[6] == 0 ? 6 : 8;
				computerTurn(nextPos);
				userInput = takeInputFromUser();
				if(userInput+nextPos == 8){
					nextPos = userInput + 3;
					computerTurn(nextPos);
					userInput = takeInputFromUser();
					
					tieCall();
				}else{
					nextPos = 8 - nextPos;
					computerTurn(nextPos);
					computerWin();
				}
				
			}

		}else{
			if(((userInputs[0] - '0') == 0 && (userInput == 1 || userInput == 3)) 
				|| ((userInputs[0] - '0') == 2 && (userInput == 1 || userInput == 5)) 
				|| ((userInputs[0] - '0') == 6 && (userInput == 7 || userInput == 3))
				|| ((userInputs[0] - '0') == 8 && (userInput == 5 || userInput == 7))){

				nextPos = 2*userInput - (userInputs[0]-'0');
				computerTurn(nextPos);
				userInput = takeInputFromUser();
				
				if(userInput != 8 - nextPos){
					nextPos = (8 - nextPos);
					computerTurn(nextPos);
					computerWin();
				}else{
					nextPos = (userInput + (userInputs[0]-'0'))/2;
					computerTurn(nextPos);
					userInput = takeInputFromUser();
					
					if(userInput != (8 - nextPos)){
						nextPos = 8 - nextPos;
						computerTurn(nextPos);
						computerWin();
					}else{
						for(i=0;i<9;i++){
							if(arr[i]==0){
							nextPos = i;
							}
						}
						computerTurn(nextPos);
						userInput = takeInputFromUser();
						tieCall();
					}

				}


			}else{
				if(((userInputs[0] - '0') == 0 && (userInput == 2 || userInput == 6)) 
					|| ((userInputs[0] - '0') == 2 && (userInput == 0 || userInput == 8)) 
					|| ((userInputs[0] - '0') == 6 && (userInput == 0 || userInput == 8))
					|| ((userInputs[0] - '0') == 8 && (userInput == 6 || userInput == 2))){
					nextPos = (userInput + (userInputs[0]-'0'))/2;
					computerTurn(nextPos);
					userInput = takeInputFromUser();
					
					if(userInput != 8 - nextPos){
						nextPos = (8 - nextPos);
						computerTurn(nextPos);
						computerWin();
					}else{
						i = abs(userInput - 4)==1 ? 3 : 1;
						nextPos = 4+i;
						computerTurn(nextPos);
						userInput = takeInputFromUser();
						userInputs.push_back(userInput+'0');
						if(userInput != 8 - nextPos){
							nextPos = 8 - nextPos;
							computerTurn(nextPos);
							computerWin();
						}else{
							if(userInput - (userInputs[0]-'0') == 1 || userInput - (userInputs[0]-'0') == 3){
								nextPos = 2*userInput - (userInputs[0]-'0');
							}else{
								nextPos = 2*userInput - (userInputs[1]-'0');
							}
							computerTurn(nextPos);
							userInput = takeInputFromUser();
							tieCall();
						}

					}
				}else{
					i = abs(userInput - 4)==1 ? 3 : 1;
					nextPos = 4+i;
					computerTurn(nextPos);
					userInput = takeInputFromUser();
					userInputs.push_back(userInput+'0');
					if(userInput != 8 - nextPos){
						nextPos = 8 - nextPos;
						computerTurn(nextPos);
						computerWin();
					}else{
						if(((userInputs[0] - '0') == 0 && (userInput == 2 || userInput == 6)) 
					|| ((userInputs[0] - '0') == 2 && (userInput == 0 || userInput == 8)) 
					|| ((userInputs[0] - '0') == 6 && (userInput == 0 || userInput == 8))
					|| ((userInputs[0] - '0') == 8 && (userInput == 6 || userInput == 2))){
							nextPos = 2*userInput - (userInputs[0]-'0');
							computerTurn(nextPos);
							userInput = takeInputFromUser();
							if(userInput != 8 - nextPos){
								nextPos = 8 - nextPos;
								computerTurn(nextPos);
								computerWin();
							}else{
								nextPos = (userInput + (userInputs[0]-'0'))/2;
								computerTurn(nextPos);
								userInput = takeInputFromUser();
								tieCall();
							}
						}else{
							if((userInputs[0]-'0') == 2 || (userInputs[0]-'0') == 6){
								nextPos = 0;
							}else{
								nextPos = (computerInputs[1]-'0') == 5 ? 6 : 2;
							}
							computerTurn(nextPos);
							userInput = takeInputFromUser();
							userInputs.push_back(userInput+'0');
							if(userInput != 8 - nextPos){
								nextPos = 8 - nextPos;
								computerTurn(nextPos);
								computerWin();
							}else{
								nextPos = 8 - (userInputs[0]-'0');
								computerTurn(nextPos);
								userInput = takeInputFromUser();
								tieCall();
							}

						}

					}
				}
			}
			
		}
		return;
	}
	if(userInput == 1 || userInput == 3 || userInput == 7 || userInput == 5){
		nextPos = 4;
		computerTurn(nextPos);
		userInput = takeInputFromUser();
		if(((userInputs[0] - '0') == 1 && (userInput == 0 || userInput == 2)) 
			|| ((userInputs[0] - '0') == 3 && (userInput == 0 || userInput == 6)) 
			|| ((userInputs[0] - '0') == 5 && (userInput == 2 || userInput == 8))
			|| ((userInputs[0] - '0') == 7 && (userInput == 6 || userInput == 8))){
			nextPos = 2*(userInputs[0] - '0') - userInput;
			computerTurn(nextPos);
			userInput = takeInputFromUser();
			if(userInput != 8 - nextPos){
				nextPos = 8 - nextPos;
				computerTurn(nextPos);
				computerWin();
			}else{
				nextPos = (userInput +  (userInputs[1]-'0'))/2;
				computerTurn(nextPos);
				userInput = takeInputFromUser();
				if(userInput != 8 - nextPos){
					nextPos = 8 - nextPos;
					computerTurn(nextPos);
					computerWin();
				}else{
					for(i=0;i<9;i++){
						if(arr[i]==0){
						nextPos = i;
						}
					}
					computerTurn(nextPos);
					userInput = takeInputFromUser();
					tieCall();
				}
			}
		}else{
			if(userInput == 8 - (userInputs[0]-'0')){
				i = abs(userInput-4)==3 ? 1 : 3;
				nextPos = (userInputs[0]-'0')+i;
				computerTurn(nextPos);

				userInput = takeInputFromUser();
				if(userInput != 8 - nextPos){
					nextPos = 8 - nextPos;
					computerTurn(nextPos);
					computerWin();
				}else{
					nextPos = 2*(userInputs[1]-'0') - userInput;
					computerTurn(nextPos);
					userInput = takeInputFromUser();
					nextPos = userInput == (nextPos + (computerInputs[1]-'0'))/2 ? 8 - nextPos : (nextPos + (computerInputs[1]-'0'))/2;
					computerTurn(nextPos);
					computerWin();
				}
			}else{
				if(((userInputs[0] - '0') == 1 && (userInput == 3 || userInput == 5)) 
			|| ((userInputs[0] - '0') == 3 && (userInput == 1 || userInput == 7)) 
			|| ((userInputs[0] - '0') == 5 && (userInput == 1 || userInput == 7))

			|| ((userInputs[0] - '0') == 7 && (userInput == 3 || userInput == 5))){
					nextPos = (userInputs[0]-'0') - (4 - userInput);
					computerTurn(nextPos);
					userInput = takeInputFromUser();
					if(userInput != 8 - nextPos){
						nextPos = 8 - nextPos;
						computerTurn(nextPos);
						computerWin();
					}else{
						nextPos = (userInputs[0]-'0') + (4 - (userInputs[1]-'0'));
						computerTurn(nextPos);
						userInput = takeInputFromUser();
						if(userInput != 8 - nextPos){
							nextPos = 8 - nextPos;
							computerTurn(nextPos);
							computerWin();
						}else{
							for(i=0;i<9;i++){
								if(arr[i]==0){
								nextPos = i;
								}
							}
							computerTurn(nextPos);
							userInput = takeInputFromUser();
							tieCall();
						}
					}
				}else{
					nextPos = userInput - (4 - (userInputs[0]-'0'));
					computerTurn(nextPos);
					userInput = takeInputFromUser();
					if(userInput != 8 - nextPos){
						nextPos = 8 - nextPos;
						computerTurn(nextPos);
						computerWin();
					}else{
						nextPos = (userInputs[1]-'0') + 2*(4 - nextPos);
						computerTurn(nextPos);
						userInput = takeInputFromUser();
						if(userInput != 8 - nextPos){
							nextPos = 8 - nextPos;
							computerTurn(nextPos);
							computerWin();
						}else{
							nextPos = (userInputs[0]-'0') + (4 - (computerInputs[1]-'0'));
							computerTurn(nextPos);
							userInput = takeInputFromUser();
							tieCall();
						}
					}

				}
			}
		}
	}
}

//this function is to clear the box after a game is over
void cleanArr(){
	for(int i = 0; i<9; i++){
		arr[i] = 0;
	}
}

int main()
{
	int p;
	while(1){
		cleanArr();
		userInputs = "";
		computerInputs = "";
		cout << "if you want to be player 1 type 1, else type 2 to be player 2, 0 not to play:" << endl;
		cin >> p;
		if(p==0){
			break;
		}else{
			printNumber();
			if(p==1){
				startByUser();
			}else{
				startByComputer();
			}
		}
	}
}