
state= ['']*9
print("computer is X");
print("user is 0");
while True :
    display(state)
    print("computer is thinking!! ")
    move=best_score(state)
    state[move] = 'X'
    if check_state(state,'X') :
        display(state)
        print("computer wins");
        break
    elif is_draw(state) :
        print("match draw")
        display(state)
        break
    display(state)
    pos = int(input("enter position 0-8 :"))
    if (pos < 0) or pos > 8 :
        print("wront choice")
        continue
    if state[pos] != '' :
        print("already filled")
 
        continue
    state[pos] = 'O'
    if(check_state(state, 'O')) :
        display(state)
        print("user_wins")
        break



def minimax(state, turn) :
    if check_winner(state, 'X') :
        return 1
    
    