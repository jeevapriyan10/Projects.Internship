import random


def number_guessing_game():
    print("Welcome to the Number Guessing Game!")
    print()
    print()
    number = random.randint(1, 100)
    attempts = 0
    while True:
        try:
            guess = int(input("Guess a number between 1 and 100: "))
            attempts += 1
            if guess == number:
                print()
                print()
                print(f"Congratulations! You've guessed the number {number} in {attempts} attempts.")
                break   
            elif guess < number:
                print("Too low! Try again.")
                print()
            else:
                print("Too high! Try again.")
                print()
        except ValueError:
            print("Please enter a valid integer.")


def rock_paper_scissors():
    print("Welcome to Rock, Paper, Scissors!")
    print()
    print()
    choices = ['rock', 'paper', 'scissors']
    while True:
        user = input("\nEnter rock, paper, or scissors (or 'exit' to quit): ").lower()
        if user == 'exit':
            print("Exiting the game. Goodbye!")
            break
        if user not in choices:
            print("Invalid choice. Please try again.")
            continue
        computer = random.choice(choices)
        print(f"Computer chose: {computer}")
        if user == computer:
            print("It's a tie!")
        elif (user == 'rock' and computer == 'scissors') or (user == 'paper' and computer == 'rock') or (user == 'scissors' and computer == 'paper'):
            print("You win!")
        else:
            print("Computer wins!")


def penalty_shootout():
    print("Welcome to the Command Line Penalty Shootout!")
    print()
    print()
    player_score = 0
    computer_score = 0
    rounds = 3
    for i in range(rounds):
        print(f"Round {i+1}:")
        print("\nChoose your direction to shoot (left, center, right): ")
        player_choice = input().lower()
        while player_choice not in ['left', 'center', 'right']:
            print("Invalid choice. Please choose left, center, or right:")
            player_choice = input().lower()
        computer_choice = random.choice(['left', 'center', 'right'])
        print(f"Computer chose to dive: {computer_choice}")
        if player_choice == computer_choice:
            print("Goalkeeper saved your shot!")        
        else:
            print("Goal! You scored.")
            player_score += 1
        
        print("\nNow it's the computer's turn to shoot.")
        computer_shot = random.choice(['left', 'center', 'right'])
        print("Choose your direction to dive (left, center, right): ")
        player_dive = input().lower()
        while player_dive not in ['left', 'center', 'right']:
            print("Invalid choice. Please choose left, center, or right:")
            player_dive = input().lower()
        if player_dive == computer_shot:
            print("Saved computer's shot!")
        else:
            print("Goal! Computer scored.")
            computer_score += 1
        print()
    print(f"\nFinal Score - You: {player_score}, Computer: {computer_score}")
    if player_score > computer_score:   
        print("Congratulations! You win the penalty shootout!")         
    elif player_score < computer_score:
        print("Computer wins the penalty shootout! Better luck next time.")
        
def main():
    print("Welcome to Text Adventure!")
    print("Choose a Game to Play:")
    choice = 0
    while choice not in [1, 2,3,4]:
        print("1. Number Guessing Game (1-100)")
        print("2. Rock, Paper, Scissors")
        print("3. Command Line Penalty Shootout")
        print("4. Exit")
        print("Enter 1, 2, or 3 to select a game:")
        try:
            choice = int(input())
        except ValueError:
            continue
    if choice == 1:
        number_guessing_game()
    elif choice == 2:
        rock_paper_scissors()
    elif choice == 3:
        penalty_shootout()
    elif choice == 4:
        print("Exiting the game. Goodbye!")
        return
    
main()
