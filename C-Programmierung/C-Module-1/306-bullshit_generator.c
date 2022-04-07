// Generate 'bullshit sentences'
// TO DO 1: In lines v=, n=, a=, ... rand%12? Why always 12?
// TO DO 2: Create more complex sentences e.g. by using more adjectives together or by concatenating several phrases.
// TO DO 3: Generalize the 'You should' by allowing other random introductions, e.g. "we have to", "our company must"
// TO DO 4: Don't write the output to the screen but copy the whole phrase into a separate string.
// Source of words see: http://dack.com/web/bullshit.html

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
	char pronoun[][30] = { "You", "We", "They" };
	char modalVerbs[][30] = { "should", "have to", "must", "need to", "will" };
	char verbs[][30] = { "benchmark", "exploit", "facilitate", "generate", "implement", "leverage", "maximize",
		"mesh", "monetize", "optimize", "orchestrate", "redefine" };
	char adjectives[][30] = { "bleeding-edge", "collaborative", "cross-platform", "distributed", "efficient",
		"global", "holistic", "innovative", "mission-critical", "next-generation", "out-of-the-box", "user-centric" };
	char nouns[][30] = { "action-items", "applications", "bandwidth", "communities", "e-business", "experiences",
		"infrastructures", "methodologies", "partnerships", "synergies", "solutions", "technologies" };
	char deadline[][30] = { "until tomorrow", "this year", "this week", "this month" };
	int og_number, number, p, m, v, n, a, d, a_amount, i, j;

	printf("How much bullshit do you need? ");
	scanf("%d", &og_number);
	number = og_number;
	// Added og_number, because sometimes it prints a nearly endless amount of lines 
	// and I believe the problem is in the scanf() call
	// but I don't know exactly why it doesn't work sometimes

	srand(time(NULL));

	// printf("%i\n", number);

	while (number > 0) {
		printf("%i. ", number);

		p = rand() % 3;
		m = rand() % 5;
		v = rand() % 12;
		n = rand() % 12;
		d = rand() % 4;
		a_amount = rand() % 5;

		char res[100];
		i = 0;

		for (j = 0; pronoun[p][j] > 0; j++, i++) res[i] = pronoun[p][j];
		res[i] = ' '; i++;
		for (j = 0; modalVerbs[m][j] > 0; j++, i++) res[i] = modalVerbs[m][j];
		res[i] = ' '; i++;
		for (j = 0; verbs[v][j] > 0; j++, i++) res[i] = verbs[v][j];
		res[i] = ' '; i++;

		while (a_amount > 0) {
			a = rand() % 12;
			for (j = 0; adjectives[a][j] > 0; j++, i++) res[i] = adjectives[a][j];
			res[i] = ' '; i++;
			a_amount--;
			}

		for (j = 0; nouns[n][j] > 0; j++, i++) res[i] = nouns[n][j];
		res[i] = ' '; i++;
		for (j = 0; deadline[d][j] > 0; j++, i++) res[i] = deadline[d][j];
		res[i] = 0;

		printf("%s\n", res);
		number--;
		}
	printf("\n%i", og_number);
	}