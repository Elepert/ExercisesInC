
#include <stdio.h>
#include <stdlib.h>

/* 
Updates the current count of the cards in the game

Count: integer count of cards
Val: integer value of card
*/
int update_count(int count, int val) {
	if ((val >2) && (val < 7)) {
		count++;
	} else if (val == 10) {
		count--;
	}
	return count;
}

/*
Counts cards "played"

card_name: char[3] identity of card
count: integer of how many cards have been played
*/
void count_cards(char card_name[3], int count){
	do {
		puts("Enter the card_name: ");
		scanf("%2s", card_name);
		int val = 0;
		switch(card_name[0]) {
		case 'K':
		case 'Q':
		case 'J':
			val = 10;
			break;
		case 'A':
			val = 11;
			break;
		case 'X':
			continue;
		default:
			val = atoi(card_name);
			if ((val < 1) || (val > 10)) {
				puts("I don't understand that value!");
				continue;
			}
		}
		count = update_count(count, val);
		printf("Current count: %i\n", count);
	} while (card_name[0]!='X');
}

/*
Runs main fxn

returns 0
*/
int main() {
	char card_name[3];
	int count = 0;
	count_cards(card_name, count);
	return 0;
}

