#include <stdio.h>
#include <stdlib.h>

int Parentheses, Curly, Bracket = 0;

void checkCharacter(char character) {
	switch (character) {
	case '(':
		Parentheses--;
		break;
	case ')':
		Parentheses++;
		break;
	case '[':
		Bracket--;
		break;
	case ']':
		Bracket++;
		break;
	case '{':
		Curly--;
		break;
	case '}':
		Curly++;
		break;
	default:
		break;
	}
}

struct stack {
	char* chars;
	int top;
	int size;
};

struct stack* newStack(int size) {
	struct stack *pt = (struct stack*)malloc(sizeof(struct stack));
	pt->size = size;
	pt->top = -1;
	pt->chars = (char*)malloc(size * sizeof(char));
	return pt;
}

void push(struct stack *pt, char x) {
	pt->top++;
	pt->chars[pt->top] = x;
}

char pop(struct stack* pt) {
	return pt->chars[pt->top--];
}

int main() {
	int totalChars = 0;
	char expression[100];
	printf("Please enter the expression without spaces:\n\n");
	scanf_s("%s", expression, 100);
	for (int i = 0; expression[i] != '\0'; i++) {
		totalChars++;
	}
	struct stack *pt = newStack(totalChars);
	for (int i = 0; i < totalChars; i++) {
		push(pt, expression[i]);
	}
	while (pt->top != -1) {
		checkCharacter(pop(pt));
	}
	if ((Parentheses == 0) && (Curly == 0) && (Bracket == 0)) {
		printf("Expression is balanced! \n \n");
	}
	else {
		printf("Unbalanced expression! \n \n");
	}
}